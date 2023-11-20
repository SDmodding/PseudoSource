// File Line: 34
// RVA: 0x77AE30
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::AvmDisplayObj(Scaleform::GFx::AS3::AvmDisplayObj *this, Scaleform::GFx::DisplayObject *pdispObj)
{
  Scaleform::GFx::DisplayObject *v2; // rdi
  Scaleform::GFx::AS3::AvmDisplayObj *v3; // rbx
  Scaleform::RefCountImplCoreVtbl *v4; // rax
  Scaleform::GFx::AS3::VMAppDomain *v5; // rax

  v2 = pdispObj;
  v3 = this;
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObj::`vftable';
  this->pAS3CollectiblePtr.pObject = 0i64;
  this->pDispObj = pdispObj;
  this->pClassName = 0i64;
  ((void (__cdecl *)(Scaleform::GFx::ASMovieRootBase *))pdispObj->pASRoot->vfptr[4].__vecDelDtor)(pdispObj->pASRoot);
  v4 = v3->pDispObj->pASRoot[2].vfptr;
  if ( v4[30].__vecDelDtor && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    v5 = *(Scaleform::GFx::AS3::VMAppDomain **)(*(_QWORD *)(*((_QWORD *)v4[33].__vecDelDtor
                                                            + (((unsigned __int64)v4[30].__vecDelDtor - 1) >> 6))
                                                          + 136i64 * ((LODWORD(v4[30].__vecDelDtor) - 1) & 0x3F)
                                                          + 40)
                                              + 48i64);
  else
    v5 = (Scaleform::GFx::AS3::VMAppDomain *)v4[52].__vecDelDtor;
  v3->AppDomain = v5;
  v3->Flags = 0;
  Scaleform::GFx::DisplayObjectBase::BindAvmObj(
    (Scaleform::GFx::DisplayObjectBase *)&v2->vfptr,
    (Scaleform::GFx::AvmDisplayObjBase *)&v3->vfptr);
  v3->pAS3RawPtr = 0i64;
}

// File Line: 40
// RVA: 0x789860
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::AS3::AvmDisplayObj *v1; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v2; // rcx
  unsigned int v3; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObj::`vftable';
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)this->pClassName);
  v2 = v1->pAS3CollectiblePtr.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v2 - 1);
    }
    else
    {
      v3 = v2->RefCount;
      if ( v3 & 0x3FFFFF )
      {
        v2->RefCount = v3 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
  }
  v1->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
}

// File Line: 59
// RVA: 0x810DA0
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::ReleaseAS3Obj(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::AS3::AvmDisplayObj *v1; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v2; // rcx
  unsigned int v3; // eax

  v1 = this;
  v2 = this->pAS3CollectiblePtr.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v2 - 1);
      v1->pAS3CollectiblePtr.pObject = 0i64;
      v1->pAS3RawPtr = 0i64;
    }
    else
    {
      v3 = v2->RefCount;
      if ( v3 & 0x3FFFFF )
      {
        v2->RefCount = v3 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
      v1->pAS3CollectiblePtr.pObject = 0i64;
      v1->pAS3RawPtr = 0i64;
    }
  }
  else
  {
    v1->pAS3RawPtr = 0i64;
  }
}

// File Line: 78
// RVA: 0x8056C0
_BOOL8 __fastcall Scaleform::GFx::AS3::AvmDisplayObj::OnUnloading(Scaleform::GFx::AS3::AvmDisplayObj *this, bool m)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v2; // rax
  bool v3; // r15
  Scaleform::GFx::AS3::AvmDisplayObj *v4; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v5; // rbx
  Scaleform::GFx::DisplayObject *v6; // rdi
  Scaleform::GFx::ASMovieRootBase *v7; // rbp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v8; // r14
  signed __int64 v9; // rax
  signed __int64 v10; // rax
  __int64 *v11; // rax
  __int64 v12; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v13; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v14; // rbx
  signed __int64 v15; // rax
  signed __int64 v16; // rax
  __int64 *v17; // rax
  __int64 v18; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v19; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v20; // rbx
  Scaleform::RefCountNTSImpl *v21; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v22; // rcx
  unsigned int v23; // eax
  Scaleform::GFx::AS3::WeakProxy *v24; // rdx
  bool v25; // zf
  Scaleform::Render::RenderBuffer *v26; // rcx

  v2 = this->pAS3RawPtr;
  v3 = m;
  v4 = this;
  if ( !v2 )
    v2 = this->pAS3CollectiblePtr.pObject;
  if ( (unsigned __int8)v2 & 1 )
    v2 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v2 - 1);
  if ( v2 )
  {
    v5 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v2->pImpl.pObject;
    v6 = this->pDispObj;
    v7 = v6->pASRoot;
    if ( v5 )
    {
      v8 = v5[1].pTable;
      if ( v8 )
      {
        v9 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               v5 + 1,
               (Scaleform::GFx::ASString *)&v7[15].RefCount,
               v8->SizeMask & *(unsigned int *)(*(_QWORD *)&v7[15].RefCount + 28i64));
        if ( v9 >= 0 )
        {
          v10 = (signed __int64)v8 + 8 * (3 * v9 + 3);
          if ( v10 )
          {
            v11 = (__int64 *)(v10 + 8);
            if ( v11 )
            {
              v12 = *v11;
              if ( v12 )
              {
                if ( *(_QWORD *)(v12 + 8) )
                  goto LABEL_43;
              }
            }
          }
        }
      }
    }
    if ( v5 )
    {
      v13 = v5 + 1;
      v14 = v5[1].pTable;
      if ( v14 )
      {
        v15 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                v13,
                (Scaleform::GFx::ASString *)&v7[15].pMovieImpl,
                v14->SizeMask & HIDWORD(v7[15].pMovieImpl->pASMovieRoot.pObject));
        if ( v15 >= 0 )
        {
          v16 = (signed __int64)v14 + 8 * (3 * v15 + 3);
          if ( v16 )
          {
            v17 = (__int64 *)(v16 + 8);
            if ( v17 )
            {
              v18 = *v17;
              if ( v18 )
              {
                if ( *(_QWORD *)(v18 + 8) )
                {
LABEL_43:
                  v19 = Scaleform::GFx::AS3::MovieRoot::InsertEmptyAction(
                          (Scaleform::GFx::AS3::MovieRoot *)v7,
                          AL_EnterFrame);
                  v20 = v19;
                  v19->Type = 1;
                  if ( v6 )
                    ++v6->RefCount;
                  v21 = (Scaleform::RefCountNTSImpl *)&v19->pCharacter.pObject->vfptr;
                  if ( v21 )
                    Scaleform::RefCountNTSImpl::Release(v21);
                  v20->pCharacter.pObject = v6;
                  *(_QWORD *)&v20->mEventId.Id = 16777232i64;
                  v20->mEventId.KeyCode = 0;
                  v20->mEventId.AsciiCode = 0;
                  *(_DWORD *)&v20->mEventId.RollOverCnt = 65280;
                  v20->CFunction = 0i64;
                  v22 = v20->pAS3Obj.pObject;
                  if ( v22 )
                  {
                    if ( (unsigned __int8)v22 & 1 )
                    {
                      v20->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v22 - 1);
                    }
                    else
                    {
                      v23 = v22->RefCount;
                      if ( v23 & 0x3FFFFF )
                      {
                        v22->RefCount = v23 - 1;
                        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v22->vfptr);
                      }
                    }
                    v20->pAS3Obj.pObject = 0i64;
                  }
                  if ( (v20->Function.Flags & 0x1F) > 9 )
                  {
                    if ( (v20->Function.Flags >> 9) & 1 )
                    {
                      v24 = v20->Function.Bonus.pWeakProxy;
                      v25 = v24->RefCount-- == 1;
                      if ( v25 )
                        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                      v20->Function.Flags &= 0xFFFFFDE0;
                      v20->Function.Bonus.pWeakProxy = 0i64;
                      v20->Function.value.VNumber = 0.0;
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
                  v4->pDispObj->Depth = -2;
                  if ( Scaleform::GFx::AS3::AvmDisplayObj::IsStageAccessible(v4) )
                    v4->Flags |= 1u;
                }
              }
            }
          }
        }
      }
    }
  }
  return v3;
}

// File Line: 121
// RVA: 0x803990
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::OnEventUnload(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::AS3::AvmDisplayObj *v1; // r15
  Scaleform::GFx::DisplayObject *v2; // rdx
  Scaleform::GFx::AS3::AvmInteractiveObj *v3; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // r14
  unsigned int v5; // er12
  unsigned int v6; // esi
  Scaleform::GFx::ASStringNode *v7; // rbx
  Scaleform::GFx::AS3::Value::V2U v8; // rdx
  Scaleform::GFx::AS3::GASRefCountBase *v9; // rcx
  int v10; // er13
  const char *v11; // rax
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::VM *v16; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rbx
  Scaleform::GFx::AS3::Value::V2U v19; // rdx
  Scaleform::GFx::AS3::GASRefCountBase *v20; // rcx
  int v21; // esi
  const char *v22; // rax
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *v26; // rbx
  Scaleform::GFx::AS3::Value *v27; // rax
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::AS3::Value v29; // [rsp+20h] [rbp-79h]
  Scaleform::GFx::AS3::Multiname v30; // [rsp+40h] [rbp-59h]
  Scaleform::GFx::AS3::Value v31; // [rsp+70h] [rbp-29h]
  Scaleform::GFx::ASString v32; // [rsp+90h] [rbp-9h]
  Scaleform::GFx::AS3::Value::V2U v33; // [rsp+98h] [rbp-1h]
  __int64 v34; // [rsp+A0h] [rbp+7h]
  char v35; // [rsp+100h] [rbp+67h]
  Scaleform::GFx::ASString v36; // [rsp+108h] [rbp+6Fh]
  Scaleform::GFx::ASString result; // [rsp+110h] [rbp+77h]
  Scaleform::GFx::AS3::AvmInteractiveObj *v38; // [rsp+118h] [rbp+7Fh]

  v34 = -2i64;
  v1 = this;
  v2 = this->pDispObj;
  if ( v2->Depth < -1 )
  {
    if ( (LOBYTE(v2->Flags) >> 4) & 1 )
      v2->pParent = 0i64;
    this->pDispObj->Flags &= 0xEFEFu;
  }
  else
  {
    if ( !((LOBYTE(v2->Flags) >> 1) & 1) && v2->Flags & 1 && Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Parent(this) )
    {
      v3 = Scaleform::GFx::AS3::AvmDisplayObj::GetAvmParent(v1);
      v38 = v3;
      v4 = v3->pAS3RawPtr;
      if ( !v4 )
        v4 = v3->pAS3CollectiblePtr.pObject;
      if ( (unsigned __int8)v4 & 1 )
      {
        v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v4 - 1);
        if ( (unsigned __int8)v4 & 1 )
          v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v4 - 1);
      }
      Scaleform::GFx::AS3::AvmDisplayObj::GetName((Scaleform::GFx::AS2::AvmCharacter *)v1, &result);
      v31.Flags = 0;
      v31.Bonus.pWeakProxy = 0i64;
      v5 = 10;
      v6 = 10;
      v29.Flags = 10;
      v29.Bonus.pWeakProxy = 0i64;
      v7 = result.pNode;
      *(Scaleform::GFx::ASString *)&v29.value.VNumber = result;
      if ( result.pNode == &result.pNode->pManager->NullStringNode )
      {
        v7 = 0i64;
        v29.value.VNumber = 0.0;
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
      v9 = (Scaleform::GFx::AS3::GASRefCountBase *)v1->pDispObj->pASRoot[2].vfptr[53].__vecDelDtor;
      v30.Kind = 0;
      v30.Obj.pObject = v9;
      if ( v9 )
        v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
      v30.Name.Flags = 0;
      v30.Name.Bonus.pWeakProxy = 0i64;
      v10 = v6 & 0x1F;
      if ( (unsigned int)(v10 - 12) <= 3
        && v7
        && (v11 = v7[1].pData, *((_DWORD *)v11 + 30) == 17)
        && ~((const unsigned __int8)v11[112] >> 5) & 1 )
      {
        Scaleform::GFx::AS3::Value::Assign(&v30.Name, (Scaleform::GFx::ASString *)&v7[1].16);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v30.Obj,
          *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v7[1].RefCount);
        v30.Kind &= 0xFFFFFFF9;
      }
      else
      {
        __asm { prefetcht1 byte ptr [rbp+57h+var_D0.Flags]; Prefetch to all cache levels }
        *(_QWORD *)&v30.Name.Flags = *(_QWORD *)&v29.Flags;
        v30.Name.Bonus.pWeakProxy = 0i64;
        *(_QWORD *)&v30.Name.value.VNumber = v7;
        v30.Name.value.VS._2 = v8;
        if ( v10 > 9 )
        {
          if ( (v6 >> 9) & 1 )
          {
            LODWORD(MEMORY[0]) = MEMORY[0] + 1;
          }
          else if ( v10 == 10 )
          {
            ++v7->RefCount;
          }
          else if ( v10 > 10 )
          {
            if ( v10 <= 15 )
            {
              if ( v7 )
                v7->Size = (v7->Size + 1) & 0x8FBFFFFF;
            }
            else if ( v10 <= 17 && v8.VObj )
            {
              v8.VObj->RefCount = (v8.VObj->RefCount + 1) & 0x8FBFFFFF;
            }
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
              v14 = v32.pNode->RefCount == 1;
              --v13->RefCount;
              if ( v14 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v13);
            }
          }
          v15 = v36.pNode;
          v14 = v36.pNode->RefCount == 1;
          --v15->RefCount;
          if ( v14 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        }
      }
      ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))v4->vfptr[1].~RefCountBaseGC<328>)(
        v4,
        &v35,
        &v30,
        &v31);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v30);
      if ( v10 > 9 )
      {
        if ( (v6 >> 9) & 1 )
        {
          LODWORD(MEMORY[0]) = MEMORY[0] - 1;
          if ( !(_DWORD)MEMORY[0] )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
          v29.Bonus.pWeakProxy = 0i64;
          v29.value = 0ui64;
          v29.Flags = v6 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v29);
        }
      }
      v16 = (Scaleform::GFx::AS3::VM *)v1->pDispObj->pASRoot[2].vfptr;
      if ( v16->HandleException )
        goto LABEL_103;
      if ( (v31.Flags & 0x1F) - 12 <= 3 )
      {
        v17 = v1->pAS3RawPtr;
        if ( !v17 )
          v17 = v1->pAS3CollectiblePtr.pObject;
        if ( (unsigned __int8)v17 & 1 )
          v17 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v17 - 1);
        if ( (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v31.value.VS._1.VStr == v17 )
        {
          v29.Flags = 10;
          v29.Bonus.pWeakProxy = 0i64;
          v18 = result.pNode;
          *(Scaleform::GFx::ASString *)&v29.value.VNumber = result;
          if ( result.pNode == &result.pNode->pManager->NullStringNode )
          {
            v18 = 0i64;
            v29.value.VNumber = 0.0;
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
          v20 = (Scaleform::GFx::AS3::GASRefCountBase *)v1->pDispObj->pASRoot[2].vfptr[53].__vecDelDtor;
          v30.Kind = 0;
          v30.Obj.pObject = v20;
          if ( v20 )
            v20->RefCount = (v20->RefCount + 1) & 0x8FBFFFFF;
          v30.Name.Flags = 0;
          v30.Name.Bonus.pWeakProxy = 0i64;
          v21 = v5 & 0x1F;
          if ( (unsigned int)(v21 - 12) <= 3
            && v18
            && (v22 = v18[1].pData, *((_DWORD *)v22 + 30) == 17)
            && ~((const unsigned __int8)v22[112] >> 5) & 1 )
          {
            Scaleform::GFx::AS3::Value::Assign(&v30.Name, (Scaleform::GFx::ASString *)&v18[1].16);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v30.Obj,
              *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v18[1].RefCount);
            v30.Kind &= 0xFFFFFFF9;
          }
          else
          {
            __asm { prefetcht1 byte ptr [rbp+57h+var_D0.Flags]; Prefetch to all cache levels }
            *(_QWORD *)&v30.Name.Flags = *(_QWORD *)&v29.Flags;
            v30.Name.Bonus.pWeakProxy = 0i64;
            *(_QWORD *)&v30.Name.value.VNumber = v18;
            v30.Name.value.VS._2 = v19;
            if ( v21 > 9 )
            {
              if ( (v5 >> 9) & 1 )
              {
                LODWORD(MEMORY[0]) = MEMORY[0] + 1;
              }
              else if ( v21 == 10 )
              {
                ++v18->RefCount;
              }
              else if ( v21 > 10 )
              {
                if ( v21 <= 15 )
                {
                  if ( v18 )
                    v18->Size = (v18->Size + 1) & 0x8FBFFFFF;
                }
                else if ( v21 <= 17 && v19.VObj )
                {
                  v19.VObj->RefCount = (v19.VObj->RefCount + 1) & 0x8FBFFFFF;
                }
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
                  v14 = v32.pNode->RefCount == 1;
                  --v24->RefCount;
                  if ( v14 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
                }
              }
              v25 = v36.pNode;
              v14 = v36.pNode->RefCount == 1;
              --v25->RefCount;
              if ( v14 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v25);
            }
          }
          v26 = v4->vfptr;
          v27 = Scaleform::GFx::AS3::Value::GetNull();
          ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))v26[1].ForEachChild_GC)(
            v4,
            &v35,
            &v30,
            v27);
          Scaleform::GFx::AS3::Multiname::~Multiname(&v30);
          if ( v21 > 9 )
          {
            if ( (v5 >> 9) & 1 )
            {
              LODWORD(MEMORY[0]) = MEMORY[0] - 1;
              if ( !(_DWORD)MEMORY[0] )
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
              v29.Bonus.pWeakProxy = 0i64;
              v29.value = 0ui64;
              v29.Flags = v5 & 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v29);
            }
          }
          v16 = (Scaleform::GFx::AS3::VM *)v1->pDispObj->pASRoot[2].vfptr;
          if ( v16->HandleException )
          {
LABEL_103:
            Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v16);
            v38->pDispObj->Flags |= 0x20u;
          }
        }
      }
      if ( (v31.Flags & 0x1F) > 9 )
      {
        if ( (v31.Flags >> 9) & 1 )
        {
          v14 = v31.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v14 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v31.Bonus.pWeakProxy = 0i64;
          v31.value = 0ui64;
          v31.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v31);
        }
      }
      v28 = result.pNode;
      v14 = result.pNode->RefCount == 1;
      --v28->RefCount;
      if ( v14 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v28);
    }
    Scaleform::GFx::AS3::AvmDisplayObj::OnDetachFromTimeline(v1);
  }
}

// File Line: 181
// RVA: 0x80A470
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::PropagateEvent(Scaleform::GFx::AS3::AvmDisplayObj *this, Scaleform::GFx::AS3::Instances::fl_events::Event *evtProto, bool __formal)
{
  Scaleform::GFx::AS3::AvmDisplayObj *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // rbx
  Scaleform::GFx::DisplayObject *v5; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v6; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v7; // rcx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *evt; // [rsp+40h] [rbp+8h]

  v3 = this;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_events::Event *, Scaleform::GFx::AS3::Instances::fl_events::Event **))evtProto->vfptr[7].~RefCountBaseGC<328>)(
    evtProto,
    &evt);
  v4 = v3->pAS3RawPtr;
  if ( !v4 )
    v4 = v3->pAS3CollectiblePtr.pObject;
  if ( (unsigned __int8)v4 & 1 )
    v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v4 - 1);
  if ( v4 )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&evt->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4);
    v5 = v3->pDispObj;
    v6 = evt;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&evt->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v4->vfptr,
      v6,
      v5);
  }
  v7 = evt;
  if ( evt )
  {
    if ( (unsigned __int8)evt & 1 )
    {
      evt = (Scaleform::GFx::AS3::Instances::fl_events::Event *)((char *)evt - 1);
    }
    else
    {
      v8 = evt->RefCount;
      if ( v8 & 0x3FFFFF )
      {
        evt->RefCount = v8 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v7->vfptr);
      }
    }
  }
}

// File Line: 193
// RVA: 0x7E59B0
Scaleform::RefCountImplCoreVtbl *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetAVM(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::AS3::AvmDisplayObj *v1; // rbx

  v1 = this;
  ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))this->pDispObj->pASRoot->vfptr[4].__vecDelDtor)(this->pDispObj->pASRoot);
  return v1->pDispObj->pASRoot[2].vfptr;
}

// File Line: 200
// RVA: 0x7D4320
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::FireEvent(Scaleform::GFx::AS3::AvmDisplayObj *this, Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::AS3::AvmDisplayObj *v2; // rsi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v3; // rbx
  unsigned int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  unsigned int v8; // er15
  Scaleform::GFx::ASStringNode *v9; // r14
  Scaleform::GFx::AS3::Value::V2U v10; // r12
  long double v11; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v12; // rcx
  int v13; // er13
  const char *v14; // rax
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASMovieRootBase *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v20; // rax
  Scaleform::GFx::DisplayObject *dispObject; // rax
  Scaleform::GFx::ASString *v22; // rdx
  Scaleform::GFx::ASMovieRootBase *v23; // r15
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v24; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v25; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v26; // r14
  signed __int64 v27; // rax
  signed __int64 v28; // rax
  signed __int64 v29; // rax
  Scaleform::GFx::ASStringNode *v30; // rcx
  unsigned int v31; // eax
  Scaleform::GFx::ASMovieRootBase *v32; // rcx
  Scaleform::GFx::ASStringNode *v33; // rcx
  unsigned int v34; // eax
  Scaleform::GFx::ASMovieRootBase *v35; // r14
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v36; // rdi
  Scaleform::GFx::ASStringNode *v37; // rcx
  unsigned int v38; // eax
  Scaleform::GFx::ASStringNode *v39; // rcx
  unsigned int v40; // eax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v41; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v42; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v43; // rax
  bool v44; // zf
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v45; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v46; // rax
  unsigned int v47; // eax
  Scaleform::GFx::AS3::Value v48; // [rsp+30h] [rbp-79h]
  Scaleform::GFx::AS3::Value v49; // [rsp+50h] [rbp-59h]
  Scaleform::GFx::AS3::Multiname v50; // [rsp+70h] [rbp-39h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v51; // [rsp+A0h] [rbp-9h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v52; // [rsp+A8h] [rbp-1h]
  Scaleform::GFx::AS3::Value::V2U v53; // [rsp+B0h] [rbp+7h]
  __int64 v54; // [rsp+B8h] [rbp+Fh]
  char v55; // [rsp+110h] [rbp+67h]
  Scaleform::GFx::ASString v56; // [rsp+118h] [rbp+6Fh]
  Scaleform::GFx::ASString result; // [rsp+120h] [rbp+77h]
  Scaleform::GFx::ASString v58; // [rsp+128h] [rbp+7Fh]

  v54 = -2i64;
  v2 = this;
  v3 = this->pAS3RawPtr;
  if ( !v3 )
    v3 = this->pAS3CollectiblePtr.pObject;
  if ( (unsigned __int8)v3 & 1 )
    v3 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v3 - 1);
  v52 = v3;
  if ( v3 )
    v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
  v4 = id->Id;
  if ( id->Id > 0x100000F )
  {
    switch ( v4 )
    {
      case 0x1000010u:
        this->pDispObj->Depth = 0;
        v35 = this->pDispObj->pASRoot;
        v36 = this->pAS3RawPtr;
        if ( !v36 )
          v36 = this->pAS3CollectiblePtr.pObject;
        if ( (unsigned __int8)v36 & 1 )
          v36 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v36 - 1);
        if ( v36 )
        {
          if ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::HasEventHandler(
                 (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v36->vfptr,
                 (Scaleform::GFx::ASString *)&v35[15].RefCount,
                 0)
            && !Scaleform::GFx::AS3::AvmDisplayObj::GetAVM(v2)->HandleException )
          {
            Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
              (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v36->vfptr,
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&v56,
              (Scaleform::GFx::ASString *)&v35[15].RefCount,
              1,
              0);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v56.pNode[1].Size,
              (Scaleform::GFx::AS3::Instances::fl::XMLList *)v36);
            Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
              (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v36->vfptr,
              (Scaleform::GFx::AS3::Instances::fl_events::Event *)v56.pNode,
              v2->pDispObj);
            v37 = v56.pNode;
            if ( v56.pNode )
            {
              if ( (_QWORD)v56.pNode & 1 )
              {
                --v56.pNode;
              }
              else
              {
                v38 = v56.pNode->Size;
                if ( v38 & 0x3FFFFF )
                {
                  v56.pNode->Size = v38 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v37);
                }
              }
            }
          }
        }
        if ( v2->Flags & 1 )
        {
          if ( !Scaleform::GFx::AS3::AvmDisplayObj::GetAVM(v2)->HandleException )
          {
            Scaleform::GFx::AS3::MovieRoot::CreateEventObject(
              (Scaleform::GFx::AS3::MovieRoot *)v2->pDispObj->pASRoot,
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&v56,
              (Scaleform::GFx::ASString *)&v2->pDispObj->pASRoot[15].pMovieImpl,
              0,
              0);
            ((void (__fastcall *)(Scaleform::GFx::AS3::AvmDisplayObj *, Scaleform::GFx::ASStringNode *, _QWORD))v2->vfptr[1].GetAbsolutePath)(
              v2,
              v56.pNode,
              0i64);
            v39 = v56.pNode;
            if ( v56.pNode )
            {
              if ( (_QWORD)v56.pNode & 1 )
              {
                --v56.pNode;
              }
              else
              {
                v40 = v56.pNode->Size;
                if ( v40 & 0x3FFFFF )
                {
                  v56.pNode->Size = v40 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v39);
                }
              }
            }
          }
        }
        ((void (*)(void))v2->pDispObj->vfptr[75].__vecDelDtor)();
        break;
      case 0x1000011u:
        if ( v3 )
        {
          v43 = v3->pImpl.pObject;
          if ( v43 )
          {
            v44 = (((unsigned int)v43->Flags >> 1) & 1) == 0;
            goto LABEL_138;
          }
        }
        break;
      case 0x1000012u:
        if ( v3 )
        {
          v45 = v3->pImpl.pObject;
          if ( v45 )
          {
            v44 = (((unsigned int)v45->Flags >> 2) & 1) == 0;
            goto LABEL_138;
          }
        }
        break;
      case 0x1000013u:
        if ( v3 )
        {
          v46 = v3->pImpl.pObject;
          if ( v46 )
          {
            v44 = (((unsigned int)v46->Flags >> 3) & 1) == 0;
            goto LABEL_138;
          }
        }
        break;
      case 0x1000014u:
        v44 = v3 == 0i64;
LABEL_138:
        if ( !v44 )
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
            (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v3->vfptr,
            id,
            this->pDispObj);
        break;
      case 0x1000015u:
        if ( v3 )
        {
          v41 = v3->pImpl.pObject;
          if ( v41 )
          {
            if ( ((unsigned int)v41->Flags >> 5) & 1 )
            {
              dispObject = this->pDispObj;
              v22 = (Scaleform::GFx::ASString *)&dispObject->pASRoot[16];
              goto LABEL_72;
            }
          }
        }
        break;
      case 0x1000016u:
        if ( v3 )
        {
          v42 = v3->pImpl.pObject;
          if ( v42 )
          {
            if ( ((unsigned int)v42->Flags >> 6) & 1 )
            {
              dispObject = this->pDispObj;
              v22 = (Scaleform::GFx::ASString *)&dispObject->pASRoot[16].RefCount;
              goto LABEL_72;
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
    if ( (unsigned __int8)v24 & 1 )
      v24 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v24 - 1);
    if ( v24 )
    {
      v25 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v24->pImpl.pObject;
      if ( v25 )
      {
        v26 = v25[1].pTable;
        if ( v26 )
        {
          v27 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                  v25 + 1,
                  (Scaleform::GFx::ASString *)&v23[14].AVMVersion,
                  *(unsigned int *)(*(_QWORD *)&v23[14].AVMVersion + 28i64) & v26->SizeMask);
          if ( v27 >= 0 )
          {
            v28 = (signed __int64)v26 + 8 * (3 * v27 + 3);
            if ( v28 )
            {
              v29 = v28 + 8;
              if ( v29 )
              {
                if ( *(_QWORD *)v29 )
                {
                  if ( *(_QWORD *)(*(_QWORD *)v29 + 8i64) )
                  {
                    if ( !Scaleform::GFx::AS3::AvmDisplayObj::GetAVM(v2)->HandleException )
                    {
                      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
                        (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v24->vfptr,
                        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&v56,
                        (Scaleform::GFx::ASString *)&v23[14].AVMVersion,
                        1,
                        0);
                      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v56.pNode[1].Size,
                        (Scaleform::GFx::AS3::Instances::fl::XMLList *)v24);
                      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
                        (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v24->vfptr,
                        (Scaleform::GFx::AS3::Instances::fl_events::Event *)v56.pNode,
                        v2->pDispObj);
                      v30 = v56.pNode;
                      if ( v56.pNode )
                      {
                        if ( (_QWORD)v56.pNode & 1 )
                        {
                          --v56.pNode;
                        }
                        else
                        {
                          v31 = v56.pNode->Size;
                          if ( v31 & 0x3FFFFF )
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
    if ( Scaleform::GFx::AS3::AvmDisplayObj::IsStageAccessible(v2) )
    {
      ((void (*)(void))v2->pDispObj->pASRoot->vfptr[4].__vecDelDtor)();
      v32 = v2->pDispObj->pASRoot;
      if ( !LOBYTE(v32[2].vfptr[21].__vecDelDtor) )
      {
        Scaleform::GFx::AS3::MovieRoot::CreateEventObject(
          (Scaleform::GFx::AS3::MovieRoot *)v32,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&v56,
          (Scaleform::GFx::ASString *)&v32[15],
          0,
          0);
        ((void (__fastcall *)(Scaleform::GFx::AS3::AvmDisplayObj *, Scaleform::GFx::ASStringNode *, _QWORD))v2->vfptr[1].GetAbsolutePath)(
          v2,
          v56.pNode,
          0i64);
        v33 = v56.pNode;
        if ( v56.pNode )
        {
          if ( (_QWORD)v56.pNode & 1 )
          {
            --v56.pNode;
          }
          else
          {
            v34 = v56.pNode->Size;
            if ( v34 & 0x3FFFFF )
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
        else if ( this->pDispObj->Flags & 1 )
        {
          Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(this);
          if ( !((LOBYTE(v2->pDispObj->Flags) >> 1) & 1) )
          {
            if ( Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Parent(v2) )
            {
              Scaleform::GFx::AS3::AvmDisplayObj::GetName((Scaleform::GFx::AS2::AvmCharacter *)v2, &result);
              v8 = 10;
              v48.Flags = 10;
              v48.Bonus.pWeakProxy = 0i64;
              v9 = result.pNode;
              *(Scaleform::GFx::ASString *)&v48.value.VNumber = result;
              if ( result.pNode == &result.pNode->pManager->NullStringNode )
              {
                v9 = 0i64;
                v48.value.VNumber = 0.0;
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
              v51 = Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Parent(v2);
              v11 = *(double *)&v2->pAS3RawPtr;
              if ( v11 == 0.0 )
                v11 = *(double *)&v2->pAS3CollectiblePtr.pObject;
              if ( LOBYTE(v11) & 1 )
                --*(_QWORD *)&v11;
              v49.Flags = 12;
              v49.Bonus.pWeakProxy = 0i64;
              v49.value.VNumber = v11;
              if ( v11 != 0.0 )
                *(_DWORD *)(*(_QWORD *)&v11 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v11 + 32i64) + 1) & 0x8FBFFFFF;
              v12 = (Scaleform::GFx::AS3::GASRefCountBase *)v2->pDispObj->pASRoot[2].vfptr[53].__vecDelDtor;
              v50.Kind = 0;
              v50.Obj.pObject = v12;
              if ( v12 )
                v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
              v50.Name.Flags = 0;
              v50.Name.Bonus.pWeakProxy = 0i64;
              v13 = v8 & 0x1F;
              if ( (unsigned int)(v13 - 12) <= 3
                && v9
                && (v14 = v9[1].pData, *((_DWORD *)v14 + 30) == 17)
                && ~((const unsigned __int8)v14[112] >> 5) & 1 )
              {
                Scaleform::GFx::AS3::Value::Assign(&v50.Name, (Scaleform::GFx::ASString *)&v9[1].16);
                Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                  (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v50.Obj,
                  *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v9[1].RefCount);
                v50.Kind &= 0xFFFFFFF9;
              }
              else
              {
                __asm { prefetcht1 byte ptr [rbp+57h+var_D0.Flags]; Prefetch to all cache levels }
                *(_QWORD *)&v50.Name.Flags = *(_QWORD *)&v48.Flags;
                v50.Name.Bonus.pWeakProxy = 0i64;
                *(_QWORD *)&v50.Name.value.VNumber = v9;
                v50.Name.value.VS._2 = v10;
                if ( v13 > 9 )
                {
                  if ( (v8 >> 9) & 1 )
                  {
                    LODWORD(MEMORY[0]) = MEMORY[0] + 1;
                  }
                  else if ( v13 == 10 )
                  {
                    ++v9->RefCount;
                  }
                  else if ( v13 > 10 )
                  {
                    if ( v13 <= 15 )
                    {
                      if ( v9 )
                        v9->Size = (v9->Size + 1) & 0x8FBFFFFF;
                    }
                    else if ( v13 <= 17 && v10.VObj )
                    {
                      v10.VObj->RefCount = (v10.VObj->RefCount + 1) & 0x8FBFFFFF;
                    }
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
                      v44 = v58.pNode->RefCount == 1;
                      --v16->RefCount;
                      if ( v44 )
                        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
                    }
                  }
                  v17 = v56.pNode;
                  v44 = v56.pNode->RefCount == 1;
                  --v17->RefCount;
                  if ( v44 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
                }
              }
              ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))v51->vfptr[1].ForEachChild_GC)(
                v51,
                &v55,
                &v50,
                &v49);
              Scaleform::GFx::AS3::Multiname::~Multiname(&v50);
              if ( (v49.Flags & 0x1F) > 9 )
              {
                if ( (v49.Flags >> 9) & 1 )
                {
                  v44 = v49.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v44 )
                    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                  v49.Bonus.pWeakProxy = 0i64;
                  v49.value = 0ui64;
                  v49.Flags &= 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v49);
                }
              }
              if ( v13 > 9 )
              {
                if ( (v8 >> 9) & 1 )
                {
                  LODWORD(MEMORY[0]) = MEMORY[0] - 1;
                  if ( !(_DWORD)MEMORY[0] )
                    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
                  v48.Bonus.pWeakProxy = 0i64;
                  v48.value = 0ui64;
                  v48.Flags = v8 & 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v48);
                }
              }
              v18 = v2->pDispObj->pASRoot;
              if ( LOBYTE(v18[2].vfptr[21].__vecDelDtor) )
              {
                Scaleform::GFx::AS3::VM::OutputAndIgnoreException((Scaleform::GFx::AS3::VM *)v18[2].vfptr);
                v2->pDispObj->pParent->Flags |= 0x20u;
              }
              v19 = result.pNode;
              v44 = result.pNode->RefCount == 1;
              --v19->RefCount;
              if ( v44 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v19);
            }
          }
        }
      }
      else if ( v3 )
      {
        v20 = v3->pImpl.pObject;
        if ( v20 )
        {
          if ( v20->Flags & 1 )
          {
            dispObject = this->pDispObj;
            v22 = (Scaleform::GFx::ASString *)&dispObject->pASRoot[15].AVMVersion;
LABEL_72:
            Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchToTarget(
              (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v3->vfptr,
              v22,
              (Scaleform::GFx::AS3::Instances::fl::Object *)&v3->vfptr,
              0,
              dispObject);
          }
        }
      }
    }
    else
    {
      ((void (*)(void))this->pDispObj->vfptr[73].__vecDelDtor)();
    }
  }
  if ( v3 )
  {
    if ( (unsigned __int8)v3 & 1 )
    {
      v52 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v3 - 1);
    }
    else
    {
      v47 = v3->RefCount;
      if ( v47 & 0x3FFFFF )
      {
        v3->RefCount = v47 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->vfptr);
      }
    }
  }
}ntBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->vfptr);
      }
    }
  }
}

// File Line: 363
// RVA: 0x802B40
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::OnAdded(Scaleform::GFx::AS3::AvmDisplayObj *this, bool byTimeline)
{
  bool v2; // r14
  Scaleform::GFx::AS3::AvmDisplayObj *v3; // rsi
  Scaleform::GFx::DisplayObject *v4; // rcx
  Scaleform::GFx::MovieImpl *v5; // rbp
  __int64 v6; // rdx
  char v7; // di
  Scaleform::GFx::DisplayObject *v8; // rbx
  Scaleform::GFx::InteractiveObject *v9; // rbx
  char v10; // dl
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  int v13; // eax
  Scaleform::GFx::ASString *v14; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v15; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v16; // rcx
  unsigned int v17; // eax
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
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> result; // [rsp+60h] [rbp+8h]

  v2 = byTimeline;
  v3 = this;
  v4 = this->pDispObj;
  v5 = v4->pASRoot->pMovieImpl;
  if ( (v5->Flags >> 11) & 1 )
  {
    v7 = ((__int64 (*)(void))v4->vfptr[59].__vecDelDtor)();
    if ( v7 )
    {
      v8 = v3->pDispObj;
      if ( v8 )
      {
        while ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->vfptr[59].__vecDelDtor)(v8) )
        {
          v8 = (Scaleform::GFx::DisplayObject *)&v8->pParent->vfptr;
          if ( !v8 )
            goto LABEL_8;
        }
        v7 = 0;
      }
    }
LABEL_8:
    v9 = 0i64;
    if ( SLOBYTE(v3->pDispObj->Flags) < 0 )
      v9 = (Scaleform::GFx::InteractiveObject *)v3->pDispObj;
    if ( v9 )
    {
      v10 = v7 || !((v5->Flags >> 11) & 1) ? 0 : 1;
      v11 = v9->Flags;
      if ( v10 != ((v9->Flags >> 3) & 1) )
      {
        if ( v10 )
          v12 = v11 | 8;
        else
          v12 = v11 & 0xFFFFFFF7;
        v9->Flags = v12;
        if ( !((v12 >> 21) & 1) || (v12 >> 22) & 1 )
          v6 = 0i64;
        else
          LOBYTE(v6) = 1;
        v13 = (__int64)v9->vfptr[103].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v9->vfptr, v6);
        if ( v13 == -1 )
        {
          v9->Flags |= 0x400000u;
        }
        else if ( v13 == 1 )
        {
          Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v9);
        }
        ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v9->vfptr[104].__vecDelDtor)(v9);
      }
    }
  }
  v14 = (Scaleform::GFx::ASString *)v3->pDispObj->pASRoot;
  v15 = v3->pAS3RawPtr;
  if ( !v15 )
    v15 = v3->pAS3CollectiblePtr.pObject;
  if ( (unsigned __int8)v15 & 1 )
    v15 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v15 - 1);
  if ( v15 != v3->pAS3CollectiblePtr.pObject )
  {
    if ( v15 )
      v15->RefCount = (v15->RefCount + 1) & 0x8FBFFFFF;
    v16 = v3->pAS3CollectiblePtr.pObject;
    if ( v16 )
    {
      if ( (unsigned __int8)v16 & 1 )
      {
        v3->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v16 - 1);
      }
      else
      {
        v17 = v16->RefCount;
        if ( v17 & 0x3FFFFF )
        {
          v16->RefCount = v17 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v16->vfptr);
        }
      }
    }
    v3->pAS3CollectiblePtr.pObject = v15;
  }
  v3->pAS3RawPtr = 0i64;
  if ( v15 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v15->vfptr,
      &result,
      v14 + 74,
      1,
      0);
    v18 = result.pObject;
    if ( v15 != (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)result.pObject->Target.pObject )
    {
      v15->RefCount = (v15->RefCount + 1) & 0x8FBFFFFF;
      v19 = v18->Target.pObject;
      if ( v19 )
      {
        if ( (unsigned __int8)v19 & 1 )
        {
          v18->Target.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v19 - 1);
        }
        else
        {
          v20 = v19->RefCount;
          if ( v20 & 0x3FFFFF )
          {
            v19->RefCount = v20 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v19->vfptr);
          }
        }
      }
      v18->Target.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)&v15->vfptr;
      v18 = result.pObject;
    }
    v21 = v3->pDispObj;
    if ( v15 != (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v18->Target.pObject )
    {
      v15->RefCount = (v15->RefCount + 1) & 0x8FBFFFFF;
      v22 = v18->Target.pObject;
      if ( v22 )
      {
        if ( (unsigned __int8)v22 & 1 )
        {
          v18->Target.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v22 - 1);
        }
        else
        {
          v23 = v22->RefCount;
          if ( v23 & 0x3FFFFF )
          {
            v22->RefCount = v23 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v22->vfptr);
          }
        }
      }
      v18->Target.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)&v15->vfptr;
    }
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v15->vfptr,
      v18,
      v21);
    v24 = result.pObject;
    if ( result.pObject )
    {
      if ( (_QWORD)result.pObject & 1 )
      {
        --result.pObject;
      }
      else
      {
        v25 = result.pObject->RefCount;
        if ( v25 & 0x3FFFFF )
        {
          result.pObject->RefCount = v25 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v24->vfptr);
        }
      }
    }
  }
  if ( Scaleform::GFx::AS3::AvmDisplayObj::IsStageAccessible(v3) )
  {
    ((void (*)(void))v3->pDispObj->pASRoot->vfptr[4].__vecDelDtor)();
    v26 = v3->pDispObj->pASRoot;
    if ( !LOBYTE(v26[2].vfptr[21].__vecDelDtor) )
    {
      Scaleform::GFx::AS3::MovieRoot::CreateEventObject(
        (Scaleform::GFx::AS3::MovieRoot *)v26,
        &result,
        (Scaleform::GFx::ASString *)&v26[15],
        0,
        0);
      LOBYTE(v27) = v2 == 0;
      ((void (__fastcall *)(Scaleform::GFx::AS3::AvmDisplayObj *, Scaleform::GFx::AS3::Instances::fl_events::Event *, __int64))v3->vfptr[1].GetAbsolutePath)(
        v3,
        result.pObject,
        v27);
      v28 = result.pObject;
      if ( result.pObject )
      {
        if ( (_QWORD)result.pObject & 1 )
        {
          --result.pObject;
        }
        else
        {
          v29 = result.pObject->RefCount;
          if ( v29 & 0x3FFFFF )
          {
            result.pObject->RefCount = v29 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v28->vfptr);
          }
        }
      }
    }
  }
}

// File Line: 422
// RVA: 0x8053B0
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::OnRemoved(Scaleform::GFx::AS3::AvmDisplayObj *this, bool byTimeline)
{
  bool v2; // bp
  Scaleform::GFx::AS3::AvmDisplayObj *v3; // r14
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // rbx
  Scaleform::GFx::DisplayObject *v5; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v6; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v7; // rcx
  unsigned int v8; // eax
  Scaleform::GFx::ASMovieRootBase *v9; // rcx
  __int64 v10; // r8
  Scaleform::GFx::AS3::Instances::fl_events::Event *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> result; // [rsp+60h] [rbp+8h]

  v2 = byTimeline;
  v3 = this;
  v4 = this->pAS3RawPtr;
  if ( !v4 )
    v4 = this->pAS3CollectiblePtr.pObject;
  if ( (unsigned __int8)v4 & 1 )
    v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v4 - 1);
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v4->vfptr,
      &result,
      (Scaleform::GFx::ASString *)&this->pDispObj->pASRoot[15].RefCount,
      1,
      0);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4);
    v5 = v3->pDispObj;
    v6 = result.pObject;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v4->vfptr,
      v6,
      v5);
    v7 = result.pObject;
    if ( result.pObject )
    {
      if ( (_QWORD)result.pObject & 1 )
      {
        --result.pObject;
      }
      else
      {
        v8 = result.pObject->RefCount;
        if ( v8 & 0x3FFFFF )
        {
          result.pObject->RefCount = v8 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v7->vfptr);
        }
      }
    }
  }
  if ( Scaleform::GFx::AS3::AvmDisplayObj::IsStageAccessible(v3) )
  {
    ((void (*)(void))v3->pDispObj->pASRoot->vfptr[4].__vecDelDtor)();
    v9 = v3->pDispObj->pASRoot;
    if ( !LOBYTE(v9[2].vfptr[21].__vecDelDtor) )
    {
      Scaleform::GFx::AS3::MovieRoot::CreateEventObject(
        (Scaleform::GFx::AS3::MovieRoot *)v9,
        &result,
        (Scaleform::GFx::ASString *)&v9[15].pMovieImpl,
        0,
        0);
      LOBYTE(v10) = v2 == 0;
      ((void (__fastcall *)(Scaleform::GFx::AS3::AvmDisplayObj *, Scaleform::GFx::AS3::Instances::fl_events::Event *, __int64))v3->vfptr[1].GetAbsolutePath)(
        v3,
        result.pObject,
        v10);
      v11 = result.pObject;
      if ( result.pObject )
      {
        if ( (_QWORD)result.pObject & 1 )
        {
          --result.pObject;
        }
        else
        {
          v12 = result.pObject->RefCount;
          if ( v12 & 0x3FFFFF )
          {
            result.pObject->RefCount = v12 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v11->vfptr);
          }
        }
      }
    }
  }
  v3->pAS3RawPtr = v4;
  v13 = v3->pAS3CollectiblePtr.pObject;
  if ( v13 )
  {
    if ( (unsigned __int8)v13 & 1 )
    {
      v3->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v13 - 1);
    }
    else
    {
      v14 = v13->RefCount;
      if ( v14 & 0x3FFFFF )
      {
        v13->RefCount = v14 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v13->vfptr);
      }
    }
    v3->pAS3CollectiblePtr.pObject = 0i64;
  }
}

// File Line: 449
// RVA: 0x803170
char __fastcall Scaleform::GFx::AS3::AvmDisplayObj::OnEvent(Scaleform::GFx::AS3::AvmDisplayObj *this, Scaleform::GFx::EventId *id)
{
  unsigned int v2; // eax
  Scaleform::GFx::EventId *v3; // rbx
  Scaleform::GFx::AS3::AvmDisplayObj *v4; // rdi
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
  Scaleform::GFx::DisplayObject *v16; // rsi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v17; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v18; // rbp
  Scaleform::RefCountNTSImpl *v19; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v20; // rcx
  unsigned int v21; // eax
  Scaleform::GFx::AS3::WeakProxy *v22; // rdx
  Scaleform::Render::RenderBuffer *v23; // rcx

  v2 = id->Id;
  v3 = id;
  v4 = this;
  if ( id->Id == 2 )
  {
    if ( *(_OWORD *)&this->pAS3CollectiblePtr.pObject != 0i64 && this->Flags & 2 )
    {
      v16 = this->pDispObj;
      v17 = Scaleform::GFx::AS3::MovieRoot::InsertEmptyAction(
              (Scaleform::GFx::AS3::MovieRoot *)v16->pASRoot,
              AL_EnterFrame);
      v18 = v17;
      v17->Type = 1;
      if ( v16 )
        ++v16->RefCount;
      v19 = (Scaleform::RefCountNTSImpl *)&v17->pCharacter.pObject->vfptr;
      if ( v19 )
        Scaleform::RefCountNTSImpl::Release(v19);
      v18->pCharacter.pObject = v16;
      v18->mEventId.Id = v3->Id;
      v18->mEventId.WcharCode = v3->WcharCode;
      v18->mEventId.KeyCode = v3->KeyCode;
      v18->mEventId.AsciiCode = v3->AsciiCode;
      v18->mEventId.RollOverCnt = v3->RollOverCnt;
      v18->mEventId.ControllerIndex = v3->ControllerIndex;
      v18->mEventId.KeysState.States = v3->KeysState.States;
      v18->mEventId.MouseWheelDelta = v3->MouseWheelDelta;
      v18->CFunction = 0i64;
      v20 = v18->pAS3Obj.pObject;
      if ( v20 )
      {
        if ( (unsigned __int8)v20 & 1 )
        {
          v18->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v20 - 1);
        }
        else
        {
          v21 = v20->RefCount;
          if ( v21 & 0x3FFFFF )
          {
            v20->RefCount = v21 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v20->vfptr);
          }
        }
        v18->pAS3Obj.pObject = 0i64;
      }
      if ( (v18->Function.Flags & 0x1F) > 9 )
      {
        if ( (v18->Function.Flags >> 9) & 1 )
        {
          v22 = v18->Function.Bonus.pWeakProxy;
          v13 = v22->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v18->Function.Flags &= 0xFFFFFDE0;
          v18->Function.Bonus.pWeakProxy = 0i64;
          v18->Function.value.VNumber = 0.0;
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
    v4->Flags |= 2u;
    return 1;
  }
  if ( v2 == 16777235 )
  {
    if ( *(_OWORD *)&this->pAS3CollectiblePtr.pObject != 0i64 )
    {
      v5 = 5;
      goto LABEL_6;
    }
    return 1;
  }
  if ( v2 - 16777237 > 1 )
    return 0;
  if ( *(_OWORD *)&this->pAS3CollectiblePtr.pObject == 0i64 )
    return 1;
  v5 = 3;
LABEL_6:
  v6 = this->pDispObj;
  v7 = Scaleform::GFx::AS3::MovieRoot::InsertEmptyAction((Scaleform::GFx::AS3::MovieRoot *)v6->pASRoot, v5);
  v8 = v7;
  v7->Type = 1;
  if ( v6 )
    ++v6->RefCount;
  v9 = (Scaleform::RefCountNTSImpl *)&v7->pCharacter.pObject->vfptr;
  if ( v9 )
    Scaleform::RefCountNTSImpl::Release(v9);
  v8->pCharacter.pObject = v6;
  v8->mEventId.Id = v3->Id;
  v8->mEventId.WcharCode = v3->WcharCode;
  v8->mEventId.KeyCode = v3->KeyCode;
  v8->mEventId.AsciiCode = v3->AsciiCode;
  v8->mEventId.RollOverCnt = v3->RollOverCnt;
  v8->mEventId.ControllerIndex = v3->ControllerIndex;
  v8->mEventId.KeysState.States = v3->KeysState.States;
  v8->mEventId.MouseWheelDelta = v3->MouseWheelDelta;
  v8->CFunction = 0i64;
  v10 = v8->pAS3Obj.pObject;
  if ( v10 )
  {
    if ( (unsigned __int8)v10 & 1 )
    {
      v8->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v10 - 1);
    }
    else
    {
      v11 = v10->RefCount;
      if ( v11 & 0x3FFFFF )
      {
        v10->RefCount = v11 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v10->vfptr);
      }
    }
    v8->pAS3Obj.pObject = 0i64;
  }
  if ( (v8->Function.Flags & 0x1F) > 9 )
  {
    if ( (v8->Function.Flags >> 9) & 1 )
    {
      v12 = v8->Function.Bonus.pWeakProxy;
      v13 = v12->RefCount-- == 1;
      if ( v13 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v8->Function.Bonus.pWeakProxy = 0i64;
      v8->Function.value.VNumber = 0.0;
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
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v1; // rax
  Scaleform::GFx::AS3::AvmDisplayObj *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v3; // rcx
  unsigned int v4; // eax

  v1 = this->pAS3RawPtr;
  v2 = this;
  if ( !v1 )
    v1 = this->pAS3CollectiblePtr.pObject;
  if ( (unsigned __int8)v1 & 1 )
    v1 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v1 - 1);
  this->pAS3RawPtr = v1;
  v3 = this->pAS3CollectiblePtr.pObject;
  if ( v3 )
  {
    if ( (unsigned __int8)v3 & 1 )
    {
      v2->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v3 - 1);
      v2->pAS3CollectiblePtr.pObject = 0i64;
    }
    else
    {
      v4 = v3->RefCount;
      if ( v4 & 0x3FFFFF )
      {
        v3->RefCount = v4 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->vfptr);
      }
      v2->pAS3CollectiblePtr.pObject = 0i64;
    }
  }
}

// File Line: 501
// RVA: 0x7B19E0
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::AssignAS3Obj(Scaleform::GFx::AS3::AvmDisplayObj *this, Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pas3obj)
{
  Scaleform::GFx::AS3::AvmDisplayObj *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v3; // rcx
  unsigned int v4; // eax

  v2 = this;
  this->pAS3RawPtr = pas3obj;
  v3 = this->pAS3CollectiblePtr.pObject;
  if ( v3 )
  {
    if ( (unsigned __int8)v3 & 1 )
    {
      v2->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v3 - 1);
      v2->pAS3CollectiblePtr.pObject = 0i64;
    }
    else
    {
      v4 = v3->RefCount;
      if ( v4 & 0x3FFFFF )
      {
        v3->RefCount = v4 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->vfptr);
      }
      v2->pAS3CollectiblePtr.pObject = 0i64;
    }
  }
}

// File Line: 515
// RVA: 0x7E5A70
const char *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetAbsolutePath(Scaleform::GFx::AS3::AvmDisplayObj *this, Scaleform::String *ppath)
{
  Scaleform::String *v2; // rbx
  Scaleform::GFx::AS2::AvmCharacter *v3; // rdi
  Scaleform::GFx::InteractiveObject *v4; // rcx
  const char ***v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v2 = ppath;
  v3 = (Scaleform::GFx::AS2::AvmCharacter *)this;
  v4 = this->pDispObj->pParent;
  if ( v4 )
  {
    Scaleform::GFx::DisplayObject::GetAbsolutePath((Scaleform::GFx::DisplayObject *)&v4->vfptr, ppath);
    Scaleform::String::AppendString(v2, ".", -1i64);
    v5 = (const char ***)Scaleform::GFx::AS3::AvmDisplayObj::GetName(v3, &result);
    Scaleform::String::AppendString(v2, **v5, -1i64);
    v6 = result.pNode;
    v7 = result.pNode->RefCount == 1;
    --v6->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
  return (const char *)((v2->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
}

// File Line: 528
// RVA: 0x7E4900
Scaleform::GFx::ASMovieRootBase *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Root(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  return this->pDispObj->pASRoot;
}

// File Line: 533
// RVA: 0x7E4940
Scaleform::String *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetASClassName(Scaleform::GFx::AS3::AvmDisplayObj *this, Scaleform::String *className)
{
  Scaleform::String *v2; // rbx
  const char *v3; // rdx
  Scaleform::GFx::AS3::AvmDisplayObj *v4; // rdi
  Scaleform::GFx::DisplayObject *v5; // rcx
  Scaleform::GFx::MovieDefImpl *v6; // rax
  Scaleform::String *v7; // rax
  Scaleform::GFx::ResourceId rid; // [rsp+30h] [rbp+8h]

  v2 = className;
  v3 = this->pClassName;
  v4 = this;
  if ( v3 )
    goto LABEL_4;
  v5 = this->pDispObj;
  rid.Id = v5->Id.Id;
  v6 = (Scaleform::GFx::MovieDefImpl *)((__int64 (*)(void))v5->vfptr[66].__vecDelDtor)();
  v7 = Scaleform::GFx::MovieDefImpl::GetNameOfExportedResource(v6, (Scaleform::GFx::ResourceId)&rid);
  if ( !v7 )
  {
    v3 = (const char *)v4->vfptr[1].ToAvmButttonBase((Scaleform::GFx::AvmDisplayObjBase *)&v4->vfptr);
LABEL_4:
    Scaleform::String::operator=(v2, v3);
    return v2;
  }
  Scaleform::String::operator=(v2, v7);
  return v2;
}

// File Line: 553
// RVA: 0x7BB4B0
Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstance(Scaleform::GFx::AS3::AvmDisplayObj *this, bool execute)
{
  bool v2; // di
  Scaleform::GFx::AS3::AvmDisplayObj *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *result; // rax

  v2 = execute;
  v3 = this;
  if ( *(_OWORD *)&this->pAS3CollectiblePtr.pObject == 0i64
    && Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(this) )
  {
    result = Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(v3, v2);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 563
// RVA: 0x7BB500
char __fastcall Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::AS3::AvmDisplayObj *v1; // rsi
  Scaleform::GFx::AS3::VM *v2; // rdi
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Class *v4; // rax
  Scaleform::GFx::AS3::Class *v5; // r15
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // r13
  Scaleform::GFx::DisplayObject *v7; // r14
  Scaleform::RefCountNTSImpl *v8; // rcx
  __int64 v9; // rdx
  bool v10; // zf
  char v11; // di
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::StringDataPtr gname; // [rsp+28h] [rbp-51h]
  Scaleform::GFx::AS3::Class *v16; // [rsp+38h] [rbp-41h]
  unsigned __int64 v17; // [rsp+40h] [rbp-39h]
  Scaleform::GFx::AS3::VM::Error v18; // [rsp+48h] [rbp-31h]
  Scaleform::GFx::AS3::Value v19; // [rsp+58h] [rbp-21h]
  Scaleform::GFx::AS3::Value v20; // [rsp+78h] [rbp-1h]
  char v21; // [rsp+E0h] [rbp+67h]
  Scaleform::String v22; // [rsp+E8h] [rbp+6Fh]

  v1 = this;
  if ( *(_OWORD *)&this->pAS3CollectiblePtr.pObject != 0i64 )
    return 0;
  v2 = (Scaleform::GFx::AS3::VM *)this->pDispObj->pASRoot[2].vfptr;
  if ( !v2 )
    return 0;
  Scaleform::String::String(&v22);
  ((void (__fastcall *)(Scaleform::GFx::AS3::AvmDisplayObj *, Scaleform::String *))v1->vfptr[1].ToAvmTextFieldBase)(
    v1,
    &v22);
  v19.Flags = 0;
  v19.Bonus.pWeakProxy = 0i64;
  v3 = 0;
  v20.Flags = 0;
  v20.Bonus.pWeakProxy = 0i64;
  gname.pStr = (const char *)((v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  gname.Size = *(_QWORD *)(v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64;
  v4 = Scaleform::GFx::AS3::VM::GetClass(v2, &gname, v1->AppDomain);
  v5 = v4;
  if ( !v4 )
  {
    if ( v2->HandleException )
      goto LABEL_16;
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eUndefinedVarError, v2);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v2, v12, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    v13 = v18.Message.pNode;
    v10 = v18.Message.pNode->RefCount == 1;
    --v13->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v10 = v2->HandleException == 0;
LABEL_15:
    if ( v10 )
    {
LABEL_17:
      v11 = 0;
      goto LABEL_18;
    }
LABEL_16:
    Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v2);
    v1->pDispObj->Flags |= 0x20u;
    goto LABEL_17;
  }
  v3 = 13;
  v20.Flags = 13;
  v16 = v4;
  v20.value = (Scaleform::GFx::AS3::Value::VU)__PAIR__(v17, (unsigned __int64)v4);
  v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
  (*((void (__fastcall **)(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *))v4->pTraits.pObject[1].vfptr->ForEachChild_GC
   + 11))(
    v4->pTraits.pObject[1].vfptr,
    &v19,
    v4->pTraits.pObject[1].vfptr);
  v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v19.value.VS._1.VStr;
  v7 = v1->pDispObj;
  if ( v7 )
    ++v7->RefCount;
  v8 = (Scaleform::RefCountNTSImpl *)v6->List.Data.Size;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
  v6->List.Data.Size = (unsigned __int64)v7;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v1->pAS3CollectiblePtr,
    v6);
  v1->pAS3RawPtr = 0i64;
  if ( !*(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Class *, char *, Scaleform::GFx::AS3::Value *))v5->vfptr[6].Finalize_GC)(
                    v5,
                    &v21,
                    &v19) )
  {
    v10 = v2->HandleException == 0;
    goto LABEL_15;
  }
  LOBYTE(v9) = 1;
  (*((void (__fastcall **)(_QWORD, __int64))v19.value.VS._1.VStr->pData + 13))(*(_QWORD *)&v19.value.VNumber, v9);
  v11 = 1;
LABEL_18:
  if ( (char)(v3 & 0x1F) > 9 )
  {
    if ( (v3 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      v20.Bonus.pWeakProxy = 0i64;
      v20.value = 0ui64;
      v20.Flags = v3 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v20);
    }
  }
  if ( (v19.Flags & 0x1F) > 9 )
  {
    if ( (v19.Flags >> 9) & 1 )
    {
      v10 = v19.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v19.Bonus.pWeakProxy = 0i64;
      v19.value = 0ui64;
      v19.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v19);
    }
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v11;
}

// File Line: 638
// RVA: 0x7B2DD0
Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(Scaleform::GFx::AS3::AvmDisplayObj *this, bool execute)
{
  bool v2; // bp
  Scaleform::GFx::AS3::AvmDisplayObj *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *result; // rax
  Scaleform::GFx::AS3::Traits *v5; // rbx
  Scaleform::GFx::AS3::Class *v6; // r10
  long double v7; // rax
  Scaleform::GFx::AS3::VM *v8; // rsi
  unsigned __int64 v9; // rbx
  unsigned int v10; // ebx
  bool v11; // zf
  Scaleform::GFx::AS3::Value v12; // [rsp+28h] [rbp-30h]

  v2 = execute;
  v3 = this;
  result = this->pAS3RawPtr;
  if ( !result )
  {
    if ( !this->pAS3CollectiblePtr.pObject )
      return result;
    result = this->pAS3CollectiblePtr.pObject;
  }
  if ( (unsigned __int8)result & 1 )
    result = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)result - 1);
  v5 = result->pTraits.pObject;
  if ( !v5->pConstructor.pObject )
    v5->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
  v6 = v5->pConstructor.pObject;
  v7 = *(double *)&v3->pAS3RawPtr;
  if ( v7 == 0.0 )
    v7 = *(double *)&v3->pAS3CollectiblePtr.pObject;
  if ( LOBYTE(v7) & 1 )
    --*(_QWORD *)&v7;
  v12.Flags = 12;
  v12.Bonus.pWeakProxy = 0i64;
  v12.value.VNumber = v7;
  if ( v7 != 0.0 )
    *(_DWORD *)(*(_QWORD *)&v7 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v7 + 32i64) + 1) & 0x8FBFFFFF;
  v8 = (Scaleform::GFx::AS3::VM *)v3->pDispObj->pASRoot[2].vfptr;
  if ( !v8 )
    goto LABEL_20;
  v9 = v8->CallStack.Size;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, _QWORD, _QWORD, signed __int64))v6->vfptr[7].ForEachChild_GC)(
    v6,
    &v12,
    0i64,
    0i64,
    -2i64);
  if ( v8->CallStack.Size <= v9 )
    goto LABEL_20;
  if ( v2 )
  {
    Scaleform::GFx::AS3::VM::ExecuteCode(v8, 1u);
    if ( v8->HandleException )
    {
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v8);
      v3->pDispObj->Flags |= 0x20u;
    }
LABEL_20:
    v10 = 0;
    goto LABEL_21;
  }
  v10 = 1;
LABEL_21:
  if ( (v12.Flags & 0x1F) > 9 )
  {
    if ( (v12.Flags >> 9) & 1 )
    {
      v11 = v12.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v12.Bonus.pWeakProxy = 0i64;
      v12.value = 0ui64;
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
Scaleform::GFx::DisplayObject *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetRoot(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::AS3::AvmDisplayObj *v1; // rdx
  bool v2; // zf
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v3; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // rcx
  Scaleform::GFx::InteractiveObject *v5; // rcx
  __int64 v6; // rax

  v1 = this;
  v2 = this == 0i64;
  while ( !v2 )
  {
    v3 = v1->pAS3RawPtr;
    v4 = v3;
    if ( !v3 )
      v4 = v1->pAS3CollectiblePtr.pObject;
    if ( (unsigned __int8)v4 & 1 )
      v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v4 - 1);
    if ( v4 )
    {
      if ( !v3 )
        v3 = v1->pAS3CollectiblePtr.pObject;
      if ( (unsigned __int8)v3 & 1 )
        v3 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v3 - 1);
      if ( v3->pLoaderInfo.pObject )
        return v1->pDispObj;
    }
    v5 = v1->pDispObj->pParent;
    if ( v5
      && (v6 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v5->vfptr
                                                                           + 4 * (unsigned __int8)v5->AvmObjOffset))[1].__vecDelDtor)()) != 0 )
    {
      v1 = (Scaleform::GFx::AS3::AvmDisplayObj *)(v6 - 56);
      v2 = v6 == 56;
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
  Scaleform::GFx::DisplayObject *v1; // rdx
  Scaleform::GFx::AS3::AvmDisplayObj *v2; // rbx
  __int64 v3; // rax
  signed __int64 v4; // rcx
  Scaleform::GFx::InteractiveObject *v6; // rcx
  __int64 v7; // rax
  _QWORD *v8; // rbx
  __int64 v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rcx
  __int64 v12; // rax

  v1 = this->pDispObj;
  v2 = this;
  if ( SLOBYTE(v1->Flags) < 0 )
  {
    if ( v1
      && (v3 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v1->vfptr
                                                                                                + 4
                                                                                                * (unsigned __int8)v1->AvmObjOffset))[1].__vecDelDtor)((signed __int64)v1 + 4 * (unsigned __int8)v1->AvmObjOffset)) != 0 )
    {
      v4 = v3 - 56;
    }
    else
    {
      v4 = 0i64;
    }
    if ( (*(unsigned __int8 (**)(void))(*(_QWORD *)v4 + 176i64))() )
      return 1;
  }
  v6 = v2->pDispObj->pParent;
  if ( v6
    && (v7 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v6->vfptr
                                                                         + 4 * (unsigned __int8)v6->AvmObjOffset))[1].__vecDelDtor)()) != 0 )
  {
    v8 = (_QWORD *)(v7 - 56);
  }
  else
  {
    v8 = 0i64;
  }
  if ( !v8 )
    return 0;
  while ( 1 )
  {
    v9 = *(_QWORD *)(v8[3] + 56i64);
    if ( !v9 )
      break;
    v10 = (*(__int64 (**)(void))(*(_QWORD *)(v9 + 4i64 * *(unsigned __int8 *)(v9 + 109)) + 8i64))();
    if ( !v10 || v10 == 56 )
      break;
    v11 = *(_QWORD *)(v8[3] + 56i64);
    if ( v11 && (v12 = (*(__int64 (**)(void))(*(_QWORD *)(v11 + 4i64 * *(unsigned __int8 *)(v11 + 109)) + 8i64))()) != 0 )
      v8 = (_QWORD *)(v12 - 56);
    else
      v8 = 0i64;
    if ( !v8 )
      return 0;
  }
  return (*(__int64 (__fastcall **)(_QWORD *))(*v8 + 176i64))(v8);
}

// File Line: 718
// RVA: 0x7E60B0
Scaleform::GFx::AS3::AvmInteractiveObj *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetAvmParent(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::InteractiveObject *v1; // rcx
  __int64 v2; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *result; // rax

  v1 = this->pDispObj->pParent;
  if ( v1
    && (v2 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v1->vfptr
                                                                         + 4 * (unsigned __int8)v1->AvmObjOffset))[1].__vecDelDtor)()) != 0 )
  {
    result = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v2 - 56);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 723
// RVA: 0x7E4880
Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *__fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Parent(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::AS3::AvmDisplayObj *v1; // rbx
  Scaleform::GFx::InteractiveObject *v2; // rdx
  __int64 v3; // rax
  Scaleform::GFx::InteractiveObject *v4; // rcx
  __int64 v5; // rax
  signed __int64 v6; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *result; // rax

  v1 = this;
  v2 = this->pDispObj->pParent;
  if ( !v2 )
    return 0i64;
  v3 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v2->vfptr
                                                                                        + 4
                                                                                        * (unsigned __int8)v2->AvmObjOffset))[1].__vecDelDtor)((signed __int64)v2 + 4 * (unsigned __int8)v2->AvmObjOffset);
  if ( !v3 || v3 == 56 )
    return 0i64;
  v4 = v1->pDispObj->pParent;
  if ( v4
    && (v5 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v4->vfptr
                                                                         + 4 * (unsigned __int8)v4->AvmObjOffset))[1].__vecDelDtor)()) != 0 )
  {
    v6 = v5 - 56;
  }
  else
  {
    v6 = 0i64;
  }
  result = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v6 + 16);
  if ( !result )
    result = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v6 + 8);
  if ( (unsigned __int8)result & 1 )
    result = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)result - 1);
  return result;
}

// File Line: 728
// RVA: 0x7F2C80
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::InitClassName(Scaleform::GFx::AS3::AvmDisplayObj *this, const char *className)
{
  const char *v2; // rsi
  Scaleform::GFx::AS3::AvmDisplayObj *v3; // rbp
  signed __int64 v4; // rax
  size_t v6; // rdi
  void *v7; // rbx

  v2 = className;
  v3 = this;
  if ( !this->pClassName )
  {
    v4 = -1i64;
    while ( className[v4++ + 1] != 0 )
      ;
    v6 = v4 + 1;
    v7 = Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
           Scaleform::Memory::pGlobalHeap,
           this->pDispObj,
           v4 + 1,
           0i64);
    memmove(v7, v2, v6);
    v3->pClassName = (const char *)v7;
  }
}

// File Line: 739
// RVA: 0x818190
void __fastcall Scaleform::GFx::AS3::AvmDisplayObj::SetAppDomain(Scaleform::GFx::AS3::AvmDisplayObj *this, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
    this->AppDomain = appDomain;
}

// File Line: 750
// RVA: 0x7ED250
char __fastcall Scaleform::GFx::AS3::AvmDisplayObj::GetObjectsUnderPoint(Scaleform::GFx::AS3::AvmDisplayObj *this, Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2,Scaleform::ArrayDefaultPolicy> *destArray, Scaleform::Render::Point<float> *pt)
{
  Scaleform::Render::Point<float> *v3; // r9
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2,Scaleform::ArrayDefaultPolicy> *v4; // rdi
  Scaleform::GFx::AS3::AvmDisplayObj *v5; // rbx
  Scaleform::RefCountNTSImpl *v6; // rbx
  _QWORD *v7; // rax

  v3 = pt;
  v4 = destArray;
  v5 = this;
  LOBYTE(pt) = 1;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Point<float> *, Scaleform::Render::Point<float> *))this->pDispObj->vfptr[63].__vecDelDtor)(
          this->pDispObj,
          v3,
          pt) )
    return 0;
  v6 = (Scaleform::RefCountNTSImpl *)&v5->pDispObj->vfptr;
  if ( v6 )
    ++v6->RefCount;
  Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v4->Data,
    v4->Data.Size + 1);
  if ( v4->Data.Size != 1 )
    memmove(&v4->Data.Data[1], v4->Data.Data, 8 * (v4->Data.Size - 1));
  v7 = &v4->Data.Data->pObject;
  if ( v4->Data.Data )
  {
    if ( v6 )
      ++v6->RefCount;
    *v7 = v6;
  }
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  return 1;
}

// File Line: 791
// RVA: 0x781DC0
void __fastcall Scaleform::GFx::AS3::ShapeObject::ShapeObject(Scaleform::GFx::AS3::ShapeObject *this, Scaleform::GFx::CharacterDef *pdef, Scaleform::GFx::ASMovieRootBase *pasRoot, Scaleform::GFx::InteractiveObject *pparent, Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::CharacterDef *v5; // rsi
  Scaleform::GFx::AS3::ShapeObject *v6; // rdi

  v5 = pdef;
  v6 = this;
  id.Id = **(_DWORD **)&id.Id;
  Scaleform::GFx::DisplayObject::DisplayObject(
    (Scaleform::GFx::DisplayObject *)&this->vfptr,
    pasRoot,
    pparent,
    (Scaleform::GFx::ResourceId)&id);
  Scaleform::GFx::AS3::AvmDisplayObj::AvmDisplayObj(
    (Scaleform::GFx::AS3::AvmDisplayObj *)&v6->vfptr,
    (Scaleform::GFx::DisplayObject *)&v6->vfptr);
  v6->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  v6->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  v6->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable';
  if ( v5 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)&v5->vfptr);
  v6->pDef.pObject = (Scaleform::GFx::ShapeBaseCharacterDef *)v5;
  v6->pDrawing.pObject = 0i64;
}

// File Line: 797
// RVA: 0x78DC40
void __fastcall Scaleform::GFx::AS3::ShapeObject::~ShapeObject(Scaleform::GFx::AS3::ShapeObject *this)
{
  Scaleform::GFx::AS3::ShapeObject *v1; // rbx
  Scaleform::GFx::DrawingContext *v2; // rcx
  Scaleform::GFx::Resource *v3; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable';
  this->AvmObjOffset = 0;
  v2 = this->pDrawing.pObject;
  if ( v2 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v2->vfptr);
  v3 = (Scaleform::GFx::Resource *)&v1->pDef.pObject->vfptr;
  if ( v3 )
    Scaleform::GFx::Resource::Release(v3);
  Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj((Scaleform::GFx::AS3::AvmDisplayObj *)&v1->vfptr);
  Scaleform::GFx::DisplayObject::~DisplayObject((Scaleform::GFx::DisplayObject *)&v1->vfptr);
}

// File Line: 806
// RVA: 0x7E9250
Scaleform::GFx::DrawingContext *__fastcall Scaleform::GFx::AS3::ShapeObject::GetDrawingContext(Scaleform::GFx::AS3::ShapeObject *this)
{
  Scaleform::GFx::AS3::ShapeObject *v1; // rdi
  Scaleform::GFx::DisplayObject *v2; // rax
  Scaleform::GFx::DisplayObject *v3; // rsi
  Scaleform::GFx::DrawingContext *v4; // rbx
  Scaleform::RefCountNTSImpl *v5; // rcx
  Scaleform::Render::TreeContainer *v6; // rbx

  v1 = this;
  if ( this->pDrawing.pObject )
    return this->pDrawing.pObject;
  v2 = Scaleform::GFx::DisplayObject::GetMask((Scaleform::GFx::DisplayObject *)&this->vfptr);
  v3 = v2;
  if ( v2 )
    ++v2->RefCount;
  if ( v2 )
    Scaleform::GFx::DisplayObject::SetMask((Scaleform::GFx::DisplayObject *)&v1->vfptr, 0i64, 1);
  v4 = Scaleform::GFx::MovieImpl::CreateDrawingContext(v1->pASRoot->pMovieImpl);
  v5 = (Scaleform::RefCountNTSImpl *)&v1->pDrawing.pObject->vfptr;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  v1->pDrawing.pObject = v4;
  v6 = Scaleform::GFx::DisplayObjectBase::ConvertToTreeContainer((Scaleform::GFx::DisplayObjectBase *)&v1->vfptr);
  Scaleform::Render::TreeContainer::Remove(v6, 0i64, 1ui64);
  Scaleform::Render::TreeContainer::Add(
    v6,
    (Scaleform::Render::TreeNode *)&v1->pDrawing.pObject->pTreeContainer.pObject->0);
  if ( v3 )
    Scaleform::GFx::DisplayObject::SetMask((Scaleform::GFx::DisplayObject *)&v1->vfptr, v3, 1);
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v3->vfptr);
  return v1->pDrawing.pObject;
}

// File Line: 833
// RVA: 0x7F0A40
signed __int64 __fastcall Scaleform::GFx::AS3::ShapeObject::GetTopMostMouseEntity(Scaleform::GFx::AS3::ShapeObject *this, Scaleform::Render::Point<float> *pt, Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::DisplayObjectBase::TopMostDescr *v3; // rdi
  Scaleform::GFx::AS3::ShapeObject *v4; // rbx
  signed __int64 result; // rax
  Scaleform::GFx::InteractiveObject *v6; // rax
  bool v7; // zf
  Scaleform::Render::Point<float> p; // [rsp+40h] [rbp+8h]

  v3 = pdescr;
  v4 = this;
  if ( this->pDrawing.pObject )
  {
    if ( Scaleform::GFx::DisplayObject::TransformPointToLocalAndCheckBounds(
           (Scaleform::GFx::DisplayObject *)&this->vfptr,
           &p,
           pt,
           1,
           0i64)
      && Scaleform::GFx::DrawingContext::DefPointTestLocal(
           v4->pDrawing.pObject,
           &p,
           1,
           (Scaleform::GFx::DisplayObjectBase *)&v4->vfptr) )
    {
      v3->pResult = v4->pParent;
      return 1i64;
    }
  }
  else
  {
    v6 = Scaleform::GFx::DisplayObjectBase::GetTopMostMouseEntityDef(
           (Scaleform::GFx::DisplayObjectBase *)&this->vfptr,
           (Scaleform::GFx::CharacterDef *)&this->pDef.pObject->vfptr,
           pt,
           pdescr->TestAll,
           pdescr->pIgnoreMC);
    v3->pResult = v6;
    v7 = v6 == 0i64;
    result = 3i64;
    if ( !v7 )
      return result;
  }
  return 2i64;
}

// File Line: 858
// RVA: 0x807540
char __fastcall Scaleform::GFx::AS3::ShapeObject::PointTestLocal(Scaleform::GFx::AS3::ShapeObject *this, Scaleform::Render::Point<float> *pt, char hitTestMask)
{
  Scaleform::GFx::AS3::ShapeObject *v3; // rbx
  Scaleform::GFx::DrawingContext *v4; // rcx
  char v5; // di
  Scaleform::Render::Point<float> *v6; // rsi
  char result; // al

  v3 = this;
  v4 = this->pDrawing.pObject;
  v5 = hitTestMask;
  v6 = pt;
  if ( v4
    && Scaleform::GFx::DrawingContext::DefPointTestLocal(
         v4,
         pt,
         hitTestMask & 1,
         (Scaleform::GFx::DisplayObjectBase *)&v3->vfptr) )
  {
    result = 1;
  }
  else
  {
    result = ((__int64 (__fastcall *)(Scaleform::GFx::ShapeBaseCharacterDef *, Scaleform::Render::Point<float> *, _QWORD, Scaleform::GFx::AS3::ShapeObject *))v3->pDef.pObject->vfptr[1].GetResourceTypeCode)(
               v3->pDef.pObject,
               v6,
               v5 & 1,
               v3);
  }
  return result;
}

// File Line: 868
// RVA: 0x7E66E0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::AS3::ShapeObject::GetBounds(Scaleform::GFx::AS3::ShapeObject *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::Render::Rect<float> *v3; // rsi
  Scaleform::GFx::AS3::ShapeObject *v4; // rdx
  Scaleform::GFx::DrawingContext *v5; // rcx
  Scaleform::Render::Matrix2x4<float> *v6; // rbp
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  Scaleform::Render::Rect<float> *v12; // rax
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  Scaleform::GFx::ShapeBaseCharacterDef *v16; // rbx
  Scaleform::GFx::ResourceVtbl *v17; // rdi
  Scaleform::Render::Rect<float> *v18; // rax
  float v19; // xmm1_4
  Scaleform::Render::Rect<float> pr; // [rsp+20h] [rbp-28h]
  Scaleform::Render::Rect<float> pRect; // [rsp+30h] [rbp-18h]

  v3 = result;
  v4 = this;
  v5 = this->pDrawing.pObject;
  v6 = transform;
  *(_QWORD *)&v3->x1 = 0i64;
  *(_QWORD *)&v3->x2 = 0i64;
  if ( !v5 )
  {
    v16 = v4->pDef.pObject;
    v17 = v16->vfptr;
    ((void (__fastcall *)(Scaleform::GFx::AS3::ShapeObject *))v4->vfptr[17].__vecDelDtor)(v4);
    v18 = (Scaleform::Render::Rect<float> *)((__int64 (__fastcall *)(Scaleform::GFx::ShapeBaseCharacterDef *, Scaleform::Render::Rect<float> *))v17[1].GetResourceReport)(
                                              v16,
                                              &pr);
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(v6, &pRect, v18);
    v19 = pRect.y1;
    v3->x1 = pRect.x1;
    v14 = pRect.x2;
    v3->y1 = v19;
    v15 = pRect.y2;
    goto LABEL_17;
  }
  pRect = 0i64;
  Scaleform::GFx::DrawingContext::ComputeBound(v5, &pRect);
  if ( pRect.x1 >= pRect.x2 || pRect.y1 >= pRect.y2 )
    return v3;
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(v6, &pr, &pRect);
  v7 = v3->x2;
  if ( v3->x1 >= v7 || (v8 = v3->y1, v9 = v3->y2, v8 >= v9) )
  {
    v13 = pr.y1;
    v3->x1 = pr.x1;
    v14 = pr.x2;
    v3->y1 = v13;
    v15 = pr.y2;
LABEL_17:
    v3->y2 = v15;
    v3->x2 = v14;
    return v3;
  }
  v10 = pr.x1;
  if ( v3->x1 <= pr.x1 )
    v10 = v3->x1;
  if ( v7 <= pr.x2 )
    v7 = pr.x2;
  v11 = pr.y1;
  if ( v8 <= pr.y1 )
    v11 = v3->y1;
  if ( v9 <= pr.y2 )
    v9 = pr.y2;
  v3->x1 = v10;
  v3->y1 = v11;
  v3->x2 = v7;
  v12 = v3;
  v3->y2 = v9;
  return v12;
}

// File Line: 891
// RVA: 0x7BE870
Scaleform::Ptr<Scaleform::Render::TreeNode> *__fastcall Scaleform::GFx::AS3::ShapeObject::CreateRenderNode(Scaleform::GFx::AS3::ShapeObject *this, Scaleform::Ptr<Scaleform::Render::TreeNode> *result, Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::ContextImpl::Context *v3; // rdi
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v4; // rsi
  Scaleform::GFx::ShapeBaseCharacterDef *v5; // rbx
  Scaleform::GFx::MovieDefImpl *v6; // rax

  v3 = context;
  v4 = result;
  v5 = this->pDef.pObject;
  v6 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__cdecl *)(Scaleform::GFx::AS3::ShapeObject *, Scaleform::Ptr<Scaleform::Render::TreeNode> *))this->vfptr[66].__vecDelDtor)(
                                         this,
                                         result);
  Scaleform::GFx::ShapeBaseCharacterDef::CreateTreeShape(v5, v4, v3, v6);
  return v4;
}

