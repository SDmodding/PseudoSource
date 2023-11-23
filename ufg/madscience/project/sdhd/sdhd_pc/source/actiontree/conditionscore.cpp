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
  int v3; // ecx
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
  int v3; // ecx
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
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->mBreakPoint = 0;
  this->mPrev = &this->UFG::qNode<IConditionInit,IConditionInit>;
  this->mNext = &this->UFG::qNode<IConditionInit,IConditionInit>;
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&IConditionInit::`vftable;
  this->Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&DebugTestCondition::`vftable{for `Condition};
  this->IConditionInit::vfptr = (IConditionInitVtbl *)&DebugTestCondition::`vftable{for `IConditionInit};
}

// File Line: 129
// RVA: 0x271C40
void __fastcall DebugTestCondition::ResolveReferences(DebugTestCondition *this, ActionNode *action_node)
{
  __int64 v3; // rax
  IConditionInit *v4; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *v5; // r8
  int v6; // ecx
  __int64 v7; // rax
  UFG::qNode<IConditionInit,IConditionInit> *mPrev; // rax

  v3 = ((__int64 (__fastcall *)(ActionNode *))action_node->vfptr[1].SetResourceOwner)(action_node);
  if ( this )
    v4 = &this->IConditionInit;
  else
    v4 = 0i64;
  v5 = (UFG::qNode<IConditionInit,IConditionInit> *)(v3 + 144);
  v6 = -1;
  v7 = *(_QWORD *)(v3 + 152) - 8i64;
  if ( (UFG::qNode<IConditionInit,IConditionInit> **)v7 == &v5[-1].mNext )
    goto LABEL_9;
  while ( 1 )
  {
    ++v6;
    if ( (IConditionInit *)v7 == v4 )
      break;
    v7 = *(_QWORD *)(v7 + 16) - 8i64;
    if ( (UFG::qNode<IConditionInit,IConditionInit> **)v7 == &v5[-1].mNext )
      goto LABEL_9;
  }
  if ( v6 == -1 )
  {
LABEL_9:
    mPrev = v5->mPrev;
    mPrev->mNext = &v4->UFG::qNode<IConditionInit,IConditionInit>;
    v4->mPrev = mPrev;
    v4->mNext = v5;
    v5->mPrev = &v4->UFG::qNode<IConditionInit,IConditionInit>;
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
  BinString *p_m_Text; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->mBreakPoint = 0;
  this->vfptr = (Expression::IMemberMapVtbl *)&PrintCondition::`vftable;
  p_m_Text = &this->m_Text;
  p_m_Text->mOffset = 1i64;
  BinString::Set(p_m_Text, &customCaption);
  this->m_PrintLocation.mValue = 2;
}

// File Line: 189
// RVA: 0x26FAD0
char __fastcall PrintCondition::Match(PrintCondition *this, ActionContext *context)
{
  UFG::TransformNodeComponent *m_pPointer; // rax
  const char *v4; // rdx

  if ( !this->m_PrintLocation.mValue )
  {
    if ( (this->m_Text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    {
      UFG::qPrintf("%s\n", (const char *)&this->m_Text + (this->m_Text.mOffset & 0xFFFFFFFFFFFFFFFEui64));
      return 1;
    }
    UFG::qPrintf("%s\n", BinString::sEmptyString);
    return 1;
  }
  if ( this->m_PrintLocation.mValue != 1 )
  {
    if ( this->m_PrintLocation.mValue == 2 && context )
    {
      m_pPointer = (UFG::TransformNodeComponent *)context->mSimObject.m_pPointer;
      if ( m_pPointer )
        m_pPointer = (UFG::TransformNodeComponent *)m_pPointer->mChildren.mNode.mNext;
      if ( m_pPointer )
      {
        UFG::DrawDebugText(m_pPointer, &UFG::qColour::White, "%s", (int)m_pPointer);
        return 1;
      }
    }
    return 1;
  }
  if ( (this->m_Text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
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
  NodeRefCondition::NodeRefCondition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&QueryCondition::`vftable;
  this->mpQueryableNodeLocalRoot = 0i64;
  this->mpQueryableNodeAbsoluteRoot = 0i64;
  this->mpMyAbsoluteRoot = 0i64;
  this->mpMyActionNode = 0i64;
}

// File Line: 252
// RVA: 0x271E90
void __fastcall QueryCondition::ResolveReferences(QueryCondition *this, ActionNode *parent)
{
  __int64 mOffset; // rax
  char *v5; // rcx
  ActionNodeRoot *v6; // rax
  __int64 v7; // rax
  char *v8; // rcx
  ActionNodeRoot *v9; // rax
  ActionNodeRoot *v10; // rax

  ((void (__fastcall *)(QueryCondition *))this->vfptr[2].Serialize)(this);
  ((void (__fastcall *)(QueryCondition *, ActionNode *))this->vfptr[2].CreateClone)(this, parent);
  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset && (v5 = (char *)&this->mActionNodeReference + mOffset) != 0i64 )
    v6 = (ActionNodeRoot *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 144i64))(v5);
  else
    v6 = 0i64;
  this->mpQueryableNodeLocalRoot = v6;
  v7 = this->mActionNodeReference.mOffset;
  if ( v7 && (v8 = (char *)&this->mActionNodeReference + v7) != 0i64 )
    v9 = (ActionNodeRoot *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v8 + 152i64))(v8);
  else
    v9 = 0i64;
  this->mpQueryableNodeAbsoluteRoot = v9;
  if ( parent )
  {
    v10 = (ActionNodeRoot *)parent->vfptr[1].GetResourceOwner(parent);
    this->mpMyActionNode = parent;
    this->mpMyAbsoluteRoot = v10;
  }
  else
  {
    this->mpMyAbsoluteRoot = 0i64;
    this->mpMyActionNode = 0i64;
  }
}

// File Line: 267
// RVA: 0x26FBC0
bool __fastcall QueryCondition::Match(QueryCondition *this, ActionContext *context)
{
  __int64 mOffset; // rax
  __int64 v5; // rcx
  __int64 v6; // rdi
  ActionNodeRoot *mpQueryableNodeAbsoluteRoot; // rdx
  __int64 mValue; // r8
  UFG::ActionTreeComponentBase *v9; // rcx
  __int64 v10; // rax

  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset )
    mOffset += (__int64)&this->mActionNodeReference;
  v5 = *(_QWORD *)(mOffset + 72);
  if ( !v5 )
    return 0;
  v6 = v5 + mOffset + 72;
  if ( !v6 )
    return 0;
  mpQueryableNodeAbsoluteRoot = this->mpQueryableNodeAbsoluteRoot;
  mValue = mpQueryableNodeAbsoluteRoot->mActionTreeType.mValue;
  if ( (context->mActionTreeComponentBase[mValue] || context->mActionTreeComponentBase[1])
    && this->mpMyAbsoluteRoot != mpQueryableNodeAbsoluteRoot )
  {
    v9 = context->mActionTreeComponentBase[mValue];
    if ( !v9 )
      v9 = context->mActionTreeComponentBase[1];
    if ( UFG::ActionTreeComponentBase::AllocateFor(v9, mpQueryableNodeAbsoluteRoot) )
      ActionNodeRoot::Init(this->mpQueryableNodeAbsoluteRoot, context);
  }
  if ( !(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 272i64))(v6) )
    return 0;
  v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 272i64))(v6);
  return (*(__int64 (__fastcall **)(__int64, ActionContext *))(*(_QWORD *)v10 + 80i64))(v10, context);
}

// File Line: 324
// RVA: 0x26CEA0
Expression::IMemberMap *__fastcall QueryCondition::CreateClone(QueryCondition *this)
{
  char *v2; // rax
  _QWORD *v3; // rdi
  __int64 mOffset; // rax
  char *v5; // rbp
  __int64 v6; // rax
  char *v7; // rsi

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "QueryCondition::CreateClone", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    NodeRefCondition::NodeRefCondition((NodeRefCondition *)v2);
    *v3 = &QueryCondition::`vftable;
    v3[4] = 0i64;
    v3[5] = 0i64;
    v3[6] = 0i64;
    v3[7] = 0i64;
  }
  else
  {
    v3 = 0i64;
  }
  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset )
    v5 = (char *)&this->mActionNodeReference + mOffset;
  else
    v5 = 0i64;
  v6 = v3[3];
  if ( v6 )
    v7 = (char *)v3 + v6 + 24;
  else
    v7 = 0i64;
  BinArray<ActionID,0>::Clone((BinArray<ActionID,0> *)(v5 + 56), (BinArray<ActionID,0> *)(v7 + 56));
  *((_QWORD *)v7 + 9) = 0i64;
  *((_DWORD *)v7 + 10) = *((_DWORD *)v5 + 10);
  *((_QWORD *)v7 + 2) = 0i64;
  v7[44] = v5[44] != 0;
  v3[4] = 0i64;
  v3[5] = 0i64;
  v3[6] = 0i64;
  v3[7] = 0i64;
  return (Expression::IMemberMap *)v3;
}

