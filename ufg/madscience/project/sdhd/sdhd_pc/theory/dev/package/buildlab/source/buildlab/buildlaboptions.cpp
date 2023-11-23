// File Line: 71
// RVA: 0x14F040
void __fastcall UFG::CsvDocument::~CsvDocument(UFG::CsvDocument *this)
{
  Render::Skinning *p_mValues; // rdi
  UFG::qBaseTreeRB *i; // rbx
  UFG::qBaseNodeRB *mParent; // rsi
  Render::SkinningCacheNode *Head; // rbx

  p_mValues = (Render::Skinning *)&this->mValues;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mValues);
        i;
        i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)p_mValues, &i->mRoot) )
  {
    mParent = i->mNULL.mParent;
    if ( mParent )
    {
      UFG::qString::~qString((UFG::qString *)i->mNULL.mParent);
      operator delete[](mParent);
    }
    i->mNULL.mParent = 0i64;
  }
  while ( p_mValues->mSkinnedVertexBuffers.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&p_mValues->mSkinnedVertexBuffers);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&p_mValues->mSkinnedVertexBuffers.mTree, &Head->mNode);
    operator delete[](Head);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB(p_mValues);
  UFG::qString::~qString(&this->mFilename);
}

// File Line: 92
// RVA: 0x14FE00
// bad sp value at call has been detected, the output may be wrong!
UFG::qString *__fastcall UFG::CsvDocument::Load(
        UFG::CsvDocument *this,
        UFG::qString *result,
        const char *filename,
        const char *key)
{
  unsigned int v8; // r14d
  Render::SkinningCacheNode *Head; // rbx
  char *v10; // rbx
  __int64 v11; // rcx
  __int64 v12; // r8
  UFG::qString *v13; // rax
  unsigned int v14; // r12d
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString *v16; // rdi
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rax
  int v19; // esi
  UFG::qBaseNodeRB *v20; // rbx
  unsigned int mNumCols; // ecx
  unsigned int mNumRows; // ecx
  UFG::qString *k; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v24; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v25; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v27; // rax
  UFG::qString *m; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v29; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v30; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v31; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v32; // rax
  UFG::qString *n; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v34; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v35; // rax
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v37; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v38; // rax
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v41; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v42; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v43; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> list; // [rsp+0h] [rbp-71h] BYREF
  UFG::qList<UFG::qString,UFG::qString,1,0> v46; // [rsp+10h] [rbp-61h] BYREF
  int v47; // [rsp+20h] [rbp-51h]
  UFG::qString v48; // [rsp+28h] [rbp-49h] BYREF
  UFG::qBaseNodeRB *v49; // [rsp+50h] [rbp-21h]
  __int64 v50; // [rsp+58h] [rbp-19h]
  UFG::qString resulta; // [rsp+60h] [rbp-11h] BYREF
  __int64 loaded_size; // [rsp+D0h] [rbp+5Fh] BYREF
  UFG::qString *v53; // [rsp+D8h] [rbp+67h]
  const char *v54; // [rsp+E0h] [rbp+6Fh]
  void *ptr; // [rsp+F0h] [rbp+7Fh]

  v50 = -2i64;
  v8 = 0;
  UFG::qString::Set(&this->mFilename, 0i64);
  *(_QWORD *)&this->mNumRows = 0i64;
  if ( this->mValues.mTree.mTree.mCount )
  {
    do
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mValues);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mValues,
        &Head->mNode);
      operator delete[](Head);
    }
    while ( this->mValues.mTree.mTree.mCount );
    filename = v54;
  }
  if ( UFG::qFileExists(filename) )
  {
    UFG::qString::qString(&v48);
    if ( key )
    {
      loaded_size = 0i64;
      v10 = UFG::qReadEntireFile(filename, &loaded_size, 0i64, 0i64, 0i64);
      if ( v10 )
      {
        v11 = 0i64;
        if ( loaded_size > 0 )
        {
          v12 = (unsigned int)ptr;
          do
          {
            v10[v11] ^= key[v11 % v12];
            ++v11;
          }
          while ( v11 < loaded_size );
        }
        UFG::qString::Set(&v48, v10);
        UFG::qFreeEntireFile(v10, 0i64);
      }
      filename = v54;
    }
    else
    {
      v13 = UFG::qReadString(&resulta, filename);
      UFG::qString::Set(&v48, v13->mData, v13->mLength, 0i64, 0);
      UFG::qString::~qString(&resulta);
    }
    if ( v48.mLength )
    {
      list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
      v14 = 0;
      UFG::qString::Tokenize(&v48, &list, "\n", "CsvDocument");
      mNext = list.mNode.mNext;
      loaded_size = (__int64)list.mNode.mNext;
      if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext == &list )
      {
LABEL_47:
        UFG::qString::qString(result);
        v47 = 1;
        for ( i = (UFG::qString *)list.mNode.mNext;
              (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list;
              i = (UFG::qString *)list.mNode.mNext )
        {
          mPrev = i->mPrev;
          v41 = i->mNext;
          mPrev->mNext = v41;
          v41->mPrev = mPrev;
          i->mPrev = i;
          i->mNext = i;
          UFG::qString::~qString(i);
          operator delete[](i);
        }
      }
      else
      {
        while ( 1 )
        {
          if ( v14 >= 0x10000 )
          {
            result = v53;
            UFG::qString::FormatEx(v53, "ERROR: CSV has more than 65536 rows!  filename=%s", v54);
            v47 = 1;
            for ( j = (UFG::qString *)list.mNode.mNext;
                  (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list;
                  j = (UFG::qString *)list.mNode.mNext )
            {
              v37 = j->mPrev;
              v38 = j->mNext;
              v37->mNext = v38;
              v38->mPrev = v37;
              j->mPrev = j;
              j->mNext = j;
              UFG::qString::~qString(j);
              operator delete[](j);
            }
            goto LABEL_49;
          }
          v46.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v46;
          v46.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v46;
          UFG::qTokenize(&v46, ",", (const char *)mNext[1].mNext, HIDWORD(mNext[1].mPrev), "CsvDocument", 1);
          v16 = (UFG::qString *)v46.mNode.mNext;
          if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)v46.mNode.mNext != &v46 )
            break;
LABEL_32:
          mNumRows = ++v14;
          if ( this->mNumRows > v14 )
            mNumRows = this->mNumRows;
          this->mNumRows = mNumRows;
          for ( k = (UFG::qString *)v46.mNode.mNext;
                (UFG::qList<UFG::qString,UFG::qString,1,0> *)v46.mNode.mNext != &v46;
                k = (UFG::qString *)v46.mNode.mNext )
          {
            v24 = k->mPrev;
            v25 = k->mNext;
            v24->mNext = v25;
            v25->mPrev = v24;
            k->mPrev = k;
            k->mNext = k;
            UFG::qString::~qString(k);
            operator delete[](k);
          }
          v26 = v46.mNode.mPrev;
          v27 = v46.mNode.mNext;
          v46.mNode.mPrev->mNext = v46.mNode.mNext;
          v27->mPrev = v26;
          v46.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v46;
          v46.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v46;
          mNext = *(UFG::qNode<UFG::qString,UFG::qString> **)(loaded_size + 8);
          loaded_size = (__int64)mNext;
          if ( mNext == (UFG::qNode<UFG::qString,UFG::qString> *)&list )
          {
            result = v53;
            goto LABEL_47;
          }
          v8 = 0;
        }
        while ( 1 )
        {
          v17 = v16->mPrev;
          v18 = v16->mNext;
          v17->mNext = v18;
          v18->mPrev = v17;
          v16->mPrev = v16;
          v16->mNext = v16;
          if ( v8 >= 0x10000 )
            break;
          if ( v16->mLength )
          {
            v19 = v14 | (v8 << 16);
            if ( !v19 || (v20 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::Get(&this->mValues.mTree.mTree, v19)) == 0i64 )
            {
              v20 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
              v49 = v20;
              if ( v20 )
              {
                v20->mParent = 0i64;
                v20->mChild[0] = 0i64;
                v20->mChild[1] = 0i64;
                v20->mUID = v19;
                v20[1].mParent = (UFG::qBaseNodeRB *)v16;
              }
              else
              {
                v20 = 0i64;
              }
              UFG::qBaseTreeRB::Add(&this->mValues.mTree.mTree, v20);
            }
            v20[1].mParent = (UFG::qBaseNodeRB *)v16;
          }
          else
          {
            UFG::qString::~qString(v16);
            operator delete[](v16);
          }
          mNumCols = ++v8;
          if ( this->mNumCols > v8 )
            mNumCols = this->mNumCols;
          this->mNumCols = mNumCols;
          v16 = (UFG::qString *)v46.mNode.mNext;
          if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)v46.mNode.mNext == &v46 )
            goto LABEL_32;
        }
        result = v53;
        UFG::qString::FormatEx(v53, "ERROR: CSV has more than 65536 columns!  filename=%s", v54);
        v47 = 1;
        for ( m = (UFG::qString *)v46.mNode.mNext;
              (UFG::qList<UFG::qString,UFG::qString,1,0> *)v46.mNode.mNext != &v46;
              m = (UFG::qString *)v46.mNode.mNext )
        {
          v29 = m->mPrev;
          v30 = m->mNext;
          v29->mNext = v30;
          v30->mPrev = v29;
          m->mPrev = m;
          m->mNext = m;
          UFG::qString::~qString(m);
          operator delete[](m);
        }
        v31 = v46.mNode.mPrev;
        v32 = v46.mNode.mNext;
        v46.mNode.mPrev->mNext = v46.mNode.mNext;
        v32->mPrev = v31;
        v46.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v46;
        v46.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v46;
        for ( n = (UFG::qString *)list.mNode.mNext;
              (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list;
              n = (UFG::qString *)list.mNode.mNext )
        {
          v34 = n->mPrev;
          v35 = n->mNext;
          v34->mNext = v35;
          v35->mPrev = v34;
          n->mPrev = n;
          n->mNext = n;
          UFG::qString::~qString(n);
          operator delete[](n);
        }
      }
LABEL_49:
      v42 = list.mNode.mPrev;
      v43 = list.mNode.mNext;
      list.mNode.mPrev->mNext = list.mNode.mNext;
      v43->mPrev = v42;
      list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
      list.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
    }
    else
    {
      UFG::qString::FormatEx(result, "ERROR: File couldnt be loaded!  filename=%s", filename);
      v47 = 1;
    }
    UFG::qString::~qString(&v48);
  }
  else
  {
    UFG::qString::FormatEx(result, "ERROR: File not found!  filename=%s", filename);
    v47 = 1;
  }
  return result;
}

// File Line: 200
// RVA: 0x14E9A0
void __fastcall UFG::BuildLabOption::BuildLabOption(
        UFG::BuildLabOption *this,
        const char *name,
        const char *value,
        bool is_hidden)
{
  unsigned int v8; // eax

  v8 = UFG::qStringHashUpper32(name, 0xFFFFFFFF);
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v8;
  this->mPrev = &this->UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption>;
  this->mNext = &this->UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption>;
  UFG::qString::qString(&this->mName);
  UFG::qString::qString(&this->mValue);
  UFG::qString::Set(&this->mName, name);
  UFG::qString::Set(&this->mValue, value);
  this->mIsHidden = is_hidden;
}

// File Line: 221
// RVA: 0x14EA50
void __fastcall UFG::BuildLabOptionGroup::BuildLabOptionGroup(UFG::BuildLabOptionGroup *this, const char *name)
{
  unsigned int v4; // eax

  v4 = UFG::qStringHashUpper32(name, 0xFFFFFFFF);
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v4;
  UFG::qString::qString(&this->mName);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mOptionTree.mTree);
  this->mOptionList.mNode.mPrev = &this->mOptionList.mNode;
  this->mOptionList.mNode.mNext = &this->mOptionList.mNode;
  UFG::qString::Set(&this->mName, name);
}

// File Line: 231
// RVA: 0x150E40
void __fastcall UFG::BuildLabOptionGroup::SetOption(
        UFG::BuildLabOptionGroup *this,
        char *name,
        const char *value,
        bool is_hidden)
{
  int v8; // ebp
  int v9; // esi
  char *v10; // rbx
  char *v11; // rdi
  unsigned int mStringHashUpper32; // eax
  UFG::qTreeRB<UFG::BuildLabOption,UFG::BuildLabOption,0> *p_mOptionTree; // rbp
  UFG::qBaseTreeRB *v14; // rbx
  char *v15; // rax
  UFG::qBaseTreeRB *v16; // rax
  UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> *mPrev; // rax
  unsigned int v18; // eax
  char *v19; // rsi
  int v20; // eax
  UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> *v21; // rax
  UFG::qString result; // [rsp+20h] [rbp-458h] BYREF
  __int64 v23; // [rsp+48h] [rbp-430h]
  char text; // [rsp+50h] [rbp-428h] BYREF
  char v25; // [rsp+51h] [rbp-427h] BYREF

  v23 = -2i64;
  UFG::qTrim(&result, name, -1);
  v8 = 0;
  text = 0;
  v9 = 0;
  if ( *name )
  {
    v10 = name;
    v11 = &v25;
    while ( *v10 != 46 )
    {
      if ( !UFG::qIsWhitespace(*v10) )
      {
        *(_WORD *)(v11 - 1) = (unsigned __int8)*v10;
        ++v8;
        ++v11;
      }
      ++v9;
      if ( !*++v10 )
        goto LABEL_9;
    }
    UFG::qStringCopy(&text + v8, 0x7FFFFFFF, &name[v9], -1);
    UFG::qStringLength(&text);
  }
LABEL_9:
  mStringHashUpper32 = result.mStringHashUpper32;
  if ( result.mStringHashUpper32 == -1 )
  {
    mStringHashUpper32 = UFG::qStringHashUpper32(result.mData, 0xFFFFFFFF);
    result.mStringHashUpper32 = mStringHashUpper32;
  }
  if ( !mStringHashUpper32
    || (p_mOptionTree = &this->mOptionTree,
        (v14 = UFG::qBaseTreeRB::Get(&this->mOptionTree.mTree, mStringHashUpper32)) == 0i64) )
  {
    v15 = UFG::qMalloc(0x88ui64, "BuildLabOption", 0i64);
    if ( v15 )
    {
      UFG::BuildLabOption::BuildLabOption((UFG::BuildLabOption *)v15, result.mData, value, is_hidden);
      v14 = v16;
    }
    else
    {
      v14 = 0i64;
    }
    p_mOptionTree = &this->mOptionTree;
    UFG::qBaseTreeRB::Add(&this->mOptionTree.mTree, &v14->mRoot);
    mPrev = this->mOptionList.mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> *)&v14->mNULL;
    v14->mNULL.mParent = (UFG::qBaseNodeRB *)mPrev;
    v14->mNULL.mChild[0] = (UFG::qBaseNodeRB *)&this->mOptionList;
    this->mOptionList.mNode.mPrev = (UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> *)&v14->mNULL;
  }
  UFG::qString::Set((UFG::qString *)&v14[1].mRoot.mChild[1], value);
  LOBYTE(v14[1].mNULL.mUID) = is_hidden;
  if ( UFG::qStringCompareInsensitive(&text, result.mData, -1) )
  {
    v18 = UFG::qStringHashUpper32(&text, 0xFFFFFFFF);
    if ( !v18 || (v19 = (char *)UFG::qBaseTreeRB::Get(&p_mOptionTree->mTree, v18)) == 0i64 )
    {
      v19 = UFG::qMalloc(0x88ui64, "BuildLabOption", 0i64);
      if ( v19 )
      {
        v20 = UFG::qStringHashUpper32(&text, 0xFFFFFFFF);
        *(_QWORD *)v19 = 0i64;
        *((_QWORD *)v19 + 1) = 0i64;
        *((_QWORD *)v19 + 2) = 0i64;
        *((_DWORD *)v19 + 6) = v20;
        *((_QWORD *)v19 + 4) = v19 + 32;
        *((_QWORD *)v19 + 5) = v19 + 32;
        UFG::qString::qString((UFG::qString *)(v19 + 48));
        UFG::qString::qString((UFG::qString *)(v19 + 88));
        UFG::qString::Set((UFG::qString *)(v19 + 48), &text);
        UFG::qString::Set((UFG::qString *)(v19 + 88), value);
        v19[128] = is_hidden;
      }
      else
      {
        v19 = 0i64;
      }
      UFG::qBaseTreeRB::Add(&p_mOptionTree->mTree, (UFG::qBaseNodeRB *)v19);
      v21 = this->mOptionList.mNode.mPrev;
      v21->mNext = (UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> *)(v19 + 32);
      *((_QWORD *)v19 + 4) = v21;
      *((_QWORD *)v19 + 5) = &this->mOptionList;
      this->mOptionList.mNode.mPrev = (UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> *)(v19 + 32);
    }
    UFG::qString::Set((UFG::qString *)(v19 + 88), value);
    v19[128] = is_hidden;
  }
  UFG::qString::~qString(&result);
}

// File Line: 343
// RVA: 0x14EE80
void __fastcall UFG::BuildLabDefaults::~BuildLabDefaults(UFG::BuildLabDefaults *this)
{
  UFG::BuildLabOptionGroup *mProjectDefault; // rdi

  mProjectDefault = this->mProjectDefault;
  if ( mProjectDefault )
  {
    UFG::BuildLabOptionGroup::~BuildLabOptionGroup(this->mProjectDefault);
    operator delete[](mProjectDefault);
  }
  this->mProjectDefault = 0i64;
  UFG::qTreeRB<UFG::BuildLabOptionGroup,UFG::BuildLabOptionGroup,1>::DeleteAll(&this->mUserRoles);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)this);
}

// File Line: 358
// RVA: 0x14F300
UFG::qBaseTreeRB *__fastcall UFG::BuildLabDefaults::Get(
        UFG::BuildLabDefaults *this,
        const char *user_role_name,
        const char *option_name)
{
  unsigned int v5; // edi
  unsigned int v6; // eax
  UFG::qBaseTreeRB *v7; // rax
  UFG::qBaseTreeRB *result; // rax

  v5 = UFG::qStringHashUpper32(option_name, 0xFFFFFFFF);
  v6 = UFG::qStringHashUpper32(user_role_name, 0xFFFFFFFF);
  if ( !v6
    || (v7 = UFG::qBaseTreeRB::Get(&this->mUserRoles.mTree, v6)) == 0i64
    || !v5
    || (result = UFG::qBaseTreeRB::Get(v7 + 1, v5)) == 0i64 )
  {
    if ( v5 )
      return UFG::qBaseTreeRB::Get(&this->mProjectDefault->mOptionTree.mTree, v5);
    else
      return 0i64;
  }
  return result;
}

// File Line: 400
// RVA: 0x150350
void __fastcall UFG::BuildLabDefaults::LoadProject(
        UFG::BuildLabDefaults *this,
        const char *filename,
        const char *key,
        unsigned int keyLength)
{
  UFG::BuildLabOptionGroup *mProjectDefault; // r13
  char *v9; // rsi
  __int64 v10; // rcx
  int i; // edx
  SimpleXML::XMLDocument *v12; // rax
  SimpleXML::XMLDocument *v13; // r15
  SimpleXML::XMLNode *Node; // rax
  SimpleXML::XMLNode *ChildNode; // rdi
  char *Name; // rax
  SimpleXML::XMLNode *v17; // rbx
  char *v18; // rax
  SimpleXML::XMLNode *v19; // rax
  SimpleXML::XMLNode *v20; // r15
  char *v21; // rax
  char *Attribute; // rbx
  char *v23; // rsi
  char *v24; // r12
  char *v25; // r14
  char *v26; // rdi
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rbx
  UFG::qString *String; // rax
  const char *v29; // r8
  UFG::qString *m; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v32; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v33; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v34; // rax
  UFG::qString *n; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v36; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v37; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v38; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v39; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> list; // [rsp+8h] [rbp-59h] BYREF
  UFG::qList<UFG::qString,UFG::qString,1,0> v41; // [rsp+18h] [rbp-49h] BYREF
  bool add_empty_strings[8]; // [rsp+28h] [rbp-39h]
  __int64 loaded_size; // [rsp+30h] [rbp-31h] BYREF
  SimpleXML::XMLNode *j; // [rsp+38h] [rbp-29h]
  void *ptr; // [rsp+40h] [rbp-21h]
  SimpleXML::XMLNode *k; // [rsp+48h] [rbp-19h]
  SimpleXML::XMLNode *v47; // [rsp+50h] [rbp-11h]
  SimpleXML::XMLNode *prev_node; // [rsp+58h] [rbp-9h]
  __int64 v49; // [rsp+60h] [rbp-1h]
  UFG::qString result; // [rsp+68h] [rbp+7h] BYREF

  v49 = -2i64;
  if ( UFG::qFileExists(filename) )
  {
    mProjectDefault = this->mProjectDefault;
    ptr = 0i64;
    if ( key )
    {
      loaded_size = 0i64;
      v9 = UFG::qReadEntireFile(filename, &loaded_size, 0i64, 0i64, 0i64);
      ptr = v9;
      if ( !v9 )
        return;
      v10 = 0i64;
      for ( i = loaded_size; v10 < loaded_size; i = loaded_size )
      {
        v9[v10] ^= key[v10 % keyLength];
        ++v10;
      }
      v12 = (SimpleXML::XMLDocument *)SimpleXML::XMLDocument::OpenBuffer(v9, i);
    }
    else
    {
      v12 = SimpleXML::XMLDocument::Open(filename, 1ui64, 0i64);
    }
    v13 = v12;
    *(_QWORD *)add_empty_strings = v12;
    if ( v12 )
    {
      Node = SimpleXML::XMLDocument::GetNode(v12, "BuildLab", 0i64);
      if ( Node )
      {
        ChildNode = SimpleXML::XMLDocument::GetChildNode(v13, 0i64, Node);
        for ( j = ChildNode; ChildNode; j = ChildNode )
        {
          Name = SimpleXML::XMLNode::GetName(ChildNode);
          if ( !UFG::qStringCompareInsensitive(Name, "Pipeline", -1) )
          {
            v17 = SimpleXML::XMLDocument::GetChildNode(v13, 0i64, ChildNode);
            v47 = v17;
            if ( v17 )
            {
              do
              {
                v18 = SimpleXML::XMLNode::GetName(v17);
                if ( !UFG::qStringCompareInsensitive(v18, "Tabs", -1) )
                {
                  v19 = SimpleXML::XMLDocument::GetChildNode(v13, 0i64, v17);
                  prev_node = v19;
                  if ( v19 )
                  {
                    do
                    {
                      v20 = SimpleXML::XMLDocument::GetChildNode(v13, 0i64, v19);
                      for ( k = v20; v20; k = v20 )
                      {
                        v21 = SimpleXML::XMLNode::GetName(v20);
                        if ( !UFG::qStringCompareInsensitive(v21, "Object", -1) )
                        {
                          Attribute = SimpleXML::XMLNode::GetAttribute(v20, "type");
                          v23 = SimpleXML::XMLNode::GetAttribute(v20, "name");
                          v24 = SimpleXML::XMLNode::GetAttribute(v20, "defaults");
                          v25 = SimpleXML::XMLNode::GetAttribute(v20, "value");
                          SimpleXML::XMLNode::GetAttribute(v20, "comboDefaults");
                          v26 = SimpleXML::XMLNode::GetAttribute(v20, "comboValue");
                          if ( UFG::qStringCompareInsensitive(Attribute, "CheckBox", -1)
                            && UFG::qStringCompareInsensitive(Attribute, "ComboBox", -1)
                            && UFG::qStringCompareInsensitive(Attribute, "String", -1) )
                          {
                            if ( !UFG::qStringCompareInsensitive(Attribute, "ArrayList", -1) )
                            {
                              if ( v26 && *v26 )
                                UFG::BuildLabOptionGroup::SetOption(mProjectDefault, v23, v26, 0);
                              UFG::qTokenize(&list, ",", v24, 0, 0i64, 0);
                              UFG::qTokenize(&v41, ",", v25, 0, 0i64, 0);
                              mNext = list.mNode.mNext;
                              if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list )
                              {
                                do
                                {
                                  UFG::qString::FormatEx(&result, "%s.%s", v23, (const char *)mNext[1].mNext);
                                  String = UFG::qFindString(&v41, (const char *)mNext[1].mNext, 1);
                                  v29 = "False";
                                  if ( String )
                                    v29 = "True";
                                  UFG::BuildLabOptionGroup::SetOption(mProjectDefault, result.mData, v29, 0);
                                  UFG::qString::~qString(&result);
                                  mNext = mNext->mNext;
                                }
                                while ( mNext != (UFG::qNode<UFG::qString,UFG::qString> *)&list );
                                v20 = k;
                              }
                              for ( m = (UFG::qString *)v41.mNode.mNext;
                                    (UFG::qList<UFG::qString,UFG::qString,1,0> *)v41.mNode.mNext != &v41;
                                    m = (UFG::qString *)v41.mNode.mNext )
                              {
                                mPrev = m->mPrev;
                                v32 = m->mNext;
                                mPrev->mNext = v32;
                                v32->mPrev = mPrev;
                                m->mPrev = m;
                                m->mNext = m;
                                UFG::qString::~qString(m);
                                operator delete[](m);
                              }
                              v33 = v41.mNode.mPrev;
                              v34 = v41.mNode.mNext;
                              v41.mNode.mPrev->mNext = v41.mNode.mNext;
                              v34->mPrev = v33;
                              v41.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v41;
                              v41.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v41;
                              for ( n = (UFG::qString *)list.mNode.mNext;
                                    (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list;
                                    n = (UFG::qString *)list.mNode.mNext )
                              {
                                v36 = n->mPrev;
                                v37 = n->mNext;
                                v36->mNext = v37;
                                v37->mPrev = v36;
                                n->mPrev = n;
                                n->mNext = n;
                                UFG::qString::~qString(n);
                                operator delete[](n);
                              }
                              v38 = list.mNode.mPrev;
                              v39 = list.mNode.mNext;
                              list.mNode.mPrev->mNext = list.mNode.mNext;
                              v39->mPrev = v38;
                              list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
                              list.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
                            }
                          }
                          else
                          {
                            UFG::BuildLabOptionGroup::SetOption(mProjectDefault, v23, v25, 0);
                          }
                        }
                        v20 = SimpleXML::XMLDocument::GetNode(*(SimpleXML::XMLDocument **)add_empty_strings, 0i64, v20);
                      }
                      v13 = *(SimpleXML::XMLDocument **)add_empty_strings;
                      v19 = SimpleXML::XMLDocument::GetNode(
                              *(SimpleXML::XMLDocument **)add_empty_strings,
                              0i64,
                              prev_node);
                      prev_node = v19;
                    }
                    while ( v19 );
                    v17 = v47;
                  }
                }
                v17 = SimpleXML::XMLDocument::GetNode(v13, 0i64, v17);
                v47 = v17;
              }
              while ( v17 );
              ChildNode = j;
            }
          }
          ChildNode = SimpleXML::XMLDocument::GetNode(v13, 0i64, ChildNode);
        }
        SimpleXML::XMLDocument::~XMLDocument(v13);
        operator delete[](v13);
        if ( ptr )
          UFG::qFreeEntireFile(ptr, 0i64);
      }
      else
      {
        SimpleXML::XMLDocument::~XMLDocument(v13);
        operator delete[](v13);
      }
    }
  }
}

// File Line: 547
// RVA: 0x14F920
UFG::qString *__fastcall UFG::BuildLabDefaults::Load(
        UFG::BuildLabDefaults *this,
        UFG::qString *result,
        const char *project_filename,
        const char *defaults_filename,
        const char *key,
        unsigned int keyLength)
{
  UFG::qString *v8; // r15
  unsigned int mNumRows; // esi
  unsigned int mNumCols; // r14d
  unsigned int v12; // ebx
  unsigned int v13; // edi
  UFG::qBaseTreeRB *v14; // rax
  __int64 *p_mNULL; // rax
  const char *v16; // rdx
  unsigned int mStringHashUpper32; // eax
  UFG::BuildLabOptionGroup *v18; // r12
  char *v19; // rax
  UFG::BuildLabOptionGroup *v20; // rax
  unsigned int v21; // r15d
  UFG::qBaseTreeRB *v22; // rax
  __int64 *v23; // rax
  const char *v24; // rdx
  UFG::qBaseTreeRB *v25; // rax
  UFG::qMap<UFG::qString *> **p_p_mValues; // rax
  const char *v27; // rdx
  bool v28; // r14
  UFG::qString *v29; // rax
  char *mData; // rdi
  UFG::BuildLabOptionGroup *mProjectDefault; // rsi
  __int64 v32; // rbx
  UFG::qBaseNodeRB **mChild; // rsi
  char *v34; // rsi
  UFG::qBaseNodeRB **v35; // rdi
  unsigned int v37; // [rsp+30h] [rbp-D0h]
  int v38; // [rsp+38h] [rbp-C8h]
  UFG::qMap<UFG::qString *> *p_mValues; // [rsp+40h] [rbp-C0h] BYREF
  unsigned int v40; // [rsp+48h] [rbp-B8h]
  __int64 v41; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v42; // [rsp+58h] [rbp-A8h] BYREF
  UFG::qString v43; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qString v44; // [rsp+88h] [rbp-78h] BYREF
  UFG::qString v45; // [rsp+B0h] [rbp-50h] BYREF
  UFG::qString resulta; // [rsp+D8h] [rbp-28h] BYREF
  UFG::CsvDocument v47; // [rsp+100h] [rbp+0h] BYREF
  __int64 v48; // [rsp+180h] [rbp+80h]
  UFG::qString v49; // [rsp+188h] [rbp+88h] BYREF
  unsigned int v50; // [rsp+1F0h] [rbp+F0h]

  v48 = -2i64;
  v8 = result;
  UFG::qTreeRB<UFG::BuildLabOptionGroup,UFG::BuildLabOptionGroup,1>::DeleteAll(&this->mUserRoles);
  UFG::qTreeRB<UFG::BuildLabOption,UFG::BuildLabOption,0>::DeleteAll(&this->mProjectDefault->mOptionTree);
  UFG::BuildLabDefaults::LoadProject(this, project_filename, key, keyLength);
  if ( !UFG::qFileExists(defaults_filename) )
    goto LABEL_64;
  UFG::qString::qString(&v47.mFilename);
  p_mValues = &v47.mValues;
  UFG::qBaseTreeRB::qBaseTreeRB(&v47.mValues.mTree.mTree);
  UFG::qString::Set(&v47.mFilename, 0i64);
  *(_QWORD *)&v47.mNumRows = 0i64;
  UFG::CsvDocument::Load(&v47, &resulta, defaults_filename, key);
  mNumRows = v47.mNumRows;
  v37 = v47.mNumRows;
  mNumCols = v47.mNumCols;
  v40 = v47.mNumCols;
  if ( !resulta.mLength )
  {
    if ( v47.mNumRows <= 1 || v47.mNumCols <= 1 )
    {
      UFG::qString::qString(v8);
      UFG::qString::~qString(&resulta);
      UFG::CsvDocument::~CsvDocument(&v47);
      return v8;
    }
    v12 = 1;
    v38 = 1;
    v42 = 0i64;
    do
    {
      v13 = (unsigned __int16)v12 << 16;
      v50 = v13;
      if ( v13 && (v14 = UFG::qBaseTreeRB::Get(&v47.mValues.mTree.mTree, v13)) != 0i64 )
        p_mNULL = (__int64 *)&v14->mNULL;
      else
        p_mNULL = &v42;
      if ( *p_mNULL )
        v16 = *(const char **)(*p_mNULL + 24);
      else
        v16 = 0i64;
      UFG::qTrim(&v44, v16, -1);
      if ( v44.mLength )
      {
        mStringHashUpper32 = v44.mStringHashUpper32;
        if ( v44.mStringHashUpper32 == -1 )
        {
          mStringHashUpper32 = UFG::qStringHashUpper32(v44.mData, 0xFFFFFFFF);
          v44.mStringHashUpper32 = mStringHashUpper32;
        }
        if ( !mStringHashUpper32
          || (v18 = (UFG::BuildLabOptionGroup *)UFG::qBaseTreeRB::Get(&this->mUserRoles.mTree, mStringHashUpper32)) == 0i64 )
        {
          v19 = UFG::qMalloc(0xA0ui64, "BuildLabOptionGroup", 0i64);
          p_mValues = (UFG::qMap<UFG::qString *> *)v19;
          if ( v19 )
          {
            UFG::BuildLabOptionGroup::BuildLabOptionGroup((UFG::BuildLabOptionGroup *)v19, v44.mData);
            v18 = v20;
          }
          else
          {
            v18 = 0i64;
          }
          UFG::qBaseTreeRB::Add(&this->mUserRoles.mTree, &v18->mNode);
        }
        v21 = 1;
        if ( mNumRows > 1 )
        {
          v41 = 0i64;
          p_mValues = 0i64;
          do
          {
            if ( (_WORD)v21 && (v22 = UFG::qBaseTreeRB::Get(&v47.mValues.mTree.mTree, (unsigned __int16)v21)) != 0i64 )
              v23 = (__int64 *)&v22->mNULL;
            else
              v23 = &v41;
            if ( *v23 )
              v24 = *(const char **)(*v23 + 24);
            else
              v24 = 0i64;
            UFG::qTrim(&v43, v24, -1);
            if ( (unsigned __int16)v21 | v13
              && (v25 = UFG::qBaseTreeRB::Get(&v47.mValues.mTree.mTree, (unsigned __int16)v21 | v13)) != 0i64 )
            {
              p_p_mValues = (UFG::qMap<UFG::qString *> **)&v25->mNULL;
            }
            else
            {
              p_p_mValues = &p_mValues;
            }
            if ( *p_p_mValues )
              v27 = *(const char **)&(*p_p_mValues)->mTree.mTree.mRoot.mUID;
            else
              v27 = 0i64;
            UFG::qTrim(&v45, v27, -1);
            v28 = 0;
            if ( v43.mLength )
            {
              if ( (unsigned int)UFG::qString::StartsWith(&v45, "!", -1) )
              {
                v29 = UFG::qString::Substring(&v45, &v49, 1, -1);
                UFG::qString::Set(&v45, v29->mData, v29->mLength, 0i64, 0);
                UFG::qString::~qString(&v49);
                v28 = 1;
              }
              if ( UFG::qStringFind(v43.mData, pattern) || UFG::qStringFind(v43.mData, "?") )
              {
                mData = v43.mData;
                mProjectDefault = this->mProjectDefault;
                if ( v43.mData )
                {
                  if ( *v43.mData )
                  {
                    v32 = (__int64)&mProjectDefault->mOptionList.mNode.mNext[-2];
                    mChild = mProjectDefault->mOptionTree.mTree.mNULL.mChild;
                    if ( (UFG::qBaseNodeRB **)v32 != mChild )
                    {
                      while ( !UFG::qWildcardMatchInsensitive(mData, *(const char **)(v32 + 72)) )
                      {
                        v32 = *(_QWORD *)(v32 + 40) - 32i64;
                        if ( (UFG::qBaseNodeRB **)v32 == mChild )
                          goto LABEL_57;
                      }
                      while ( 1 )
                      {
                        UFG::BuildLabOptionGroup::SetOption(v18, *(const char **)(v32 + 72), v45.mData, v28);
                        v34 = v43.mData;
                        if ( !v43.mData )
                          break;
                        if ( !*v43.mData )
                          break;
                        v32 = *(_QWORD *)(v32 + 40) - 32i64;
                        v35 = this->mProjectDefault->mOptionTree.mTree.mNULL.mChild;
                        if ( (UFG::qBaseNodeRB **)v32 == v35 )
                          break;
                        while ( !UFG::qWildcardMatchInsensitive(v34, *(const char **)(v32 + 72)) )
                        {
                          v32 = *(_QWORD *)(v32 + 40) - 32i64;
                          if ( (UFG::qBaseNodeRB **)v32 == v35 )
                            goto LABEL_57;
                        }
                      }
                    }
                  }
                }
LABEL_57:
                v13 = v50;
                mNumRows = v37;
              }
              else
              {
                UFG::BuildLabOptionGroup::SetOption(v18, v43.mData, v45.mData, v28);
              }
            }
            UFG::qString::~qString(&v45);
            UFG::qString::~qString(&v43);
            ++v21;
          }
          while ( v21 < mNumRows );
          v12 = v38;
          mNumCols = v40;
        }
      }
      UFG::qString::~qString(&v44);
      v38 = ++v12;
    }
    while ( v12 < mNumCols );
    v8 = result;
    UFG::qString::~qString(&resulta);
    UFG::CsvDocument::~CsvDocument(&v47);
LABEL_64:
    UFG::qString::qString(v8);
    return v8;
  }
  UFG::qString::qString(v8, &resulta);
  UFG::qString::~qString(&resulta);
  UFG::CsvDocument::~CsvDocument(&v47);
  return v8;
}vDocument::~CsvDocument(&v47);
LABEL_64:
    UFG::qSt

// File Line: 673
// RVA: 0x14EAE0
void __fastcall UFG::BuildLabOptions::BuildLabOptions(
        UFG::BuildLabOptions *this,
        const char *user_options_filename,
        UFG::BuildLabOptions::LoadOptions load_options,
        const char *key,
        unsigned int keyLength)
{
  char v6; // r15
  char *v9; // rax
  char *v10; // rax
  char *v11; // rax
  UFG::qString *v12; // rax
  UFG::qString *v13; // rax
  UFG::qString *v14; // rax
  char *Value; // rax
  char *v16; // rax
  UFG::qString result; // [rsp+40h] [rbp-31h] BYREF
  UFG::qString v18; // [rsp+68h] [rbp-9h] BYREF

  v6 = load_options;
  UFG::qString::qString(&this->mProjectFilename);
  UFG::qString::qString(&this->mDefaultsFilename);
  UFG::qString::qString(&this->mUserOptionsFilename);
  UFG::qString::qString(&this->mUserRoleName);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mDefaults.mUserRoles.mTree);
  v9 = UFG::qMalloc(0xA0ui64, "BuildLabOptionGroup", 0i64);
  if ( v9 )
    UFG::BuildLabOptionGroup::BuildLabOptionGroup((UFG::BuildLabOptionGroup *)v9, "ProjectDefault");
  this->mDefaults.mProjectDefault = (UFG::BuildLabOptionGroup *)v9;
  v10 = UFG::qMalloc(0xA0ui64, "BuildLabOptionGroup", 0i64);
  if ( v10 )
    UFG::BuildLabOptionGroup::BuildLabOptionGroup((UFG::BuildLabOptionGroup *)v10, "ProjectOptions");
  this->mProjectOptionGroup = (UFG::BuildLabOptionGroup *)v10;
  v11 = UFG::qMalloc(0xA0ui64, "BuildLabOptionGroup", 0i64);
  if ( v11 )
    UFG::BuildLabOptionGroup::BuildLabOptionGroup((UFG::BuildLabOptionGroup *)v11, "UserOptions");
  this->mUserOptionGroup = (UFG::BuildLabOptionGroup *)v11;
  this->mEnableDiagnostics = 0;
  UFG::qString::Set(&this->mUserOptionsFilename, user_options_filename);
  UFG::qString::GetFilePath(&this->mUserOptionsFilename, &result);
  if ( result.mLength
    && !(unsigned int)UFG::qString::EndsWith(&result, "\\", -1)
    && !(unsigned int)UFG::qString::EndsWith(&result, "/", -1) )
  {
    UFG::qString::operator+=(&result, "\\");
  }
  if ( key )
  {
    v12 = UFG::qString::FormatEx(&v18, "%sBuildLab.project.dat", result.mData);
    UFG::qString::Set(&this->mProjectFilename, v12->mData, v12->mLength, 0i64, 0);
    UFG::qString::~qString(&v18);
    v13 = UFG::qString::FormatEx(&v18, "%sBuildLab.defaults.dat", result.mData);
  }
  else
  {
    v14 = UFG::qString::FormatEx(&v18, "%sBuildLab.project.xml", result.mData);
    UFG::qString::Set(&this->mProjectFilename, v14->mData, v14->mLength, 0i64, 0);
    UFG::qString::~qString(&v18);
    v13 = UFG::qString::FormatEx(&v18, "%sBuildLab.defaults.csv", result.mData);
  }
  UFG::qString::Set(&this->mDefaultsFilename, v13->mData, v13->mLength, 0i64, 0);
  UFG::qString::~qString(&v18);
  if ( (v6 & 2) != 0 )
    UFG::BuildLabOptions::LoadProjectFile(this, this->mProjectFilename.mData, key, keyLength);
  if ( (v6 & 1) != 0 )
  {
    UFG::BuildLabOptions::LoadUserFile(this, this->mUserOptionsFilename.mData, key, keyLength);
    UFG::BuildLabDefaults::Load(
      &this->mDefaults,
      &v18,
      this->mProjectFilename.mData,
      this->mDefaultsFilename.mData,
      key,
      keyLength);
    UFG::qString::~qString(&v18);
  }
  Value = UFG::BuildLabOptions::GetValue(this, "UserRole", 0i64);
  UFG::qString::Set(&this->mUserRoleName, Value);
  v16 = UFG::BuildLabOptions::GetValue(this, "Diagnostics", &customCaption);
  this->mEnableDiagnostics = UFG::qToBool(v16, 0);
  UFG::qString::~qString(&result);
}

// File Line: 729
// RVA: 0x14EF50
void __fastcall UFG::BuildLabOptions::~BuildLabOptions(UFG::BuildLabOptions *this)
{
  UFG::BuildLabOptionGroup *mProjectOptionGroup; // rdi
  UFG::BuildLabOptionGroup *mUserOptionGroup; // rdi
  UFG::BuildLabOptionGroup *mProjectDefault; // rsi

  mProjectOptionGroup = this->mProjectOptionGroup;
  if ( mProjectOptionGroup )
  {
    UFG::BuildLabOptionGroup::~BuildLabOptionGroup(this->mProjectOptionGroup);
    operator delete[](mProjectOptionGroup);
  }
  mUserOptionGroup = this->mUserOptionGroup;
  if ( mUserOptionGroup )
  {
    UFG::BuildLabOptionGroup::~BuildLabOptionGroup(this->mUserOptionGroup);
    operator delete[](mUserOptionGroup);
  }
  this->mProjectOptionGroup = 0i64;
  this->mUserOptionGroup = 0i64;
  mProjectDefault = this->mDefaults.mProjectDefault;
  if ( mProjectDefault )
  {
    UFG::BuildLabOptionGroup::~BuildLabOptionGroup(this->mDefaults.mProjectDefault);
    operator delete[](mProjectDefault);
  }
  this->mDefaults.mProjectDefault = 0i64;
  UFG::qTreeRB<UFG::BuildLabOptionGroup,UFG::BuildLabOptionGroup,1>::DeleteAll(&this->mDefaults.mUserRoles);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->mDefaults);
  UFG::qString::~qString(&this->mUserRoleName);
  UFG::qString::~qString(&this->mUserOptionsFilename);
  UFG::qString::~qString(&this->mDefaultsFilename);
  UFG::qString::~qString(&this->mProjectFilename);
}

// File Line: 913
// RVA: 0x14F8E0
UFG::qBaseNodeRB *__fastcall UFG::BuildLabOptions::GetValue(UFG::BuildLabOptions *this, const char *option_name)
{
  return UFG::BuildLabOptions::GetValue(this, option_name, 0i64);
}

// File Line: 918
// RVA: 0x14F7D0
UFG::qBaseNodeRB *__fastcall UFG::BuildLabOptions::GetValue(
        UFG::BuildLabOptions *this,
        const char *option_name,
        const char *default_value)
{
  UFG::qBaseTreeRB *v6; // rax
  char mUID; // r15
  UFG::qBaseTreeRB *v8; // rax
  UFG::qBaseNodeRB *v9; // rdi
  UFG::BuildLabOptionGroup *mUserOptionGroup; // rbp
  UFG::qNode<UFG::BuildLabOption,UFG::BuildLabOption> *mNext; // rbx
  UFG::qBaseNodeRB **mChild; // rbp
  __int64 v13; // rbx

  v6 = UFG::BuildLabDefaults::Get(&this->mDefaults, this->mUserRoleName.mData, option_name);
  if ( v6 )
    mUID = v6[1].mNULL.mUID;
  else
    mUID = 0;
  v8 = UFG::BuildLabDefaults::Get(&this->mDefaults, this->mUserRoleName.mData, option_name);
  if ( v8 )
    v9 = v8[1].mNULL.mChild[0];
  else
    v9 = 0i64;
  mUserOptionGroup = this->mUserOptionGroup;
  if ( option_name
    && *option_name
    && (mNext = mUserOptionGroup->mOptionList.mNode.mNext,
        mChild = mUserOptionGroup->mOptionTree.mTree.mNULL.mChild,
        v13 = (__int64)&mNext[-2],
        (UFG::qBaseNodeRB **)v13 != mChild) )
  {
    while ( !UFG::qWildcardMatchInsensitive(option_name, *(const char **)(v13 + 72)) )
    {
      v13 = *(_QWORD *)(v13 + 40) - 32i64;
      if ( (UFG::qBaseNodeRB **)v13 == mChild )
        goto LABEL_12;
    }
  }
  else
  {
LABEL_12:
    v13 = 0i64;
  }
  if ( mUID )
    return v9;
  if ( v13 )
    return *(UFG::qBaseNodeRB **)(v13 + 112);
  if ( v9 )
    return v9;
  return (UFG::qBaseNodeRB *)default_value;
}

// File Line: 946
// RVA: 0x14F7A0
int __fastcall UFG::BuildLabOptions::GetValue(UFG::BuildLabOptions *this, const char *option_name, int default_value)
{
  char *Value; // rax

  Value = UFG::BuildLabOptions::GetValue(this, option_name, &customCaption);
  return UFG::qToInt32(Value, default_value);
}

// File Line: 950
// RVA: 0x14F8F0
char __fastcall UFG::BuildLabOptions::GetValue(UFG::BuildLabOptions *this, const char *option_name, bool default_value)
{
  UFG::qBaseNodeRB *Value; // rax

  Value = UFG::BuildLabOptions::GetValue(this, option_name, &customCaption);
  return UFG::qToBool((const char *)Value, default_value);
}

// File Line: 953
// RVA: 0x14F390
void __fastcall UFG::BuildLabOptions::GetNames(
        UFG::BuildLabOptions *this,
        UFG::qList<UFG::qString,UFG::qString,1,0> *option_list,
        const char *option_name_pattern,
        const char *option_value_pattern,
        const char *strip_prefix)
{
  __int64 v9; // r12
  UFG::BuildLabOptionGroup *mProjectDefault; // rdi
  __int64 v11; // rbx
  UFG::qBaseNodeRB **mChild; // rdi
  char *Value; // rax
  char *v14; // rax
  UFG::qString *v15; // rax
  UFG::qString *v16; // rdi
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rax
  char *v18; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v19; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v20; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
  UFG::qBaseNodeRB **v22; // rdi
  UFG::BuildLabOptionGroup *mUserOptionGroup; // rdi
  __int64 v24; // rbx
  UFG::qBaseNodeRB **v25; // rdi
  const char *v26; // rsi
  UFG::BuildLabOptionGroup *v27; // rbp
  __int64 v28; // rdi
  UFG::qBaseNodeRB **v29; // rbp
  char *v30; // rax
  char *v31; // rax
  UFG::qString *v32; // rax
  UFG::qString *v33; // rdi
  UFG::qNode<UFG::qString,UFG::qString> *v34; // rax
  char *v35; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v36; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v37; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v38; // rax
  UFG::qBaseNodeRB **v39; // rdi

  if ( this->mEnableDiagnostics )
    UFG::qPrintf("[BuildLabOptions::GetNames] %-20s -> ", option_name_pattern);
  v9 = (int)UFG::qStringLength(strip_prefix);
  mProjectDefault = this->mDefaults.mProjectDefault;
  if ( option_name_pattern )
  {
    if ( *option_name_pattern )
    {
      v11 = (__int64)&mProjectDefault->mOptionList.mNode.mNext[-2];
      mChild = mProjectDefault->mOptionTree.mTree.mNULL.mChild;
      if ( (UFG::qBaseNodeRB **)v11 != mChild )
      {
        while ( !UFG::qWildcardMatchInsensitive(option_name_pattern, *(const char **)(v11 + 72)) )
        {
          v11 = *(_QWORD *)(v11 + 40) - 32i64;
          if ( (UFG::qBaseNodeRB **)v11 == mChild )
            goto LABEL_28;
        }
        while ( 1 )
        {
          Value = UFG::BuildLabOptions::GetValue(this, *(const char **)(v11 + 72), 0i64);
          if ( UFG::qWildcardMatchInsensitive(option_value_pattern, Value) )
          {
            if ( (int)v9 <= 0 )
            {
              if ( this->mEnableDiagnostics )
                UFG::qPrintf("%s  ", *(const char **)(v11 + 72));
              v18 = UFG::qMalloc(0x28ui64, "BuildLabOptionString", 0i64);
              if ( v18 )
              {
                UFG::qString::qString((UFG::qString *)v18, (UFG::qString *)(v11 + 48));
                v20 = v19;
              }
              else
              {
                v20 = 0i64;
              }
              mPrev = option_list->mNode.mPrev;
              mPrev->mNext = v20;
              v20->mPrev = mPrev;
              v20->mNext = &option_list->mNode;
              option_list->mNode.mPrev = v20;
            }
            else if ( *(_DWORD *)(v11 + 68) - (int)v9 > 0 )
            {
              v14 = UFG::qMalloc(0x28ui64, "BuildLabOptionString", 0i64);
              if ( v14 )
              {
                UFG::qString::qString((UFG::qString *)v14);
                v16 = v15;
              }
              else
              {
                v16 = 0i64;
              }
              UFG::qString::Set(v16, (const char *)(*(_QWORD *)(v11 + 72) + v9));
              if ( this->mEnableDiagnostics )
                UFG::qPrintf("%s  ", v16->mData);
              v17 = option_list->mNode.mPrev;
              v17->mNext = v16;
              v16->mPrev = v17;
              v16->mNext = &option_list->mNode;
              option_list->mNode.mPrev = v16;
            }
          }
          if ( !*option_name_pattern )
            break;
          v11 = *(_QWORD *)(v11 + 40) - 32i64;
          v22 = this->mDefaults.mProjectDefault->mOptionTree.mTree.mNULL.mChild;
          if ( (UFG::qBaseNodeRB **)v11 == v22 )
            break;
          while ( !UFG::qWildcardMatchInsensitive(option_name_pattern, *(const char **)(v11 + 72)) )
          {
            v11 = *(_QWORD *)(v11 + 40) - 32i64;
            if ( (UFG::qBaseNodeRB **)v11 == v22 )
              goto LABEL_28;
          }
        }
      }
    }
  }
LABEL_28:
  mUserOptionGroup = this->mUserOptionGroup;
  if ( option_name_pattern )
  {
    if ( *option_name_pattern )
    {
      v24 = (__int64)&mUserOptionGroup->mOptionList.mNode.mNext[-2];
      v25 = mUserOptionGroup->mOptionTree.mTree.mNULL.mChild;
      if ( (UFG::qBaseNodeRB **)v24 != v25 )
      {
        while ( !UFG::qWildcardMatchInsensitive(option_name_pattern, *(const char **)(v24 + 72)) )
        {
          v24 = *(_QWORD *)(v24 + 40) - 32i64;
          if ( (UFG::qBaseNodeRB **)v24 == v25 )
            return;
        }
        while ( 1 )
        {
          v26 = *(const char **)(v24 + 72);
          v27 = this->mDefaults.mProjectDefault;
          if ( v26
            && *v26
            && (v28 = (__int64)&v27->mOptionList.mNode.mNext[-2],
                v29 = v27->mOptionTree.mTree.mNULL.mChild,
                (UFG::qBaseNodeRB **)v28 != v29) )
          {
            while ( !UFG::qWildcardMatchInsensitive(v26, *(const char **)(v28 + 72)) )
            {
              v28 = *(_QWORD *)(v28 + 40) - 32i64;
              if ( (UFG::qBaseNodeRB **)v28 == v29 )
                goto LABEL_39;
            }
          }
          else
          {
LABEL_39:
            v30 = UFG::BuildLabOptions::GetValue(this, *(const char **)(v24 + 72), 0i64);
            if ( UFG::qWildcardMatchInsensitive(option_value_pattern, v30) )
            {
              if ( (int)v9 <= 0 )
              {
                if ( this->mEnableDiagnostics )
                  UFG::qPrintf("%s  ", *(const char **)(v24 + 72));
                v35 = UFG::qMalloc(0x28ui64, "BuildLabOptionString", 0i64);
                if ( v35 )
                {
                  UFG::qString::qString((UFG::qString *)v35, (UFG::qString *)(v24 + 48));
                  v37 = v36;
                }
                else
                {
                  v37 = 0i64;
                }
                v38 = option_list->mNode.mPrev;
                v38->mNext = v37;
                v37->mPrev = v38;
                v37->mNext = &option_list->mNode;
                option_list->mNode.mPrev = v37;
              }
              else if ( *(_DWORD *)(v24 + 68) - (int)v9 > 0 )
              {
                v31 = UFG::qMalloc(0x28ui64, "BuildLabOptionString", 0i64);
                if ( v31 )
                {
                  UFG::qString::qString((UFG::qString *)v31);
                  v33 = v32;
                }
                else
                {
                  v33 = 0i64;
                }
                UFG::qString::Set(v33, (const char *)(*(_QWORD *)(v24 + 72) + v9));
                if ( this->mEnableDiagnostics )
                  UFG::qPrintf("%s  ", v33->mData);
                v34 = option_list->mNode.mPrev;
                v34->mNext = v33;
                v33->mPrev = v34;
                v33->mNext = &option_list->mNode;
                option_list->mNode.mPrev = v33;
              }
            }
          }
          if ( !*option_name_pattern )
            break;
          v24 = *(_QWORD *)(v24 + 40) - 32i64;
          v39 = this->mUserOptionGroup->mOptionTree.mTree.mNULL.mChild;
          if ( (UFG::qBaseNodeRB **)v24 == v39 )
            break;
          while ( !UFG::qWildcardMatchInsensitive(option_name_pattern, *(const char **)(v24 + 72)) )
          {
            v24 = *(_QWORD *)(v24 + 40) - 32i64;
            if ( (UFG::qBaseNodeRB **)v24 == v39 )
              return;
          }
        }
      }
    }
  }
}

// File Line: 1067
// RVA: 0x1508A0
void __fastcall UFG::BuildLabOptions::LoadProjectFile(
        UFG::BuildLabOptions *this,
        const char *filename,
        const char *obfuscateKey,
        unsigned int obfuscateKeyLength)
{
  __int64 v4; // rsi
  char v7; // bp
  UFG::qString *v8; // rax
  __int64 v9; // rbx
  char *v10; // r8
  int v11; // ecx
  UFG::qMemoryPool **v12; // rax
  SimpleXML::XMLDocument *v13; // rsi
  SimpleXML::XMLNode *Node; // rax
  SimpleXML::XMLNode *i; // rdi
  char *Name; // rax
  char *Attribute; // rbx
  char *Value; // rax
  UFG::qString v19; // [rsp+38h] [rbp-70h] BYREF
  UFG::qString result; // [rsp+60h] [rbp-48h] BYREF
  __int64 loaded_size; // [rsp+C0h] [rbp+18h] BYREF

  v4 = obfuscateKeyLength;
  v7 = 0;
  UFG::qString::qString(&v19, filename);
  if ( obfuscateKey && (_DWORD)v4 )
  {
    v8 = UFG::qString::ReplaceExtension(&v19, &result, ".dat");
    UFG::qString::Set(&v19, v8->mData);
    UFG::qString::~qString(&result);
    v7 = 1;
  }
  if ( UFG::qFileExists(v19.mData) )
  {
    v9 = 0i64;
    loaded_size = 0i64;
    v10 = UFG::qReadEntireFile(v19.mData, &loaded_size, 0i64, 0i64, 0i64);
    v11 = loaded_size;
    if ( ((v10 != 0i64) & (unsigned __int8)v7) != 0 && loaded_size > 0 )
    {
      do
      {
        v10[v9] ^= obfuscateKey[v9 % v4];
        ++v9;
        v11 = loaded_size;
      }
      while ( v9 < loaded_size );
    }
    v12 = SimpleXML::XMLDocument::OpenBuffer(v10, v11);
    v13 = (SimpleXML::XMLDocument *)v12;
    if ( v12 )
    {
      Node = SimpleXML::XMLDocument::GetNode((SimpleXML::XMLDocument *)v12, "BuildLab", 0i64);
      if ( Node )
      {
        for ( i = SimpleXML::XMLDocument::GetChildNode(v13, 0i64, Node);
              i;
              i = SimpleXML::XMLDocument::GetNode(v13, 0i64, i) )
        {
          Name = SimpleXML::XMLNode::GetName(i);
          if ( !UFG::qStringCompareInsensitive(Name, "Param", -1) )
          {
            Attribute = SimpleXML::XMLNode::GetAttribute(i, "key");
            Value = SimpleXML::XMLNode::GetValue(i);
            UFG::BuildLabOptionGroup::SetOption(this->mProjectOptionGroup, Attribute, Value, 0);
          }
        }
      }
      SimpleXML::XMLDocument::~XMLDocument(v13);
      operator delete[](v13);
    }
  }
  UFG::qString::~qString(&v19);
}

// File Line: 1126
// RVA: 0x150A70
void __fastcall UFG::BuildLabOptions::LoadUserFile(
        UFG::BuildLabOptions *this,
        const char *filename,
        const char *obfuscateKey,
        unsigned int obfuscateKeyLength)
{
  __int64 v4; // rdi
  char v7; // si
  UFG::qString *v8; // rax
  char *v9; // r13
  int v10; // edx
  __int64 i; // rcx
  UFG::qMemoryPool **v12; // rax
  SimpleXML::XMLDocument *v13; // r14
  SimpleXML::XMLNode *Node; // rax
  UFG::BuildLabOptionGroup *mUserOptionGroup; // r15
  SimpleXML::XMLNode *j; // r12
  char *Name; // rax
  char *v18; // rax
  char *v19; // rax
  char *Attribute; // rbx
  char *v21; // rax
  char *Value; // rbx
  char *v23; // rax
  SimpleXML::XMLNode *k; // rsi
  char *v25; // rax
  const char *v26; // rbx
  char *v27; // rax
  UFG::qString *v28; // rax
  char *v29; // rax
  SimpleXML::XMLNode *ChildNode; // rbx
  char *v31; // rax
  const char *v32; // rdi
  UFG::qString *v33; // rax
  char *v34; // rax
  UFG::qString lhs; // [rsp+30h] [rbp-71h] BYREF
  UFG::qString result; // [rsp+58h] [rbp-49h] BYREF
  __int64 v37; // [rsp+80h] [rbp-21h]
  UFG::qString v38; // [rsp+88h] [rbp-19h] BYREF
  UFG::qString v39; // [rsp+B0h] [rbp+Fh] BYREF
  __int64 loaded_size; // [rsp+118h] [rbp+77h] BYREF

  v37 = -2i64;
  v4 = obfuscateKeyLength;
  v7 = 0;
  UFG::qString::qString(&lhs, filename);
  if ( obfuscateKey && (_DWORD)v4 )
  {
    v8 = UFG::qString::ReplaceExtension(&lhs, &result, ".dat");
    UFG::qString::Set(&lhs, v8->mData);
    UFG::qString::~qString(&result);
    v7 = 1;
  }
  if ( UFG::qFileExists(lhs.mData) )
  {
    loaded_size = 0i64;
    v9 = UFG::qReadEntireFile(lhs.mData, &loaded_size, 0i64, 0i64, 0i64);
    if ( v9 )
    {
      v10 = loaded_size;
      if ( (v7 & 1) != 0 )
      {
        for ( i = 0i64; i < loaded_size; v10 = loaded_size )
        {
          v9[i] ^= obfuscateKey[i % v4];
          ++i;
        }
      }
      v12 = SimpleXML::XMLDocument::OpenBuffer(v9, v10);
      v13 = (SimpleXML::XMLDocument *)v12;
      if ( v12 )
      {
        Node = SimpleXML::XMLDocument::GetNode((SimpleXML::XMLDocument *)v12, "UserOptions", 0i64);
        if ( Node )
        {
          mUserOptionGroup = this->mUserOptionGroup;
          for ( j = SimpleXML::XMLDocument::GetChildNode(v13, 0i64, Node);
                j;
                j = SimpleXML::XMLDocument::GetNode(v13, 0i64, j) )
          {
            Name = SimpleXML::XMLNode::GetName(j);
            if ( UFG::qStringCompareInsensitive(Name, "PipelineOptions", -1)
              && (v18 = SimpleXML::XMLNode::GetName(j), UFG::qStringCompareInsensitive(v18, "RunOptions", -1)) )
            {
              v19 = SimpleXML::XMLNode::GetName(j);
              if ( UFG::qStringCompareInsensitive(v19, "Param", -1) )
              {
                Value = SimpleXML::XMLNode::GetValue(j);
                v23 = SimpleXML::XMLNode::GetName(j);
                UFG::BuildLabOptionGroup::SetOption(mUserOptionGroup, v23, Value, 0);
              }
              else
              {
                Attribute = SimpleXML::XMLNode::GetAttribute(j, "key");
                v21 = SimpleXML::XMLNode::GetValue(j);
                UFG::BuildLabOptionGroup::SetOption(mUserOptionGroup, Attribute, v21, 0);
              }
            }
            else
            {
              for ( k = SimpleXML::XMLDocument::GetChildNode(v13, 0i64, j);
                    k;
                    k = SimpleXML::XMLDocument::GetNode(v13, 0i64, k) )
              {
                UFG::qString::qString(&lhs);
                v25 = SimpleXML::XMLNode::GetAttribute(k, "name");
                v26 = v25;
                if ( v25 && *v25 )
                {
                  v27 = SimpleXML::XMLNode::GetName(k);
                  v28 = UFG::qString::FormatEx(&v38, "%s.%s", v27, v26);
                  UFG::qString::Set(&lhs, v28->mData, v28->mLength, 0i64, 0);
                  UFG::qString::~qString(&v38);
                }
                else
                {
                  v29 = SimpleXML::XMLNode::GetName(k);
                  UFG::qString::Set(&lhs, v29);
                }
                ChildNode = SimpleXML::XMLDocument::GetChildNode(v13, "anyType", k);
                if ( ChildNode )
                {
                  do
                  {
                    v31 = SimpleXML::XMLNode::GetValue(ChildNode);
                    v32 = v31;
                    if ( v31 && *v31 )
                    {
                      v33 = UFG::operator+(&v39, &lhs, ".");
                      UFG::operator+(&result, v33, v32);
                      UFG::qString::~qString(&v39);
                      UFG::BuildLabOptionGroup::SetOption(mUserOptionGroup, result.mData, "True", 0);
                      UFG::qString::~qString(&result);
                    }
                    ChildNode = SimpleXML::XMLDocument::GetNode(v13, 0i64, ChildNode);
                  }
                  while ( ChildNode );
                }
                else
                {
                  v34 = SimpleXML::XMLNode::GetValue(k);
                  UFG::BuildLabOptionGroup::SetOption(mUserOptionGroup, lhs.mData, v34, 0);
                }
                UFG::qString::~qString(&lhs);
              }
            }
          }
        }
        SimpleXML::XMLDocument::~XMLDocument(v13);
        operator delete[](v13);
        UFG::qFreeEntireFile(v9, 0i64);
      }
    }
  }
  UFG::qString::~qString(&lhs);
}

