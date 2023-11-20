// File Line: 326
// RVA: 0x1EE300
void __fastcall UFG::qNode<UFG::AddedProperty,UFG::_FullList>::~qNode<UFG::AddedProperty,UFG::_FullList>(UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *this)
{
  UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *v1; // ST08_8
  UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *v2; // ST00_8
  UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *v3; // [rsp+30h] [rbp+8h]

  v3 = this;
  v1 = this->mPrev;
  v2 = this->mNext;
  v1->mNext = v2;
  v2->mPrev = v1;
  v3->mPrev = v3;
  v3->mNext = v3;
}

// File Line: 382
// RVA: 0x1618F0
void __fastcall UFG::qReflectHandleBase::qReflectHandleBase(UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *this)
{
  this->mNode.mPrev = &this->mNode;
  this->mNode.mNext = &this->mNode;
}

// File Line: 384
// RVA: 0x5B1C40
void __fastcall UFG::qList<UFG::SpawnZone,UFG::SpawnRegionList,1,0>::~qList<UFG::SpawnZone,UFG::SpawnRegionList,1,0>(UFG::qList<SimObjectFlagSetTask,SimObjectFlagSetList,1,0> *this)
{
  UFG::qList<SimObjectFlagSetTask,SimObjectFlagSetList,1,0> *v1; // rbx
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *v2; // rdx
  UFG::qNode<SimObjectFlagSetTask,SimObjectFlagSetList> *v3; // rax

  v1 = this;
  UFG::qList<SimObjectFlagSetTask,SimObjectFlagSetList,1,0>::DeleteNodes(this);
  v2 = v1->mNode.mPrev;
  v3 = v1->mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
}

// File Line: 404
// RVA: 0x1CAE40
void __fastcall UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *this)
{
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *v1; // rbx
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *v2; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rcx

  v1 = this;
  v2 = (UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)this->mNode.mNext;
  if ( v2 != this )
  {
    do
    {
      v3 = v2->mNode.mPrev;
      v4 = v2->mNode.mNext;
      v3->mNext = v4;
      v4->mPrev = v3;
      v2->mNode.mPrev = &v2->mNode;
      v2->mNode.mNext = &v2->mNode;
      if ( v2[1].mNode.mPrev )
      {
        v5 = v2->mNode.mPrev;
        v6 = v2->mNode.mNext;
        v5->mNext = v6;
        v6->mPrev = v5;
        v2->mNode.mPrev = &v2->mNode;
        v2->mNode.mNext = &v2->mNode;
      }
      v2[1].mNode.mPrev = 0i64;
      v7 = v2->mNode.mPrev;
      v8 = v2->mNode.mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v2->mNode.mPrev = &v2->mNode;
      v2->mNode.mNext = &v2->mNode;
      operator delete[](v2);
      v2 = (UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)v1->mNode.mNext;
    }
    while ( v2 != v1 );
  }
}

// File Line: 405
// RVA: 0x1F22B0
void __fastcall UFG::qList<UFG::AddedProperty,UFG::_FullList,1,0>::Clear(UFG::qList<UFG::SchemaDef,UFG::SchemaDef,0,0> *this)
{
  UFG::qList<UFG::SchemaDef,UFG::SchemaDef,0,0> *i; // [rsp+70h] [rbp+8h]

  for ( i = this;
        i->mNode.mNext != (UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *)i;
        UFG::qList<UFG::SchemaDef,UFG::SchemaDef,0,0>::Remove(i, (UFG::SchemaDef *)i->mNode.mNext) )
  {
    ;
  }
}

// File Line: 415
// RVA: 0x1FB4F0
UFG::SchemaDef *__fastcall UFG::qList<UFG::SchemaDef,UFG::SchemaDef,0,0>::Remove(UFG::qList<UFG::SchemaDef,UFG::SchemaDef,0,0> *this, UFG::SchemaDef *obj)
{
  UFG::SchemaDef *v2; // ST00_8
  UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *v3; // ST10_8
  UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *v4; // ST08_8

  v2 = obj;
  v3 = obj->mPrev;
  v4 = obj->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = (UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *)&v2->mPrev;
  return obj;
}

// File Line: 428
// RVA: 0x5D5DC0
__int64 __fastcall UFG::qList<UFG::SocialLogData,UFG::SocialLogData,1,0>::Count(UFG::qList<UFG::SocialLogData,UFG::SocialLogData,1,0> *this)
{
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v1; // rdx
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> **v2; // rcx
  __int64 result; // rax
  signed __int64 i; // rdx

  v1 = this->mNode.mNext;
  v2 = &this[-2].mNode.mNext;
  result = 0i64;
  for ( i = (signed __int64)&v1[-2].mNext;
        (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> **)i != v2;
        i = *(_QWORD *)(i + 32) - 24i64 )
  {
    result = (unsigned int)(result + 1);
  }
  return result;
}

// File Line: 507
// RVA: 0x25940
void __fastcall UFG::qSList<CullResultBucket,CullResultBucket,1>::~qSList<CullResultBucket,CullResultBucket,1>(UFG::qSList<CullResultBucket,CullResultBucket,1> *this)
{
  UFG::qSList<CullResultBucket,CullResultBucket,1> *v1; // rbx
  UFG::qSNode<CullResultBucket,CullResultBucket> *v2; // rcx

  v1 = this;
  while ( v1->mHead )
  {
    v2 = v1->mHead;
    v1->mHead = v1->mHead->mNext;
    v2->mNext = 0i64;
    operator delete[](v2);
  }
}

// File Line: 702
// RVA: 0x200E50
void __fastcall UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal>>::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal>>(UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *this, UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> *v)
{
  UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> *v2; // r8
  UFG::Editor::Terminal *v3; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v10; // rax

  this->mPrev = (UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *)&this->mPrev;
  v2 = &this->mValue;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mValue.m_pPointer = 0i64;
  v3 = v->m_pPointer;
  if ( this->mValue.m_pPointer )
  {
    v4 = v2->mPrev;
    v5 = v2->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = v3;
  if ( v3 )
  {
    v6 = v3->m_SafePointerList.mNode.mPrev;
    v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mPrev = v6;
    v2->mNext = &v3->m_SafePointerList.mNode;
    v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  if ( v->m_pPointer )
  {
    v7 = v->mPrev;
    v8 = v->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *)&v->mPrev;
    v->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *)&v->mPrev;
  }
  v->m_pPointer = 0i64;
  v9 = v->mPrev;
  v10 = v->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *)&v->mPrev;
  v->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *)&v->mPrev;
}

// File Line: 1223
// RVA: 0x5A33A0
void __fastcall UFG::qList<UFG::qPointerNode<UFG::VoiceProfile>,UFG::qPointerNode<UFG::VoiceProfile>,1,0>::MergeSort(UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *this, bool (__fastcall *SwapFunction)(Render::DebugTriStrip *, Render::DebugTriStrip *))
{
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v2; // r13
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v3; // r14
  signed int v4; // er12
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v5; // rsi
  signed int v6; // ecx
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v7; // r15
  int v8; // edi
  signed int v9; // eax
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v10; // rbx
  signed int v11; // ebp
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> **v12; // rax
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v13; // rax
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *j; // rcx
  int i; // [rsp+60h] [rbp+8h]
  bool (__fastcall *v16)(Render::DebugTriStrip *, Render::DebugTriStrip *); // [rsp+68h] [rbp+10h]
  signed int v17; // [rsp+70h] [rbp+18h]

  v16 = SwapFunction;
  v2 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)this->mNode.mNext;
  v3 = this;
  if ( v2 == this )
    return;
  v4 = 1;
  while ( 2 )
  {
    v5 = v2;
    v6 = 0;
    v17 = v4;
    v2 = v3;
    v7 = v3;
    if ( v5 == v3 )
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
        if ( v10 == v3 )
          break;
      }
      v11 = v4;
      while ( 1 )
      {
        if ( v8 > 0 )
          goto LABEL_13;
        if ( v11 <= 0 || v10 == v3 )
          break;
        if ( !v8 )
        {
          v12 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> **)v10;
          v10 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v10->mNode.mNext;
          --v11;
          goto LABEL_18;
        }
LABEL_13:
        if ( !v11 || v10 == v3 || v16((Render::DebugTriStrip *)v5, (Render::DebugTriStrip *)v10) )
        {
          v12 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> **)v5;
          v5 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v5->mNode.mNext;
          --v8;
        }
        else
        {
          v12 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> **)v10;
          v10 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v10->mNode.mNext;
          --v11;
        }
LABEL_18:
        if ( v7 == v3 )
        {
          v2 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v12;
          *v12 = v3;
        }
        else
        {
          v7->mNode.mNext = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)v12;
          *v12 = v7;
        }
        v7 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v12;
      }
      v4 = v17;
      v6 = i;
      v5 = v10;
    }
    while ( v10 != v3 );
LABEL_23:
    v7->mNode.mNext = &v3->mNode;
    if ( v6 > 1 )
    {
      v4 *= 2;
      continue;
    }
    break;
  }
  v13 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v2->mNode.mNext;
  for ( j = v2; v13 != v3; v13 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)v13->mNode.mNext )
    j = v13;
  v3->mNode.mPrev = &j->mNode;
  v2->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v2->mNode;
}

