// File Line: 13
// RVA: 0x14B94D0
hkSeekableStreamReader *dynamic_initializer_for__UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates__()
{
  hkSeekableStreamReader *v0; // rbx
  signed int v1; // edi
  hkSeekableStreamReader *result; // rax

  v0 = &UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates;
  v1 = 499;
  do
  {
    result = Assembly::GetRCX(v0);
    v0 = (hkSeekableStreamReader *)((char *)v0 + 100);
    --v1;
  }
  while ( v1 >= 0 );
  return result;
}

// File Line: 29
// RVA: 0x39AD50
void __fastcall UFG::AIAwareness::KnowledgeSpace::GlobalUpdate(float deltaTime)
{
  UFG::DataStreamer::Handle *v1; // r8
  signed int v2; // er10
  unsigned __int16 v3; // r9
  signed int v4; // er11
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v5; // rax
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v6; // rcx
  signed __int64 v7; // rax
  signed __int64 v8; // rcx
  unsigned __int64 v9; // rdx
  __int64 v10; // rcx
  int v11; // xmm0_4
  int v12; // xmm1_4
  int v13; // xmm0_4
  int v14; // xmm1_4
  __int128 v15; // xmm3
  __int128 v16; // xmm2
  __int128 v17; // xmm1

  v1 = (UFG::DataStreamer::Handle *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext[-6].mNext;
  v2 = 0;
  UFG::AIAwareness::KnowledgeSpace::mNumSpaceCandidates = 0;
  if ( (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> **)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext[-6].mNext != &UFG::SectionChooser::mStreamBSPDebugData.mNext )
  {
    while ( 1 )
    {
      v3 = 0;
      v4 = WORD2(v1[2].mNext[5].mNext);
      if ( v4 > 0 )
        break;
LABEL_8:
      v1 = (UFG::DataStreamer::Handle *)&v1[2].mPrev[-6].mNext;
      if ( v1 == (UFG::DataStreamer::Handle *)&UFG::SectionChooser::mStreamBSPDebugData.mNext )
        return;
    }
    while ( 1 )
    {
      v5 = v1[2].mNext;
      v6 = v5[7].mNext;
      v7 = (signed __int64)&v5[7].mNext;
      v8 = (signed __int64)(v6 ? (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)((char *)v6 + v7) : 0i64);
      v9 = v8 + ((unsigned __int64)v3 << 7);
      if ( v2 >= 500 )
        break;
      v10 = v2;
      ++v3;
      ++v2;
      v10 *= 100i64;
      *(_DWORD *)(v10 + 5406203008i64) = 0;
      v11 = *(_DWORD *)(v9 + 4);
      v12 = *(_DWORD *)(v9 + 8);
      *(_DWORD *)(v10 + 5406203012i64) = *(_DWORD *)v9;
      *(_DWORD *)(v10 + 5406203016i64) = v11;
      *(_DWORD *)(v10 + 5406203020i64) = v12;
      v13 = *(_DWORD *)(v9 + 20);
      v14 = *(_DWORD *)(v9 + 24);
      *(_DWORD *)(v10 + 5406203024i64) = *(_DWORD *)(v9 + 16);
      *(_DWORD *)(v10 + 5406203028i64) = v13;
      *(_DWORD *)(v10 + 5406203032i64) = v14;
      v15 = *(_OWORD *)(v9 + 80);
      v16 = *(_OWORD *)(v9 + 96);
      v17 = *(_OWORD *)(v9 + 112);
      *(_OWORD *)(v10 + 5406203036i64) = *(_OWORD *)(v9 + 64);
      UFG::AIAwareness::KnowledgeSpace::mNumSpaceCandidates = v2;
      *(_OWORD *)(v10 + 5406203052i64) = v15;
      *(_OWORD *)(v10 + 5406203068i64) = v16;
      *(_OWORD *)(v10 + 5406203084i64) = v17;
      *(_DWORD *)(v10 + 5406203100i64) = 2;
      *(_WORD *)(v10 + 5406203104i64) = 512;
      if ( v3 >= v4 )
        goto LABEL_8;
    }
  }
}

// File Line: 61
// RVA: 0x39B820
void __fastcall UFG::AIAwareness::KnowledgeSpace::Update(UFG::AIAwareness::KnowledgeSpace *this, float deltaTime)
{
  int v2; // er10
  UFG::AIAwareness::KnowledgeSpace *v3; // r9
  UFG::AIAwareness::KnowledgeSpace *v4; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rdx
  bool v6; // sf
  __int64 v7; // rax
  signed __int64 v8; // r11
  float v9; // xmm0_4
  float v10; // xmm1_4
  UFG::SimObject *v11; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax

  v2 = 0;
  v3 = this;
  this->mHasOverridingTarget = 0;
  if ( this->mNumPositionCandidates > 0 )
  {
    v4 = this;
    v5 = &this->mPositionCandidates[0].mSimObject;
    do
    {
      if ( v4->mPositionCandidates[0].mPriority == 2 )
        v3->mHasOverridingTarget = 1;
      if ( v4->mPositionCandidates[0].mLockRefCount <= 0
        && (v6 = (char)(v4->mPositionCandidates[0].mRefCount - 1) < 0, --v4->mPositionCandidates[0].mRefCount, v6) )
      {
        v7 = --v3->mNumPositionCandidates;
        if ( v2 == (_DWORD)v7 )
          return;
        v8 = (signed __int64)&v3->mPositionCandidates[v7];
        v4->mPositionCandidates[0].mPriority = *(_DWORD *)v8;
        v9 = *(float *)(v8 + 8);
        v10 = *(float *)(v8 + 12);
        v4->mPositionCandidates[0].mPosition.x = *(float *)(v8 + 4);
        v4->mPositionCandidates[0].mPosition.y = v9;
        v4->mPositionCandidates[0].mPosition.z = v10;
        v4->mPositionCandidates[0].mName.mUID = *(_DWORD *)(v8 + 16);
        v11 = *(UFG::SimObject **)(v8 + 40);
        if ( v5->m_pPointer )
        {
          v12 = v5->mPrev;
          v13 = v5->mNext;
          v12->mNext = v13;
          v13->mPrev = v12;
          v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
          v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
        }
        v5->m_pPointer = v11;
        if ( v11 )
        {
          v14 = v11->m_SafePointerList.mNode.mPrev;
          v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
          v5->mPrev = v14;
          v5->mNext = &v11->m_SafePointerList.mNode;
          v11->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
        }
        v4->mPositionCandidates[0].mType = *(_DWORD *)(v8 + 48);
        v4->mPositionCandidates[0].mLockRefCount = *(_BYTE *)(v8 + 52);
        v4->mPositionCandidates[0].mRefCount = *(_BYTE *)(v8 + 53);
      }
      else
      {
        ++v2;
        v4 = (UFG::AIAwareness::KnowledgeSpace *)((char *)v4 + 56);
        v5 = (UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *)((char *)v5 + 56);
      }
    }
    while ( v2 < v3->mNumPositionCandidates );
  }
}

// File Line: 132
// RVA: 0x39A6F0
void __fastcall UFG::AIAwareness::KnowledgeSpace::AddTargetSimObject(UFG::AIAwareness::KnowledgeSpace *this, UFG::SimObject *pSimObject, UFG::AIAwareness::TargetPriority priority)
{
  UFG::AIAwareness::KnowledgeSpace *v3; // r10
  signed int v4; // ecx
  UFG::SimObject *v5; // rbx
  __int64 v6; // r11
  UFG::qSymbol *v7; // r9
  float v8; // xmm1_4
  float v9; // xmm2_4
  signed __int64 v10; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  signed __int64 v15; // rax

  v3 = this;
  v4 = 0;
  v5 = pSimObject;
  v6 = v3->mNumPositionCandidates;
  if ( (signed int)v6 <= 0 )
    goto LABEL_6;
  v7 = &v3->mPositionCandidates[0].mName;
  while ( v7[8].mUID != 1 || v7->mUID != pSimObject->m_Name.mUID )
  {
    ++v4;
    v7 += 14;
    if ( v4 >= (signed int)v6 )
      goto LABEL_6;
  }
  if ( v4 < 0 )
  {
LABEL_6:
    if ( (signed int)v6 < 100 )
    {
      v3->mPositionCandidates[v6].mPriority = priority;
      v8 = UFG::qVector3::msZero.y;
      v9 = UFG::qVector3::msZero.z;
      v10 = v3->mNumPositionCandidates;
      v3->mPositionCandidates[v10].mPosition.x = UFG::qVector3::msZero.x;
      v3->mPositionCandidates[v10].mPosition.y = v8;
      v3->mPositionCandidates[v10].mPosition.z = v9;
      v3->mPositionCandidates[v3->mNumPositionCandidates].mName.mUID = pSimObject->m_Name.mUID;
      v11 = &v3->mPositionCandidates[v3->mNumPositionCandidates].mSimObject;
      if ( v11->m_pPointer )
      {
        v12 = v11->mPrev;
        v13 = v11->mNext;
        v12->mNext = v13;
        v13->mPrev = v12;
        v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
        v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
      }
      v11->m_pPointer = v5;
      v14 = v5->m_SafePointerList.mNode.mPrev;
      v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
      v11->mPrev = v14;
      v11->mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
      v3->mPositionCandidates[v3->mNumPositionCandidates].mType = 1;
      v3->mPositionCandidates[v3->mNumPositionCandidates].mLockRefCount = 0;
      v3->mPositionCandidates[v3->mNumPositionCandidates++].mRefCount = 2;
    }
  }
  else
  {
    v15 = v4;
    ++v3->mPositionCandidates[v15].mRefCount;
    if ( v3->mPositionCandidates[v15].mPriority < priority )
      v3->mPositionCandidates[v15].mPriority = priority;
  }
}

