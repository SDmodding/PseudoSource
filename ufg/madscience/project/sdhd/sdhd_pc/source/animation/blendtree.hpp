// File Line: 109
// RVA: 0x298910
void __fastcall PoseNode::PoseNode(PoseNode *this)
{
  PoseNode *v1; // rdi
  UFG::qNode<PoseNode,PoseNode> *v2; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  UFG::qSafePointerNode<PoseNode>::qSafePointerNode<PoseNode>((UFG::qSafePointerNode<PoseNode> *)&this->vfptr);
  v2 = (UFG::qNode<PoseNode,PoseNode> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (Expression::IMemberMapVtbl *)&PoseNode::`vftable{for `Expression::IMemberMap};
  v1->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v1->mParent.mOffset = 0i64;
  v1->mPriority = 0;
  *(_QWORD *)&v1->mName.mUID = -1i64;
  *(_WORD *)&v1->mBreakPoint = 0;
  v1->mDebugPoseColour.r = UFG::qColour::Green.r;
  v1->mDebugPoseColour.g = UFG::qColour::Green.g;
  v1->mDebugPoseColour.b = UFG::qColour::Green.b;
  v1->mDebugPoseColour.a = UFG::qColour::Green.a;
}

// File Line: 293
// RVA: 0x2BD570
PoseNode *__fastcall PoseNode::FindFirstAtPriority(PoseNode *this, int priority)
{
  PoseNode *result; // rax

  result = 0i64;
  if ( priority >= this->mPriority )
    result = this;
  return result;
}

// File Line: 302
// RVA: 0x2BD4E0
PoseNode *__fastcall PoseNode::Find(PoseNode *this, UFG::qSymbolUC *name)
{
  PoseNode *result; // rax

  result = 0i64;
  if ( name->mUID == this->mName.mUID )
    result = this;
  return result;
}

// File Line: 329
// RVA: 0x29D520
void __fastcall PoseNodeParent::~PoseNodeParent(PoseNodeParent *this)
{
  PoseNodeParent *v1; // rdi
  UFG::qList<PoseNode,PoseNode,1,0> *v2; // rbx
  int *v3; // rax
  int *v4; // rsi
  _QWORD *v5; // rdx
  __int64 v6; // rcx
  _QWORD *v7; // rax
  UFG::qNode<PoseNode,PoseNode> *v8; // rcx
  UFG::qNode<PoseNode,PoseNode> *v9; // rax
  __int64 v10; // rax
  char *v11; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseNodeParent::`vftable{for `Expression::IMemberMap};
  this->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNodeParent::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v2 = &this->mChildren;
  v3 = (int *)&this->mChildren.mNode.mNext[-3].mNext;
  v4 = &this->mNetPoseSequence;
  if ( v3 != &this->mNetPoseSequence )
  {
    do
    {
      v5 = v3 + 10;
      v6 = *((_QWORD *)v3 + 5);
      v7 = (_QWORD *)*((_QWORD *)v3 + 6);
      *(_QWORD *)(v6 + 8) = v7;
      *v7 = v6;
      *v5 = v5;
      v5[1] = v5;
      if ( v5 != (_QWORD *)40 )
        (*(void (__fastcall **)(_QWORD *, signed __int64))(*(v5 - 5) + 8i64))(v5 - 5, 1i64);
      v3 = (int *)&v2->mNode.mNext[-3].mNext;
    }
    while ( v3 != v4 );
  }
  UFG::qList<PoseNode,PoseNode,1,0>::DeleteNodes(v2);
  v8 = v2->mNode.mPrev;
  v9 = v2->mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  if ( v1->mChildrenSerialized.mCount >= 0 )
  {
    v10 = v1->mChildrenSerialized.mData.mOffset;
    if ( v10 )
    {
      v11 = (char *)&v1->mChildrenSerialized.mData + v10;
      if ( v11 )
        operator delete[](v11);
    }
    v1->mChildrenSerialized.mData.mOffset = 0i64;
    v1->mChildrenSerialized.mCount &= 0x80000000;
  }
  PoseNode::~PoseNode((PoseNode *)&v1->vfptr);
}

// File Line: 331
// RVA: 0x2C1FC0
const char *__fastcall PoseNodeParent::GetClassname(PoseNodeParent *this)
{
  return PoseNodeParent::sClassName;
}

// File Line: 340
// RVA: 0x2AEE50
void __fastcall PoseNodeParent::Accept(PoseNodeParent *this, PoseNodeVisitor *visitor)
{
  visitor->vfptr->Visit(visitor, this);
}

// File Line: 350
// RVA: 0x2BD400
void __fastcall PoseNodeParent::DeleteChildren(PoseNodeParent *this)
{
  UFG::qNode<PoseNode,PoseNode> *v1; // rax
  int *v2; // rdi
  PoseNodeParent *v3; // rbx
  UFG::qNode<PoseNode,PoseNode> *v4; // rcx
  UFG::qNode<PoseNode,PoseNode> *v5; // rdx

  v1 = this->mChildren.mNode.mNext;
  v2 = &this->mNetPoseSequence;
  v3 = this;
  if ( &v1[-3].mNext != (UFG::qNode<PoseNode,PoseNode> **)&this->mNetPoseSequence )
  {
    do
    {
      v4 = v1->mNext;
      v5 = v1->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      v1->mPrev = v1;
      v1->mNext = v1;
      if ( v1 != (UFG::qNode<PoseNode,PoseNode> *)40 )
        ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, signed __int64))v1[-3].mNext->mNext)(
          &v1[-3].mNext,
          1i64);
      v1 = v3->mChildren.mNode.mNext;
    }
    while ( &v1[-3].mNext != (UFG::qNode<PoseNode,PoseNode> **)v2 );
  }
}

// File Line: 357
// RVA: 0x2BD6F0
Expression::IMemberMap *__fastcall PoseNodeParent::GetChild2(PoseNodeParent *this, __int64 priority)
{
  return (Expression::IMemberMap *)this->vfptr[1].__vecDelDtor((Expression::IMemberMap *)this, priority);
}

// File Line: 358
// RVA: 0x2AF130
void __fastcall PoseNodeParent::AddChild2(PoseNodeParent *this, Expression::IMemberMap *node)
{
  ((void (__fastcall *)(PoseNodeParent *, Expression::IMemberMap *))this->vfptr[4].GetClassNameUID)(this, node);
}

// File Line: 359
// RVA: 0x2BD3B0
void __fastcall PoseNodeParent::DeleteChild2(PoseNodeParent *this, Expression::IMemberMap *node)
{
  ((void (__fastcall *)(PoseNodeParent *, Expression::IMemberMap *))this->vfptr[4].GetResourcePath)(this, node);
}

// File Line: 360
// RVA: 0x2AF190
void __fastcall PoseNodeParent::ChangeChildPriority2(PoseNodeParent *this, Expression::IMemberMap *node, __int64 increase)
{
  ((void (__fastcall *)(PoseNodeParent *, Expression::IMemberMap *, __int64))this->vfptr[4].ResolveReferences)(
    this,
    node,
    increase);
}

// File Line: 414
// RVA: 0x2AF5A0
PoseNodeParent *__fastcall PoseNodeParent::Clone(PoseNodeParent *this)
{
  PoseNodeParent *v1; // rdi
  PoseNodeParent *v2; // rax
  PoseNodeParent *v3; // rbx

  v1 = this;
  v2 = PoseNodeParent::Create();
  v2->mName.mUID = v1->mName.mUID;
  v3 = v2;
  PoseNodeParent::copyChildren(v1, v2);
  return v3;
}

// File Line: 422
// RVA: 0x2DCD10
char __usercall PoseNodeParent::Update@<al>(PoseNodeParent *this@<rcx>, float timeDelta@<xmm1>, bool updateAnimation@<r8b>, __int64 a4@<rdx>)
{
  int *v4; // rbp
  int *v5; // rdi
  bool v6; // r14
  char v7; // si
  signed __int64 v8; // rbx
  __int64 v9; // rdx
  _QWORD *v10; // rax
  _QWORD *v11; // r8

  v4 = &this->mNetPoseSequence;
  v5 = (int *)&this->mChildren.mNode.mNext[-3].mNext;
  v6 = updateAnimation;
  v7 = v5 == &this->mNetPoseSequence;
  this->mLocalTime = timeDelta + this->mLocalTime;
  if ( !v5 )
    return 1;
  do
  {
    if ( v7 )
      break;
    v8 = *((_QWORD *)v5 + 6) - 40i64;
    if ( (*(unsigned __int8 (__fastcall **)(int *, __int64, bool))(*(_QWORD *)v5 + 120i64))(v5, a4, v6) )
    {
      v7 = v8 == (_QWORD)v4;
    }
    else
    {
      v7 = v8 && (int *)v8 != v4 ? 0 : 1;
      v9 = *((_QWORD *)v5 + 5);
      v10 = (_QWORD *)*((_QWORD *)v5 + 6);
      v11 = v5 + 10;
      *(_QWORD *)(v9 + 8) = v10;
      *v10 = v9;
      *v11 = v11;
      v11[1] = v11;
      (*(void (__fastcall **)(int *, signed __int64))(*(_QWORD *)v5 + 8i64))(v5, 1i64);
    }
    v5 = (int *)v8;
  }
  while ( v8 );
  return 1;
}

// File Line: 465
// RVA: 0x2DD020
void __fastcall PoseNodeParent::copyChildren(PoseNodeParent *this, PoseNodeParent *clone)
{
  int *v2; // rbp
  PoseNodeParent *v3; // rsi
  PoseNodeParent *v4; // rbx
  Expression::IMemberMapVtbl *v5; // rdi
  __int64 v6; // rax

  v2 = &this->mNetPoseSequence;
  v3 = clone;
  v4 = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v4 != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      v5 = v3->vfptr;
      v6 = ((__int64 (__fastcall *)(PoseNodeParent *))v4->vfptr[1].Serialize)(v4);
      ((void (__fastcall *)(PoseNodeParent *, __int64))v5[4].GetClassNameUID)(v3, v6);
      v4 = (PoseNodeParent *)&v4->mNext[-3].mNext;
    }
    while ( v4 != (PoseNodeParent *)v2 );
  }
}

// File Line: 474
// RVA: 0x2DCBF0
void __fastcall PoseNodeParent::SetParametricPlayTime(PoseNodeParent *this, float parametric)
{
  int *v2; // rdi
  PoseNodeParent *v3; // rbx

  v2 = &this->mNetPoseSequence;
  v3 = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v3 != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      v3->vfptr[3].GetClassNameUID((Expression::IMemberMap *)&v3->vfptr);
      v3 = (PoseNodeParent *)&v3->mNext[-3].mNext;
    }
    while ( v3 != (PoseNodeParent *)v2 );
  }
}

// File Line: 483
// RVA: 0x2DCB60
void __fastcall PoseNodeParent::SetLocalTime(PoseNodeParent *this, float localTime)
{
  int *v2; // rdi
  PoseNodeParent *v3; // rbx

  v2 = &this->mNetPoseSequence;
  v3 = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v3 != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      ((void (__fastcall *)(PoseNodeParent *))v3->vfptr[3].GetResourcePath)(v3);
      v3 = (PoseNodeParent *)&v3->mNext[-3].mNext;
    }
    while ( v3 != (PoseNodeParent *)v2 );
  }
}

// File Line: 492
// RVA: 0x2BD700
PoseNodeParent *__fastcall PoseNodeParent::GetChild(PoseNodeParent *this, int priority)
{
  PoseNodeParent *v2; // r8
  PoseNodeParent *v3; // rax

  v2 = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v2 == (PoseNodeParent *)&this->mNetPoseSequence )
    return 0i64;
  while ( 1 )
  {
    v3 = (PoseNodeParent *)&v2->mNext[-3].mNext;
    if ( !priority )
      break;
    --priority;
    v2 = (PoseNodeParent *)&v2->mNext[-3].mNext;
    if ( v3 == (PoseNodeParent *)&this->mNetPoseSequence )
      return 0i64;
  }
  return v2;
}

// File Line: 507
// RVA: 0x2BD730
__int64 __fastcall PoseNodeParent::GetChildCount(PoseNodeParent *this)
{
  UFG::qNode<PoseNode,PoseNode> *v1; // rdx
  int *v2; // rcx
  __int64 result; // rax
  signed __int64 i; // rdx

  v1 = this->mChildren.mNode.mNext;
  v2 = &this->mNetPoseSequence;
  result = 0i64;
  for ( i = (signed __int64)&v1[-3].mNext; (int *)i != v2; i = *(_QWORD *)(i + 48) - 40i64 )
    result = (unsigned int)(result + 1);
  return result;
}

// File Line: 512
// RVA: 0x2AF140
void __fastcall PoseNodeParent::AddChild(PoseNodeParent *this, PoseNode *node)
{
  PoseNode *v2; // r9
  UFG::qOffset64<PoseNodeParent *> *v3; // r8
  char *v4; // rax
  UFG::qNode<PoseNode,PoseNode> *v5; // rax
  UFG::qList<PoseNode,PoseNode,1,0> *v6; // rdx
  UFG::qNode<PoseNode,PoseNode> *v7; // rcx

  v2 = node;
  v3 = &node->mParent;
  if ( this )
    v4 = (char *)((char *)this - (char *)v3);
  else
    v4 = 0i64;
  v3->mOffset = (__int64)v4;
  v5 = this->mChildren.mNode.mPrev;
  v6 = &this->mChildren;
  v7 = (UFG::qNode<PoseNode,PoseNode> *)&v2->mPrev;
  v5->mNext = (UFG::qNode<PoseNode,PoseNode> *)&v2->mPrev;
  v7->mPrev = v5;
  v7->mNext = &v6->mNode;
  v6->mNode.mPrev = (UFG::qNode<PoseNode,PoseNode> *)&v2->mPrev;
}

// File Line: 518
// RVA: 0x2BD3C0
void __fastcall PoseNodeParent::DeleteChild(PoseNodeParent *this, PoseNode *child)
{
  UFG::qNode<PoseNode,PoseNode> *v2; // rcx
  UFG::qNode<PoseNode,PoseNode> *v3; // rax
  UFG::qNode<PoseNode,PoseNode> *v4; // r8

  v2 = child->mPrev;
  v3 = child->mNext;
  v4 = (UFG::qNode<PoseNode,PoseNode> *)&child->mPrev;
  v2->mNext = v3;
  v3->mPrev = v2;
  v4->mPrev = v4;
  v4->mNext = v4;
  if ( child )
    child->vfptr->__vecDelDtor((Expression::IMemberMap *)child, 1u);
}

// File Line: 524
// RVA: 0x2DC820
void __fastcall PoseNodeParent::RemoveChild(PoseNodeParent *this, PoseNode *child)
{
  UFG::qNode<PoseNode,PoseNode> *v2; // rcx
  UFG::qNode<PoseNode,PoseNode> *v3; // rax
  UFG::qNode<PoseNode,PoseNode> *v4; // r8

  v2 = child->mPrev;
  v3 = child->mNext;
  v4 = (UFG::qNode<PoseNode,PoseNode> *)&child->mPrev;
  v2->mNext = v3;
  v3->mPrev = v2;
  v4->mPrev = v4;
  v4->mNext = v4;
  child->mParent.mOffset = 0i64;
}

// File Line: 530
// RVA: 0x2DC850
void __fastcall PoseNodeParent::Replace(PoseNodeParent *this, PoseNode *currentChild, PoseNode *newChild)
{
  UFG::qNode<PoseNode,PoseNode> *v3; // rax
  UFG::qNode<PoseNode,PoseNode> *v4; // r9
  UFG::qOffset64<PoseNodeParent *> *v5; // r8

  v3 = currentChild->mPrev;
  v4 = (UFG::qNode<PoseNode,PoseNode> *)&newChild->mPrev;
  v3->mNext = (UFG::qNode<PoseNode,PoseNode> *)&newChild->mPrev;
  v5 = &newChild->mParent;
  v4->mPrev = v3;
  v4->mNext = (UFG::qNode<PoseNode,PoseNode> *)&currentChild->mPrev;
  currentChild->mPrev = v4;
  if ( this )
  {
    v5->mOffset = (char *)this - (char *)v5;
    ((void (*)(void))this->vfptr[4].SetResourceOwner)();
  }
  else
  {
    v5->mOffset = 0i64;
    (*(void (**)(void))(MEMORY[0] + 384))();
  }
}

// File Line: 539
// RVA: 0x2AF1A0
void __fastcall PoseNodeParent::ChangeChildPriority(PoseNodeParent *this, PoseNode *childMove, bool increase)
{
  qNodeOrderChange<PoseNode,PoseNode,1,0>(&this->mChildren, childMove, increase);
}

// File Line: 545
// RVA: 0x2C30E0
void __fastcall PoseNodeParent::GetExtractedDeltaReferenceFrame(PoseNodeParent *this, float deltaTime, hkQsTransformf *deltaMotionOut)
{
  PoseNodeParent *v3; // rdx

  v3 = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v3 != (PoseNodeParent *)&this->mNetPoseSequence )
    v3->vfptr[1].GetResourcePath(
      (Expression::IMemberMap *)&this->mChildren.mNode.mNext[-3].mNext,
      (char *)v3,
      (int)deltaMotionOut);
}

// File Line: 556
// RVA: 0x2DCAE0
void __fastcall PoseNodeParent::SetActiveDirection(PoseNodeParent *this, float activeDirection, bool force)
{
  UFG::qNode<PoseNode,PoseNode> *v3; // rax
  int *v4; // rcx
  signed __int64 i; // rax

  v3 = this->mChildren.mNode.mNext;
  v4 = &this->mNetPoseSequence;
  for ( i = (signed __int64)&v3[-3].mNext; (int *)i != v4; i = *(_QWORD *)(i + 48) - 40i64 )
    ;
}

// File Line: 566
// RVA: 0x2DCB00
void __fastcall PoseNodeParent::SetContext(PoseNodeParent *this, ActionContext *context)
{
  int *v2; // rdi
  ActionContext *v3; // rsi
  PoseNodeParent *v4; // rbx

  v2 = &this->mNetPoseSequence;
  v3 = context;
  v4 = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v4 != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      ((void (__fastcall *)(PoseNodeParent *, ActionContext *))v4->vfptr[2].GetResourceOwner)(v4, v3);
      v4 = (PoseNodeParent *)&v4->mNext[-3].mNext;
    }
    while ( v4 != (PoseNodeParent *)v2 );
  }
}

// File Line: 575
// RVA: 0x2BD580
PoseNodeParent *__fastcall PoseNodeParent::FindFirstAtPriority(PoseNodeParent *this, int priority)
{
  unsigned int v2; // esi
  PoseNodeParent *result; // rax
  int *v4; // rdi
  PoseNodeParent *v5; // rbx

  v2 = priority;
  if ( priority >= this->mPriority )
    return this;
  v4 = &this->mNetPoseSequence;
  v5 = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v5 == (PoseNodeParent *)&this->mNetPoseSequence )
    return 0i64;
  while ( 1 )
  {
    result = (PoseNodeParent *)((__int64 (__fastcall *)(PoseNodeParent *, _QWORD))v5->vfptr[3].GetResourceOwner)(v5, v2);
    if ( result )
      break;
    v5 = (PoseNodeParent *)&v5->mNext[-3].mNext;
    if ( v5 == (PoseNodeParent *)v4 )
      return 0i64;
  }
  return result;
}

// File Line: 595
// RVA: 0x2BD4F0
PoseNodeParent *__fastcall PoseNodeParent::Find(PoseNodeParent *this, UFG::qSymbolUC *name)
{
  UFG::qSymbolUC *v2; // rsi
  PoseNodeParent *result; // rax
  int *v4; // rdi
  PoseNodeParent *v5; // rbx

  v2 = name;
  if ( name->mUID == this->mName.mUID )
    return this;
  v4 = &this->mNetPoseSequence;
  v5 = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v5 == (PoseNodeParent *)&this->mNetPoseSequence )
    return 0i64;
  while ( 1 )
  {
    result = (PoseNodeParent *)v5->vfptr[4].FindWithOldPath((Expression::IMemberMap *)&v5->vfptr, (const char *)v2);
    if ( result )
      break;
    v5 = (PoseNodeParent *)&v5->mNext[-3].mNext;
    if ( v5 == (PoseNodeParent *)v4 )
      return 0i64;
  }
  return result;
}

// File Line: 615
// RVA: 0x2DCC80
void __fastcall PoseNodeParent::SetPlayPriority(PoseNodeParent *this, int playPriority)
{
  int *v2; // rsi
  unsigned int v3; // edi
  PoseNodeParent *v4; // rbx

  v2 = &this->mNetPoseSequence;
  v3 = playPriority;
  v4 = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  this->mPriority = playPriority;
  if ( v4 != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      v4->vfptr[4].__vecDelDtor((Expression::IMemberMap *)&v4->vfptr, v3);
      v4 = (PoseNodeParent *)&v4->mNext[-3].mNext;
    }
    while ( v4 != (PoseNodeParent *)v2 );
  }
}

// File Line: 625
// RVA: 0x2DC490
void __fastcall PoseNodeParent::PreserveMotion(PoseNodeParent *this, bool tf)
{
  int *v2; // rdi
  bool v3; // si
  PoseNodeParent *v4; // rbx

  v2 = &this->mNetPoseSequence;
  v3 = tf;
  v4 = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( v4 != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      v4->vfptr[3].__vecDelDtor((Expression::IMemberMap *)&v4->vfptr, v3);
      v4 = (PoseNodeParent *)&v4->mNext[-3].mNext;
    }
    while ( v4 != (PoseNodeParent *)v2 );
  }
}

// File Line: 704
// RVA: 0x39E400
void __fastcall PoseNodeRoot::PoseNodeRoot(PoseNodeRoot *this)
{
  PoseNodeRoot *v1; // rbx
  UFG::qList<PoseNode,PoseNode,1,0> *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  PoseNode::PoseNode((PoseNode *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PoseNodeParent::`vftable{for `Expression::IMemberMap};
  v1->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNodeParent::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v1->mChildrenSerialized.mCount = 0;
  v1->mChildrenSerialized.mData.mOffset = 0i64;
  v2 = &v1->mChildren;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v1->mLocalTime = 0.0;
  v1->vfptr = (Expression::IMemberMapVtbl *)&PoseNodeRoot::`vftable{for `Expression::IMemberMap};
  v1->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNodeRoot::`vftable{for `UFG::qSafePointerNode<PoseNode>};
}

// File Line: 707
// RVA: 0x3A5F20
void __fastcall PoseNodeRoot::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x88ui64, "MemberMap::PoseNodeRoot", 0i64, 1u);
  if ( v0 )
    PoseNodeRoot::PoseNodeRoot((PoseNodeRoot *)v0);
}

// File Line: 739
// RVA: 0x299F70
void __fastcall BlendNode::~BlendNode(BlendNode *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&BlendNode::`vftable{for `Expression::IMemberMap};
  this->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&BlendNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  PoseNodeParent::~PoseNodeParent((PoseNodeParent *)&this->vfptr);
}

// File Line: 741
// RVA: 0x3A57D0
void __fastcall BlendNode::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB0ui64, "MemberMap::BlendNode", 0i64, 1u);
  if ( v0 )
    BlendNode::BlendNode((BlendNode *)v0);
}

// File Line: 750
// RVA: 0x2AEE30
void __fastcall BlendNode::Accept(BlendNode *this, PoseNodeVisitor *visitor)
{
  visitor->vfptr->Visit(visitor, this);
}

// File Line: 762
// RVA: 0x2DCCE0
void __fastcall BlendNode::SetPlayRate(BlendNode *this, float rate)
{
  this->mBlendRate = rate;
}

// File Line: 860
// RVA: 0x298520
void __fastcall BlendNode::BlendNode(BlendNode *this)
{
  BlendNode *v1; // rbx
  UFG::qList<PoseNode,PoseNode,1,0> *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  PoseNode::PoseNode((PoseNode *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PoseNodeParent::`vftable{for `Expression::IMemberMap};
  v1->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNodeParent::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v1->mChildrenSerialized.mCount = 0;
  v1->mChildrenSerialized.mData.mOffset = 0i64;
  v2 = &v1->mChildren;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v1->mLocalTime = 0.0;
  v1->vfptr = (Expression::IMemberMapVtbl *)&BlendNode::`vftable{for `Expression::IMemberMap};
  v1->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&BlendNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v1->mWeightSet = 0i64;
  v1->mWeightSetMask = 0i64;
  *(_DWORD *)&v1->mStarted = 0;
  *(_QWORD *)&v1->mBlendRate = 1065353216i64;
  *(_QWORD *)&v1->mWeightSetName.mUID = -1i64;
}

// File Line: 872
// RVA: 0x30F380
void __fastcall BlendNode::BlendNode(BlendNode *this, float blendInTime)
{
  BlendNode *v2; // rbx
  UFG::qList<PoseNode,PoseNode,1,0> *v3; // [rsp+60h] [rbp+18h]

  v2 = this;
  PoseNode::PoseNode((PoseNode *)&this->vfptr);
  v2->vfptr = (Expression::IMemberMapVtbl *)&PoseNodeParent::`vftable{for `Expression::IMemberMap};
  v2->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNodeParent::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v2->mChildrenSerialized.mCount = 0;
  v2->mChildrenSerialized.mData.mOffset = 0i64;
  v3 = &v2->mChildren;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  v2->mLocalTime = 0.0;
  v2->vfptr = (Expression::IMemberMapVtbl *)&BlendNode::`vftable{for `Expression::IMemberMap};
  v2->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&BlendNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v2->mWeightSet = 0i64;
  v2->mWeightSetMask = 0i64;
  *(_DWORD *)&v2->mStarted = 0;
  *(_QWORD *)&v2->mBlendRate = 1065353216i64;
  *(_QWORD *)&v2->mWeightSetName.mUID = -1i64;
  if ( blendInTime == 0.0 )
  {
    v2->mBlendRate = 1.0;
    v2->mBlendParam = 1.0;
  }
  else if ( blendInTime > 0.0 )
  {
    v2->mBlendRate = 1.0 / blendInTime;
    v2->mBlendParam = 0.0;
  }
}

// File Line: 888
// RVA: 0x2AF2C0
PoseNode *__fastcall BlendNode::Clone(BlendNode *this)
{
  BlendNode *v1; // rdi
  char *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB0ui64, "BlendNode", 0i64, 1u);
  if ( v2 )
  {
    BlendNode::BlendNode((BlendNode *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  *(float *)(v4 + 156) = v1->mBlendRate;
  *(float *)(v4 + 160) = v1->mBlendParam;
  *(_BYTE *)(v4 + 155) = v1->mKeepBlend;
  *(_BYTE *)(v4 + 153) = v1->mSyncOnStart;
  *(_BYTE *)(v4 + 154) = v1->mPauseBlend;
  *(_DWORD *)(v4 + 68) = v1->mName.mUID;
  *(_DWORD *)(v4 + 64) = v1->mPriority;
  *(_QWORD *)(v4 + 136) = v1->mWeightSet;
  *(_QWORD *)(v4 + 144) = v1->mWeightSetMask;
  *(_DWORD *)(v4 + 164) = v1->mWeightSetName.mUID;
  *(_DWORD *)(v4 + 168) = v1->mWeightSetMaskName.mUID;
  PoseNodeParent::copyChildren((PoseNodeParent *)&v1->vfptr, (PoseNodeParent *)v4);
  return (PoseNode *)v4;
}

// File Line: 946
// RVA: 0x312C20
void __fastcall BlendNode::SetBlendOut(BlendNode *this, float blendOutTime)
{
  if ( blendOutTime == 0.0 )
  {
    this->mBlendRate = -1.0;
    this->mBlendParam = 0.0;
    this->mKeepBlend = 0;
  }
  else if ( blendOutTime > 0.0 )
  {
    this->mKeepBlend = 0;
    this->mBlendRate = -1.0 / blendOutTime;
  }
}

// File Line: 1085
// RVA: 0x3A7E10
const char *__fastcall BlendDirectionNode::GetClassname(BlendDirectionNode *this)
{
  return BlendDirectionNode::sClassName;
}

// File Line: 1161
// RVA: 0x3A9560
float __fastcall BlendDirectionNode::GetPlayRate(BlendNode *this)
{
  return this->mBlendRate;
}

// File Line: 1228
// RVA: 0x3A4E70
BlendDirectionNode *__fastcall BlendDirectionNode::Clone(BlendDirectionNode *this)
{
  BlendDirectionNode *v1; // rdi
  char *v2; // rax
  BlendDirectionNode *v3; // rax
  BlendDirectionNode *v4; // rbx

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xF0ui64, "BlendDirectionNode", 0i64, 1u);
  if ( v2 )
  {
    BlendDirectionNode::BlendDirectionNode((BlendDirectionNode *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  BlendDirectionNode::operator=(v4, v1);
  v4->mNetPoseSequence = -1;
  v4->mName.mUID = v1->mName.mUID;
  PoseNodeParent::copyChildren((PoseNodeParent *)&v1->vfptr, (PoseNodeParent *)&v4->vfptr);
  return v4;
}

// File Line: 1377
// RVA: 0x30F330
void __fastcall BlendAddNode::BlendAddNode(BlendAddNode *this, float blendInTime)
{
  BlendAddNode *v2; // rbx

  v2 = this;
  BlendNode::BlendNode((BlendNode *)&this->vfptr, blendInTime);
  v2->vfptr = (Expression::IMemberMapVtbl *)&BlendAddNode::`vftable{for `Expression::IMemberMap};
  v2->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&BlendAddNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v2->mKeepBlend = 1;
}

// File Line: 1380
// RVA: 0x3A5700
BlendAddNode *__fastcall BlendAddNode::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB0ui64, "MemberMap::BlendAddNode", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  BlendNode::BlendNode((BlendNode *)v0);
  *(_QWORD *)v1 = &BlendAddNode::`vftable{for `Expression::IMemberMap};
  *((_QWORD *)v1 + 2) = &BlendAddNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v1[155] = 1;
  return (BlendAddNode *)v1;
}

// File Line: 1385
// RVA: 0x2AEE20
void __fastcall ActionNodeBank::Accept(MemberMapFileObject *this, MemberMapFileNodeVisitor *visitor)
{
  visitor->vfptr->Visit(visitor, this);
}

// File Line: 1404
// RVA: 0x2AF1B0
PoseNode *__fastcall BlendAddNode::Clone(BlendAddNode *this)
{
  BlendAddNode *v1; // rdi
  char *v2; // rax
  char *v3; // rbx

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB0ui64, "BlendAddNode", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    BlendNode::BlendNode((BlendNode *)v2);
    *(_QWORD *)v3 = &BlendAddNode::`vftable{for `Expression::IMemberMap};
    *((_QWORD *)v3 + 2) = &BlendAddNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
    v3[155] = 1;
  }
  else
  {
    v3 = 0i64;
  }
  *((_DWORD *)v3 + 39) = LODWORD(v1->mBlendRate);
  *((_DWORD *)v3 + 40) = LODWORD(v1->mBlendParam);
  v3[155] = v1->mKeepBlend;
  v3[153] = v1->mSyncOnStart;
  v3[154] = v1->mPauseBlend;
  *((_DWORD *)v3 + 17) = v1->mName.mUID;
  *((_DWORD *)v3 + 16) = v1->mPriority;
  *((_QWORD *)v3 + 17) = v1->mWeightSet;
  *((_QWORD *)v3 + 18) = v1->mWeightSetMask;
  *((_DWORD *)v3 + 41) = v1->mWeightSetName.mUID;
  *((_DWORD *)v3 + 42) = v1->mWeightSetMaskName.mUID;
  PoseNodeParent::copyChildren((PoseNodeParent *)&v1->vfptr, (PoseNodeParent *)v3);
  return (PoseNode *)v3;
}

// File Line: 1434
// RVA: 0x3A58A0
BlendSubNode *__fastcall BlendSubNode::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB0ui64, "MemberMap::BlendSubNode", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  BlendNode::BlendNode((BlendNode *)v0);
  *(_QWORD *)v1 = &BlendSubNode::`vftable{for `Expression::IMemberMap};
  *((_QWORD *)v1 + 2) = &BlendSubNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v1[155] = 1;
  return (BlendSubNode *)v1;
}

// File Line: 1456
// RVA: 0x2AF4D0
PoseNode *__fastcall BlendSubNode::Clone(BlendSubNode *this)
{
  BlendSubNode *v1; // rdi
  char *v2; // rax
  char *v3; // rbx

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB0ui64, "BlendSubNode", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    BlendNode::BlendNode((BlendNode *)v2);
    *(_QWORD *)v3 = &BlendSubNode::`vftable{for `Expression::IMemberMap};
    *((_QWORD *)v3 + 2) = &BlendSubNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
    v3[155] = 1;
  }
  else
  {
    v3 = 0i64;
  }
  *((_DWORD *)v3 + 39) = LODWORD(v1->mBlendRate);
  *((_DWORD *)v3 + 40) = LODWORD(v1->mBlendParam);
  v3[155] = v1->mKeepBlend;
  v3[153] = v1->mSyncOnStart;
  v3[154] = v1->mPauseBlend;
  *((_DWORD *)v3 + 17) = v1->mName.mUID;
  PoseNodeParent::copyChildren((PoseNodeParent *)&v1->vfptr, (PoseNodeParent *)v3);
  return (PoseNode *)v3;
}

// File Line: 1473
// RVA: 0x30F470
void __fastcall BlendPhaseNode::BlendPhaseNode(BlendPhaseNode *this, float blendInTime)
{
  BlendPhaseNode *v2; // rbx

  v2 = this;
  BlendNode::BlendNode((BlendNode *)&this->vfptr, blendInTime);
  v2->vfptr = (Expression::IMemberMapVtbl *)&BlendPhaseNode::`vftable{for `Expression::IMemberMap};
  v2->vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&BlendPhaseNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  v2->mHoldPose = 0;
  v2->mKeepBlend = 1;
}

// File Line: 1476
// RVA: 0x2BDD20
__int64 __fastcall BlendPhaseNode::GetClassNameUID(BlendPhaseNode *this)
{
  return BlendPhaseNode::sClassNameUID;
}

// File Line: 1480
// RVA: 0x2AEE40
void __fastcall UELFragmentNode::Accept(MemberMapFileProject *this, MemberMapFileNodeVisitor *visitor)
{
  visitor->vfptr->Visit(visitor, this);
}

// File Line: 1515
// RVA: 0x2AF3B0
PoseNode *__fastcall BlendPhaseNode::Clone(BlendPhaseNode *this)
{
  BlendPhaseNode *v1; // rdi
  char *v2; // rax
  char *v3; // rbx

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB8ui64, "BlendPhaseNode", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    BlendNode::BlendNode((BlendNode *)v2);
    *(_QWORD *)v3 = &BlendPhaseNode::`vftable{for `Expression::IMemberMap};
    *((_QWORD *)v3 + 2) = &BlendPhaseNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
    v3[176] = 0;
    v3[155] = 1;
  }
  else
  {
    v3 = 0i64;
  }
  *((_DWORD *)v3 + 39) = LODWORD(v1->mBlendRate);
  *((_DWORD *)v3 + 40) = LODWORD(v1->mBlendParam);
  v3[155] = v1->mKeepBlend;
  v3[153] = v1->mSyncOnStart;
  v3[154] = v1->mPauseBlend;
  v3[176] = v1->mHoldPose;
  *((_DWORD *)v3 + 17) = v1->mName.mUID;
  *((_DWORD *)v3 + 16) = v1->mPriority;
  *((_QWORD *)v3 + 17) = v1->mWeightSet;
  *((_QWORD *)v3 + 18) = v1->mWeightSetMask;
  *((_DWORD *)v3 + 41) = v1->mWeightSetName.mUID;
  *((_DWORD *)v3 + 42) = v1->mWeightSetMaskName.mUID;
  PoseNodeParent::copyChildren((PoseNodeParent *)&v1->vfptr, (PoseNodeParent *)v3);
  return (PoseNode *)v3;
}

// File Line: 1553
// RVA: 0x3A56B0
void __fastcall AnimationNode::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x170ui64, "MemberMap::AnimationNode", 0i64, 1u);
  if ( v0 )
    AnimationNode::AnimationNode((AnimationNode *)v0);
}

// File Line: 1583
// RVA: 0x3AA750
void __fastcall AnimationNode::HoldLastFrame(AnimationNode *this)
{
  this->mPlayMode.mValue = 2;
}

// File Line: 1584
// RVA: 0x3AC540
void __fastcall AnimationNode::Pause(AnimationNode *this)
{
  this->mPause = 1;
}

// File Line: 1585
// RVA: 0x3AB2A0
_BOOL8 __fastcall AnimationNode::IsPaused(AnimationNode *this)
{
  return this->mPause != 0;
}

// File Line: 1586
// RVA: 0x3AE450
void __fastcall AnimationNode::Resume(AnimationNode *this)
{
  this->mPause = 0;
}

// File Line: 1587
// RVA: 0x3AD5C0
void __fastcall AnimationNode::PreserveMotion(AnimationNode *this, bool tf)
{
  this->mPreserveMotionOnHoldLastFrame = tf;
}

// File Line: 1603
// RVA: 0x3A8EF0
float __fastcall AnimationNode::GetLocalTime(AnimationNode *this)
{
  return this->mLocalTime;
}

// File Line: 1605
// RVA: 0x3AF610
void __fastcall AnimationNode::SetPlayRate(AnimationNode *this, float rate)
{
  this->mPlayRate = rate;
}

// File Line: 1606
// RVA: 0x3A9550
float __fastcall AnimationNode::GetPlayRate(AnimationNode *this)
{
  return this->mPlayRate;
}

// File Line: 1619
// RVA: 0x3AF5B0
void __fastcall AnimationNode::SetPlayMode(AnimationNode *this, AnimationPlayMode mode)
{
  this->mPlayMode.mValue = mode;
}

// File Line: 1633
// RVA: 0x3AA680
MotionPhase2 *__fastcall AnimationNode::Get_MotionPhase(AnimationNode *this)
{
  return &this->mMotionPhase;
}

// File Line: 1634
// RVA: 0x3AFAD0
void __fastcall AnimationNode::Set_MotionPhase(AnimationNode *this, Expression::IMemberMap *motionPhase)
{
  this->mMotionPhase.mResourceOwner = motionPhase->mResourceOwner;
  this->mMotionPhase.mPhaseMark.mValue = (unsigned int)motionPhase[1].vfptr;
  this->mMotionPhase.mPhasePeriod = HIDWORD(motionPhase[1].vfptr);
  this->mMotionPhase.mPhase = *(float *)&motionPhase[1].mResourceOwner;
  this->mMotionPhase.mPhaseDuration = *((float *)&motionPhase[1].mResourceOwner + 1);
}

// File Line: 1762
// RVA: 0x3A8EE0
__int64 __fastcall AnimationNode::GetIsFinished(AnimationNode *this)
{
  return ((__int64 (*)(void))this->vfptr[1].SetResourceOwner)();
}

