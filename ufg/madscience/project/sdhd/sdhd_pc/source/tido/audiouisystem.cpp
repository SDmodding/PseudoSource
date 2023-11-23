// File Line: 16
// RVA: 0x1554B00
__int64 dynamic_initializer_for__UFG::AudioUISystem::smScreenList__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::AudioUISystem::smScreenList.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AudioUISystem::smScreenList__);
}

// File Line: 49
// RVA: 0x597270
void __fastcall UFG::AudioUISystem::BasicHandler(
        const char *pScreenName,
        unsigned int screenHash,
        unsigned int msgId,
        unsigned int resultId)
{
  UFG::AudioUISystem::HandleInput(screenHash, msgId, 0, 1);
}

// File Line: 55
// RVA: 0x59E9E0
char __fastcall UFG::AudioUISystem::HandleInput(const char *screenName, unsigned int inputUID, bool playEvent)
{
  char *Last; // rsi
  char *v8; // rax
  unsigned int v9; // eax
  char v10; // bl
  UFG::qString v11; // [rsp+38h] [rbp-30h] BYREF

  if ( inputUID == UI_HASH_INVALID_27 )
    return 1;
  UFG::qString::qString(&v11);
  Last = UFG::qStringFindLast(screenName, "/");
  v8 = UFG::qStringFindLast(screenName, ".");
  if ( Last && v8 )
    UFG::qString::Set(&v11, Last + 1, (_DWORD)v8 - (_DWORD)Last - 1, 0i64, 0);
  else
    UFG::qString::Set(&v11, screenName);
  v9 = UFG::qStringHashUpper32(v11.mData, -1);
  v10 = UFG::AudioUISystem::HandleInput(v9, inputUID, 0, playEvent);
  UFG::qString::~qString(&v11);
  return v10;
}

// File Line: 66
// RVA: 0x59E880
char __fastcall UFG::AudioUISystem::HandleInput(
        unsigned int screenUID,
        unsigned int inputUID,
        unsigned int switchOverride,
        bool playEvent)
{
  unsigned int v6; // edi
  unsigned int v7; // eax
  char v9; // bl
  UFG::qBaseTreeRB *v10; // rax
  int *p_mCount; // rdi
  UFG::qBaseTreeRB *v12; // rax
  int *v13; // rax
  unsigned int v14; // edx
  unsigned int v15; // r8d
  UFG::qBaseTreeRB *v16; // rax
  UFG::qBaseTreeRB *v17; // rax
  int *v18; // rax

  v6 = screenUID;
  if ( (_S40_0 & 1) != 0 )
  {
    v7 = defaultScreenUID;
  }
  else
  {
    _S40_0 |= 1u;
    v7 = UFG::qStringHashUpper32("Default", -1);
    defaultScreenUID = v7;
  }
  if ( inputUID == UI_HASH_INVALID_27 )
    return 1;
  v9 = 0;
  if ( !v6 )
    goto LABEL_28;
  v10 = UFG::qBaseTreeRB::Get(&UFG::AudioUISystem::smScreenList.mTree, v6);
  if ( !v10 )
  {
LABEL_27:
    v7 = defaultScreenUID;
LABEL_28:
    if ( v6 != v7 )
      return UFG::AudioUISystem::HandleInput(v7, inputUID, 0, playEvent);
    return v9;
  }
  p_mCount = &v10[-1].mCount;
  if ( v10 == (UFG::qBaseTreeRB *)8 )
  {
    v6 = screenUID;
    goto LABEL_27;
  }
  if ( inputUID
    && (v12 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)(p_mCount + 12), inputUID)) != 0i64
    && (v13 = &v12[-1].mCount) != 0i64 )
  {
    v14 = v13[12];
    if ( v14 == -1 )
      v14 = p_mCount[11];
    if ( switchOverride )
      v15 = switchOverride;
    else
      v15 = v13[13];
    UFG::AudioEntity::SetWwiseSwitch(UFG::HudAudio::m_instance, v14, v15);
    return 1;
  }
  else
  {
    v16 = UFG::qBaseTreeRB::Get(&UFG::AudioUISystem::smScreenList.mTree, 0xBAE5C714);
    if ( v16 )
    {
      if ( v16 != (UFG::qBaseTreeRB *)8 )
      {
        if ( inputUID )
        {
          v17 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)v16->mNULL.mChild, inputUID);
          if ( v17 )
          {
            v18 = &v17[-1].mCount;
            if ( v18 )
            {
              if ( playEvent )
                UFG::AudioEntity::SetWwiseSwitch(UFG::HudAudio::m_instance, p_mCount[11], v18[13]);
              return 1;
            }
          }
        }
      }
    }
  }
  return v9;
}

// File Line: 186
// RVA: 0x5A2460
void __fastcall UFG::AudioUISystem::LoadUISoundDataCallback(SimpleXML::XMLDocument *pXmlDoc)
{
  SimpleXML::XMLDocument *v1; // rdi
  SimpleXML::XMLNode *Node; // rax
  SimpleXML::XMLNode *ChildNode; // rsi
  char *Attribute; // rax
  unsigned int v5; // eax
  unsigned int v6; // ebx
  UFG::qBaseTreeRB *v7; // rax
  UFG::allocator::free_link *p_mCount; // r15
  UFG::allocator::free_link *v9; // rax
  char *v10; // rax
  char *v11; // rax
  SimpleXML::XMLNode *v12; // rbp
  char *v13; // rdi
  char v14; // r12
  char v15; // r13
  char v16; // bl
  int v17; // r14d
  char *v18; // rax
  char *v19; // r8
  char *v20; // rax
  char *v21; // rax
  unsigned int v22; // eax
  unsigned int v23; // edi
  char v24; // si
  UFG::qBaseTreeRB *v25; // rax
  _DWORD *v26; // rbx
  UFG::allocator::free_link *v27; // rax
  char *v28; // rax
  char *v29; // rax
  char *v30; // rax
  char *v31; // rax
  UFG::qBaseNodeRB *v32; // rdx
  char dest; // [rsp+30h] [rbp-178h] BYREF
  __int64 v34; // [rsp+31h] [rbp-177h]
  int v35; // [rsp+39h] [rbp-16Fh]
  __int16 v36; // [rsp+3Dh] [rbp-16Bh]
  char v37; // [rsp+3Fh] [rbp-169h]
  SimpleXML::XMLNode *v38; // [rsp+40h] [rbp-168h]
  UFG::allocator::free_link *v39; // [rsp+48h] [rbp-160h]
  __int64 v40; // [rsp+50h] [rbp-158h]
  char str[328]; // [rsp+60h] [rbp-148h] BYREF
  char v43; // [rsp+1B8h] [rbp+10h]
  char v44; // [rsp+1C0h] [rbp+18h]
  char *v45; // [rsp+1C8h] [rbp+20h]

  if ( pXmlDoc )
  {
    v40 = -2i64;
    v1 = pXmlDoc;
    Node = SimpleXML::XMLDocument::GetNode(pXmlDoc, "AudioUIMap", 0i64);
    ChildNode = SimpleXML::XMLDocument::GetChildNode(v1, "Screen", Node);
    v38 = ChildNode;
    if ( ChildNode )
    {
      while ( 1 )
      {
        Attribute = SimpleXML::XMLNode::GetAttribute(ChildNode, "Name", 0i64);
        v5 = UFG::qStringHashUpper32(Attribute, -1);
        v6 = v5;
        v44 = 0;
        if ( v5 && (v7 = UFG::qBaseTreeRB::Get(&UFG::AudioUISystem::smScreenList.mTree, v5)) != 0i64 )
          p_mCount = (UFG::allocator::free_link *)&v7[-1].mCount;
        else
          p_mCount = 0i64;
        if ( !p_mCount )
        {
          v9 = UFG::qMemoryPool::Allocate(&g_AudioMemoryPool, 0x78ui64, "AudioUIScreen", 0i64, 1u);
          p_mCount = v9;
          if ( v9 )
          {
            v9[1].mNext = 0i64;
            v9[2].mNext = 0i64;
            v9[3].mNext = 0i64;
            v9->mNext = (UFG::allocator::free_link *)&UFG::AudioUIScreen::`vftable;
            v9[5].mNext = (UFG::allocator::free_link *)-1i64;
            UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)&v9[6]);
          }
          else
          {
            p_mCount = 0i64;
          }
          LODWORD(p_mCount[4].mNext) = v6;
          v44 = 1;
        }
        v10 = SimpleXML::XMLNode::GetAttribute(ChildNode, "Event", 0i64);
        LODWORD(p_mCount[5].mNext) = UFG::TiDo::CalcWwiseUid(v10);
        v11 = SimpleXML::XMLNode::GetAttribute(ChildNode, "SwitchGroup", 0i64);
        HIDWORD(p_mCount[5].mNext) = UFG::TiDo::CalcWwiseUid(v11);
        v12 = SimpleXML::XMLDocument::GetChildNode(v1, "Input", ChildNode);
        if ( v12 )
          break;
LABEL_59:
        if ( v44 )
        {
          if ( SLODWORD(p_mCount[14].mNext) <= 0 )
            ((void (__fastcall *)(UFG::allocator::free_link *, __int64))p_mCount->mNext->mNext)(p_mCount, 1i64);
          else
            UFG::qBaseTreeRB::Add(&UFG::AudioUISystem::smScreenList.mTree, (UFG::qBaseNodeRB *)&p_mCount[1]);
        }
        ChildNode = SimpleXML::XMLDocument::GetNode(v1, "Screen", ChildNode);
        v38 = ChildNode;
        if ( !ChildNode )
          goto LABEL_64;
      }
LABEL_13:
      v13 = SimpleXML::XMLNode::GetAttribute(v12, "Type", 0i64);
      v45 = v13;
      v14 = 0;
      v15 = 0;
      v16 = 0;
      v43 = 0;
      v17 = 0;
      while ( 1 )
      {
        dest = 0;
        v34 = 0i64;
        v35 = 0;
        v36 = 0;
        v37 = 0;
        if ( v17 )
        {
          if ( v17 == 1 )
          {
            v20 = SimpleXML::XMLNode::GetAttribute(v12, "Repeat", 0i64);
            if ( v20 && !(unsigned int)UFG::qStringCompareInsensitive(v20, "On", -1) )
            {
              v15 = 1;
              v19 = "_REPEAT";
              goto LABEL_31;
            }
          }
          else if ( v17 == 2 )
          {
            v18 = SimpleXML::XMLNode::GetAttribute(v12, "Released", 0i64);
            if ( v18 && !(unsigned int)UFG::qStringCompareInsensitive(v18, "On", -1) )
            {
              v43 = 1;
              v19 = "_RELEASED";
LABEL_31:
              UFG::qStringCopy(&dest, 0x7FFFFFFF, v19, -1);
LABEL_32:
              memset(str, 0, 256);
              if ( (int)UFG::qStringLength(&dest) <= 0 )
                UFG::qSPrintf(str, "%s", v13);
              else
                UFG::qSPrintf(str, "%s%s", v13, &dest);
              v22 = UFG::qStringHashUpper32(str, -1);
              v23 = v22;
              v24 = 0;
              if ( !v22
                || (v25 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&p_mCount[6], v22)) == 0i64
                || (v26 = &v25[-1].mCount, v25 == (UFG::qBaseTreeRB *)8) )
              {
                v27 = UFG::qMemoryPool::Allocate(&g_AudioMemoryPool, 0x38ui64, "AudioUIInput", 0i64, 1u);
                v26 = v27;
                v39 = v27;
                if ( v27 )
                {
                  v27[1].mNext = 0i64;
                  v27[2].mNext = 0i64;
                  v27[3].mNext = 0i64;
                  v27->mNext = (UFG::allocator::free_link *)&UFG::AudioUIInput::`vftable;
                  v27[5].mNext = (UFG::allocator::free_link *)-1i64;
                  v27[6].mNext = (UFG::allocator::free_link *)-1i64;
                }
                else
                {
                  v26 = 0i64;
                }
                v26[8] = v23;
                v24 = 1;
              }
              v28 = SimpleXML::XMLNode::GetAttribute(v12, "SwitchType", 0i64);
              if ( v28 )
                v26[13] = UFG::TiDo::CalcWwiseUid(v28);
              v29 = SimpleXML::XMLNode::GetAttribute(v12, "Event", 0i64);
              if ( v29 )
                v26[10] = UFG::TiDo::CalcWwiseUid(v29);
              v30 = SimpleXML::XMLNode::GetAttribute(v12, "SwitchGroup", 0i64);
              if ( v30 )
                v26[12] = UFG::TiDo::CalcWwiseUid(v30);
              v31 = SimpleXML::XMLNode::GetAttribute(v12, "EndEvent", 0i64);
              if ( v31 )
                v26[11] = UFG::TiDo::CalcWwiseUid(v31);
              if ( v24 )
              {
                if ( v26 )
                  v32 = (UFG::qBaseNodeRB *)(v26 + 2);
                else
                  v32 = 0i64;
                UFG::qBaseTreeRB::Add((UFG::qBaseTreeRB *)&p_mCount[6], v32);
              }
              v13 = v45;
              v16 = v43;
            }
          }
          else if ( v17 == 3 && !v14 && !v16 && !v15 )
          {
            goto LABEL_32;
          }
        }
        else
        {
          v21 = SimpleXML::XMLNode::GetAttribute(v12, "Pressed", 0i64);
          if ( v21 && !(unsigned int)UFG::qStringCompareInsensitive(v21, "On", -1) )
          {
            v14 = 1;
            v19 = "_PRESSED";
            goto LABEL_31;
          }
        }
        if ( ++v17 >= 4 )
        {
          v1 = pXmlDoc;
          v12 = SimpleXML::XMLDocument::GetNode(pXmlDoc, "Input", v12);
          if ( !v12 )
          {
            ChildNode = v38;
            goto LABEL_59;
          }
          goto LABEL_13;
        }
      }
    }
LABEL_64:
    SimpleXML::XMLDocument::~XMLDocument(v1);
    operator delete[](v1);
  }
}

