#pragma once

#include <list>
#include <map>
#include <asmjit/asmjit.h>

namespace vEngine {
    template<typename T>
    class TSFPTrunk {
    public:
        template<typename TRet>
        TRet(__stdcall*sfp0(TRet(T::*mfuncPtr)()))() {
            void* mfp = mfp_cast(mfuncPtr);

            std::map<void*, void*>::iterator itr = funcPtrMap.find(mfp);
            if (itr != funcPtrMap.end()) {
                return asmjit_cast<TRet(__stdcall*)()>(itr->second);
            }

            AsmJit* jit = new AsmJit;
            jits.push_front(jit);

            jit->compiler->addFunc(asmjit::FuncBuilder0<TRet>(asmjit::kCallConvHostStdCall));
            asmjit::X86GpVar ret = jit->compiler->newInt32("ret");

            asmjit::X86GpVar ecx = jit->compiler->newIntPtr("ecx");
            jit->compiler->alloc(ecx, asmjit::x86::ecx);
            jit->compiler->mov(ecx, asmjit::imm((int64_t)objThisPtr));

            asmjit::X86CallNode* call = jit->compiler->call(asmjit::imm_ptr(mfp), asmjit::FuncBuilder0<TRet>(asmjit::kCallConvHostStdCall));
            call->setRet(0, ret);

            jit->compiler->ret(ret);
            jit->compiler->endFunc();
            jit->compiler->finalize();

            void* thunkFP = jit->assembler->make();

            funcPtrMap.insert(std::pair<void*, void*>(mfp, thunkFP));
            return asmjit_cast<TRet(__stdcall*)()>(thunkFP);
        }

        template<typename TRet, typename TArg0>
        TRet(__stdcall*sfp1(TRet(T::* mfuncPtr)(TArg0)))(TArg0) {
            void* mfp = mfp_cast(mfuncPtr);

            std::map<void*, void*>::iterator itr = funcPtrMap.find(mfp);
            if (itr != funcPtrMap.end()) {
                return asmjit_cast<TRet(__stdcall*)(TArg0)>(itr->second);
            }

            AsmJit* jit = new AsmJit;
            jits.push_front(jit);

            jit->compiler->addFunc(asmjit::FuncBuilder1<TRet, TArg0>(asmjit::kCallConvHostStdCall));
            asmjit::X86GpVar arg0 = jit->compiler->newInt32("arg0");
            jit->compiler->setArg(0, arg0);

            asmjit::X86GpVar ecx = jit->compiler->newIntPtr("ecx");
            jit->compiler->alloc(ecx, asmjit::x86::ecx);
            jit->compiler->mov(ecx, asmjit::imm((int64_t)objThisPtr));

            asmjit::X86CallNode* call = jit->compiler->call(asmjit::imm_ptr(mfp), asmjit::FuncBuilder1<TRet, TArg0>(asmjit::kCallConvHostStdCall));
            call->setArg(0, arg0);
            call->setRet(0, arg0);

            jit->compiler->ret(arg0);
            jit->compiler->endFunc();
            jit->compiler->finalize();

            void* thunkFP = jit->assembler->make();

            funcPtrMap.insert(std::pair<void*, void*>(mfp, thunkFP));
            return asmjit_cast<TRet(__stdcall*)(TArg0)>(thunkFP);
        }

        template<typename TRet, typename TArg0>
        TRet(__cdecl*sfp1_cdecl(TRet(T::* mfuncPtr)(TArg0)))(TArg0) {
            void* mfp = mfp_cast(mfuncPtr);

            std::map<void*, void*>::iterator itr = funcPtrMap.find(mfp);
            if (itr != funcPtrMap.end()) {
                return asmjit_cast<TRet(__cdecl*)(TArg0)>(itr->second);
            }

            AsmJit* jit = new AsmJit;
            jits.push_front(jit);

            jit->compiler->addFunc(asmjit::FuncBuilder1<TRet, TArg0>(asmjit::kCallConvHostCDecl));
            asmjit::X86GpVar arg0 = jit->compiler->newInt32("arg0");
            jit->compiler->setArg(0, arg0);

            asmjit::X86GpVar ecx = jit->compiler->newIntPtr("ecx");
            jit->compiler->alloc(ecx, asmjit::x86::ecx);
            jit->compiler->mov(ecx, asmjit::imm((int64_t)objThisPtr));

            asmjit::X86CallNode* call = jit->compiler->call(asmjit::imm_ptr(mfp), asmjit::FuncBuilder1<TRet, TArg0>(asmjit::kCallConvHostStdCall));
            call->setArg(0, arg0);
            call->setRet(0, arg0);

            jit->compiler->ret(arg0);
            jit->compiler->endFunc();
            jit->compiler->finalize();

            void* thunkFP = jit->assembler->make();

            funcPtrMap.insert(std::pair<void*, void*>(mfp, thunkFP));
            return asmjit_cast<TRet(__cdecl*)(TArg0)>(thunkFP);
        }

        template<typename TRet, typename TArg0, typename TArg1>
        TRet(__stdcall*sfp2(TRet(T::* mfuncPtr)(TArg0, TArg1)))(TArg0, TArg1) {
            void* mfp = mfp_cast(mfuncPtr);

            std::map<void*, void*>::iterator itr = funcPtrMap.find(mfp);
            if (itr != funcPtrMap.end()) {
                return asmjit_cast<TRet(__stdcall*)(TArg0, TArg1)>(itr->second);
            }

            AsmJit* jit = new AsmJit;
            jits.push_front(jit);

            jit->compiler->addFunc(asmjit::FuncBuilder2<TRet, TArg0, TArg1>(asmjit::kCallConvHostStdCall));
            asmjit::X86GpVar arg0 = jit->compiler->newInt32("arg0");
            asmjit::X86GpVar arg1 = jit->compiler->newInt32("arg1");
            jit->compiler->setArg(0, arg0);
            jit->compiler->setArg(1, arg1);

            asmjit::X86GpVar ecx = jit->compiler->newIntPtr("ecx");
            jit->compiler->alloc(ecx, asmjit::x86::ecx);
            jit->compiler->mov(ecx, asmjit::imm((int64_t)objThisPtr));

            asmjit::X86CallNode* call = jit->compiler->call(asmjit::imm_ptr(mfp), asmjit::FuncBuilder2<TRet, TArg0, TArg1>(asmjit::kCallConvHostStdCall));
            call->setArg(0, arg0);
            call->setArg(1, arg1);
            call->setRet(0, arg0);

            jit->compiler->ret(arg0);
            jit->compiler->endFunc();
            jit->compiler->finalize();

            void* thunkFP = jit->assembler->make();

            funcPtrMap.insert(std::pair<void*, void*>(mfp, thunkFP));
            return asmjit_cast<TRet(__stdcall*)(TArg0, TArg1)>(thunkFP);
        }

        template<typename TRet, typename TArg0, typename TArg1, typename TArg2>
        TRet(__stdcall*sfp3(TRet(T::* mfuncPtr)(TArg0, TArg1, TArg2)))(TArg0, TArg1, TArg2) {
            void* mfp = mfp_cast(mfuncPtr);

            std::map<void*, void*>::iterator itr = funcPtrMap.find(mfp);
            if (itr != funcPtrMap.end()) {
                return asmjit_cast<TRet(__stdcall*)(TArg0, TArg1, TArg2)>(itr->second);
            }

            AsmJit* jit = new AsmJit;
            jits.push_front(jit);

            jit->compiler->addFunc(asmjit::FuncBuilder3<TRet, TArg0, TArg1, TArg2>(asmjit::kCallConvHostStdCall));
            asmjit::X86GpVar arg0 = jit->compiler->newInt32("arg0");
            asmjit::X86GpVar arg1 = jit->compiler->newInt32("arg1");
            asmjit::X86GpVar arg2 = jit->compiler->newInt32("arg2");
            jit->compiler->setArg(0, arg0);
            jit->compiler->setArg(1, arg1);
            jit->compiler->setArg(2, arg2);

            asmjit::X86GpVar ecx = jit->compiler->newIntPtr("ecx");
            jit->compiler->alloc(ecx, asmjit::x86::ecx);
            jit->compiler->mov(ecx, asmjit::imm((int64_t)objThisPtr));

            asmjit::X86CallNode* call = jit->compiler->call(asmjit::imm_ptr(mfp), asmjit::FuncBuilder3<TRet, TArg0, TArg1, TArg2>(asmjit::kCallConvHostStdCall));
            call->setArg(0, arg0);
            call->setArg(1, arg1);
            call->setArg(2, arg2);
            call->setRet(0, arg0);

            jit->compiler->ret(arg0);
            jit->compiler->endFunc();
            jit->compiler->finalize();

            void* thunkFP = jit->assembler->make();

            funcPtrMap.insert(std::pair<void*, void*>(mfp, thunkFP));
            return asmjit_cast<TRet(__stdcall*)(TArg0, TArg1, TArg2)>(thunkFP);
        }

        template<typename TRet, typename TArg0, typename TArg1, typename TArg2, typename TArg3>
        TRet(__stdcall*sfp4(TRet(T::* mfuncPtr)(TArg0, TArg1, TArg2, TArg3)))(TArg0, TArg1, TArg2, TArg3) {
            void* mfp = mfp_cast(mfuncPtr);

            std::map<void*, void*>::iterator itr = funcPtrMap.find(mfp);
            if (itr != funcPtrMap.end()) {
                return asmjit_cast<TRet(__stdcall*)(TArg0, TArg1, TArg2, TArg3)>(itr->second);
            }

            AsmJit* jit = new AsmJit;
            jits.push_front(jit);

            jit->compiler->addFunc(asmjit::FuncBuilder4<TRet, TArg0, TArg1, TArg2, TArg3>(asmjit::kCallConvHostStdCall));
            asmjit::X86GpVar arg0 = jit->compiler->newInt32("arg0");
            asmjit::X86GpVar arg1 = jit->compiler->newInt32("arg1");
            asmjit::X86GpVar arg2 = jit->compiler->newInt32("arg2");
            asmjit::X86GpVar arg3 = jit->compiler->newInt32("arg3");
            jit->compiler->setArg(0, arg0);
            jit->compiler->setArg(1, arg1);
            jit->compiler->setArg(2, arg2);
            jit->compiler->setArg(3, arg3);

            asmjit::X86GpVar ecx = jit->compiler->newIntPtr("ecx");
            jit->compiler->alloc(ecx, asmjit::x86::ecx);
            jit->compiler->mov(ecx, asmjit::imm((int64_t)objThisPtr));

            asmjit::X86CallNode* call = jit->compiler->call(asmjit::imm_ptr(mfp), asmjit::FuncBuilder4<TRet, TArg0, TArg1, TArg2, TArg3>(asmjit::kCallConvHostStdCall));
            call->setArg(0, arg0);
            call->setArg(1, arg1);
            call->setArg(2, arg2);
            call->setArg(3, arg3);
            call->setRet(0, arg0);

            jit->compiler->ret(arg0);
            jit->compiler->endFunc();
            jit->compiler->finalize();

            void* thunkFP = jit->assembler->make();

            funcPtrMap.insert(std::pair<void*, void*>(mfp, thunkFP));
            return asmjit_cast<TRet(__stdcall*)(TArg0, TArg1, TArg2, TArg3)>(thunkFP);
        }

        void sfp_clear() {
            std::list<AsmJit*>::iterator itr;
            for (itr = jits.begin(); itr != jits.end(); itr++) {
                delete *itr;
            }
            funcPtrMap.clear();
        }

        void operator=(T* objPtr) {
            objThisPtr = objPtr;
        }

        TSFPTrunk() {
            objThisPtr = (T*)this;
        }

        TSFPTrunk(T* objPtr) {
            objThisPtr = objPtr;
        }

        ~TSFPTrunk() {
            sfp_clear();
        }

    private:
        template<typename TMFP> void* mfp_cast(TMFP mfp) { return  (void*&)mfp; }

        struct AsmJit {
            AsmJit() {
                runtime = new asmjit::JitRuntime;
                assembler = new asmjit::X86Assembler(runtime);
                compiler = new asmjit::X86Compiler(assembler);
            }
            ~AsmJit() {
                delete compiler;
                delete assembler;
                delete runtime;
            }
            asmjit::JitRuntime*     runtime;
            asmjit::X86Assembler*   assembler;
            asmjit::X86Compiler*    compiler;
        };

        T*                      objThisPtr;
        std::list<AsmJit*>      jits;
        std::map<void*, void*>  funcPtrMap;
    };
}
