// File Line: 39
// RVA: 0x15880C0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::Bitmap_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_display::BitmapData___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B6B0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData>>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *))Scaleform::GFx::AS3::Instances::fl_display::Bitmap::bitmapDataGet;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Bitmap,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *>::Method = Scaleform::GFx::AS3::Instances::fl_display::Bitmap::bitmapDataSet;
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
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::bitmapDataGet(Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl::Object **v2; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rcx
  unsigned int v5; // eax

  v2 = &this->pContextMenu.pObject;
  v3 = result;
  if ( &this->pContextMenu != result )
  {
    if ( *v2 )
      (*v2)->RefCount = ((*v2)->RefCount + 1) & 0x8FBFFFFF;
    v4 = result->pObject;
    if ( result->pObject )
    {
      if ( (unsigned __int8)v4 & 1 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v4 - 1);
        result->pObject = *v2;
        return;
      }
      v5 = v4->RefCount;
      if ( v5 & 0x3FFFFF )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
    v3->pObject = *v2;
  }
}

// File Line: 67
// RVA: 0x82DCB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::bitmapDataSet(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_display::BitmapData *value)
{
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap *v3; // rsi
  Scaleform::GFx::DisplayObject *v4; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v5; // rdi
  Scaleform::GFx::Resource *v6; // rdi
  Scaleform::GFx::Resource *v7; // rcx
  Scaleform::GFx::Resource *v8; // rcx
  Scaleform::GFx::AS3::AvmBitmap *v9; // rcx

  v3 = this;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->pBitmapData,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)value);
  v4 = v3->pDispObj.pObject;
  if ( v4 )
  {
    v5 = v3->pBitmapData.pObject;
    if ( v5 )
    {
      v6 = (Scaleform::GFx::Resource *)&v5->pDefImpl.pObject->vfptr;
      if ( v6 )
        Scaleform::Render::RenderBuffer::AddRef(v6);
      v7 = (Scaleform::GFx::Resource *)v4[1].pParent;
      if ( v7 )
        Scaleform::GFx::Resource::Release(v7);
      v4[1].pParent = (Scaleform::GFx::InteractiveObject *)v6;
    }
    else
    {
      v8 = (Scaleform::GFx::Resource *)v4[1].pParent;
      if ( v8 )
        Scaleform::GFx::Resource::Release(v8);
      v4[1].pParent = 0i64;
    }
  }
  v9 = (Scaleform::GFx::AS3::AvmBitmap *)v3->pDispObj.pObject;
  if ( v9 )
    Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode(v9);
}

// File Line: 83
// RVA: 0x8574B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::pixelSnappingGet(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap::PixelSnappingType v2; // er8
  int v3; // er8

  v2 = this->PixelSnapping;
  if ( v2 )
  {
    v3 = v2 - 1;
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
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::pixelSnappingSet(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap::PixelSnappingType v4; // eax
  Scaleform::GFx::AS3::AvmBitmap *v5; // rcx

  v3 = this;
  v4 = (unsigned int)Scaleform::GFx::AS3::Instances::fl_display::Bitmap::String2PixelSnapping(this, value->pNode->pData);
  v5 = (Scaleform::GFx::AS3::AvmBitmap *)v3->pDispObj.pObject;
  v3->PixelSnapping = v4;
  if ( v5 )
    Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode(v5);
}

// File Line: 104
// RVA: 0x85F6B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::smoothingGet(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this, bool *result)
{
  *result = this->Smoothing;
}

// File Line: 111
// RVA: 0x85F6C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::smoothingSet(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this, Scaleform::GFx::AS3::Value *result, bool value)
{
  this->Smoothing = value;
  JUMPOUT(this->pDispObj.pObject, 0i64, Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode);
}

// File Line: 142
// RVA: 0x7D53C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::ForEachChild_GC(Scaleform::GFx::AS3::Instances::fl_display::Shape *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rbx
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::Shape *v5; // rsi

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ForEachChild_GC(
    (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&this->vfptr,
    prcc,
    op);
  if ( v5->pLoaderInfo.pObject )
    v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v5->pLoaderInfo);
  if ( v5->pGraphics.pObject )
    v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v5->pGraphics);
}

// File Line: 148
// RVA: 0x795360
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::AS3Constructor(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // rbp
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap *v5; // rdi
  Scaleform::GFx::DisplayObject *v6; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v7; // rdx
  Scaleform::GFx::Resource *v8; // rcx
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS3::AvmBitmap *v12; // rcx
  Scaleform::GFx::AS3::CheckResult v13; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+20h]

  if ( argc >= 1 )
  {
    v3 = argv;
    v4 = argc;
    v5 = this;
    if ( Scaleform::GFx::AS3::VM::IsOfType(
           this->pTraits.pObject->pVM,
           argv,
           "flash.display.BitmapData",
           this->pTraits.pObject->pVM->CurrentDomain.pObject) )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v5->pBitmapData,
        (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3->value.VS._1.VStr);
      v6 = v5->pDispObj.pObject;
      if ( v6 )
      {
        v7 = v5->pBitmapData.pObject;
        if ( v7 )
        {
          Scaleform::GFx::AS3::AvmBitmap::SetResourceMovieDef(
            (Scaleform::GFx::AS3::AvmBitmap *)v5->pDispObj.pObject,
            v7->pDefImpl.pObject);
        }
        else
        {
          v8 = (Scaleform::GFx::Resource *)v6[1].pParent;
          if ( v8 )
            Scaleform::GFx::Resource::Release(v8);
          v6[1].pParent = 0i64;
        }
      }
    }
    if ( v4 >= 2 )
    {
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->pTraits.pObject->pVM->StringManagerRef->Builtins,
        &result);
      if ( !Scaleform::GFx::AS3::Value::Convert2String(v3 + 1, &v13, &result)->Result )
      {
        v9 = result.pNode;
        v10 = result.pNode->RefCount == 1;
        --v9->RefCount;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
        return;
      }
      v5->PixelSnapping = Scaleform::GFx::AS3::Instances::fl_display::Bitmap::String2PixelSnapping(
                            v5,
                            result.pNode->pData);
      if ( v4 >= 3 )
        v5->Smoothing = Scaleform::GFx::AS3::Value::Convert2Boolean(v3 + 2);
      v11 = result.pNode;
      v10 = result.pNode->RefCount == 1;
      --v11->RefCount;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    }
    v12 = (Scaleform::GFx::AS3::AvmBitmap *)v5->pDispObj.pObject;
    if ( v12 )
      Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode(v12);
  }
}

// File Line: 183
// RVA: 0x7F2D00
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::InitInstance(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this, bool extCall)
{
  JUMPOUT(extCall, 0, Scaleform::GFx::AS3::Instances::fl_display::Bitmap::CreateStageObject);
}

// File Line: 193
// RVA: 0x7BEB20
Scaleform::GFx::DisplayObject *__fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::CreateStageObject(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap *v1; // rdi
  Scaleform::GFx::AS3::ASVM *v2; // r14
  Scaleform::GFx::AS3::MovieRoot *v3; // rsi
  Scaleform::GFx::MovieDefImpl *v4; // rax
  Scaleform::GFx::MovieDefRootNode *i; // rbx
  signed __int64 v6; // rax
  Scaleform::GFx::ASSupport *v7; // rcx
  __int64 v8; // rbx
  Scaleform::RefCountNTSImpl *v9; // rcx
  _QWORD *v10; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::Traits *v13; // rsi
  __int64 v14; // rax
  Scaleform::GFx::AS3::VMAppDomain *v15; // rax
  Scaleform::GFx::AS3::CheckResult *v16; // rax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v17; // rbx
  unsigned int v18; // eax
  Scaleform::GFx::CharacterCreateInfo pccinfo; // [rsp+38h] [rbp-21h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+50h] [rbp-9h]
  int v22; // [rsp+70h] [rbp+17h]
  __int64 v23; // [rsp+78h] [rbp+1Fh]
  __int64 v24; // [rsp+80h] [rbp+27h]
  int result; // [rsp+C0h] [rbp+67h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> pobj; // [rsp+C8h] [rbp+6Fh]

  v1 = this;
  if ( this->pDispObj.pObject )
    return this->pDispObj.pObject;
  v2 = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  v3 = v2->pMovieRoot;
  v4 = Scaleform::GFx::AS3::ASVM::GetResourceMovieDef(v2, (Scaleform::GFx::AS3::Instances::fl::Object *)&this->vfptr);
  if ( v4 )
  {
    pccinfo.pBindDefImpl = 0i64;
    pccinfo.pResource = 0i64;
    pccinfo.pCharDef = 0i64;
    if ( !Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::FindLibarySymbol(
            (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)&v1->vfptr,
            &pccinfo,
            v4) )
    {
      for ( i = v3->pMovieImpl->RootMovieDefNodes.Root.pNext; ; i = i->pNext )
      {
        v6 = (signed __int64)(v3->pMovieImpl == (Scaleform::GFx::MovieImpl *)-112i64 ? 0i64 : &v3->pMovieImpl->MovieLevels.Data.Policy);
        if ( i == (Scaleform::GFx::MovieDefRootNode *)v6 )
          break;
        if ( Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::FindLibarySymbol(
               (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)&v1->vfptr,
               &pccinfo,
               i->pDefImpl) )
        {
          goto LABEL_12;
        }
      }
      pccinfo.pCharDef = 0i64;
      pccinfo.pResource = 0i64;
    }
LABEL_12:
    v7 = v3->pASSupport.pObject;
    result = 0x40000;
    v8 = ((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *, _QWORD, int *, signed int, signed __int64))v7->vfptr[4].__vecDelDtor)(
           v7,
           v3->pMovieImpl,
           &pccinfo,
           0i64,
           &result,
           8,
           -2i64);
    v9 = (Scaleform::RefCountNTSImpl *)&v1->pDispObj.pObject->vfptr;
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release(v9);
    v1->pDispObj.pObject = (Scaleform::GFx::DisplayObject *)v8;
    if ( v8 )
      v10 = (_QWORD *)(v8 + 4i64 * *(unsigned __int8 *)(v8 + 109));
    else
      v10 = 0i64;
    v10[2] = v1;
    v11 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v10[1];
    if ( v11 )
    {
      if ( (unsigned __int8)v11 & 1 )
      {
        v10[1] = (char *)v11 - 1;
      }
      else
      {
        v12 = v11->RefCount;
        if ( v12 & 0x3FFFFF )
        {
          v11->RefCount = v12 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
        }
      }
      v10[1] = 0i64;
    }
    v13 = v1->pTraits.pObject;
    v14 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))v13->vfptr[2].~RefCountBaseGC<328>)(v1->pTraits.pObject);
    if ( v14 )
      v15 = *(Scaleform::GFx::AS3::VMAppDomain **)(v14 + 48);
    else
      v15 = v13->pVM->SystemDomain.pObject;
    if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
      v10[5] = v15;
    if ( pccinfo.pResource && (((__int64 (*)(void))pccinfo.pResource->vfptr->GetResourceTypeCode)() & 0xFF00) == 256 )
    {
      ptr.Flags = 4;
      ptr.Bonus.pWeakProxy = 0i64;
      ptr.value.VNumber = 0.0;
      v22 = 4;
      v23 = 0i64;
      v24 = 0i64;
      pobj.pObject = 0i64;
      v16 = Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
              (Scaleform::GFx::AS3::VM *)&v2->vfptr,
              (Scaleform::GFx::AS3::CheckResult *)&result,
              &pobj,
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
          v1,
          (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)v17);
      }
      if ( v17 )
      {
        if ( (unsigned __int8)v17 & 1 )
        {
          pobj.pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)((char *)v17 - 1);
        }
        else
        {
          v18 = v17->RefCount;
          if ( v18 & 0x3FFFFF )
          {
            v17->RefCount = v18 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v17->vfptr);
          }
        }
      }
      `eh vector destructor iterator'(
        &ptr,
        0x20ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    }
  }
  return v1->pDispObj.pObject;
}

// File Line: 254
// RVA: 0x822890
signed __int64 __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::String2PixelSnapping(Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this, const char *str)
{
  const char *v2; // r10
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap *v3; // rbx
  signed __int64 result; // rax
  __int64 v5; // r9
  char v6; // r8
  __int64 v7; // rdx
  char v8; // cl
  char v9; // cl
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+28h] [rbp-20h]

  v2 = str;
  v3 = this;
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
    v8 = v2[v7++];
    if ( v8 != aAlways[v7 - 1] )
      break;
    if ( v7 == 7 )
      return 1i64;
  }
  while ( 1 )
  {
    v9 = v2[result++];
    if ( v9 != aAuto[result - 1] )
      break;
    if ( result == 5 )
      return 2i64;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v13, eInvalidEnumError, v3->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3->pTraits.pObject->pVM, v10, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
  v11 = v13.Message.pNode;
  v12 = v13.Message.pNode->RefCount == 1;
  --v11->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  return 0i64;
}

// File Line: 303
// RVA: 0x7FF1F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::Bitmap::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_display::Bitmap *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::Bitmap> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_display::Bitmap::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_display::Bitmap *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 326
// RVA: 0x7559A0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_display::Bitmap::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_display::BitmapCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::DisplayObject::`vftable';
    v6->TraitsType = 22;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::Bitmap::`vftable';
    v6->TraitsType = 27;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8.pV = (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v7->vfptr;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_display::BitmapCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::`vftable';
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::DisplayObject::`vftable';
    v8.pV->TraitsType = 22;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::Bitmap::`vftable';
    v8.pV->TraitsType = 27;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
  return v3;
}

