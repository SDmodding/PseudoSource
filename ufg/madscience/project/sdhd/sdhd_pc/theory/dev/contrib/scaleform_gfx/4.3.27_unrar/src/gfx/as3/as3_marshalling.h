// File Line: 63
// RVA: 0x76C400
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *__fastcall Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>>(
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::StringManager *__formal)
{
  result->pObject = 0i64;
  return result;
}

// File Line: 152
// RVA: 0x76C430
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::StringManager *sm)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(sm, result);
  return result;
}

// File Line: 166
// RVA: 0x76C310
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::AS3::Value const &>(
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::StringManager *__formal)
{
  Scaleform::GFx::AS3::Value::V1U VObj; // rax

  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  result->Flags = v.Flags;
  result->Bonus.pWeakProxy = v.Bonus.pWeakProxy;
  result->value = v.value;
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else
    {
      if ( (v.Flags & 0x1F) == 10 )
      {
        ++v.value.VS._1.VStr->RefCount;
        return result;
      }
      if ( (v.Flags & 0x1F) > 0xA )
      {
        if ( (v.Flags & 0x1F) <= 0xF )
        {
          VObj = v.value.VS._1;
        }
        else
        {
          if ( (v.Flags & 0x1F) > 0x11 )
            return result;
          VObj = (Scaleform::GFx::AS3::Value::V1U)v.value.VS._2.VObj;
        }
        if ( VObj.VStr )
        {
          ++VObj.VStr->Size;
          VObj.VStr->Size &= 0x8FBFFFFF;
        }
      }
    }
  }
  return result;
}

// File Line: 195
// RVA: 0x883B60
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext,1,0,Scaleform::GFx::ASString const &>(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::StringManager *sm)
{
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(result, sm);
  return result;
}

// File Line: 1402
// RVA: 0x8D40D0
void __fastcall Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,18,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Func(
        Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,18,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *> *this,
        Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *a3,
        Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,18,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)((char *)a3->StringManagerRef + (int)qword_142440B58),
    obj,
    (unsigned int)result,
    argc);
}

// File Line: 2156
// RVA: 0x788080
void __fastcall Scaleform::GFx::AS3::UnboxArgV0<bool>::~UnboxArgV0<bool>(Scaleform::GFx::AS3::UnboxArgV0<bool> *this)
{
  Scaleform::GFx::AS3::Value *Result; // rdx
  Scaleform::GFx::AS3::Value::VU v2; // [rsp+0h] [rbp-18h]

  if ( !this->Vm->HandleException )
  {
    Result = this->Result;
    v2.VS._1.VBool = this->r;
    Result->Flags = Result->Flags & 0xFFFFFFE0 | 1;
    Result->value = v2;
  }
}

// File Line: 2342
// RVA: 0x778A80
void __fastcall Scaleform::GFx::AS3::UnboxArgV2<bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double>::UnboxArgV2<bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double>(
        Scaleform::GFx::AS3::UnboxArgV2<bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double> *da)
{
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double> *v9; // r14
  Scaleform::GFx::AS3::Value *v10; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v11; // rax
  Scaleform::GFx::AS3::Value v13; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+98h] [rbp+20h] BYREF

  this->Vm = vm;
  this->Result = result;
  this->r = 0;
  v9 = da;
  this->a0 = da->_0;
  v10 = argv;
  if ( argc )
  {
    v13.Flags = 0;
    v13.Bonus.pWeakProxy = 0i64;
    v11 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, &Scaleform::GFx::AS3::fl_geom::Vector3DTI);
    if ( !v11
      || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v11->vfptr[3].Finalize_GC)(
            v11,
            v10,
            &v13) )
    {
      Scaleform::GFx::AS3::Value::Assign(&v13, v10);
    }
    this->a0 = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)v13.value.VS._1.VStr;
    if ( (v13.Flags & 0x1F) > 9 )
    {
      if ( (v13.Flags & 0x200) != 0 )
      {
        if ( v13.Bonus.pWeakProxy->RefCount-- == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v13.Bonus, 0, 24);
        v13.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v13);
      }
    }
  }
  this->a1 = v9->_1;
  if ( !vm->HandleException && argc > 1 )
    Scaleform::GFx::AS3::Value::Convert2Number(v10 + 1, &resulta, &this->a1);
}

// File Line: 2419
// RVA: 0x776760
void __fastcall Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,Scaleform::GFx::AS3::Value const &>::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextField *,Scaleform::GFx::AS3::Value const &>(
        Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::AS3::Instances::fl_text::TextField *,Scaleform::GFx::AS3::Value const &> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Instances::fl_text::TextField *,Scaleform::GFx::AS3::Value const &> *da)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v8; // rax
  Scaleform::GFx::AS3::Value *v10; // rax
  Scaleform::GFx::AS3::Value v11; // [rsp+28h] [rbp-30h] BYREF

  this->Vm = vm;
  this->r = result;
  this->a0 = da->_0;
  if ( argc )
  {
    v11.Flags = 0;
    v11.Bonus.pWeakProxy = 0i64;
    v8 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, &Scaleform::GFx::AS3::fl_text::TextFieldTI);
    if ( !v8
      || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v8->vfptr[3].Finalize_GC)(
            v8,
            argv,
            &v11) )
    {
      Scaleform::GFx::AS3::Value::Assign(&v11, argv);
    }
    this->a0 = (Scaleform::GFx::AS3::Instances::fl_text::TextField *)v11.value.VS._1.VStr;
    if ( (v11.Flags & 0x1F) > 9 )
    {
      if ( (v11.Flags & 0x200) != 0 )
      {
        if ( v11.Bonus.pWeakProxy->RefCount-- == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v11.Bonus, 0, 24);
        v11.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
      }
    }
  }
  v10 = argv + 1;
  if ( argc <= 1 )
    v10 = &da->_1;
  this->a1 = v10;
}

// File Line: 2442
// RVA: 0x779750
void __fastcall Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value,double,long,Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *>::UnboxArgV3<Scaleform::GFx::AS3::Value,double,long,Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *>(
        Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value,double,long,Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::DefArgs3<double,long,Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *> *da)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Value v11; // [rsp+38h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value,double,long>::UnboxArgV2<Scaleform::GFx::AS3::Value,double,long>(
    this,
    vm,
    result,
    argc,
    argv,
    da);
  this->a2 = da->_2;
  if ( !vm->HandleException && argc > 2 )
  {
    v11.Flags = 0;
    v11.Bonus.pWeakProxy = 0i64;
    v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, &Scaleform::GFx::AS3::fl_media::SoundTransformTI);
    if ( !v9
      || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v9->vfptr[3].Finalize_GC)(
            v9,
            argv + 2,
            &v11) )
    {
      Scaleform::GFx::AS3::Value::Assign(&v11, argv + 2);
    }
    this->a2 = (Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *)v11.value.VS._1.VStr;
    if ( (v11.Flags & 0x1F) > 9 )
    {
      if ( (v11.Flags & 0x200) != 0 )
      {
        if ( v11.Bonus.pWeakProxy->RefCount-- == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v11.Bonus, 0, 24);
        v11.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
      }
    }
  }
}

// File Line: 2517
// RVA: 0x7799B0
void __fastcall Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *>::UnboxArgV4<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *>(
        Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::DefArgs4<Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *> *da)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Value v11; // [rsp+38h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::UnboxArgV3<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::BitmapData *,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *,Scaleform::GFx::AS3::Instances::fl_geom::Point *>(
    this,
    vm,
    result,
    argc,
    argv,
    da);
  this->a3 = da->_3;
  if ( !vm->HandleException && argc > 3 )
  {
    v11.Flags = 0;
    v11.Bonus.pWeakProxy = 0i64;
    v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, &Scaleform::GFx::AS3::fl_filters::BitmapFilterTI);
    if ( !v9
      || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v9->vfptr[3].Finalize_GC)(
            v9,
            argv + 3,
            &v11) )
    {
      Scaleform::GFx::AS3::Value::Assign(&v11, argv + 3);
    }
    this->a3 = (Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *)v11.value.VS._1.VStr;
    if ( (v11.Flags & 0x1F) > 9 )
    {
      if ( (v11.Flags & 0x200) != 0 )
      {
        if ( v11.Bonus.pWeakProxy->RefCount-- == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v11.Bonus, 0, 24);
        v11.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
      }
    }
  }
}

// File Line: 2548
// RVA: 0x779F60
void __fastcall Scaleform::GFx::AS3::UnboxArgV5<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>::UnboxArgV5<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *>(
        Scaleform::GFx::AS3::UnboxArgV5<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::DefArgs5<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *> *da)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Value v11; // [rsp+38h] [rbp-40h] BYREF

  Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &>::UnboxArgV4<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix *,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *,Scaleform::GFx::ASString const &>(
    this,
    vm,
    result,
    argc,
    argv,
    da);
  this->a4 = da->_4;
  if ( !vm->HandleException && argc > 4 )
  {
    v11.Flags = 0;
    v11.Bonus.pWeakProxy = 0i64;
    v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, &Scaleform::GFx::AS3::fl_geom::RectangleTI);
    if ( !v9
      || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v9->vfptr[3].Finalize_GC)(
            v9,
            argv + 4,
            &v11) )
    {
      Scaleform::GFx::AS3::Value::Assign(&v11, argv + 4);
    }
    this->a4 = (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)v11.value.VS._1.VStr;
    if ( (v11.Flags & 0x1F) > 9 )
    {
      if ( (v11.Flags & 0x200) != 0 )
      {
        if ( v11.Bonus.pWeakProxy->RefCount-- == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v11.Bonus, 0, 24);
        v11.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
      }
    }
  }
}

// File Line: 2626
// RVA: 0x7431F0
void __fastcall Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,4,Scaleform::GFx::AS3::Value>::Func(
        Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int a5,
        Scaleform::GFx::AS3::Value *a6)
{
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject,4,Scaleform::GFx::AS3::Value>::Method(
    (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)((char *)obj->value.VS._1.VStr
                                                                    + (int)qword_14243C050),
    result);
}

// File Line: 2636
// RVA: 0x876560
void __fastcall Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,26,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,26,Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> *this,
        Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *argc)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rbp
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  unsigned int v12; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // rdi
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::Value *v16; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::ASString v17; // [rsp+38h] [rbp-20h] BYREF
  Scaleform::GFx::ASString v18; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::GFx::ASStringNode *v19; // [rsp+70h] [rbp+18h]

  StringManagerRef = vm->StringManagerRef;
  pNode = Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext,1,0,Scaleform::GFx::ASString const &>(
            &v18,
            (Scaleform::GFx::AS3::StringManager *)__formal->Name)->pNode;
  v19 = pNode;
  ++pNode->RefCount;
  v10 = v18.pNode;
  v11 = v18.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v16 = obj;
  v17.pNode = pNode;
  ++pNode->RefCount;
  if ( (_DWORD)result )
  {
    v12 = argc->Flags & 0x1F;
    if ( v12 - 12 > 3 && v12 != 10 || argc->value.VS._1.VStr )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argc, (Scaleform::GFx::AS3::CheckResult *)&result, &v17);
    }
    else
    {
      p_NullStringNode = &v17.pNode->pManager->NullStringNode;
      ++v17.pNode->pManager->NullStringNode.RefCount;
      v14 = v17.pNode;
      v11 = v17.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      v17.pNode = p_NullStringNode;
    }
  }
  if ( !LOBYTE(__formal[3].NamespaceName) )
    Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,26,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)((char *)StringManagerRef + (int)qword_14243FBB8),
      v16,
      &v17);
  v15 = v17.pNode;
  v11 = v17.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  v11 = pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 2653
// RVA: 0x8D1F70
void __fastcall Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,14,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Func(
        Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,14,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &> *this,
        Scaleform::GFx::AS3::VM *__formal,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *obj)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // r14
  Scaleform::GFx::AS3::StringManager *v7; // rbx
  Scaleform::GFx::AS3::Value *v8; // rdi
  Scaleform::GFx::AS3::Value *v9; // rax
  Scaleform::GFx::AS3::Value **p_a0; // rax
  Scaleform::GFx::AS3::Value *v11; // rax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v12; // [rsp+18h] [rbp-79h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>,Scaleform::GFx::AS3::Value const &> v13; // [rsp+20h] [rbp-71h] BYREF
  Scaleform::GFx::AS3::Value::Extra v14; // [rsp+40h] [rbp-51h]
  Scaleform::GFx::AS3::Value::VU value; // [rsp+48h] [rbp-49h]
  Scaleform::GFx::AS3::Value v16; // [rsp+58h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Value v17; // [rsp+78h] [rbp-19h] BYREF
  Scaleform::GFx::AS3::Value v18; // [rsp+98h] [rbp+7h] BYREF
  __int64 v19; // [rsp+B8h] [rbp+27h]
  unsigned int v20; // [rsp+108h] [rbp+77h]
  __int64 v21; // [rsp+110h] [rbp+7Fh]

  v19 = -2i64;
  StringManagerRef = vm->StringManagerRef;
  v7 = __formal->StringManagerRef;
  v8 = Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint,9,1,Scaleform::GFx::AS3::Value const &>(
         (Scaleform::GFx::AS3::Value *)&v17.value.VS._2,
         v7);
  v9 = Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,7,0,Scaleform::GFx::AS3::Value const &>(
         &v18,
         v7);
  LODWORD(v13.a0) = v9->Flags;
  v14.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v9->Bonus;
  value = v9->value;
  if ( (v9->Flags & 0x1F) > 9 )
  {
    if ( (v9->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v9);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v9);
  }
  v16.Flags = v8->Flags;
  v16.Bonus.pWeakProxy = v8->Bonus.pWeakProxy;
  v16.value = v8->value;
  if ( (v8->Flags & 0x1F) > 9 )
  {
    if ( (v8->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v8);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v8);
  }
  if ( (v18.Flags & 0x1F) > 9 )
  {
    if ( (v18.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v18);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v18);
  }
  if ( (v17.Flags & 0x1F) > 9 )
  {
    if ( (v17.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v17);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v17);
  }
  v13.Vm = __formal;
  v13.Result = obj;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>>(
    &v12,
    __formal->StringManagerRef);
  p_a0 = &v13.a0;
  if ( v20 )
    p_a0 = (Scaleform::GFx::AS3::Value **)v21;
  v13.Vm = (Scaleform::GFx::AS3::VM *)p_a0;
  v11 = (Scaleform::GFx::AS3::Value *)(v21 + 32);
  if ( v20 <= 1 )
    v11 = &v16;
  v13.Result = v11;
  if ( !__formal->HandleException )
    Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,14,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)((char *)StringManagerRef + (int)qword_142440C88),
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *)&v12,
      (Scaleform::GFx::AS3::Value *)v13.Vm,
      v13.Result);
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>,bool>::~UnboxArgV1<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>,bool>(&v13);
  if ( (v16.Flags & 0x1F) > 9 )
  {
    if ( (v16.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v16);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v16);
  }
  if ( (unsigned __int64)((__int64)v13.a0 & 0x1F) > 9 )
  {
    if ( ((__int64)v13.a0 & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&v13.a0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v13.a0);
  }
}

// File Line: 2671
// RVA: 0x727500
void __fastcall Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,13,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D>,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,double>::Func(
        Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,13,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D>,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,double> *this,
        Scaleform::GFx::AS3::VM *__formal,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *argc)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // r14
  long double v9; // xmm6_8
  Scaleform::GFx::AS3::Value *v10; // rbp
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *> da; // [rsp+38h] [rbp-60h] BYREF
  long double v12; // [rsp+48h] [rbp-50h]
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D>,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *> v13; // [rsp+50h] [rbp-48h] BYREF
  long double v14[3]; // [rsp+78h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::CheckResult v15; // [rsp+A8h] [rbp+10h] BYREF

  StringManagerRef = vm->StringManagerRef;
  v9 = Scaleform::GFx::NumberUtil::NaN();
  da._0 = 0i64;
  da._1 = 0i64;
  v12 = v9;
  v10 = argc;
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D>,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *>::UnboxArgV2<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D>,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *>(
    &v13,
    __formal,
    obj,
    (unsigned int)result,
    argc,
    &da);
  v14[0] = v9;
  if ( !__formal->HandleException && (unsigned int)result > 2 )
    Scaleform::GFx::AS3::Value::Convert2Number(v10 + 2, &v15, v14);
  if ( !__formal->HandleException )
    Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,13,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D>,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *,double>::Method(
      (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)((char *)StringManagerRef + (int)qword_14243E320),
      &v13.r,
      v13.a0,
      v13.a1,
      v14[0]);
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,double>::~UnboxArgV1<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,double>((Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>,Scaleform::GFx::AS3::Value const &> *)&v13);
}

// File Line: 2690
// RVA: 0x74A0E0
void __fastcall Scaleform::GFx::AS3::ThunkFunc4<Scaleform::GFx::AS3::Instances::fl_display::Graphics,4,Scaleform::GFx::AS3::Value const,double,double,double,double>::Func(
        Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // rbp
  long double v9; // xmm6_8
  long double v10; // xmm8_8
  long double v11; // xmm7_8
  long double v12; // xmm0_8
  unsigned int v13; // esi
  Scaleform::GFx::AS3::Value *v14; // rbx
  bool v15; // zf
  Scaleform::GFx::AS3::Value *v16; // [rsp+38h] [rbp-60h]
  long double resulta; // [rsp+40h] [rbp-58h] BYREF
  long double v18; // [rsp+48h] [rbp-50h] BYREF
  long double v19; // [rsp+50h] [rbp-48h] BYREF
  long double v20[3]; // [rsp+58h] [rbp-40h] BYREF

  v6 = obj->value.VS._1;
  v9 = Scaleform::GFx::NumberUtil::NaN();
  v10 = Scaleform::GFx::NumberUtil::NaN();
  v11 = Scaleform::GFx::NumberUtil::NaN();
  v12 = Scaleform::GFx::NumberUtil::NaN();
  v13 = argc;
  v16 = result;
  v14 = argv;
  resulta = v12;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &resulta);
  v15 = !vm->HandleException;
  v18 = v11;
  if ( v15 && v13 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Number(v14 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &v18);
  v15 = !vm->HandleException;
  v19 = v10;
  if ( v15 && v13 > 2 )
    Scaleform::GFx::AS3::Value::Convert2Number(v14 + 2, (Scaleform::GFx::AS3::CheckResult *)&argc, &v19);
  v15 = !vm->HandleException;
  v20[0] = v9;
  if ( v15 )
  {
    if ( v13 > 3 )
    {
      Scaleform::GFx::AS3::Value::Convert2Number(v14 + 3, (Scaleform::GFx::AS3::CheckResult *)&argc, v20);
      v9 = v20[0];
    }
    if ( !vm->HandleException )
      Scaleform::GFx::AS3::ThunkFunc4<Scaleform::GFx::AS3::Instances::fl_display::Graphics,4,Scaleform::GFx::AS3::Value const,double,double,double,double>::Method(
        (Scaleform::GFx::AS3::Instances::fl_display::Graphics *)((char *)v6.VStr + (int)qword_14243BEC0),
        v16,
        resulta,
        v18,
        v19,
        v9);
  }
}

// File Line: 2710
// RVA: 0x731490
void __fastcall Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_display::Stage,40,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &,bool,long,bool>::Func(
        Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_display::Stage,40,Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &,bool,long,bool> *this,
        Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *obj)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // r15
  Scaleform::GFx::AS3::StringManager *Name; // rbx
  Scaleform::GFx::AS3::Value *v8; // rdi
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  int v12; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // r14
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::Value *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString v18; // [rsp+28h] [rbp-79h] BYREF
  Scaleform::GFx::AS3::Value *v19; // [rsp+30h] [rbp-71h]
  char v20; // [rsp+38h] [rbp-69h]
  int v21[2]; // [rsp+40h] [rbp-61h] BYREF
  Scaleform::GFx::AS3::Value *v22; // [rsp+48h] [rbp-59h]
  Scaleform::GFx::ASStringNode *pNode; // [rsp+58h] [rbp-49h]
  Scaleform::GFx::AS3::Value v24; // [rsp+60h] [rbp-41h] BYREF
  char v25; // [rsp+80h] [rbp-21h]
  int v26; // [rsp+88h] [rbp-19h]
  char v27; // [rsp+90h] [rbp-11h]
  Scaleform::GFx::AS3::Value v28; // [rsp+98h] [rbp-9h] BYREF
  __int64 v29; // [rsp+B8h] [rbp+17h]
  Scaleform::GFx::AS3::Value v30; // [rsp+C0h] [rbp+1Fh] BYREF
  Scaleform::GFx::ASString v31; // [rsp+100h] [rbp+5Fh] BYREF
  void *retaddr; // [rsp+118h] [rbp+77h] BYREF
  Scaleform::GFx::AS3::Value *v33; // [rsp+120h] [rbp+7Fh]

  v29 = -2i64;
  StringManagerRef = vm->StringManagerRef;
  Name = (Scaleform::GFx::AS3::StringManager *)__formal->Name;
  v8 = Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo,7,0,Scaleform::GFx::AS3::Value const &>(
         &v30,
         Name);
  pNode = Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Classes::fl_external::ExtensionContext,1,0,Scaleform::GFx::ASString const &>(
            &v31,
            Name)->pNode;
  ++pNode->RefCount;
  v24.Flags = v8->Flags;
  v24.Bonus.pWeakProxy = v8->Bonus.pWeakProxy;
  v24.value = v8->value;
  if ( (v8->Flags & 0x1F) > 9 )
  {
    if ( (v8->Flags & 0x200) != 0 )
    {
      ++v8->Bonus.pWeakProxy->RefCount;
      goto LABEL_13;
    }
    if ( (v8->Flags & 0x1F) == 10 )
    {
      ++v8->value.VS._1.VStr->RefCount;
    }
    else
    {
      if ( (v8->Flags & 0x1F) <= 0xA )
        goto LABEL_13;
      if ( (v8->Flags & 0x1F) <= 0xF )
      {
        VObj = v8->value.VS._1;
      }
      else
      {
        if ( (v8->Flags & 0x1F) > 0x11 )
          goto LABEL_13;
        VObj = (Scaleform::GFx::AS3::Value::V1U)v8->value.VS._2.VObj;
      }
      if ( VObj.VStr )
        VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
    }
  }
LABEL_13:
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v10 = v31.pNode;
  v11 = v31.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( (v28.Flags & 0x1F) > 9 )
  {
    if ( (v28.Flags & 0x200) != 0 )
    {
      v11 = v28.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v28.Bonus, 0, 24);
      v28.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v28);
    }
  }
  *(_QWORD *)v21 = __formal;
  v22 = obj;
  v18.pNode = pNode;
  ++pNode->RefCount;
  if ( (_DWORD)retaddr )
  {
    v12 = v33->Flags & 0x1F;
    if ( (unsigned int)(v12 - 12) > 3 && v12 != 10 || v33->value.VS._1.VStr )
    {
      Scaleform::GFx::AS3::Value::Convert2String(v33, (Scaleform::GFx::AS3::CheckResult *)&retaddr, &v18);
    }
    else
    {
      p_NullStringNode = &v18.pNode->pManager->NullStringNode;
      ++v18.pNode->pManager->NullStringNode.RefCount;
      v14 = v18.pNode;
      v11 = v18.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      v18.pNode = p_NullStringNode;
    }
  }
  v15 = v33 + 1;
  if ( (unsigned int)retaddr <= 1 )
    v15 = &v24;
  v19 = v15;
  v20 = v25;
  if ( !LOBYTE(__formal[3].NamespaceName) && (unsigned int)retaddr > 2 )
    v20 = Scaleform::GFx::AS3::Value::Convert2Boolean(v33 + 2);
  v21[0] = v26;
  if ( !LOBYTE(__formal[3].NamespaceName) && (unsigned int)retaddr > 3 )
    Scaleform::GFx::AS3::Value::Convert2Int32(v33 + 3, (Scaleform::GFx::AS3::CheckResult *)&retaddr, v21);
  LOBYTE(v22) = v27;
  if ( !LOBYTE(__formal[3].NamespaceName) && (unsigned int)retaddr > 4 )
    LOBYTE(v22) = Scaleform::GFx::AS3::Value::Convert2Boolean(v33 + 4);
  if ( !LOBYTE(__formal[3].NamespaceName) )
  {
    LOBYTE(v19) = (_BYTE)v22;
    Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_display::Stage,40,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &,bool,long,bool>::Method(
      (Scaleform::GFx::AS3::Instances::fl_display::Stage *)((char *)StringManagerRef + (int)qword_14243C8B0),
      v22,
      &v18,
      v19,
      v20,
      v21[0],
      (bool)v22);
  }
  v16 = v18.pNode;
  v11 = v18.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  if ( (v24.Flags & 0x1F) > 9 )
  {
    if ( (v24.Flags & 0x200) != 0 )
    {
      v11 = v24.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v24.Bonus, 0, 24);
      v24.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v24);
    }
  }
  v17 = pNode;
  v11 = pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
}

// File Line: 2731
// RVA: 0x757250
void __fastcall Scaleform::GFx::AS3::ThunkFunc6<Scaleform::GFx::AS3::Instances::fl_display::Graphics,10,Scaleform::GFx::AS3::Value const,double,double,double,double,double,double>::Func(
        Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *argc)
{
  Scaleform::GFx::AS3::Value::V1U v5; // r14
  long double v8; // xmm6_8
  long double v9; // xmm10_8
  long double v10; // xmm9_8
  long double v11; // xmm8_8
  long double v12; // xmm7_8
  long double v13; // xmm0_8
  Scaleform::GFx::AS3::Value *v14; // rsi
  unsigned int v15; // ebx
  bool v16; // zf
  Scaleform::GFx::AS3::Value *v17; // [rsp+40h] [rbp-41h]
  long double v18; // [rsp+48h] [rbp-39h] BYREF
  long double v19; // [rsp+50h] [rbp-31h] BYREF
  long double v20; // [rsp+58h] [rbp-29h] BYREF
  long double v21; // [rsp+60h] [rbp-21h] BYREF
  long double v22; // [rsp+68h] [rbp-19h] BYREF
  long double v23[12]; // [rsp+70h] [rbp-11h] BYREF
  unsigned int resulta; // [rsp+F8h] [rbp+77h] BYREF

  v5 = obj->value.VS._1;
  v8 = Scaleform::GFx::NumberUtil::NaN();
  v9 = Scaleform::GFx::NumberUtil::NaN();
  v10 = Scaleform::GFx::NumberUtil::NaN();
  v11 = Scaleform::GFx::NumberUtil::NaN();
  v12 = Scaleform::GFx::NumberUtil::NaN();
  v13 = Scaleform::GFx::NumberUtil::NaN();
  v14 = argc;
  v17 = result;
  v15 = resulta;
  v18 = v13;
  if ( resulta )
    Scaleform::GFx::AS3::Value::Convert2Number(argc, (Scaleform::GFx::AS3::CheckResult *)&resulta, &v18);
  v16 = !vm->HandleException;
  v19 = v12;
  if ( v16 && v15 > 1 )
    Scaleform::GFx::AS3::Value::Convert2Number(v14 + 1, (Scaleform::GFx::AS3::CheckResult *)&resulta, &v19);
  v16 = !vm->HandleException;
  v20 = v11;
  if ( v16 && v15 > 2 )
    Scaleform::GFx::AS3::Value::Convert2Number(v14 + 2, (Scaleform::GFx::AS3::CheckResult *)&resulta, &v20);
  v16 = !vm->HandleException;
  v21 = v10;
  if ( v16 && v15 > 3 )
    Scaleform::GFx::AS3::Value::Convert2Number(v14 + 3, (Scaleform::GFx::AS3::CheckResult *)&resulta, &v21);
  v16 = !vm->HandleException;
  v22 = v9;
  if ( v16 && v15 > 4 )
    Scaleform::GFx::AS3::Value::Convert2Number(v14 + 4, (Scaleform::GFx::AS3::CheckResult *)&resulta, &v22);
  v16 = !vm->HandleException;
  v23[0] = v8;
  if ( v16 )
  {
    if ( v15 > 5 )
    {
      Scaleform::GFx::AS3::Value::Convert2Number(v14 + 5, (Scaleform::GFx::AS3::CheckResult *)&resulta, v23);
      v8 = v23[0];
    }
    if ( !vm->HandleException )
      Scaleform::GFx::AS3::ThunkFunc6<Scaleform::GFx::AS3::Instances::fl_display::Graphics,10,Scaleform::GFx::AS3::Value const,double,double,double,double,double,double>::Method(
        (Scaleform::GFx::AS3::Instances::fl_display::Graphics *)((char *)v5.VStr + (int)qword_14243BF20),
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v8);
  }
}

