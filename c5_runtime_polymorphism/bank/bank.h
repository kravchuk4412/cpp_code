#pragma once
#include "database.h"
#include "loggers.h"
#include <exception>

class Bank{
    Database clients_db;
    Logger* logger;
public: 
    Bank(Logger* logger) : clients_db{}, logger{logger} {};

    void set_logger(Logger* new_logger) {
        logger = new_logger;
    };

    void make_transfer(size_t from, size_t to, double amount) {
        Client *from_c{clients_db.get_client(from)},
               *to_c{clients_db.get_client(to)};
        if(from_c && to_c){
            if (logger) logger->log_transfer(from_c->get_name(), to_c->get_name(), amount);
            else throw runtime_error("There is no logger!\n");
        } else {
            throw logic_error("Incorrect clients id in transaction(some of ids absent)!\n");
        }
    };

    void fill_db(){
        clients_db.add_client("Phil Jones", ClientType::SILVER);
        clients_db.add_client("Luke Shaw", ClientType::GOLDEN);
        clients_db.add_client("Akex Telles", ClientType::GOLDEN);
        clients_db.add_client("Juan Mata", ClientType::PLATINUM);
    };

    void print_db(){
        clients_db.print_client_database();
    };

    ~Bank() = default;
};