// File Line: 39
// RVA: 0x15880C0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::Bitmap_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_display::BitmapData___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B6B0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData>>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *))Scaleform::GFx::AS3::Instances::fl_display::Bitmap::bitmapDataGet;
  return result;
}

// File Line: 40
// RVA: 0x158F2F0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_display::Bitmap_1_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_display::BitmapData_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B6C0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_display::BitmapData *))Scaleform::GFx::AS3::Instances::fl_display::Bitmap::bitmapDataSet;
  return result;
}

// File Line: 41
// RVA: 0x1588060
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::Bitmap_2_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B6D0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,2,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_display::Bitmap::pixelSnappingGet;
  return result;
}

// File Line: 42
// RVA: 0x158F320
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_display::Bitmap_3_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B6E0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Instances::fl_display::Bitmap::pixelSnappingSet;
  return result;
}

// File Line: 43
// RVA: 0x1588090
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::Bitmap_4_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B6F0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,4,bool>::Method = Scaleform::GFx::AS3::Instances::fl_display::Bitmap::smoothingGet;
  return result;
}

// File Line: 44
// RVA: 0x158F350
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_display::Bitmap_5_Scaleform::GFx::AS3::Value_const__bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B700 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,5,Scaleform::GFx::AS3::Value const,bool>::Method = Scaleform::GFx::AS3::Instances::fl_display::Bitmap::smoothingSet;
  return result;
}

// File Line: 60
// RVA: 0x832330
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::bitmapDataGet(
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *p_pContextMenu; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // rcx
  unsigned int RefCount; // eax

  p_pContextMenu = &this->pContextMenu;
  if ( &this->pContextMenu != result )
  {
    if ( p_pContextMenu->pObject )
      p_pContextMenu->pObject->RefCount = (p_pContextMenu->pObject->RefCount + 1) & 0x8FBFFFFF;
    pObject = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)pObject - 1);
        result->pObject = p_pContextMenu->pObject;
        return;
      }
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    result->pObject = p_pContextMenu->pObject;
  }
}

// File Line: 67
// RVA: 0x82DCB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::bitmapDataSet(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl::XMLList *value)
{
  Scaleform::GFx::DisplayObject *pObject; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v5; // rdi
  Scaleform::GFx::Resource *v6; // rdi
  Scaleform::GFx::Resource *pParent; // rcx
  Scaleform::GFx::Resource *v8; // rcx
  Scaleform::GFx::AS3::AvmBitmap *v9; // rcx

  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->pBitmapData,
    value);
  pObject = this->pDispObj.pObject;
  if ( pObject )
  {
    v5 = this->pBitmapData.pObject;
    if ( v5 )
    {
      v6 = v5->pDefImpl.pObject;
      if ( v6 )
        Scaleform::Render::RenderBuffer::AddRef(v6);
      pParent = (Scaleform::GFx::Resource *)pObject[1].pParent;
      if ( pParent )
        Scaleform::GFx::Resource::Release(pParent);
      pObject[1].pParent = (Scaleform::GFx::InteractiveObject *)v6;
    }
    else
    {
      v8 = (Scaleform::GFx::Resource *)pObject[1].pParent;
      if ( v8 )
        Scaleform::GFx::Resource::Release(v8);
      pObject[1].pParent = 0i64;
    }
  }
  v9 = (Scaleform::GFx::AS3::AvmBitmap *)this->pDispObj.pObject;
  if ( v9 )
    Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode(v9);
}

// File Line: 83
// RVA: 0x8574B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::pixelSnappingGet(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap::PixelSnappingType PixelSnapping; // r8d
  __int32 v3; // r8d

  PixelSnapping = this->PixelSnapping;
  if ( PixelSnapping )
  {
    v3 = PixelSnapping - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
        Scaleform::GFx::ASString::operator=(result, "auto");
    }
    else
    {
      Scaleform::GFx::ASString::operator=(result, "always");
    }
  }
  else
  {
    Scaleform::GFx::ASString::operator=(result, "never");
  }
}

// File Line: 96
// RVA: 0x857500
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::pixelSnappingSet(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap::PixelSnappingType v4; // eax
  Scaleform::GFx::AS3::AvmBitmap *pObject; // rcx

  v4 = (unsigned int)Scaleform::GFx::AS3::Instances::fl_display::Bitmap::String2PixelSnapping(this, value->pNode->pData);
  pObject = (Scaleform::GFx::AS3::AvmBitmap *)this->pDispObj.pObject;
  this->PixelSnapping = v4;
  if ( pObject )
    Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode(pObject);
}

// File Line: 104
// RVA: 0x85F6B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::smoothingGet(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        bool *result)
{
  *result = this->Smoothing;
}

// File Line: 111
// RVA: 0x85F6C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::smoothingSet(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        Scaleform::GFx::AS3::Value *result,
        bool value)
{
  Scaleform::GFx::AS3::AvmBitmap *pObject; // rcx

  this->Smoothing = value;
  pObject = (Scaleform::GFx::AS3::AvmBitmap *)this->pDispObj.pObject;
  if ( pObject )
    Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode(pObject);
}

// File Line: 142
// RVA: 0x7D53C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_display::Shape *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ForEachChild_GC(this, prcc, op);
  if ( this->pLoaderInfo.pObject )
    op(prcc, &this->pLoaderInfo.pObject);
  if ( this->pGraphics.pObject )
    op(prcc, &this->pGraphics.pObject);
}

// File Line: 148
// RVA: 0x795360
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::DisplayObject *pObject; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v7; // rdx
  Scaleform::GFx::Resource *pParent; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS3::AvmBitmap *v12; // rcx
  Scaleform::GFx::AS3::CheckResult v13; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+20h] BYREF

  if ( argc )
  {
    if ( Scaleform::GFx::AS3::VM::IsOfType(
           this->pTraits.pObject->pVM,
           argv,
           "flash.display.BitmapData",
           this->pTraits.pObject->pVM->CurrentDomain.pObject) )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->pBitmapData,
        (Scaleform::GFx::AS3::Instances::fl::XMLList *)argv->value.VS._1.VStr);
      pObject = this->pDispObj.pObject;
      if ( pObject )
      {
        v7 = this->pBitmapData.pObject;
        if ( v7 )
        {
          Scaleform::GFx::AS3::AvmBitmap::SetResourceMovieDef(
            (Scaleform::GFx::AS3::AvmBitmap *)this->pDispObj.pObject,
            v7->pDefImpl.pObject);
        }
        else
        {
          pParent = (Scaleform::GFx::Resource *)pObject[1].pParent;
          if ( pParent )
            Scaleform::GFx::Resource::Release(pParent);
          pObject[1].pParent = 0i64;
        }
      }
    }
    if ( argc >= 2 )
    {
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
        this->pTraits.pObject->pVM->StringManagerRef,
        &result);
      if ( !Scaleform::GFx::AS3::Value::Convert2String(argv + 1, &v13, &result)->Result )
      {
        pNode = result.pNode;
        v10 = result.pNode->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        return;
      }
      this->PixelSnapping = Scaleform::GFx::AS3::Instances::fl_display::Bitmap::String2PixelSnapping(
                              this,
                              result.pNode->pData);
      if ( argc >= 3 )
        this->Smoothing = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 2);
      v11 = result.pNode;
      v10 = result.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    }
    v12 = (Scaleform::GFx::AS3::AvmBitmap *)this->pDispObj.pObject;
    if ( v12 )
      Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode(v12);
  }
}

// File Line: 183
// RVA: 0x7F2D00
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::InitInstance(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        bool extCall)
{
  if ( !extCall )
    Scaleform::GFx::AS3::Instances::fl_display::Bitmap::CreateStageObject(this);
}

// File Line: 193
// RVA: 0x7BEB20
Scaleform::GFx::DisplayObject *__fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::CreateStageObject(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this)
{
  Scaleform::GFx::AS3::ASVM *pVM; // r14
  Scaleform::GFx::AS3::MovieRoot *pMovieRoot; // rsi
  Scaleform::GFx::MovieDefImpl *ResourceMovieDef; // rax
  Scaleform::GFx::MovieDefRootNode *i; // rbx
  __int64 v6; // rax
  Scaleform::GFx::ASSupport *pObject; // rcx
  Scaleform::GFx::DisplayObject *v8; // rbx
  Scaleform::GFx::DisplayObject *v9; // rcx
  _QWORD *v10; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Traits *v13; // rsi
  __int64 v14; // rax
  Scaleform::GFx::AS3::VMAppDomain *v15; // rax
  Scaleform::GFx::AS3::CheckResult *v16; // rax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v17; // rbx
  unsigned int v18; // eax
  Scaleform::GFx::CharacterCreateInfo pccinfo; // [rsp+38h] [rbp-21h] BYREF
  Scaleform::GFx::AS3::Value ptr; // [rsp+50h] [rbp-9h] BYREF
  int v22; // [rsp+70h] [rbp+17h]
  __int64 v23; // [rsp+78h] [rbp+1Fh]
  __int64 v24; // [rsp+80h] [rbp+27h]
  int result; // [rsp+C0h] [rbp+67h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> pobj; // [rsp+C8h] [rbp+6Fh] BYREF

  if ( this->pDispObj.pObject )
    return this->pDispObj.pObject;
  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  pMovieRoot = pVM->pMovieRoot;
  ResourceMovieDef = Scaleform::GFx::AS3::ASVM::GetResourceMovieDef(pVM, this);
  if ( ResourceMovieDef )
  {
    memset(&pccinfo, 0, sizeof(pccinfo));
    if ( !Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::FindLibarySymbol(this, &pccinfo, ResourceMovieDef) )
    {
      for ( i = pMovieRoot->pMovieImpl->RootMovieDefNodes.Root.pNext; ; i = i->pNext )
      {
        v6 = pMovieRoot->pMovieImpl == (Scaleform::GFx::MovieImpl *)-112i64
           ? 0i64
           : (__int64)&pMovieRoot->pMovieImpl->MovieLevels.Data.Policy;
        if ( i == (Scaleform::GFx::MovieDefRootNode *)v6 )
          break;
        if ( Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::FindLibarySymbol(this, &pccinfo, i->pDefImpl) )
          goto LABEL_12;
      }
      pccinfo.pCharDef = 0i64;
      pccinfo.pResource = 0i64;
    }
LABEL_12:
    pObject = pMovieRoot->pASSupport.pObject;
    result = 0x40000;
    v8 = (Scaleform::GFx::DisplayObject *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *, _QWORD, int *, int, __int64))pObject->vfptr[4].__vecDelDtor)(
                                            pObject,
                                            pMovieRoot->pMovieImpl,
                                            &pccinfo,
                                            0i64,
                                            &result,
                                            8,
                                            -2i64);
    v9 = this->pDispObj.pObject;
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
    this->pDispObj.pObject = v8;
    if ( v8 )
      v10 = (Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                  + 4 * (unsigned __int8)v8->AvmObjOffset);
    else
      v10 = 0i64;
    v10[2] = this;
    v11 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v10[1];
    if ( v11 )
    {
      if ( ((unsigned __int8)v11 & 1) != 0 )
      {
        v10[1] = (char *)v11 - 1;
      }
      else
      {
        RefCount = v11->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v11->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
        }
      }
      v10[1] = 0i64;
    }
    v13 = this->pTraits.pObject;
    v14 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))v13->vfptr[2].~RefCountBaseGC<328>)(v13);
    if ( v14 )
      v15 = *(Scaleform::GFx::AS3::VMAppDomain **)(v14 + 48);
    else
      v15 = v13->pVM->SystemDomain.pObject;
    if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
      v10[5] = v15;
    if ( pccinfo.pResource
      && (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))pccinfo.pResource->vfptr->GetResourceTypeCode)(pccinfo.pResource) & 0xFF00) == 256 )
    {
      ptr.Flags = 4;
      ptr.Bonus.pWeakProxy = 0i64;
      ptr.value.VS._1.VStr = 0i64;
      v22 = 4;
      v23 = 0i64;
      v24 = 0i64;
      pobj.pObject = 0i64;
      v16 = Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
              pVM,
              (Scaleform::GFx::AS3::CheckResult *)&result,
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&pobj,
              "flash.display.BitmapData",
              2u,
              &ptr);
      v17 = pobj.pObject;
      if ( v16->Result
        && Scaleform::GFx::AS3::Instances::fl_display::BitmapData::CreateLibraryObject(
             (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)pobj.pObject,
             (Scaleform::GFx::ImageResource *)pccinfo.pResource,
             pccinfo.pBindDefImpl) )
      {
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap::SetBitmapData(
          this,
          (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)v17);
      }
      if ( v17 )
      {
        if ( ((unsigned __int8)v17 & 1) != 0 )
        {
          pobj.pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)((char *)v17 - 1);
        }
        else
        {
          v18 = v17->RefCount;
          if ( (v18 & 0x3FFFFF) != 0 )
          {
            v17->RefCount = v18 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
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
  return this->pDispObj.pObject;
}

// File Line: 254
// RVA: 0x822890
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::String2PixelSnapping(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        const char *str)
{
  __int64 result; // rax
  __int64 v5; // r9
  char v6; // r8
  __int64 v7; // rdx
  char v8; // cl
  char v9; // cl
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+28h] [rbp-20h] BYREF

  result = 0i64;
  v5 = 0i64;
  while ( 1 )
  {
    v6 = str[v5++];
    if ( v6 != aNever[v5 - 1] )
      break;
    if ( v5 == 6 )
      return result;
  }
  v7 = 0i64;
  while ( 1 )
  {
    v8 = str[v7++];
    if ( v8 != aAlways[v7 - 1] )
      break;
    if ( v7 == 7 )
      return 1i64;
  }
  while ( 1 )
  {
    v9 = str[result++];
    if ( v9 != aAuto[result - 1] )
      break;
    if ( result == 5 )
      return 2i64;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v13, 2008, this->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    this->pTraits.pObject->pVM,
    v10,
    &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  pNode = v13.Message.pNode;
  if ( v13.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return 0i64;
}

// File Line: 303
// RVA: 0x7FF1F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::Bitmap::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_display::Bitmap *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::Bitmap *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::Bitmap> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::Bitmap> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_display::Bitmap::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 326
// RVA: 0x7559A0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_display::Bitmap::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_display::BitmapCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::DisplayObject::`vftable;
    v6->TraitsType = Traits_DisplayObject_Begin;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::Bitmap::`vftable;
    v6->TraitsType = Traits_Bitmap;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8.pV = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_display::BitmapCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::`vftable;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::DisplayObject::`vftable;
    v8.pV->TraitsType = Traits_DisplayObject_Begin;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::Bitmap::`vftable;
    v8.pV->TraitsType = Traits_Bitmap;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
  return result;
}

