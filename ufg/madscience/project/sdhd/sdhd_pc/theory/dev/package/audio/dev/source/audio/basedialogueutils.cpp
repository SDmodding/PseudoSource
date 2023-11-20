// File Line: 22
// RVA: 0x13FE60
void __fastcall UFG::ArgumentSequencerBase::ArgumentSequencerBase(UFG::ArgumentSequencerBase *this)
{
  UFG::ArgumentSequencerBase *v1; // rbx
  UFG::qString v2; // [rsp+28h] [rbp-30h]

  v1 = this;
  this->vfptr = (UFG::ArgumentSequencerBaseVtbl *)&UFG::ArgumentSequencerBase::`vftable;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->m_argumentGroup.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->m_events.mTree);
  UFG::ArgumentSequencerBase::Populate(v1);
  UFG::qString::qString(&v2, "Data\\Audio\\DialogueSequences.xml");
  UFG::ArgumentSequencerBase::PopulateSequences(v1, v2.mData);
  UFG::qString::~qString(&v2);
}

// File Line: 33
// RVA: 0x140E90
void __fastcall UFG::ArgumentSequencerBase::~ArgumentSequencerBase(UFG::ArgumentSequencerBase *this)
{
  UFG::ArgumentSequencerBase *v1; // rdi

  v1 = this;
  this->vfptr = (UFG::ArgumentSequencerBaseVtbl *)&UFG::ArgumentSequencerBase::`vftable;
  UFG::ArgumentSequencerBase::Destroy(this);
  UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll(&v1->m_events);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->m_events);
  UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll((UFG::qTreeRB<UFG::DialogEvent,UFG::DialogEvent,1> *)&v1->m_argumentGroup);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->m_argumentGroup);
}

// File Line: 42
// RVA: 0x144830
void __fastcall UFG::ArgumentSequencerBase::Destroy(UFG::ArgumentSequencerBase *this)
{
  UFG::ArgumentSequencerBase *v1; // rsi
  Render::SkinningCacheNode *v2; // rax
  Illusion::Buffer **v3; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rdx
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *v5; // rdi
  Render::SkinningCacheNode *v6; // rax
  Illusion::Buffer **v7; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v8; // rdx

  v1 = this;
  if ( this->m_argumentGroup.mTree.mCount )
  {
    while ( 1 )
    {
      v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->m_argumentGroup);
      if ( !v2 )
        break;
      v3 = &v2[-1].mCachedBufferPtr;
      if ( v2 == (Render::SkinningCacheNode *)8 )
        goto LABEL_6;
      v4 = &v2->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->m_argumentGroup,
        v4);
      if ( v3 )
        ((void (__fastcall *)(Illusion::Buffer **, signed __int64))(*v3)->mNode.mParent)(v3, 1i64);
      if ( !v1->m_argumentGroup.mTree.mCount )
        goto LABEL_10;
    }
    v3 = 0i64;
LABEL_6:
    v4 = 0i64;
    goto LABEL_7;
  }
LABEL_10:
  v5 = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->m_events;
  if ( v1->m_events.mTree.mCount )
  {
    while ( 1 )
    {
      v6 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(v5);
      if ( !v6 )
        break;
      v7 = &v6[-1].mCachedBufferPtr;
      if ( v6 == (Render::SkinningCacheNode *)8 )
        goto LABEL_15;
      v8 = &v6->mNode;
LABEL_16:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v5->mTree, v8);
      if ( v7 )
        ((void (__fastcall *)(Illusion::Buffer **, signed __int64))(*v7)->mNode.mParent)(v7, 1i64);
      if ( !v1->m_events.mTree.mCount )
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
  UFG::ArgumentSequencerBase *v1; // r13
  SimpleXML::XMLDocument *v2; // rax
  SimpleXML::XMLDocument *v3; // rsi
  SimpleXML::XMLNode *v4; // rax
  SimpleXML::XMLNode *i; // r15
  char *v6; // rax
  char *v7; // rax
  SimpleXML::XMLNode *v8; // r14
  char *v9; // rax
  unsigned int v10; // edi
  char *v11; // rax
  char *v12; // rbx
  UFG::qBaseNodeRB *v13; // rdx
  SimpleXML::XMLNode *v14; // rdi
  UFG::qBaseTreeRB *v15; // rbp
  char *v16; // rax
  unsigned int v17; // ebx
  UFG::qBaseNodeRB *v18; // rax
  UFG::qString v19; // [rsp+38h] [rbp-B0h]
  UFG::qString v20; // [rsp+60h] [rbp-88h]
  UFG::qString v21; // [rsp+88h] [rbp-60h]

  v1 = this;
  UFG::qString::qString(&v19, "Data\\Global\\Act\\AudioTag.xml");
  v2 = SimpleXML::XMLDocument::Open(v19.mData, 1ui64, 0i64);
  v3 = v2;
  if ( v2 )
  {
    v4 = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, 0i64);
    if ( v4 )
    {
      for ( i = SimpleXML::XMLDocument::GetChildNode(v3, 0i64, v4); i; i = SimpleXML::XMLDocument::GetNode(v3, 0i64, i) )
      {
        v6 = SimpleXML::XMLNode::GetName(i);
        if ( (unsigned int)UFG::qStringCompare(v6, "SwitchType", -1) )
        {
          v7 = SimpleXML::XMLNode::GetName(i);
          if ( (unsigned int)UFG::qStringCompare(v7, "StateType", -1) )
            continue;
        }
        if ( (signed int)SimpleXML::XMLNode::GetChildCount(i) > 0 )
        {
          v8 = SimpleXML::XMLDocument::GetChildNode(v3, 0i64, i);
          while ( v8 )
          {
            v9 = SimpleXML::XMLNode::GetAttribute(v8, "name");
            UFG::qString::qString(&v21, v9);
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
              UFG::qBaseTreeRB::Add(&v1->m_argumentGroup.mTree, v13);
              v14 = SimpleXML::XMLDocument::GetChildNode(v3, 0i64, v8);
              if ( v14 )
              {
                v15 = (UFG::qBaseTreeRB *)(v12 + 40);
                do
                {
                  v16 = SimpleXML::XMLNode::GetAttribute(v14, "name");
                  UFG::qString::qString(&v20, v16);
                  v17 = SimpleXML::XMLNode::GetAttribute(v14, "id", 0);
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
                  v14 = SimpleXML::XMLDocument::GetNode(v3, 0i64, v14);
                  UFG::qString::~qString(&v20);
                }
                while ( v14 );
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
  UFG::ArgumentSequencerBase *v2; // r13
  SimpleXML::XMLDocument *v3; // rax
  SimpleXML::XMLDocument *v4; // r14
  SimpleXML::XMLNode *v5; // rax
  SimpleXML::XMLNode *i; // r15
  char *v7; // rax
  signed int v8; // esi
  char *v9; // rbx
  int v10; // edi
  char *v11; // rax
  UFG::DialogEvent *v12; // rbx
  UFG::qBaseNodeRB *v13; // rdx
  SimpleXML::XMLNode *v14; // rsi
  int v15; // edi
  char *v16; // rax
  char *v17; // rbp
  unsigned int v18; // eax
  UFG::qString v19; // [rsp+28h] [rbp-50h]

  v2 = this;
  v3 = SimpleXML::XMLDocument::Open(filename, 1ui64, 0i64);
  v4 = v3;
  if ( v3 )
  {
    v5 = SimpleXML::XMLDocument::GetChildNode(v3, 0i64, 0i64);
    if ( v5 )
    {
      for ( i = SimpleXML::XMLDocument::GetChildNode(v4, 0i64, v5); i; i = SimpleXML::XMLDocument::GetNode(v4, 0i64, i) )
      {
        v7 = SimpleXML::XMLNode::GetName(i);
        if ( !(unsigned int)UFG::qStringCompare(v7, "DialogueEvent", -1) )
        {
          v8 = SimpleXML::XMLNode::GetChildCount(i);
          v9 = SimpleXML::XMLNode::GetAttribute(i, "name", &customWorldMapCaption);
          if ( (unsigned int)UFG::qStringLength(v9) )
            v10 = AK::SoundEngine::GetIDFromString(v9);
          else
            v10 = 0;
          v11 = UFG::qMalloc(0x38ui64, "ArgumentSequencerBase.DialogEvent", 0i64);
          v12 = (UFG::DialogEvent *)v11;
          if ( v11 )
          {
            *((_QWORD *)v11 + 1) = 0i64;
            *((_QWORD *)v11 + 2) = 0i64;
            *((_QWORD *)v11 + 3) = 0i64;
            *((_DWORD *)v11 + 8) = v10;
            *(_QWORD *)v11 = &UFG::DialogEvent::`vftable;
            *((_QWORD *)v11 + 6) = 0i64;
            *((_QWORD *)v11 + 5) = 0i64;
          }
          else
          {
            v12 = 0i64;
          }
          v13 = &v12->mNode;
          if ( !v12 )
            v13 = 0i64;
          UFG::qBaseTreeRB::Add(&v2->m_events.mTree, v13);
          if ( v8 > 0 )
          {
            UFG::DialogEvent::Resize(v12, v8);
            v14 = SimpleXML::XMLDocument::GetChildNode(v4, 0i64, i);
            v15 = 0;
            while ( v14 )
            {
              v16 = SimpleXML::XMLNode::GetAttribute(v14, "name");
              UFG::qString::qString(&v19, v16);
              v17 = v19.mData;
              if ( (unsigned int)UFG::qStringLength(v19.mData) )
              {
                v18 = AK::SoundEngine::GetIDFromString(v17);
                if ( v18 )
                  v12->m_args.p[v15++] = v18;
              }
              v14 = SimpleXML::XMLDocument::GetNode(v4, 0i64, v14);
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
char __fastcall UFG::ArgumentSequencerBase::EventRequiresArgument(UFG::ArgumentSequencerBase *this, unsigned int eventId, unsigned int argId)
{
  unsigned int v3; // ebx
  UFG::qBaseTreeRB *v4; // rax
  signed __int64 v5; // rax
  unsigned int v6; // edx
  unsigned int v7; // ecx
  _DWORD *v8; // rax

  v3 = argId;
  if ( eventId )
  {
    v4 = UFG::qBaseTreeRB::Get(&this->m_events.mTree, eventId);
    if ( v4 )
    {
      v5 = (signed __int64)&v4[-1].mCount;
      if ( v5 )
      {
        v6 = *(_DWORD *)(v5 + 40);
        v7 = 0;
        if ( !v6 )
          return 0;
        v8 = *(_DWORD **)(v5 + 48);
        while ( *v8 != v3 )
        {
          ++v7;
          ++v8;
          if ( v7 >= v6 )
            return 0;
        }
      }
    }
  }
  return 1;
}

