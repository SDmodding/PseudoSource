// File Line: 64
// RVA: 0x26A2D0
float __fastcall ExpressionParameterFloat::operator float(ExpressionParameterFloat *this)
{
  __int64 v1; // rax
  ExpressionParameterFloat *v2; // rbx
  char *v3; // rcx
  __int64 v5; // [rsp+30h] [rbp-28h]
  __int16 v6; // [rsp+44h] [rbp-14h]

  v1 = this->expression.mOffset;
  v2 = this;
  if ( !v1 )
    return v2->value;
  v3 = (char *)&this->expression + v1;
  if ( !v3 )
    return v2->value;
  (*(void (__fastcall **)(char *, __int64 *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v3 + 24i64))(
    v3,
    &v5,
    UEL::gCurrentParameters,
    0i64,
    UEL::gCurrentStringBuilder);
  if ( !v6 )
    return v2->value;
  if ( v6 == 4 )
    return *(float *)&v5;
  return (float)(signed int)v5;
}

// File Line: 113
// RVA: 0x279A30
__int64 __fastcall ExpressionParameterInt::operator long(ExpressionParameterInt *this)
{
  __int64 v1; // rax
  ExpressionParameterInt *v2; // rbx
  char *v3; // rcx
  __int64 result; // rax
  float v5; // [rsp+30h] [rbp-28h]
  __int16 v6; // [rsp+44h] [rbp-14h]

  v1 = this->expression.mOffset;
  v2 = this;
  if ( !v1 )
    return (unsigned int)v2->value;
  v3 = (char *)&this->expression + v1;
  if ( !v3 )
    return (unsigned int)v2->value;
  (*(void (__fastcall **)(char *, float *, UEL::ParametersBase *, _QWORD, UFG::qStringBuilder *))(*(_QWORD *)v3 + 24i64))(
    v3,
    &v5,
    UEL::gCurrentParameters,
    0i64,
    UEL::gCurrentStringBuilder);
  if ( !v6 )
    return (unsigned int)v2->value;
  result = LODWORD(v5);
  if ( v6 != 1 )
    result = (unsigned int)(signed int)v5;
  return result;
}

// File Line: 605
// RVA: 0x151EB0
void __fastcall Expression::IMemberMap::operator delete(void *ptr, unsigned __int64 size)
{
  UFG::qMemoryPool2::Free(&gActionTreeMemoryPool, ptr, size);
}

// File Line: 629
// RVA: 0x151D40
void __fastcall Expression::IMemberMap::~IMemberMap(Expression::IMemberMap *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 690
// RVA: 0x152910
void __fastcall Illusion::EnginePlat::SetDevice(hkProcessContext *this, hkVisualDebugger *vdb)
{
  this->m_owner = vdb;
}

// File Line: 2742
// RVA: 0x2980E0
void __fastcall qNodeOrderChange<PoseNode,PoseNode,1,0>(UFG::qList<PoseNode,PoseNode,1,0> *list, PoseNode *item, bool increase)
{
  UFG::qNode<PoseNode,PoseNode> *v3; // r9
  char *v4; // rcx
  signed __int64 v5; // r9
  PoseNode *v6; // rax
  UFG::qNode<PoseNode,PoseNode> *v7; // rdx
  UFG::qNode<PoseNode,PoseNode> *v8; // r8
  UFG::qNode<PoseNode,PoseNode> *v9; // rax
  UFG::qNode<PoseNode,PoseNode> *v10; // rcx
  UFG::qNode<PoseNode,PoseNode> *v11; // rax
  UFG::qNode<PoseNode,PoseNode> *v12; // r8
  UFG::qNode<PoseNode,PoseNode> *v13; // rcx
  UFG::qNode<PoseNode,PoseNode> *v14; // rdx
  UFG::qNode<PoseNode,PoseNode> *v15; // rax
  UFG::qNode<PoseNode,PoseNode> *v16; // rax

  v3 = list->mNode.mNext;
  v4 = (char *)&list[-3].mNode.mNext;
  v5 = (signed __int64)&v3[-3].mNext;
  v6 = (PoseNode *)v5;
  if ( (char *)v5 != v4 )
  {
    while ( v6 != item )
    {
      v6 = (PoseNode *)&v6->mNext[-3].mNext;
      if ( v6 == (PoseNode *)v4 )
        return;
    }
    if ( increase )
    {
      v7 = (UFG::qNode<PoseNode,PoseNode> *)&v6->mPrev;
      if ( v6->mPrev != (UFG::qNode<PoseNode,PoseNode> *)40 )
      {
        v8 = v6->mPrev;
        if ( v6->mPrev != 0i64 && v6 != (PoseNode *)v5 )
        {
          v9 = v6->mNext;
          v10 = v7->mPrev;
          v10->mNext = v9;
          v9->mPrev = v10;
          v7->mPrev = v7;
          v7->mNext = v7;
          v11 = v8->mPrev;
          v11->mNext = v7;
          v7->mPrev = v11;
          v7->mNext = v8;
          v8->mPrev = v7;
        }
      }
    }
    else if ( v6->mNext != (UFG::qNode<PoseNode,PoseNode> *)40 )
    {
      v12 = v6->mNext;
      if ( v12 )
      {
        if ( v4 )
          v4 += 40;
        if ( v12 != (UFG::qNode<PoseNode,PoseNode> *)v4 )
        {
          v13 = v6->mPrev;
          v14 = (UFG::qNode<PoseNode,PoseNode> *)&v6->mPrev;
          v15 = v6->mNext;
          v13->mNext = v15;
          v15->mPrev = v13;
          v14->mPrev = v14;
          v14->mNext = v14;
          v16 = v12->mNext;
          v12->mNext = v14;
          v14->mPrev = v12;
          v14->mNext = v16;
          v16->mPrev = v14;
        }
      }
    }
  }
}

