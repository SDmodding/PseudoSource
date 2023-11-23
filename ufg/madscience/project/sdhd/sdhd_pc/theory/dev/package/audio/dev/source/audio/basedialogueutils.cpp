// File Line: 22
// RVA: 0x13FE60
void __fastcall UFG::ArgumentSequencerBase::ArgumentSequencerBase(UFG::ArgumentSequencerBase *this)
{
  UFG::qString v2; // [rsp+28h] [rbp-30h] BYREF

  this->vfptr = (UFG::ArgumentSequencerBaseVtbl *)&UFG::ArgumentSequencerBase::`vftable;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->m_argumentGroup.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->m_events.mTree);
  UFG::ArgumentSequencerBase::Populate(this);
  UFG::qString::qString(&v2, "Data\\Audio\\DialogueSequences.xml");
  UFG::ArgumentSequencerBase::PopulateSequences(this, v2.mData);
  UFG::qString::~qString(&v2);
}

// File Line: 33
// RVA: 0x140E90
void __fastcall UFG::ArgumentSequencerBase::~ArgumentSequencerBase(UFG::ArgumentSequencerBase *this)
{
  this->vfptr = (UFG::ArgumentSequencerBaseVtbl *)&UFG::ArgumentSequencerBase::`vftable;
  UFG::ArgumentSequencerBase::Destroy(this);
  UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll(&this->m_events);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->m_events);
  UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll((UFG::qTreeRB<UFG::DialogEvent,UFG::DialogEvent,1> *)&this->m_argumentGroup);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->m_argumentGroup);
}

// File Line: 42
// RVA: 0x144830
void __fastcall UFG::ArgumentSequencerBase::Destroy(UFG::ArgumentSequencerBase *this)
{
  Render::SkinningCacheNode *Head; // rax
  Illusion::Buffer **p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNode; // rdx
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *p_m_events; // rdi
  Render::SkinningCacheNode *v6; // rax
  Illusion::Buffer **v7; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v8; // rdx

  if ( this->m_argumentGroup.mTree.mCount )
  {
    while ( 1 )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->m_argumentGroup);
      if ( !Head )
        break;
      p_mCachedBufferPtr = &Head[-1].mCachedBufferPtr;
      if ( Head == (Render::SkinningCacheNode *)8 )
        goto LABEL_6;
      p_mNode = &Head->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->m_argumentGroup,
        p_mNode);
      if ( p_mCachedBufferPtr )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*p_mCachedBufferPtr)->mNode.mParent)(
          p_mCachedBufferPtr,
          1i64);
      if ( !this->m_argumentGroup.mTree.mCount )
        goto LABEL_10;
    }
    p_mCachedBufferPtr = 0i64;
LABEL_6:
    p_mNode = 0i64;
    goto LABEL_7;
  }
LABEL_10:
  p_m_events = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->m_events;
  if ( this->m_events.mTree.mCount )
  {
    while ( 1 )
    {
      v6 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(p_m_events);
      if ( !v6 )
        break;
      v7 = &v6[-1].mCachedBufferPtr;
      if ( v6 == (Render::SkinningCacheNode *)8 )
        goto LABEL_15;
      v8 = &v6->mNode;
LABEL_16:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&p_m_events->mTree, v8);
      if ( v7 )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*v7)->mNode.mParent)(v7, 1i64);
      if ( !this->m_events.mTree.mCount )
        return;
    }
    v7 = 0i64;
LABEL_15:
    v8 = 0i64;
    goto LABEL_16;
  }
}

// File Line: 51
// RVA: 0x14A4C0
void __fastcall UFG::ArgumentSequencerBase::Populate(UFG::ArgumentSequencerBase *this)
{
  SimpleXML::XMLDocument *v2; // rax
  SimpleXML::XMLDocument *v3; // rsi
  SimpleXML::XMLNode *ChildNode; // rax
  SimpleXML::XMLNode *i; // r15
  char *Name; // rax
  char *v7; // rax
  SimpleXML::XMLNode *v8; // r14
  char *Attribute; // rax
  unsigned int v10; // edi
  char *v11; // rax
  char *v12; // rbx
  UFG::qBaseNodeRB *v13; // rdx
  SimpleXML::XMLNode *Node; // rdi
  UFG::qBaseTreeRB *v15; // rbp
  char *v16; // rax
  unsigned int v17; // ebx
  UFG::qBaseNodeRB *v18; // rax
  UFG::qString v19; // [rsp+38h] [rbp-B0h] BYREF
  UFG::qString v20; // [rsp+60h] [rbp-88h] BYREF
  UFG::qString v21; // [rsp+88h] [rbp-60h] BYREF

  UFG::qString::qString(&v19, "Data\\Global\\Act\\AudioTag.xml");
  v2 = SimpleXML::XMLDocument::Open(v19.mData, 1ui64, 0i64);
  v3 = v2;
  if ( v2 )
  {
    ChildNode = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, 0i64);
    if ( ChildNode )
    {
      for ( i = SimpleXML::XMLDocument::GetChildNode(v3, 0i64, ChildNode);
            i;
            i = SimpleXML::XMLDocument::GetNode(v3, 0i64, i) )
      {
        Name = SimpleXML::XMLNode::GetName(i);
        if ( (unsigned int)UFG::qStringCompare(Name, "SwitchType", -1) )
        {
          v7 = SimpleXML::XMLNode::GetName(i);
          if ( (unsigned int)UFG::qStringCompare(v7, "StateType", -1) )
            continue;
        }
        if ( (int)SimpleXML::XMLNode::GetChildCount(i) > 0 )
        {
          v8 = SimpleXML::XMLDocument::GetChildNode(v3, 0i64, i);
          while ( v8 )
          {
            Attribute = SimpleXML::XMLNode::GetAttribute(v8, "name");
            UFG::qString::qString(&v21, Attribute);
            v10 = SimpleXML::XMLNode::GetAttribute(v8, "id", 0);
            if ( v10 )
            {
              v11 = UFG::qMalloc(0x70ui64, "ArgumentSequencerBase.DialogArgSet", 0i64);
              v12 = v11;
              if ( v11 )
              {
                *((_QWORD *)v11 + 1) = 0i64;
                *((_QWORD *)v11 + 2) = 0i64;
                *((_QWORD *)v11 + 3) = 0i64;
                *((_DWORD *)v11 + 8) = v10;
                *(_QWORD *)v11 = &UFG::DialogArgSet::`vftable;
                UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)(v11 + 40));
              }
              else
              {
                v12 = 0i64;
              }
              v13 = (UFG::qBaseNodeRB *)(v12 + 8);
              if ( !v12 )
                v13 = 0i64;
              UFG::qBaseTreeRB::Add(&this->m_argumentGroup.mTree, v13);
              Node = SimpleXML::XMLDocument::GetChildNode(v3, 0i64, v8);
              if ( Node )
              {
                v15 = (UFG::qBaseTreeRB *)(v12 + 40);
                do
                {
                  v16 = SimpleXML::XMLNode::GetAttribute(Node, "name");
                  UFG::qString::qString(&v20, v16);
                  v17 = SimpleXML::XMLNode::GetAttribute(Node, "id", 0);
                  v18 = (UFG::qBaseNodeRB *)UFG::qMemoryPool::Allocate(
                                              &g_AudioComponentPool,
                                              0x20ui64,
                                              "ArgumentSequencerBase.DialogArg",
                                              0i64,
                                              1u);
                  if ( v18 )
                  {
                    v18->mParent = 0i64;
                    v18->mChild[0] = 0i64;
                    v18->mChild[1] = 0i64;
                    v18->mUID = v17;
                  }
                  else
                  {
                    v18 = 0i64;
                  }
                  UFG::qBaseTreeRB::Add(v15, v18);
                  Node = SimpleXML::XMLDocument::GetNode(v3, 0i64, Node);
                  UFG::qString::~qString(&v20);
                }
                while ( Node );
              }
            }
            v8 = SimpleXML::XMLDocument::GetNode(v3, 0i64, v8);
            UFG::qString::~qString(&v21);
          }
        }
      }
    }
    SimpleXML::XMLDocument::~XMLDocument(v3);
    operator delete[](v3);
  }
  UFG::qString::~qString(&v19);
}

// File Line: 107
// RVA: 0x14A880
void __fastcall UFG::ArgumentSequencerBase::PopulateSequences(UFG::ArgumentSequencerBase *this, const char *filename)
{
  SimpleXML::XMLDocument *v3; // rax
  SimpleXML::XMLDocument *v4; // r14
  SimpleXML::XMLNode *ChildNode; // rax
  SimpleXML::XMLNode *i; // r15
  char *Name; // rax
  signed int ChildCount; // esi
  char *Attribute; // rbx
  int IDFromString; // edi
  char *v11; // rax
  UFG::DialogEvent *v12; // rbx
  UFG::qBaseNodeRB *p_mNode; // rdx
  SimpleXML::XMLNode *Node; // rsi
  int v15; // edi
  char *v16; // rax
  char *mData; // rbp
  unsigned int v18; // eax
  UFG::qString v19; // [rsp+28h] [rbp-50h] BYREF

  v3 = SimpleXML::XMLDocument::Open(filename, 1ui64, 0i64);
  v4 = v3;
  if ( v3 )
  {
    ChildNode = SimpleXML::XMLDocument::GetChildNode(v3, 0i64, 0i64);
    if ( ChildNode )
    {
      for ( i = SimpleXML::XMLDocument::GetChildNode(v4, 0i64, ChildNode);
            i;
            i = SimpleXML::XMLDocument::GetNode(v4, 0i64, i) )
      {
        Name = SimpleXML::XMLNode::GetName(i);
        if ( !(unsigned int)UFG::qStringCompare(Name, "DialogueEvent", -1) )
        {
          ChildCount = SimpleXML::XMLNode::GetChildCount(i);
          Attribute = SimpleXML::XMLNode::GetAttribute(i, "name", &customCaption);
          if ( (unsigned int)UFG::qStringLength(Attribute) )
            IDFromString = AK::SoundEngine::GetIDFromString(Attribute);
          else
            IDFromString = 0;
          v11 = UFG::qMalloc(0x38ui64, "ArgumentSequencerBase.DialogEvent", 0i64);
          v12 = (UFG::DialogEvent *)v11;
          if ( v11 )
          {
            *((_QWORD *)v11 + 1) = 0i64;
            *((_QWORD *)v11 + 2) = 0i64;
            *((_QWORD *)v11 + 3) = 0i64;
            *((_DWORD *)v11 + 8) = IDFromString;
            *(_QWORD *)v11 = &UFG::DialogEvent::`vftable;
            *((_QWORD *)v11 + 6) = 0i64;
            *((_QWORD *)v11 + 5) = 0i64;
          }
          else
          {
            v12 = 0i64;
          }
          p_mNode = &v12->mNode;
          if ( !v12 )
            p_mNode = 0i64;
          UFG::qBaseTreeRB::Add(&this->m_events.mTree, p_mNode);
          if ( ChildCount > 0 )
          {
            UFG::DialogEvent::Resize(v12, ChildCount);
            Node = SimpleXML::XMLDocument::GetChildNode(v4, 0i64, i);
            v15 = 0;
            while ( Node )
            {
              v16 = SimpleXML::XMLNode::GetAttribute(Node, "name");
              UFG::qString::qString(&v19, v16);
              mData = v19.mData;
              if ( (unsigned int)UFG::qStringLength(v19.mData) )
              {
                v18 = AK::SoundEngine::GetIDFromString(mData);
                if ( v18 )
                  v12->m_args.p[v15++] = v18;
              }
              Node = SimpleXML::XMLDocument::GetNode(v4, 0i64, Node);
              UFG::qString::~qString(&v19);
            }
          }
        }
      }
    }
    SimpleXML::XMLDocument::~XMLDocument(v4);
    operator delete[](v4);
  }
}

// File Line: 194
// RVA: 0x1453A0
char __fastcall UFG::ArgumentSequencerBase::EventRequiresArgument(
        UFG::ArgumentSequencerBase *this,
        unsigned int eventId,
        unsigned int argId)
{
  UFG::qBaseTreeRB *v4; // rax
  int *p_mCount; // rax
  unsigned int v6; // edx
  int v7; // ecx
  _DWORD *i; // rax

  if ( eventId )
  {
    v4 = UFG::qBaseTreeRB::Get(&this->m_events.mTree, eventId);
    if ( v4 )
    {
      p_mCount = &v4[-1].mCount;
      if ( p_mCount )
      {
        v6 = p_mCount[10];
        v7 = 0;
        if ( !v6 )
          return 0;
        for ( i = (_DWORD *)*((_QWORD *)p_mCount + 6); *i != argId; ++i )
        {
          if ( ++v7 >= v6 )
            return 0;
        }
      }
    }
  }
  return 1;
}

