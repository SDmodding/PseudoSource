// File Line: 21
// RVA: 0x1480590
__int64 dynamic_initializer_for__FalseCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FalseCondition", 0xFFFFFFFF);
  FalseCondition::sClassNameUID = result;
  return result;
}

// File Line: 32
// RVA: 0x1480630
__int64 dynamic_initializer_for__NotCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NotCondition", 0xFFFFFFFF);
  NotCondition::sClassNameUID = result;
  return result;
}

// File Line: 42
// RVA: 0x1480650
__int64 dynamic_initializer_for__ORCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ORCondition", 0xFFFFFFFF);
  ORCondition::sClassNameUID = result;
  return result;
}

// File Line: 55
// RVA: 0x26C200
char __fastcall CompareFloat(UFG::InEqualityOperator inEqualityOperator, float compareValue, float currentValue)
{
  __int32 v3; // ecx
  int v4; // ecx
  int v5; // ecx

  if ( inEqualityOperator )
  {
    v3 = inEqualityOperator - 1;
    if ( !v3 )
      return currentValue > compareValue;
    v4 = v3 - 1;
    if ( !v4 )
      return compareValue > currentValue;
    v5 = v4 - 1;
    if ( !v5 )
      return currentValue >= compareValue;
    if ( v5 == 1 )
      return compareValue >= currentValue;
  }
  else if ( currentValue == compareValue )
  {
    return 1;
  }
  return 0;
}

// File Line: 84
// RVA: 0x26C240
bool __fastcall CompareInt(UFG::InEqualityOperator inEqualityOperator, int compareValue, int currentValue)
{
  __int32 v3; // ecx
  int v4; // ecx
  int v5; // ecx

  if ( inEqualityOperator == IEO_EQUAL )
    return currentValue == compareValue;
  v3 = inEqualityOperator - 1;
  if ( !v3 )
    return currentValue > compareValue;
  v4 = v3 - 1;
  if ( !v4 )
    return currentValue < compareValue;
  v5 = v4 - 1;
  if ( !v5 )
    return currentValue >= compareValue;
  if ( v5 == 1 )
    return currentValue <= compareValue;
  return 0;
}

// File Line: 116
// RVA: 0x1480530
__int64 dynamic_initializer_for__DebugTestCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DebugTestCondition", 0xFFFFFFFF);
  DebugTestCondition::sClassNameUID = result;
  return result;
}

// File Line: 119
// RVA: 0x268BC0
void __fastcall DebugTestCondition::DebugTestCondition(DebugTestCondition *this)
{
  IConditionInit *v1; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *v2; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->mBreakPoint = 0;
  v1 = (IConditionInit *)&this->vfptr;
  v2 = (UFG::qNode<IConditionInit,IConditionInit> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (IConditionInitVtbl *)&IConditionInit::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&DebugTestCondition::`vftable'{for `Condition'};
  v1->vfptr = (IConditionInitVtbl *)&DebugTestCondition::`vftable'{for `IConditionInit'};
}

// File Line: 129
// RVA: 0x271C40
void __fastcall DebugTestCondition::ResolveReferences(DebugTestCondition *this, ActionNode *action_node)
{
  DebugTestCondition *v2; // rbx
  __int64 v3; // rax
  signed __int64 v4; // rdx
  __int64 *v5; // r8
  signed int v6; // ecx
  signed __int64 v7; // rax
  __int64 v8; // rax
  _QWORD *v9; // rcx

  v2 = this;
  v3 = ((__int64 (__fastcall *)(ActionNode *))action_node->vfptr[1].SetResourceOwner)(action_node);
  if ( v2 )
    v4 = (signed __int64)&v2->vfptr;
  else
    v4 = 0i64;
  v5 = (__int64 *)(v3 + 144);
  v6 = -1;
  v7 = *(_QWORD *)(v3 + 152) - 8i64;
  if ( (__int64 *)v7 == v5 - 1 )
    goto LABEL_9;
  while ( 1 )
  {
    ++v6;
    if ( v7 == v4 )
      break;
    v7 = *(_QWORD *)(v7 + 16) - 8i64;
    if ( (__int64 *)v7 == v5 - 1 )
      goto LABEL_9;
  }
  if ( v6 == -1 )
  {
LABEL_9:
    v8 = *v5;
    v9 = (_QWORD *)(v4 + 8);
    *(_QWORD *)(v8 + 8) = v4 + 8;
    *v9 = v8;
    v9[1] = v5;
    *v5 = v4 + 8;
  }
}

// File Line: 167
// RVA: 0x1480690
__int64 dynamic_initializer_for__PrintCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PrintCondition", 0xFFFFFFFF);
  PrintCondition::sClassNameUID = result;
  return result;
}

// File Line: 173
// RVA: 0x268F60
void __fastcall PrintCondition::PrintCondition(PrintCondition *this)
{
  PrintCondition *v1; // rbx
  BinString *v2; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->mBreakPoint = 0;
  this->vfptr = (Expression::IMemberMapVtbl *)&PrintCondition::`vftable';
  v2 = &this->m_Text;
  v2->mOffset = 1i64;
  BinString::Set(v2, &customWorldMapCaption);
  v1->m_PrintLocation.mValue = 2;
}

// File Line: 189
// RVA: 0x26FAD0
char __fastcall PrintCondition::Match(PrintCondition *this, ActionContext *context)
{
  UFG::TransformNodeComponent *v2; // rax
  const char *v4; // rdx

  if ( !this->m_PrintLocation.mValue )
  {
    if ( this->m_Text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      UFG::qPrintf("%s\n", (char *)&this->m_Text + (this->m_Text.mOffset & 0xFFFFFFFFFFFFFFFEui64));
      return 1;
    }
    UFG::qPrintf("%s\n", BinString::sEmptyString);
    return 1;
  }
  if ( this->m_PrintLocation.mValue != 1 )
  {
    if ( this->m_PrintLocation.mValue == 2 && context )
    {
      v2 = (UFG::TransformNodeComponent *)context->mSimObject.m_pPointer;
      if ( v2 )
        v2 = (UFG::TransformNodeComponent *)v2->mChildren.mNode.mNext;
      if ( v2 )
      {
        this->m_Text.mOffset;
        UFG::DrawDebugText(v2, &UFG::qColour::White, "%s", (int)v2);
        return 1;
      }
    }
    return 1;
  }
  if ( this->m_Text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    v4 = (char *)&this->m_Text + (this->m_Text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
  else
    v4 = BinString::sEmptyString;
  UFG::DrawDebugText(0, 0, &UFG::qColour::White, "%s", v4);
  return 1;
}

// File Line: 237
// RVA: 0x14806D0
__int64 dynamic_initializer_for__QueryCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("QueryCondition", 0xFFFFFFFF);
  QueryCondition::sClassNameUID = result;
  return result;
}

// File Line: 244
// RVA: 0x269040
void __fastcall QueryCondition::QueryCondition(QueryCondition *this)
{
  QueryCondition *v1; // rbx

  v1 = this;
  NodeRefCondition::NodeRefCondition((NodeRefCondition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&QueryCondition::`vftable';
  v1->mpQueryableNodeLocalRoot = 0i64;
  v1->mpQueryableNodeAbsoluteRoot = 0i64;
  v1->mpMyAbsoluteRoot = 0i64;
  v1->mpMyActionNode = 0i64;
}

// File Line: 252
// RVA: 0x271E90
void __fastcall QueryCondition::ResolveReferences(QueryCondition *this, ActionNode *parent)
{
  ActionNode *v2; // rdi
  QueryCondition *v3; // rbx
  __int64 v4; // rax
  signed __int64 v5; // rcx
  __int64 v6; // rax
  __int64 v7; // rax
  signed __int64 v8; // rcx
  __int64 v9; // rax
  __int64 v10; // rax

  v2 = parent;
  v3 = this;
  ((void (*)(void))this->vfptr[2].Serialize)();
  ((void (__fastcall *)(QueryCondition *, ActionNode *))v3->vfptr[2].CreateClone)(v3, v2);
  v4 = v3->mActionNodeReference.mOffset;
  if ( v4 && (v5 = (signed __int64)&v3->mActionNodeReference + v4) != 0 )
    v6 = (*(__int64 (**)(void))(*(_QWORD *)v5 + 144i64))();
  else
    v6 = 0i64;
  v3->mpQueryableNodeLocalRoot = (ActionNodeRoot *)v6;
  v7 = v3->mActionNodeReference.mOffset;
  if ( v7 && (v8 = (signed __int64)&v3->mActionNodeReference + v7) != 0 )
    v9 = (*(__int64 (**)(void))(*(_QWORD *)v8 + 152i64))();
  else
    v9 = 0i64;
  v3->mpQueryableNodeAbsoluteRoot = (ActionNodeRoot *)v9;
  if ( v2 )
  {
    v10 = (__int64)v2->vfptr[1].GetResourceOwner((Expression::IMemberMap *)&v2->vfptr);
    v3->mpMyActionNode = v2;
    v3->mpMyAbsoluteRoot = (ActionNodeRoot *)v10;
  }
  else
  {
    v3->mpMyAbsoluteRoot = 0i64;
    v3->mpMyActionNode = 0i64;
  }
}

// File Line: 267
// RVA: 0x26FBC0
bool __fastcall QueryCondition::Match(QueryCondition *this, ActionContext *context)
{
  __int64 v2; // rax
  ActionContext *v3; // rbx
  QueryCondition *v4; // rsi
  __int64 v5; // rcx
  signed __int64 v6; // rdi
  ActionNodeRoot *v7; // rdx
  __int64 v8; // r8
  UFG::ActionTreeComponentBase *v9; // rcx
  __int64 v10; // rax

  v2 = this->mActionNodeReference.mOffset;
  v3 = context;
  v4 = this;
  if ( v2 )
    v2 += (__int64)&this->mActionNodeReference;
  v5 = *(_QWORD *)(v2 + 72);
  if ( !v5 )
    return 0;
  v6 = v5 + v2 + 72;
  if ( !v6 )
    return 0;
  v7 = v4->mpQueryableNodeAbsoluteRoot;
  v8 = v7->mActionTreeType.mValue;
  if ( (v3->mActionTreeComponentBase[v8] || v3->mActionTreeComponentBase[1]) && v4->mpMyAbsoluteRoot != v7 )
  {
    v9 = v3->mActionTreeComponentBase[v8];
    if ( !v9 )
      v9 = v3->mActionTreeComponentBase[1];
    if ( UFG::ActionTreeComponentBase::AllocateFor(v9, v7) )
      ActionNodeRoot::Init(v4->mpQueryableNodeAbsoluteRoot, v3);
  }
  if ( !(*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v6 + 272i64))(v6) )
    return 0;
  v10 = (*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v6 + 272i64))(v6);
  return (*(__int64 (__fastcall **)(__int64, ActionContext *))(*(_QWORD *)v10 + 80i64))(v10, v3);
}

// File Line: 324
// RVA: 0x26CEA0
Expression::IMemberMap *__fastcall QueryCondition::CreateClone(QueryCondition *this)
{
  QueryCondition *v1; // rsi
  char *v2; // rax
  _QWORD *v3; // rdi
  __int64 v4; // rax
  signed __int64 v5; // rbp
  __int64 v6; // rax
  signed __int64 v7; // rsi

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "QueryCondition::CreateClone", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    NodeRefCondition::NodeRefCondition((NodeRefCondition *)v2);
    *v3 = &QueryCondition::`vftable';
    v3[4] = 0i64;
    v3[5] = 0i64;
    v3[6] = 0i64;
    v3[7] = 0i64;
  }
  else
  {
    v3 = 0i64;
  }
  v4 = v1->mActionNodeReference.mOffset;
  if ( v4 )
    v5 = (signed __int64)&v1->mActionNodeReference + v4;
  else
    v5 = 0i64;
  v6 = v3[3];
  if ( v6 )
    v7 = (signed __int64)v3 + v6 + 24;
  else
    v7 = 0i64;
  BinArray<ActionID,0>::Clone((BinArray<ActionID,0> *)(v5 + 56), (BinArray<ActionID,0> *)(v7 + 56));
  *(_QWORD *)(v7 + 72) = 0i64;
  *(_DWORD *)(v7 + 40) = *(_DWORD *)(v5 + 40);
  *(_QWORD *)(v7 + 16) = 0i64;
  *(_BYTE *)(v7 + 44) = *(_BYTE *)(v5 + 44) != 0;
  v3[4] = 0i64;
  v3[5] = 0i64;
  v3[6] = 0i64;
  v3[7] = 0i64;
  return (Expression::IMemberMap *)v3;
}

