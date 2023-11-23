// File Line: 35
// RVA: 0x1468160
__int64 UFG::_dynamic_initializer_for__gTaskManager__()
{
  UFG::qTaskManager::qTaskManager(&UFG::gTaskManager);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gTaskManager__);
}

// File Line: 49
// RVA: 0x162160
void __fastcall UFG::qTaskFunctionDecl::qTaskFunctionDecl(
        UFG::qTaskFunctionDecl *this,
        UFG::qTaskFunctionDeclData *data)
{
  UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *mNext; // rax

  this->mPrev = this;
  this->mNext = this;
  this->mData = data;
  if ( (_S8_4 & 1) == 0 )
  {
    _S8_4 |= 1u;
    stru_14235BC40.mTaskFunctionDecls.mNode.mPrev = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)&stru_14235BC40;
    stru_14235BC40.mTaskFunctionDecls.mNode.mNext = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)&stru_14235BC40;
    UFG::gTaskFunctionManager = &stru_14235BC40;
    atexit(UFG::qTaskFunctionManager::Instance_::_2_::_dynamic_atexit_destructor_for__sInstance__);
  }
  mNext = stru_14235BC40.mTaskFunctionDecls.mNode.mNext;
  stru_14235BC40.mTaskFunctionDecls.mNode.mNext = this;
  this->mPrev = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)&stru_14235BC40;
  this->mNext = mNext;
  mNext->mPrev = this;
}

// File Line: 66
// RVA: 0x17D9A0
bool __fastcall UFG::SortTaskFunctionDecl(UFG::qTaskFunctionDecl *a, UFG::qTaskFunctionDecl *b)
{
  const char *mName; // rdx
  const char *v3; // rcx
  int v4; // eax

  mName = b->mData->mName;
  v3 = a->mData->mName;
  if ( !v3 || !mName )
    return 1;
  v4 = -1;
  while ( *v3 && *v3 == *mName )
  {
    ++v3;
    ++mName;
    if ( !--v4 )
      return 0;
  }
  return *(unsigned __int8 *)v3 - *(unsigned __int8 *)mName < 0;
}

// File Line: 84
// RVA: 0x173670
void __fastcall UFG::qTaskFunctionManager::Init(UFG::qTaskFunctionManager *this)
{
  UFG::qSpuManager *v2; // rax
  UFG::qList<UFG::qSpuElf,UFG::qSpuElf,1,0> *SpuElfList; // rsi
  UFG::qSpuElf *i; // rbx
  UFG::qTaskFunctionManager *j; // rbx
  UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *mPrev; // rcx
  UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *v7; // rax
  const char *v8; // rdx

  v2 = UFG::qSpuManager::Instance();
  SpuElfList = UFG::qSpuManager::GetSpuElfList(v2);
  for ( i = (UFG::qSpuElf *)SpuElfList->mNode.mNext; i != (UFG::qSpuElf *)SpuElfList; i = (UFG::qSpuElf *)i->mNext )
    UFG::qTaskFunctionManager::OnSpuElfLoaded(this, i);
  UFG::qList<UFG::qPointerNode<UFG::VoiceProfile>,UFG::qPointerNode<UFG::VoiceProfile>,1,0>::MergeSort(
    (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)this,
    (bool (__fastcall *)(Render::DebugTriStrip *, Render::DebugTriStrip *))UFG::SortTaskFunctionDecl);
  for ( j = (UFG::qTaskFunctionManager *)this->mTaskFunctionDecls.mNode.mNext;
        j != this;
        j = (UFG::qTaskFunctionManager *)j->mTaskFunctionDecls.mNode.mNext )
  {
    mPrev = j[1].mTaskFunctionDecls.mNode.mPrev;
    v7 = mPrev[1].mPrev;
    if ( v7 )
      v8 = (const char *)v7[1].mPrev;
    else
      v8 = &customCaption;
    UFG::qPrintf(
      "[qTaskFunction] uid=0x%08x %-40s  PPU=0x%08x  SPU=0x%08x %s\n",
      LODWORD(mPrev[3].mPrev),
      (const char *)mPrev[3].mNext,
      mPrev[2].mPrev,
      mPrev[1].mNext,
      v8);
  }
}

// File Line: 137
// RVA: 0x1787B0
void __fastcall UFG::qTaskFunctionManager::OnSpuElfLoaded(
        UFG::qTaskFunctionManager *this,
        UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *spu_elf)
{
  char *mPrev; // rbx
  char *v4; // rbp
  int v6; // edx
  UFG::qTaskFunctionManager *mNext; // rax
  UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *v8; // rcx
  UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *v9; // rax
  UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *v10; // rax
  _DWORD source_b[6]; // [rsp+20h] [rbp-18h] BYREF

  mPrev = (char *)spu_elf[2].mPrev;
  v4 = &mPrev[SLODWORD(spu_elf[2].mNext)];
  source_b[0] = 305419896;
  source_b[1] = 305419896;
  source_b[2] = 305419896;
  for ( source_b[3] = 305419896; mPrev < v4; mPrev += 16 )
  {
    if ( !UFG::qMemCompare(mPrev, source_b, 0x10u) )
    {
      v6 = *((_DWORD *)mPrev + 12);
      if ( v6 )
      {
        mNext = (UFG::qTaskFunctionManager *)this->mTaskFunctionDecls.mNode.mNext;
        if ( mNext != this )
        {
          while ( 1 )
          {
            v8 = mNext[1].mTaskFunctionDecls.mNode.mPrev;
            if ( LODWORD(v8[3].mPrev) == v6 )
              break;
            mNext = (UFG::qTaskFunctionManager *)mNext->mTaskFunctionDecls.mNode.mNext;
            if ( mNext == this )
              goto LABEL_9;
          }
          v9 = v8[2].mPrev;
          *((_QWORD *)mPrev + 2) = spu_elf;
          *((_QWORD *)mPrev + 4) = v9;
          v10 = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)*((_QWORD *)mPrev + 3);
          v8[1].mPrev = spu_elf;
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
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *mSingleFrameTaskGroupLists; // rdi

  mSingleFrameTaskGroupLists = this->mSingleFrameTaskGroupLists;
  `eh vector constructor iterator(
    this->mSingleFrameTaskGroupLists,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
  `eh vector constructor iterator(
    this->mSingleFrameTaskLists,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
  this->mMultiFrameTaskGroups.mNode.mPrev = &this->mMultiFrameTaskGroups.mNode;
  this->mMultiFrameTaskGroups.mNode.mNext = &this->mMultiFrameTaskGroups.mNode;
  this->mMultiFrameTasks.mNode.mPrev = &this->mMultiFrameTasks.mNode;
  this->mMultiFrameTasks.mNode.mNext = &this->mMultiFrameTasks.mNode;
  this->mSingleFrameTaskGroups = mSingleFrameTaskGroupLists;
  this->mSingleFrameTasks = this->mSingleFrameTaskLists;
}

// File Line: 204
// RVA: 0x164460
void __fastcall UFG::qTaskManager::~qTaskManager(UFG::qTaskManager *this)
{
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *p_mMultiFrameTasks; // r8
  UFG::qTaskManager *mNext; // rax
  UFG::qTaskManagerData *mData; // rdx
  UFG::qLinearAllocator *mAllocator; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *mPrev; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v7; // rax
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *p_mMultiFrameTaskGroups; // r8
  UFG::qTaskManager *v9; // rdx
  UFG::qTaskManagerData *v10; // rcx
  UFG::qLinearAllocator *v11; // rax
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v12; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v13; // rax

  p_mMultiFrameTasks = &this->mMultiFrameTasks;
  mNext = (UFG::qTaskManager *)this->mMultiFrameTasks.mNode.mNext;
  if ( mNext != (UFG::qTaskManager *)&this->mMultiFrameTasks )
  {
    do
    {
      mData = mNext->mData;
      mAllocator = mNext->mAllocator;
      *(_QWORD *)&mData->mMaxThreads = mAllocator;
      *(_QWORD *)&mAllocator->mCurrentPos = mData;
      mNext->mData = (UFG::qTaskManagerData *)mNext;
      mNext->mAllocator = (UFG::qLinearAllocator *)mNext;
      mNext = (UFG::qTaskManager *)p_mMultiFrameTasks->mNode.mNext;
    }
    while ( mNext != (UFG::qTaskManager *)p_mMultiFrameTasks );
  }
  mPrev = p_mMultiFrameTasks->mNode.mPrev;
  v7 = p_mMultiFrameTasks->mNode.mNext;
  mPrev->mNext = v7;
  v7->mPrev = mPrev;
  p_mMultiFrameTasks->mNode.mPrev = &p_mMultiFrameTasks->mNode;
  p_mMultiFrameTasks->mNode.mNext = &p_mMultiFrameTasks->mNode;
  p_mMultiFrameTaskGroups = &this->mMultiFrameTaskGroups;
  v9 = (UFG::qTaskManager *)this->mMultiFrameTaskGroups.mNode.mNext;
  if ( v9 != (UFG::qTaskManager *)&this->mMultiFrameTaskGroups )
  {
    do
    {
      v10 = v9->mData;
      v11 = v9->mAllocator;
      *(_QWORD *)&v10->mMaxThreads = v11;
      *(_QWORD *)&v11->mCurrentPos = v10;
      v9->mData = (UFG::qTaskManagerData *)v9;
      v9->mAllocator = (UFG::qLinearAllocator *)v9;
      v9 = (UFG::qTaskManager *)this->mMultiFrameTaskGroups.mNode.mNext;
    }
    while ( v9 != (UFG::qTaskManager *)p_mMultiFrameTaskGroups );
  }
  v12 = p_mMultiFrameTaskGroups->mNode.mPrev;
  v13 = this->mMultiFrameTaskGroups.mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  p_mMultiFrameTaskGroups->mNode.mPrev = &p_mMultiFrameTaskGroups->mNode;
  this->mMultiFrameTaskGroups.mNode.mNext = &this->mMultiFrameTaskGroups.mNode;
  `eh vector destructor iterator(
    this->mSingleFrameTaskLists,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0>::~qList<UFG::allocator::page,UFG::allocator::page,0,0>);
  `eh vector destructor iterator(
    this->mSingleFrameTaskGroupLists,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0>::~qList<UFG::allocator::page,UFG::allocator::page,0,0>);
}

// File Line: 210
// RVA: 0x173730
void __fastcall UFG::qTaskManager::Init(
        UFG::qTaskManager *this,
        void (__fastcall *startCallback)(),
        void (__fastcall *stopCallback)())
{
  this->mMode = MODE_ALL_WORKERS;
  this->mData = 0i64;
  this->mAllocator = 0i64;
  this->mPrintSingleFrame = 0;
  UFG::qTaskManager::InitPlat(this, startCallback, stopCallback);
}

// File Line: 227
// RVA: 0x1680E0
void __fastcall UFG::qTaskManager::Close(UFG::qTaskManager *this)
{
  UFG::qTaskManager::SyncPlat(this, 0i64);
  UFG::qTaskManager::ClosePlat(this);
  this->mAllocator = 0i64;
}

// File Line: 249
// RVA: 0x1781B0
void __fastcall UFG::qTaskManager::NextFrame(
        UFG::qTaskManager *this,
        UFG::qLinearAllocator *frame_allocator,
        bool safety_check_frame)
{
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *mSingleFrameTaskGroupLists; // rax
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *mSingleFrameTaskLists; // rdx

  mSingleFrameTaskGroupLists = this->mSingleFrameTaskGroupLists;
  this->mAllocator = frame_allocator;
  if ( this->mSingleFrameTaskGroups == this->mSingleFrameTaskGroupLists )
  {
    mSingleFrameTaskGroupLists = &this->mSingleFrameTaskGroupLists[1];
    mSingleFrameTaskLists = &this->mSingleFrameTaskLists[1];
  }
  else
  {
    mSingleFrameTaskLists = this->mSingleFrameTaskLists;
  }
  mSingleFrameTaskGroupLists->mNode.mPrev = &mSingleFrameTaskGroupLists->mNode;
  mSingleFrameTaskGroupLists->mNode.mNext = &mSingleFrameTaskGroupLists->mNode;
  mSingleFrameTaskLists->mNode.mPrev = &mSingleFrameTaskLists->mNode;
  mSingleFrameTaskLists->mNode.mNext = &mSingleFrameTaskLists->mNode;
  this->mSingleFrameTaskGroups = mSingleFrameTaskGroupLists;
  this->mSingleFrameTasks = mSingleFrameTaskLists;
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
// attributes: thunk
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
void __fastcall UFG::qTaskManager::AddDependent(
        UFG::qTaskManager *this,
        UFG::qTaskGroup *task_group,
        UFG::qTaskGroup *dependent)
{
  if ( dependent )
    UFG::qTaskManager::AddDependentPlat(this, &task_group->mStartTask, &dependent->mEndTask);
}

// File Line: 397
// RVA: 0x165FF0
void __fastcall UFG::qTaskManager::AddDependent(
        UFG::qTaskManager *this,
        UFG::qTaskGroup *task_group,
        UFG::qTask *dependent)
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
  if ( dependent )
    UFG::qTaskManager::AddDependentPlat(this, task, dependent);
}

