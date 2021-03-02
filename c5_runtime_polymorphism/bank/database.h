#pragma once
#include <vector>
#include "clients.h"

class Database{
    vector<Client*> client_base;
    size_t id_counter;
public:
    Database() : id_counter{} {};

    void add_client(string name, ClientType type){
        Client* client;
        switch (type)
        {
        case ClientType::SILVER:
            client = (Client*) new SilverClient(name, ++id_counter);
            break;

        case ClientType::GOLDEN:
            client = (Client*) new GoldenClient(name, ++id_counter);
            break;
        
        case ClientType::PLATINUM:
            client = (Client*) new PlatinumClient(name, ++id_counter);
            break;
        
        default:
            break;
        }

        client_base.push_back(client);
    };

    Client* get_client(size_t id){
        for (auto x : client_base){
            if(x->get_id() == id)
                return x;
        }
        return nullptr;
    };

    void print_client_database(){
        for (auto x : client_base)
            x->print();
    };

    ~Database(){
        for (auto& x : client_base)
            delete x;
    };
};