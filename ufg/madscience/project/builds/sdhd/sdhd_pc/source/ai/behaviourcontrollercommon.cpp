// File Line: 24
// RVA: 0x38A050
UFG::qString *__fastcall UFG::InvokeBehaviourResult::ToString(UFG::InvokeBehaviourResult *this, UFG::qString *result)
{
  UFG::qString *v2; // rdi
  UFG::InvokeBehaviourResult *v3; // rsi
  signed int v4; // ebx
  UFG::Behaviour *v5; // rcx
  char *v6; // rbp
  char *v7; // r15
  char *v8; // r14
  const char *v9; // rax
  _QWORD v11[2]; // [rsp+30h] [rbp-78h]
  UFG::qString v12; // [rsp+40h] [rbp-68h]
  UFG::qString resulta; // [rsp+68h] [rbp-40h]

  v2 = result;
  v3 = this;
  UFG::qString::qString(result);
  v4 = 1;
  LODWORD(v11[0]) = 1;
  v5 = v3->mBehaviour;
  v6 = &customWorldMapCaption;
  if ( v5 && v3->mId <= 0 )
  {
    v4 = 3;
    LODWORD(v11[0]) = 3;
    v7 = UFG::InvokeBehaviourParams::ToString(&v5->mParams, &resulta, "Prev")->mData;
  }
  else
  {
    v7 = &customWorldMapCaption;
  }
  if ( v3->mInvokeParams.mNode )
  {
    v4 |= 4u;
    LODWORD(v11[0]) = v4;
    v8 = UFG::InvokeBehaviourParams::ToString(&v3->mInvokeParams, &v12, "New")->mData;
  }
  else
  {
    v8 = &customWorldMapCaption;
  }
  if ( v3->mDesc )
    v6 = (char *)v3->mDesc;
  v9 = UFG::InvokeBehaviourResult::ResultEnumToString(v3->mId);
  UFG::qString::Format(v2, "\nInvokeBehaviour: %s. %s\n%s%s", v9, v6, v8, v7, v11[0], -2i64);
  if ( v4 & 4 )
  {
    LOBYTE(v4) = v4 & 0xFB;
    UFG::qString::~qString(&v12);
  }
  if ( v4 & 2 )
    UFG::qString::~qString(&resulta);
  return v2;
}

// File Line: 36
// RVA: 0x389F20
UFG::qString *__fastcall UFG::InvokeBehaviourParams::ToString(UFG::InvokeBehaviourParams *this, UFG::qString *result, const char *prefix)
{
  const char *v3; // rsi
  UFG::qString *v4; // rbx
  UFG::InvokeBehaviourParams *v5; // rdi
  ActionNode *v6; // rcx
  char *v7; // r9
  int v8; // edx
  __int64 v10; // [rsp+30h] [rbp-48h]
  ActionPath v11; // [rsp+60h] [rbp-18h]

  v3 = prefix;
  v4 = result;
  v5 = this;
  v11.mPath.mCount = 0;
  v11.mPath.mData.mOffset = 0i64;
  v6 = this->mNode;
  if ( v6 )
    ActionNode::GetNameFullPath(v6, &v11);
  UFG::qString::qString(v4);
  if ( v5->mNode )
    v7 = ActionPath::GetString_DBG(&v11);
  else
    v7 = "NULL";
  LODWORD(v10) = v5->mPriority;
  UFG::qString::Format(
    v4,
    "  %s: '%s'\n       Flags  [PriorityMode: '%s', Control: '%s']\n       Params [P: %d, Life: %.2f, Wait: %.2f]\n",
    v3,
    v7,
    gInvokeBehaviourPriorityModeNames[v5->mPriorityMode],
    gInvokeBehaviourControlNames[v5->mControlType],
    v10,
    v5->mMaxLifeTime,
    v5->mMaxWaitTime);
  v8 = v11.mPath.mCount;
  if ( v11.mPath.mCount >= 0 )
  {
    if ( v11.mPath.mData.mOffset && (UFG::qOffset64<ActionID *> *)((char *)&v11.mPath.mData + v11.mPath.mData.mOffset) )
    {
      operator delete[]((char *)&v11.mPath.mData + v11.mPath.mData.mOffset);
      v8 = v11.mPath.mCount;
    }
    v11.mPath.mData.mOffset = 0i64;
    v11.mPath.mCount = v8 & 0x80000000;
  }
  return v4;
}

