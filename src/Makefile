CC=gcc
INCLUDE_DIR=./include
OBJECT_DIR=./.object
BIN_DIR=../bin
LOG_DIR=./log
UTIL_DIR=./utils

SERVER_DIR=./server
SERVER_INCLUDE=./server/include
SERVER_TEST=./server/test

CLIENT_DIR=./client
CLIENT_INCLUDE=./client/include
CLIENT_TEST=./client/test

TEST_DIR=./test
BDB_DIR=/home/zhumeiqi/BDB
INCLUDE_FLAG=-I$(INCLUDE_DIR) -I$(BDB_DIR)/include -I$(SERVER_DIR)/include -I$(CLIENT_DIR)/include
LIB_FLAG=-L$(BDB_DIR)/lib -lpthread -ldb
CFLAGS=$(INCLUDE_FLAG) $(LIB_FLAG) -Wall -DDEBUG=1
INSTALL_DIR=$(POMME_HOME)

include $(SERVER_DIR)/Makefile
include $(LOG_DIR)/Makefile
include $(UTIL_DIR)/Makefile
include $(TEST_DIR)/Makefile
include $(CLIENT_DIR)/Makefile

all_depends=$(addprefix $(OBJECT_DIR)/,all_test all_log all_server all_utils all_client)
all_clean= $(addprefix clean_, test log server utils client)

.PHONY: all $(all_depends) all_clean

all: $(all_depends)
	mkdir -p .object

default:
	echo $(INCLUDE_DIR)
clean: $(all_clean) 
	rm -f .object/*
	rm -f *~
	rm -f include/*~
install:
	mkdir -p $(INSTALL_DIR)
	mkdir -p $(INSTALL_DIR)/bin
	mkdir -p $(INSTALL_DIR)/lib
	cp ../bin/* $(INSTALL_DIR)/bin
	cp ../lib/* $(INSTALL_DIR)/lib
	
