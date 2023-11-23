// File Line: 109
// RVA: 0x298910
void __fastcall PoseNode::PoseNode(PoseNode *this)
{
  this->Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  UFG::qSafePointerNode<PoseNode>::qSafePointerNode<PoseNode>(&this->UFG::qSafePointerNode<PoseNode>);
  this->mPrev = &this->UFG::qNode<PoseNode,PoseNode>;
  this->mNext = &this->UFG::qNode<PoseNode,PoseNode>;
  this->Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&PoseNode::`vftable{for `Expression::IMemberMap};
  this->UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  this->mParent.mOffset = 0i64;
  this->mPriority = 0;
  *(_QWORD *)&this->mName.mUID = -1i64;
  *(_WORD *)&this->mBreakPoint = 0;
  this->mDebugPoseColour = UFG::qColour::Green;
}

// File Line: 293
// RVA: 0x2BD570
PoseNode *__fastcall PoseNode::FindFirstAtPriority(PoseNode *this, int priority)
{
  PoseNode *result; // rax

  result = 0i64;
  if ( priority >= this->mPriority )
    return this;
  return result;
}

// File Line: 302
// RVA: 0x2BD4E0
PoseNode *__fastcall PoseNode::Find(PoseNode *this, UFG::qSymbolUC *name)
{
  PoseNode *result; // rax

  result = 0i64;
  if ( name->mUID == this->mName.mUID )
    return this;
  return result;
}

// File Line: 329
// RVA: 0x29D520
void __fastcall PoseNodeParent::~PoseNodeParent(PoseNodeParent *this)
{
  UFG::qList<PoseNode,PoseNode,1,0> *p_mChildren; // rbx
  int *p_mNext; // rax
  int *i; // rsi
  _QWORD *v5; // rdx
  __int64 v6; // rcx
  _QWORD *v7; // rax
  UFG::qNode<PoseNode,PoseNode> *mPrev; // rcx
  UFG::qNode<PoseNode,PoseNode> *mNext; // rax
  __int64 mOffset; // rax
  char *v11; // rcx

  this->PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&PoseNodeParent::`vftable{for `Expression::IMemberMap};
  this->PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNodeParent::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  p_mChildren = &this->mChildren;
  p_mNext = (int *)&this->mChildren.mNode.mNext[-3].mNext;
  for ( i = &this->mNetPoseSequence; p_mNext != i; p_mNext = (int *)&p_mChildren->mNode.mNext[-3].mNext )
  {
    v5 = p_mNext + 10;
    v6 = *((_QWORD *)p_mNext + 5);
    v7 = (_QWORD *)*((_QWORD *)p_mNext + 6);
    *(_QWORD *)(v6 + 8) = v7;
    *v7 = v6;
    *v5 = v5;
    v5[1] = v5;
    if ( v5 != (_QWORD *)40 )
      (*(void (__fastcall **)(_QWORD *, __int64))(*(v5 - 5) + 8i64))(v5 - 5, 1i64);
  }
  UFG::qList<PoseNode,PoseNode,1,0>::DeleteNodes(p_mChildren);
  mPrev = p_mChildren->mNode.mPrev;
  mNext = p_mChildren->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mChildren->mNode.mPrev = &p_mChildren->mNode;
  p_mChildren->mNode.mNext = &p_mChildren->mNode;
  if ( this->mChildrenSerialized.mCount >= 0 )
  {
    mOffset = this->mChildrenSerialized.mData.mOffset;
    if ( mOffset )
    {
      v11 = (char *)&this->mChildrenSerialized.mData + mOffset;
      if ( v11 )
        operator delete[](v11);
    }
    this->mChildrenSerialized.mData.mOffset = 0i64;
    this->mChildrenSerialized.mCount &= 0x80000000;
  }
  PoseNode::~PoseNode(this);
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
  UFG::qNode<PoseNode,PoseNode> *mNext; // rax
  int *i; // rdi
  UFG::qNode<PoseNode,PoseNode> *v4; // rcx
  UFG::qNode<PoseNode,PoseNode> *mPrev; // rdx

  mNext = this->mChildren.mNode.mNext;
  for ( i = &this->mNetPoseSequence;
        &mNext[-3].mNext != (UFG::qNode<PoseNode,PoseNode> **)i;
        mNext = this->mChildren.mNode.mNext )
  {
    v4 = mNext->mNext;
    mPrev = mNext->mPrev;
    mPrev->mNext = v4;
    v4->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    if ( mNext != (UFG::qNode<PoseNode,PoseNode> *)40 )
      ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, __int64))mNext[-3].mNext->mNext)(&mNext[-3].mNext, 1i64);
  }
}

// File Line: 357
// RVA: 0x2BD6F0
Expression::IMemberMap *__fastcall PoseNodeParent::GetChild2(PoseNodeParent *this, __int64 priority)
{
  return (Expression::IMemberMap *)this->PoseNode::Expression::IMemberMap::vfptr[1].__vecDelDtor(this, priority);
}

// File Line: 358
// RVA: 0x2AF130
void __fastcall PoseNodeParent::AddChild2(PoseNodeParent *this, Expression::IMemberMap *node)
{
  ((void (__fastcall *)(PoseNodeParent *, Expression::IMemberMap *))this->PoseNode::Expression::IMemberMap::vfptr[4].GetClassNameUID)(
    this,
    node);
}

// File Line: 359
// RVA: 0x2BD3B0
void __fastcall PoseNodeParent::DeleteChild2(PoseNodeParent *this, Expression::IMemberMap *node)
{
  ((void (__fastcall *)(PoseNodeParent *, Expression::IMemberMap *))this->PoseNode::Expression::IMemberMap::vfptr[4].GetResourcePath)(
    this,
    node);
}

// File Line: 360
// RVA: 0x2AF190
void __fastcall PoseNodeParent::ChangeChildPriority2(
        PoseNodeParent *this,
        Expression::IMemberMap *node,
        __int64 increase)
{
  ((void (__fastcall *)(PoseNodeParent *, Expression::IMemberMap *, __int64))this->PoseNode::Expression::IMemberMap::vfptr[4].ResolveReferences)(
    this,
    node,
    increase);
}

// File Line: 414
// RVA: 0x2AF5A0
PoseNodeParent *__fastcall PoseNodeParent::Clone(PoseNodeParent *this)
{
  PoseNodeParent *v2; // rax
  PoseNodeParent *v3; // rbx

  v2 = PoseNodeParent::Create();
  v2->mName.mUID = this->mName.mUID;
  v3 = v2;
  PoseNodeParent::copyChildren(this, v2);
  return v3;
}

// File Line: 422
// RVA: 0x2DCD10
char __fastcall PoseNodeParent::Update(PoseNodeParent *this, float timeDelta, bool updateAnimation)
{
  __int64 v3; // rdx
  int *p_mNetPoseSequence; // rbp
  int *p_mNext; // rdi
  bool v7; // si
  __int64 v8; // rbx
  __int64 v9; // rdx
  _QWORD *v10; // rax

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (int *)&this->mChildren.mNode.mNext[-3].mNext;
  v7 = p_mNext == &this->mNetPoseSequence;
  this->mLocalTime = timeDelta + this->mLocalTime;
  if ( !p_mNext )
    return 1;
  do
  {
    if ( v7 )
      break;
    v8 = *((_QWORD *)p_mNext + 6) - 40i64;
    if ( (*(unsigned __int8 (__fastcall **)(int *, __int64, bool))(*(_QWORD *)p_mNext + 120i64))(
           p_mNext,
           v3,
           updateAnimation) )
    {
      v7 = v8 == (_QWORD)p_mNetPoseSequence;
    }
    else
    {
      v7 = !v8 || (int *)v8 == p_mNetPoseSequence;
      v9 = *((_QWORD *)p_mNext + 5);
      v10 = (_QWORD *)*((_QWORD *)p_mNext + 6);
      *(_QWORD *)(v9 + 8) = v10;
      *v10 = v9;
      *((_QWORD *)p_mNext + 5) = p_mNext + 10;
      *((_QWORD *)p_mNext + 6) = p_mNext + 10;
      (*(void (__fastcall **)(int *, __int64))(*(_QWORD *)p_mNext + 8i64))(p_mNext, 1i64);
    }
    p_mNext = (int *)v8;
  }
  while ( v8 );
  return 1;
}

// File Line: 465
// RVA: 0x2DD020
void __fastcall PoseNodeParent::copyChildren(PoseNodeParent *this, PoseNodeParent *clone)
{
  int *p_mNetPoseSequence; // rbp
  PoseNodeParent *p_mNext; // rbx
  Expression::IMemberMapVtbl *vfptr; // rdi
  __int64 v6; // rax

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      vfptr = clone->PoseNode::Expression::IMemberMap::vfptr;
      v6 = ((__int64 (__fastcall *)(PoseNodeParent *))p_mNext->PoseNode::Expression::IMemberMap::vfptr[1].Serialize)(p_mNext);
      ((void (__fastcall *)(PoseNodeParent *, __int64))vfptr[4].GetClassNameUID)(clone, v6);
      p_mNext = (PoseNodeParent *)&p_mNext->mNext[-3].mNext;
    }
    while ( p_mNext != (PoseNodeParent *)p_mNetPoseSequence );
  }
}

// File Line: 474
// RVA: 0x2DCBF0
void __fastcall PoseNodeParent::SetParametricPlayTime(PoseNodeParent *this, float parametric)
{
  int *p_mNetPoseSequence; // rdi
  PoseNodeParent *p_mNext; // rbx

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      p_mNext->PoseNode::Expression::IMemberMap::vfptr[3].GetClassNameUID(p_mNext);
      p_mNext = (PoseNodeParent *)&p_mNext->mNext[-3].mNext;
    }
    while ( p_mNext != (PoseNodeParent *)p_mNetPoseSequence );
  }
}

// File Line: 483
// RVA: 0x2DCB60
void __fastcall PoseNodeParent::SetLocalTime(PoseNodeParent *this, float localTime)
{
  int *p_mNetPoseSequence; // rdi
  PoseNodeParent *p_mNext; // rbx

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      ((void (__fastcall *)(PoseNodeParent *))p_mNext->PoseNode::Expression::IMemberMap::vfptr[3].GetResourcePath)(p_mNext);
      p_mNext = (PoseNodeParent *)&p_mNext->mNext[-3].mNext;
    }
    while ( p_mNext != (PoseNodeParent *)p_mNetPoseSequence );
  }
}

// File Line: 492
// RVA: 0x2BD700
PoseNodeParent *__fastcall PoseNodeParent::GetChild(PoseNodeParent *this, int priority)
{
  PoseNodeParent *p_mNext; // r8
  PoseNodeParent *v3; // rax

  p_mNext = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext == (PoseNodeParent *)&this->mNetPoseSequence )
    return 0i64;
  while ( 1 )
  {
    v3 = (PoseNodeParent *)&p_mNext->mNext[-3].mNext;
    if ( !priority )
      break;
    --priority;
    p_mNext = (PoseNodeParent *)&p_mNext->mNext[-3].mNext;
    if ( v3 == (PoseNodeParent *)&this->mNetPoseSequence )
      return 0i64;
  }
  return p_mNext;
}

// File Line: 507
// RVA: 0x2BD730
__int64 __fastcall PoseNodeParent::GetChildCount(PoseNodeParent *this)
{
  UFG::qNode<PoseNode,PoseNode> *mNext; // rdx
  int *p_mNetPoseSequence; // rcx
  __int64 result; // rax
  __int64 i; // rdx

  mNext = this->mChildren.mNode.mNext;
  p_mNetPoseSequence = &this->mNetPoseSequence;
  result = 0i64;
  for ( i = (__int64)&mNext[-3].mNext; (int *)i != p_mNetPoseSequence; i = *(_QWORD *)(i + 48) - 40i64 )
    result = (unsigned int)(result + 1);
  return result;
}

// File Line: 512
// RVA: 0x2AF140
void __fastcall PoseNodeParent::AddChild(PoseNodeParent *this, PoseNode *node)
{
  UFG::qOffset64<PoseNodeParent *> *p_mParent; // r8
  char *v3; // rax
  UFG::qNode<PoseNode,PoseNode> *mPrev; // rax

  p_mParent = &node->mParent;
  if ( this )
    v3 = (char *)((char *)this - (char *)p_mParent);
  else
    v3 = 0i64;
  p_mParent->mOffset = (__int64)v3;
  mPrev = this->mChildren.mNode.mPrev;
  mPrev->mNext = &node->UFG::qNode<PoseNode,PoseNode>;
  node->mPrev = mPrev;
  node->mNext = &this->mChildren.mNode;
  this->mChildren.mNode.mPrev = &node->UFG::qNode<PoseNode,PoseNode>;
}

// File Line: 518
// RVA: 0x2BD3C0
void __fastcall PoseNodeParent::DeleteChild(PoseNodeParent *this, PoseNode *child)
{
  UFG::qNode<PoseNode,PoseNode> *mPrev; // rcx
  UFG::qNode<PoseNode,PoseNode> *mNext; // rax

  mPrev = child->mPrev;
  mNext = child->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  child->mPrev = &child->UFG::qNode<PoseNode,PoseNode>;
  child->mNext = &child->UFG::qNode<PoseNode,PoseNode>;
  if ( child )
    child->Expression::IMemberMap::vfptr->__vecDelDtor(child, 1u);
}

// File Line: 524
// RVA: 0x2DC820
void __fastcall PoseNodeParent::RemoveChild(PoseNodeParent *this, PoseNode *child)
{
  UFG::qNode<PoseNode,PoseNode> *mPrev; // rcx
  UFG::qNode<PoseNode,PoseNode> *mNext; // rax

  mPrev = child->mPrev;
  mNext = child->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  child->mPrev = &child->UFG::qNode<PoseNode,PoseNode>;
  child->mNext = &child->UFG::qNode<PoseNode,PoseNode>;
  child->mParent.mOffset = 0i64;
}

// File Line: 530
// RVA: 0x2DC850
void __fastcall PoseNodeParent::Replace(PoseNodeParent *this, PoseNode *currentChild, PoseNode *newChild)
{
  UFG::qNode<PoseNode,PoseNode> *mPrev; // rax
  UFG::qNode<PoseNode,PoseNode> *v4; // r9
  UFG::qOffset64<PoseNodeParent *> *p_mParent; // r8

  mPrev = currentChild->mPrev;
  v4 = &newChild->UFG::qNode<PoseNode,PoseNode>;
  mPrev->mNext = &newChild->UFG::qNode<PoseNode,PoseNode>;
  p_mParent = &newChild->mParent;
  v4->mPrev = mPrev;
  v4->mNext = &currentChild->UFG::qNode<PoseNode,PoseNode>;
  currentChild->mPrev = v4;
  if ( this )
  {
    p_mParent->mOffset = (char *)this - (char *)p_mParent;
    ((void (__fastcall *)(PoseNodeParent *))this->PoseNode::Expression::IMemberMap::vfptr[4].SetResourceOwner)(this);
  }
  else
  {
    p_mParent->mOffset = 0i64;
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
void __fastcall PoseNodeParent::GetExtractedDeltaReferenceFrame(
        PoseNodeParent *this,
        float deltaTime,
        hkQsTransformf *deltaMotionOut)
{
  PoseNodeParent *p_mNext; // rdx

  p_mNext = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext != (PoseNodeParent *)&this->mNetPoseSequence )
    ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **))p_mNext->PoseNode::Expression::IMemberMap::vfptr[1].GetResourcePath)(&this->mChildren.mNode.mNext[-3].mNext);
}

// File Line: 556
// RVA: 0x2DCAE0
void __fastcall PoseNodeParent::SetActiveDirection(PoseNodeParent *this, float activeDirection, bool force)
{
  UFG::qNode<PoseNode,PoseNode> *mNext; // rax
  int *p_mNetPoseSequence; // rcx
  __int64 i; // rax

  mNext = this->mChildren.mNode.mNext;
  p_mNetPoseSequence = &this->mNetPoseSequence;
  for ( i = (__int64)&mNext[-3].mNext; (int *)i != p_mNetPoseSequence; i = *(_QWORD *)(i + 48) - 40i64 )
    ;
}

// File Line: 566
// RVA: 0x2DCB00
void __fastcall PoseNodeParent::SetContext(PoseNodeParent *this, ActionContext *context)
{
  int *p_mNetPoseSequence; // rdi
  PoseNodeParent *p_mNext; // rbx

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      ((void (__fastcall *)(PoseNodeParent *, ActionContext *))p_mNext->PoseNode::Expression::IMemberMap::vfptr[2].GetResourceOwner)(
        p_mNext,
        context);
      p_mNext = (PoseNodeParent *)&p_mNext->mNext[-3].mNext;
    }
    while ( p_mNext != (PoseNodeParent *)p_mNetPoseSequence );
  }
}

// File Line: 575
// RVA: 0x2BD580
PoseNodeParent *__fastcall PoseNodeParent::FindFirstAtPriority(PoseNodeParent *this, int priority)
{
  PoseNodeParent *result; // rax
  int *p_mNetPoseSequence; // rdi
  PoseNodeParent *p_mNext; // rbx

  if ( priority >= this->mPriority )
    return this;
  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext == (PoseNodeParent *)&this->mNetPoseSequence )
    return 0i64;
  while ( 1 )
  {
    result = (PoseNodeParent *)((__int64 (__fastcall *)(PoseNodeParent *, _QWORD))p_mNext->PoseNode::Expression::IMemberMap::vfptr[3].GetResourceOwner)(
                                 p_mNext,
                                 (unsigned int)priority);
    if ( result )
      break;
    p_mNext = (PoseNodeParent *)&p_mNext->mNext[-3].mNext;
    if ( p_mNext == (PoseNodeParent *)p_mNetPoseSequence )
      return 0i64;
  }
  return result;
}

// File Line: 595
// RVA: 0x2BD4F0
PoseNodeParent *__fastcall PoseNodeParent::Find(PoseNodeParent *this, UFG::qSymbolUC *name)
{
  PoseNodeParent *result; // rax
  int *p_mNetPoseSequence; // rdi
  PoseNodeParent *p_mNext; // rbx

  if ( name->mUID == this->mName.mUID )
    return this;
  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext == (PoseNodeParent *)&this->mNetPoseSequence )
    return 0i64;
  while ( 1 )
  {
    result = (PoseNodeParent *)p_mNext->PoseNode::Expression::IMemberMap::vfptr[4].FindWithOldPath(
                                 p_mNext,
                                 (const char *)name);
    if ( result )
      break;
    p_mNext = (PoseNodeParent *)&p_mNext->mNext[-3].mNext;
    if ( p_mNext == (PoseNodeParent *)p_mNetPoseSequence )
      return 0i64;
  }
  return result;
}

// File Line: 615
// RVA: 0x2DCC80
void __fastcall PoseNodeParent::SetPlayPriority(PoseNodeParent *this, unsigned int playPriority)
{
  int *p_mNetPoseSequence; // rsi
  PoseNodeParent *p_mNext; // rbx

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  this->mPriority = playPriority;
  if ( p_mNext != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      p_mNext->PoseNode::Expression::IMemberMap::vfptr[4].__vecDelDtor(p_mNext, playPriority);
      p_mNext = (PoseNodeParent *)&p_mNext->mNext[-3].mNext;
    }
    while ( p_mNext != (PoseNodeParent *)p_mNetPoseSequence );
  }
}

// File Line: 625
// RVA: 0x2DC490
void __fastcall PoseNodeParent::PreserveMotion(PoseNodeParent *this, bool tf)
{
  int *p_mNetPoseSequence; // rdi
  PoseNodeParent *p_mNext; // rbx

  p_mNetPoseSequence = &this->mNetPoseSequence;
  p_mNext = (PoseNodeParent *)&this->mChildren.mNode.mNext[-3].mNext;
  if ( p_mNext != (PoseNodeParent *)&this->mNetPoseSequence )
  {
    do
    {
      p_mNext->PoseNode::Expression::IMemberMap::vfptr[3].__vecDelDtor(p_mNext, tf);
      p_mNext = (PoseNodeParent *)&p_mNext->mNext[-3].mNext;
    }
    while ( p_mNext != (PoseNodeParent *)p_mNetPoseSequence );
  }
}

// File Line: 704
// RVA: 0x39E400
void __fastcall PoseNodeRoot::PoseNodeRoot(PoseNodeRoot *this)
{
  PoseNode::PoseNode(this);
  this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&PoseNodeParent::`vftable{for `Expression::IMemberMap};
  this->PoseNodeParent::PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNodeParent::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  this->mChildrenSerialized.mCount = 0;
  this->mChildrenSerialized.mData.mOffset = 0i64;
  this->mChildren.mNode.PoseNodeParent::mPrev = &this->mChildren.mNode;
  this->mChildren.mNode.mNext = &this->mChildren.mNode;
  this->mLocalTime = 0.0;
  this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&PoseNodeRoot::`vftable{for `Expression::IMemberMap};
  this->PoseNodeParent::PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNodeRoot::`vftable{for `UFG::qSafePointerNode<PoseNode>};
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
  this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&BlendNode::`vftable{for `Expression::IMemberMap};
  this->PoseNodeParent::PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&BlendNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  PoseNodeParent::~PoseNodeParent(this);
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
  PoseNode::PoseNode(this);
  this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&PoseNodeParent::`vftable{for `Expression::IMemberMap};
  this->PoseNodeParent::PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNodeParent::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  this->mChildrenSerialized.mCount = 0;
  this->mChildrenSerialized.mData.mOffset = 0i64;
  this->mChildren.mNode.PoseNodeParent::mPrev = &this->mChildren.mNode;
  this->mChildren.mNode.mNext = &this->mChildren.mNode;
  this->mLocalTime = 0.0;
  this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&BlendNode::`vftable{for `Expression::IMemberMap};
  this->PoseNodeParent::PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&BlendNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  this->mWeightSet = 0i64;
  this->mWeightSetMask = 0i64;
  *(_DWORD *)&this->mStarted = 0;
  *(_QWORD *)&this->mBlendRate = 1065353216i64;
  *(_QWORD *)&this->mWeightSetName.mUID = -1i64;
}

// File Line: 872
// RVA: 0x30F380
void __fastcall BlendNode::BlendNode(BlendNode *this, float blendInTime)
{
  PoseNode::PoseNode(this);
  this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&PoseNodeParent::`vftable{for `Expression::IMemberMap};
  this->PoseNodeParent::PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNodeParent::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  this->mChildrenSerialized.mCount = 0;
  this->mChildrenSerialized.mData.mOffset = 0i64;
  this->mChildren.mNode.PoseNodeParent::mPrev = &this->mChildren.mNode;
  this->mChildren.mNode.mNext = &this->mChildren.mNode;
  this->mLocalTime = 0.0;
  this->PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&BlendNode::`vftable{for `Expression::IMemberMap};
  this->PoseNodeParent::PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&BlendNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  this->mWeightSet = 0i64;
  this->mWeightSetMask = 0i64;
  *(_DWORD *)&this->mStarted = 0;
  *(_QWORD *)&this->mBlendRate = 1065353216i64;
  *(_QWORD *)&this->mWeightSetName.mUID = -1i64;
  if ( blendInTime == 0.0 )
  {
    this->mBlendRate = 1.0;
    this->mBlendParam = 1.0;
  }
  else if ( blendInTime > 0.0 )
  {
    this->mBlendRate = 1.0 / blendInTime;
    this->mBlendParam = 0.0;
  }
}

// File Line: 888
// RVA: 0x2AF2C0
PoseNode *__fastcall BlendNode::Clone(BlendNode *this)
{
  char *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx

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
  *(float *)(v4 + 156) = this->mBlendRate;
  *(float *)(v4 + 160) = this->mBlendParam;
  *(_BYTE *)(v4 + 155) = this->mKeepBlend;
  *(_BYTE *)(v4 + 153) = this->mSyncOnStart;
  *(_BYTE *)(v4 + 154) = this->mPauseBlend;
  *(_DWORD *)(v4 + 68) = this->mName.mUID;
  *(_DWORD *)(v4 + 64) = this->mPriority;
  *(_QWORD *)(v4 + 136) = this->mWeightSet;
  *(_QWORD *)(v4 + 144) = this->mWeightSetMask;
  *(_DWORD *)(v4 + 164) = this->mWeightSetName.mUID;
  *(_DWORD *)(v4 + 168) = this->mWeightSetMaskName.mUID;
  PoseNodeParent::copyChildren(this, (PoseNodeParent *)v4);
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
  char *v2; // rax
  BlendDirectionNode *v3; // rax
  BlendDirectionNode *v4; // rbx

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
  BlendDirectionNode::operator=(v4, this);
  v4->mNetPoseSequence = -1;
  v4->mName.mUID = this->mName.mUID;
  PoseNodeParent::copyChildren(this, v4);
  return v4;
}

// File Line: 1377
// RVA: 0x30F330
void __fastcall BlendAddNode::BlendAddNode(BlendAddNode *this, float blendInTime)
{
  BlendNode::BlendNode(this, blendInTime);
  this->BlendNode::PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&BlendAddNode::`vftable{for `Expression::IMemberMap};
  this->BlendNode::PoseNodeParent::PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&BlendAddNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  this->mKeepBlend = 1;
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
  char *v2; // rax
  char *v3; // rbx

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
  *((_DWORD *)v3 + 39) = LODWORD(this->mBlendRate);
  *((_DWORD *)v3 + 40) = LODWORD(this->mBlendParam);
  v3[155] = this->mKeepBlend;
  v3[153] = this->mSyncOnStart;
  v3[154] = this->mPauseBlend;
  *((_DWORD *)v3 + 17) = this->mName.mUID;
  *((_DWORD *)v3 + 16) = this->mPriority;
  *((_QWORD *)v3 + 17) = this->mWeightSet;
  *((_QWORD *)v3 + 18) = this->mWeightSetMask;
  *((_DWORD *)v3 + 41) = this->mWeightSetName.mUID;
  *((_DWORD *)v3 + 42) = this->mWeightSetMaskName.mUID;
  PoseNodeParent::copyChildren(this, (PoseNodeParent *)v3);
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
  char *v2; // rax
  char *v3; // rbx

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
  *((_DWORD *)v3 + 39) = LODWORD(this->mBlendRate);
  *((_DWORD *)v3 + 40) = LODWORD(this->mBlendParam);
  v3[155] = this->mKeepBlend;
  v3[153] = this->mSyncOnStart;
  v3[154] = this->mPauseBlend;
  *((_DWORD *)v3 + 17) = this->mName.mUID;
  PoseNodeParent::copyChildren(this, (PoseNodeParent *)v3);
  return (PoseNode *)v3;
}

// File Line: 1473
// RVA: 0x30F470
void __fastcall BlendPhaseNode::BlendPhaseNode(BlendPhaseNode *this, float blendInTime)
{
  BlendNode::BlendNode(this, blendInTime);
  this->BlendNode::PoseNodeParent::PoseNode::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&BlendPhaseNode::`vftable{for `Expression::IMemberMap};
  this->BlendNode::PoseNodeParent::PoseNode::UFG::qSafePointerNode<PoseNode>::vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&BlendPhaseNode::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  this->mHoldPose = 0;
  this->mKeepBlend = 1;
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
  char *v2; // rax
  char *v3; // rbx

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
  *((_DWORD *)v3 + 39) = LODWORD(this->mBlendRate);
  *((_DWORD *)v3 + 40) = LODWORD(this->mBlendParam);
  v3[155] = this->mKeepBlend;
  v3[153] = this->mSyncOnStart;
  v3[154] = this->mPauseBlend;
  v3[176] = this->mHoldPose;
  *((_DWORD *)v3 + 17) = this->mName.mUID;
  *((_DWORD *)v3 + 16) = this->mPriority;
  *((_QWORD *)v3 + 17) = this->mWeightSet;
  *((_QWORD *)v3 + 18) = this->mWeightSetMask;
  *((_DWORD *)v3 + 41) = this->mWeightSetName.mUID;
  *((_DWORD *)v3 + 42) = this->mWeightSetMaskName.mUID;
  PoseNodeParent::copyChildren(this, (PoseNodeParent *)v3);
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
void __fastcall AnimationNode::PreserveMotion(AnimationNode *this, char tf)
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
  *(_QWORD *)&this->mMotionPhase.mPhase = motionPhase[1].mResourceOwner;
}

// File Line: 1762
// RVA: 0x3A8EE0
__int64 __fastcall AnimationNode::GetIsFinished(AnimationNode *this)
{
  return ((__int64 (__fastcall *)(AnimationNode *))this->PoseNode::Expression::IMemberMap::vfptr[1].SetResourceOwner)(this);
}

