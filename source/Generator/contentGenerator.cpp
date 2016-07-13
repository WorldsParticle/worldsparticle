#include <algorithm>
#include <math.h>
#include <log4cpp/Category.hh>

#include "Generator/contentGenerator.hpp"

#include "Generator/data/sceneData.hpp"
#include "Generator/content/sceneContent.hpp"
#include "Generator/content/elementContent.hpp"

using namespace log4cpp;
using GenData::ZoneData;
using GenData::ElementData;
using GenData::ClimateData;

//#define GEN_ELEM_OFFEST_MAX(size, elemCount) (static_cast<int>(static_cast<float>(size) / 10.0f / static_cast<float>(elemCount)))
//#define GEN_ELEM_OFFSET(size, elemCount) (rand() % GEN_ELEM_OFFEST_MAX(size, elemCount) - (GEN_ELEM_OFFEST_MAX(size, elemCount) / 2))
//#define GEN_ELEM_POS(i, size, elemCount) (static_cast<float>(i) * static_cast<float>(size) / static_cast<float>(elemCount) + GEN_ELEM_OFFSET(size, elemCount))// + (rand() % (size / elemCount)))

namespace gen
{

ContentGenerator::ContentGenerator()
: _map(nullptr), _datas(),
_contents()
{
    
}

ContentGenerator::~ContentGenerator()
{
    
}

static float calcPosition(float i, float size, float elemCount)
{
    float position = i * size / elemCount;

    int offsetMax = static_cast<int>(size / 2.0f, elemCount);
    int offset = rand() % offsetMax - (offsetMax / 2);
    position += static_cast<float>(offset);
    
    return position;
}

void ContentGenerator::launch(map::MapGraph *map, GenData::SceneData const& datas)
{
    _map = map;
    _datas = datas;
    
//    Engine::Transform contentPos;
//    contentPos.translate(glm::vec3(0.0f, 0.0f, 2.0f));//Tmp, to be sure elements are above the floor
//    contentPos.scale(glm::vec3(0.1f, 0.1f, 0.1f));//To fit big trees
    
//    std::for_each(_datas.zones().begin(), _datas.zones().end(), [&](ZoneData* zone){//TODO change to activeZoneDatas
        ZoneData * zone = _datas.zones().at(0);
        
        int totalElementInZone = zone->elementCountTotal.value();
        int width = zone->width.value();//static_cast<int>(_map->xMax());
        int height = zone->height.value();//static_cast<int>(_map->yMax());//TODO put this in ZoneData
        
        std::for_each(zone->elements().begin(), zone->elements().end(), [&](ElementData* element){
//            ElementData* element = zone->elements().at(0);

            Category::getRoot() << Priority::INFO << "Create content from data : " << element->name;
            int elemCount = element->density.value() * totalElementInZone / 100;
            int elemCountSide = static_cast<int>(std::sqrt(elemCount));
            for (int i = 0; i < elemCountSide; i++)
            {
                float x = calcPosition(i, width, elemCountSide);

                for (int j = 0; j < elemCountSide; j++)
                {
                    float y = calcPosition(j, height, elemCountSide);

                    GenContent::ElementContent * content = new GenContent::ElementContent(element->name, element->filename());

                    Engine::Transform contentPos;
                    contentPos.translate(glm::vec3(0.0f, 0.0f, 2.0f));//Tmp, to be sure elements are above the floor
                    //contentPos.scale(glm::vec3(0.1f, 0.1f, 0.1f));//To fit big trees

                    contentPos.translate(glm::vec3(x, y, 0.0f));
                    content->setTransform(contentPos);
                    _contents.elements().push_back(content);
                }
            }
        });
        
        ClimateData * climate = zone->climate();
        
        _contents.exploHour = climate->exploHour.value();
        _contents.framebuffer = climate->frameBuffer.value();//TODO skybox content !

//    });
}

}