// File Line: 34
// RVA: 0x77AE30
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::AvmDisplayObj(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        Scaleform::GFx::DisplayObject *pdispObj)
{
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::GFx::AS3::VMAppDomain *vecDelDtor; // rax

  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObj::`vftable;
  this->pAS3CollectiblePtr.pObject = 0i64;
  this->pDispObj = pdispObj;
  this->pClassName = 0i64;
  ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))pdispObj->pASRoot->Scaleform::GFx::DisplayObjectBase::vfptr[4].__vecDelDtor)(pdispObj->pASRoot);
  vfptr = this->pDispObj->pASRoot[2].vfptr;
  if ( vfptr[30].__vecDelDtor && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    vecDelDtor = *(Scaleform::GFx::AS3::VMAppDomain **)(*(_QWORD *)(*((_QWORD *)vfptr[33].__vecDelDtor
                                                                    + (((unsigned __int64)vfptr[30].__vecDelDtor - 1) >> 6))
                                                                  + 136i64
                                                                  * ((LODWORD(vfptr[30].__vecDelDtor) - 1) & 0x3F)
                                                                  + 40)
                                                      + 48i64);
  else
    vecDelDtor = (Scaleform::GFx::AS3::VMAppDomain *)vfptr[52].__vecDelDtor;
  this->AppDomain = vecDelDtor;
  this->Flags = 0;
  Scaleform::GFx::DisplayObjectBase::BindAvmObj(pdispObj, this);
  this->pAS3RawPtr = 0i64;
}

// File Line: 40
// RVA: 0x789860
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // rcx
  unsigned int RefCount; // eax

  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObj::`vftable;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)this->pClassName);
  pObject = this->pAS3CollectiblePtr.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
}

// File Line: 59
// RVA: 0x810DA0
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::ReleaseAS3Obj(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // rcx
  unsigned int RefCount; // eax

  pObject = this->pAS3CollectiblePtr.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
      this->pAS3CollectiblePtr.pObject = 0i64;
      this->pAS3RawPtr = 0i64;
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
      this->pAS3CollectiblePtr.pObject = 0i64;
      this->pAS3RawPtr = 0i64;
    }
  }
  else
  {
    this->pAS3RawPtr = 0i64;
  }
}

// File Line: 78
// RVA: 0x8056C0
_BOOL8 __fastcall Scaleform::GFx::AS3::AvmDisplayObj::OnUnloading(Scaleform::GFx::AS3::AvmDisplayObj *this, bool m)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pObject; // rbx
  Scaleform::GFx::DisplayObject *pDispObj; // rdi
  Scaleform::GFx::ASMovieRootBase *pASRoot; // rbp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // r14
  __int64 v9; // rax
  unsigned __int64 *v10; // rax
  __int64 *v11; // rax
  __int64 v12; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v13; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v14; // rbx
  __int64 v15; // rax
  unsigned __int64 *v16; // rax
  __int64 *v17; // rax
  __int64 v18; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *inserted; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v20; // rbx
  Scaleform::RefCountNTSImpl *v21; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v22; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::Render::RenderBuffer *v26; // rcx

  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  if ( pAS3RawPtr )
  {
    pObject = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)pAS3RawPtr->pImpl.pObject;
    pDispObj = this->pDispObj;
    pASRoot = pDispObj->pASRoot;
    if ( pObject )
    {
      pTable = pObject[1].pTable;
      if ( pTable )
      {
        v9 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               pObject + 1,
               (Scaleform::GFx::ASString *)&pASRoot[15].RefCount,
               pTable->SizeMask & *(unsigned int *)(*(_QWORD *)&pASRoot[15].RefCount + 28i64));
        if ( v9 >= 0 )
        {
          v10 = &pTable[1].SizeMask + 3 * v9;
          if ( v10 )
          {
            v11 = (__int64 *)(v10 + 1);
            if ( v11 )
            {
              v12 = *v11;
              if ( v12 )
              {
                if ( *(_QWORD *)(v12 + 8) )
                  goto LABEL_20;
              }
            }
          }
        }
      }
    }
    if ( pObject )
    {
      v13 = pObject + 1;
      v14 = pObject[1].pTable;
      if ( v14 )
      {
        v15 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                v13,
                (Scaleform::GFx::ASString *)&pASRoot[15].pMovieImpl,
                v14->SizeMask & HIDWORD(pASRoot[15].pMovieImpl->pASMovieRoot.pObject));
        if ( v15 >= 0 )
        {
          v16 = &v14[1].SizeMask + 3 * v15;
          if ( v16 )
          {
            v17 = (__int64 *)(v16 + 1);
            if ( v17 )
            {
              v18 = *v17;
              if ( v18 )
              {
                if ( *(_QWORD *)(v18 + 8) )
                {
LABEL_20:
                  inserted = Scaleform::GFx::AS3::MovieRoot::InsertEmptyAction(
                               (Scaleform::GFx::AS3::MovieRoot *)pASRoot,
                               AL_EnterFrame);
                  v20 = inserted;
                  inserted->Type = Entry_Buffer;
                  if ( pDispObj )
                    ++pDispObj->RefCount;
                  v21 = inserted->pCharacter.pObject;
                  if ( v21 )
                    Scaleform::RefCountNTSImpl::Release(v21);
                  v20->pCharacter.pObject = pDispObj;
                  *(_QWORD *)&v20->mEventId.Id = 16777232i64;
                  v20->mEventId.KeyCode = 0;
                  v20->mEventId.AsciiCode = 0;
                  *(_DWORD *)&v20->mEventId.RollOverCnt = 65280;
                  v20->CFunction = 0i64;
                  v22 = v20->pAS3Obj.pObject;
                  if ( v22 )
                  {
                    if ( ((unsigned __int8)v22 & 1) != 0 )
                    {
                      v20->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v22 - 1);
                    }
                    else
                    {
                      RefCount = v22->RefCount;
                      if ( (RefCount & 0x3FFFFF) != 0 )
                      {
                        v22->RefCount = RefCount - 1;
                        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v22);
                      }
                    }
                    v20->pAS3Obj.pObject = 0i64;
                  }
                  if ( (v20->Function.Flags & 0x1F) > 9 )
                  {
                    if ( (v20->Function.Flags & 0x200) != 0 )
                    {
                      pWeakProxy = v20->Function.Bonus.pWeakProxy;
                      if ( pWeakProxy->RefCount-- == 1 )
                        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                      v20->Function.Flags &= 0xFFFFFDE0;
                      v20->Function.Bonus.pWeakProxy = 0i64;
                      v20->Function.value.VS._1.VStr = 0i64;
                      v20->Function.value.VS._2.VObj = 0i64;
                    }
                    else
                    {
                      Scaleform::GFx::AS3::Value::ReleaseInternal(&v20->Function);
                    }
                  }
                  v20->Function.Flags &= 0xFFFFFFE0;
                  v26 = (Scaleform::Render::RenderBuffer *)v20->pNLoadInitCL.pObject;
                  if ( v26 )
                    Scaleform::RefCountImpl::Release(v26);
                  v20->pNLoadInitCL.pObject = 0i64;
                  this->pDispObj->Depth = -2;
                  if ( Scaleform::GFx::AS3::AvmDisplayObj::IsStageAccessible(this) )
                    this->Flags |= 1u;
                }
              }
            }
          }
        }
      }
    }
  }
  return m;
}

// File Line: 121
// RVA: 0x803990
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::OnEventUnload(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::DisplayObject *pDispObj; // rdx
  Scaleform::GFx::AS3::AvmInteractiveObj *AvmParent; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // r14
  char v5; // r12
  char v6; // si
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::AS3::Value::V2U v8; // rdx
  Scaleform::GFx::AS3::GASRefCountBase *vecDelDtor; // rcx
  int v10; // r13d
  const char *pData; // rax
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::VM *vfptr; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // rax
  Scaleform::GFx::ASStringNode *v18; // rbx
  Scaleform::GFx::AS3::Value::V2U v19; // rdx
  Scaleform::GFx::AS3::GASRefCountBase *v20; // rcx
  int v21; // esi
  const char *v22; // rax
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *v26; // rbx
  Scaleform::GFx::AS3::Value *Null; // rax
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::AS3::Value v29; // [rsp+20h] [rbp-79h] BYREF
  Scaleform::GFx::AS3::Multiname v30; // [rsp+40h] [rbp-59h] BYREF
  Scaleform::GFx::AS3::Value v31; // [rsp+70h] [rbp-29h] BYREF
  Scaleform::GFx::ASString v32; // [rsp+90h] [rbp-9h] BYREF
  Scaleform::GFx::AS3::Value::V2U v33; // [rsp+98h] [rbp-1h]
  __int64 v34; // [rsp+A0h] [rbp+7h]
  char v35; // [rsp+100h] [rbp+67h] BYREF
  Scaleform::GFx::ASString v36; // [rsp+108h] [rbp+6Fh] BYREF
  Scaleform::GFx::ASString result; // [rsp+110h] [rbp+77h] BYREF
  Scaleform::GFx::AS3::AvmInteractiveObj *v38; // [rsp+118h] [rbp+7Fh]

  v34 = -2i64;
  pDispObj = this->pDispObj;
  if ( pDispObj->Depth < -1 )
  {
    if ( (pDispObj->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) != 0 )
      pDispObj->pParent = 0i64;
    this->pDispObj->Flags &= 0xEFEFu;
  }
  else
  {
    if ( (pDispObj->Flags & 2) == 0
      && (pDispObj->Flags & 1) != 0
      && Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Parent(this) )
    {
      AvmParent = Scaleform::GFx::AS3::AvmDisplayObj::GetAvmParent(this);
      v38 = AvmParent;
      pAS3RawPtr = AvmParent->pAS3RawPtr;
      if ( !pAS3RawPtr )
        pAS3RawPtr = AvmParent->pAS3CollectiblePtr.pObject;
      if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
      {
        pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
        if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
          pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
      }
      Scaleform::GFx::AS3::AvmDisplayObj::GetName((Scaleform::GFx::AS2::AvmCharacter *)this, &result);
      v31.Flags = 0;
      v31.Bonus.pWeakProxy = 0i64;
      v5 = 10;
      v6 = 10;
      v29.Flags = 10;
      v29.Bonus.pWeakProxy = 0i64;
      pNode = result.pNode;
      *(Scaleform::GFx::ASString *)&v29.value.VNumber = (Scaleform::GFx::ASString)result.pNode;
      if ( result.pNode == &result.pNode->pManager->NullStringNode )
      {
        pNode = 0i64;
        v29.value.VS._1.VStr = 0i64;
        v8.VObj = v33.VObj;
        v29.value.VS._2 = v33;
        v6 = 12;
        v29.Flags = 12;
      }
      else
      {
        ++result.pNode->RefCount;
        v8.VObj = (Scaleform::GFx::AS3::Object *)v29.value.VS._2;
      }
      vecDelDtor = (Scaleform::GFx::AS3::GASRefCountBase *)this->pDispObj->pASRoot[2].vfptr[53].__vecDelDtor;
      v30.Kind = MN_QName;
      v30.Obj.pObject = vecDelDtor;
      if ( vecDelDtor )
        vecDelDtor->RefCount = (vecDelDtor->RefCount + 1) & 0x8FBFFFFF;
      v30.Name.Flags = 0;
      v30.Name.Bonus.pWeakProxy = 0i64;
      v10 = v6 & 0x1F;
      if ( (unsigned int)(v10 - 12) <= 3
        && pNode
        && (pData = pNode[1].pData, *((_DWORD *)pData + 30) == 17)
        && (pData[112] & 0x20) == 0 )
      {
        Scaleform::GFx::AS3::Value::Assign(&v30.Name, (Scaleform::GFx::ASString *)&pNode[1].16);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v30.Obj,
          *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&pNode[1].RefCount);
        v30.Kind &= 0xFFFFFFF9;
      }
      else
      {
        _mm_prefetch((const char *)&v29, 2);
        *(_QWORD *)&v30.Name.Flags = *(_QWORD *)&v29.Flags;
        v30.Name.Bonus.pWeakProxy = 0i64;
        v30.Name.value.VS._1.VStr = pNode;
        v30.Name.value.VS._2 = v8;
        if ( (v6 & 0x1Fu) > 9 )
        {
          if ( v10 == 10 )
          {
            ++pNode->RefCount;
          }
          else if ( (v6 & 0x1Fu) <= 0xF )
          {
            if ( pNode )
              pNode->Size = (pNode->Size + 1) & 0x8FBFFFFF;
          }
          else if ( (v6 & 0x1Fu) <= 0x11 && v8.VObj )
          {
            v8.VObj->RefCount = (v8.VObj->RefCount + 1) & 0x8FBFFFFF;
          }
        }
        if ( (v30.Name.Flags & 0x1F) == 10 )
        {
          Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v30.Name, &v36);
          if ( v36.pNode->Size )
          {
            if ( *v36.pNode->pData == 64 )
            {
              v30.Kind |= 8u;
              v12 = Scaleform::GFx::ASString::Substring(&v36, &v32, 1, v36.pNode->Size);
              Scaleform::GFx::AS3::Value::Assign(&v30.Name, v12);
              v13 = v32.pNode;
              v14 = v32.pNode->RefCount-- == 1;
              if ( v14 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v13);
            }
          }
          v15 = v36.pNode;
          v14 = v36.pNode->RefCount-- == 1;
          if ( v14 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        }
      }
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))pAS3RawPtr->vfptr[1].~RefCountBaseGC<328>)(
        pAS3RawPtr,
        &v35,
        &v30,
        &v31);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v30);
      if ( (v6 & 0x1Fu) > 9 )
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v29);
      vfptr = (Scaleform::GFx::AS3::VM *)this->pDispObj->pASRoot[2].vfptr;
      if ( vfptr->HandleException )
        goto LABEL_74;
      if ( (v31.Flags & 0x1F) - 12 <= 3 )
      {
        pObject = this->pAS3RawPtr;
        if ( !pObject )
          pObject = this->pAS3CollectiblePtr.pObject;
        if ( ((unsigned __int8)pObject & 1) != 0 )
          pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
        if ( (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v31.value.VS._1.VStr == pObject )
        {
          v29.Flags = 10;
          v29.Bonus.pWeakProxy = 0i64;
          v18 = result.pNode;
          *(Scaleform::GFx::ASString *)&v29.value.VNumber = (Scaleform::GFx::ASString)result.pNode;
          if ( result.pNode == &result.pNode->pManager->NullStringNode )
          {
            v18 = 0i64;
            v29.value.VS._1.VStr = 0i64;
            v19.VObj = v33.VObj;
            v29.value.VS._2 = v33;
            v5 = 12;
            v29.Flags = 12;
          }
          else
          {
            ++result.pNode->RefCount;
            v19.VObj = (Scaleform::GFx::AS3::Object *)v29.value.VS._2;
          }
          v20 = (Scaleform::GFx::AS3::GASRefCountBase *)this->pDispObj->pASRoot[2].vfptr[53].__vecDelDtor;
          v30.Kind = MN_QName;
          v30.Obj.pObject = v20;
          if ( v20 )
            v20->RefCount = (v20->RefCount + 1) & 0x8FBFFFFF;
          v30.Name.Flags = 0;
          v30.Name.Bonus.pWeakProxy = 0i64;
          v21 = v5 & 0x1F;
          if ( (unsigned int)(v21 - 12) <= 3
            && v18
            && (v22 = v18[1].pData, *((_DWORD *)v22 + 30) == 17)
            && (v22[112] & 0x20) == 0 )
          {
            Scaleform::GFx::AS3::Value::Assign(&v30.Name, (Scaleform::GFx::ASString *)&v18[1].16);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v30.Obj,
              *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v18[1].RefCount);
            v30.Kind &= 0xFFFFFFF9;
          }
          else
          {
            _mm_prefetch((const char *)&v29, 2);
            *(_QWORD *)&v30.Name.Flags = *(_QWORD *)&v29.Flags;
            v30.Name.Bonus.pWeakProxy = 0i64;
            v30.Name.value.VS._1.VStr = v18;
            v30.Name.value.VS._2 = v19;
            if ( (v5 & 0x1Fu) > 9 )
            {
              if ( v21 == 10 )
              {
                ++v18->RefCount;
              }
              else if ( (v5 & 0x1Fu) <= 0xF )
              {
                if ( v18 )
                  v18->Size = (v18->Size + 1) & 0x8FBFFFFF;
              }
              else if ( (v5 & 0x1Fu) <= 0x11 && v19.VObj )
              {
                v19.VObj->RefCount = (v19.VObj->RefCount + 1) & 0x8FBFFFFF;
              }
            }
            if ( (v30.Name.Flags & 0x1F) == 10 )
            {
              Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v30.Name, &v36);
              if ( v36.pNode->Size )
              {
                if ( *v36.pNode->pData == 64 )
                {
                  v30.Kind |= 8u;
                  v23 = Scaleform::GFx::ASString::Substring(&v36, &v32, 1, v36.pNode->Size);
                  Scaleform::GFx::AS3::Value::Assign(&v30.Name, v23);
                  v24 = v32.pNode;
                  v14 = v32.pNode->RefCount-- == 1;
                  if ( v14 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
                }
              }
              v25 = v36.pNode;
              v14 = v36.pNode->RefCount-- == 1;
              if ( v14 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v25);
            }
          }
          v26 = pAS3RawPtr->vfptr;
          Null = Scaleform::GFx::AS3::Value::GetNull();
          ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))v26[1].ForEachChild_GC)(
            pAS3RawPtr,
            &v35,
            &v30,
            Null);
          Scaleform::GFx::AS3::Multiname::~Multiname(&v30);
          if ( (v5 & 0x1Fu) > 9 )
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v29);
          vfptr = (Scaleform::GFx::AS3::VM *)this->pDispObj->pASRoot[2].vfptr;
          if ( vfptr->HandleException )
          {
LABEL_74:
            Scaleform::GFx::AS3::VM::OutputAndIgnoreException(vfptr);
            v38->pDispObj->Flags |= 0x20u;
          }
        }
      }
      if ( (v31.Flags & 0x1F) > 9 )
      {
        if ( (v31.Flags & 0x200) != 0 )
        {
          v14 = v31.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v14 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v31.Bonus, 0, 24);
          v31.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v31);
        }
      }
      v28 = result.pNode;
      v14 = result.pNode->RefCount-- == 1;
      if ( v14 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v28);
    }
    Scaleform::GFx::AS3::AvmDisplayObj::OnDetachFromTimeline(this);
  }
}

// File Line: 181
// RVA: 0x80A470
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::PropagateEvent(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        Scaleform::GFx::AS3::Instances::fl_events::Event *evtProto,
        bool __formal)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // rbx
  Scaleform::GFx::DisplayObject *pDispObj; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v6; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v7; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *evt; // [rsp+40h] [rbp+8h] BYREF

  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_events::Event *, Scaleform::GFx::AS3::Instances::fl_events::Event **))evtProto->vfptr[7].~RefCountBaseGC<328>)(
    evtProto,
    &evt);
  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  if ( pAS3RawPtr )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&evt->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)pAS3RawPtr);
    pDispObj = this->pDispObj;
    v6 = evt;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&evt->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)pAS3RawPtr);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(pAS3RawPtr, v6, pDispObj);
  }
  v7 = evt;
  if ( evt )
  {
    if ( ((unsigned __int8)evt & 1) != 0 )
    {
      evt = (Scaleform::GFx::AS3::Instances::fl_events::Event *)((char *)evt - 1);
    }
    else
    {
      RefCount = evt->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        evt->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
      }
    }
  }
}

// File Line: 193
// RVA: 0x7E59B0
Scaleform::RefCountImplCoreVtbl *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetAVM(
        Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pDispObj->pASRoot->vfptr[4].__vecDelDtor)(this->pDispObj->pASRoot);
  return this->pDispObj->pASRoot[2].vfptr;
}

// File Line: 200
// RVA: 0x7D4320
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::FireEvent(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // rbx
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  char v8; // r15
  Scaleform::GFx::ASStringNode *v9; // r14
  Scaleform::GFx::AS3::Value::V2U v10; // r12
  Scaleform::GFx::AS3::Value::V1U v11; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *vecDelDtor; // rcx
  int v13; // r13d
  const char *pData; // rax
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASMovieRootBase *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v20; // rax
  Scaleform::GFx::DisplayObject *dispObject; // rax
  Scaleform::GFx::ASString *p_RefCount; // rdx
  Scaleform::GFx::ASMovieRootBase *v23; // r15
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v24; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v25; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // r14
  __int64 v27; // rax
  unsigned __int64 *v28; // rax
  char *v29; // rax
  Scaleform::GFx::ASStringNode *v30; // rcx
  unsigned int v31; // eax
  Scaleform::GFx::ASMovieRootBase *v32; // rcx
  Scaleform::GFx::ASStringNode *v33; // rcx
  unsigned int v34; // eax
  Scaleform::GFx::ASMovieRootBase *pASRoot; // r14
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int Size; // eax
  Scaleform::GFx::ASStringNode *v39; // rcx
  unsigned int v40; // eax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v41; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v42; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v43; // rax
  bool v44; // zf
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v45; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v46; // rax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value v48; // [rsp+30h] [rbp-79h] BYREF
  Scaleform::GFx::AS3::Value v49; // [rsp+50h] [rbp-59h] BYREF
  Scaleform::GFx::AS3::Multiname v50; // [rsp+70h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *AS3Parent; // [rsp+A0h] [rbp-9h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v52; // [rsp+A8h] [rbp-1h]
  Scaleform::GFx::AS3::Value::V2U v53; // [rsp+B0h] [rbp+7h]
  __int64 v54; // [rsp+B8h] [rbp+Fh]
  char v55; // [rsp+110h] [rbp+67h] BYREF
  Scaleform::GFx::ASString v56; // [rsp+118h] [rbp+6Fh] BYREF
  Scaleform::GFx::ASString result; // [rsp+120h] [rbp+77h] BYREF
  Scaleform::GFx::ASString v58; // [rsp+128h] [rbp+7Fh] BYREF

  v54 = -2i64;
  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  v52 = pAS3RawPtr;
  if ( pAS3RawPtr )
    pAS3RawPtr->RefCount = (pAS3RawPtr->RefCount + 1) & 0x8FBFFFFF;
  v4 = id->Id;
  if ( id->Id > 0x100000F )
  {
    switch ( v4 )
    {
      case 0x1000010u:
        this->pDispObj->Depth = 0;
        pASRoot = this->pDispObj->pASRoot;
        pObject = this->pAS3RawPtr;
        if ( !pObject )
          pObject = this->pAS3CollectiblePtr.pObject;
        if ( ((unsigned __int8)pObject & 1) != 0 )
          pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
        if ( pObject )
        {
          if ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(
                 pObject,
                 (Scaleform::GFx::ASString *)&pASRoot[15].RefCount,
                 0)
            && !Scaleform::GFx::AS3::AvmDisplayObj::GetAVM(this)->HandleException )
          {
            Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
              pObject,
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v56,
              (Scaleform::GFx::ASString *)&pASRoot[15].RefCount,
              1,
              0);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v56.pNode[1].Size,
              (Scaleform::GFx::AS3::Instances::fl::XMLList *)pObject);
            Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
              pObject,
              (Scaleform::GFx::AS3::Instances::fl_events::Event *)v56.pNode,
              this->pDispObj);
            pNode = v56.pNode;
            if ( v56.pNode )
            {
              if ( ((__int64)v56.pNode & 1) != 0 )
              {
                --v56.pNode;
              }
              else
              {
                Size = v56.pNode->Size;
                if ( (Size & 0x3FFFFF) != 0 )
                {
                  v56.pNode->Size = Size - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pNode);
                }
              }
            }
          }
        }
        if ( (this->Flags & 1) != 0 && !Scaleform::GFx::AS3::AvmDisplayObj::GetAVM(this)->HandleException )
        {
          Scaleform::GFx::AS3::MovieRoot::CreateEventObject(
            (Scaleform::GFx::AS3::MovieRoot *)this->pDispObj->pASRoot,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v56,
            (Scaleform::GFx::ASString *)&this->pDispObj->pASRoot[15].pMovieImpl,
            0,
            0);
          ((void (__fastcall *)(Scaleform::GFx::AS3::AvmDisplayObj *, Scaleform::GFx::ASStringNode *, _QWORD))this->vfptr[1].GetAbsolutePath)(
            this,
            v56.pNode,
            0i64);
          v39 = v56.pNode;
          if ( v56.pNode )
          {
            if ( ((__int64)v56.pNode & 1) != 0 )
            {
              --v56.pNode;
            }
            else
            {
              v40 = v56.pNode->Size;
              if ( (v40 & 0x3FFFFF) != 0 )
              {
                v56.pNode->Size = v40 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v39);
              }
            }
          }
        }
        ((void (__fastcall *)(Scaleform::GFx::DisplayObject *))this->pDispObj->vfptr[75].__vecDelDtor)(this->pDispObj);
        break;
      case 0x1000011u:
        if ( pAS3RawPtr )
        {
          v43 = pAS3RawPtr->pImpl.pObject;
          if ( v43 )
          {
            v44 = (v43->Flags & 2) == 0;
            goto LABEL_131;
          }
        }
        break;
      case 0x1000012u:
        if ( pAS3RawPtr )
        {
          v45 = pAS3RawPtr->pImpl.pObject;
          if ( v45 )
          {
            v44 = (v45->Flags & 4) == 0;
            goto LABEL_131;
          }
        }
        break;
      case 0x1000013u:
        if ( pAS3RawPtr )
        {
          v46 = pAS3RawPtr->pImpl.pObject;
          if ( v46 )
          {
            v44 = (v46->Flags & 8) == 0;
            goto LABEL_131;
          }
        }
        break;
      case 0x1000014u:
        v44 = pAS3RawPtr == 0i64;
LABEL_131:
        if ( !v44 )
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(pAS3RawPtr, id, this->pDispObj);
        break;
      case 0x1000015u:
        if ( pAS3RawPtr )
        {
          v41 = pAS3RawPtr->pImpl.pObject;
          if ( v41 )
          {
            if ( (v41->Flags & 0x20) != 0 )
            {
              dispObject = this->pDispObj;
              p_RefCount = (Scaleform::GFx::ASString *)&dispObject->pASRoot[16];
              goto LABEL_65;
            }
          }
        }
        break;
      case 0x1000016u:
        if ( pAS3RawPtr )
        {
          v42 = pAS3RawPtr->pImpl.pObject;
          if ( v42 )
          {
            if ( (v42->Flags & 0x40) != 0 )
            {
              dispObject = this->pDispObj;
              p_RefCount = (Scaleform::GFx::ASString *)&dispObject->pASRoot[16].RefCount;
              goto LABEL_65;
            }
          }
        }
        break;
      default:
        break;
    }
  }
  else if ( v4 == 16777231 )
  {
    v23 = this->pDispObj->pASRoot;
    v24 = this->pAS3RawPtr;
    if ( !v24 )
      v24 = this->pAS3CollectiblePtr.pObject;
    if ( ((unsigned __int8)v24 & 1) != 0 )
      v24 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v24 - 1);
    if ( v24 )
    {
      v25 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v24->pImpl.pObject;
      if ( v25 )
      {
        pTable = v25[1].pTable;
        if ( pTable )
        {
          v27 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                  v25 + 1,
                  (Scaleform::GFx::ASString *)&v23[14].AVMVersion,
                  *(unsigned int *)(*(_QWORD *)&v23[14].AVMVersion + 28i64) & pTable->SizeMask);
          if ( v27 >= 0 )
          {
            v28 = &pTable[1].SizeMask + 3 * v27;
            if ( v28 )
            {
              v29 = (char *)(v28 + 1);
              if ( v29 )
              {
                if ( *(_QWORD *)v29 )
                {
                  if ( *(_QWORD *)(*(_QWORD *)v29 + 8i64) )
                  {
                    if ( !Scaleform::GFx::AS3::AvmDisplayObj::GetAVM(this)->HandleException )
                    {
                      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
                        v24,
                        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v56,
                        (Scaleform::GFx::ASString *)&v23[14].AVMVersion,
                        1,
                        0);
                      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v56.pNode[1].Size,
                        (Scaleform::GFx::AS3::Instances::fl::XMLList *)v24);
                      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
                        v24,
                        (Scaleform::GFx::AS3::Instances::fl_events::Event *)v56.pNode,
                        this->pDispObj);
                      v30 = v56.pNode;
                      if ( v56.pNode )
                      {
                        if ( ((__int64)v56.pNode & 1) != 0 )
                        {
                          --v56.pNode;
                        }
                        else
                        {
                          v31 = v56.pNode->Size;
                          if ( (v31 & 0x3FFFFF) != 0 )
                          {
                            v56.pNode->Size = v31 - 1;
                            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v30);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if ( Scaleform::GFx::AS3::AvmDisplayObj::IsStageAccessible(this) )
    {
      ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pDispObj->pASRoot->vfptr[4].__vecDelDtor)(this->pDispObj->pASRoot);
      v32 = this->pDispObj->pASRoot;
      if ( !LOBYTE(v32[2].vfptr[21].__vecDelDtor) )
      {
        Scaleform::GFx::AS3::MovieRoot::CreateEventObject(
          (Scaleform::GFx::AS3::MovieRoot *)v32,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v56,
          (Scaleform::GFx::ASString *)&v32[15],
          0,
          0);
        ((void (__fastcall *)(Scaleform::GFx::AS3::AvmDisplayObj *, Scaleform::GFx::ASStringNode *, _QWORD))this->vfptr[1].GetAbsolutePath)(
          this,
          v56.pNode,
          0i64);
        v33 = v56.pNode;
        if ( v56.pNode )
        {
          if ( ((__int64)v56.pNode & 1) != 0 )
          {
            --v56.pNode;
          }
          else
          {
            v34 = v56.pNode->Size;
            if ( (v34 & 0x3FFFFF) != 0 )
            {
              v56.pNode->Size = v34 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v33);
            }
          }
        }
      }
    }
  }
  else
  {
    v5 = v4 - 1;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( v6 )
      {
        v7 = v6 - 510;
        if ( v7 )
        {
          if ( v7 == 261632 )
            Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(this, 1);
        }
        else if ( (this->pDispObj->Flags & 1) != 0 )
        {
          Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(this);
          if ( (this->pDispObj->Flags & 2) == 0 )
          {
            if ( Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Parent(this) )
            {
              Scaleform::GFx::AS3::AvmDisplayObj::GetName((Scaleform::GFx::AS2::AvmCharacter *)this, &result);
              v8 = 10;
              v48.Flags = 10;
              v48.Bonus.pWeakProxy = 0i64;
              v9 = result.pNode;
              *(Scaleform::GFx::ASString *)&v48.value.VNumber = (Scaleform::GFx::ASString)result.pNode;
              if ( result.pNode == &result.pNode->pManager->NullStringNode )
              {
                v9 = 0i64;
                v48.value.VS._1.VStr = 0i64;
                v10.VObj = v53.VObj;
                v48.value.VS._2 = v53;
                v8 = 12;
                v48.Flags = 12;
              }
              else
              {
                ++result.pNode->RefCount;
                v10.VObj = (Scaleform::GFx::AS3::Object *)v48.value.VS._2;
              }
              AS3Parent = Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Parent(this);
              v11 = (Scaleform::GFx::AS3::Value::V1U)this->pAS3RawPtr;
              if ( !v11.VStr )
                v11 = (Scaleform::GFx::AS3::Value::V1U)this->pAS3CollectiblePtr.pObject;
              if ( v11.VBool )
                --v11.VStr;
              v49.Flags = 12;
              v49.Bonus.pWeakProxy = 0i64;
              v49.value.VS._1 = v11;
              if ( v11.VStr )
                v11.VStr->Size = (v11.VStr->Size + 1) & 0x8FBFFFFF;
              vecDelDtor = (Scaleform::GFx::AS3::GASRefCountBase *)this->pDispObj->pASRoot[2].vfptr[53].__vecDelDtor;
              v50.Kind = MN_QName;
              v50.Obj.pObject = vecDelDtor;
              if ( vecDelDtor )
                vecDelDtor->RefCount = (vecDelDtor->RefCount + 1) & 0x8FBFFFFF;
              v50.Name.Flags = 0;
              v50.Name.Bonus.pWeakProxy = 0i64;
              v13 = v8 & 0x1F;
              if ( (unsigned int)(v13 - 12) <= 3
                && v9
                && (pData = v9[1].pData, *((_DWORD *)pData + 30) == 17)
                && (pData[112] & 0x20) == 0 )
              {
                Scaleform::GFx::AS3::Value::Assign(&v50.Name, (Scaleform::GFx::ASString *)&v9[1].16);
                Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                  (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v50.Obj,
                  *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v9[1].RefCount);
                v50.Kind &= 0xFFFFFFF9;
              }
              else
              {
                _mm_prefetch((const char *)&v48, 2);
                *(_QWORD *)&v50.Name.Flags = *(_QWORD *)&v48.Flags;
                v50.Name.Bonus.pWeakProxy = 0i64;
                v50.Name.value.VS._1.VStr = v9;
                v50.Name.value.VS._2 = v10;
                if ( (v8 & 0x1Fu) > 9 )
                {
                  if ( v13 == 10 )
                  {
                    ++v9->RefCount;
                  }
                  else if ( (v8 & 0x1Fu) <= 0xF )
                  {
                    if ( v9 )
                      v9->Size = (v9->Size + 1) & 0x8FBFFFFF;
                  }
                  else if ( (v8 & 0x1Fu) <= 0x11 && v10.VObj )
                  {
                    v10.VObj->RefCount = (v10.VObj->RefCount + 1) & 0x8FBFFFFF;
                  }
                }
                if ( (v50.Name.Flags & 0x1F) == 10 )
                {
                  Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v50.Name, &v56);
                  if ( v56.pNode->Size )
                  {
                    if ( *v56.pNode->pData == 64 )
                    {
                      v50.Kind |= 8u;
                      v15 = Scaleform::GFx::ASString::Substring(&v56, &v58, 1, v56.pNode->Size);
                      Scaleform::GFx::AS3::Value::Assign(&v50.Name, v15);
                      v16 = v58.pNode;
                      v44 = v58.pNode->RefCount-- == 1;
                      if ( v44 )
                        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
                    }
                  }
                  v17 = v56.pNode;
                  v44 = v56.pNode->RefCount-- == 1;
                  if ( v44 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
                }
              }
              ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))AS3Parent->vfptr[1].ForEachChild_GC)(
                AS3Parent,
                &v55,
                &v50,
                &v49);
              Scaleform::GFx::AS3::Multiname::~Multiname(&v50);
              if ( (v49.Flags & 0x1F) > 9 )
              {
                if ( (v49.Flags & 0x200) != 0 )
                {
                  v44 = v49.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v44 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                  memset(&v49.Bonus, 0, 24);
                  v49.Flags &= 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v49);
                }
              }
              if ( (v8 & 0x1Fu) > 9 )
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v48);
              v18 = this->pDispObj->pASRoot;
              if ( LOBYTE(v18[2].vfptr[21].__vecDelDtor) )
              {
                Scaleform::GFx::AS3::VM::OutputAndIgnoreException((Scaleform::GFx::AS3::VM *)v18[2].vfptr);
                this->pDispObj->pParent->Flags |= 0x20u;
              }
              v19 = result.pNode;
              v44 = result.pNode->RefCount-- == 1;
              if ( v44 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v19);
            }
          }
        }
      }
      else if ( pAS3RawPtr )
      {
        v20 = pAS3RawPtr->pImpl.pObject;
        if ( v20 )
        {
          if ( (v20->Flags & 1) != 0 )
          {
            dispObject = this->pDispObj;
            p_RefCount = (Scaleform::GFx::ASString *)&dispObject->pASRoot[15].AVMVersion;
LABEL_65:
            Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchToTarget(
              pAS3RawPtr,
              p_RefCount,
              (Scaleform::GFx::AS3::Instances::fl::XMLList *)pAS3RawPtr,
              0,
              dispObject);
          }
        }
      }
    }
    else
    {
      ((void (__fastcall *)(Scaleform::GFx::DisplayObject *))this->pDispObj->vfptr[73].__vecDelDtor)(this->pDispObj);
    }
  }
  if ( pAS3RawPtr )
  {
    if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    {
      v52 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
    }
    else
    {
      RefCount = pAS3RawPtr->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pAS3RawPtr->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pAS3RawPtr);
      }
    }
  }
}

// File Line: 363
// RVA: 0x802B40
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::OnAdded(Scaleform::GFx::AS3::AvmDisplayObj *this, bool byTimeline)
{
  Scaleform::GFx::DisplayObject *pDispObj; // rcx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rbp
  __int64 v6; // rdx
  char v7; // di
  Scaleform::GFx::DisplayObject *pParent; // rbx
  Scaleform::GFx::InteractiveObject *v9; // rbx
  bool v10; // dl
  unsigned int Flags; // ecx
  unsigned int v12; // ecx
  int v13; // eax
  Scaleform::GFx::ASMovieRootBase *pASRoot; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v18; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v19; // rcx
  unsigned int v20; // eax
  Scaleform::GFx::DisplayObject *v21; // rbp
  Scaleform::GFx::AS3::Instances::fl::Object *v22; // rcx
  unsigned int v23; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v24; // rcx
  unsigned int v25; // eax
  Scaleform::GFx::ASMovieRootBase *v26; // rcx
  __int64 v27; // r8
  Scaleform::GFx::AS3::Instances::fl_events::Event *v28; // rcx
  unsigned int v29; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> result; // [rsp+60h] [rbp+8h] BYREF

  pDispObj = this->pDispObj;
  pMovieImpl = pDispObj->pASRoot->pMovieImpl;
  if ( (pMovieImpl->Flags & 0x800) != 0 )
  {
    v7 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))pDispObj->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(pDispObj);
    if ( v7 )
    {
      pParent = this->pDispObj;
      if ( pParent )
      {
        while ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))pParent->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(pParent) )
        {
          pParent = pParent->pParent;
          if ( !pParent )
            goto LABEL_8;
        }
        v7 = 0;
      }
    }
LABEL_8:
    v9 = 0i64;
    if ( SLOBYTE(this->pDispObj->Flags) < 0 )
      v9 = (Scaleform::GFx::InteractiveObject *)this->pDispObj;
    if ( v9 )
    {
      v10 = !v7 && (pMovieImpl->Flags & 0x800) != 0;
      Flags = v9->Flags;
      if ( v10 != ((Flags & 8) != 0) )
      {
        if ( v10 )
          v12 = Flags | 8;
        else
          v12 = Flags & 0xFFFFFFF7;
        v9->Flags = v12;
        if ( (v12 & 0x200000) == 0 || (v12 & 0x400000) != 0 )
          v6 = 0i64;
        else
          LOBYTE(v6) = 1;
        v13 = (int)v9->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[103].__vecDelDtor(
                     v9,
                     v6);
        if ( v13 == -1 )
        {
          v9->Flags |= 0x400000u;
        }
        else if ( v13 == 1 )
        {
          Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v9);
        }
        ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v9->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[104].__vecDelDtor)(v9);
      }
    }
  }
  pASRoot = this->pDispObj->pASRoot;
  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  if ( pAS3RawPtr != this->pAS3CollectiblePtr.pObject )
  {
    if ( pAS3RawPtr )
      pAS3RawPtr->RefCount = (pAS3RawPtr->RefCount + 1) & 0x8FBFFFFF;
    pObject = this->pAS3CollectiblePtr.pObject;
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    this->pAS3CollectiblePtr.pObject = pAS3RawPtr;
  }
  this->pAS3RawPtr = 0i64;
  if ( pAS3RawPtr )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
      pAS3RawPtr,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
      (Scaleform::GFx::ASString *)&pASRoot[14].AVMVersion,
      1,
      0);
    v18 = result.pObject;
    if ( pAS3RawPtr != result.pObject->Target.pObject )
    {
      pAS3RawPtr->RefCount = (pAS3RawPtr->RefCount + 1) & 0x8FBFFFFF;
      v19 = v18->Target.pObject;
      if ( v19 )
      {
        if ( ((unsigned __int8)v19 & 1) != 0 )
        {
          v18->Target.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v19 - 1);
        }
        else
        {
          v20 = v19->RefCount;
          if ( (v20 & 0x3FFFFF) != 0 )
          {
            v19->RefCount = v20 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v19);
          }
        }
      }
      v18->Target.pObject = pAS3RawPtr;
      v18 = result.pObject;
    }
    v21 = this->pDispObj;
    if ( pAS3RawPtr != v18->Target.pObject )
    {
      pAS3RawPtr->RefCount = (pAS3RawPtr->RefCount + 1) & 0x8FBFFFFF;
      v22 = v18->Target.pObject;
      if ( v22 )
      {
        if ( ((unsigned __int8)v22 & 1) != 0 )
        {
          v18->Target.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v22 - 1);
        }
        else
        {
          v23 = v22->RefCount;
          if ( (v23 & 0x3FFFFF) != 0 )
          {
            v22->RefCount = v23 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v22);
          }
        }
      }
      v18->Target.pObject = pAS3RawPtr;
    }
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(pAS3RawPtr, v18, v21);
    v24 = result.pObject;
    if ( result.pObject )
    {
      if ( ((__int64)result.pObject & 1) != 0 )
      {
        --result.pObject;
      }
      else
      {
        v25 = result.pObject->RefCount;
        if ( (v25 & 0x3FFFFF) != 0 )
        {
          result.pObject->RefCount = v25 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v24);
        }
      }
    }
  }
  if ( Scaleform::GFx::AS3::AvmDisplayObj::IsStageAccessible(this) )
  {
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pDispObj->pASRoot->vfptr[4].__vecDelDtor)(this->pDispObj->pASRoot);
    v26 = this->pDispObj->pASRoot;
    if ( !LOBYTE(v26[2].vfptr[21].__vecDelDtor) )
    {
      Scaleform::GFx::AS3::MovieRoot::CreateEventObject(
        (Scaleform::GFx::AS3::MovieRoot *)v26,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
        (Scaleform::GFx::ASString *)&v26[15],
        0,
        0);
      LOBYTE(v27) = !byTimeline;
      ((void (__fastcall *)(Scaleform::GFx::AS3::AvmDisplayObj *, Scaleform::GFx::AS3::Instances::fl_events::Event *, __int64))this->vfptr[1].GetAbsolutePath)(
        this,
        result.pObject,
        v27);
      v28 = result.pObject;
      if ( result.pObject )
      {
        if ( ((__int64)result.pObject & 1) != 0 )
        {
          --result.pObject;
        }
        else
        {
          v29 = result.pObject->RefCount;
          if ( (v29 & 0x3FFFFF) != 0 )
          {
            result.pObject->RefCount = v29 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v28);
          }
        }
      }
    }
  }
}

// File Line: 422
// RVA: 0x8053B0
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::OnRemoved(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        bool byTimeline)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // rbx
  Scaleform::GFx::DisplayObject *pDispObj; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v7; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASMovieRootBase *pASRoot; // rcx
  __int64 v10; // r8
  Scaleform::GFx::AS3::Instances::fl_events::Event *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> result; // [rsp+60h] [rbp+8h] BYREF

  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  if ( pAS3RawPtr )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
      pAS3RawPtr,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
      (Scaleform::GFx::ASString *)&this->pDispObj->pASRoot[15].RefCount,
      1,
      0);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)pAS3RawPtr);
    pDispObj = this->pDispObj;
    pObject = result.pObject;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)pAS3RawPtr);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(pAS3RawPtr, pObject, pDispObj);
    v7 = result.pObject;
    if ( result.pObject )
    {
      if ( ((__int64)result.pObject & 1) != 0 )
      {
        --result.pObject;
      }
      else
      {
        RefCount = result.pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          result.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
      }
    }
  }
  if ( Scaleform::GFx::AS3::AvmDisplayObj::IsStageAccessible(this) )
  {
    ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pDispObj->pASRoot->vfptr[4].__vecDelDtor)(this->pDispObj->pASRoot);
    pASRoot = this->pDispObj->pASRoot;
    if ( !LOBYTE(pASRoot[2].vfptr[21].__vecDelDtor) )
    {
      Scaleform::GFx::AS3::MovieRoot::CreateEventObject(
        (Scaleform::GFx::AS3::MovieRoot *)pASRoot,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
        (Scaleform::GFx::ASString *)&pASRoot[15].pMovieImpl,
        0,
        0);
      LOBYTE(v10) = !byTimeline;
      ((void (__fastcall *)(Scaleform::GFx::AS3::AvmDisplayObj *, Scaleform::GFx::AS3::Instances::fl_events::Event *, __int64))this->vfptr[1].GetAbsolutePath)(
        this,
        result.pObject,
        v10);
      v11 = result.pObject;
      if ( result.pObject )
      {
        if ( ((__int64)result.pObject & 1) != 0 )
        {
          --result.pObject;
        }
        else
        {
          v12 = result.pObject->RefCount;
          if ( (v12 & 0x3FFFFF) != 0 )
          {
            result.pObject->RefCount = v12 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
          }
        }
      }
    }
  }
  this->pAS3RawPtr = pAS3RawPtr;
  v13 = this->pAS3CollectiblePtr.pObject;
  if ( v13 )
  {
    if ( ((unsigned __int8)v13 & 1) != 0 )
    {
      this->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v13 - 1);
    }
    else
    {
      v14 = v13->RefCount;
      if ( (v14 & 0x3FFFFF) != 0 )
      {
        v13->RefCount = v14 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
      }
    }
    this->pAS3CollectiblePtr.pObject = 0i64;
  }
}

// File Line: 449
// RVA: 0x803170
char __fastcall Scaleform::GFx::AS3::AvmDisplayObj::OnEvent(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        Scaleform::GFx::EventId *id)
{
  unsigned int v2; // eax
  Scaleform::GFx::AS3::MovieRoot::ActionLevel v5; // edx
  Scaleform::GFx::DisplayObject *v6; // rdi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v7; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v8; // rsi
  Scaleform::RefCountNTSImpl *v9; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v10; // rcx
  unsigned int v11; // eax
  Scaleform::GFx::AS3::WeakProxy *v12; // rdx
  bool v13; // zf
  Scaleform::Render::RenderBuffer *v14; // rcx
  Scaleform::GFx::DisplayObject *pDispObj; // rsi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *inserted; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v18; // rbp
  Scaleform::RefCountNTSImpl *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v20; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::Render::RenderBuffer *v23; // rcx

  v2 = id->Id;
  if ( id->Id == 2 )
  {
    if ( (this->pAS3RawPtr || this->pAS3CollectiblePtr.pObject) && (this->Flags & 2) != 0 )
    {
      pDispObj = this->pDispObj;
      inserted = Scaleform::GFx::AS3::MovieRoot::InsertEmptyAction(
                   (Scaleform::GFx::AS3::MovieRoot *)pDispObj->pASRoot,
                   AL_EnterFrame);
      v18 = inserted;
      inserted->Type = Entry_Buffer;
      if ( pDispObj )
        ++pDispObj->RefCount;
      pObject = inserted->pCharacter.pObject;
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
      v18->pCharacter.pObject = pDispObj;
      v18->mEventId.Id = id->Id;
      v18->mEventId.WcharCode = id->WcharCode;
      v18->mEventId.KeyCode = id->KeyCode;
      v18->mEventId.AsciiCode = id->AsciiCode;
      v18->mEventId.RollOverCnt = id->RollOverCnt;
      v18->mEventId.ControllerIndex = id->ControllerIndex;
      v18->mEventId.KeysState.States = id->KeysState.States;
      v18->mEventId.MouseWheelDelta = id->MouseWheelDelta;
      v18->CFunction = 0i64;
      v20 = v18->pAS3Obj.pObject;
      if ( v20 )
      {
        if ( ((unsigned __int8)v20 & 1) != 0 )
        {
          v18->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v20 - 1);
        }
        else
        {
          RefCount = v20->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v20->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
          }
        }
        v18->pAS3Obj.pObject = 0i64;
      }
      if ( (v18->Function.Flags & 0x1F) > 9 )
      {
        if ( (v18->Function.Flags & 0x200) != 0 )
        {
          pWeakProxy = v18->Function.Bonus.pWeakProxy;
          v13 = pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          v18->Function.Flags &= 0xFFFFFDE0;
          v18->Function.Bonus.pWeakProxy = 0i64;
          v18->Function.value.VS._1.VStr = 0i64;
          v18->Function.value.VS._2.VObj = 0i64;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v18->Function);
        }
      }
      v18->Function.Flags &= 0xFFFFFFE0;
      v23 = (Scaleform::Render::RenderBuffer *)v18->pNLoadInitCL.pObject;
      if ( v23 )
        Scaleform::RefCountImpl::Release(v23);
      v18->pNLoadInitCL.pObject = 0i64;
    }
    this->Flags |= 2u;
    return 1;
  }
  if ( v2 == 16777235 )
  {
    if ( this->pAS3RawPtr || this->pAS3CollectiblePtr.pObject )
    {
      v5 = AL_Render;
      goto LABEL_7;
    }
    return 1;
  }
  if ( v2 - 16777237 > 1 )
    return 0;
  if ( !this->pAS3RawPtr && !this->pAS3CollectiblePtr.pObject )
    return 1;
  v5 = AL_Frame;
LABEL_7:
  v6 = this->pDispObj;
  v7 = Scaleform::GFx::AS3::MovieRoot::InsertEmptyAction((Scaleform::GFx::AS3::MovieRoot *)v6->pASRoot, v5);
  v8 = v7;
  v7->Type = Entry_Buffer;
  if ( v6 )
    ++v6->RefCount;
  v9 = v7->pCharacter.pObject;
  if ( v9 )
    Scaleform::RefCountNTSImpl::Release(v9);
  v8->pCharacter.pObject = v6;
  v8->mEventId.Id = id->Id;
  v8->mEventId.WcharCode = id->WcharCode;
  v8->mEventId.KeyCode = id->KeyCode;
  v8->mEventId.AsciiCode = id->AsciiCode;
  v8->mEventId.RollOverCnt = id->RollOverCnt;
  v8->mEventId.ControllerIndex = id->ControllerIndex;
  v8->mEventId.KeysState.States = id->KeysState.States;
  v8->mEventId.MouseWheelDelta = id->MouseWheelDelta;
  v8->CFunction = 0i64;
  v10 = v8->pAS3Obj.pObject;
  if ( v10 )
  {
    if ( ((unsigned __int8)v10 & 1) != 0 )
    {
      v8->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v10 - 1);
    }
    else
    {
      v11 = v10->RefCount;
      if ( (v11 & 0x3FFFFF) != 0 )
      {
        v10->RefCount = v11 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
      }
    }
    v8->pAS3Obj.pObject = 0i64;
  }
  if ( (v8->Function.Flags & 0x1F) > 9 )
  {
    if ( (v8->Function.Flags & 0x200) != 0 )
    {
      v12 = v8->Function.Bonus.pWeakProxy;
      v13 = v12->RefCount-- == 1;
      if ( v13 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v8->Function.Bonus.pWeakProxy = 0i64;
      v8->Function.value.VS._1.VStr = 0i64;
      v8->Function.value.VS._2.VObj = 0i64;
      v8->Function.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v8->Function);
    }
  }
  v8->Function.Flags &= 0xFFFFFFE0;
  v14 = (Scaleform::Render::RenderBuffer *)v8->pNLoadInitCL.pObject;
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  v8->pNLoadInitCL.pObject = 0i64;
  return 1;
}

// File Line: 493
// RVA: 0x802ED0
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::OnDetachFromTimeline(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // rcx
  unsigned int RefCount; // eax

  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  this->pAS3RawPtr = pAS3RawPtr;
  pObject = this->pAS3CollectiblePtr.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
      this->pAS3CollectiblePtr.pObject = 0i64;
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
      this->pAS3CollectiblePtr.pObject = 0i64;
    }
  }
}

// File Line: 501
// RVA: 0x7B19E0
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::AssignAS3Obj(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pas3obj)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // rcx
  unsigned int RefCount; // eax

  this->pAS3RawPtr = pas3obj;
  pObject = this->pAS3CollectiblePtr.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
      this->pAS3CollectiblePtr.pObject = 0i64;
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
      this->pAS3CollectiblePtr.pObject = 0i64;
    }
  }
}

// File Line: 515
// RVA: 0x7E5A70
const char *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetAbsolutePath(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        Scaleform::String *ppath)
{
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  pParent = this->pDispObj->pParent;
  if ( pParent )
  {
    Scaleform::GFx::DisplayObject::GetAbsolutePath(pParent, ppath);
    Scaleform::String::AppendString(ppath, ".", -1i64);
    Name = Scaleform::GFx::AS3::AvmDisplayObj::GetName((Scaleform::GFx::AS2::AvmCharacter *)this, &result);
    Scaleform::String::AppendString(ppath, Name->pNode->pData, -1i64);
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  return (const char *)((ppath->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
}

// File Line: 528
// RVA: 0x7E4900
Scaleform::GFx::AS3::MovieRoot *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Root(
        Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  return (Scaleform::GFx::AS3::MovieRoot *)this->pDispObj->pASRoot;
}

// File Line: 533
// RVA: 0x7E4940
Scaleform::String *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetASClassName(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        Scaleform::String *className)
{
  const char *pClassName; // rdx
  Scaleform::GFx::DisplayObject *pDispObj; // rcx
  Scaleform::GFx::MovieDefImpl *v6; // rax
  Scaleform::String *NameOfExportedResource; // rax
  Scaleform::GFx::ResourceId rid; // [rsp+30h] [rbp+8h] BYREF

  pClassName = this->pClassName;
  if ( pClassName )
    goto LABEL_4;
  pDispObj = this->pDispObj;
  rid.Id = pDispObj->Id.Id;
  v6 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))pDispObj->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(pDispObj);
  NameOfExportedResource = Scaleform::GFx::MovieDefImpl::GetNameOfExportedResource(v6, (Scaleform::GFx::ResourceId)&rid);
  if ( !NameOfExportedResource )
  {
    pClassName = (const char *)this->vfptr[1].ToAvmButttonBase(this);
LABEL_4:
    Scaleform::String::operator=(className, pClassName);
    return className;
  }
  Scaleform::String::operator=(className, NameOfExportedResource);
  return className;
}

// File Line: 553
// RVA: 0x7BB4B0
Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstance(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        bool execute)
{
  if ( this->pAS3RawPtr
    || this->pAS3CollectiblePtr.pObject
    || !Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(this) )
  {
    return 0i64;
  }
  else
  {
    return Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(this, execute);
  }
}

// File Line: 563
// RVA: 0x7BB500
char __fastcall Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::AS3::VM *vfptr; // rdi
  char v3; // bl
  Scaleform::GFx::AS3::Class *Class; // rax
  Scaleform::GFx::AS3::Class *v5; // r15
  Scaleform::GFx::AS3::Instances::fl::XMLList *VStr; // r13
  Scaleform::GFx::DisplayObject *pDispObj; // r14
  Scaleform::RefCountNTSImpl *Size; // rcx
  __int64 v9; // rdx
  bool v10; // zf
  char v11; // di
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::StringDataPtr gname; // [rsp+28h] [rbp-51h] BYREF
  Scaleform::GFx::AS3::Class *v16; // [rsp+38h] [rbp-41h]
  unsigned __int64 v17; // [rsp+40h] [rbp-39h]
  Scaleform::GFx::AS3::VM::Error v18; // [rsp+48h] [rbp-31h] BYREF
  Scaleform::GFx::AS3::Value v19; // [rsp+58h] [rbp-21h] BYREF
  Scaleform::GFx::AS3::Value v20; // [rsp+78h] [rbp-1h] BYREF
  char v21; // [rsp+E0h] [rbp+67h] BYREF
  Scaleform::String v22; // [rsp+E8h] [rbp+6Fh] BYREF

  if ( this->pAS3RawPtr )
    return 0;
  if ( this->pAS3CollectiblePtr.pObject )
    return 0;
  vfptr = (Scaleform::GFx::AS3::VM *)this->pDispObj->pASRoot[2].vfptr;
  if ( !vfptr )
    return 0;
  Scaleform::String::String(&v22);
  ((void (__fastcall *)(Scaleform::GFx::AS3::AvmDisplayObj *, Scaleform::String *))this->vfptr[1].ToAvmTextFieldBase)(
    this,
    &v22);
  v19.Flags = 0;
  v19.Bonus.pWeakProxy = 0i64;
  v3 = 0;
  v20.Flags = 0;
  v20.Bonus.pWeakProxy = 0i64;
  gname.pStr = (const char *)((v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  gname.Size = *(_QWORD *)(v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64;
  Class = Scaleform::GFx::AS3::VM::GetClass(vfptr, &gname, this->AppDomain);
  v5 = Class;
  if ( !Class )
  {
    if ( vfptr->HandleException )
      goto LABEL_17;
    Scaleform::GFx::AS3::VM::Error::Error(&v18, 1065, vfptr);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vfptr, v12, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    pNode = v18.Message.pNode;
    v10 = v18.Message.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v10 = !vfptr->HandleException;
LABEL_16:
    if ( v10 )
    {
LABEL_18:
      v11 = 0;
      goto LABEL_19;
    }
LABEL_17:
    Scaleform::GFx::AS3::VM::OutputAndIgnoreException(vfptr);
    this->pDispObj->Flags |= 0x20u;
    goto LABEL_18;
  }
  v3 = 13;
  v20.Flags = 13;
  v16 = Class;
  v20.value = (Scaleform::GFx::AS3::Value::VU)__PAIR128__(v17, (unsigned __int64)Class);
  Class->RefCount = (Class->RefCount + 1) & 0x8FBFFFFF;
  (*((void (__fastcall **)(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *))Class->pTraits.pObject[1].vfptr->ForEachChild_GC
   + 11))(
    Class->pTraits.pObject[1].vfptr,
    &v19,
    Class->pTraits.pObject[1].vfptr);
  VStr = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v19.value.VS._1.VStr;
  pDispObj = this->pDispObj;
  if ( pDispObj )
    ++pDispObj->RefCount;
  Size = (Scaleform::RefCountNTSImpl *)VStr->List.Data.Size;
  if ( Size )
    Scaleform::RefCountNTSImpl::Release(Size);
  VStr->List.Data.Size = (unsigned __int64)pDispObj;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->pAS3CollectiblePtr,
    VStr);
  this->pAS3RawPtr = 0i64;
  if ( !*(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Class *, char *, Scaleform::GFx::AS3::Value *))v5->vfptr[6].Finalize_GC)(
                    v5,
                    &v21,
                    &v19) )
  {
    v10 = !vfptr->HandleException;
    goto LABEL_16;
  }
  LOBYTE(v9) = 1;
  (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, __int64))v19.value.VS._1.VStr->pData + 13))(
    v19.value.VS._1,
    v9);
  v11 = 1;
LABEL_19:
  if ( (v3 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v20);
  if ( (v19.Flags & 0x1F) > 9 )
  {
    if ( (v19.Flags & 0x200) != 0 )
    {
      v10 = v19.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v19.Bonus, 0, 24);
      v19.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v19);
    }
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v11;
}

// File Line: 638
// RVA: 0x7B2DD0
Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        bool execute)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *result; // rax
  Scaleform::GFx::AS3::Traits *pObject; // rbx
  Scaleform::GFx::AS3::Class *v6; // r10
  Scaleform::GFx::AS3::Value::V1U pAS3RawPtr; // rax
  Scaleform::GFx::AS3::VM *vfptr; // rsi
  unsigned __int64 Size; // rbx
  unsigned int v10; // ebx
  Scaleform::GFx::AS3::Value v12; // [rsp+28h] [rbp-30h] BYREF

  result = this->pAS3RawPtr;
  if ( !result )
  {
    if ( !this->pAS3CollectiblePtr.pObject )
      return result;
    result = this->pAS3CollectiblePtr.pObject;
  }
  if ( ((unsigned __int8)result & 1) != 0 )
    result = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)result - 1);
  pObject = result->pTraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(pObject);
  v6 = pObject->pConstructor.pObject;
  pAS3RawPtr = (Scaleform::GFx::AS3::Value::V1U)this->pAS3RawPtr;
  if ( !pAS3RawPtr.VStr )
    pAS3RawPtr = (Scaleform::GFx::AS3::Value::V1U)this->pAS3CollectiblePtr.pObject;
  if ( pAS3RawPtr.VBool )
    --pAS3RawPtr.VStr;
  v12.Flags = 12;
  v12.Bonus.pWeakProxy = 0i64;
  v12.value.VS._1 = pAS3RawPtr;
  if ( pAS3RawPtr.VStr )
    pAS3RawPtr.VStr->Size = (pAS3RawPtr.VStr->Size + 1) & 0x8FBFFFFF;
  vfptr = (Scaleform::GFx::AS3::VM *)this->pDispObj->pASRoot[2].vfptr;
  if ( !vfptr )
    goto LABEL_20;
  Size = vfptr->CallStack.Size;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, _QWORD, _QWORD, __int64))v6->vfptr[7].ForEachChild_GC)(
    v6,
    &v12,
    0i64,
    0i64,
    -2i64);
  if ( vfptr->CallStack.Size <= Size )
    goto LABEL_20;
  if ( execute )
  {
    Scaleform::GFx::AS3::VM::ExecuteCode(vfptr, 1u);
    if ( vfptr->HandleException )
    {
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(vfptr);
      this->pDispObj->Flags |= 0x20u;
    }
LABEL_20:
    v10 = 0;
    goto LABEL_21;
  }
  v10 = 1;
LABEL_21:
  if ( (v12.Flags & 0x1F) > 9 )
  {
    if ( (v12.Flags & 0x200) != 0 )
    {
      if ( v12.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v12.Bonus, 0, 24);
      v12.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v12);
    }
  }
  return (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v10;
}

// File Line: 683
// RVA: 0x7EEF20
Scaleform::GFx::DisplayObject *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetRoot(
        Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::AS3::AvmDisplayObj *v1; // rdx
  bool v2; // zf
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // rcx
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  char *v6; // rcx
  __int64 v7; // rax

  v1 = this;
  v2 = this == 0i64;
  while ( !v2 )
  {
    pAS3RawPtr = v1->pAS3RawPtr;
    pObject = pAS3RawPtr;
    if ( !pAS3RawPtr )
      pObject = v1->pAS3CollectiblePtr.pObject;
    if ( ((unsigned __int8)pObject & 1) != 0 )
      pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
    if ( pObject )
    {
      if ( !pAS3RawPtr )
        pAS3RawPtr = v1->pAS3CollectiblePtr.pObject;
      if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
        pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
      if ( pAS3RawPtr->pLoaderInfo.pObject )
        return v1->pDispObj;
    }
    pParent = v1->pDispObj->pParent;
    if ( pParent
      && (v6 = (char *)pParent + 4 * (unsigned __int8)pParent->AvmObjOffset,
          (v7 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v6 + 8i64))(v6)) != 0) )
    {
      v1 = (Scaleform::GFx::AS3::AvmDisplayObj *)(v7 - 56);
      v2 = v7 == 56;
    }
    else
    {
      v1 = 0i64;
      v2 = 1;
    }
  }
  return 0i64;
}

// File Line: 703
// RVA: 0x7F91C0
char __fastcall Scaleform::GFx::AS3::AvmDisplayObj::IsStageAccessible(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::DisplayObject *pDispObj; // rdx
  char *v3; // rcx
  __int64 v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  char *v8; // rcx
  __int64 v9; // rax
  _QWORD *v10; // rbx
  __int64 v11; // rcx
  __int64 v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rcx
  __int64 v15; // rcx
  __int64 v16; // rax

  pDispObj = this->pDispObj;
  if ( SLOBYTE(pDispObj->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
  {
    if ( pDispObj
      && (v3 = (char *)pDispObj + 4 * (unsigned __int8)pDispObj->AvmObjOffset,
          (v4 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v3 + 8i64))(v3)) != 0) )
    {
      v5 = v4 - 56;
    }
    else
    {
      v5 = 0i64;
    }
    if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v5 + 176i64))(v5) )
      return 1;
  }
  pParent = this->pDispObj->pParent;
  if ( pParent
    && (v8 = (char *)pParent + 4 * (unsigned __int8)pParent->AvmObjOffset,
        (v9 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v8 + 8i64))(v8)) != 0) )
  {
    v10 = (_QWORD *)(v9 - 56);
  }
  else
  {
    v10 = 0i64;
  }
  if ( !v10 )
    return 0;
  while ( 1 )
  {
    v11 = *(_QWORD *)(v10[3] + 56i64);
    if ( !v11 )
      break;
    v12 = v11 + 4i64 * *(unsigned __int8 *)(v11 + 109);
    v13 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v12 + 8i64))(v12);
    if ( !v13 || v13 == 56 )
      break;
    v14 = *(_QWORD *)(v10[3] + 56i64);
    if ( v14
      && (v15 = v14 + 4i64 * *(unsigned __int8 *)(v14 + 109),
          (v16 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v15 + 8i64))(v15)) != 0) )
    {
      v10 = (_QWORD *)(v16 - 56);
    }
    else
    {
      v10 = 0i64;
    }
    if ( !v10 )
      return 0;
  }
  return (*(__int64 (__fastcall **)(_QWORD *))(*v10 + 176i64))(v10);
}

// File Line: 718
// RVA: 0x7E60B0
Scaleform::GFx::AS3::AvmInteractiveObj *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetAvmParent(
        Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  char *v2; // rcx
  __int64 v3; // rax

  pParent = this->pDispObj->pParent;
  if ( pParent
    && (v2 = (char *)pParent + 4 * (unsigned __int8)pParent->AvmObjOffset,
        (v3 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v2 + 8i64))(v2)) != 0) )
  {
    return (Scaleform::GFx::AS3::AvmInteractiveObj *)(v3 - 56);
  }
  else
  {
    return 0i64;
  }
}

// File Line: 723
// RVA: 0x7E4880
Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Parent(
        Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::InteractiveObject *pParent; // rdx
  char *v3; // rcx
  __int64 v4; // rax
  Scaleform::GFx::InteractiveObject *v5; // rcx
  char *v6; // rcx
  __int64 v7; // rax
  __int64 v8; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *result; // rax

  pParent = this->pDispObj->pParent;
  if ( !pParent )
    return 0i64;
  v3 = (char *)pParent + 4 * (unsigned __int8)pParent->AvmObjOffset;
  v4 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v3 + 8i64))(v3);
  if ( !v4 || v4 == 56 )
    return 0i64;
  v5 = this->pDispObj->pParent;
  if ( v5
    && (v6 = (char *)v5 + 4 * (unsigned __int8)v5->AvmObjOffset,
        (v7 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v6 + 8i64))(v6)) != 0) )
  {
    v8 = v7 - 56;
  }
  else
  {
    v8 = 0i64;
  }
  result = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v8 + 16);
  if ( !result )
    result = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v8 + 8);
  if ( ((unsigned __int8)result & 1) != 0 )
    return (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)result - 1);
  return result;
}

// File Line: 728
// RVA: 0x7F2C80
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::InitClassName(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        const char *className)
{
  __int64 v4; // rax
  size_t v6; // rdi
  void *v7; // rbx

  if ( !this->pClassName )
  {
    v4 = -1i64;
    while ( className[++v4] != 0 )
      ;
    v6 = v4 + 1;
    v7 = Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
           Scaleform::Memory::pGlobalHeap,
           this->pDispObj,
           v4 + 1,
           0i64);
    memmove(v7, className, v6);
    this->pClassName = (const char *)v7;
  }
}

// File Line: 739
// RVA: 0x818190
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::SetAppDomain(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
    this->AppDomain = appDomain;
}

// File Line: 750
// RVA: 0x7ED250
char __fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetObjectsUnderPoint(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2,Scaleform::ArrayDefaultPolicy> *destArray,
        Scaleform::Render::Point<float> *pt)
{
  Scaleform::Render::Point<float> *v3; // r9
  Scaleform::GFx::DisplayObject *pDispObj; // rbx
  Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase> *Data; // rax

  v3 = pt;
  LOBYTE(pt) = 1;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Point<float> *, Scaleform::Render::Point<float> *))this->pDispObj->vfptr[63].__vecDelDtor)(
          this->pDispObj,
          v3,
          pt) )
    return 0;
  pDispObj = this->pDispObj;
  if ( pDispObj )
    ++pDispObj->RefCount;
  Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &destArray->Data,
    destArray->Data.Size + 1);
  if ( destArray->Data.Size != 1 )
    memmove(&destArray->Data.Data[1], destArray->Data.Data, 8 * (destArray->Data.Size - 1));
  Data = destArray->Data.Data;
  if ( destArray->Data.Data )
  {
    if ( pDispObj )
      ++pDispObj->RefCount;
    Data->pObject = pDispObj;
  }
  if ( pDispObj )
    Scaleform::RefCountNTSImpl::Release(pDispObj);
  return 1;
}

// File Line: 791
// RVA: 0x781DC0
void __fastcall Scaleform::GFx::AS3::ShapeObject::ShapeObject(
        Scaleform::GFx::AS3::ShapeObject *this,
        Scaleform::GFx::ShapeBaseCharacterDef *pdef,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *pparent,
        _DWORD *id)
{
  LODWORD(id) = *id;
  Scaleform::GFx::DisplayObject::DisplayObject(this, pasRoot, pparent, (Scaleform::GFx::ResourceId)&id);
  Scaleform::GFx::AS3::AvmDisplayObj::AvmDisplayObj(&this->Scaleform::GFx::AS3::AvmDisplayObj, this);
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  this->Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable;
  if ( pdef )
    Scaleform::Render::RenderBuffer::AddRef(pdef);
  this->pDef.pObject = pdef;
  this->pDrawing.pObject = 0i64;
}

// File Line: 797
// RVA: 0x78DC40
void __fastcall Scaleform::GFx::AS3::ShapeObject::~ShapeObject(Scaleform::GFx::AS3::ShapeObject *this)
{
  Scaleform::GFx::DrawingContext *pObject; // rcx
  Scaleform::GFx::ShapeBaseCharacterDef *v3; // rcx

  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  this->Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable;
  this->AvmObjOffset = 0;
  pObject = this->pDrawing.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v3 = this->pDef.pObject;
  if ( v3 )
    Scaleform::GFx::Resource::Release(v3);
  Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj(&this->Scaleform::GFx::AS3::AvmDisplayObj);
  Scaleform::GFx::DisplayObject::~DisplayObject(this);
}

// File Line: 806
// RVA: 0x7E9250
Scaleform::GFx::DrawingContext *__fastcall Scaleform::GFx::AS3::ShapeObject::GetDrawingContext(
        Scaleform::GFx::AS3::ShapeObject *this)
{
  Scaleform::GFx::DisplayObject *Mask; // rax
  Scaleform::GFx::DisplayObject *v3; // rsi
  Scaleform::GFx::DrawingContext *DrawingContext; // rbx
  Scaleform::GFx::DrawingContext *pObject; // rcx
  Scaleform::Render::TreeContainer *v6; // rbx

  if ( this->pDrawing.pObject )
    return this->pDrawing.pObject;
  Mask = Scaleform::GFx::DisplayObject::GetMask(this);
  v3 = Mask;
  if ( Mask )
    ++Mask->RefCount;
  if ( Mask )
    Scaleform::GFx::DisplayObject::SetMask(this, 0i64, 1);
  DrawingContext = Scaleform::GFx::MovieImpl::CreateDrawingContext(this->pASRoot->pMovieImpl);
  pObject = this->pDrawing.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pDrawing.pObject = DrawingContext;
  v6 = Scaleform::GFx::DisplayObjectBase::ConvertToTreeContainer(this);
  Scaleform::Render::TreeContainer::Remove(v6, 0i64, 1ui64);
  Scaleform::Render::TreeContainer::Add(v6, this->pDrawing.pObject->pTreeContainer.pObject);
  if ( v3 )
    Scaleform::GFx::DisplayObject::SetMask(this, v3, 1);
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  return this->pDrawing.pObject;
}

// File Line: 833
// RVA: 0x7F0A40
__int64 __fastcall Scaleform::GFx::AS3::ShapeObject::GetTopMostMouseEntity(
        Scaleform::GFx::AS3::ShapeObject *this,
        Scaleform::Render::Point<float> *pt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  __int64 result; // rax
  Scaleform::GFx::InteractiveObject *TopMostMouseEntityDef; // rax
  bool v7; // zf
  Scaleform::Render::Point<float> p; // [rsp+40h] [rbp+8h] BYREF

  if ( this->pDrawing.pObject )
  {
    if ( Scaleform::GFx::DisplayObject::TransformPointToLocalAndCheckBounds(this, &p, pt, 1, 0i64)
      && Scaleform::GFx::DrawingContext::DefPointTestLocal(this->pDrawing.pObject, &p, 1, this) )
    {
      pdescr->pResult = this->pParent;
      return 1i64;
    }
  }
  else
  {
    TopMostMouseEntityDef = Scaleform::GFx::DisplayObjectBase::GetTopMostMouseEntityDef(
                              this,
                              this->pDef.pObject,
                              pt,
                              pdescr->TestAll,
                              pdescr->pIgnoreMC);
    pdescr->pResult = TopMostMouseEntityDef;
    v7 = TopMostMouseEntityDef == 0i64;
    result = 3i64;
    if ( !v7 )
      return result;
  }
  return 2i64;
}

// File Line: 858
// RVA: 0x807540
char __fastcall Scaleform::GFx::AS3::ShapeObject::PointTestLocal(
        Scaleform::GFx::AS3::ShapeObject *this,
        Scaleform::Render::Point<float> *pt,
        char hitTestMask)
{
  Scaleform::GFx::DrawingContext *pObject; // rcx

  pObject = this->pDrawing.pObject;
  if ( pObject && Scaleform::GFx::DrawingContext::DefPointTestLocal(pObject, pt, hitTestMask & 1, this) )
    return 1;
  else
    return ((__int64 (__fastcall *)(Scaleform::GFx::ShapeBaseCharacterDef *, Scaleform::Render::Point<float> *, _QWORD, Scaleform::GFx::AS3::ShapeObject *))this->pDef.pObject->vfptr[1].GetResourceTypeCode)(
             this->pDef.pObject,
             pt,
             hitTestMask & 1,
             this);
}

// File Line: 868
// RVA: 0x7E66E0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::AS3::ShapeObject::GetBounds(
        Scaleform::GFx::AS3::ShapeObject *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::GFx::DrawingContext *pObject; // rcx
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float x1; // xmm4_4
  float v11; // xmm2_4
  Scaleform::Render::Rect<float> *v12; // rax
  float v13; // xmm1_4
  float x2; // xmm0_4
  float y2; // xmm1_4
  Scaleform::GFx::ShapeBaseCharacterDef *v16; // rbx
  Scaleform::GFx::ResourceVtbl *vfptr; // rdi
  Scaleform::Render::Rect<float> *v18; // rax
  float y1; // xmm1_4
  Scaleform::Render::Rect<float> pr; // [rsp+20h] [rbp-28h] BYREF
  Scaleform::Render::Rect<float> pRect; // [rsp+30h] [rbp-18h] BYREF

  pObject = this->pDrawing.pObject;
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  if ( !pObject )
  {
    v16 = this->pDef.pObject;
    vfptr = v16->vfptr;
    ((void (__fastcall *)(Scaleform::GFx::AS3::ShapeObject *))this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[17].__vecDelDtor)(this);
    v18 = (Scaleform::Render::Rect<float> *)((__int64 (__fastcall *)(Scaleform::GFx::ShapeBaseCharacterDef *, Scaleform::Render::Rect<float> *))vfptr[1].GetResourceReport)(
                                              v16,
                                              &pr);
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, &pRect, v18);
    y1 = pRect.y1;
    result->x1 = pRect.x1;
    x2 = pRect.x2;
    result->y1 = y1;
    y2 = pRect.y2;
    goto LABEL_17;
  }
  pRect = 0i64;
  Scaleform::GFx::DrawingContext::ComputeBound(pObject, &pRect);
  if ( pRect.x1 >= pRect.x2 || pRect.y1 >= pRect.y2 )
    return result;
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, &pr, &pRect);
  v7 = result->x2;
  if ( result->x1 >= v7 || (v8 = result->y1, v9 = result->y2, v8 >= v9) )
  {
    v13 = pr.y1;
    result->x1 = pr.x1;
    x2 = pr.x2;
    result->y1 = v13;
    y2 = pr.y2;
LABEL_17:
    result->y2 = y2;
    result->x2 = x2;
    return result;
  }
  x1 = pr.x1;
  if ( result->x1 <= pr.x1 )
    x1 = result->x1;
  if ( v7 <= pr.x2 )
    v7 = pr.x2;
  v11 = pr.y1;
  if ( v8 <= pr.y1 )
    v11 = result->y1;
  if ( v9 <= pr.y2 )
    v9 = pr.y2;
  result->x1 = x1;
  result->y1 = v11;
  result->x2 = v7;
  v12 = result;
  result->y2 = v9;
  return v12;
}

// File Line: 891
// RVA: 0x7BE870
Scaleform::Ptr<Scaleform::Render::TreeNode> *__fastcall Scaleform::GFx::AS3::ShapeObject::CreateRenderNode(
        Scaleform::GFx::AS3::ShapeObject *this,
        Scaleform::Ptr<Scaleform::Render::TreeNode> *result,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::GFx::ShapeBaseCharacterDef *pObject; // rbx
  Scaleform::GFx::MovieDefImpl *v6; // rax

  pObject = this->pDef.pObject;
  v6 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::ShapeObject *))this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(this);
  Scaleform::GFx::ShapeBaseCharacterDef::CreateTreeShape(pObject, result, context, v6);
  return result;
}

