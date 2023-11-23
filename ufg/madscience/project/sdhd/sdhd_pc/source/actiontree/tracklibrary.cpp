// File Line: 27
// RVA: 0x1480750
__int64 dynamic_initializer_for__TrackLibraryNode::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TrackLibraryNode", 0xFFFFFFFF);
  TrackLibraryNode::sClassNameUID = result;
  return result;
}

// File Line: 69
// RVA: 0x26D310
ActionNodeImplementation *__fastcall TrackLibraryNode::CreateClone(TrackLibraryNode *this)
{
  char *v2; // rax
  ActionNodeImplementation *v3; // rbx

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x58ui64, "ActionNodePlayable::CreateClone", 0i64, 1u);
  v3 = (ActionNodeImplementation *)v2;
  if ( v2 )
  {
    ActionNodeImplementation::ActionNodeImplementation((ActionNodeImplementation *)v2);
    v3->vfptr = (Expression::IMemberMapVtbl *)&ActionNodePlayable::`vftable;
    v3->vfptr = (Expression::IMemberMapVtbl *)&TrackLibraryNode::`vftable;
  }
  else
  {
    v3 = 0i64;
  }
  ActionNodeImplementation::CopyFrom(v3, this);
  return v3;
}

// File Line: 95
// RVA: 0x1480570
__int64 dynamic_initializer_for__ExecuteTrackLibraryTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ExecuteTrackLibraryTrack", 0xFFFFFFFF);
  ExecuteTrackLibraryTrack::sClassNameUID = result;
  return result;
}

// File Line: 102
// RVA: 0x268C30
void __fastcall ExecuteTrackLibraryTrack::ExecuteTrackLibraryTrack(ExecuteTrackLibraryTrack *this)
{
  NodeRefTrack<ExecuteTrackLibraryTask>::NodeRefTrack<ExecuteTrackLibraryTask>(
    this,
    ExecuteTrackLibraryTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&ExecuteTrackLibraryTrack::`vftable;
}

// File Line: 107
// RVA: 0x271CC0
void __fastcall ExecuteTrackLibraryTrack::ResolveReferences(
        ExecuteTrackLibraryTrack *this,
        ActionNode *pParentActionNode)
{
  __int64 mOffset; // rax
  char *v5; // rax
  __int64 v6; // rcx
  ActionNode *v7; // rcx
  int mCount; // edx
  ActionPath v9; // [rsp+28h] [rbp-30h] BYREF
  ActionPath pathToPopulate; // [rsp+38h] [rbp-20h] BYREF

  ((void (__fastcall *)(ExecuteTrackLibraryTrack *))this->vfptr[2].FindWithOldPath)(this);
  ((void (__fastcall *)(ExecuteTrackLibraryTrack *, ActionNode *))this->vfptr[1].GetResourceOwner)(
    this,
    pParentActionNode);
  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset )
    v5 = (char *)&this->mActionNodeReference + mOffset;
  else
    v5 = 0i64;
  v6 = *((_QWORD *)v5 + 9);
  if ( v6 )
    v7 = (ActionNode *)&v5[v6 + 72];
  else
    v7 = 0i64;
  if ( pParentActionNode && v7 )
  {
    pathToPopulate.mPath.mCount = 0;
    pathToPopulate.mPath.mData.mOffset = 0i64;
    v9.mPath.mCount = 0;
    v9.mPath.mData.mOffset = 0i64;
    ActionNode::GetNameFullPath(v7, &pathToPopulate);
    ActionNode::GetNameFullPath(pParentActionNode, &v9);
    mCount = v9.mPath.mCount;
    if ( v9.mPath.mCount >= 0 )
    {
      if ( v9.mPath.mData.mOffset && (UFG::qOffset64<ActionID *> *)((char *)&v9.mPath.mData + v9.mPath.mData.mOffset) )
      {
        operator delete[]((char *)&v9.mPath.mData + v9.mPath.mData.mOffset);
        mCount = v9.mPath.mCount;
      }
      v9.mPath.mData.mOffset = 0i64;
      v9.mPath.mCount = mCount & 0x80000000;
    }
    if ( pathToPopulate.mPath.mCount >= 0 && pathToPopulate.mPath.mData.mOffset )
    {
      if ( (UFG::qOffset64<ActionID *> *)((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset) )
        operator delete[]((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset);
    }
  }
}

