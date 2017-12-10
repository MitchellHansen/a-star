#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include "tinyxml2.h"

class GraphNode{

    public:

        GraphNode(sf::Vector2f position, std::string sprite_texture);
        ~GraphNode();

        void add_node(GraphNode* node);
        bool remove_node(GraphNode* node);

        sf::Vector2f getPosition();

    	static void set_spritesheet(std::string xml_path, std::string texture_path);

    private:


        sf::Sprite sprite;
        sf::Vector2f position;        

       	static tinyxml2::XMLDocument spritesheet_xml;
    	static sf::Texture spritesheet;
       
        std::list<GraphNode*> adjacent_nodes;


};



















