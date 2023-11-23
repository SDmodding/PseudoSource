// File Line: 45
// RVA: 0x15AA630
__int64 Illusion::_dynamic_initializer_for__gRenderThreadManager__()
{
  UFG::qMutex::qMutex(&Illusion::gRenderThreadManager.mCommandsMutex, &customCaption);
  stru_142452770.mNode.mPrev = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&stru_142452770;
  stru_142452770.mNode.mNext = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&stru_142452770;
  UFG::qThread::qThread(&stru_142452790);
  UFG::qEvent::qEvent(&stru_1424527D0);
  UFG::qEvent::qEvent(&stru_1424527E8);
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gRenderThreadManager__);
}

// File Line: 67
// RVA: 0xA1B650
void __fastcall Illusion::RenderThreadManager::Init(Illusion::RenderThreadManager *this)
{
  this->mEventWaitTimeoutMicroSeconds = 16666;
  this->mSubFlipEnabled = 1;
  *(_QWORD *)&this->mNumCommandsAdded = 0i64;
  UFG::qEvent::Create(&this->mEventFlag_CommandAdded, "RT_Add", 0);
  UFG::qEvent::Create(&this->mEventFlag_CompletedAllCommands, "RT_Done", 0);
  UFG::qEvent::Signal(&this->mEventFlag_CompletedAllCommands);
  this->mFlag_UserEvent = 0;
  this->mRenderThreadEnabled = 1;
  UFG::qThread::SetName((ANTLR3_TOKEN_STREAM_struct *)&this->mRenderThread, &stru_141A183E8);
  UFG::qThread::SetThreadPriority(&this->mRenderThread, 15);
  UFG::qThread::SetLogicalCoreID(&this->mRenderThread, 1);
  UFG::qThread::Start(&this->mRenderThread, Illusion::RenderThreadManager::RenderThreadFunctionBridge, this);
}

// File Line: 115
// RVA: 0xA17090
void __fastcall Illusion::RenderThreadManager::AddCommand(
        Illusion::RenderThreadManager *this,
        Illusion::RenderThreadCommand command,
        UFG::allocator::free_link *param,
        UFG::allocator::free_link *data0,
        UFG::allocator::free_link *data1)
{
  UFG::allocator::free_link *v9; // rax
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *v10; // r9
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *mPrev; // rax

  UFG::qMutex::Lock((LPCRITICAL_SECTION)this);
  ++this->mNumCommandsAdded;
  v9 = UFG::qMalloc(0x30ui64, "rtCommand", 0x800ui64);
  v10 = (UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *)v9;
  if ( v9 )
  {
    v9->mNext = v9;
    v9[1].mNext = v9;
    LODWORD(v9[2].mNext) = command;
    v9[3].mNext = param;
    v9[4].mNext = data0;
    v9[5].mNext = data1;
  }
  else
  {
    v10 = 0i64;
  }
  mPrev = this->mCommands.mNode.mPrev;
  mPrev->mNext = v10;
  v10->mPrev = mPrev;
  v10->mNext = &this->mCommands.mNode;
  this->mCommands.mNode.mPrev = v10;
  UFG::qEvent::Clear(&this->mEventFlag_CompletedAllCommands);
  UFG::qEvent::Signal(&this->mEventFlag_CommandAdded);
  this->mFlag_UserEvent = 0;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)this);
}

// File Line: 148
// RVA: 0xA21620
// attributes: thunk
void __fastcall Illusion::RenderThreadManager::RenderThreadFunctionBridge(Illusion::RenderThreadManager *arg)
{
  Illusion::RenderThreadManager::RenderThreadFunction(arg);
}

// File Line: 153
// RVA: 0xA21370
void __fastcall Illusion::RenderThreadManager::RenderThreadFunction(Illusion::RenderThreadManager *this)
{
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *mNext; // r8
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *mPrev; // rcx
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *v4; // rax
  int v5; // esi
  UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *v6; // rdi
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *v7; // r14
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *v8; // r15
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *v9; // rdx
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *v10; // rax
  _QWORD *v11; // rdi
  __int64 v12; // rcx
  __int64 v13; // [rsp+80h] [rbp+8h] BYREF
  __int64 v14; // [rsp+88h] [rbp+10h] BYREF
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *v15; // [rsp+90h] [rbp+18h]

  while ( this->mRenderThreadEnabled )
  {
    if ( UFG::qEvent::Wait(&this->mEventFlag_CommandAdded, this->mEventWaitTimeoutMicroSeconds) )
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)this);
      mNext = this->mCommands.mNode.mNext;
      mPrev = mNext->mPrev;
      v4 = mNext->mNext;
      mPrev->mNext = v4;
      v4->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      v5 = (int)mNext[1].mPrev;
      v6 = (UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *)mNext[1].mNext;
      v7 = mNext[2].mPrev;
      v8 = mNext[2].mNext;
      v15 = mNext;
      v9 = mNext->mPrev;
      v10 = mNext->mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      operator delete[](mNext);
      if ( (UFG::qList<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand,1,0> *)this->mCommands.mNode.mNext == &this->mCommands )
        UFG::qEvent::Clear(&this->mEventFlag_CommandAdded);
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)this);
      switch ( v5 )
      {
        case 2:
          Illusion::RenderQueuePlat::ExecuteFlushedRenderPhasesImmediate(v6);
          break;
        case 4:
          ((void (__fastcall *)(UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *))v6)(v7);
          break;
        case 5:
          ((void (__fastcall *)(UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *, UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *))v6)(
            v7,
            v8);
          break;
        case 7:
          v13 = 0i64;
          v14 = 0i64;
          ((void (__fastcall *)(ID3D11Device *, __int64 *, __int64 *))UFG::gD3D11Device->vfptr->OMSetRenderTargets)(
            UFG::gD3D11Device,
            &v14,
            &v13);
          v11 = (_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
          (*(void (__fastcall **)(_QWORD, __int64))(*(_QWORD *)*v11 + 224i64))(*v11, v13);
          while ( (*(unsigned int (__fastcall **)(_QWORD, __int64, _QWORD, _QWORD, _DWORD))(*(_QWORD *)*v11 + 232i64))(
                    *v11,
                    v13,
                    0i64,
                    0i64,
                    0) == 1 )
            UFG::qSleep(0);
          if ( v13 )
          {
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v13 + 16i64))(v13);
            v13 = 0i64;
          }
          break;
        case 9:
          if ( v6->mNode.mPrev )
          {
            v12 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
            (*(void (__fastcall **)(__int64, UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *, _QWORD))(*(_QWORD *)v12 + 464i64))(
              v12,
              v6->mNode.mPrev,
              0i64);
            if ( v6->mNode.mPrev )
            {
              ((void (__fastcall *)(UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *))v6->mNode.mPrev->mPrev[1].mPrev)(v6->mNode.mPrev);
              v6->mNode.mPrev = 0i64;
            }
          }
          break;
        case 10:
          this->mFlag_UserEvent = 1;
          break;
        default:
          break;
      }
      UFG::qMutex::Lock((LPCRITICAL_SECTION)this);
      if ( ++this->mNumCommandsCompleted == this->mNumCommandsAdded )
        UFG::qEvent::Signal(&this->mEventFlag_CompletedAllCommands);
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)this);
    }
  }
}

// File Line: 421
// RVA: 0xA17160
void __fastcall Illusion::AddRenderThreadCommand(
        Illusion::RenderThreadCommand command,
        UFG::allocator::free_link *param,
        UFG::allocator::free_link *data0,
        UFG::allocator::free_link *data1)
{
  Illusion::RenderThreadManager::AddCommand(&Illusion::gRenderThreadManager, command, param, data0, data1);
}

// File Line: 429
// RVA: 0xA22E10
void __fastcall Illusion::WaitForRenderThread(Illusion *this)
{
  UFG::qEvent::Wait(&stru_1424527E8);
}

