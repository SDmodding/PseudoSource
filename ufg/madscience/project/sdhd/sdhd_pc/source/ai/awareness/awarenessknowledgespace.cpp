// File Line: 13
// RVA: 0x14B94D0
hkSeekableStreamReader *dynamic_initializer_for__UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates__()
{
  hkSeekableStreamReader *v0; // rbx
  int i; // edi
  hkSeekableStreamReader *result; // rax

  v0 = &UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates;
  for ( i = 499; i >= 0; --i )
  {
    result = Assembly::GetRCX(v0);
    v0 = (hkSeekableStreamReader *)((char *)v0 + 100);
  }
  return result;
}

// File Line: 29
// RVA: 0x39AD50
void __fastcall UFG::AIAwareness::KnowledgeSpace::GlobalUpdate(float deltaTime)
{
  UFG::DataStreamer::Handle *p_mNext; // r8
  int v2; // r10d
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *mNext; // rax
  unsigned __int16 v4; // r9
  int v5; // r11d
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v6; // rax
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v7; // rcx
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> **v8; // rax
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v9; // rcx
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *v10; // rdx
  __int64 v11; // rcx
  int mPrev_high; // xmm0_4
  int v13; // xmm1_4
  int v14; // xmm0_4
  int v15; // xmm1_4
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> v16; // xmm3
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> v17; // xmm2
  UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> v18; // xmm1

  p_mNext = (UFG::DataStreamer::Handle *)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext[-6].mNext;
  v2 = 0;
  UFG::AIAwareness::KnowledgeSpace::mNumSpaceCandidates = 0;
  if ( (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> **)&UFG::SceneryGroupComponent::s_SceneryGroupComponentList.mNode.mNext[-6].mNext != &UFG::SectionChooser::mStreamBSPDebugData.mNext )
  {
    while ( 1 )
    {
      mNext = p_mNext[2].mNext;
      v4 = 0;
      v5 = WORD2(mNext[5].mNext);
      if ( WORD2(mNext[5].mNext) )
        break;
LABEL_8:
      p_mNext = (UFG::DataStreamer::Handle *)&p_mNext[2].mPrev[-6].mNext;
      if ( p_mNext == (UFG::DataStreamer::Handle *)&UFG::SectionChooser::mStreamBSPDebugData.mNext )
        return;
    }
    while ( 1 )
    {
      v6 = p_mNext[2].mNext;
      v7 = v6[7].mNext;
      v8 = &v6[7].mNext;
      v9 = v7 ? (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)((char *)v7 + (_QWORD)v8) : 0i64;
      v10 = &v9[8 * (unsigned __int64)v4];
      if ( v2 >= 500 )
        break;
      v11 = v2;
      ++v4;
      ++v2;
      v11 *= 100i64;
      *(_DWORD *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates.vfptr + v11) = 0;
      mPrev_high = HIDWORD(v10->mPrev);
      v13 = (int)v10->mNext;
      *(_DWORD *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates.vfptr + v11 + 4) = v10->mPrev;
      *(_DWORD *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates.m_memSizeAndFlags + v11) = mPrev_high;
      *(_DWORD *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates.m_referenceCount + v11 + 2) = v13;
      v14 = HIDWORD(v10[1].mPrev);
      v15 = (int)v10[1].mNext;
      *(_DWORD *)((char *)&unk_1423C1C90 + v11) = v10[1].mPrev;
      *(_DWORD *)((char *)&unk_1423C1C94 + v11) = v14;
      *(_DWORD *)((char *)&unk_1423C1C98 + v11) = v15;
      v16 = v10[5];
      v17 = v10[6];
      v18 = v10[7];
      *(UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)((char *)&unk_1423C1C9C + v11) = v10[4];
      UFG::AIAwareness::KnowledgeSpace::mNumSpaceCandidates = v2;
      *(UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)((char *)&unk_1423C1CAC + v11) = v16;
      *(UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)((char *)&unk_1423C1CBC + v11) = v17;
      *(UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)((char *)&unk_1423C1CCC + v11) = v18;
      *(_DWORD *)((char *)&unk_1423C1CDC + v11) = 2;
      *(_WORD *)((char *)&unk_1423C1CE0 + v11) = 512;
      if ( v4 >= v5 )
        goto LABEL_8;
    }
  }
}

// File Line: 61
// RVA: 0x39B820
void __fastcall UFG::AIAwareness::KnowledgeSpace::Update(UFG::AIAwareness::KnowledgeSpace *this, float deltaTime)
{
  int v2; // r10d
  UFG::AIAwareness::KnowledgeSpace *v4; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mSimObject; // rdx
  bool v6; // sf
  __int64 v7; // rax
  UFG::AIAwareness::KnowledgeSpace::PositionCandidate *v8; // r11
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::SimObject *m_pPointer; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax

  v2 = 0;
  this->mHasOverridingTarget = 0;
  if ( this->mNumPositionCandidates > 0 )
  {
    v4 = this;
    p_mSimObject = &this->mPositionCandidates[0].mSimObject;
    do
    {
      if ( v4->mPositionCandidates[0].mPriority == TARGETPRIORITY_OVERRIDE )
        this->mHasOverridingTarget = 1;
      if ( v4->mPositionCandidates[0].mLockRefCount <= 0
        && (v6 = (char)(v4->mPositionCandidates[0].mRefCount - 1) < 0, --v4->mPositionCandidates[0].mRefCount, v6) )
      {
        v7 = --this->mNumPositionCandidates;
        if ( v2 == (_DWORD)v7 )
          return;
        v8 = &this->mPositionCandidates[v7];
        v4->mPositionCandidates[0].mPriority = v8->mPriority;
        y = v8->mPosition.y;
        z = v8->mPosition.z;
        v4->mPositionCandidates[0].mPosition.x = v8->mPosition.x;
        v4->mPositionCandidates[0].mPosition.y = y;
        v4->mPositionCandidates[0].mPosition.z = z;
        v4->mPositionCandidates[0].mName.mUID = v8->mName.mUID;
        m_pPointer = v8->mSimObject.m_pPointer;
        if ( p_mSimObject->m_pPointer )
        {
          mPrev = p_mSimObject->mPrev;
          mNext = p_mSimObject->mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_mSimObject->mPrev = p_mSimObject;
          p_mSimObject->mNext = p_mSimObject;
        }
        p_mSimObject->m_pPointer = m_pPointer;
        if ( m_pPointer )
        {
          v14 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
          v14->mNext = p_mSimObject;
          p_mSimObject->mPrev = v14;
          p_mSimObject->mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
          m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mSimObject;
        }
        v4->mPositionCandidates[0].mType = v8->mType;
        v4->mPositionCandidates[0].mLockRefCount = v8->mLockRefCount;
        v4->mPositionCandidates[0].mRefCount = v8->mRefCount;
      }
      else
      {
        ++v2;
        v4 = (UFG::AIAwareness::KnowledgeSpace *)((char *)v4 + 56);
        p_mSimObject = (UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *)((char *)p_mSimObject + 56);
      }
    }
    while ( v2 < this->mNumPositionCandidates );
  }
}

// File Line: 132
// RVA: 0x39A6F0
void __fastcall UFG::AIAwareness::KnowledgeSpace::AddTargetSimObject(
        UFG::AIAwareness::KnowledgeSpace *this,
        UFG::SimObject *pSimObject,
        UFG::AIAwareness::TargetPriority priority)
{
  int v4; // ecx
  __int64 mNumPositionCandidates; // r11
  UFG::qSymbol *p_mName; // r9
  float y; // xmm1_4
  float z; // xmm2_4
  __int64 v10; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  __int64 v15; // rax

  v4 = 0;
  mNumPositionCandidates = this->mNumPositionCandidates;
  if ( (int)mNumPositionCandidates <= 0 )
    goto LABEL_6;
  p_mName = &this->mPositionCandidates[0].mName;
  while ( p_mName[8].mUID != 1 || p_mName->mUID != pSimObject->m_Name.mUID )
  {
    ++v4;
    p_mName += 14;
    if ( v4 >= (int)mNumPositionCandidates )
      goto LABEL_6;
  }
  if ( v4 < 0 )
  {
LABEL_6:
    if ( (int)mNumPositionCandidates < 100 )
    {
      this->mPositionCandidates[mNumPositionCandidates].mPriority = priority;
      y = UFG::qVector3::msZero.y;
      z = UFG::qVector3::msZero.z;
      v10 = this->mNumPositionCandidates;
      this->mPositionCandidates[v10].mPosition.x = UFG::qVector3::msZero.x;
      this->mPositionCandidates[v10].mPosition.y = y;
      this->mPositionCandidates[v10].mPosition.z = z;
      this->mPositionCandidates[this->mNumPositionCandidates].mName.mUID = pSimObject->m_Name.mUID;
      p_mSimObject = &this->mPositionCandidates[this->mNumPositionCandidates].mSimObject;
      if ( p_mSimObject->m_pPointer )
      {
        mPrev = p_mSimObject->mPrev;
        mNext = p_mSimObject->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mSimObject->mPrev = p_mSimObject;
        p_mSimObject->mNext = p_mSimObject;
      }
      p_mSimObject->m_pPointer = pSimObject;
      v14 = pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v14->mNext = p_mSimObject;
      p_mSimObject->mPrev = v14;
      p_mSimObject->mNext = &pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mSimObject;
      this->mPositionCandidates[this->mNumPositionCandidates].mType = CANDIDATETYPE_SIMOBJECT;
      this->mPositionCandidates[this->mNumPositionCandidates].mLockRefCount = 0;
      this->mPositionCandidates[this->mNumPositionCandidates++].mRefCount = 2;
    }
  }
  else
  {
    v15 = v4;
    ++this->mPositionCandidates[v15].mRefCount;
    if ( this->mPositionCandidates[v15].mPriority < priority )
      this->mPositionCandidates[v15].mPriority = priority;
  }
}

