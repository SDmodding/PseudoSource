// File Line: 24
// RVA: 0x38A050
UFG::qString *__fastcall UFG::InvokeBehaviourResult::ToString(UFG::InvokeBehaviourResult *this, UFG::qString *result)
{
  char v4; // bl
  UFG::Behaviour *mBehaviour; // rcx
  char *mDesc; // rbp
  char *mData; // r15
  char *v8; // r14
  const char *v9; // rax
  UFG::qString v11; // [rsp+40h] [rbp-68h] BYREF
  UFG::qString resulta; // [rsp+68h] [rbp-40h] BYREF

  UFG::qString::qString(result);
  v4 = 1;
  mBehaviour = this->mBehaviour;
  mDesc = &customCaption;
  if ( mBehaviour && this->mId <= 0 )
  {
    v4 = 3;
    mData = UFG::InvokeBehaviourParams::ToString(&mBehaviour->mParams, &resulta, "Prev")->mData;
  }
  else
  {
    mData = &customCaption;
  }
  if ( this->mInvokeParams.mNode )
  {
    v4 |= 4u;
    v8 = UFG::InvokeBehaviourParams::ToString(&this->mInvokeParams, &v11, "New")->mData;
  }
  else
  {
    v8 = &customCaption;
  }
  if ( this->mDesc )
    mDesc = (char *)this->mDesc;
  v9 = UFG::InvokeBehaviourResult::ResultEnumToString(this->mId);
  UFG::qString::Format(result, "\nInvokeBehaviour: %s. %s\n%s%s", v9, mDesc, v8, mData);
  if ( (v4 & 4) != 0 )
  {
    v4 &= ~4u;
    UFG::qString::~qString(&v11);
  }
  if ( (v4 & 2) != 0 )
    UFG::qString::~qString(&resulta);
  return result;
}

// File Line: 36
// RVA: 0x389F20
UFG::qString *__fastcall UFG::InvokeBehaviourParams::ToString(
        UFG::InvokeBehaviourParams *this,
        UFG::qString *result,
        const char *prefix)
{
  ActionNode *mNode; // rcx
  char *String_DBG; // r9
  int mCount; // edx
  int mPriority; // [rsp+30h] [rbp-48h]
  ActionPath v11; // [rsp+60h] [rbp-18h] BYREF

  v11.mPath.mCount = 0;
  v11.mPath.mData.mOffset = 0i64;
  mNode = this->mNode;
  if ( mNode )
    ActionNode::GetNameFullPath(mNode, &v11);
  UFG::qString::qString(result);
  if ( this->mNode )
    String_DBG = ActionPath::GetString_DBG(&v11);
  else
    String_DBG = "NULL";
  mPriority = this->mPriority;
  UFG::qString::Format(
    result,
    "  %s: %s\n       Flags  [PriorityMode: %s, Control: %s]\n       Params [P: %d, Life: %.2f, Wait: %.2f]\n",
    prefix,
    String_DBG,
    gInvokeBehaviourPriorityModeNames[this->mPriorityMode],
    gInvokeBehaviourControlNames[this->mControlType],
    mPriority,
    this->mMaxLifeTime,
    this->mMaxWaitTime);
  mCount = v11.mPath.mCount;
  if ( v11.mPath.mCount >= 0 )
  {
    if ( v11.mPath.mData.mOffset && (UFG::qOffset64<ActionID *> *)((char *)&v11.mPath.mData + v11.mPath.mData.mOffset) )
    {
      operator delete[]((char *)&v11.mPath.mData + v11.mPath.mData.mOffset);
      mCount = v11.mPath.mCount;
    }
    v11.mPath.mData.mOffset = 0i64;
    v11.mPath.mCount = mCount & 0x80000000;
  }
  return result;
}

