// File Line: 215
// RVA: 0x787AB0
void __fastcall Scaleform::GFx::AS3::MultinameHash<bool,2>::~MultinameHash<bool,2>(
        Scaleform::GFx::AS3::MultinameHash<bool,2> *this)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::Clear(&this->Entries.mHash);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::Clear(&this->Entries.mHash);
}

// File Line: 221
// RVA: 0x7E4140
Scaleform::GFx::AS3::ClassTraits::Traits **__fastcall Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
        Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *this,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor> *v5; // rax
  bool *p_Second; // rsi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::MultinameHash<bool,2>::Key key; // [rsp+28h] [rbp-20h] BYREF

  pNode = name->pNode;
  key.Name.pNode = pNode;
  ++pNode->RefCount;
  key.pNs.pObject = ns;
  if ( ns )
    ns->RefCount = (ns->RefCount + 1) & 0x8FBFFFFF;
  v5 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::GetAlt<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key>(
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)this,
         &key);
  if ( v5 )
    p_Second = &v5->Second;
  else
    p_Second = 0i64;
  if ( ns )
  {
    if ( ((unsigned __int8)ns & 1) != 0 )
    {
      key.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)ns - 1);
    }
    else
    {
      RefCount = ns->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        ns->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(ns);
      }
    }
  }
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return (Scaleform::GFx::AS3::ClassTraits::Traits **)p_Second;
}

// File Line: 226
// RVA: 0x7E41F0
Scaleform::GFx::AS3::ClassTraits::Traits **__fastcall Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
        Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *this,
        Scaleform::GFx::AS3::Multiname *mn)
{
  Scaleform::GFx::AS3::ClassTraits::Traits **v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // r13
  __int64 v9; // rsi
  Scaleform::GFx::AS3::RefCountCollector<328> *pRCC; // r12
  unsigned __int64 v11; // rbp
  __int64 v12; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> >::TableType *pTable; // rsi
  signed __int64 v15; // rax
  __int64 v16; // rsi
  int v17; // eax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::MultinameHash<bool,2>::Key key; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::ASString name; // [rsp+78h] [rbp+10h] BYREF

  if ( (mn->Kind & 3) == 2 )
  {
    pObject = mn->Obj.pObject;
    v9 = 0i64;
    pRCC = pObject[1]._pRCC;
    v11 = 0i64;
    do
    {
      if ( v11 >= (unsigned __int64)pRCC )
        break;
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&mn->Name, &name);
      v12 = *((_QWORD *)&pObject[1].vfptr->ForEachChild_GC + v11);
      pNode = name.pNode;
      key.Name = name;
      ++name.pNode->RefCount;
      key.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v12;
      if ( v12 )
        *(_DWORD *)(v12 + 32) = (*(_DWORD *)(v12 + 32) + 1) & 0x8FBFFFFF;
      pTable = this->Entries.mHash.pTable;
      if ( this->Entries.mHash.pTable
        && (v15 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key>(
                    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)this,
                    &key,
                    pTable->SizeMask & (pNode->HashFlags & 0xFFFFFF ^ (4
                                                                     * (*(_DWORD *)(*(_QWORD *)(v12 + 56) + 28i64) & 0xFFFFFFu)) ^ (unsigned __int64)(unsigned int)((int)(*(_DWORD *)(v12 + 40) << 28) >> 28))),
            v15 >= 0)
        && (v16 = (__int64)&pTable[2] + 40 * v15) != 0 )
      {
        v9 = v16 + 16;
      }
      else
      {
        v9 = 0i64;
      }
      if ( v12 )
      {
        if ( (v12 & 1) != 0 )
        {
          key.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)(v12 - 1);
        }
        else
        {
          v17 = *(_DWORD *)(v12 + 32);
          if ( (v17 & 0x3FFFFF) != 0 )
          {
            *(_DWORD *)(v12 + 32) = v17 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v12);
          }
        }
      }
      v6 = pNode->RefCount-- == 1;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v18 = name.pNode;
      v6 = name.pNode->RefCount-- == 1;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      ++v11;
    }
    while ( !v9 );
    return (Scaleform::GFx::AS3::ClassTraits::Traits **)v9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&mn->Name, &name);
    v4 = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
           this,
           &name,
           (Scaleform::GFx::AS3::Instances::fl::Namespace *)mn->Obj.pObject);
    v5 = name.pNode;
    v6 = name.pNode->RefCount-- == 1;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    return v4;
  }
}

// File Line: 240
// RVA: 0x7AA930
void __fastcall Scaleform::GFx::AS3::MultinameHash<bool,2>::Add(
        Scaleform::GFx::AS3::MultinameHash<bool,2> *this,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        const bool *val)
{
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v4; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v6; // rcx
  Scaleform::GFx::ASStringNode *pNode; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v9; // [rsp+30h] [rbp-28h]
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-20h] BYREF

  pNode = name->pNode;
  ++pNode->RefCount;
  v9 = ns;
  if ( ns )
    ns->RefCount = (ns->RefCount + 1) & 0x8FBFFFFF;
  key.pFirst = (Scaleform::GFx::AS3::MultinameHash<bool,2>::Key *)&pNode;
  key.pSecond = val;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeRef>(
    &this->Entries.mHash,
    this->Entries.mHash.pHeap,
    &key,
    pNode->HashFlags & 0xFFFFFF ^ (4 * (HIDWORD(v9[1].pNext->pPrevRoot) & 0xFFFFFFu)) ^ (unsigned __int64)(unsigned int)((int)(LODWORD(v9[1].vfptr) << 28) >> 28));
  v4 = v9;
  if ( v9 )
  {
    if ( ((unsigned __int8)v9 & 1) != 0 )
    {
      v9 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v9 - 1);
    }
    else
    {
      RefCount = v9->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v9->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
  }
  v6 = pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
}

// File Line: 252
// RVA: 0x812450
void __fastcall Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::RemoveValue(
        Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *const *v)
{
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *v2; // r10
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  unsigned __int64 v6; // rax
  unsigned __int64 SizeMask; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> >::TableType *v8; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> >::TableType *v9; // r9
  unsigned __int64 v10; // r8
  unsigned __int64 *v11; // rdx

  v2 = 0i64;
  pTable = this->Entries.mHash.pTable;
  v6 = 0i64;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v8 = pTable + 1;
    do
    {
      if ( v8->EntryCount != -2i64 )
        break;
      ++v6;
      v8 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> >::TableType *)((char *)v8 + 40);
    }
    while ( v6 <= SizeMask );
    v2 = this;
  }
  while ( v2 )
  {
    v9 = v2->Entries.mHash.pTable;
    if ( !v2->Entries.mHash.pTable )
      break;
    v10 = v9->SizeMask;
    if ( (__int64)v6 > (__int64)v10 )
      break;
    if ( (Scaleform::GFx::AS3::ClassTraits::Traits *const)*(&v9[3].EntryCount + 5 * v6) == *v )
    {
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key>(
        &this->Entries.mHash,
        (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)(&v9[2 * v6 + 2].EntryCount
                                                                                                  + v6));
      return;
    }
    if ( ++v6 <= v10 )
    {
      v11 = &v9[2 * v6 + 1].EntryCount + v6;
      do
      {
        if ( *v11 != -2i64 )
          break;
        ++v6;
        v11 += 5;
      }
      while ( v6 <= v10 );
    }
  }
}

// File Line: 305
// RVA: 0x785810
void __fastcall Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::~AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>(
        Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340> *this)
{
  __1__HashSetBase_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12_UNodeAltHashF_12_U__AllocatorLH_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___0BFE__2_V__HashsetCachedNodeEntry_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12__2__Scaleform__QEAA_XZ(&this->Entries.mHash);
  __1__HashSetBase_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12_UNodeAltHashF_12_U__AllocatorLH_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___0BFE__2_V__HashsetCachedNodeEntry_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12__2__Scaleform__QEAA_XZ(&this->Entries.mHash);
}

// File Line: 312
// RVA: 0x7E4070
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *__fastcall Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Get(
        Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340> *this,
        __int64 ind,
        int next_ind)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeHashF> >::TableType *pTable; // r9
  __int64 v4; // r11
  __int64 v6; // rcx
  __int64 v7; // r8
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // r8
  __int64 v11; // rdx
  __int64 v12; // rcx
  bool v13; // zf
  unsigned __int64 *v14; // rcx
  unsigned __int64 *v15; // rax
  char v17; // [rsp+1h] [rbp-19h]
  __int64 v18; // [rsp+2h] [rbp-18h]
  __int64 v19; // [rsp+Ah] [rbp-10h]

  pTable = this->Entries.mHash.pTable;
  v4 = next_ind;
  v18 = ind;
  v19 = next_ind;
  if ( !pTable )
    return 0i64;
  v6 = 5381i64;
  v7 = 16i64;
  do
  {
    v8 = (unsigned __int8)*(&v17 + v7--);
    v9 = 65599 * v6 + v8;
    v6 = v9;
  }
  while ( v7 );
  v10 = v9 & pTable->SizeMask;
  v11 = v10;
  v12 = v10 + 4 * v10 + 2;
  v13 = *(&pTable->EntryCount + v12) == -2i64;
  v14 = &pTable->EntryCount + v12;
  if ( v13 || v14[1] != v10 )
    return 0i64;
  while ( v14[1] != v10 || v14[2] != ind || v14[3] != v4 )
  {
    v11 = *v14;
    if ( *v14 == -1i64 )
      return 0i64;
    v14 = &pTable[2 * v11 + 1].EntryCount + v11;
  }
  if ( v11 >= 0 && (v15 = &pTable[2 * v11 + 2].EntryCount + v11) != 0i64 )
    return (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *)(v15 + 2);
  else
    return 0i64;
}

// File Line: 342
// RVA: 0x7D50E0
void __fastcall Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::ForEachChild_GC(
        Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340> *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, __int64, void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **), Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340> *))
{
  Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340> *v3; // r9
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeHashF> >::TableType *pTable; // rcx
  unsigned __int64 v5; // rax
  unsigned __int64 SizeMask; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeHashF> >::TableType *v9; // rcx
  signed __int64 v10; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeHashF> >::TableType *v11; // rcx
  __int64 v12; // rdx
  bool v13; // zf
  __int64 v14; // rdx
  unsigned __int64 v15; // rcx
  unsigned __int64 *v16; // rax
  Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340> *v17; // [rsp+20h] [rbp-18h]

  v3 = this;
  pTable = this->Entries.mHash.pTable;
  v5 = 0i64;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v9 = pTable + 1;
    do
    {
      if ( v9->EntryCount != -2i64 )
        break;
      ++v5;
      v9 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeHashF> >::TableType *)((char *)v9 + 40);
    }
    while ( v5 <= SizeMask );
    v17 = v3;
  }
  else
  {
    v17 = 0i64;
  }
  v10 = v5;
  while ( v17 )
  {
    v11 = v17->Entries.mHash.pTable;
    if ( !v17->Entries.mHash.pTable || v10 > (signed __int64)v11->SizeMask )
      break;
    v12 = v10 + 4 * v10 + 6;
    v13 = *(&v11->EntryCount + v12) == 0;
    v14 = (__int64)v11 + 8 * v12;
    if ( !v13 )
      op(
        prcc,
        v14,
        (void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))op,
        v3);
    v15 = v17->Entries.mHash.pTable->SizeMask;
    if ( v10 <= (__int64)v15 && ++v10 <= v15 )
    {
      v16 = &v17->Entries.mHash.pTable[2 * v10 + 1].EntryCount + v10;
      do
      {
        if ( *v16 != -2i64 )
          break;
        ++v10;
        v16 += 5;
      }
      while ( v10 <= v15 );
    }
  }
}

// File Line: 1680
// RVA: 0x80FB70
void __fastcall Scaleform::GFx::AS3::VM::RegisterGlobalObject(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Instances::fl::GlobalObject *go)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl::GlobalObject *,2,Scaleform::ArrayDefaultPolicy> *p_GlobalObjects; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // r8
  Scaleform::GFx::AS3::Instances::fl::GlobalObject **Data; // rcx
  Scaleform::GFx::AS3::Instances::fl::GlobalObject **v8; // rcx

  p_GlobalObjects = &this->GlobalObjects;
  Size = this->GlobalObjects.Data.Size;
  v5 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v5 <= this->GlobalObjects.Data.Policy.Capacity )
      goto LABEL_7;
    v6 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= this->GlobalObjects.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v6 = Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->GlobalObjects,
    &this->GlobalObjects,
    v6);
LABEL_7:
  Data = p_GlobalObjects->Data.Data;
  p_GlobalObjects->Data.Size = v5;
  v8 = &Data[v5 - 1];
  if ( v8 )
    *v8 = go;
}

// File Line: 2324
// RVA: 0x805C40
void __fastcall Scaleform::GFx::AS3::VM::OutputAndIgnoreException(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *p_ExceptionObj; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx

  p_ExceptionObj = &this->ExceptionObj;
  this->HandleException = 0;
  Scaleform::GFx::AS3::VM::OutputError(this, &this->ExceptionObj);
  if ( (p_ExceptionObj->Flags & 0x1F) <= 9 )
    goto LABEL_7;
  if ( (p_ExceptionObj->Flags & 0x200) == 0 )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(p_ExceptionObj);
LABEL_7:
    p_ExceptionObj->Flags &= 0xFFFFFFE0;
    return;
  }
  pWeakProxy = p_ExceptionObj->Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  p_ExceptionObj->Flags &= 0xFFFFFDE0;
  p_ExceptionObj->Bonus.pWeakProxy = 0i64;
  p_ExceptionObj->value.VS._1.VStr = 0i64;
  p_ExceptionObj->value.VS._2.VObj = 0i64;
}

// File Line: 2335
// RVA: 0x7FEFB0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__fastcall Scaleform::GFx::AS3::VM::MakeNamespace(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind)
{
  Scaleform::GFx::ASString *v6; // rbp
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+50h] [rbp+8h] BYREF

  v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
         this->StringManagerRef,
         &resulta);
  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
    (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)this->TraitsNamespace.pObject->ITraits.pObject,
    result,
    kind,
    v6,
    &v);
  pNode = resulta.pNode;
  if ( resulta.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return result;
}

// File Line: 2427
// RVA: 0x7BE4A0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::VM::CreateObject(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const char *gname,
        Scaleform::GFx::AS3::VMAppDomain *appDomain,
        Scaleform::GFx::AS3::Value *resulta,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  bool v9; // al

  v9 = Scaleform::GFx::AS3::VM::Construct(this, gname, appDomain, resulta, argc, argv, 0);
  if ( this->HandleException )
  {
    result->Result = 0;
    return result;
  }
  else
  {
    if ( v9 )
      Scaleform::GFx::AS3::VM::ExecuteCode(this, 1u);
    result->Result = !this->HandleException;
    return result;
  }
}

// File Line: 2446
// RVA: 0x76C260
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *pobj,
        const char *gname,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM::constructBuiltinObject(this, result, pobj, gname, argc, argv);
  return result;
}

// File Line: 2457
// RVA: 0x7B97A0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::VM::ConstructBuiltinValue(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *v,
        const char *gname,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v9; // ecx

  Scaleform::GFx::AS3::VM::Construct(this, gname, this->CurrentDomain.pObject, v, argc, argv, 1);
  if ( this->HandleException || (v9 = v->Flags & 0x1F) == 0 || (v9 - 12 <= 3 || v9 == 10) && !v->value.VS._1.VStr )
  {
    result->Result = 0;
    return result;
  }
  else
  {
    result->Result = 1;
    return result;
  }
}

// File Line: 2547
// RVA: 0x7CAEF0
void __fastcall Scaleform::GFx::AS3::VM::ExecuteAndRetrieveResult(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value *pCurrent; // rcx

  if ( !this->HandleException )
  {
    Scaleform::GFx::AS3::VM::ExecuteCode(this, 1u);
    if ( !this->HandleException )
    {
      if ( (result->Flags & 0x1F) > 9 )
      {
        if ( (result->Flags & 0x200) != 0 )
        {
          pWeakProxy = result->Bonus.pWeakProxy;
          if ( pWeakProxy->RefCount-- == 1 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          result->Flags &= 0xFFFFFDE0;
          result->Bonus.pWeakProxy = 0i64;
          result->value.VS._1.VStr = 0i64;
          result->value.VS._2.VObj = 0i64;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(result);
        }
      }
      pCurrent = this->OpStack.pCurrent;
      result->Flags = pCurrent->Flags;
      result->Bonus.pWeakProxy = pCurrent->Bonus.pWeakProxy;
      result->value.VS._1.VStr = pCurrent->value.VS._1.VStr;
      result->value.VS._2.VObj = pCurrent->value.VS._2.VObj;
      --this->OpStack.pCurrent;
    }
  }
}

// File Line: 2637
// RVA: 0x78AEA0
void __fastcall Scaleform::GFx::AS3::VM::GCGuard::~GCGuard(Scaleform::GFx::AS3::VM::GCGuard *this)
{
  Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(this->GC, 0i64, 1u);
}

// File Line: 2820
// RVA: 0x78BFA0
void __fastcall Scaleform::GFx::AS3::InitializerGuard::~InitializerGuard(Scaleform::GFx::AS3::InitializerGuard *this)
{
  --this->Resource->InInitializer;
}

// File Line: 2868
// RVA: 0x7E4A20
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Object::GetASString(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::ASString *result,
        Scaleform::String *str)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    this->pTraits.pObject->pVM->StringManagerRef,
    result,
    str);
  return result;
}

// File Line: 2902
// RVA: 0x7AC790
void __fastcall Scaleform::GFx::AS3::Object::AddDynamicFunc(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::ThunkInfo *func)
{
  Scaleform::GFx::ASString *ConstString; // rax
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf
  Scaleform::GFx::ASStringNode *v6; // rcx
  int v7; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+30h] [rbp-48h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::Value v10; // [rsp+48h] [rbp-30h] BYREF
  Scaleform::GFx::ASStringNode *v11; // [rsp+80h] [rbp+8h] BYREF

  v10.Flags = 5;
  v10.Bonus.pWeakProxy = 0i64;
  v10.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)func;
  ConstString = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                  this->pTraits.pObject->pVM->StringManagerRef,
                  (Scaleform::GFx::ASString *)&v11,
                  func->Name);
  v7 = 1;
  pNode = ConstString->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v7;
  key.pSecond = &v10;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    &this->DynAttrs.mHash,
    &this->DynAttrs,
    &key);
  v4 = pNode;
  v5 = pNode->RefCount-- == 1;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v6 = v11;
  v5 = v11->RefCount-- == 1;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  if ( (v10.Flags & 0x1F) > 9 )
  {
    if ( (v10.Flags & 0x200) != 0 )
    {
      v5 = v10.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v5 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v10.Bonus, 0, 24);
      v10.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
    }
  }
}

// File Line: 2950
// RVA: 0x7D3F50
Scaleform::GFx::AS3::SlotInfo *__fastcall Scaleform::GFx::AS3::Traits::FindSlotInfo(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::File *pObject; // r9
  __int64 p_any_namespace; // r8
  Scaleform::GFx::AS3::VM *pVM; // rdi
  Scaleform::GFx::AS3::Abc::NamespaceKind v9; // ebx
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  Scaleform::GFx::ASString *InternedString; // rax
  unsigned __int64 FirstOwnSlotNum; // rdx
  Scaleform::GFx::AS3::SlotInfo *p_Value; // rbx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex ind; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::GFx::ASString v21; // [rsp+70h] [rbp+18h] BYREF

  pObject = file->File.pObject;
  if ( mn->Ind )
    p_any_namespace = (__int64)&pObject->Const_Pool.ConstNamespace.Data.Data[mn->Ind];
  else
    p_any_namespace = (__int64)&pObject->Const_Pool.any_namespace;
  pVM = this->pVM;
  v9 = *(_DWORD *)p_any_namespace;
  v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          pVM->StringManagerRef,
          &result,
          *(const char **)(p_any_namespace + 8),
          *(_QWORD *)(p_any_namespace + 16));
  InternedNamespace = Scaleform::GFx::AS3::VM::GetInternedNamespace(pVM, v9, v10);
  pNode = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  InternedString = Scaleform::GFx::AS3::VMFile::GetInternedString(file, &v21, mn->NameIndex);
  Scaleform::GFx::AS3::Slots::FindSlotInfoIndex(
    &this->Scaleform::GFx::AS3::Slots,
    &ind,
    InternedString,
    InternedNamespace);
  if ( ind.Index < 0 )
  {
    p_Value = 0i64;
  }
  else
  {
    FirstOwnSlotNum = this->FirstOwnSlotNum;
    if ( ind.Index >= FirstOwnSlotNum )
      p_Value = &this->VArray.Data.Data[LODWORD(ind.Index) - FirstOwnSlotNum].Value;
    else
      p_Value = Scaleform::GFx::AS3::Slots::GetSlotInfo(this->Parent, ind);
  }
  v17 = v21.pNode;
  v13 = v21.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  return p_Value;
}

