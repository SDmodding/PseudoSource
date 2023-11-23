// File Line: 65
// RVA: 0x6A0BA0
void __fastcall UFG::qArray<OutputInfo,0>::Reallocate(
        UFG::qArray<OutputInfo,0> *this,
        unsigned int newsize,
        const char *reason)
{
  unsigned __int64 v5; // rax
  UFG::allocator::free_link *v6; // rsi
  unsigned int i; // r8d
  OutputInfo *p; // rcx
  __int64 v9; // rdx

  if ( newsize != this->size )
  {
    v5 = 120i64 * newsize;
    if ( !is_mul_ok(newsize, 0x78ui64) )
      v5 = -1i64;
    v6 = UFG::qMalloc(v5, reason, 0i64);
    if ( this->p )
    {
      for ( i = 0;
            i < this->size;
            *(UFG::allocator::free_link *)((char *)v6 + v9 + 112) = *(UFG::allocator::free_link *)((char *)&p->mpValidDisplayModes
                                                                                                 + v9) )
      {
        p = this->p;
        v9 = i++;
        v9 *= 120i64;
        *(UFG::allocator::free_link *)((char *)v6 + v9) = *(UFG::allocator::free_link *)((char *)p->mOutputDesc.DeviceName
                                                                                       + v9);
        *(UFG::allocator::free_link *)((char *)v6 + v9 + 8) = *(UFG::allocator::free_link *)((char *)&p->mOutputDesc.DeviceName[4]
                                                                                           + v9);
        *(UFG::allocator::free_link *)((char *)v6 + v9 + 16) = *(UFG::allocator::free_link *)((char *)&p->mOutputDesc.DeviceName[8]
                                                                                            + v9);
        *(UFG::allocator::free_link *)((char *)v6 + v9 + 24) = *(UFG::allocator::free_link *)((char *)&p->mOutputDesc.DeviceName[12]
                                                                                            + v9);
        *(UFG::allocator::free_link *)((char *)v6 + v9 + 32) = *(UFG::allocator::free_link *)((char *)&p->mOutputDesc.DeviceName[16]
                                                                                            + v9);
        *(UFG::allocator::free_link *)((char *)v6 + v9 + 40) = *(UFG::allocator::free_link *)((char *)&p->mOutputDesc.DeviceName[20]
                                                                                            + v9);
        *(UFG::allocator::free_link *)((char *)v6 + v9 + 48) = *(UFG::allocator::free_link *)((char *)&p->mOutputDesc.DeviceName[24]
                                                                                            + v9);
        *(UFG::allocator::free_link *)((char *)v6 + v9 + 56) = *(UFG::allocator::free_link *)((char *)&p->mOutputDesc.DeviceName[28]
                                                                                            + v9);
        *(UFG::allocator::free_link *)((char *)v6 + v9 + 64) = *(UFG::allocator::free_link *)((char *)&p->mOutputDesc.DesktopCoordinates.left
                                                                                            + v9);
        *(UFG::allocator::free_link *)((char *)v6 + v9 + 72) = *(UFG::allocator::free_link *)((char *)&p->mOutputDesc.DesktopCoordinates.right
                                                                                            + v9);
        *(UFG::allocator::free_link *)((char *)v6 + v9 + 80) = *(UFG::allocator::free_link *)((char *)&p->mOutputDesc.AttachedToDesktop
                                                                                            + v9);
        *(UFG::allocator::free_link *)((char *)v6 + v9 + 88) = *(UFG::allocator::free_link *)((char *)&p->mOutputDesc.Monitor
                                                                                            + v9);
        *(UFG::allocator::free_link *)((char *)v6 + v9 + 96) = *(UFG::allocator::free_link *)((char *)&p->mOutputInterface
                                                                                            + v9);
        *(UFG::allocator::free_link *)((char *)v6 + v9 + 104) = *(UFG::allocator::free_link *)((char *)&p->mAdapterInfoIndex
                                                                                             + v9);
      }
      operator delete[](this->p);
    }
    this->p = (OutputInfo *)v6;
    this->capacity = newsize;
  }
}

// File Line: 83
// RVA: 0x200B40
void __fastcall UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>(UFG::qArray<unsigned long,0> *this)
{
  this->p = 0i64;
  *(_QWORD *)&this->size = 0i64;
}

// File Line: 90
// RVA: 0x22F310
void __fastcall UFG::qArray<UFG::StreamPriorityHandle *,0>::qArray<UFG::StreamPriorityHandle *,0>(
        UFG::qArray<UFG::StreamPriorityHandle *,0> *this,
        unsigned int initial_capacity,
        bool autosize_to_capacity)
{
  unsigned int v3; // edi
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::StreamPriorityHandle **v9; // rsi
  __int64 v10; // rcx

  v3 = 0;
  this->p = 0i64;
  *(_QWORD *)&this->size = 0i64;
  if ( initial_capacity )
  {
    v7 = 8i64 * initial_capacity;
    if ( !is_mul_ok(initial_capacity, 8ui64) )
      v7 = -1i64;
    v8 = UFG::qMalloc(v7, "qArray.Reallocate(Constructor)", 0i64);
    v9 = (UFG::StreamPriorityHandle **)v8;
    if ( this->p )
    {
      if ( this->size )
      {
        do
        {
          v10 = v3++;
          v8[v10] = (UFG::allocator::free_link)this->p[v10];
        }
        while ( v3 < this->size );
      }
      operator delete[](this->p);
    }
    this->p = v9;
    this->capacity = initial_capacity;
  }
  if ( autosize_to_capacity )
    this->size = initial_capacity;
}

// File Line: 117
// RVA: 0xE0130
void __fastcall UFG::qArray<unsigned long,0>::Resize(
        UFG::qArray<unsigned long,0> *this,
        unsigned int newsize,
        const char *reason)
{
  unsigned int size; // eax
  signed int v4; // edx
  unsigned int v5; // edx

  size = this->size;
  v4 = newsize - this->size;
  if ( v4 > 0 )
  {
    UFG::qArray<unsigned long,0>::Grow(this, v4, reason);
  }
  else
  {
    v5 = -v4;
    if ( v5 )
    {
      if ( v5 < size )
        this->size = size - v5;
      else
        this->size = 0;
    }
  }
}

// File Line: 131
// RVA: 0x497F60
void __fastcall UFG::qArray<bool,0>::Clone(UFG::qArray<bool,0> *this, UFG::qArray<bool,0> *_dst)
{
  bool *p; // rcx
  unsigned int v5; // ebx
  __int64 v6; // rdx
  bool v7; // al

  p = _dst->p;
  if ( p )
    operator delete[](p);
  v5 = 0;
  _dst->p = 0i64;
  *(_QWORD *)&_dst->size = 0i64;
  if ( this->size )
  {
    _dst->size = this->size;
    _dst->p = (bool *)UFG::qMalloc(this->size, "qArray.Clone", 0i64);
    _dst->capacity = this->size;
    if ( this->size )
    {
      do
      {
        v6 = v5;
        v7 = this->p[v5++];
        _dst->p[v6] = v7;
      }
      while ( v5 < this->size );
    }
  }
  else
  {
    _dst->p = 0i64;
    *(_QWORD *)&_dst->size = 0i64;
  }
}

// File Line: 152
// RVA: 0x437A10
void __fastcall UFG::qArray<UFG::PartRequest *,0>::~qArray<UFG::PartRequest *,0>(
        UFG::qArray<ActiveMultiMorphTarget,0> *this)
{
  ActiveMultiMorphTarget *p; // rcx

  p = this->p;
  if ( p )
    operator delete[](p);
  this->p = 0i64;
  *(_QWORD *)&this->size = 0i64;
}

// File Line: 157
// RVA: 0x1F21D0
void __fastcall UFG::qArray<UFG::PropertyLookup,0>::Clear(UFG::qArray<UFG::PropertyLookup,0> *this)
{
  if ( this->p )
    Illusion::ShaderParam::operator delete(this->p);
  this->p = 0i64;
  this->size = 0;
  this->capacity = 0;
}

// File Line: 193
// RVA: 0x4FC40
void __fastcall UFG::qArray<unsigned long,0>::Grow(
        UFG::qArray<unsigned long,0> *this,
        unsigned int expand,
        const char *reason)
{
  unsigned int v4; // ebx
  unsigned int capacity; // edx
  unsigned int v6; // edx

  v4 = expand + this->size;
  capacity = this->capacity;
  if ( v4 <= capacity )
  {
    this->size = v4;
  }
  else
  {
    if ( capacity )
      v6 = 2 * capacity;
    else
      v6 = 1;
    for ( ; v6 < v4; v6 *= 2 )
      ;
    if ( v6 <= 4 )
      v6 = 4;
    if ( v6 - v4 > 0x10000 )
      v6 = v4 + 0x10000;
    UFG::qArray<long,0>::Reallocate(this, v6, reason);
    this->size = v4;
  }
}

// File Line: 246
// RVA: 0x164F40
UFG::qReflectOnDemandLoader::RequestCallback *__fastcall UFG::qArray<UFG::qReflectOnDemandLoader::RequestCallback,0>::Add(
        UFG::qArray<UFG::qReflectOnDemandLoader::RequestCallback,0> *this,
        const char *reason)
{
  __int64 size; // rsi
  unsigned int capacity; // edx
  unsigned int v5; // ebx
  unsigned int v7; // edx

  size = this->size;
  capacity = this->capacity;
  v5 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v5; v7 *= 2 )
      ;
    if ( v7 - v5 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<UFG::qReflectOnDemandLoader::RequestCallback,0>::Reallocate(this, v7, reason);
  }
  this->size = v5;
  return &this->p[size];
}

// File Line: 253
// RVA: 0x49840
unsigned int *__fastcall UFG::qArray<int,0>::Add(
        UFG::qArray<unsigned long,0> *this,
        unsigned int *item,
        const char *reason)
{
  __int64 size; // rsi
  unsigned int capacity; // edx
  unsigned int v6; // ebx
  unsigned int v8; // edx
  unsigned int *p; // rcx

  size = this->size;
  capacity = this->capacity;
  v6 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v8 = 2 * capacity;
    else
      v8 = 1;
    for ( ; v8 < v6; v8 *= 2 )
      ;
    if ( v8 <= 4 )
      v8 = 4;
    if ( v8 - v6 > 0x10000 )
      v8 = size + 65537;
    UFG::qArray<long,0>::Reallocate(this, v8, reason);
  }
  p = this->p;
  this->size = v6;
  p[size] = *item;
  return &this->p[size];
}

// File Line: 273
// RVA: 0x2650A0
UFG::NavWaypoint *__fastcall UFG::qArray<UFG::NavWaypoint,0>::Insert(
        UFG::qArray<UFG::NavWaypoint,0> *this,
        unsigned int index,
        UFG::NavWaypoint *item,
        const char *reason)
{
  unsigned __int64 v4; // rbp
  unsigned int capacity; // edx
  unsigned int v6; // ebx
  unsigned int v9; // edx
  __int64 v10; // rbx
  __int64 v11; // rcx
  UFG::NavWaypoint *p; // rdx
  UFG::NavWaypoint *v13; // r8
  float y; // xmm0_4
  float z; // xmm1_4
  bool m_bValid; // al
  float x; // eax
  UFG::NavWaypoint *v18; // rdx
  float v19; // xmm1_4
  unsigned __int64 v20; // rcx
  bool v21; // al

  v4 = index;
  capacity = this->capacity;
  v6 = this->size + 1;
  if ( v6 > capacity )
  {
    if ( capacity )
      v9 = 2 * capacity;
    else
      v9 = 1;
    for ( ; v9 < v6; v9 *= 2 )
      ;
    if ( v9 - v6 > 0x10000 )
      v9 = this->size + 65537;
    UFG::qArray<UFG::NavWaypoint,0>::Reallocate(this, v9, reason);
  }
  this->size = v6;
  v10 = v6 - 1;
  if ( (unsigned int)v10 > (unsigned int)v4 )
  {
    v11 = v10;
    do
    {
      p = this->p;
      v10 = (unsigned int)(v10 - 1);
      v13 = &p[v10];
      y = v13->m_navPosition.m_vPosition.y;
      z = v13->m_navPosition.m_vPosition.z;
      p[v11].m_navPosition.m_vPosition.x = v13->m_navPosition.m_vPosition.x;
      p[v11].m_navPosition.m_vPosition.y = y;
      p[v11].m_navPosition.m_vPosition.z = z;
      m_bValid = v13->m_navPosition.m_bValid;
      if ( m_bValid )
      {
        p[v11].m_navPosition.m_bValid = m_bValid;
        p[v11].m_navPosition.m_hkvMeshPosition = v13->m_navPosition.m_hkvMeshPosition;
        p[v11].m_navPosition.m_packedKey = v13->m_navPosition.m_packedKey;
        p[v11].m_navPosition.m_aiMeshUid = v13->m_navPosition.m_aiMeshUid;
      }
      else
      {
        p[v11].m_navPosition.m_bValid = 0;
      }
      p[v11--].m_pNavObject = v13->m_pNavObject;
      p[v11 + 1].m_stopPoint = v13->m_stopPoint;
      p[v11 + 1].m_goalPoint = v13->m_goalPoint;
      p[v11 + 1].m_canSmooth = v13->m_canSmooth;
    }
    while ( (unsigned int)v10 > (unsigned int)v4 );
  }
  x = item->m_navPosition.m_vPosition.x;
  v18 = this->p;
  v19 = item->m_navPosition.m_vPosition.z;
  v20 = v4;
  v18[v20].m_navPosition.m_vPosition.y = item->m_navPosition.m_vPosition.y;
  v18[v20].m_navPosition.m_vPosition.z = v19;
  v18[v20].m_navPosition.m_vPosition.x = x;
  v21 = item->m_navPosition.m_bValid;
  if ( v21 )
  {
    v18[v20].m_navPosition.m_bValid = v21;
    v18[v20].m_navPosition.m_hkvMeshPosition = item->m_navPosition.m_hkvMeshPosition;
    v18[v20].m_navPosition.m_packedKey = item->m_navPosition.m_packedKey;
    v18[v20].m_navPosition.m_aiMeshUid = item->m_navPosition.m_aiMeshUid;
  }
  else
  {
    v18[v20].m_navPosition.m_bValid = 0;
  }
  v18[v20].m_pNavObject = item->m_pNavObject;
  v18[v20].m_stopPoint = item->m_stopPoint;
  v18[v20].m_goalPoint = item->m_goalPoint;
  v18[v20].m_canSmooth = item->m_canSmooth;
  return &this->p[v20];
}

// File Line: 286
// RVA: 0x209D80
__int64 __fastcall UFG::qArray<UFG::Editor::DAGPath,0>::Find(
        UFG::qArray<UFG::Editor::DAGPath,0> *this,
        UFG::Editor::DAGPath *item)
{
  unsigned int i; // r14d
  UFG::Editor::DAGPath *v5; // rdi
  unsigned int size; // eax
  signed int v7; // esi
  __int64 v8; // rdx
  __int64 v9; // r9
  UFG::qSymbol *p; // rax
  signed __int64 v11; // r8
  __int64 v12; // rbx

  for ( i = 0; i < this->size; ++i )
  {
    v5 = &this->p[i];
    if ( item->mSystemName.mUID == v5->mSystemName.mUID && item->mInterfaceName.mUID == v5->mInterfaceName.mUID )
    {
      size = item->mElements.size;
      if ( size == v5->mElements.size )
      {
        v7 = item->mSubElements.size;
        if ( v7 == v5->mSubElements.size )
        {
          v8 = 0i64;
          v9 = size;
          if ( item->mElements.size )
          {
            p = item->mElements.p;
            v11 = (char *)v5->mElements.p - (char *)p;
            while ( p->mUID == *(unsigned int *)((char *)&p->mUID + v11) )
            {
              ++v8;
              ++p;
              if ( v8 >= v9 )
                goto LABEL_10;
            }
          }
          else
          {
LABEL_10:
            v12 = 0i64;
            if ( v7 <= 0 )
              return i;
            while ( !UFG::qString::operator!=(&item->mSubElements.p[v12], &v5->mSubElements.p[v12]) )
            {
              v12 = (unsigned int)(v12 + 1);
              if ( (int)v12 >= v7 )
                return i;
            }
          }
        }
      }
    }
  }
  return 0xFFFFFFFFi64;
}

// File Line: 325
// RVA: 0x522A50
void __fastcall UFG::qArray<UFG::qSymbol,0>::BubbleSortCorrect(
        UFG::qArray<UFG::qSymbol,0> *this,
        bool (__fastcall *CompareFunction)(UFG::qSymbol *, UFG::qSymbol *))
{
  int v4; // ebp
  char v5; // r12
  int v6; // ebx
  unsigned int size; // eax
  __int64 v8; // rdi
  __int64 v9; // r14
  UFG::qSymbol *p; // rcx
  bool v11; // zf
  unsigned int mUID; // eax

  v4 = 0;
  do
  {
    v5 = 0;
    v6 = v4;
    if ( v4 )
      v6 = v4 - 1;
    size = this->size;
    if ( v6 == this->size )
      break;
    do
    {
      v8 = (unsigned int)(v6 + 1);
      if ( (_DWORD)v8 == size )
        break;
      v9 = v8;
      if ( !CompareFunction(&this->p[v6], &this->p[v8]) )
      {
        p = this->p;
        v11 = v5 == 0;
        v5 = 1;
        mUID = p[v6].mUID;
        p[v6] = p[v9];
        if ( v11 )
          v4 = v6;
        this->p[v9].mUID = mUID;
      }
      size = this->size;
      ++v6;
    }
    while ( (_DWORD)v8 != this->size );
  }
  while ( v5 );
}

// File Line: 393
// RVA: 0x43CAE0
void __fastcall UFG::qArray<UFG::WeaponManager::WeaponEntry,0>::FastDelete(
        UFG::qArray<UFG::WeaponManager::WeaponEntry,0> *this,
        unsigned int index)
{
  UFG::WeaponManager::WeaponEntry *v3; // r9
  UFG::WeaponManager::WeaponEntry *v4; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectWeaponPropertiesComponent> *p_mComponent; // rdx
  UFG::SimObject *m_pPointer; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  v3 = &this->p[this->size - 1];
  v4 = &this->p[index];
  v4->mScore = v3->mScore;
  p_mComponent = &v4->mComponent;
  HIDWORD(p_mComponent[-1].mPrev) = LODWORD(v3->mSpawnTime);
  *(float *)&p_mComponent[-1].mNext = v3->mTimeAlive;
  HIDWORD(p_mComponent[-1].mNext) = LODWORD(v3->mDistFromPlayer);
  LOBYTE(p_mComponent[-1].m_pPointer) = v3->mEquipped;
  m_pPointer = v3->mComponent.m_pPointer;
  if ( p_mComponent->m_pPointer )
  {
    mPrev = p_mComponent->mPrev;
    mNext = p_mComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mComponent->mPrev = p_mComponent;
    p_mComponent->mNext = p_mComponent;
  }
  p_mComponent->m_pPointer = m_pPointer;
  if ( m_pPointer )
  {
    v9 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v9->mNext = p_mComponent;
    p_mComponent->mPrev = v9;
    p_mComponent->mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mComponent;
  }
  if ( this->size > 1 )
    --this->size;
  else
    this->size = 0;
}

// File Line: 401
// RVA: 0x1FF630
void __fastcall UFG::qArray<unsigned long,0>::_FastDelete(UFG::qArray<unsigned long,0> *this, unsigned int index)
{
  this->p[index] = this->p[this->size - 1];
  if ( this->size > 1 )
    --this->size;
  else
    this->size = 0;
}

// File Line: 410
// RVA: 0x1A7470
char __fastcall UFG::qArray<DNA::PropertyData::Value *,0>::StableDelete(
        UFG::qArray<DNA::PropertyData::Value *,0> *this,
        DNA::PropertyData::Value **item)
{
  unsigned int size; // ecx
  __int64 v4; // r8
  DNA::PropertyData::Value *v5; // rdx
  int v7; // r8d
  __int64 v8; // rdx

  size = this->size;
  v4 = 0i64;
  if ( !size )
    return 0;
  v5 = *item;
  while ( v5 != this->p[v4] )
  {
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= size )
      return 0;
  }
  if ( (int)v4 < 0 )
    return 0;
  v7 = v4 + 1;
  if ( v7 != size )
  {
    v8 = v7;
    do
    {
      ++v7;
      ++v8;
      this->p[v8 - 2] = this->p[v8 - 1];
    }
    while ( v7 != this->size );
  }
  if ( this->size > 1 )
    --this->size;
  else
    this->size = 0;
  return 1;
}

// File Line: 423
// RVA: 0x443480
void __fastcall UFG::qArray<UFG::WeaponManager::WeaponEntry,0>::StableDelete(
        UFG::qArray<UFG::WeaponManager::WeaponEntry,0> *this,
        unsigned int index)
{
  int v2; // r10d
  __int64 v4; // r9
  UFG::WeaponManager::WeaponEntry *p; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectWeaponPropertiesComponent> *p_mComponent; // r8
  UFG::SimObject *m_pPointer; // r11
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax

  v2 = index + 1;
  if ( index + 1 != this->size )
  {
    v4 = v2;
    do
    {
      p = this->p;
      p[v4 - 1].mScore = p[v4].mScore;
      p_mComponent = &p[v4 - 1].mComponent;
      p[v4 - 1].mSpawnTime = p[v4].mSpawnTime;
      p[v4 - 1].mTimeAlive = p[v4].mTimeAlive;
      p[v4 - 1].mDistFromPlayer = p[v4].mDistFromPlayer;
      p[v4 - 1].mEquipped = p[v4].mEquipped;
      m_pPointer = p[v4].mComponent.m_pPointer;
      if ( p_mComponent->m_pPointer )
      {
        mPrev = p_mComponent->mPrev;
        mNext = p_mComponent->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mComponent->mPrev = p_mComponent;
        p_mComponent->mNext = p_mComponent;
      }
      p_mComponent->m_pPointer = m_pPointer;
      if ( m_pPointer )
      {
        v10 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v10->mNext = p_mComponent;
        p_mComponent->mPrev = v10;
        p_mComponent->mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mComponent;
      }
      ++v2;
      ++v4;
    }
    while ( v2 != this->size );
  }
  if ( this->size > 1 )
    --this->size;
  else
    this->size = 0;
}

// File Line: 464
// RVA: 0x2315C0
UFG::StreamPriorityHandle **__fastcall UFG::qArray<UFG::StreamPriorityHandle *,0>::Erase(
        UFG::qArray<UFG::StreamPriorityHandle *,0> *this,
        UFG::StreamPriorityHandle **item)
{
  __int64 size; // rcx
  __int64 v4; // r8
  UFG::StreamPriorityHandle *v5; // rdx
  int v7; // edx
  __int64 v8; // r10
  UFG::StreamPriorityHandle **p; // rax

  size = this->size;
  v4 = 0i64;
  if ( (_DWORD)size )
  {
    v5 = *item;
    while ( v5 != this->p[v4] )
    {
      v4 = (unsigned int)(v4 + 1);
      if ( (unsigned int)v4 >= (unsigned int)size )
        return &this->p[size];
    }
    if ( (int)v4 >= 0 )
    {
      v7 = v4 + 1;
      if ( (_DWORD)v4 + 1 != (_DWORD)size )
      {
        v8 = v7;
        do
        {
          ++v7;
          ++v8;
          this->p[v8 - 2] = this->p[v8 - 1];
        }
        while ( v7 != this->size );
      }
      if ( this->size <= 1 )
      {
        p = this->p;
        this->size = 0;
        return &p[(int)v4];
      }
      size = (int)v4;
      --this->size;
    }
  }
  return &this->p[size];
}

