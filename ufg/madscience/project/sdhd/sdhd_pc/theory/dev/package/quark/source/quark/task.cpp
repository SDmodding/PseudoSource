// File Line: 35
// RVA: 0x1468160
__int64 UFG::_dynamic_initializer_for__gTaskManager__()
{
  UFG::qTaskManager::qTaskManager(&UFG::gTaskManager);
  return atexit(UFG::_dynamic_atexit_destructor_for__gTaskManager__);
}

// File Line: 49
// RVA: 0x162160
void __fastcall UFG::qTaskFunctionDecl::qTaskFunctionDecl(UFG::qTaskFunctionDecl *this, UFG::qTaskFunctionDeclData *data)
{
  UFG::qTaskFunctionDecl *v2; // rbx
  UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *v3; // rax

  v2 = this;
  this->mPrev = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)&this->mPrev;
  this->mData = data;
  if ( !(_S8_4 & 1) )
  {
    _S8_4 |= 1u;
    stru_14235BC40.mTaskFunctionDecls.mNode.mPrev = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)&stru_14235BC40;
    stru_14235BC40.mTaskFunctionDecls.mNode.mNext = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)&stru_14235BC40;
    UFG::gTaskFunctionManager = &stru_14235BC40;
    atexit(UFG::qTaskFunctionManager::Instance_::_2_::_dynamic_atexit_destructor_for__sInstance__);
  }
  v3 = stru_14235BC40.mTaskFunctionDecls.mNode.mNext;
  stru_14235BC40.mTaskFunctionDecls.mNode.mNext = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)&v2->mPrev;
  v2->mPrev = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)&stru_14235BC40;
  v2->mNext = v3;
  v3->mPrev = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)&v2->mPrev;
}

// File Line: 66
// RVA: 0x17D9A0
bool __fastcall UFG::SortTaskFunctionDecl(UFG::qTaskFunctionDecl *a, UFG::qTaskFunctionDecl *b)
{
  const char *v2; // rdx
  const char *v3; // rcx
  signed int v4; // eax

  v2 = b->mData->mName;
  v3 = a->mData->mName;
  if ( !v3 || !v2 )
    return 1;
  v4 = -1;
  while ( *v3 && *v3 == *v2 )
  {
    ++v3;
    ++v2;
    if ( !--v4 )
      return 0;
  }
  return *(unsigned __int8 *)v3 - *(unsigned __int8 *)v2 < 0;
}

// File Line: 84
// RVA: 0x173670
void __fastcall UFG::qTaskFunctionManager::Init(UFG::qTaskFunctionManager *this)
{
  UFG::qTaskFunctionManager *v1; // rdi
  UFG::qSpuManager *v2; // rax
  UFG::qList<UFG::qSpuElf,UFG::qSpuElf,1,0> *v3; // rsi
  UFG::qSpuElf *i; // rbx
  UFG::qTaskFunctionManager *j; // rbx
  UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *v6; // rcx
  UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *v7; // rax
  char *v8; // rdx

  v1 = this;
  v2 = UFG::qSpuManager::Instance();
  v3 = UFG::qSpuManager::GetSpuElfList(v2);
  for ( i = (UFG::qSpuElf *)v3->mNode.mNext; i != (UFG::qSpuElf *)v3; i = (UFG::qSpuElf *)i->mNext )
    UFG::qTaskFunctionManager::OnSpuElfLoaded(v1, i);
  UFG::qList<UFG::qPointerNode<UFG::VoiceProfile>,UFG::qPointerNode<UFG::VoiceProfile>,1,0>::MergeSort(
    (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v1,
    (bool (__fastcall *)(Render::DebugTriStrip *, Render::DebugTriStrip *))UFG::SortTaskFunctionDecl);
  for ( j = (UFG::qTaskFunctionManager *)v1->mTaskFunctionDecls.mNode.mNext;
        j != v1;
        j = (UFG::qTaskFunctionManager *)j->mTaskFunctionDecls.mNode.mNext )
  {
    v6 = j[1].mTaskFunctionDecls.mNode.mPrev;
    v7 = v6[1].mPrev;
    if ( v7 )
      v8 = (char *)v7[1].mPrev;
    else
      v8 = &customWorldMapCaption;
    UFG::qPrintf(
      "[qTaskFunction] uid=0x%08x %-40s  PPU=0x%08x  SPU=0x%08x %s\n",
      LODWORD(v6[3].mPrev),
      v6[3].mNext,
      v6[2].mPrev,
      v6[1].mNext,
      v8);
  }
}

// File Line: 137
// RVA: 0x1787B0
void __fastcall UFG::qTaskFunctionManager::OnSpuElfLoaded(UFG::qTaskFunctionManager *this, UFG::qSpuElf *spu_elf)
{
  char *v2; // rbx
  UFG::qSpuElf *v3; // rsi
  char *v4; // rbp
  UFG::qTaskFunctionManager *v5; // rdi
  int v6; // edx
  UFG::qTaskFunctionManager *v7; // rax
  UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *v8; // rcx
  UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *v9; // rax
  UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *v10; // rax
  int source_b; // [rsp+20h] [rbp-18h]
  int v12; // [rsp+24h] [rbp-14h]
  int v13; // [rsp+28h] [rbp-10h]
  int i; // [rsp+2Ch] [rbp-Ch]

  v2 = spu_elf->mAddress;
  v3 = spu_elf;
  v4 = &v2[spu_elf->mNumBytes];
  v5 = this;
  source_b = 305419896;
  v12 = 305419896;
  v13 = 305419896;
  for ( i = 305419896; v2 < v4; v2 += 16 )
  {
    if ( !UFG::qMemCompare(v2, &source_b, 0x10u) )
    {
      v6 = *((_DWORD *)v2 + 12);
      if ( v6 )
      {
        v7 = (UFG::qTaskFunctionManager *)v5->mTaskFunctionDecls.mNode.mNext;
        if ( v7 != v5 )
        {
          while ( 1 )
          {
            v8 = v7[1].mTaskFunctionDecls.mNode.mPrev;
            if ( LODWORD(v8[3].mPrev) == v6 )
              break;
            v7 = (UFG::qTaskFunctionManager *)v7->mTaskFunctionDecls.mNode.mNext;
            if ( v7 == v5 )
              goto LABEL_9;
          }
          v9 = v8[2].mPrev;
          *((_QWORD *)v2 + 2) = v3;
          *((_QWORD *)v2 + 4) = v9;
          v10 = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)*((_QWORD *)v2 + 3);
          v8[1].mPrev = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)v3;
          v8[1].mNext = v10;
        }
      }
    }
LABEL_9:
    ;
  }
}

// File Line: 198
// RVA: 0x1621F0
void __fastcall UFG::qTaskManager::qTaskManager(UFG::qTaskManager *this)
{
  UFG::qTaskManager *v1; // rsi
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v2; // rdi
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v3; // [rsp+58h] [rbp+10h]
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v4; // [rsp+58h] [rbp+10h]

  v1 = this;
  v2 = this->mSingleFrameTaskGroupLists;
  `eh vector constructor iterator(
    this->mSingleFrameTaskGroupLists,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
  `eh vector constructor iterator(
    v1->mSingleFrameTaskLists,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
  v3 = &v1->mMultiFrameTaskGroups;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  v4 = &v1->mMultiFrameTasks;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v1->mSingleFrameTaskGroups = v2;
  v1->mSingleFrameTasks = v1->mSingleFrameTaskLists;
}

// File Line: 204
// RVA: 0x164460
void __fastcall UFG::qTaskManager::~qTaskManager(UFG::qTaskManager *this)
{
  UFG::qTaskManager *v1; // rbx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v2; // r8
  UFG::qTaskManager *v3; // rax
  UFG::qTaskManagerData *v4; // rdx
  UFG::qLinearAllocator *v5; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v6; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v7; // rax
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v8; // r8
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v9; // rdx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v10; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v11; // rax
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v12; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v13; // rax

  v1 = this;
  v2 = &this->mMultiFrameTasks;
  v3 = (UFG::qTaskManager *)this->mMultiFrameTasks.mNode.mNext;
  if ( v3 != (UFG::qTaskManager *)&this->mMultiFrameTasks )
  {
    do
    {
      v4 = v3->mData;
      v5 = v3->mAllocator;
      *(_QWORD *)&v4->mMaxThreads = v5;
      *(_QWORD *)&v5->mCurrentPos = v4;
      v3->mData = (UFG::qTaskManagerData *)v3;
      v3->mAllocator = (UFG::qLinearAllocator *)v3;
      v3 = (UFG::qTaskManager *)v2->mNode.mNext;
    }
    while ( v3 != (UFG::qTaskManager *)v2 );
  }
  v6 = v2->mNode.mPrev;
  v7 = v2->mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v8 = &v1->mMultiFrameTaskGroups;
  v9 = (UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *)v1->mMultiFrameTaskGroups.mNode.mNext;
  if ( v9 != &v1->mMultiFrameTaskGroups )
  {
    do
    {
      v10 = v9->mNode.mPrev;
      v11 = v9->mNode.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mNode.mPrev = &v9->mNode;
      v9->mNode.mNext = &v9->mNode;
      v9 = (UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *)v1->mMultiFrameTaskGroups.mNode.mNext;
    }
    while ( v9 != v8 );
  }
  v12 = v8->mNode.mPrev;
  v13 = v1->mMultiFrameTaskGroups.mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v8->mNode.mPrev = &v8->mNode;
  v1->mMultiFrameTaskGroups.mNode.mNext = &v1->mMultiFrameTaskGroups.mNode;
  `eh vector destructor iterator(
    v1->mSingleFrameTaskLists,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0>::~qList<UFG::allocator::page,UFG::allocator::page,0,0>);
  `eh vector destructor iterator(
    v1->mSingleFrameTaskGroupLists,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0>::~qList<UFG::allocator::page,UFG::allocator::page,0,0>);
}

// File Line: 210
// RVA: 0x173730
void __fastcall UFG::qTaskManager::Init(UFG::qTaskManager *this, void (__fastcall *startCallback)(), void (__fastcall *stopCallback)())
{
  this->mMode = 3;
  this->mData = 0i64;
  this->mAllocator = 0i64;
  this->mPrintSingleFrame = 0;
  UFG::qTaskManager::InitPlat(this, startCallback, stopCallback);
}

// File Line: 227
// RVA: 0x1680E0
void __fastcall UFG::qTaskManager::Close(UFG::qTaskManager *this)
{
  UFG::qTaskManager *v1; // rbx

  v1 = this;
  UFG::qTaskManager::SyncPlat(this, 0i64);
  UFG::qTaskManager::ClosePlat(v1);
  v1->mAllocator = 0i64;
}

// File Line: 249
// RVA: 0x1781B0
void __fastcall UFG::qTaskManager::NextFrame(UFG::qTaskManager *this, UFG::qLinearAllocator *frame_allocator, bool safety_check_frame)
{
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v3; // rax
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v4; // rdx

  v3 = this->mSingleFrameTaskGroupLists;
  this->mAllocator = frame_allocator;
  if ( this->mSingleFrameTaskGroups == this->mSingleFrameTaskGroupLists )
  {
    v3 = &this->mSingleFrameTaskGroupLists[1];
    v4 = &this->mSingleFrameTaskLists[1];
  }
  else
  {
    v4 = this->mSingleFrameTaskLists;
  }
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  this->mSingleFrameTaskGroups = v3;
  this->mSingleFrameTasks = v4;
  UFG::qTaskManager::NextFramePlat(this);
}

// File Line: 349
// RVA: 0x17E330
void __fastcall UFG::qTaskManager::Sync(UFG::qTaskManager *this, UFG::qTaskGroup *task_group)
{
  UFG::qTaskManager::SyncPlat(this, &task_group->mEndTask);
}

// File Line: 362
// RVA: 0x17E320
void __fastcall UFG::qTaskManager::Sync(UFG::qTaskManager *this, UFG::qTask *task)
{
  UFG::qTaskManager::SyncPlat(this, task);
}

// File Line: 375
// RVA: 0x17E340
void __fastcall UFG::qTaskManager::Sync(UFG::qTaskManager *this)
{
  UFG::qTaskManager::SyncPlat(this, 0i64);
}

// File Line: 387
// RVA: 0x165FD0
void __fastcall UFG::qTaskManager::AddDependent(UFG::qTaskManager *this, UFG::qTaskGroup *task_group, UFG::qTaskGroup *dependent)
{
  if ( dependent )
    UFG::qTaskManager::AddDependentPlat(this, &task_group->mStartTask, &dependent->mEndTask);
}

// File Line: 397
// RVA: 0x165FF0
void __fastcall UFG::qTaskManager::AddDependent(UFG::qTaskManager *this, UFG::qTaskGroup *task_group, UFG::qTask *dependent)
{
  if ( dependent )
    UFG::qTaskManager::AddDependentPlat(this, &task_group->mStartTask, dependent);
}

// File Line: 407
// RVA: 0x165FB0
void __fastcall UFG::qTaskManager::AddDependent(UFG::qTaskManager *this, UFG::qTask *task, UFG::qTaskGroup *dependent)
{
  if ( dependent )
    UFG::qTaskManager::AddDependentPlat(this, task, &dependent->mEndTask);
}

// File Line: 417
// RVA: 0x165FA0
void __fastcall UFG::qTaskManager::AddDependent(UFG::qTaskManager *this, UFG::qTask *task, UFG::qTask *dependent)
{
  JUMPOUT(dependent, 0i64, UFG::qTaskManager::AddDependentPlat);
}

