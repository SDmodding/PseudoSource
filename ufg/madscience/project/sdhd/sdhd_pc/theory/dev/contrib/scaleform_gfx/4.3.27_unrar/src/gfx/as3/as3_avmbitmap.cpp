// File Line: 30
// RVA: 0x77AC50
void __fastcall Scaleform::GFx::AS3::AvmBitmap::AvmBitmap(
        Scaleform::GFx::AS3::AvmBitmap *this,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::CharacterCreateInfo *ccinfo,
        Scaleform::GFx::InteractiveObject *pparent,
        _DWORD *id)
{
  _DWORD *v7; // rsi
  Scaleform::GFx::MovieDefImpl *pBindDefImpl; // rbx
  Scaleform::GFx::ImageResource *pResource; // rbx
  Scaleform::GFx::MovieDataDef *pObject; // rcx
  Scaleform::GFx::ImageResource *v11; // rcx
  Scaleform::GFx::ResourceHandle phandle; // [rsp+28h] [rbp-20h] BYREF

  v7 = id;
  LODWORD(id) = *id;
  Scaleform::GFx::DisplayObject::DisplayObject(this, pasRoot, pparent, (Scaleform::GFx::ResourceId)&id);
  Scaleform::GFx::AS3::AvmDisplayObj::AvmDisplayObj(&this->Scaleform::GFx::AS3::AvmDisplayObj, this);
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  this->Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable;
  pBindDefImpl = ccinfo->pBindDefImpl;
  if ( pBindDefImpl )
    Scaleform::Render::RenderBuffer::AddRef(ccinfo->pBindDefImpl);
  this->pDefImpl.pObject = pBindDefImpl;
  this->pImage.pObject = 0i64;
  pResource = (Scaleform::GFx::ImageResource *)ccinfo->pResource;
  if ( *v7 != 0x40000 )
  {
    phandle.HType = RH_Pointer;
    phandle.pResource = 0i64;
    pObject = this->pDefImpl.pObject->pBindData.pObject->pDataDef.pObject;
    LODWORD(id) = *v7;
    if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
           pObject->pData.pObject,
           &phandle,
           (Scaleform::GFx::ResourceId)&id) )
    {
      pResource = (Scaleform::GFx::ImageResource *)Scaleform::GFx::ResourceHandle::GetResource(
                                                     &phandle,
                                                     &this->pDefImpl.pObject->pBindData.pObject->ResourceBinding);
    }
    if ( phandle.HType == RH_Pointer && phandle.pResource )
      Scaleform::GFx::Resource::Release(phandle.pResource);
  }
  if ( pResource
    && (((__int64 (__fastcall *)(Scaleform::GFx::ImageResource *))pResource->vfptr->GetResourceTypeCode)(pResource) & 0xFF00) == 256 )
  {
    Scaleform::Render::RenderBuffer::AddRef(pResource);
    v11 = this->pImage.pObject;
    if ( v11 )
      Scaleform::GFx::Resource::Release(v11);
    this->pImage.pObject = pResource;
  }
}

// File Line: 50
// RVA: 0x7897C0
void __fastcall Scaleform::GFx::AS3::AvmBitmap::~AvmBitmap(Scaleform::GFx::AS3::AvmBitmap *this)
{
  Scaleform::GFx::MovieDefImpl *pObject; // rdx
  Scaleform::GFx::ImageResource *v3; // rcx
  Scaleform::GFx::MovieDefImpl *v4; // rcx

  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  this->Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable;
  pObject = this->pDefImpl.pObject;
  if ( pObject )
    Scaleform::GFx::MovieImpl::AddMovieDefToKillList(this->pASRoot->pMovieImpl, pObject);
  this->AvmObjOffset = 0;
  v3 = this->pImage.pObject;
  if ( v3 )
    Scaleform::GFx::Resource::Release(v3);
  v4 = this->pDefImpl.pObject;
  if ( v4 )
    Scaleform::GFx::Resource::Release(v4);
  Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj(&this->Scaleform::GFx::AS3::AvmDisplayObj);
  Scaleform::GFx::DisplayObject::~DisplayObject(this);
}

// File Line: 64
// RVA: 0x7BB0B0
__int64 __fastcall Scaleform::GFx::AS3::AvmBitmap::CreateASInstance(Scaleform::GFx::AS3::AvmBitmap *this, bool execute)
{
  unsigned int v4; // r15d
  Scaleform::WeakPtrProxy *pWeakProxy; // rcx
  Scaleform::WeakPtrProxy *v6; // rax
  Scaleform::WeakPtrProxy *v7; // rdi
  Scaleform::WeakPtrProxy *v8; // rax
  __int64 v9; // rcx
  unsigned int Flags; // ebx
  bool v11; // zf
  unsigned int v12; // ebx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *pObject; // rbx
  unsigned int *vfptr; // rcx
  Scaleform::GFx::MovieDefImpl *v15; // rax
  Scaleform::String *NameOfExportedResource; // rax
  Scaleform::GFx::AS3::VM *v17; // rsi
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *, unsigned int); // r8
  int v19; // edx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *VStr; // rcx
  Scaleform::GFx::ImageResource *v21; // rsi
  Scaleform::GFx::MovieDefImpl *v22; // rax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value other; // [rsp+48h] [rbp-41h] BYREF
  Scaleform::GFx::AS3::Value ptr; // [rsp+70h] [rbp-19h] BYREF
  Scaleform::GFx::AS3::Value v27; // [rsp+90h] [rbp+7h] BYREF
  Scaleform::GFx::ResourceId rid; // [rsp+F0h] [rbp+67h] BYREF
  int v29; // [rsp+F4h] [rbp+6Bh]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> pobj; // [rsp+100h] [rbp+77h] BYREF

  v4 = 0;
  pWeakProxy = this->pWeakProxy;
  v6 = pWeakProxy;
  if ( !pWeakProxy )
    v6 = *(Scaleform::WeakPtrProxy **)&this->RefCount;
  if ( ((unsigned __int8)v6 & 1) != 0 )
    v6 = (Scaleform::WeakPtrProxy *)((char *)v6 - 1);
  if ( !v6
    && !pWeakProxy
    && !*(_QWORD *)&this->RefCount
    && Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor((Scaleform::GFx::AS3::AvmDisplayObj *)this) )
  {
    v4 = (unsigned int)Scaleform::GFx::AS3::AvmDisplayObj::CallCtor((Scaleform::GFx::AS3::AvmDisplayObj *)this, execute);
  }
  v7 = this->pWeakProxy;
  v8 = v7;
  if ( !v7 )
    v8 = *(Scaleform::WeakPtrProxy **)&this->RefCount;
  if ( ((unsigned __int8)v8 & 1) != 0 )
    v8 = (Scaleform::WeakPtrProxy *)((char *)v8 - 1);
  if ( v8 )
  {
    if ( !v7 )
      v7 = *(Scaleform::WeakPtrProxy **)&this->RefCount;
    if ( ((unsigned __int8)v7 & 1) != 0 )
      v7 = (Scaleform::WeakPtrProxy *)((char *)v7 - 1);
    if ( !v7[6].pObject
      && (*((__int64 (__fastcall **)(Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *))this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr->__vecDelDtor
          + 66))(this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr) )
    {
      ptr.Flags = 4;
      ptr.Bonus.pWeakProxy = 0i64;
      ptr.value.VS._1.VStr = 0i64;
      v27.Flags = 4;
      v27.Bonus.pWeakProxy = 0i64;
      v27.value.VS._1.VStr = 0i64;
      v9 = *(_QWORD *)&this->LastHitTestX;
      if ( v9 && *(_QWORD *)(v9 + 24) )
      {
        (*(void (__fastcall **)(_QWORD, Scaleform::GFx::ResourceId *))(**(_QWORD **)(v9 + 24) + 40i64))(
          *(_QWORD *)(v9 + 24),
          &rid);
        other.Flags = 3;
        other.Bonus.pWeakProxy = 0i64;
        LODWORD(other.value.VNumber) = rid;
        Scaleform::GFx::AS3::Value::Assign(&ptr, &other);
        Flags = other.Flags;
        if ( (other.Flags & 0x1F) > 9 )
        {
          if ( (other.Flags & 0x200) != 0 )
          {
            v11 = other.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&other.Bonus, 0, 24);
            other.Flags = Flags & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
          }
        }
        other.Flags = 3;
        other.Bonus.pWeakProxy = 0i64;
        other.value.VS._1.VInt = v29;
        Scaleform::GFx::AS3::Value::Assign(&v27, &other);
        v12 = other.Flags;
        if ( (other.Flags & 0x1F) > 9 )
        {
          if ( (other.Flags & 0x200) != 0 )
          {
            v11 = other.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&other.Bonus, 0, 24);
            other.Flags = v12 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
          }
        }
      }
      pObject = 0i64;
      pobj.pObject = 0i64;
      vfptr = (unsigned int *)this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr;
      rid.Id = vfptr[10];
      v15 = (Scaleform::GFx::MovieDefImpl *)(*(__int64 (__fastcall **)(unsigned int *))(*(_QWORD *)vfptr + 528i64))(vfptr);
      NameOfExportedResource = Scaleform::GFx::MovieDefImpl::GetNameOfExportedResource(
                                 v15,
                                 (Scaleform::GFx::ResourceId)&rid);
      if ( NameOfExportedResource )
      {
        v17 = (Scaleform::GFx::AS3::VM *)*((_QWORD *)this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr[2].__vecDelDtor
                                         + 10);
        other.Flags = 0;
        other.Bonus.pWeakProxy = 0i64;
        if ( Scaleform::GFx::AS3::VM::Construct(
               v17,
               (const char *)((NameOfExportedResource->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
               *(Scaleform::GFx::AS3::VMAppDomain **)&this->Id.Id,
               &other,
               2u,
               &ptr,
               1) )
        {
          if ( execute )
            Scaleform::GFx::AS3::VM::ExecuteCode(v17, 1u);
          else
            ++v4;
        }
        vecDelDtor = this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr[2].__vecDelDtor;
        if ( *(_BYTE *)(*((_QWORD *)vecDelDtor + 10) + 168i64)
          || (v19 = other.Flags & 0x1F, (other.Flags & 0x1F) == 0)
          || ((VStr = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)other.value.VS._1.VStr,
               (unsigned int)(v19 - 12) <= 3)
           || v19 == 10)
          && !other.value.VS._1.VStr )
        {
          if ( *(_BYTE *)(*((_QWORD *)vecDelDtor + 10) + 168i64) )
            Scaleform::GFx::AS3::VM::OutputAndIgnoreException(*((Scaleform::GFx::AS3::VM **)vecDelDtor + 10));
        }
        else if ( other.value.VS._1.VStr )
        {
          ++other.value.VS._1.VStr->Size;
          VStr->RefCount &= 0x8FBFFFFF;
          pObject = VStr;
          pobj.pObject = VStr;
        }
        if ( (other.Flags & 0x1F) > 9 )
        {
          if ( (other.Flags & 0x200) != 0 )
          {
            v11 = other.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&other.Bonus, 0, 24);
            other.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
          }
        }
      }
      else
      {
        Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
          *((Scaleform::GFx::AS3::VM **)this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr[2].__vecDelDtor
          + 10),
          (Scaleform::GFx::AS3::CheckResult *)&rid,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&pobj,
          "flash.display.BitmapData",
          2u,
          &ptr);
        pObject = pobj.pObject;
      }
      if ( pObject )
      {
        v21 = *(Scaleform::GFx::ImageResource **)&this->LastHitTestX;
        v22 = (Scaleform::GFx::MovieDefImpl *)(*((__int64 (__fastcall **)(Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *))this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr->__vecDelDtor
                                               + 66))(this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr);
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData::CreateLibraryObject(
          (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)pObject,
          v21,
          v22);
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap::SetBitmapData(
          (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)v7,
          (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)pObject);
      }
      if ( pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          pobj.pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)((char *)pObject - 1);
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
      `eh vector destructor iterator(
        &ptr,
        0x20ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    }
  }
  return v4;
}

// File Line: 134
// RVA: 0x7F08D0
__int64 __fastcall Scaleform::GFx::AS3::AvmBitmap::GetTopMostMouseEntity(
        Scaleform::GFx::AS3::AvmBitmap *this,
        Scaleform::Render::Point<float> *pt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::ImageResource *pObject; // rax
  __int64 *v7; // rax
  __int64 v8; // r8
  Scaleform::Render::Rect<float> pr; // [rsp+30h] [rbp-50h] BYREF
  int v11[4]; // [rsp+40h] [rbp-40h] BYREF
  Scaleform::Render::Rect<float> r; // [rsp+50h] [rbp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> v13; // [rsp+60h] [rbp-20h] BYREF
  Scaleform::Render::Point<float> p; // [rsp+90h] [rbp+10h] BYREF

  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::AvmBitmap *))this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(this)
    || !this->pImage.pObject )
  {
    return 2i64;
  }
  Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, &p, pt, 1, 0i64);
  this->pImage.pObject->pImage->vfptr[6].__vecDelDtor(this->pImage.pObject->pImage, (unsigned int)v11);
  *(_QWORD *)&pr.x1 = 0i64;
  pObject = this->pImage.pObject;
  pr.x2 = (float)(v11[2] - v11[0]) * 20.0;
  pr.y2 = (float)(v11[3] - v11[1]) * 20.0;
  v7 = (__int64 *)((__int64 (__fastcall *)(Scaleform::Render::ImageBase *))pObject->pImage->vfptr[9].__vecDelDtor)(pObject->pImage);
  if ( v7 )
  {
    v8 = *v7;
    *(_OWORD *)&v13.M[0][0] = _xmm;
    *(__m128 *)&v13.M[1][0] = _xmm;
    (*(void (__fastcall **)(__int64 *, Scaleform::Render::Matrix2x4<float> *))(v8 + 112))(v7, &v13);
    r = pr;
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v13, &pr, &r);
  }
  if ( p.x > pr.x2 || p.x < pr.x1 || p.y > pr.y2 || p.y < pr.y1 )
    return 2i64;
  pdescr->pResult = this->pParent;
  return 1i64;
}

// File Line: 165
// RVA: 0x8074B0
bool __fastcall Scaleform::GFx::AS3::AvmBitmap::PointTestLocal(
        Scaleform::GFx::AS3::AvmBitmap *this,
        Scaleform::Render::Point<float> *pt,
        __int64 hitTestMask)
{
  Scaleform::GFx::ImageResource *pObject; // rcx
  float y; // xmm0_4
  bool result; // al
  int v7[6]; // [rsp+20h] [rbp-18h] BYREF

  pObject = this->pImage.pObject;
  result = 0;
  if ( pObject )
  {
    ((void (__fastcall *)(Scaleform::Render::ImageBase *, int *, __int64))pObject->pImage->vfptr[6].__vecDelDtor)(
      pObject->pImage,
      v7,
      hitTestMask);
    if ( pt->x <= (float)((float)(v7[2] - v7[0]) * 20.0) && pt->x >= 0.0 )
    {
      y = pt->y;
      if ( y <= (float)((float)(v7[3] - v7[1]) * 20.0) && y >= 0.0 )
        return 1;
    }
  }
  return result;
}

// File Line: 184
// RVA: 0x7E6530
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::AS3::AvmBitmap::GetBounds(
        Scaleform::GFx::AS3::AvmBitmap *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::GFx::ImageResource *pObject; // rcx
  Scaleform::GFx::ImageResource *v7; // rax
  __int64 v8; // rax
  Scaleform::Render::Rect<float> pr; // [rsp+20h] [rbp-50h] BYREF
  int v11; // [rsp+30h] [rbp-40h] BYREF
  int v12; // [rsp+34h] [rbp-3Ch]
  int v13; // [rsp+38h] [rbp-38h]
  int v14; // [rsp+3Ch] [rbp-34h]
  Scaleform::Render::Rect<float> r; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> v16; // [rsp+50h] [rbp-20h] BYREF

  pObject = this->pImage.pObject;
  pr = 0i64;
  if ( pObject )
  {
    pObject->pImage->vfptr[6].__vecDelDtor(pObject->pImage, (unsigned int)&v11);
    v7 = this->pImage.pObject;
    *(_OWORD *)&v16.M[0][0] = _xmm;
    *(__m128 *)&v16.M[1][0] = _xmm;
    v8 = ((__int64 (__fastcall *)(Scaleform::Render::ImageBase *))v7->pImage->vfptr[9].__vecDelDtor)(v7->pImage);
    if ( v8 )
    {
      (*(void (__fastcall **)(__int64, Scaleform::Render::Matrix2x4<float> *))(*(_QWORD *)v8 + 112i64))(v8, &v16);
      r.x1 = (float)(20 * v11);
      r.y1 = (float)(20 * v12);
      r.x2 = (float)(20 * v13);
      r.y2 = (float)(20 * v14);
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v16, &pr, &r);
    }
    else
    {
      pr.x1 = (float)(20 * v11);
      pr.y1 = (float)(20 * v12);
      pr.x2 = (float)(20 * v13);
      pr.y2 = (float)(20 * v14);
    }
  }
  *(_QWORD *)&r.x1 = 0i64;
  r.x2 = pr.x2 - pr.x1;
  r.y2 = pr.y2 - pr.y1;
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, result, &r);
  return result;
}

// File Line: 225
// RVA: 0x80F460
Scaleform::Render::TreeNode *__fastcall Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode(
        Scaleform::GFx::AS3::AvmBitmap *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // rbx
  unsigned __int64 v3; // rsi
  Scaleform::Render::TreeContainer *pParent; // r14
  Scaleform::Render::TreeNode *pObject; // rbp
  unsigned __int64 Size; // r9
  _QWORD *v7; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *vfptr; // rcx
  Scaleform::GFx::ImageResource *ImageResource; // rax
  Scaleform::GFx::ImageResource *v10; // rbx
  Scaleform::GFx::ImageResource *v11; // rcx
  Scaleform::Render::TreeNode *result; // rax
  Scaleform::Render::TreeNode *v13; // rbx
  Scaleform::Render::TreeNode **v14; // r15
  Scaleform::Render::TreeNode *v15; // rcx
  bool v16; // zf
  Scaleform::Render::ContextImpl::Entry *v17; // rcx
  Scaleform::Render::TreeNode *v18; // rcx
  Scaleform::Render::ContextImpl::Entry *v19; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::Render::TreeNode *v20; // [rsp+68h] [rbp+10h]

  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  v3 = 0xFFFFFFFFi64;
  pParent = 0i64;
  pObject = this->pRenNode.pObject;
  if ( pAS3RawPtr )
  {
    if ( pObject && pObject->pParent )
    {
      if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                 + 8i64
                                 * (unsigned int)((int)((_DWORD)pObject - ((unsigned int)pObject & 0xFFFFF000) - 56) / 56)
                                 + 40)
                     + 10i64) & 0x20) == 0 )
        pParent = (Scaleform::Render::TreeContainer *)pObject->pParent;
      v3 = 0i64;
      Size = Scaleform::Render::TreeContainer::GetSize(pParent);
      if ( Size )
      {
        do
        {
          v7 = (_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pParent & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                    + 8i64
                                    * (unsigned int)((__int64)((__int64)&pParent[-1]
                                                             - ((unsigned __int64)pParent & 0xFFFFFFFFFFFFF000ui64))
                                                   / 56)
                                    + 40)
                        + 144i64);
          if ( (*(_BYTE *)v7 & 1) != 0 )
            v7 = (_QWORD *)((*v7 & 0xFFFFFFFFFFFFFFFEui64) + 16);
          if ( (Scaleform::Render::TreeNode *)v7[v3] == pObject )
            break;
          ++v3;
        }
        while ( v3 < Size );
      }
      Scaleform::Render::TreeContainer::Remove(pParent, v3, 1ui64);
    }
    vfptr = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)pAS3RawPtr[1].vfptr;
    if ( vfptr )
    {
      ImageResource = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::GetImageResource(vfptr);
      v10 = ImageResource;
      if ( ImageResource )
      {
        Scaleform::Render::RenderBuffer::AddRef(ImageResource);
        v11 = this->pImage.pObject;
        if ( v11 )
          Scaleform::GFx::Resource::Release(v11);
        this->pImage.pObject = v10;
      }
    }
  }
  result = this->pRenNode.pObject;
  if ( pObject )
  {
    if ( result )
      ++result->RefCount;
    v13 = this->pRenNode.pObject;
    v20 = v13;
    v14 = (Scaleform::Render::TreeNode **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::AvmBitmap *, Scaleform::Render::ContextImpl::Entry **, Scaleform::Render::ContextImpl::Context *))this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[1].__vecDelDtor)(
                                            this,
                                            &v19,
                                            &this->pASRoot->pMovieImpl->RenderContext);
    if ( *v14 )
      ++(*v14)->RefCount;
    v15 = this->pRenNode.pObject;
    if ( v15 )
    {
      v16 = v15->RefCount-- == 1;
      if ( v16 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v15);
    }
    this->pRenNode.pObject = *v14;
    v17 = v19;
    if ( v19 )
    {
      v16 = v19->RefCount-- == 1;
      if ( v16 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v17);
    }
    v18 = this->pRenNode.pObject;
    if ( v18 )
    {
      if ( v13 )
        Scaleform::Render::TreeNode::CopyGeomData(v18, v13);
      else
        Scaleform::Render::TreeNode::SetVisible(
          v18,
          (this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x4000) != 0);
      if ( pParent )
        Scaleform::Render::TreeContainer::Insert(pParent, v3, this->pRenNode.pObject);
    }
    if ( v13 )
    {
      v16 = v13->RefCount-- == 1;
      if ( v16 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v13);
    }
    return this->pRenNode.pObject;
  }
  return result;
}

// File Line: 280
// RVA: 0x7BE7C0
Scaleform::Ptr<Scaleform::Render::TreeNode> *__fastcall Scaleform::GFx::AS3::AvmBitmap::CreateRenderNode(
        Scaleform::GFx::AS3::AvmBitmap *this,
        Scaleform::Ptr<Scaleform::Render::TreeNode> *result,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::TreeShape *v5; // rsi
  Scaleform::Render::TreeNode *pObject; // rcx
  bool v7; // zf
  Scaleform::Render::TreeNode *v8; // rcx
  Scaleform::Render::TreeNode *v9; // rax

  v5 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeShape>(context);
  pObject = this->pRenNode.pObject;
  if ( pObject )
  {
    v7 = pObject->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  this->pRenNode.pObject = v5;
  if ( (unsigned __int8)Scaleform::GFx::AS3::AvmBitmap::CreateBitmapShape(this) )
  {
    v9 = this->pRenNode.pObject;
    if ( v9 )
      ++v9->RefCount;
    result->pObject = (Scaleform::Render::TreeNode *)this->pRenNode;
  }
  else
  {
    v8 = this->pRenNode.pObject;
    if ( v8 )
    {
      v7 = v8->RefCount-- == 1;
      if ( v7 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v8);
    }
    this->pRenNode.pObject = 0i64;
    result->pObject = 0i64;
  }
  return result;
}

// File Line: 291
// RVA: 0x7BB9F0
__int64 __fastcall Scaleform::GFx::AS3::AvmBitmap::CreateBitmapShape(Scaleform::GFx::AS3::AvmBitmap *this)
{
  Scaleform::Render::TreeShape *pObject; // r13
  Scaleform::MemoryHeap *v3; // r12
  Scaleform::Render::ShapeDataFloat *v4; // rax
  Scaleform::Render::ShapeMeshProvider *v5; // r14
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v6; // rax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v7; // r15
  __int64 v8; // rsi
  Scaleform::Render::ImageBase *pImage; // rbx
  Scaleform::GFx::ImageCreator *v10; // rbx
  Scaleform::MemoryHeap *pHeap; // rax
  __int64 v12; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v14; // rcx
  __int64 v15; // rcx
  __int64 v16; // rdi
  bool v17; // zf
  __int64 v18; // rdi
  float StartX; // xmm1_4
  Scaleform::Render::ShapeMeshProvider *v20; // rax
  Scaleform::Render::ShapeMeshProvider *v21; // rax
  void (__fastcall **vfptr)(void *); // rax
  void *v23; // rcx
  unsigned __int8 v24; // bl
  float v25; // xmm1_4
  Scaleform::Render::ShapeMeshProvider *v26; // rax
  Scaleform::Render::ShapeMeshProvider *v27; // rax
  Scaleform::Render::Rect<float> pr; // [rsp+20h] [rbp-E0h] BYREF
  int v30[4]; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::Render::Rect<float> r; // [rsp+40h] [rbp-C0h] BYREF
  int v32; // [rsp+50h] [rbp-B0h]
  __int64 v33; // [rsp+58h] [rbp-A8h]
  int v34; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::MemoryHeap *v35; // [rsp+68h] [rbp-98h]
  int v36; // [rsp+70h] [rbp-90h]
  int v37; // [rsp+74h] [rbp-8Ch]
  __int64 v38; // [rsp+78h] [rbp-88h]
  __int64 v39; // [rsp+80h] [rbp-80h]
  __int64 v40; // [rsp+88h] [rbp-78h]
  __int64 v41; // [rsp+90h] [rbp-70h]
  Scaleform::Render::ShapeMeshProvider *v42; // [rsp+98h] [rbp-68h]
  __int64 v43; // [rsp+A0h] [rbp-60h]
  Scaleform::Render::ShapeMeshProvider *v44; // [rsp+A8h] [rbp-58h]
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v45; // [rsp+B0h] [rbp-50h]
  Scaleform::Render::Matrix2x4<float> v46; // [rsp+C0h] [rbp-40h] BYREF
  Scaleform::MemoryHeap *v47; // [rsp+E0h] [rbp-20h]
  __int64 v48; // [rsp+E8h] [rbp-18h]
  __int64 v49; // [rsp+150h] [rbp+50h] BYREF
  __int64 id; // [rsp+158h] [rbp+58h] BYREF
  Scaleform::Render::ImageBase *v51; // [rsp+160h] [rbp+60h]
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> result; // [rsp+168h] [rbp+68h] BYREF

  v48 = -2i64;
  pObject = (Scaleform::Render::TreeShape *)this->pRenNode.pObject;
  v3 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, pObject);
  v47 = v3;
  v4 = (Scaleform::Render::ShapeDataFloat *)v3->vfptr->Alloc(v3, 128ui64, 0i64);
  v49 = (__int64)v4;
  v5 = 0i64;
  if ( v4 )
  {
    Scaleform::Render::ShapeDataFloat::ShapeDataFloat(v4);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v45 = v7;
  v33 = 0i64;
  v32 = 0;
  v8 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v3->vfptr->Alloc)(v3, 80i64);
  v43 = v8;
  if ( v8 )
  {
    *(_QWORD *)v8 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v8 + 8) = 1;
    *(_QWORD *)v8 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v8 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
    *(_QWORD *)v8 = &Scaleform::RefCountBase<Scaleform::Render::ComplexFill,71>::`vftable;
    *(_QWORD *)v8 = &Scaleform::Render::ComplexFill::`vftable;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 24) = 0i64;
    *(_QWORD *)(v8 + 32) = 1065353216i64;
    *(_QWORD *)(v8 + 40) = 0i64;
    *(_DWORD *)(v8 + 48) = 0;
    *(_QWORD *)(v8 + 52) = 1065353216i64;
    *(_DWORD *)(v8 + 60) = 0;
    *(_BYTE *)(v8 + 64) = 0;
    *(_DWORD *)(v8 + 68) = -1;
  }
  else
  {
    v8 = 0i64;
  }
  v33 = v8;
  if ( this->pImage.pObject )
  {
    v51 = 0i64;
    if ( ((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))this->pImage.pObject->pImage->vfptr[3].__vecDelDtor)(this->pImage.pObject->pImage) )
    {
      pImage = this->pImage.pObject->pImage;
      if ( pImage )
        ((void (__fastcall *)(Scaleform::Render::ImageBase *))pImage->vfptr[1].__vecDelDtor)(this->pImage.pObject->pImage);
      v51 = pImage;
    }
    else
    {
      v10 = Scaleform::GFx::StateBag::GetImageCreator(&this->pASRoot->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
      if ( result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
      if ( !v10 )
      {
        LODWORD(id) = 135168;
        Scaleform::LogDebugMessage((Scaleform::LogMessageId)&id, "Image is not created: cant find ImageCreator.");
        goto LABEL_44;
      }
      pHeap = this->pASRoot->pMovieImpl->pHeap;
      v34 = 3;
      v35 = pHeap;
      v36 = 1;
      v37 = 1;
      v38 = 0i64;
      v39 = 0i64;
      v40 = 0i64;
      v41 = 0i64;
      pImage = (Scaleform::Render::ImageBase *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, Scaleform::Render::ImageBase *))v10->vfptr[4].__vecDelDtor)(
                                                 v10,
                                                 &v34,
                                                 this->pImage.pObject->pImage);
      v51 = pImage;
    }
    if ( pImage )
      ((void (__fastcall *)(Scaleform::Render::ImageBase *))pImage->vfptr[1].__vecDelDtor)(pImage);
    v12 = *(_QWORD *)(v8 + 16);
    if ( v12 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v12 + 16i64))(v12);
    *(_QWORD *)(v8 + 16) = pImage;
    if ( !pImage )
    {
      LODWORD(v49) = 135168;
      Scaleform::LogDebugMessage((Scaleform::LogMessageId)&v49, "Image is not created.");
LABEL_44:
      v24 = 0;
      goto LABEL_54;
    }
    *(_QWORD *)(v8 + 32) = 1028443341i64;
    *(_QWORD *)(v8 + 40) = 0i64;
    *(_DWORD *)(v8 + 48) = 0;
    *(_QWORD *)(v8 + 52) = 1028443341i64;
    *(_DWORD *)(v8 + 60) = 0;
    *(_BYTE *)(v8 + 64) = 1;
    pAS3RawPtr = this->pAS3RawPtr;
    v14 = pAS3RawPtr;
    if ( !pAS3RawPtr )
      v14 = this->pAS3CollectiblePtr.pObject;
    if ( ((unsigned __int8)v14 & 1) != 0 )
      v14 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v14 - 1);
    if ( !v14 )
      goto LABEL_32;
    if ( !pAS3RawPtr )
      pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
    if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
      pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
    if ( BYTE4(pAS3RawPtr[1].pRCCRaw) )
LABEL_32:
      *(_BYTE *)(v8 + 64) = 3;
    pImage->vfptr[6].__vecDelDtor(pImage, (unsigned int)v30);
    *(_OWORD *)&v46.M[0][0] = _xmm;
    *(__m128 *)&v46.M[1][0] = _xmm;
    pImage->vfptr[14].__vecDelDtor(pImage, (unsigned int)&v46);
    pr = 0i64;
    r.x1 = (float)v30[0];
    r.y1 = (float)v30[1];
    r.x2 = (float)v30[2];
    r.y2 = (float)v30[3];
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v46, &pr, &r);
    Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &v7->Fills.Data,
      &v7->Fills,
      v7->Fills.Data.Size + 1);
    v15 = 16 * v7->Fills.Data.Size;
    v16 = (__int64)&v7->Fills.Data.Data[-1];
    v17 = v15 + v16 == 0;
    v18 = v15 + v16;
    v49 = v18;
    id = v18;
    if ( !v17 )
    {
      *(_DWORD *)v18 = 0;
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v8);
      *(_QWORD *)(v18 + 8) = v8;
    }
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      v7,
      1u,
      0,
      0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      v7,
      0.0,
      0.0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      v7,
      (float)(pr.x2 - pr.x1) * 20.0,
      0.0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      v7,
      (float)(pr.x2 - pr.x1) * 20.0,
      (float)(pr.y2 - pr.y1) * 20.0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      v7,
      0.0,
      (float)(pr.y2 - pr.y1) * 20.0);
    StartX = v7->StartX;
    if ( StartX != v7->LastX || v7->StartY != v7->LastY )
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
        v7,
        StartX,
        v7->StartY);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v7);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(v7);
    v20 = (Scaleform::Render::ShapeMeshProvider *)v3->vfptr->Alloc(v3, 144ui64, 0i64);
    v49 = (__int64)v20;
    if ( v20 )
    {
      Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v20, v7, 0i64);
      v5 = v21;
    }
    v44 = v5;
    Scaleform::Render::TreeShape::SetShape(pObject, v5);
    if ( v5 )
      v5->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->Release(&v5->Scaleform::Render::MeshProvider);
    vfptr = (void (__fastcall **)(void *))pImage->vfptr;
    v23 = pImage;
  }
  else
  {
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      v7,
      0,
      0,
      0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      v7,
      0.0,
      0.0);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      v7,
      1.0,
      1.0);
    v25 = v7->StartX;
    if ( v25 != v7->LastX || v7->StartY != v7->LastY )
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
        v7,
        v25,
        v7->StartY);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v7);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(v7);
    v26 = (Scaleform::Render::ShapeMeshProvider *)v3->vfptr->Alloc(v3, 144ui64, 0i64);
    v49 = (__int64)v26;
    if ( v26 )
    {
      Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v26, v7, 0i64);
      v5 = v27;
    }
    v42 = v5;
    Scaleform::Render::TreeShape::SetShape(pObject, v5);
    if ( !v5 )
      goto LABEL_53;
    v23 = &v5->Scaleform::Render::MeshProvider;
    vfptr = (void (__fastcall **)(void *))v5->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr;
  }
  vfptr[2](v23);
LABEL_53:
  v24 = 1;
LABEL_54:
  if ( v8 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v8);
  if ( v7 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7);
  return v24;
}

// File Line: 371
// RVA: 0x7D75B0
void __fastcall Scaleform::GFx::AS3::AvmBitmap::ForceShutdown(Scaleform::GFx::AS3::AvmBitmap *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *pObject; // rcx
  unsigned int RefCount; // eax
  unsigned int v4; // eax

  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
  {
    if ( !this->pAS3CollectiblePtr.pObject )
      return;
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  }
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  if ( pAS3RawPtr )
    pAS3RawPtr->RefCount = (pAS3RawPtr->RefCount + 1) & 0x8FBFFFFF;
  pObject = pAS3RawPtr->pLoaderInfo.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      pAS3RawPtr->pLoaderInfo.pObject = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)((char *)pObject - 1);
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
    pAS3RawPtr->pLoaderInfo.pObject = 0i64;
  }
  if ( ((unsigned __int8)pAS3RawPtr & 1) == 0 )
  {
    v4 = pAS3RawPtr->RefCount;
    if ( (v4 & 0x3FFFFF) != 0 )
    {
      pAS3RawPtr->RefCount = v4 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pAS3RawPtr);
    }
  }
}

// File Line: 379
// RVA: 0x81D470
void __fastcall Scaleform::GFx::AS3::AvmBitmap::SetResourceMovieDef(
        Scaleform::GFx::AS3::AvmBitmap *this,
        Scaleform::GFx::MovieDefImpl *md)
{
  Scaleform::GFx::MovieDefImpl *pObject; // rcx

  if ( md )
    Scaleform::Render::RenderBuffer::AddRef(md);
  pObject = this->pDefImpl.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  this->pDefImpl.pObject = md;
}

