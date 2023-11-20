// File Line: 65
// RVA: 0x6A0BA0
void __fastcall UFG::qArray<OutputInfo,0>::Reallocate(UFG::qArray<OutputInfo,0> *this, unsigned int newsize, const char *reason)
{
  unsigned int v3; // edi
  UFG::qArray<OutputInfo,0> *v4; // rbx
  unsigned __int64 v5; // rax
  UFG::allocator::free_link *v6; // rsi
  unsigned int v7; // er8
  OutputInfo *v8; // rcx
  __int64 v9; // rdx

  v3 = newsize;
  v4 = this;
  if ( newsize != this->size )
  {
    v5 = 120i64 * newsize;
    if ( !is_mul_ok(newsize, 0x78ui64) )
      v5 = -1i64;
    v6 = UFG::qMalloc(v5, reason, 0i64);
    if ( v4->p )
    {
      v7 = 0;
      if ( v4->size )
      {
        do
        {
          v8 = v4->p;
          v9 = v7++;
          v9 *= 120i64;
          *(UFG::allocator::free_link *)((char *)v6 + v9) = *(UFG::allocator::free_link *)((char *)v8->mOutputDesc.DeviceName
                                                                                         + v9);
          *(UFG::allocator::free_link *)((char *)v6 + v9 + 8) = *(UFG::allocator::free_link *)((char *)&v8->mOutputDesc.DeviceName[4]
                                                                                             + v9);
          *(UFG::allocator::free_link *)((char *)v6 + v9 + 16) = *(UFG::allocator::free_link *)((char *)&v8->mOutputDesc.DeviceName[8]
                                                                                              + v9);
          *(UFG::allocator::free_link *)((char *)v6 + v9 + 24) = *(UFG::allocator::free_link *)((char *)&v8->mOutputDesc.DeviceName[12]
                                                                                              + v9);
          *(UFG::allocator::free_link *)((char *)v6 + v9 + 32) = *(UFG::allocator::free_link *)((char *)&v8->mOutputDesc.DeviceName[16]
                                                                                              + v9);
          *(UFG::allocator::free_link *)((char *)v6 + v9 + 40) = *(UFG::allocator::free_link *)((char *)&v8->mOutputDesc.DeviceName[20]
                                                                                              + v9);
          *(UFG::allocator::free_link *)((char *)v6 + v9 + 48) = *(UFG::allocator::free_link *)((char *)&v8->mOutputDesc.DeviceName[24]
                                                                                              + v9);
          *(UFG::allocator::free_link *)((char *)v6 + v9 + 56) = *(UFG::allocator::free_link *)((char *)&v8->mOutputDesc.DeviceName[28]
                                                                                              + v9);
          *(UFG::allocator::free_link *)((char *)v6 + v9 + 64) = *(UFG::allocator::free_link *)((char *)&v8->mOutputDesc.DesktopCoordinates.left
                                                                                              + v9);
          *(UFG::allocator::free_link *)((char *)v6 + v9 + 72) = *(UFG::allocator::free_link *)((char *)&v8->mOutputDesc.DesktopCoordinates.right
                                                                                              + v9);
          *(UFG::allocator::free_link *)((char *)v6 + v9 + 80) = *(UFG::allocator::free_link *)((char *)&v8->mOutputDesc.AttachedToDesktop
                                                                                              + v9);
          *(UFG::allocator::free_link *)((char *)v6 + v9 + 88) = *(UFG::allocator::free_link *)((char *)&v8->mOutputDesc.Monitor
                                                                                              + v9);
          *(UFG::allocator::free_link *)((char *)v6 + v9 + 96) = *(UFG::allocator::free_link *)((char *)&v8->mOutputInterface
                                                                                              + v9);
          *(UFG::allocator::free_link *)((char *)v6 + v9 + 104) = *(UFG::allocator::free_link *)((char *)&v8->mAdapterInfoIndex
                                                                                               + v9);
          *(UFG::allocator::free_link *)((char *)v6 + v9 + 112) = *(UFG::allocator::free_link *)((char *)&v8->mpValidDisplayModes
                                                                                               + v9);
        }
        while ( v7 < v4->size );
      }
      operator delete[](v4->p);
    }
    v4->p = (OutputInfo *)v6;
    v4->capacity = v3;
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
void __fastcall UFG::qArray<UFG::StreamPriorityHandle *,0>::qArray<UFG::StreamPriorityHandle *,0>(UFG::qArray<UFG::StreamPriorityHandle *,0> *this, int initial_capacity, bool autosize_to_capacity)
{
  unsigned int v3; // edi
  bool v4; // r14
  int v5; // ebp
  UFG::qArray<UFG::StreamPriorityHandle *,0> *v6; // rbx
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::StreamPriorityHandle **v9; // rsi
  __int64 v10; // rcx

  v3 = 0;
  v4 = autosize_to_capacity;
  v5 = initial_capacity;
  v6 = this;
  this->p = 0i64;
  *(_QWORD *)&this->size = 0i64;
  if ( initial_capacity )
  {
    v7 = 8i64 * (unsigned int)initial_capacity;
    if ( !is_mul_ok((unsigned int)initial_capacity, 8ui64) )
      v7 = -1i64;
    v8 = UFG::qMalloc(v7, "qArray.Reallocate(Constructor)", 0i64);
    v9 = (UFG::StreamPriorityHandle **)v8;
    if ( v6->p )
    {
      if ( v6->size > 0 )
      {
        do
        {
          v10 = v3++;
          v8[v10] = (UFG::allocator::free_link)v6->p[v10];
        }
        while ( v3 < v6->size );
      }
      operator delete[](v6->p);
    }
    v6->p = v9;
    v6->capacity = v5;
  }
  if ( v4 )
    v6->size = v5;
}

// File Line: 117
// RVA: 0xE0130
void __fastcall UFG::qArray<unsigned long,0>::Resize(UFG::qArray<unsigned long,0> *this, unsigned int newsize, const char *reason)
{
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // edx

  v3 = this->size;
  v4 = newsize - this->size;
  JUMPOUT(v4, 0, UFG::qArray<unsigned long,0>::Grow);
  v5 = -v4;
  if ( v5 )
  {
    if ( v5 < v3 )
      this->size = v3 - v5;
    else
      this->size = 0;
  }
}

// File Line: 131
// RVA: 0x497F60
void __fastcall UFG::qArray<bool,0>::Clone(UFG::qArray<bool,0> *this, UFG::qArray<bool,0> *_dst)
{
  UFG::qArray<bool,0> *v2; // rsi
  bool *v3; // rcx
  UFG::qArray<bool,0> *v4; // rdi
  unsigned int v5; // ebx
  __int64 v6; // rdx
  bool v7; // al

  v2 = this;
  v3 = _dst->p;
  v4 = _dst;
  if ( v3 )
    operator delete[](v3);
  v5 = 0;
  v4->p = 0i64;
  *(_QWORD *)&v4->size = 0i64;
  if ( v2->size )
  {
    v4->size = v2->size;
    v4->p = (bool *)UFG::qMalloc(v2->size, "qArray.Clone", 0i64);
    v4->capacity = v2->size;
    if ( v2->size > 0 )
    {
      do
      {
        v6 = v5;
        v7 = v2->p[v5++];
        v4->p[v6] = v7;
      }
      while ( v5 < v2->size );
    }
  }
  else
  {
    v4->p = 0i64;
    *(_QWORD *)&v4->size = 0i64;
  }
}

// File Line: 152
// RVA: 0x437A10
void __fastcall UFG::qArray<UFG::PartRequest *,0>::~qArray<UFG::PartRequest *,0>(UFG::qArray<ActiveMultiMorphTarget,0> *this)
{
  UFG::qArray<ActiveMultiMorphTarget,0> *v1; // rbx
  ActiveMultiMorphTarget *v2; // rcx

  v1 = this;
  v2 = this->p;
  if ( v2 )
    operator delete[](v2);
  v1->p = 0i64;
  *(_QWORD *)&v1->size = 0i64;
}

// File Line: 157
// RVA: 0x1F21D0
void __fastcall UFG::qArray<UFG::PropertyLookup,0>::Clear(UFG::qArray<UFG::PropertyLookup,0> *this)
{
  UFG::qArray<UFG::PropertyLookup,0> *v1; // [rsp+40h] [rbp+8h]

  v1 = this;
  if ( this->p )
    Illusion::ShaderParam::operator delete(this->p);
  v1->p = 0i64;
  *(_QWORD *)&v1->size = 0i64;
}

// File Line: 193
// RVA: 0x4FC40
void __fastcall UFG::qArray<unsigned long,0>::Grow(UFG::qArray<unsigned long,0> *this, unsigned int expand, const char *reason)
{
  UFG::qArray<unsigned long,0> *v3; // rdi
  unsigned int v4; // ebx
  unsigned int v5; // edx
  unsigned int v6; // edx

  v3 = this;
  v4 = expand + this->size;
  v5 = this->capacity;
  if ( v4 <= v5 )
  {
    this->size = v4;
  }
  else
  {
    if ( v5 )
      v6 = 2 * v5;
    else
      v6 = 1;
    for ( ; v6 < v4; v6 *= 2 )
      ;
    if ( v6 <= 4 )
      v6 = 4;
    if ( v6 - v4 > 0x10000 )
      v6 = v4 + 0x10000;
    UFG::qArray<long,0>::Reallocate(this, v6, reason);
    v3->size = v4;
  }
}

// File Line: 246
// RVA: 0x164F40
UFG::qReflectOnDemandLoader::RequestCallback *__fastcall UFG::qArray<UFG::qReflectOnDemandLoader::RequestCallback,0>::Add(UFG::qArray<UFG::qReflectOnDemandLoader::RequestCallback,0> *this, const char *reason)
{
  __int64 v2; // rsi
  const char *v3; // r8
  unsigned int v4; // edx
  unsigned int v5; // ebx
  UFG::qArray<UFG::qReflectOnDemandLoader::RequestCallback,0> *v6; // rdi
  unsigned int v7; // edx

  v2 = this->size;
  v3 = reason;
  v4 = this->capacity;
  v5 = v2 + 1;
  v6 = this;
  if ( (signed int)v2 + 1 > v4 )
  {
    if ( v4 )
      v7 = 2 * v4;
    else
      v7 = 1;
    for ( ; v7 < v5; v7 *= 2 )
      ;
    if ( v7 - v5 > 0x10000 )
      v7 = v2 + 65537;
    UFG::qArray<UFG::qReflectOnDemandLoader::RequestCallback,0>::Reallocate(this, v7, v3);
  }
  v6->size = v5;
  return &v6->p[v2];
}

// File Line: 253
// RVA: 0x49840
unsigned int *__fastcall UFG::qArray<int,0>::Add(UFG::qArray<unsigned long,0> *this, const unsigned int *item, const char *reason)
{
  __int64 v3; // rsi
  const unsigned int *v4; // r14
  unsigned int v5; // edx
  unsigned int v6; // ebx
  UFG::qArray<unsigned long,0> *v7; // rdi
  unsigned int v8; // edx
  unsigned int *v9; // rcx

  v3 = this->size;
  v4 = item;
  v5 = this->capacity;
  v6 = v3 + 1;
  v7 = this;
  if ( (signed int)v3 + 1 > v5 )
  {
    if ( v5 )
      v8 = 2 * v5;
    else
      v8 = 1;
    for ( ; v8 < v6; v8 *= 2 )
      ;
    if ( v8 <= 4 )
      v8 = 4;
    if ( v8 - v6 > 0x10000 )
      v8 = v3 + 65537;
    UFG::qArray<long,0>::Reallocate(this, v8, reason);
  }
  v9 = v7->p;
  v7->size = v6;
  v9[v3] = *v4;
  return &v7->p[v3];
}

// File Line: 273
// RVA: 0x2650A0
UFG::NavWaypoint *__fastcall UFG::qArray<UFG::NavWaypoint,0>::Insert(UFG::qArray<UFG::NavWaypoint,0> *this, unsigned int index, UFG::NavWaypoint *item, const char *reason)
{
  signed __int64 v4; // rbp
  unsigned int v5; // edx
  unsigned int v6; // ebx
  UFG::NavWaypoint *v7; // rdi
  UFG::qArray<UFG::NavWaypoint,0> *v8; // rsi
  unsigned int v9; // edx
  signed __int64 v10; // rbx
  signed __int64 v11; // rcx
  UFG::NavWaypoint *v12; // rdx
  signed __int64 v13; // r8
  float v14; // xmm0_4
  float v15; // xmm1_4
  char v16; // al
  float v17; // eax
  UFG::NavWaypoint *v18; // rdx
  float v19; // xmm1_4
  signed __int64 v20; // rcx
  bool v21; // al

  v4 = index;
  v5 = this->capacity;
  v6 = this->size + 1;
  v7 = item;
  v8 = this;
  if ( v6 > v5 )
  {
    if ( v5 )
      v9 = 2 * v5;
    else
      v9 = 1;
    for ( ; v9 < v6; v9 *= 2 )
      ;
    if ( v9 - v6 > 0x10000 )
      v9 = this->size + 65537;
    UFG::qArray<UFG::NavWaypoint,0>::Reallocate(this, v9, reason);
  }
  v8->size = v6;
  v10 = v6 - 1;
  if ( (unsigned int)v10 > (unsigned int)v4 )
  {
    v11 = v10;
    do
    {
      v12 = v8->p;
      v10 = (unsigned int)(v10 - 1);
      v13 = (signed __int64)&v12[v10];
      v14 = *(float *)(v13 + 12);
      v15 = *(float *)(v13 + 16);
      v12[v11].m_navPosition.m_vPosition.x = *(float *)(v13 + 8);
      v12[v11].m_navPosition.m_vPosition.y = v14;
      v12[v11].m_navPosition.m_vPosition.z = v15;
      v16 = *(_BYTE *)(v13 + 24);
      if ( v16 )
      {
        v12[v11].m_navPosition.m_bValid = v16;
        v12[v11].m_navPosition.m_hkvMeshPosition = *(hkVector4f *)(v13 + 32);
        v12[v11].m_navPosition.m_packedKey = *(_DWORD *)(v13 + 48);
        v12[v11].m_navPosition.m_aiMeshUid = *(_DWORD *)(v13 + 52);
      }
      else
      {
        v12[v11].m_navPosition.m_bValid = 0;
      }
      --v11;
      v12[v11 + 1].m_pNavObject = *(UFG::NavObject **)(v13 + 64);
      v12[v11 + 1].m_stopPoint = *(_BYTE *)(v13 + 72);
      v12[v11 + 1].m_goalPoint = *(_BYTE *)(v13 + 73);
      v12[v11 + 1].m_canSmooth = *(_BYTE *)(v13 + 74);
    }
    while ( (unsigned int)v10 > (unsigned int)v4 );
  }
  v17 = v7->m_navPosition.m_vPosition.x;
  v18 = v8->p;
  v19 = v7->m_navPosition.m_vPosition.z;
  v20 = v4;
  v18[v20].m_navPosition.m_vPosition.y = v7->m_navPosition.m_vPosition.y;
  v18[v20].m_navPosition.m_vPosition.z = v19;
  v18[v20].m_navPosition.m_vPosition.x = v17;
  v21 = v7->m_navPosition.m_bValid;
  if ( v21 )
  {
    v18[v20].m_navPosition.m_bValid = v21;
    v18[v20].m_navPosition.m_hkvMeshPosition = v7->m_navPosition.m_hkvMeshPosition;
    v18[v20].m_navPosition.m_packedKey = v7->m_navPosition.m_packedKey;
    v18[v20].m_navPosition.m_aiMeshUid = v7->m_navPosition.m_aiMeshUid;
  }
  else
  {
    v18[v20].m_navPosition.m_bValid = 0;
  }
  v18[v20].m_pNavObject = v7->m_pNavObject;
  v18[v20].m_stopPoint = v7->m_stopPoint;
  v18[v20].m_goalPoint = v7->m_goalPoint;
  v18[v20].m_canSmooth = v7->m_canSmooth;
  return &v8->p[v20];
}

// File Line: 286
// RVA: 0x209D80
signed __int64 __fastcall UFG::qArray<UFG::Editor::DAGPath,0>::Find(UFG::qArray<UFG::Editor::DAGPath,0> *this, UFG::Editor::DAGPath *item)
{
  unsigned int v2; // er14
  UFG::Editor::DAGPath *v3; // rbp
  UFG::qArray<UFG::Editor::DAGPath,0> *v4; // r15
  signed __int64 v5; // rdi
  __int64 v6; // rax
  signed int v7; // esi
  __int64 v8; // rdx
  __int64 v9; // r9
  UFG::qSymbol *v10; // rax
  __int64 v11; // r8
  __int64 v12; // rbx

  v2 = 0;
  v3 = item;
  v4 = this;
  if ( this->size )
  {
    do
    {
      v5 = (signed __int64)&v4->p[v2];
      if ( v3->mSystemName.mUID == *(_DWORD *)(v5 + 32) && v3->mInterfaceName.mUID == *(_DWORD *)(v5 + 56) )
      {
        v6 = v3->mElements.size;
        if ( (_DWORD)v6 == *(_DWORD *)(v5 + 40) )
        {
          v7 = v3->mSubElements.size;
          if ( v7 == *(_DWORD *)(v5 + 64) )
          {
            v8 = 0i64;
            v9 = (unsigned int)v6;
            if ( v6 <= 0 )
            {
LABEL_10:
              v12 = 0i64;
              if ( v7 <= 0 )
                return v2;
              while ( !UFG::qString::operator!=(
                         &v3->mSubElements.p[v12],
                         (UFG::qString *)(*(_QWORD *)(v5 + 72) + 40 * v12)) )
              {
                v12 = (unsigned int)(v12 + 1);
                if ( (signed int)v12 >= v7 )
                  return v2;
              }
            }
            else
            {
              v10 = v3->mElements.p;
              v11 = *(_QWORD *)(v5 + 48) - (_QWORD)v10;
              while ( v10->mUID == *(unsigned int *)((char *)&v10->mUID + v11) )
              {
                ++v8;
                ++v10;
                if ( v8 >= v9 )
                  goto LABEL_10;
              }
            }
          }
        }
      }
      ++v2;
    }
    while ( v2 < v4->size );
  }
  return 0xFFFFFFFFi64;
}

// File Line: 325
// RVA: 0x522A50
void __fastcall UFG::qArray<UFG::qSymbol,0>::BubbleSortCorrect(UFG::qArray<UFG::qSymbol,0> *this, bool (__fastcall *CompareFunction)(UFG::qSymbol *, UFG::qSymbol *))
{
  bool (__fastcall *v2)(UFG::qSymbol *, UFG::qSymbol *); // r13
  UFG::qArray<UFG::qSymbol,0> *v3; // rsi
  unsigned int v4; // ebp
  char v5; // r12
  unsigned int v6; // ebx
  unsigned int v7; // eax
  signed __int64 v8; // rdi
  signed __int64 v9; // r14
  signed __int64 v10; // r15
  UFG::qSymbol *v11; // rcx
  bool v12; // zf
  unsigned int v13; // eax

  v2 = CompareFunction;
  v3 = this;
  v4 = 0;
  do
  {
    v5 = 0;
    v6 = v4;
    if ( v4 )
      v6 = v4 - 1;
    v7 = v3->size;
    if ( v6 == v3->size )
      break;
    do
    {
      v8 = v6 + 1;
      if ( (_DWORD)v8 == v7 )
        break;
      v9 = v8;
      v10 = v6;
      if ( !v2(&v3->p[v10], &v3->p[v8]) )
      {
        v11 = v3->p;
        v12 = v5 == 0;
        v5 = 1;
        v13 = v11[v10].mUID;
        v11[v10] = v11[v9];
        if ( v12 )
          v4 = v6;
        v3->p[v9].mUID = v13;
      }
      v7 = v3->size;
      v6 = v8;
    }
    while ( (_DWORD)v8 != v3->size );
  }
  while ( v5 );
}

// File Line: 393
// RVA: 0x43CAE0
void __fastcall UFG::qArray<UFG::WeaponManager::WeaponEntry,0>::FastDelete(UFG::qArray<UFG::WeaponManager::WeaponEntry,0> *this, unsigned int index)
{
  UFG::qArray<UFG::WeaponManager::WeaponEntry,0> *v2; // r10
  UFG::WeaponManager::WeaponEntry *v3; // r9
  UFG::WeaponManager::WeaponEntry *v4; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectWeaponPropertiesComponent> *v5; // rdx
  UFG::SimObject *v6; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  v2 = this;
  v3 = &this->p[this->size - 1];
  v4 = &this->p[index];
  v4->mScore = v3->mScore;
  v5 = &v4->mComponent;
  HIDWORD(v5[-1].mPrev) = LODWORD(v3->mSpawnTime);
  *(float *)&v5[-1].mNext = v3->mTimeAlive;
  HIDWORD(v5[-1].mNext) = LODWORD(v3->mDistFromPlayer);
  LOBYTE(v5[-1].m_pPointer) = v3->mEquipped;
  v6 = v3->mComponent.m_pPointer;
  if ( v5->m_pPointer )
  {
    v7 = v5->mPrev;
    v8 = v5->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  v5->m_pPointer = v6;
  if ( v6 )
  {
    v9 = v6->m_SafePointerList.mNode.mPrev;
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mPrev = v9;
    v5->mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  if ( v2->size > 1 )
    --v2->size;
  else
    v2->size = 0;
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
char __fastcall UFG::qArray<DNA::PropertyData::Value *,0>::StableDelete(UFG::qArray<DNA::PropertyData::Value *,0> *this, DNA::PropertyData::Value *const *item)
{
  UFG::qArray<DNA::PropertyData::Value *,0> *v2; // r9
  unsigned int v3; // ecx
  __int64 v4; // r8
  DNA::PropertyData::Value *v5; // rdx
  int v7; // er8
  signed __int64 v8; // rdx

  v2 = this;
  v3 = this->size;
  v4 = 0i64;
  if ( !v3 )
    return 0;
  v5 = *item;
  while ( v5 != v2->p[v4] )
  {
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= v3 )
      return 0;
  }
  if ( (signed int)v4 < 0 )
    return 0;
  v7 = v4 + 1;
  if ( v7 != v3 )
  {
    v8 = v7;
    do
    {
      ++v7;
      ++v8;
      v2->p[v8 - 2] = v2->p[v8 - 1];
    }
    while ( v7 != v2->size );
  }
  if ( v2->size > 1 )
    --v2->size;
  else
    v2->size = 0;
  return 1;
}

// File Line: 423
// RVA: 0x443480
void __fastcall UFG::qArray<UFG::WeaponManager::WeaponEntry,0>::StableDelete(UFG::qArray<UFG::WeaponManager::WeaponEntry,0> *this, unsigned int index)
{
  signed int v2; // er10
  UFG::qArray<UFG::WeaponManager::WeaponEntry,0> *v3; // rbx
  signed __int64 v4; // r9
  UFG::WeaponManager::WeaponEntry *v5; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectWeaponPropertiesComponent> *v6; // r8
  UFG::SimObject *v7; // r11
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax

  v2 = index + 1;
  v3 = this;
  if ( index + 1 != this->size )
  {
    v4 = v2;
    do
    {
      v5 = v3->p;
      v5[v4 - 1].mScore = v5[v4].mScore;
      v6 = &v5[v4 - 1].mComponent;
      *((_DWORD *)&v5[v4] - 11) = LODWORD(v5[v4].mSpawnTime);
      *((_DWORD *)&v5[v4] - 10) = LODWORD(v5[v4].mTimeAlive);
      *((_DWORD *)&v5[v4] - 9) = LODWORD(v5[v4].mDistFromPlayer);
      *((_BYTE *)&v5[v4] - 32) = v5[v4].mEquipped;
      v7 = v5[v4].mComponent.m_pPointer;
      if ( v6->m_pPointer )
      {
        v8 = v6->mPrev;
        v9 = v6->mNext;
        v8->mNext = v9;
        v9->mPrev = v8;
        v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
        v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      }
      v6->m_pPointer = v7;
      if ( v7 )
      {
        v10 = v7->m_SafePointerList.mNode.mPrev;
        v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
        v6->mPrev = v10;
        v6->mNext = &v7->m_SafePointerList.mNode;
        v7->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      }
      ++v2;
      ++v4;
    }
    while ( v2 != v3->size );
  }
  if ( v3->size > 1 )
    --v3->size;
  else
    v3->size = 0;
}

// File Line: 464
// RVA: 0x2315C0
UFG::StreamPriorityHandle **__fastcall UFG::qArray<UFG::StreamPriorityHandle *,0>::Erase(UFG::qArray<UFG::StreamPriorityHandle *,0> *this, UFG::StreamPriorityHandle *const *item)
{
  UFG::qArray<UFG::StreamPriorityHandle *,0> *v2; // r9
  __int64 v3; // rcx
  __int64 v4; // r8
  UFG::StreamPriorityHandle *v5; // rdx
  int v7; // edx
  signed __int64 v8; // r10
  UFG::StreamPriorityHandle **v9; // rax

  v2 = this;
  v3 = this->size;
  v4 = 0i64;
  if ( (_DWORD)v3 )
  {
    v5 = *item;
    while ( v5 != v2->p[v4] )
    {
      v4 = (unsigned int)(v4 + 1);
      if ( (unsigned int)v4 >= (unsigned int)v3 )
        return &v2->p[v3];
    }
    if ( (signed int)v4 >= 0 )
    {
      v7 = v4 + 1;
      if ( (_DWORD)v4 + 1 != (_DWORD)v3 )
      {
        v8 = v7;
        do
        {
          ++v7;
          ++v8;
          v2->p[v8 - 2] = v2->p[v8 - 1];
        }
        while ( v7 != v2->size );
      }
      if ( v2->size <= 1 )
      {
        v9 = v2->p;
        v2->size = 0;
        return &v9[(signed int)v4];
      }
      v3 = (signed int)v4;
      --v2->size;
    }
  }
  return &v2->p[v3];
}

