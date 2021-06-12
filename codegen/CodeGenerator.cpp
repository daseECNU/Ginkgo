/*
 * CodeGenerator.cpp
 *
 *  Created on: Mar 21, 2015
 *      Author: wangli
 */

#include "CodeGenerator.h"

#include <assert.h>
#include <iostream>

using llvm::IRBuilder;
using llvm::legacy::FunctionPassManager;
using llvm::createCFGSimplificationPass;
using llvm::createDeadCodeEliminationPass;
using llvm::InitializeNativeTarget;
using llvm::EngineBuilder;

llvm::IRBuilder<>* CodeGenerator::builder_=0;
Module* CodeGenerator::module_=0;
CodeGenerator* CodeGenerator::instance_=0;
FunctionPassManager* CodeGenerator::fpm_=0;
ExecutionEngine* CodeGenerator::engine_=0;

CodeGenerator* CodeGenerator::getInstance() {
	if(instance_==0){
		instance_ = new CodeGenerator();
	}
	return instance_;
}

const Module* CodeGenerator::getModule() const {
	return module_;
}

llvm::IRBuilder<>* CodeGenerator::getBuilder() const {
	return builder_;
}

FunctionPassManager* CodeGenerator::getFunctionPassManager() const {
	return fpm_;
}

ExecutionEngine* CodeGenerator::getExecutionEngine() const {
	return engine_;
}

void CodeGenerator::lock() {
	lock_.acquire();
}

void CodeGenerator::release() {
	lock_.release();
//	std::cout<<"    unlock    "<<std::endl;
}

CodeGenerator::CodeGenerator() {
	InitializeNativeTarget();
	builder_=new IRBuilder<>(llvm::getGlobalContext());
	module_=new Module("my cool jit", llvm::getGlobalContext());
   fpm_=new FunctionPassManager (module_);
	fpm_->add(llvm::createCFGSimplificationPass());
	fpm_->add(llvm::createDeadCodeEliminationPass());
	fpm_->add(llvm::createMemCpyOptPass());
	engine_ = EngineBuilder(module_).create();
	assert(engine_);

}

CodeGenerator::~CodeGenerator() {
	delete builder_;
	builder_ = NULL;
	delete module_;
	module_ = NULL;
	delete fpm_;
	fpm_ = NULL;
	instance_=0;
}

