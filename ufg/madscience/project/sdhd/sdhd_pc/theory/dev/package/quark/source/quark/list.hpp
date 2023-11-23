// File Line: 326
// RVA: 0x1EE300
void __fastcall UFG::qNode<UFG::AddedProperty,UFG::_FullList>::~qNode<UFG::AddedProperty,UFG::_FullList>(
        UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *this)
{
  UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *mNext; // [rsp+0h] [rbp-28h]
  UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *mPrev; // [rsp+8h] [rbp-20h]

  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 382
// RVA: 0x1618F0
void __fastcall UFG::qReflectHandleBase::qReflectHandleBase(
        UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *this)
{
  this->mNode.mPrev = &this->mNode;
  this->mNode.mNext = &this->mNode;
}

// File Line: 384
// RVA: 0x5B1C40
void __fastcall UFG::qList<UFG::SpawnZone,UFG::SpawnRegionList,1,0>::~qList<UFG::SpawnZone,UFG::SpawnRegionList,1,0>(
        UFG::qList<SimObjectFlagSetTask,SimObjectFlagSetList,1,0> *this)
{
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *mPrev; // rdx
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *mNext; // rax

  UFG::qList<SimObjectFlagSetTask,SimObjectFlagSetList,1,0>::DeleteNodes(this);
  mPrev = this->mNode.mPrev;
  mNext = this->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mNode.mPrev = &this->mNode;
  this->mNode.mNext = &this->mNode;
}

// File Line: 404
// RVA: 0x1CAE40
void __fastcall UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(
        UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *this)
{
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *i; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rcx

  for ( i = (UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)this->mNode.mNext;
        i != this;
        i = (UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)this->mNode.mNext )
  {
    mPrev = i->mNode.mPrev;
    mNext = i->mNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mNode.mPrev = &i->mNode;
    i->mNode.mNext = &i->mNode;
    if ( i[1].mNode.mPrev )
    {
      v5 = i->mNode.mPrev;
      v6 = i->mNode.mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      i->mNode.mPrev = &i->mNode;
      i->mNode.mNext = &i->mNode;
    }
    i[1].mNode.mPrev = 0i64;
    v7 = i->mNode.mPrev;
    v8 = i->mNode.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    i->mNode.mPrev = &i->mNode;
    i->mNode.mNext = &i->mNode;
    operator delete[](i);
  }
}

// File Line: 405
// RVA: 0x1F22B0
void __fastcall UFG::qList<UFG::AddedProperty,UFG::_FullList,1,0>::Clear(
        UFG::qList<UFG::SchemaDef,UFG::SchemaDef,0,0> *this)
{
  while ( (UFG::qList<UFG::SchemaDef,UFG::SchemaDef,0,0> *)this->mNode.mNext != this )
    UFG::qList<UFG::SchemaDef,UFG::SchemaDef,0,0>::Remove(this, (UFG::SchemaDef *)this->mNode.mNext);
}

// File Line: 415
// RVA: 0x1FB4F0
UFG::SchemaDef *__fastcall UFG::qList<UFG::SchemaDef,UFG::SchemaDef,0,0>::Remove(
        UFG::qList<UFG::SchemaDef,UFG::SchemaDef,0,0> *this,
        UFG::SchemaDef *obj)
{
  UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *mNext; // [rsp+8h] [rbp-30h]
  UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *mPrev; // [rsp+10h] [rbp-28h]

  mPrev = obj->mPrev;
  mNext = obj->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  obj->mPrev = obj;
  obj->mNext = obj;
  return obj;
}

// File Line: 428
// RVA: 0x5D5DC0
__int64 __fastcall UFG::qList<UFG::SocialLogData,UFG::SocialLogData,1,0>::Count(
        UFG::qList<UFG::SocialLogData,UFG::SocialLogData,1,0> *this)
{
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *mNext; // rdx
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> **p_mNext; // rcx
  __int64 result; // rax
  __int64 i; // rdx

  mNext = this->mNode.mNext;
  p_mNext = &this[-2].mNode.mNext;
  result = 0i64;
  for ( i = (__int64)&mNext[-2].mNext;
        (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> **)i != p_mNext;
        i = *(_QWORD *)(i + 32) - 24i64 )
  {
    result = (unsigned int)(result + 1);
  }
  return result;
}

// File Line: 507
// RVA: 0x25940
void __fastcall UFG::qSList<CullResultBucket,CullResultBucket,1>::~qSList<CullResultBucket,CullResultBucket,1>(
        UFG::qSList<CullResultBucket,CullResultBucket,1> *this)
{
  UFG::qSNode<CullResultBucket,CullResultBucket> *mHead; // rcx

  while ( this->mHead )
  {
    mHead = this->mHead;
    this->mHead = this->mHead->mNext;
    mHead->mNext = 0i64;
    operator delete[](mHead);
  }
}

// File Line: 702
// RVA: 0x200E50
void __fastcall UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal>>::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal>>(
        UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *this,
        UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> *v)
{
  UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> *p_mValue; // r8
  UFG::Editor::Terminal *m_pPointer; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v10; // rax

  this->mPrev = this;
  this->mNext = this;
  p_mValue = &this->mValue;
  this->mValue.mPrev = &this->mValue;
  this->mValue.mNext = &this->mValue;
  this->mValue.m_pPointer = 0i64;
  m_pPointer = v->m_pPointer;
  if ( this->mValue.m_pPointer )
  {
    mPrev = p_mValue->mPrev;
    mNext = p_mValue->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mValue->mPrev = p_mValue;
    p_mValue->mNext = p_mValue;
  }
  p_mValue->m_pPointer = m_pPointer;
  if ( m_pPointer )
  {
    v6 = m_pPointer->UFG::qSafePointerNode<UFG::Editor::Terminal>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Editor::Terminal>::mPrev;
    v6->mNext = p_mValue;
    p_mValue->mPrev = v6;
    p_mValue->mNext = &m_pPointer->UFG::qSafePointerNode<UFG::Editor::Terminal>::m_SafePointerList.mNode;
    m_pPointer->UFG::qSafePointerNode<UFG::Editor::Terminal>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Editor::Terminal>::mPrev = p_mValue;
  }
  if ( v->m_pPointer )
  {
    v7 = v->mPrev;
    v8 = v->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v->mPrev = v;
    v->mNext = v;
  }
  v->m_pPointer = 0i64;
  v9 = v->mPrev;
  v10 = v->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v->mPrev = v;
  v->mNext = v;
}

// File Line: 1223
// RVA: 0x5A33A0
void __fastcall UFG::qList<UFG::qPointerNode<UFG::VoiceProfile>,UFG::qPointerNode<UFG::VoiceProfile>,1,0>::MergeSort(
        UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *this,
        bool (__fastcall *SwapFunction)(Render::DebugTriStrip *, Render::DebugTriStrip *))
{
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *mNext; // r13
  int v4; // r12d
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v5; // rsi
  int v6; // ecx
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v7; // r15
  int v8; // edi
  int v9; // eax
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v10; // rbx
  int v11; // ebp
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v12; // rax
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v13; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *j; // rcx
  int i; // [rsp+60h] [rbp+8h]
  int v17; // [rsp+70h] [rbp+18h]

  mNext = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)this->mNode.mNext;
  if ( mNext == this )
    return;
  v4 = 1;
  while ( 2 )
  {
    v5 = mNext;
    v6 = 0;
    v17 = v4;
    mNext = this;
    v7 = this;
    if ( v5 == this )
      goto LABEL_23;
    do
    {
      v8 = 0;
      v9 = 0;
      v10 = v5;
      for ( i = v6 + 1; v9 < v4; ++v9 )
      {
        v10 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v10->mNode.mNext;
        ++v8;
        if ( v10 == this )
          break;
      }
      v11 = v4;
      while ( 1 )
      {
        if ( v8 > 0 )
          goto LABEL_13;
        if ( v11 <= 0 || v10 == this )
          break;
        if ( !v8 )
        {
          v12 = v10;
          v10 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v10->mNode.mNext;
          --v11;
          goto LABEL_18;
        }
LABEL_13:
        if ( !v11 || v10 == this || SwapFunction((Render::DebugTriStrip *)v5, (Render::DebugTriStrip *)v10) )
        {
          v12 = v5;
          v5 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v5->mNode.mNext;
          --v8;
        }
        else
        {
          v12 = v10;
          v10 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v10->mNode.mNext;
          --v11;
        }
LABEL_18:
        if ( v7 == this )
        {
          mNext = v12;
          v12->mNode.mPrev = &this->mNode;
        }
        else
        {
          v7->mNode.mNext = &v12->mNode;
          v12->mNode.mPrev = &v7->mNode;
        }
        v7 = v12;
      }
      v4 = v17;
      v6 = i;
      v5 = v10;
    }
    while ( v10 != this );
LABEL_23:
    v7->mNode.mNext = &this->mNode;
    if ( v6 > 1 )
    {
      v4 *= 2;
      continue;
    }
    break;
  }
  v13 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)mNext->mNode.mNext;
  for ( j = &mNext->mNode;
        v13 != this;
        v13 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v13->mNode.mNext )
  {
    j = &v13->mNode;
  }
  this->mNode.mPrev = j;
  mNext->mNode.mPrev = &this->mNode;
  this->mNode.mNext = &mNext->mNode;
}

