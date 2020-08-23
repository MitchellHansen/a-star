#include "GraphNode.h"

GraphNode::GraphNode(sf::Vector2f position, std::string sprite_texture) {

    tinyxml2::XMLElement* t = spritesheet_xml.FirstChildElement(sprite_texture.c_str());

	sf::Vector2i xy(t->IntAttribute("x"),t->IntAttribute("y"));
	sf::Vector2i hw(t->IntAttribute("height"),t->IntAttribute("width"));
    
    sprite = sf::Sprite(GraphNode::spritesheet, sf::Rect<int>(xy, hw));
}


GraphNode::~GraphNode(){

}

sf::Vector2f GraphNode::getPosition(){
    return position;   
}

void GraphNode::add_node(GraphNode* node){
	adjacent_nodes.push_back(node);
}

bool GraphNode::remove_node(GraphNode* node){

	std::list<GraphNode*>::iterator i = adjacent_nodes.begin();

	while (i != adjacent_nodes.end()) {
		if ((*i) == node) {
	        i = adjacent_nodes.erase(i);
			return true;
	    } else {
		    ++i;
		}
	}
	return false;
}

void GraphNode::set_spritesheet(std::string xml_path, std::string texture_path) {

	spritesheet.loadFromFile(texture_path);
    spritesheet_xml.LoadFile(xml_path.c_str());
}

tinyxml2::XMLDocument GraphNode::spritesheet_xml;
sf::Texture GraphNode::spritesheet;

