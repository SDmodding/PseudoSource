// File Line: 45
// RVA: 0x15AA630
__int64 Illusion::_dynamic_initializer_for__gRenderThreadManager__()
{
  UFG::qMutex::qMutex(&Illusion::gRenderThreadManager.mCommandsMutex, &customWorldMapCaption);
  stru_142452770.mNode.mPrev = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&stru_142452770;
  stru_142452770.mNode.mNext = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&stru_142452770;
  UFG::qThread::qThread(&stru_142452790);
  UFG::qEvent::qEvent(&stru_1424527D0);
  UFG::qEvent::qEvent(&stru_1424527E8);
  return atexit(Illusion::_dynamic_atexit_destructor_for__gRenderThreadManager__);
}

// File Line: 67
// RVA: 0xA1B650
void __fastcall Illusion::RenderThreadManager::Init(Illusion::RenderThreadManager *this)
{
  Illusion::RenderThreadManager *v1; // rdi

  v1 = this;
  this->mEventWaitTimeoutMicroSeconds = 16666;
  this->mSubFlipEnabled = 1;
  *(_QWORD *)&this->mNumCommandsAdded = 0i64;
  UFG::qEvent::Create(&this->mEventFlag_CommandAdded, "RT_Add", 0);
  UFG::qEvent::Create(&v1->mEventFlag_CompletedAllCommands, "RT_Done", 0);
  UFG::qEvent::Signal(&v1->mEventFlag_CompletedAllCommands);
  v1->mFlag_UserEvent = 0;
  v1->mRenderThreadEnabled = 1;
  UFG::qThread::SetName((ANTLR3_TOKEN_STREAM_struct *)&v1->mRenderThread, &stru_141A183E8);
  UFG::qThread::SetThreadPriority(&v1->mRenderThread, 15);
  UFG::qThread::SetLogicalCoreID(&v1->mRenderThread, 1);
  UFG::qThread::Start(&v1->mRenderThread, Illusion::RenderThreadManager::RenderThreadFunctionBridge, v1);
}

// File Line: 115
// RVA: 0xA17090
void __fastcall Illusion::RenderThreadManager::AddCommand(Illusion::RenderThreadManager *this, Illusion::RenderThreadCommand command, void *param, void *data0, void *data1)
{
  UFG::allocator::free_link *v5; // rdi
  UFG::allocator::free_link *v6; // rsi
  Illusion::RenderThreadCommand v7; // ebp
  Illusion::RenderThreadManager *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // r9
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *v11; // rax

  v5 = (UFG::allocator::free_link *)data0;
  v6 = (UFG::allocator::free_link *)param;
  v7 = command;
  v8 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)this);
  ++v8->mNumCommandsAdded;
  v9 = UFG::qMalloc(0x30ui64, "rtCommand", 0x800ui64);
  v10 = v9;
  if ( v9 )
  {
    v9->mNext = v9;
    v9[1].mNext = v9;
    LODWORD(v9[2].mNext) = v7;
    v9[3].mNext = v6;
    v9[4].mNext = v5;
    v9[5].mNext = (UFG::allocator::free_link *)data1;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = v8->mCommands.mNode.mPrev;
  v11->mNext = (UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *)v10;
  v10->mNext = (UFG::allocator::free_link *)v11;
  v10[1].mNext = (UFG::allocator::free_link *)&v8->mCommands;
  v8->mCommands.mNode.mPrev = (UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *)v10;
  UFG::qEvent::Clear(&v8->mEventFlag_CompletedAllCommands);
  UFG::qEvent::Signal(&v8->mEventFlag_CommandAdded);
  v8->mFlag_UserEvent = 0;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)v8);
}

// File Line: 148
// RVA: 0xA21620
void __fastcall Illusion::RenderThreadManager::RenderThreadFunctionBridge(void *arg)
{
  Illusion::RenderThreadManager::RenderThreadFunction((Illusion::RenderThreadManager *)arg);
}

// File Line: 153
// RVA: 0xA21370
void __fastcall Illusion::RenderThreadManager::RenderThreadFunction(Illusion::RenderThreadManager *this)
{
  Illusion::RenderThreadManager *v1; // rbx
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *v2; // r8
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *v3; // rcx
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *v4; // rax
  int v5; // esi
  UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *v6; // rdi
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *v7; // r14
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *v8; // r15
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *v9; // rdx
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *v10; // rax
  _QWORD *v11; // rdi
  __int64 v12; // rcx
  __int64 v13[2]; // [rsp+20h] [rbp-58h]
  __int128 v14; // [rsp+80h] [rbp+8h]
  UFG::qNode<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand> *v15; // [rsp+90h] [rbp+18h]

  v1 = this;
  while ( v1->mRenderThreadEnabled )
  {
    if ( UFG::qEvent::Wait(&v1->mEventFlag_CommandAdded, v1->mEventWaitTimeoutMicroSeconds) )
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)v1);
      v2 = v1->mCommands.mNode.mNext;
      v3 = v2->mPrev;
      v4 = v2->mNext;
      v3->mNext = v4;
      v4->mPrev = v3;
      v2->mPrev = v2;
      v2->mNext = v2;
      v5 = (int)v2[1].mPrev;
      v6 = (UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *)v2[1].mNext;
      v7 = v2[2].mPrev;
      v8 = v2[2].mNext;
      v15 = v2;
      v9 = v2->mPrev;
      v10 = v2->mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v2->mPrev = v2;
      v2->mNext = v2;
      operator delete[](v2);
      if ( (UFG::qList<Illusion::RenderThreadManager::rtCommand,Illusion::RenderThreadManager::rtCommand,1,0> *)v1->mCommands.mNode.mNext == &v1->mCommands )
        UFG::qEvent::Clear(&v1->mEventFlag_CommandAdded);
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)v1);
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
          v14 = 0ui64;
          DWORD2(v14) = 0;
          ((void (__fastcall *)(ID3D11Device *, char *, __int128 *))UFG::gD3D11Device->vfptr->OMSetRenderTargets)(
            UFG::gD3D11Device,
            (char *)&v14 + 8,
            &v14);
          v11 = (_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
          (*(void (__fastcall **)(_QWORD, _QWORD))(*(_QWORD *)*v11 + 224i64))(*v11, v14);
          for ( LODWORD(v13[0]) = 0;
                (*(unsigned int (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, __int64))(*(_QWORD *)*v11 + 232i64))(
                  *v11,
                  v14,
                  0i64,
                  0i64,
                  v13[0]) == 1;
                LODWORD(v13[0]) = 0 )
          {
            UFG::qSleep(0);
          }
          if ( (_QWORD)v14 )
          {
            (*(void (**)(void))(*(_QWORD *)v14 + 16i64))();
            *(_QWORD *)&v14 = 0i64;
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
              ((void (*)(void))v6->mNode.mPrev->mPrev[1].mPrev)();
              v6->mNode.mPrev = 0i64;
            }
          }
          break;
        case 10:
          v1->mFlag_UserEvent = 1;
          break;
        default:
          break;
      }
      UFG::qMutex::Lock((LPCRITICAL_SECTION)v1);
      if ( ++v1->mNumCommandsCompleted == v1->mNumCommandsAdded )
        UFG::qEvent::Signal(&v1->mEventFlag_CompletedAllCommands);
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)v1);
    }
  }
}

// File Line: 421
// RVA: 0xA17160
void __fastcall Illusion::AddRenderThreadCommand(Illusion::RenderThreadCommand command, void *param, void *data0, void *data1)
{
  Illusion::RenderThreadManager::AddCommand(&Illusion::gRenderThreadManager, command, param, data0, data1);
}

// File Line: 429
// RVA: 0xA22E10
void __fastcall Illusion::WaitForRenderThread(Illusion *this)
{
  UFG::qEvent::Wait(&stru_1424527E8);
}

