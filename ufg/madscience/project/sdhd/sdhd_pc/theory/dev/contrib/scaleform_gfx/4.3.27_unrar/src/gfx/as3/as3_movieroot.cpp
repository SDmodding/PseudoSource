// File Line: 52
// RVA: 0x77A120
void __fastcall Scaleform::GFx::AS3::ASVM::ASVM(
        Scaleform::GFx::AS3::ASVM *this,
        Scaleform::GFx::AS3::MovieRoot *pmr,
        Scaleform::GFx::AS3::FlashUI *_ui,
        Scaleform::GFx::AS3::StringManager *sm,
        Scaleform::GFx::AS3::ASRefCountCollector *gc)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *Class; // rax
  Scaleform::GFx::AS3::ASVM *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v8; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v9; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v10; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v11; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v12; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v13; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v14; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v15; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v16; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v17; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v18; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v19; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v20; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v21; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v22; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v23; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v24; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v25; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v26; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v27; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v28; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v29; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v30; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v31; // rax
  Scaleform::StringDataPtr gname; // [rsp+28h] [rbp-18h] BYREF

  Scaleform::GFx::AS3::VM::VM(this, _ui, sm, gc);
  this->vfptr = (Scaleform::GFx::AS3::VMVtbl *)&Scaleform::GFx::AS3::ASVM::`vftable;
  this->pMovieRoot = pmr;
  this->GraphicsClass.pObject = 0i64;
  this->TransformClass.pObject = 0i64;
  this->MatrixClass.pObject = 0i64;
  this->Matrix3DClass.pObject = 0i64;
  this->PerspectiveProjectionClass.pObject = 0i64;
  this->ColorTransformClass.pObject = 0i64;
  this->EventClass.pObject = 0i64;
  this->MouseEventClass.pObject = 0i64;
  this->MouseEventExClass.pObject = 0i64;
  this->KeyboardEventClass.pObject = 0i64;
  this->KeyboardEventExClass.pObject = 0i64;
  this->FocusEventClass.pObject = 0i64;
  this->FocusEventExClass.pObject = 0i64;
  this->TextEventClass.pObject = 0i64;
  this->TextEventExClass.pObject = 0i64;
  this->TimerEventClass.pObject = 0i64;
  this->ProgressEventClass.pObject = 0i64;
  this->StageOrientationEventClass.pObject = 0i64;
  this->AppLifecycleEventClass.pObject = 0i64;
  this->StatusEventClass.pObject = 0i64;
  this->AccelerometerEventClass.pObject = 0i64;
  this->GeolocationEventClass.pObject = 0i64;
  this->PointClass.pObject = 0i64;
  this->RectangleClass.pObject = 0i64;
  this->TextFormatClass.pObject = 0i64;
  this->EventDispatcherClass.pObject = 0i64;
  this->Vector3DClass.pObject = 0i64;
  this->GeneralClipboard.pObject = 0i64;
  this->ExtensionsEnabled = 0;
  gname.pStr = "flash.display.Graphics";
  gname.Size = 22i64;
  Class = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                           this,
                                                           &gname,
                                                           this->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->GraphicsClass,
    Class);
  gname.pStr = "flash.geom.Transform";
  gname.Size = 20i64;
  v7 = this;
  v8 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                        this,
                                                        &gname,
                                                        this->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->TransformClass,
    v8);
  gname.pStr = "flash.geom.Matrix";
  gname.Size = 17i64;
  v9 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                        v7,
                                                        &gname,
                                                        v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->MatrixClass,
    v9);
  gname.pStr = "flash.geom.Matrix3D";
  gname.Size = 19i64;
  v10 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Matrix3DClass,
    v10);
  gname.pStr = "flash.geom.PerspectiveProjection";
  gname.Size = 32i64;
  v11 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->PerspectiveProjectionClass,
    v11);
  gname.pStr = "flash.geom.ColorTransform";
  gname.Size = 25i64;
  v12 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->ColorTransformClass,
    v12);
  gname.pStr = "flash.events.Event";
  gname.Size = 18i64;
  v13 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->EventClass,
    v13);
  gname.pStr = "flash.events.MouseEvent";
  gname.Size = 23i64;
  v14 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->MouseEventClass,
    v14);
  gname.pStr = "flash.events.KeyboardEvent";
  gname.Size = 26i64;
  v15 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->KeyboardEventClass,
    v15);
  gname.pStr = "flash.events.FocusEvent";
  gname.Size = 23i64;
  v16 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->FocusEventClass,
    v16);
  gname.pStr = "flash.events.TextEvent";
  gname.Size = 22i64;
  v17 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->TextEventClass,
    v17);
  gname.pStr = "scaleform.gfx.MouseEventEx";
  gname.Size = 26i64;
  v18 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->MouseEventExClass,
    v18);
  gname.pStr = "scaleform.gfx.KeyboardEventEx";
  gname.Size = 29i64;
  v19 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->KeyboardEventExClass,
    v19);
  gname.pStr = "scaleform.gfx.FocusEventEx";
  gname.Size = 26i64;
  v20 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->FocusEventExClass,
    v20);
  gname.pStr = "scaleform.gfx.TextEventEx";
  gname.Size = 25i64;
  v21 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->TextEventExClass,
    v21);
  gname.pStr = "flash.events.TimerEvent";
  gname.Size = 23i64;
  v22 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->TimerEventClass,
    v22);
  gname.pStr = "flash.events.ProgressEvent";
  gname.Size = 26i64;
  v23 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->ProgressEventClass,
    v23);
  gname.pStr = "flash.events.StatusEvent";
  gname.Size = 24i64;
  v24 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->StatusEventClass,
    v24);
  gname.pStr = "flash.events.AccelerometerEvent";
  gname.Size = 31i64;
  v25 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->AccelerometerEventClass,
    v25);
  gname.pStr = "flash.events.GeolocationEvent";
  gname.Size = 29i64;
  v26 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->GeolocationEventClass,
    v26);
  gname.pStr = "flash.geom.Point";
  gname.Size = 16i64;
  v27 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->PointClass,
    v27);
  gname.pStr = "flash.geom.Rectangle";
  gname.Size = 20i64;
  v28 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->RectangleClass,
    v28);
  gname.pStr = "flash.text.TextFormat";
  gname.Size = 21i64;
  v29 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->TextFormatClass,
    v29);
  gname.pStr = "flash.events.EventDispatcher";
  gname.Size = 28i64;
  v30 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->EventDispatcherClass,
    v30);
  gname.pStr = "flash.geom.Vector3D";
  gname.Size = 19i64;
  v31 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Vector3DClass,
    v31);
}

// File Line: 161
// RVA: 0x82A990
__int64 __fastcall Scaleform::GFx::AS3::ASVM::_constructInstance(
        Scaleform::GFx::AS3::ASVM *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *pobj,
        Scaleform::GFx::AS3::Object *classObj,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  int v7; // ecx
  unsigned __int8 v8; // bl
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value v13; // [rsp+38h] [rbp-30h] BYREF

  v13.Flags = 0;
  v13.Bonus.pWeakProxy = 0i64;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Object *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *, char))classObj->vfptr[4].ForEachChild_GC)(
    classObj,
    &v13,
    argc,
    argv,
    1);
  if ( this->HandleException
    || (v7 = v13.Flags & 0x1F, (v13.Flags & 0x1F) == 0)
    || ((unsigned int)(v7 - 12) <= 3 || v7 == 10) && !v13.value.VS._1.VStr )
  {
    pObject = pobj->pObject;
    if ( pobj->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        pobj->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)pObject - 1);
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
      pobj->pObject = 0i64;
    }
    if ( this->HandleException )
      this->HandleException = 0;
    v8 = 0;
  }
  else
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      pobj,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v13.value.VS._1.VStr);
    v8 = 1;
  }
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
  return v8;
}

// File Line: 178
// RVA: 0x7EEDF0
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::AS3::ASVM::GetResourceMovieDef(
        Scaleform::GFx::AS3::ASVM *this,
        Scaleform::GFx::AS3::Instances::fl::Object *instance)
{
  Scaleform::GFx::AS3::Traits *pObject; // rbx
  __int64 v4; // rax

  pObject = instance->pTraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(instance->pTraits.pObject);
  v4 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))pObject->pConstructor.pObject->pTraits.pObject->vfptr[2].~RefCountBaseGC<328>)(pObject->pConstructor.pObject->pTraits.pObject);
  if ( v4 )
    return *(Scaleform::GFx::MovieDefImpl **)(*(_QWORD *)(v4 + 152) + 368i64);
  else
    return this->pMovieRoot->pMovieImpl->pMainMovieDef.pObject;
}

// File Line: 195
// RVA: 0x78CA90
void __fastcall Scaleform::GFx::AS3::MovieDefRootNode::~MovieDefRootNode(Scaleform::GFx::AS3::MovieDefRootNode *this)
{
  signed __int64 i; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v3; // rbx
  Scaleform::GFx::AS3::VMAbcFile *pObject; // rcx
  unsigned int RefCount; // eax
  unsigned __int64 Size; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *j; // rbx
  Scaleform::GFx::AS3::VMAbcFile *v8; // rcx
  unsigned int v9; // eax
  Scaleform::Render::RenderBuffer *v10; // rcx

  this->vfptr = (Scaleform::GFx::MovieDefRootNodeVtbl *)&Scaleform::GFx::AS3::MovieDefRootNode::`vftable;
  for ( i = this->AbcFiles.Data.Size - 1; i >= 0; --i )
  {
    v3 = &this->AbcFiles.Data.Data[i];
    pObject = v3->pObject;
    if ( v3->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        v3->pObject = (Scaleform::GFx::AS3::VMAbcFile *)((char *)pObject - 1);
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
      v3->pObject = 0i64;
    }
  }
  Size = this->AbcFiles.Data.Size;
  for ( j = &this->AbcFiles.Data.Data[Size - 1]; Size; --Size )
  {
    v8 = j->pObject;
    if ( j->pObject )
    {
      if ( ((unsigned __int8)v8 & 1) != 0 )
      {
        j->pObject = (Scaleform::GFx::AS3::VMAbcFile *)((char *)v8 - 1);
      }
      else
      {
        v9 = v8->RefCount;
        if ( (v9 & 0x3FFFFF) != 0 )
        {
          v8->RefCount = v9 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
        }
      }
    }
    --j;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->AbcFiles.Data.Data);
  this->vfptr = (Scaleform::GFx::MovieDefRootNodeVtbl *)&Scaleform::GFx::MovieDefRootNode::`vftable;
  v10 = (Scaleform::Render::RenderBuffer *)this->pFontManager.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
}

// File Line: 216
// RVA: 0x77FD40
void __fastcall Scaleform::GFx::AS3::MovieRoot::MovieRoot(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Resource *memContext,
        Scaleform::GFx::MovieImpl *pmovie,
        Scaleform::GFx::Resource *pas)
{
  Scaleform::GFx::AS3::MovieRoot::MemContextPtr *p_MemContext; // r15
  Scaleform::MemoryHeap *pLib; // rax

  Scaleform::GFx::ASMovieRootBase::ASMovieRootBase(this, pas);
  this->Scaleform::GFx::AS3::FlashUI::vfptr = (Scaleform::GFx::AS3::FlashUIVtbl *)&Scaleform::GFx::AS3::FlashUI::`vftable;
  this->State = sError;
  this->NeedToCheck = 0;
  this->Scaleform::GFx::KeyboardState::IListener::vfptr = (Scaleform::GFx::KeyboardState::IListenerVtbl *)&Scaleform::GFx::KeyboardState::IListener::`vftable;
  this->Scaleform::GFx::MovieDefImpl::ReleaseNotifier::vfptr = (Scaleform::GFx::MovieDefImpl::ReleaseNotifierVtbl *)&Scaleform::GFx::MovieDefImpl::ReleaseNotifier::`vftable;
  this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable{for `Scaleform::GFx::ASMovieRootBase};
  this->Scaleform::GFx::AS3::FlashUI::vfptr = (Scaleform::GFx::AS3::FlashUIVtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable{for `Scaleform::GFx::AS3::FlashUI};
  this->Scaleform::GFx::KeyboardState::IListener::vfptr = (Scaleform::GFx::KeyboardState::IListenerVtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable{for `Scaleform::GFx::KeyboardState::IListener};
  this->Scaleform::GFx::MovieDefImpl::ReleaseNotifier::vfptr = (Scaleform::GFx::MovieDefImpl::ReleaseNotifierVtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable{for `Scaleform::GFx::MovieDefImpl::ReleaseNotifier};
  p_MemContext = &this->MemContext;
  if ( memContext )
    Scaleform::Render::RenderBuffer::AddRef(memContext);
  p_MemContext->pObject = (Scaleform::GFx::AS3::MemoryContextImpl *)memContext;
  this->pAVM.pObject = 0i64;
  this->pAVM.Owner = 1;
  this->ExternalIntfRetVal.Flags = 0;
  this->ExternalIntfRetVal.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&this->NumAdvancesSinceCollection = 0i64;
  pLib = (Scaleform::MemoryHeap *)memContext->pLib;
  this->ActionQueue.Entries[0].pInsertEntry = 0i64;
  this->ActionQueue.Entries[0].pLastEntry = 0i64;
  this->ActionQueue.Entries[0].pActionRoot = 0i64;
  this->ActionQueue.Entries[1].pInsertEntry = 0i64;
  this->ActionQueue.Entries[1].pLastEntry = 0i64;
  this->ActionQueue.Entries[1].pActionRoot = 0i64;
  this->ActionQueue.Entries[2].pInsertEntry = 0i64;
  this->ActionQueue.Entries[2].pLastEntry = 0i64;
  this->ActionQueue.Entries[2].pActionRoot = 0i64;
  this->ActionQueue.Entries[3].pInsertEntry = 0i64;
  this->ActionQueue.Entries[3].pLastEntry = 0i64;
  this->ActionQueue.Entries[3].pActionRoot = 0i64;
  this->ActionQueue.Entries[4].pInsertEntry = 0i64;
  this->ActionQueue.Entries[4].pLastEntry = 0i64;
  this->ActionQueue.Entries[4].pActionRoot = 0i64;
  this->ActionQueue.Entries[5].pInsertEntry = 0i64;
  this->ActionQueue.Entries[5].pLastEntry = 0i64;
  this->ActionQueue.Entries[5].pActionRoot = 0i64;
  this->ActionQueue.Entries[6].pInsertEntry = 0i64;
  this->ActionQueue.Entries[6].pLastEntry = 0i64;
  this->ActionQueue.Entries[6].pActionRoot = 0i64;
  this->ActionQueue.pHeap = pLib;
  this->ActionQueue.ModId = 1;
  this->ActionQueue.pFreeEntry = 0i64;
  this->ActionQueue.FreeEntriesCount = 0;
  this->mEventChains.Chains.mHash.pTable = 0i64;
  this->pStage.pObject = 0i64;
  Scaleform::GFx::AS3::StringManager::StringManager(&this->BuiltinsMgr, p_MemContext->pObject->StringMgr.pObject);
  `eh vector constructor iterator(
    this->mMouseState,
    0xE0ui64,
    6,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::MovieRoot::MouseState::MouseState);
  this->StageInvalidated = 0;
  this->LoadedMovieDefs.mHash.pTable = 0i64;
  this->Flags = 0;
  this->AccelerometerArray.pObject = 0i64;
  this->AccelerometerArray.Owner = 1;
  this->GeolocationArray.pObject = 0i64;
  this->GeolocationArray.Owner = 1;
  this->ExtensionContextArray.pObject = 0i64;
  this->ExtensionContextArray.Owner = 1;
  this->ASFramesToExecute = 0;
  this->pMovieImpl = pmovie;
  Scaleform::GFx::MovieImpl::SetASMovieRoot(pmovie, this);
  Scaleform::GFx::AS3::MovieRoot::CreateObjectInterface(this, pmovie);
  Scaleform::GFx::MovieImpl::SetKeyboardListener(pmovie, &this->Scaleform::GFx::KeyboardState::IListener);
  this->pInvokeAliases = 0i64;
  pmovie->Flags &= 0xDF7FFFFF;
  pmovie->Flags |= 0x10400000u;
  this->MainLoaderInfoEventsState = 0;
}

// File Line: 237
// RVA: 0x78CBA0
void __fastcall Scaleform::GFx::AS3::MovieRoot::~MovieRoot(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::Stage *pObject; // rcx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pFreeEntry; // rsi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pNextEntry; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::ASVM *v7; // rcx
  Scaleform::Render::RenderBuffer *v8; // rcx
  Scaleform::Render::RenderBuffer *v9; // rcx

  this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable{for `Scaleform::GFx::ASMovieRootBase};
  this->Scaleform::GFx::AS3::FlashUI::vfptr = (Scaleform::GFx::AS3::FlashUIVtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable{for `Scaleform::GFx::AS3::FlashUI};
  this->Scaleform::GFx::KeyboardState::IListener::vfptr = (Scaleform::GFx::KeyboardState::IListenerVtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable{for `Scaleform::GFx::KeyboardState::IListener};
  this->Scaleform::GFx::MovieDefImpl::ReleaseNotifier::vfptr = (Scaleform::GFx::MovieDefImpl::ReleaseNotifierVtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable{for `Scaleform::GFx::MovieDefImpl::ReleaseNotifier};
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy>>::~AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy>>((Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> > *)&this->ExtensionContextArray);
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy>>::~AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy>>(&this->GeolocationArray);
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy>>::~AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy>>((Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> > *)&this->AccelerometerArray);
  Scaleform::HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::~HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>((Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&this->LoadedMovieDefs);
  `eh vector destructor iterator(
    this->mMouseState,
    0xE0ui64,
    6,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::MovieRoot::MouseState::~MouseState);
  Scaleform::GFx::ASStringManager::ReleaseBuiltinArray(
    this->BuiltinsMgr.pStringManager,
    this->BuiltinsMgr.Builtins,
    0x40u);
  pObject = this->pStage.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>::Clear(&this->mEventChains.Chains.mHash);
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType::Clear(&this->ActionQueue);
  pFreeEntry = this->ActionQueue.pFreeEntry;
  if ( pFreeEntry )
  {
    do
    {
      pNextEntry = pFreeEntry->pNextEntry;
      Scaleform::GFx::AS3::MovieRoot::ActionEntry::~ActionEntry(pFreeEntry);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pFreeEntry);
      pFreeEntry = pNextEntry;
    }
    while ( pNextEntry );
  }
  if ( (this->ExternalIntfRetVal.Flags & 0x1F) > 9 )
  {
    if ( (this->ExternalIntfRetVal.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->ExternalIntfRetVal.Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->ExternalIntfRetVal.Bonus.pWeakProxy = 0i64;
      this->ExternalIntfRetVal.value.VS._1.VStr = 0i64;
      this->ExternalIntfRetVal.value.VS._2.VObj = 0i64;
      this->ExternalIntfRetVal.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->ExternalIntfRetVal);
    }
  }
  v7 = this->pAVM.pObject;
  if ( v7 )
  {
    if ( this->pAVM.Owner )
    {
      this->pAVM.Owner = 0;
      v7->vfptr->__vecDelDtor(v7, 1u);
    }
    this->pAVM.pObject = 0i64;
  }
  this->pAVM.Owner = 0;
  Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(this->MemContext.pObject->ASGC.pObject, 0i64, 1u);
  v8 = (Scaleform::Render::RenderBuffer *)this->MemContext.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  this->Scaleform::GFx::MovieDefImpl::ReleaseNotifier::vfptr = (Scaleform::GFx::MovieDefImpl::ReleaseNotifierVtbl *)&Scaleform::GFx::MovieDefImpl::ReleaseNotifier::`vftable;
  this->Scaleform::GFx::KeyboardState::IListener::vfptr = (Scaleform::GFx::KeyboardState::IListenerVtbl *)&Scaleform::GFx::KeyboardState::IListener::`vftable;
  this->Scaleform::GFx::AS3::FlashUI::vfptr = (Scaleform::GFx::AS3::FlashUIVtbl *)&Scaleform::GFx::AS3::FlashUI::`vftable;
  this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASMovieRootBase::`vftable;
  v9 = (Scaleform::Render::RenderBuffer *)this->pASSupport.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 241
// RVA: 0x8212C0
void __fastcall Scaleform::GFx::AS3::MovieRoot::Shutdown(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::Stage *pObject; // rcx
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS3::Value> *pInvokeAliases; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *p_LastMouseOverObj; // rbx
  __int64 v7; // rsi
  Scaleform::HashIdentityLH<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,2,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> > *p_LoadedMovieDefs; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> >::TableType *pTable; // rcx
  unsigned __int64 v10; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> >::TableType *v11; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> >::TableType *v12; // rcx
  Scaleform::GFx::MovieDefImpl *v13; // rcx
  unsigned __int64 SizeMask; // rdx
  unsigned __int64 *v15; // rcx
  Scaleform::GFx::MovieDefRootNode *i; // rbx
  Scaleform::ArrayDefaultPolicy *v17; // rax
  Scaleform::GFx::AS3::ASVM *v18; // rcx

  Scaleform::GFx::MovieImpl::ClearPlayList(this->pMovieImpl);
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType::Clear(&this->ActionQueue);
  pObject = this->pStage.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pStage.pObject = 0i64;
  this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[9].__vecDelDtor(
    this,
    2u);
  pInvokeAliases = this->pInvokeAliases;
  if ( pInvokeAliases )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Clear(&pInvokeAliases->mHash);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pInvokeAliases);
  }
  this->pInvokeAliases = 0i64;
  if ( (this->ExternalIntfRetVal.Flags & 0x1F) > 9 )
  {
    if ( (this->ExternalIntfRetVal.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->ExternalIntfRetVal.Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->ExternalIntfRetVal.Bonus.pWeakProxy = 0i64;
      this->ExternalIntfRetVal.value.VS._1.VStr = 0i64;
      this->ExternalIntfRetVal.value.VS._2.VObj = 0i64;
      this->ExternalIntfRetVal.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->ExternalIntfRetVal);
    }
  }
  this->ExternalIntfRetVal.Flags &= 0xFFFFFFE0;
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>::Clear(&this->mEventChains.Chains.mHash);
  p_LastMouseOverObj = &this->mMouseState[0].LastMouseOverObj;
  v7 = 6i64;
  do
  {
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *)&p_LastMouseOverObj[-3],
      &p_LastMouseOverObj[-3],
      0i64);
    if ( p_LastMouseOverObj->pObject )
      Scaleform::RefCountNTSImpl::Release(p_LastMouseOverObj->pObject);
    p_LastMouseOverObj->pObject = 0i64;
    p_LastMouseOverObj += 28;
    --v7;
  }
  while ( v7 );
  p_LoadedMovieDefs = &this->LoadedMovieDefs;
  pTable = this->LoadedMovieDefs.mHash.pTable;
  v10 = 0i64;
  if ( pTable )
  {
    v11 = pTable + 1;
    do
    {
      if ( v11->EntryCount != -2i64 )
        break;
      ++v10;
      v11 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> >::TableType *)((char *)v11 + 24);
    }
    while ( v10 <= pTable->SizeMask );
  }
  else
  {
    p_LoadedMovieDefs = 0i64;
  }
  while ( p_LoadedMovieDefs )
  {
    v12 = p_LoadedMovieDefs->mHash.pTable;
    if ( !p_LoadedMovieDefs->mHash.pTable || (signed __int64)v10 > (signed __int64)v12->SizeMask )
      break;
    v13 = (Scaleform::GFx::MovieDefImpl *)*(&v12[1].SizeMask + 3 * v10);
    if ( v13 )
      Scaleform::GFx::MovieDefImpl::RemoveReleaseNotifier(v13, &this->Scaleform::GFx::MovieDefImpl::ReleaseNotifier);
    SizeMask = p_LoadedMovieDefs->mHash.pTable->SizeMask;
    if ( (__int64)v10 <= (__int64)SizeMask && ++v10 <= SizeMask )
    {
      v15 = &p_LoadedMovieDefs->mHash.pTable[1].EntryCount + 3 * v10;
      do
      {
        if ( *v15 != -2i64 )
          break;
        ++v10;
        v15 += 3;
      }
      while ( v10 <= SizeMask );
    }
  }
  for ( i = this->pMovieImpl->RootMovieDefNodes.Root.pNext; ; i = i->pNext )
  {
    v17 = this->pMovieImpl == (Scaleform::GFx::MovieImpl *)-112i64 ? 0i64 : &this->pMovieImpl->MovieLevels.Data.Policy;
    if ( i == (Scaleform::GFx::MovieDefRootNode *)v17 )
      break;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&i[1],
      &i[1],
      0i64);
  }
  this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[9].__vecDelDtor(
    this,
    2u);
  Scaleform::GFx::AS3::VM::UnregisterAllAbcFiles(this->pAVM.pObject);
  this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[9].__vecDelDtor(
    this,
    2u);
  v18 = this->pAVM.pObject;
  if ( v18 )
  {
    if ( this->pAVM.Owner )
    {
      this->pAVM.Owner = 0;
      v18->vfptr->__vecDelDtor(v18, 1u);
    }
    this->pAVM.pObject = 0i64;
  }
  this->pAVM.Owner = 0;
}

// File Line: 286
// RVA: 0x7F2C20
char __fastcall Scaleform::GFx::AS3::MovieRoot::Init(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::MovieDefImpl *pmovieDef)
{
  ((void (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *))this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[4].__vecDelDtor)(this);
  Scaleform::GFx::AS3::MovieRoot::CreateStage(this, pmovieDef);
  Scaleform::GFx::MovieImpl::SetLevelMovie(this->pMovieImpl, 0, this->pStage.pObject);
  this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[39].__vecDelDtor(
    this,
    (unsigned int)this->pStage.pObject);
  return 1;
}

// File Line: 314
// RVA: 0x7B35C0
bool __fastcall Scaleform::GFx::AS3::MovieRoot::CheckAvm(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::ActionControl *pObject; // rsi
  Scaleform::GFx::ActionControl *v3; // rcx
  Scaleform::GFx::AS3::ASVM *v4; // r10
  Scaleform::GFx::AS3::ASVM *v5; // rax
  Scaleform::GFx::AS3::ASVM *v6; // rsi
  Scaleform::GFx::AS3::ASVM *v7; // rcx
  Scaleform::Ptr<Scaleform::GFx::ActionControl> result; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::ASVM *v10; // [rsp+58h] [rbp+10h]

  if ( !this->pAVM.pObject )
  {
    pObject = Scaleform::GFx::StateBag::GetActionControl(&this->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
    v3 = result.pObject;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( pObject )
      this->NeedToCheck = pObject->ActionFlags & 1;
    else
      this->NeedToCheck = 0;
    this->State = sStep;
    result.pObject = (Scaleform::GFx::ActionControl *)this->pMovieImpl->pHeap;
    v4 = (Scaleform::GFx::AS3::ASVM *)((__int64 (__fastcall *)(Scaleform::GFx::ActionControl *, __int64, _QWORD))result.pObject->vfptr[10].__vecDelDtor)(
                                        v3,
                                        984i64,
                                        0i64);
    v10 = v4;
    if ( v4 )
    {
      Scaleform::GFx::AS3::ASVM::ASVM(
        v4,
        this,
        &this->Scaleform::GFx::AS3::FlashUI,
        &this->BuiltinsMgr,
        this->MemContext.pObject->ASGC.pObject);
      v6 = v5;
    }
    else
    {
      v6 = 0i64;
    }
    v7 = this->pAVM.pObject;
    if ( v7 != v6 )
    {
      if ( v7 && this->pAVM.Owner )
      {
        this->pAVM.Owner = 0;
        v7->vfptr->__vecDelDtor(v7, 1u);
      }
      this->pAVM.pObject = v6;
    }
    this->pAVM.Owner = v6 != 0i64;
    Scaleform::GFx::AS3::VM::ExecuteCode(this->pAVM.pObject, 1u);
  }
  return this->pAVM.pObject != 0i64;
}

// File Line: 336
// RVA: 0x7CAA70
_BOOL8 __fastcall Scaleform::GFx::AS3::MovieRoot::ExecuteAbc(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Resource *pabc,
        Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::MovieDefImpl *v6; // rsi
  char *v7; // rcx
  __int64 v8; // rax
  Scaleform::GFx::AS3::VMAppDomain *v9; // r14
  __int64 v10; // rcx
  Scaleform::GFx::AS3::VMAbcFile *pObject; // rax
  __int64 v12; // rax
  __int64 v13; // rcx
  Scaleform::GFx::AS3::Abc::Reader *v14; // rbx
  Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef *v15; // rax
  Scaleform::GFx::AS3::Abc::File *v16; // rax
  Scaleform::GFx::AS3::Abc::File *v17; // rsi
  bool v18; // di
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v19; // r14
  Scaleform::GFx::AS3::VMAbcFile *v20; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::VMAbcFile *v22; // rcx
  unsigned int v23; // eax
  Scaleform::GFx::AS3::ASVM *v24; // rcx
  Scaleform::GFx::MovieDefRootNode *RootNode; // rax
  Scaleform::GFx::MovieDefRootNode *v26; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v27; // rdx
  Scaleform::GFx::AS3::VMAbcFile *v28; // rax
  Scaleform::GFx::AS3::VMAbcFile *v29; // rcx
  unsigned int v30; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> result; // [rsp+B0h] [rbp+48h] BYREF
  Scaleform::String src; // [rsp+B8h] [rbp+50h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> v34; // [rsp+C0h] [rbp+58h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> file; // [rsp+C8h] [rbp+60h] BYREF

  v6 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))m->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(m);
  Scaleform::String::String(&src, (Scaleform::String *)&pabc[1].RefCount);
  if ( (*(_QWORD *)((unsigned __int64)pabc->pLib & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) != 0 )
  {
    Scaleform::String::AppendString(&src, "[", -1i64);
    Scaleform::String::operator+=(&src, (Scaleform::String *)&pabc->pLib);
    Scaleform::String::AppendString(&src, "]", -1i64);
  }
  v7 = (char *)m + 4 * (unsigned __int8)m->AvmObjOffset;
  v8 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v7 + 40i64))(v7);
  if ( v8 )
    v8 -= 72i64;
  v9 = *(Scaleform::GFx::AS3::VMAppDomain **)(v8 + 40);
  Scaleform::GFx::AS3::VM::FindVMAbcFileWeak(
    this->pAVM.pObject,
    &result,
    (const char *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    v9);
  pObject = result.pObject;
  if ( result.pObject )
  {
    v18 = 1;
  }
  else
  {
    v34.pObject = (Scaleform::GFx::AS3::VMAbcFile *)this->pMovieImpl->pHeap;
    v12 = ((__int64 (__fastcall *)(__int64, __int64))v34.pObject->vfptr[3].~RefCountBaseGC<328>)(v10, 16i64);
    v14 = (Scaleform::GFx::AS3::Abc::Reader *)v12;
    file.pObject = (Scaleform::GFx::AS3::Abc::File *)v12;
    if ( v12 )
    {
      *(_QWORD *)v12 = LODWORD(pabc[1].vfptr);
      *(_QWORD *)(v12 + 8) = (char *)pabc + 40;
    }
    else
    {
      v14 = 0i64;
    }
    v34.pObject = (Scaleform::GFx::AS3::VMAbcFile *)this->pMovieImpl->pHeap;
    v15 = (Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef *)((__int64 (__fastcall *)(__int64, __int64, _QWORD))v34.pObject->vfptr[3].~RefCountBaseGC<328>)(
                                                              v13,
                                                              384i64,
                                                              0i64);
    file.pObject = v15;
    if ( v15 )
    {
      Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef::AbcFileWithMovieDef(v15, v6, pabc);
      v17 = v16;
    }
    else
    {
      v17 = 0i64;
    }
    file.pObject = v17;
    Scaleform::String::operator=(&v17->Source, &src);
    v17->DataSize = (unsigned int)pabc[1].vfptr;
    v18 = Scaleform::GFx::AS3::Abc::Reader::Read(v14, v17);
    if ( v18 )
    {
      Scaleform::GFx::AS3::MovieRoot::CheckAvm(this);
      v19 = Scaleform::GFx::AS3::VM::LoadFile(this->pAVM.pObject, &v34, &file, v9, 0);
      if ( v19 != &result )
      {
        if ( v19->pObject )
          v19->pObject->RefCount = (v19->pObject->RefCount + 1) & 0x8FBFFFFF;
        v20 = result.pObject;
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
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
            }
          }
        }
        result.pObject = v19->pObject;
      }
      v22 = v34.pObject;
      if ( v34.pObject )
      {
        if ( ((__int64)v34.pObject & 1) != 0 )
        {
          --v34.pObject;
        }
        else
        {
          v23 = v34.pObject->RefCount;
          if ( (v23 & 0x3FFFFF) != 0 )
          {
            v34.pObject->RefCount = v23 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v22);
          }
        }
      }
      v24 = this->pAVM.pObject;
      if ( v24->HandleException )
      {
        Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v24);
        v18 = 0;
      }
    }
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v17);
    if ( v14 )
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v14);
    pObject = result.pObject;
  }
  if ( pObject )
  {
    RootNode = Scaleform::GFx::DisplayObjContainer::FindRootNode(m);
    v26 = RootNode + 1;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&RootNode[1],
      &RootNode[1],
      (unsigned __int64)&RootNode[1].pPrev->Scaleform::ListNode<Scaleform::GFx::MovieDefRootNode>::$B71EF414686F0132FD6F071932AB4B37::vfptr
    + 1);
    v27 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&v26->vfptr[(__int64)&v26->pPrev[-1].pFontManager.pObject
                                                                                 + 7];
    if ( v27 )
    {
      v27->pObject = result.pObject;
      v28 = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        v28->RefCount &= 0x8FBFFFFF;
      }
    }
  }
  v29 = result.pObject;
  if ( result.pObject )
  {
    if ( ((__int64)result.pObject & 1) != 0 )
    {
      --result.pObject;
    }
    else
    {
      v30 = result.pObject->RefCount;
      if ( (v30 & 0x3FFFFF) != 0 )
      {
        result.pObject->RefCount = v30 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v29);
      }
    }
  }
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8), 0xFFFFFFFF) == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v18;
}

// File Line: 408
// RVA: 0x805BB0
void __fastcall Scaleform::GFx::AS3::MovieRoot::Output(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::FlashUI::OutputMessageType type,
        const char *msg)
{
  Scaleform::GFx::LogState *CachedLog; // r10
  int v6; // ebx
  int v7; // ebx
  int v8; // eax
  Scaleform::LogMessageId messageType; // [rsp+30h] [rbp+8h] BYREF

  CachedLog = (Scaleform::GFx::LogState *)Scaleform::GFx::MovieImpl::GetCachedLog(*(Scaleform::GFx::MovieImpl **)&this[-1].GeolocationArray.Owner);
  if ( CachedLog )
  {
    v6 = type - 1;
    if ( v6 )
    {
      v7 = v6 - 1;
      if ( v7 )
      {
        if ( v7 == 1 )
          v8 = 24576;
        else
          v8 = 4096;
      }
      else
      {
        v8 = 147456;
      }
    }
    else
    {
      v8 = 212992;
    }
    messageType.Id = v8;
    Scaleform::Log::LogMessageById(CachedLog, (Scaleform::LogMessageId)&messageType, "%s", msg);
  }
}

// File Line: 469
// RVA: 0x8028A0
void __fastcall Scaleform::GFx::AS3::MovieRoot::NotifyOnResize(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::EventChains::QueueEvents(&this->mEventChains, Event_Resize);
}

// File Line: 474
// RVA: 0x7E3240
void __fastcall Scaleform::GFx::AS3::MovieRoot::GenerateMouseEvents(
        Scaleform::GFx::AS3::MovieRoot *this,
        unsigned int mouseIndex)
{
  __int64 v2; // r14
  Scaleform::GFx::AS3::MovieRoot *v3; // r13
  Scaleform::GFx::MouseState *v4; // r15
  char *v5; // rcx
  __int64 v6; // rax
  Scaleform::GFx::AS3::AvmDisplayObj *v7; // rcx
  Scaleform::GFx::InteractiveObject *pObject; // rbx
  Scaleform::GFx::InteractiveObject *pTopmostEntity; // rsi
  Scaleform::GFx::KeyboardState *v10; // rcx
  unsigned __int8 States; // di
  Scaleform::GFx::InteractiveObject **p_pObject; // r8
  int v13; // ecx
  unsigned int PrevButtonsState; // ecx
  Scaleform::GFx::InteractiveObject *v15; // rax
  char v16; // dl
  Scaleform::GFx::InteractiveObject *v17; // rbx
  char RollOverCnt; // al
  char v19; // cl
  __int64 v20; // r13
  __int64 v21; // rcx
  Scaleform::GFx::InteractiveObject *Size; // rdx
  char *v23; // rbx
  __int64 v24; // rsi
  char v25; // r15
  __int64 v26; // rcx
  __int64 v27; // rcx
  __int64 v28; // r8
  char v29; // al
  char v30; // dl
  __int64 v31; // rcx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *v32; // r12
  unsigned __int64 v33; // r14
  unsigned __int64 v34; // rbx
  Scaleform::GFx::InteractiveObject *v35; // rcx
  unsigned __int64 i; // rbx
  __int64 v37; // rbx
  Scaleform::RefCountNTSImpl *v38; // rcx
  Scaleform::GFx::InteractiveObject *v39; // rcx
  char *v40; // rcx
  __int64 v41; // rax
  __int64 v42; // rax
  char v43; // dl
  char v44; // r8
  Scaleform::RefCountNTSImpl *v45; // rcx
  unsigned __int8 v46; // r14
  Scaleform::GFx::InteractiveObject *v47; // rsi
  unsigned int v48; // eax
  __int64 v49; // r12
  char *v50; // r13
  Scaleform::GFx::InteractiveObject *v51; // rax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *MouseButtonDownEntity; // rax
  unsigned __int64 v53; // rcx
  int v54; // eax
  char *v55; // rcx
  __int64 v56; // rax
  char v57; // al
  int v58; // eax
  float y; // xmm1_4
  int WheelDelta; // ecx
  unsigned int v61; // r12d
  Scaleform::GFx::InteractiveObject *v62; // r14
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v63; // rax
  int v64; // ebx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v65; // rax
  bool v66; // r14
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v67; // rax
  bool v68; // bl
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v69; // rax
  Scaleform::GFx::InteractiveObject *v70; // r13
  __int64 v71; // r14
  __int64 v72; // rdx
  __int64 v73; // rdx
  Scaleform::GFx::InteractiveObject *v74; // rbx
  Scaleform::GFx::InteractiveObject *v75; // rax
  Scaleform::GFx::InteractiveObject *v76; // r13
  Scaleform::GFx::InteractiveObject *v77; // rsi
  Scaleform::GFx::InteractiveObject *v78; // r15
  char v79; // cl
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *v80; // r12
  unsigned __int64 v81; // r13
  Scaleform::GFx::InteractiveObject *v82; // rcx
  __int64 v83; // r14
  unsigned __int64 v84; // r8
  Scaleform::GFx::InteractiveObject *v85; // rcx
  Scaleform::GFx::InteractiveObject *pParent; // r14
  bool v87; // zf
  char *v88; // rcx
  __int64 v89; // rax
  __int64 v90; // rdx
  char v91; // cl
  Scaleform::RefCountNTSImpl *v92; // rcx
  __int64 v93; // r13
  unsigned __int8 v94; // r14
  char v95; // si
  Scaleform::WeakPtrProxy *WeakProxy; // rbx
  Scaleform::WeakPtrProxy *v97; // rdx
  Scaleform::WeakPtrProxy *v98; // rdx
  __int64 v99; // [rsp+20h] [rbp-A0h] BYREF
  int v100; // [rsp+28h] [rbp-98h]
  unsigned __int8 v101; // [rsp+2Ch] [rbp-94h]
  char v102; // [rsp+30h] [rbp-90h]
  char v103; // [rsp+31h] [rbp-8Fh]
  unsigned __int8 v104; // [rsp+32h] [rbp-8Eh]
  char v105; // [rsp+33h] [rbp-8Dh]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> result; // [rsp+38h] [rbp-88h] BYREF
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> v107; // [rsp+40h] [rbp-80h] BYREF
  __int64 v108; // [rsp+48h] [rbp-78h] BYREF
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> v109; // [rsp+50h] [rbp-70h] BYREF
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> v110; // [rsp+58h] [rbp-68h] BYREF
  Scaleform::GFx::MovieImpl::DragState st; // [rsp+60h] [rbp-60h] BYREF
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> v112; // [rsp+90h] [rbp-30h] BYREF
  Scaleform::GFx::InteractiveObject *v113; // [rsp+98h] [rbp-28h]
  __int64 v114; // [rsp+A0h] [rbp-20h]
  Scaleform::GFx::AS3::MovieRoot *v115; // [rsp+110h] [rbp+50h]
  unsigned int v116; // [rsp+118h] [rbp+58h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> v117; // [rsp+120h] [rbp+60h] BYREF
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> v118; // [rsp+128h] [rbp+68h] BYREF

  v114 = -2i64;
  v2 = mouseIndex;
  v3 = this;
  LODWORD(st.pCharacter) = 0;
  if ( mouseIndex < 6 )
    v4 = &this->pMovieImpl->mMouseState[mouseIndex];
  else
    v4 = 0i64;
  v108 = (__int64)v4;
  Scaleform::GFx::MouseState::GetActiveEntity(v4, &result);
  Scaleform::GFx::MouseState::GetTopmostEntity(v4, &v107);
  memset(&st, 0, 18);
  memset(&st.BoundLT, 0, 24);
  st.MouseIndex = -1;
  Scaleform::GFx::MovieImpl::GetDragState(v3->pMovieImpl, v2, &st);
  if ( st.MouseIndex != (_DWORD)v2 || !st.pCharacter || (st.pCharacter->Flags & 0x1000) != 0 )
    goto LABEL_17;
  if ( !st.pTopmostEntity )
    goto LABEL_16;
  v5 = (char *)st.pTopmostEntity + 4 * (unsigned __int8)st.pTopmostEntity->AvmObjOffset;
  v6 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 8i64))(v5);
  v7 = (Scaleform::GFx::AS3::AvmDisplayObj *)(v6 - 56);
  if ( !v6 )
    v7 = 0i64;
  if ( !Scaleform::GFx::AS3::AvmDisplayObj::IsStageAccessible(v7) )
  {
LABEL_16:
    Scaleform::GFx::MovieImpl::SetDragStateTopmostEntity(v3->pMovieImpl, v2, v107.pObject);
LABEL_17:
    pObject = v107.pObject;
    goto LABEL_18;
  }
  pObject = st.pTopmostEntity;
  if ( st.pTopmostEntity )
    ++st.pTopmostEntity->RefCount;
  if ( v107.pObject )
    Scaleform::RefCountNTSImpl::Release(v107.pObject);
  v107.pObject = pObject;
LABEL_18:
  pTopmostEntity = result.pObject;
  st.pTopmostEntity = result.pObject;
  if ( result.pObject && (result.pObject->Flags & 0x10) != 0 )
  {
    Scaleform::RefCountNTSImpl::Release(result.pObject);
    pTopmostEntity = 0i64;
    st.pTopmostEntity = 0i64;
    result.pObject = 0i64;
    pObject = v107.pObject;
  }
  if ( pObject && (pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x10) != 0 )
  {
    Scaleform::RefCountNTSImpl::Release(pObject);
    v107.pObject = 0i64;
    pTopmostEntity = result.pObject;
    st.pTopmostEntity = result.pObject;
  }
  if ( pTopmostEntity )
  {
    ++pTopmostEntity->RefCount;
    pTopmostEntity = result.pObject;
    st.pTopmostEntity = result.pObject;
  }
  v113 = pTopmostEntity;
  if ( (unsigned int)v2 >= 6 )
    v10 = 0i64;
  else
    v10 = &v3->pMovieImpl->KeyboardStates[v2];
  States = Scaleform::GFx::KeyboardState::GetKeyModifiers(v10, (Scaleform::KeyModifiers *)&v117)->States;
  v13 = 1;
  if ( v3->pAVM.pObject->ExtensionsEnabled )
    v13 = 16;
  HIDWORD(st.pCharacter) = v13;
  PrevButtonsState = v4->PrevButtonsState;
  LODWORD(st.BoundLT.y) = PrevButtonsState ^ v4->CurButtonsState;
  v15 = v107.pObject;
  if ( !v107.pObject )
    v107.pObject = v3->pStage.pObject;
  if ( (PrevButtonsState & 1) != 0 )
  {
    if ( (*((_BYTE *)v4 + 76) & 4) != 0 )
    {
      v17 = result.pObject;
      if ( v15 == result.pObject )
        goto LABEL_78;
      if ( result.pObject )
      {
        RollOverCnt = result.pObject->RollOverCnt;
        if ( RollOverCnt )
        {
          v19 = RollOverCnt - 1;
          result.pObject->RollOverCnt = RollOverCnt - 1;
          v17 = result.pObject;
        }
        else
        {
          v19 = -1;
        }
        v99 = 0x10000i64;
        v100 = 0;
        v105 = 0;
        v101 = 0;
        v103 = v2;
        v102 = v19;
        v104 = States;
        v17->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor(
          v17,
          (unsigned int)&v99);
      }
      *((_BYTE *)v4 + 76) &= ~4u;
    }
    else
    {
      if ( v15 != result.pObject )
      {
LABEL_48:
        v20 = 224 * v2;
        v21 = (__int64)v115;
        Size = (Scaleform::GFx::InteractiveObject *)v115->mMouseState[v2].RolloverStack.Data.Size;
        v117.pObject = Size;
        v23 = (char *)&Size[-1].DisplayCallbackUserPtr + 7;
        if ( (__int64)&Size[-1].DisplayCallbackUserPtr + 7 >= 0 )
        {
          v24 = (__int64)v115;
          v25 = v116;
          while ( 1 )
          {
            if ( v15 )
            {
              v26 = *(_QWORD *)(224 * (v2 + 4) + v24);
              if ( *(Scaleform::GFx::InteractiveObject **)(v26 + 8i64 * (_QWORD)v23) == v15
                || Scaleform::GFx::DisplayObjectBase::IsAncestor(
                     *(Scaleform::GFx::DisplayObjectBase **)(v26 + 8i64 * (_QWORD)v23),
                     v15) )
              {
                break;
              }
            }
            v27 = 224 * (v2 + 4);
            v28 = *(_QWORD *)(*(_QWORD *)(v27 + v24) + 8i64 * (_QWORD)v23);
            v29 = *(_BYTE *)(v28 + 192);
            if ( v29 )
            {
              v30 = v29 - 1;
              *(_BYTE *)(v28 + 192) = v29 - 1;
            }
            else
            {
              v30 = -1;
            }
            v99 = 0x4000i64;
            v100 = 0;
            v105 = 0;
            v101 = 0;
            v103 = v25;
            v102 = v30;
            v104 = States;
            v31 = *(_QWORD *)(*(_QWORD *)(v27 + v24) + 8i64 * (_QWORD)v23);
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v31 + 800i64))(v31, &v99);
            if ( (__int64)--v23 < 0 )
              break;
            v15 = v107.pObject;
          }
          pTopmostEntity = st.pTopmostEntity;
          v4 = (Scaleform::GFx::MouseState *)v108;
          Size = v117.pObject;
          v21 = (__int64)v115;
        }
        v32 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *)(v21 + 224 * (v2 + 4));
        v33 = v32->Size;
        v34 = (unsigned __int64)&v23[v33 - (_QWORD)Size + 1];
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          v32,
          v32,
          v34);
        if ( v34 > v33 )
        {
          v35 = (Scaleform::GFx::InteractiveObject *)&v32->Data[v33];
          v117.pObject = v35;
          for ( i = v34 - v33; i; --i )
          {
            v118.pObject = v35;
            if ( v35 )
              v35->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = 0i64;
            v35 = (Scaleform::GFx::InteractiveObject *)((char *)v35 + 8);
            v117.pObject = v35;
          }
        }
        v17 = result.pObject;
        if ( result.pObject )
        {
          ++result.pObject->RefCount;
          v37 = (__int64)v115;
          v38 = v115->mMouseState[(unsigned __int64)v20 / 0xE0].LastMouseOverObj.pObject;
          if ( v38 )
            Scaleform::RefCountNTSImpl::Release(v38);
          v39 = result.pObject;
          *(Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)(v20 + v37 + 920) = result;
          if ( v39
            && (v40 = (char *)v39 + 4 * (unsigned __int8)v39->AvmObjOffset,
                v41 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v40 + 8i64))(v40),
                v39 = result.pObject,
                v41) )
          {
            v42 = v41 - 56;
          }
          else
          {
            v42 = 0i64;
          }
          v43 = *(_BYTE *)(v42 + 64);
          if ( v43 )
          {
            v44 = v43 - 1;
            *(_BYTE *)(v42 + 64) = v43 - 1;
            v39 = result.pObject;
          }
          else
          {
            v44 = -1;
          }
          v99 = 16777227i64;
          v100 = 0;
          v105 = 0;
          v101 = 0;
          v103 = v116;
          v102 = v44;
          v104 = States;
          v39->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor(
            v39,
            (unsigned int)&v99);
          v45 = *(Scaleform::RefCountNTSImpl **)(v20 + v37 + 920);
          if ( v45 )
            Scaleform::RefCountNTSImpl::Release(v45);
          *(_QWORD *)(v20 + v37 + 920) = 0i64;
          v17 = result.pObject;
        }
        v3 = v115;
        v15 = v107.pObject;
        goto LABEL_78;
      }
      if ( result.pObject )
      {
        v16 = result.pObject->RollOverCnt;
        result.pObject->RollOverCnt = v16 + 1;
        v99 = 0x8000i64;
        v100 = 0;
        v105 = 0;
        v101 = 0;
        v103 = v2;
        v102 = v16;
        v104 = States;
        result.pObject->vfptr[100].__vecDelDtor(result.pObject, (unsigned int)&v99);
      }
      *((_BYTE *)v4 + 76) |= 4u;
    }
    v15 = v107.pObject;
  }
  v17 = result.pObject;
  if ( v15 != result.pObject )
    goto LABEL_48;
LABEL_78:
  v46 = 0;
  if ( !BYTE4(st.pCharacter) )
    goto LABEL_110;
  p_pObject = (Scaleform::GFx::InteractiveObject **)dword_141864B20;
  v47 = v107.pObject;
  do
  {
    if ( ((LODWORD(st.BoundLT.y) >> v46) & 1) != 0 && ((1 << v46) & v4->PrevButtonsState) != 0 )
    {
      if ( v46 <= 4u )
        v48 = dword_141864B20[v46];
      else
        v48 = (int)logf((float)v46);
      v49 = 3i64 * v48;
      v50 = (char *)v3 + 224 * v116;
      v51 = Scaleform::GFx::MouseState::GetMouseButtonDownEntity(v4, &v112, v46)->pObject;
      v117.pObject = v51;
      if ( v112.pObject )
      {
        Scaleform::RefCountNTSImpl::Release(v112.pObject);
        v51 = v117.pObject;
      }
      if ( v51 )
      {
        v99 = 4096i64;
        v100 = 0;
        v105 = 0;
        v101 = v46;
        v103 = v116;
        v102 = 0;
        v104 = States;
        MouseButtonDownEntity = Scaleform::GFx::MouseState::GetMouseButtonDownEntity(v4, &v109, v46);
        MouseButtonDownEntity->pObject->vfptr[100].__vecDelDtor(MouseButtonDownEntity->pObject, (unsigned int)&v99);
        if ( v109.pObject )
          Scaleform::RefCountNTSImpl::Release(v109.pObject);
      }
      v108 = 32i64;
      LODWORD(v109.pObject) = 0;
      BYTE4(v109.pObject) = v46;
      BYTE1(v110.pObject) = v116;
      LOBYTE(v110.pObject) = 0;
      WORD1(v110.pObject) = States;
      v47->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor(
        v47,
        (unsigned int)&v108);
      if ( (*((_BYTE *)v4 + 76) & 4) == 0 )
        goto LABEL_107;
      LOBYTE(v117.pObject) = 0;
      v53 = Scaleform::Timer::GetTicks() / 0x3E8;
      *(_QWORD *)&st.LockCenter = v53;
      v54 = *(_DWORD *)&v50[4 * v49 + 928];
      if ( !v54
        || (unsigned int)v53 > v54 + 300
        || COERCE_INT(*(float *)&v50[4 * v49 + 932] * 0.050000001) != COERCE_INT(v4->LastPosition.x * 0.050000001)
        || COERCE_INT(*(float *)&v50[4 * v49 + 936] * 0.050000001) != COERCE_INT(v4->LastPosition.y * 0.050000001) )
      {
        goto LABEL_99;
      }
      LOBYTE(v117.pObject) = 1;
      v55 = (char *)v47 + 4 * (unsigned __int8)v47->AvmObjOffset;
      v56 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v55 + 8i64))(v55);
      if ( v56 )
        v56 -= 56i64;
      if ( (*(_BYTE *)(v56 + 65) & 2) != 0 )
      {
        v99 = 16777229i64;
        v100 = 0;
        v105 = 0;
        v101 = v46;
        v103 = v116;
        v102 = 0;
        v104 = States;
        v47->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor(
          v47,
          (unsigned int)&v99);
      }
      else
      {
LABEL_99:
        v57 = v47 == Scaleform::GFx::MouseState::GetMouseButtonDownEntity(v4, &v110, v46)->pObject;
        LOBYTE(v118.pObject) = v57;
        if ( v110.pObject )
        {
          Scaleform::RefCountNTSImpl::Release(v110.pObject);
          v57 = (char)v118.pObject;
        }
        if ( v57 )
        {
          v99 = 16777228i64;
          v100 = 0;
          v105 = 0;
          v101 = v46;
          v103 = v116;
          v102 = 0;
          v104 = States;
          v47->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor(
            v47,
            (unsigned int)&v99);
        }
        if ( !LOBYTE(v117.pObject) )
        {
          v58 = *(_DWORD *)&st.LockCenter;
          goto LABEL_106;
        }
      }
      v58 = 0;
LABEL_106:
      *(_DWORD *)&v50[4 * v49 + 928] = v58;
      y = v4->LastPosition.y;
      *(float *)&v50[4 * v49 + 932] = v4->LastPosition.x;
      *(float *)&v50[4 * v49 + 936] = y;
LABEL_107:
      Scaleform::GFx::MouseState::SetMouseButtonDownEntity(v4, v46, 0i64);
      p_pObject = (Scaleform::GFx::InteractiveObject **)dword_141864B20;
    }
    ++v46;
    v3 = v115;
  }
  while ( v46 < BYTE4(st.pCharacter) );
  v17 = result.pObject;
  v15 = v107.pObject;
  pTopmostEntity = st.pTopmostEntity;
LABEL_110:
  WheelDelta = v4->WheelDelta;
  v61 = v116;
  v62 = v107.pObject;
  if ( WheelDelta )
  {
    v108 = 16777230i64;
    LODWORD(v109.pObject) = 0;
    BYTE4(v109.pObject) = 0;
    BYTE1(v110.pObject) = v116;
    LOBYTE(v110.pObject) = 0;
    BYTE2(v110.pObject) = States;
    BYTE3(v110.pObject) = WheelDelta;
    v107.pObject->vfptr[100].__vecDelDtor(v107.pObject, (unsigned int)&v108);
    v17 = result.pObject;
    v15 = v107.pObject;
  }
  if ( (*((_BYTE *)v4 + 76) & 8) != 0 )
  {
    v108 = 8i64;
    LODWORD(v109.pObject) = 0;
    BYTE4(v109.pObject) = 0;
    BYTE1(v110.pObject) = v61;
    LOBYTE(v110.pObject) = 0;
    BYTE2(v110.pObject) = States;
    BYTE3(v110.pObject) = v4->WheelDelta;
    v62->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor(
      v62,
      (unsigned int)&v108);
    v63 = Scaleform::GFx::MouseState::GetMouseButtonDownEntity(v4, &v118, 0);
    v64 = 1;
    LODWORD(st.pCharacter) = 1;
    v66 = 0;
    if ( v63->pObject )
    {
      v65 = Scaleform::GFx::MouseState::GetMouseButtonDownEntity(v4, &v117, 0);
      v64 = 3;
      LODWORD(st.pCharacter) = 3;
      if ( v65->pObject != v62 )
        v66 = 1;
    }
    if ( (v64 & 2) != 0 )
    {
      v64 &= ~2u;
      LODWORD(st.pCharacter) = v64;
      if ( v117.pObject )
        Scaleform::RefCountNTSImpl::Release(v117.pObject);
    }
    if ( (v64 & 1) != 0 )
    {
      LODWORD(st.pCharacter) = v64 & 0xFFFFFFFE;
      if ( v118.pObject )
        Scaleform::RefCountNTSImpl::Release(v118.pObject);
    }
    if ( v66 )
    {
      v67 = Scaleform::GFx::MouseState::GetMouseButtonDownEntity(v4, &v117, 0);
      v68 = ((unsigned int (__fastcall *)(Scaleform::GFx::InteractiveObject *))v67->pObject->vfptr[81].__vecDelDtor)(v67->pObject) == 4;
      if ( v117.pObject )
        Scaleform::RefCountNTSImpl::Release(v117.pObject);
      if ( v68 )
      {
        v99 = 8i64;
        v100 = 0;
        v105 = 0;
        v101 = 0;
        v103 = v61;
        v102 = 0;
        v104 = States;
        v69 = Scaleform::GFx::MouseState::GetMouseButtonDownEntity(v4, &v117, 0);
        v69->pObject->vfptr[99].__vecDelDtor(v69->pObject, (unsigned int)&v99);
        if ( v117.pObject )
          Scaleform::RefCountNTSImpl::Release(v117.pObject);
      }
    }
    v15 = v107.pObject;
    v17 = result.pObject;
  }
  if ( v15 == v17 )
  {
    if ( v15 )
      goto LABEL_172;
    v93 = (__int64)v115;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &v115->mMouseState[v61].RolloverStack.Data,
      &v115->mMouseState[v61],
      0i64);
    v17 = result.pObject;
  }
  else
  {
    if ( v15 )
    {
      ++v15->RefCount;
      v17 = result.pObject;
      v15 = v107.pObject;
    }
    if ( v17 )
    {
      Scaleform::RefCountNTSImpl::Release(v17);
      v15 = v107.pObject;
    }
    result.pObject = v15;
    if ( v15 )
    {
      v118.pObject = (Scaleform::GFx::InteractiveObject *)v61;
      v70 = (Scaleform::GFx::InteractiveObject *)(224i64 * v61);
      v117.pObject = v70;
      v71 = (__int64)v115;
      v72 = *(unsigned __int64 *)((char *)&v115->mMouseState[0].RolloverStack.Data.Size + (_QWORD)v70);
      if ( v72 && (v73 = v72 - 1, v73 >= 0) )
      {
        p_pObject = &v115->mMouseState[v61].RolloverStack.Data.Data[v73].pObject;
        while ( *p_pObject != v15 )
        {
          --p_pObject;
          if ( --v73 < 0 )
            goto LABEL_141;
        }
      }
      else
      {
LABEL_141:
        ++v15->RefCount;
        v74 = result.pObject;
        v109.pObject = result.pObject;
        v75 = *(Scaleform::GFx::InteractiveObject **)(v71 + 352);
        v76 = *(Scaleform::GFx::InteractiveObject **)((char *)&v70[4].Id.Id + v71);
        v110.pObject = v76;
        if ( result.pObject )
        {
          v77 = v118.pObject;
          v78 = v75;
          do
          {
            if ( v74 == v78
              || v76
              && *(Scaleform::GFx::InteractiveObject **)(*(_QWORD *)(224i64
                                                                   * ((_QWORD)&v77->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                    + 4)
                                                                   + v71)
                                                       + 8i64 * (_QWORD)v76
                                                       - 8) == v74 )
            {
              break;
            }
            v79 = v74->RollOverCnt;
            v74->RollOverCnt = v79 + 1;
            v108 = 0x2000i64;
            LODWORD(v109.pObject) = 0;
            BYTE4(v109.pObject) = 0;
            BYTE1(v110.pObject) = v61;
            LOBYTE(v110.pObject) = v79;
            WORD1(v110.pObject) = States;
            ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int64 *, Scaleform::GFx::InteractiveObject **))v74->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor)(
              v74,
              &v108,
              p_pObject);
            v80 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *)(v71 + 224i64 * ((_QWORD)&v77->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr + 4));
            v81 = v80->Size;
            Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
              v80,
              v80,
              v81 + 1);
            if ( v81 + 1 > v81 )
            {
              v82 = (Scaleform::GFx::InteractiveObject *)&v80->Data[v81];
              v118.pObject = v82;
              v83 = 1i64;
              do
              {
                *(_QWORD *)&st.LockCenter = v82;
                if ( v82 )
                  v82->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = 0i64;
                v82 = (Scaleform::GFx::InteractiveObject *)((char *)v82 + 8);
                v118.pObject = v82;
                --v83;
              }
              while ( v83 );
            }
            v84 = v80->Size;
            v76 = v110.pObject;
            if ( (unsigned __int64)v110.pObject < v84 - 1 )
              memmove(
                &v80->Data[(__int64)v110.pObject + 1],
                &v80->Data[(__int64)v110.pObject],
                8 * (v84 - (unsigned __int64)v110.pObject) - 8);
            v85 = (Scaleform::GFx::InteractiveObject *)&v80->Data[(_QWORD)v76];
            v118.pObject = v85;
            *(_QWORD *)&st.LockCenter = v85;
            if ( v85 )
            {
              ++v74->RefCount;
              v85->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)v74;
            }
            pParent = v74->pParent;
            if ( pParent )
              ++pParent->RefCount;
            Scaleform::RefCountNTSImpl::Release(v74);
            v74 = pParent;
            v109.pObject = pParent;
            v87 = pParent == 0i64;
            v71 = (__int64)v115;
            LOBYTE(v61) = v116;
          }
          while ( !v87 );
          pTopmostEntity = st.pTopmostEntity;
          v4 = (Scaleform::GFx::MouseState *)v108;
        }
        if ( v74 )
          Scaleform::RefCountNTSImpl::Release(v74);
        v70 = v117.pObject;
        v15 = result.pObject;
      }
      if ( v15
        && (v88 = (char *)v15 + 4 * (unsigned __int8)v15->AvmObjOffset,
            (v89 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v88 + 8i64))(v88)) != 0) )
      {
        v90 = v89 - 56;
      }
      else
      {
        v90 = 0i64;
      }
      v91 = *(_BYTE *)(v90 + 64);
      *(_BYTE *)(v90 + 64) = v91 + 1;
      v99 = 16777226i64;
      v100 = 0;
      v105 = 0;
      v101 = 0;
      v103 = v61;
      v102 = v91;
      v104 = States;
      result.pObject->vfptr[100].__vecDelDtor(result.pObject, (unsigned int)&v99);
      v92 = *(Scaleform::GFx::InteractiveObject **)((char *)&v70[4].pParent + v71);
      if ( v92 )
        Scaleform::RefCountNTSImpl::Release(v92);
      *(Scaleform::GFx::InteractiveObject **)((char *)&v70[4].pParent + v71) = 0i64;
    }
    *((_BYTE *)v4 + 76) |= 4u;
    v17 = result.pObject;
LABEL_172:
    v93 = (__int64)v115;
  }
  v94 = 0;
  if ( BYTE4(st.pCharacter) )
  {
    v95 = v116;
    do
    {
      if ( ((LODWORD(st.BoundLT.y) >> v94) & 1) != 0 && ((1 << v94) & v4->PrevButtonsState) == 0 )
      {
        v108 = 16i64;
        LODWORD(v109.pObject) = 0;
        BYTE1(v110.pObject) = v95;
        LOBYTE(v110.pObject) = 0;
        WORD1(v110.pObject) = States;
        if ( !v17 )
          v17 = *(Scaleform::GFx::InteractiveObject **)(v93 + 352);
        BYTE4(v109.pObject) = v94;
        v17->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor(
          v17,
          (unsigned int)&v108);
        Scaleform::GFx::MouseState::SetMouseButtonDownEntity(v4, v94, v17);
        *((_BYTE *)v4 + 76) |= 4u;
        v17 = result.pObject;
      }
      ++v94;
    }
    while ( v94 < BYTE4(st.pCharacter) );
    pTopmostEntity = st.pTopmostEntity;
  }
  if ( v17 )
  {
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(v17);
    v97 = v4->ActiveEntity.pProxy.pObject;
    if ( v97 )
    {
      v87 = v97->RefCount-- == 1;
      if ( v87 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    v4->ActiveEntity.pProxy.pObject = WeakProxy;
  }
  else
  {
    v98 = v4->ActiveEntity.pProxy.pObject;
    if ( v98 )
    {
      v87 = v98->RefCount-- == 1;
      if ( v87 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    v4->ActiveEntity.pProxy.pObject = 0i64;
  }
  *((_BYTE *)v4 + 76) &= ~8u;
  v4->WheelDelta = 0;
  if ( pTopmostEntity )
    Scaleform::RefCountNTSImpl::Release(pTopmostEntity);
  if ( v107.pObject )
    Scaleform::RefCountNTSImpl::Release(v107.pObject);
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release(result.pObject);
}

// File Line: 1122
// RVA: 0x7BCA20
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::MovieRoot::CreateEventObject(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::ASString *type,
        bool bubbles,
        bool cancelable)
{
  ((void (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *))this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[4].__vecDelDtor)(this);
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
    (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *)this->pAVM.pObject->EventDispatcherClass.pObject,
    result,
    type,
    bubbles,
    cancelable);
  return result;
}

// File Line: 1130
// RVA: 0x7C63C0
void __fastcall Scaleform::GFx::AS3::MovieRoot::DoActions(Scaleform::GFx::AS3::MovieRoot *this)
{
  unsigned int ASFramesToExecute; // edx
  Scaleform::GFx::AS3::ASVM *pObject; // rax
  Scaleform::GFx::AS3::ASVM *v4; // rax

  ASFramesToExecute = this->ASFramesToExecute;
  if ( ASFramesToExecute )
  {
    Scaleform::GFx::AS3::VM::ExecuteCode(this->pAVM.pObject, ASFramesToExecute);
    pObject = this->pAVM.pObject;
    if ( pObject->HandleException )
      pObject->HandleException = 0;
    this->ASFramesToExecute = 0;
  }
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueues(this);
  v4 = this->pAVM.pObject;
  if ( v4->HandleException )
    v4->HandleException = 0;
}

// File Line: 1156
// RVA: 0x7CADA0
void __fastcall Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::MovieRoot::ActionLevel lvl)
{
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *i; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator v4; // [rsp+28h] [rbp-40h] BYREF

  v4.pActionQueue = &this->ActionQueue;
  v4.Level = lvl;
  v4.ModId = 0;
  v4.pLastEntry = 0i64;
  v4.pRootEntry = 0i64;
  v4.pCurEntry = this->ActionQueue.Entries[lvl].pActionRoot;
  for ( i = Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&v4);
        i;
        i = Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&v4) )
  {
    Scaleform::GFx::AS3::MovieRoot::ActionEntry::Execute(i, this);
  }
  if ( v4.pLastEntry )
    Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(v4.pActionQueue, v4.pLastEntry);
}

// File Line: 1169
// RVA: 0x812880
void __fastcall Scaleform::GFx::AS3::MovieRoot::RequeueActionQueue(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::MovieRoot::ActionLevel srclvl,
        Scaleform::GFx::AS3::MovieRoot::ActionLevel dstlvl)
{
  __int64 v3; // rbx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *p_ActionQueue; // r12
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *Next; // rdi
  Scaleform::GFx::AS3::MovieRoot::ActionQueueEntry *v6; // rsi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *NewEntry; // rbx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry **p_pNextEntry; // rax
  Scaleform::GFx::DisplayObject *pObject; // rax
  Scaleform::RefCountNTSImpl *v10; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *p_pAS3Obj; // r15
  Scaleform::GFx::AS3::RefCountBaseGC<328> **p_pObject; // r14
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::Resource *v15; // rcx
  Scaleform::Render::RenderBuffer *v16; // rcx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator v17; // [rsp+28h] [rbp-50h] BYREF

  v3 = dstlvl;
  if ( this->ActionQueue.Entries[srclvl].pActionRoot )
  {
    p_ActionQueue = &this->ActionQueue;
    v17.pActionQueue = &this->ActionQueue;
    v17.Level = srclvl;
    v17.ModId = 0;
    v17.pLastEntry = 0i64;
    v17.pRootEntry = 0i64;
    v17.pCurEntry = this->ActionQueue.Entries[srclvl].pActionRoot;
    Next = Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&v17);
    if ( Next )
    {
      v6 = &p_ActionQueue->Entries[v3];
      do
      {
        NewEntry = Scaleform::GFx::AS3::MovieRoot::ActionQueueType::GetNewEntry(p_ActionQueue);
        p_pNextEntry = &v6->pInsertEntry->pNextEntry;
        if ( p_pNextEntry )
        {
          NewEntry->pNextEntry = *p_pNextEntry;
          v6->pInsertEntry->pNextEntry = NewEntry;
        }
        else
        {
          NewEntry->pNextEntry = v6->pActionRoot;
          v6->pActionRoot = NewEntry;
        }
        v6->pInsertEntry = NewEntry;
        if ( !NewEntry->pNextEntry )
          v6->pLastEntry = NewEntry;
        ++p_ActionQueue->ModId;
        NewEntry->Type = Next->Type;
        pObject = Next->pCharacter.pObject;
        if ( pObject )
          ++pObject->RefCount;
        v10 = NewEntry->pCharacter.pObject;
        if ( v10 )
          Scaleform::RefCountNTSImpl::Release(v10);
        NewEntry->pCharacter.pObject = Next->pCharacter.pObject;
        p_pAS3Obj = &Next->pAS3Obj;
        p_pObject = &NewEntry->pAS3Obj.pObject;
        if ( &Next->pAS3Obj != &NewEntry->pAS3Obj )
        {
          if ( p_pAS3Obj->pObject )
            p_pAS3Obj->pObject->RefCount = (p_pAS3Obj->pObject->RefCount + 1) & 0x8FBFFFFF;
          v13 = *p_pObject;
          if ( *p_pObject )
          {
            if ( ((unsigned __int8)v13 & 1) != 0 )
            {
              *p_pObject = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v13 - 1);
            }
            else
            {
              RefCount = v13->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v13->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
              }
            }
          }
          *p_pObject = p_pAS3Obj->pObject;
        }
        NewEntry->mEventId.Id = Next->mEventId.Id;
        NewEntry->mEventId.WcharCode = Next->mEventId.WcharCode;
        NewEntry->mEventId.KeyCode = Next->mEventId.KeyCode;
        NewEntry->mEventId.AsciiCode = Next->mEventId.AsciiCode;
        NewEntry->mEventId.RollOverCnt = Next->mEventId.RollOverCnt;
        NewEntry->mEventId.ControllerIndex = Next->mEventId.ControllerIndex;
        NewEntry->mEventId.KeysState.States = Next->mEventId.KeysState.States;
        NewEntry->mEventId.MouseWheelDelta = Next->mEventId.MouseWheelDelta;
        NewEntry->CFunction = Next->CFunction;
        v15 = (Scaleform::GFx::Resource *)Next->pNLoadInitCL.pObject;
        if ( v15 )
          Scaleform::Render::RenderBuffer::AddRef(v15);
        v16 = (Scaleform::Render::RenderBuffer *)NewEntry->pNLoadInitCL.pObject;
        if ( v16 )
          Scaleform::RefCountImpl::Release(v16);
        NewEntry->pNLoadInitCL.pObject = Next->pNLoadInitCL.pObject;
        Next = Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&v17);
      }
      while ( Next );
    }
    if ( v17.pLastEntry )
      Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(v17.pActionQueue, v17.pLastEntry);
  }
}

// File Line: 1182
// RVA: 0x811250
void __fastcall Scaleform::GFx::AS3::MovieRoot::RemoveActionQueueEntriesFor(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::MovieRoot::ActionLevel lvl,
        Scaleform::GFx::DisplayObject *dobj)
{
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *i; // rbx
  Scaleform::GFx::DisplayObject *pObject; // rcx

  for ( i = this->ActionQueue.Entries[lvl].pActionRoot; i; i = i->pNextEntry )
  {
    pObject = i->pCharacter.pObject;
    if ( pObject == dobj )
    {
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
      i->pCharacter.pObject = 0i64;
    }
  }
}

// File Line: 1245
// RVA: 0x7CAE30
void __fastcall Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueues(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::MovieRoot::ActionLevel v2; // ebx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *p_ActionQueue; // rsi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *i; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator v5; // [rsp+28h] [rbp-40h] BYREF

  v2 = AL_Highest;
  p_ActionQueue = &this->ActionQueue;
  do
  {
    v5.pActionQueue = p_ActionQueue;
    v5.Level = v2;
    v5.ModId = 0;
    v5.pLastEntry = 0i64;
    v5.pRootEntry = 0i64;
    v5.pCurEntry = p_ActionQueue->Entries[v2].pActionRoot;
    for ( i = Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&v5);
          i;
          i = Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&v5) )
    {
      Scaleform::GFx::AS3::MovieRoot::ActionEntry::Execute(i, this);
    }
    if ( v5.pLastEntry )
      Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(v5.pActionQueue, v5.pLastEntry);
    ++v2;
  }
  while ( (unsigned int)v2 < AL_Count_ );
}

// File Line: 1260
// RVA: 0x7B33E0
void __fastcall Scaleform::GFx::AS3::MovieRoot::ChangeMouseCursorType(
        Scaleform::GFx::AS3::MovieRoot *this,
        unsigned int mouseIdx,
        unsigned int newCursorType)
{
  Scaleform::GFx::AS3::Stage *pObject; // rax
  Scaleform::GFx::AS3::ASVM *v7; // rbx
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *v8; // rbx
  Scaleform::GFx::AS3::Stage *v9; // rcx
  char *v10; // rcx
  __int64 v11; // rax
  __int64 v12; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v13; // rcx
  Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent *v14; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v17; // zf
  Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent *v18; // rcx
  unsigned int v19; // eax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdx
  Scaleform::GFx::UserEventHandler *v22; // rcx
  int v23; // [rsp+28h] [rbp-30h] BYREF
  char v24; // [rsp+2Ch] [rbp-2Ch]
  unsigned int v25; // [rsp+30h] [rbp-28h]
  unsigned int v26; // [rsp+34h] [rbp-24h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent> v27; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+20h] BYREF

  pObject = this->pStage.pObject;
  if ( pObject )
  {
    v7 = this->pAVM.pObject;
    if ( v7 )
    {
      if ( v7->ExtensionsEnabled && pObject->MouseCursorEventCnt )
      {
        v8 = (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *)v7->EventDispatcherClass.pObject;
        result.pNode = this->BuiltinsMgr.Builtins[0].pNode;
        ++result.pNode->RefCount;
        Scaleform::GFx::AS3::MovieRoot::GetMouseCursorTypeString(this, &result, newCursorType);
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseCursorEventObject(
          v8,
          &v27,
          &result,
          mouseIdx);
        v9 = this->pStage.pObject;
        if ( v9
          && (v10 = (char *)v9 + 4 * (unsigned __int8)v9->AvmObjOffset,
              (v11 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v10 + 8i64))(v10)) != 0) )
        {
          v12 = v11 - 56;
        }
        else
        {
          v12 = 0i64;
        }
        v13 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v12 + 16);
        if ( !v13 )
          v13 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v12 + 8);
        if ( ((unsigned __int8)v13 & 1) != 0 )
          v13 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v13 - 1);
        if ( v13
          && !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
                v13,
                v27.pObject,
                this->pStage.pObject) )
        {
          v14 = v27.pObject;
          if ( v27.pObject )
          {
            if ( ((__int64)v27.pObject & 1) != 0 )
            {
              --v27.pObject;
            }
            else
            {
              RefCount = v27.pObject->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v27.pObject->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
              }
            }
          }
          pNode = result.pNode;
          v17 = result.pNode->RefCount-- == 1;
          if ( v17 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          return;
        }
        v18 = v27.pObject;
        if ( v27.pObject )
        {
          if ( ((__int64)v27.pObject & 1) != 0 )
          {
            --v27.pObject;
          }
          else
          {
            v19 = v27.pObject->RefCount;
            if ( (v19 & 0x3FFFFF) != 0 )
            {
              v27.pObject->RefCount = v19 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
            }
          }
        }
        v20 = result.pNode;
        v17 = result.pNode->RefCount-- == 1;
        if ( v17 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v20);
      }
    }
  }
  pMovieImpl = this->pMovieImpl;
  v22 = pMovieImpl->pUserEventHandler.pObject;
  if ( v22 )
  {
    v24 = 0;
    v23 = 23;
    v25 = newCursorType;
    v26 = mouseIdx;
    ((void (__fastcall *)(Scaleform::GFx::UserEventHandler *, Scaleform::GFx::MovieImpl *, int *))v22->vfptr[1].__vecDelDtor)(
      v22,
      pMovieImpl,
      &v23);
  }
}

// File Line: 1296
// RVA: 0x802830
bool __fastcall Scaleform::GFx::AS3::MovieRoot::NotifyOnFocusChange(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *curFocused,
        Scaleform::GFx::InteractiveObject *toBeFocused,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt,
        Scaleform::GFx::ProcessFocusKeyInfo *pfocusKeyInfo)
{
  char *v8; // rcx
  Scaleform::GFx::AS3::Stage *pObject; // rcx
  __int64 v10; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v11; // rcx

  if ( curFocused )
  {
    v8 = (char *)curFocused + 4 * (unsigned __int8)curFocused->AvmObjOffset;
  }
  else
  {
    pObject = this->pStage.pObject;
    if ( !pObject )
    {
LABEL_7:
      v11 = 0i64;
      return Scaleform::GFx::AS3::AvmInteractiveObj::OnFocusChange(v11, toBeFocused, controllerIdx, fmt, pfocusKeyInfo);
    }
    v8 = (char *)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
  }
  v10 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v8 + 8i64))(v8);
  if ( !v10 )
    goto LABEL_7;
  v11 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v10 - 56);
  return Scaleform::GFx::AS3::AvmInteractiveObj::OnFocusChange(v11, toBeFocused, controllerIdx, fmt, pfocusKeyInfo);
}

// File Line: 1310
// RVA: 0x8028C0
void __fastcall Scaleform::GFx::AS3::MovieRoot::NotifyQueueSetFocus(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *ch,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::MovieImpl::TransferFocus(this->pMovieImpl, ch, controllerIdx, fmt);
}

// File Line: 1352
// RVA: 0x7BE8E0
Scaleform::GFx::AS3::AvmStage *__fastcall Scaleform::GFx::AS3::MovieRoot::CreateStage(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::MovieDefImpl *pdefImpl)
{
  char *v4; // rbx
  Scaleform::GFx::AS3::Stage *v5; // rax
  Scaleform::GFx::AS3::Stage *v6; // rsi
  Scaleform::GFx::AS3::Stage *pObject; // rcx
  Scaleform::GFx::AS3::AvmStage *v8; // rax
  Scaleform::GFx::AS3::AvmStage *v9; // rbp
  Scaleform::GFx::AS3::ASVM *v10; // rax
  Scaleform::GFx::AS3::VMAppDomain *v11; // rax
  Scaleform::GFx::AS3::Stage *v12; // rsi
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *p_ActionQueue; // rdi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *NewEntry; // rbx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pInsertEntry; // rax
  Scaleform::RefCountNTSImpl *v16; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v17; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::Render::RenderBuffer *v21; // rcx
  Scaleform::GFx::AS3::AvmStage *result; // rax
  char *id; // [rsp+70h] [rbp+8h] BYREF
  char *v24; // [rsp+80h] [rbp+18h]
  char *v25; // [rsp+88h] [rbp+20h]

  v4 = (char *)this->pMovieImpl->pHeap->vfptr->Alloc(this->pMovieImpl->pHeap, 384i64, 0i64);
  v24 = v4;
  v25 = v4;
  if ( v4 )
  {
    LODWORD(id) = 0x40000;
    Scaleform::GFx::AS3::Stage::Stage((Scaleform::GFx::AS3::Stage *)v4, pdefImpl, this, 0i64, &id);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  pObject = this->pStage.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pStage.pObject = v6;
  id = v4 + 304;
  if ( v4 == (char *)-304i64 )
  {
    v9 = 0i64;
  }
  else
  {
    Scaleform::GFx::AS3::AvmStage::AvmStage((Scaleform::GFx::AS3::AvmStage *)(v4 + 304), this->pStage.pObject);
    v9 = v8;
  }
  v10 = this->pAVM.pObject;
  if ( v10->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    v11 = v10->CallStack.Pages[(v10->CallStack.Size - 1) >> 6][(LODWORD(v10->CallStack.Size) - 1) & 0x3F].pFile->AppDomain.pObject;
  else
    v11 = v10->CurrentDomain.pObject;
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
    v9->AppDomain = v11;
  v12 = this->pStage.pObject;
  p_ActionQueue = &this->ActionQueue;
  NewEntry = Scaleform::GFx::AS3::MovieRoot::ActionQueueType::GetNewEntry(p_ActionQueue);
  pInsertEntry = p_ActionQueue->Entries[0].pInsertEntry;
  if ( pInsertEntry )
  {
    NewEntry->pNextEntry = pInsertEntry->pNextEntry;
    p_ActionQueue->Entries[0].pInsertEntry->pNextEntry = NewEntry;
  }
  else
  {
    NewEntry->pNextEntry = p_ActionQueue->Entries[0].pActionRoot;
    p_ActionQueue->Entries[0].pActionRoot = NewEntry;
  }
  p_ActionQueue->Entries[0].pInsertEntry = NewEntry;
  if ( !NewEntry->pNextEntry )
    p_ActionQueue->Entries[0].pLastEntry = NewEntry;
  ++p_ActionQueue->ModId;
  NewEntry->Type = Entry_Buffer;
  if ( v12 )
    ++v12->RefCount;
  v16 = NewEntry->pCharacter.pObject;
  if ( v16 )
    Scaleform::RefCountNTSImpl::Release(v16);
  NewEntry->pCharacter.pObject = v12;
  *(_QWORD *)&NewEntry->mEventId.Id = 1i64;
  NewEntry->mEventId.KeyCode = 0;
  NewEntry->mEventId.AsciiCode = 0;
  *(_DWORD *)&NewEntry->mEventId.RollOverCnt = 65280;
  NewEntry->CFunction = 0i64;
  v17 = NewEntry->pAS3Obj.pObject;
  if ( v17 )
  {
    if ( ((unsigned __int8)v17 & 1) != 0 )
    {
      NewEntry->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v17 - 1);
    }
    else
    {
      RefCount = v17->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v17->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
      }
    }
    NewEntry->pAS3Obj.pObject = 0i64;
  }
  if ( (NewEntry->Function.Flags & 0x1F) > 9 )
  {
    if ( (NewEntry->Function.Flags & 0x200) != 0 )
    {
      pWeakProxy = NewEntry->Function.Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      NewEntry->Function.Bonus.pWeakProxy = 0i64;
      NewEntry->Function.value.VS._1.VStr = 0i64;
      NewEntry->Function.value.VS._2.VObj = 0i64;
      NewEntry->Function.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&NewEntry->Function);
    }
  }
  NewEntry->Function.Flags &= 0xFFFFFFE0;
  v21 = (Scaleform::Render::RenderBuffer *)NewEntry->pNLoadInitCL.pObject;
  if ( v21 )
    Scaleform::RefCountImpl::Release(v21);
  result = v9;
  NewEntry->pNLoadInitCL.pObject = 0i64;
  return result;
}

// File Line: 1365
// RVA: 0x7B0220
void __fastcall Scaleform::GFx::AS3::MovieRoot::AdvanceFrame(Scaleform::GFx::AS3::MovieRoot *this, bool nextFrame)
{
  _QWORD *v4; // r14
  Scaleform::GFx::DisplayObject *v5; // rax
  Scaleform::GFx::DisplayObject *v6; // rdi
  char *v7; // rcx
  __int64 v8; // rax
  __int64 v9; // rcx
  __int64 v10; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v11; // rcx
  unsigned int v12; // edi
  bool v13; // di
  int v14; // eax
  Scaleform::GFx::AS3::ASRefCountCollector *pObject; // rcx
  Scaleform::AmpStats *v16; // rdx
  unsigned int CollectionScheduledFlags; // r8d

  if ( (this->MainLoaderInfoEventsState & 2) != 0 )
    goto LABEL_25;
  v4 = (_QWORD *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pMovieImpl->pMainMovie->vfptr[66].__vecDelDtor)(this->pMovieImpl->pMainMovie);
  v5 = (Scaleform::GFx::DisplayObject *)this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[16].__vecDelDtor(
                                          this,
                                          0i64);
  v6 = v5;
  if ( v5
    && (v7 = (char *)v5 + 4 * (unsigned __int8)v5->AvmObjOffset,
        (v8 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v7 + 40i64))(v7)) != 0) )
  {
    v9 = v8 - 72;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = *(_QWORD *)(v9 + 16);
  if ( !v10 )
    v10 = *(_QWORD *)(v9 + 8);
  if ( (v10 & 1) != 0 )
    --v10;
  if ( v10 )
    *(_DWORD *)(v10 + 32) = (*(_DWORD *)(v10 + 32) + 1) & 0x8FBFFFFF;
  if ( v10 )
  {
    v11 = *(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo **)(v10 + 80);
    if ( v11 )
    {
      if ( (this->MainLoaderInfoEventsState & 1) == 0 )
      {
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteInitEvent(v11, v6);
        this->MainLoaderInfoEventsState |= 1u;
      }
      v12 = (*(__int64 (__fastcall **)(_QWORD *))(*v4 + 64i64))(v4);
      v13 = (*(unsigned int (__fastcall **)(_QWORD *))(*v4 + 40i64))(v4) >= v12;
      if ( !nextFrame && !v13 )
        goto LABEL_21;
      Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteProgressEvent(
        *(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo **)(v10 + 80),
        *(unsigned int *)(v4[13] + 244i64),
        *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(v4[13] + 24i64) + 64i64) + 80i64));
      if ( !v13 )
        goto LABEL_21;
      Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteCompleteEvent(*(Scaleform::GFx::AS3::Instances::fl_net::URLLoader **)(v10 + 80));
    }
  }
  this->MainLoaderInfoEventsState |= 2u;
LABEL_21:
  if ( v10 )
  {
    if ( (v10 & 1) == 0 )
    {
      v14 = *(_DWORD *)(v10 + 32);
      if ( (v14 & 0x3FFFFF) != 0 )
      {
        *(_DWORD *)(v10 + 32) = v14 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v10);
      }
    }
  }
LABEL_25:
  if ( this->StageInvalidated )
  {
    Scaleform::GFx::AS3::EventChains::QueueEvents(&this->mEventChains, Event_Render);
    ((void (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *))this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[7].__vecDelDtor)(this);
    this->StageInvalidated = 0;
  }
  if ( nextFrame )
  {
    pObject = this->MemContext.pObject->ASGC.pObject;
    if ( pObject )
    {
      v16 = this->pMovieImpl->AdvanceStats.pObject;
      CollectionScheduledFlags = pObject->CollectionScheduledFlags;
      if ( CollectionScheduledFlags )
      {
        pObject->CollectionScheduledFlags = 0;
        Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(pObject, v16, CollectionScheduledFlags);
      }
      Scaleform::GFx::AS3::ASRefCountCollector::AdvanceFrame(
        this->MemContext.pObject->ASGC.pObject,
        &this->NumAdvancesSinceCollection,
        &this->LastCollectionFrame,
        (Scaleform::GFx::Resource *)this->pMovieImpl->AdvanceStats.pObject);
    }
  }
}

// File Line: 1428
// RVA: 0x7B4B90
void __fastcall Scaleform::GFx::AS3::MovieRoot::ClearDisplayList(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // rbx

  pMainMovie = this->pMovieImpl->pMainMovie;
  Scaleform::GFx::DisplayList::Clear((Scaleform::GFx::DisplayList *)&pMainMovie[1], pMainMovie);
  _((AMD_HD3D *)pMainMovie);
  ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pMovieImpl->pMainMovie->vfptr[75].__vecDelDtor)(this->pMovieImpl->pMainMovie);
  ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pMovieImpl->pMainMovie->vfptr[60].__vecDelDtor)(this->pMovieImpl->pMainMovie);
  Scaleform::ArrayData<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->pMovieImpl->MovieLevels.Data,
    0i64);
}

// File Line: 1451
// RVA: 0x7BDFF0
Scaleform::GFx::AS3::MovieDefRootNode *__fastcall Scaleform::GFx::AS3::MovieRoot::CreateMovieDefRootNode(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::MemoryHeap *pheap,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        bool importFlag)
{
  __int64 v6; // rcx

  v6 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pheap->vfptr->Alloc)(pheap, 88i64);
  if ( !v6 )
    return 0i64;
  *(_QWORD *)v6 = &Scaleform::GFx::MovieDefRootNode::`vftable;
  *(_DWORD *)(v6 + 24) = 1;
  *(_QWORD *)(v6 + 32) = pdefImpl;
  *(_BYTE *)(v6 + 48) = importFlag;
  *(_QWORD *)(v6 + 56) = 0i64;
  *(_QWORD *)v6 = &Scaleform::GFx::AS3::MovieDefRootNode::`vftable;
  *(_QWORD *)(v6 + 64) = 0i64;
  *(_QWORD *)(v6 + 72) = 0i64;
  *(_QWORD *)(v6 + 80) = 0i64;
  return (Scaleform::GFx::AS3::MovieDefRootNode *)v6;
}

// File Line: 1457
// RVA: 0x7D74F0
void __fastcall Scaleform::GFx::AS3::MovieRoot::ForceCollect(
        Scaleform::GFx::AS3::MovieRoot *this,
        unsigned int gcFlags)
{
  int v2; // edx
  unsigned int v3; // r8d
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdx

  if ( gcFlags )
  {
    v2 = gcFlags - 1;
    if ( v2 )
    {
      if ( v2 == 1 )
        v3 = 32;
      else
        v3 = 0;
    }
    else
    {
      v3 = 16;
    }
  }
  else
  {
    v3 = 8;
  }
  pMovieImpl = this->pMovieImpl;
  if ( !pMovieImpl->pRenderRoot.pObject || (pMovieImpl->Flags2 & 4) != 0 )
    v3 |= 1u;
  Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(
    this->MemContext.pObject->ASGC.pObject,
    (Scaleform::GFx::Resource *)pMovieImpl->AdvanceStats.pObject,
    v3);
}

// File Line: 1474
// RVA: 0x7D7550
void __fastcall Scaleform::GFx::AS3::MovieRoot::ForceEmergencyCollect(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::MemoryContextImpl *pObject; // rax
  Scaleform::GFx::AS3::ASRefCountCollector *v2; // rbx

  pObject = this->MemContext.pObject;
  v2 = pObject->ASGC.pObject;
  if ( v2->SuspendCnt )
  {
    v2->CollectionScheduledFlags = 10;
  }
  else
  {
    Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(
      pObject->ASGC.pObject,
      (Scaleform::GFx::Resource *)this->pMovieImpl->AdvanceStats.pObject,
      2u);
    *(_QWORD *)&v2->MaxRootCount = v2->PresetMaxRootCount;
  }
}

// File Line: 1479
// RVA: 0x8250F0
void __fastcall Scaleform::GFx::AS3::MovieRoot::SuspendGC(Scaleform::GFx::AS3::MovieRoot *this, bool suspend)
{
  Scaleform::GFx::AS3::ASRefCountCollector *pObject; // rcx

  pObject = this->MemContext.pObject->ASGC.pObject;
  if ( suspend )
    ++pObject->SuspendCnt;
  else
    --pObject->SuspendCnt;
}

// File Line: 1484
// RVA: 0x8174E0
void __fastcall Scaleform::GFx::AS3::MovieRoot::ScheduleGC(Scaleform::GFx::AS3::MovieRoot *this, unsigned int gcFlags)
{
  int v2; // edx
  int v3; // edx

  if ( gcFlags )
  {
    v2 = gcFlags - 1;
    if ( v2 )
    {
      if ( v2 == 1 )
        v3 = 32;
      else
        v3 = 0;
    }
    else
    {
      v3 = 16;
    }
  }
  else
  {
    v3 = 8;
  }
  this->MemContext.pObject->ASGC.pObject->CollectionScheduledFlags = v3 & 0xFFFFFFF3 | 8;
}

// File Line: 1497
// RVA: 0x804AA0
void __fastcall Scaleform::GFx::AS3::MovieRoot::OnKeyDown(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *pmovie,
        Scaleform::GFx::EventId *evt,
        int keyMask)
{
  Scaleform::GFx::InteractiveObject *pObject; // r8
  char *v8; // rcx
  __int64 v9; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v10; // rcx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pInsertEntry; // rcx
  char *v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> result; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::GFx::MovieImpl::GetFocusedCharacter(
    *(Scaleform::GFx::MovieImpl **)&this[-1].AccelerometerArray.Owner,
    &result,
    evt->ControllerIndex);
  if ( !_bittest(
          &keyMask,
          *(unsigned __int8 *)((unsigned int)evt->ControllerIndex
                             + *(_QWORD *)&this[-1].AccelerometerArray.Owner
                             + 21156i64)) )
  {
    pObject = result.pObject;
    if ( result.pObject )
    {
      v8 = (char *)result.pObject + 4 * (unsigned __int8)result.pObject->AvmObjOffset;
      v9 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v8 + 8i64))(v8);
      if ( v9 )
        v9 -= 56i64;
      v10 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v9 + 16);
      if ( !v10 )
        v10 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v9 + 8);
      if ( ((unsigned __int8)v10 & 1) != 0 )
        v10 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v10 - 1);
      pObject = result.pObject;
    }
    else
    {
      pInsertEntry = this->ActionQueue.Entries[6].pInsertEntry;
      if ( pInsertEntry
        && (v12 = (char *)pInsertEntry + 4 * BYTE5(pInsertEntry[1].pNextEntry),
            v13 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v12 + 40i64))(v12),
            pObject = result.pObject,
            v13) )
      {
        v14 = v13 - 72;
      }
      else
      {
        v14 = 0i64;
      }
      v10 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v14 + 16);
      if ( !v10 )
        v10 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v14 + 8);
      if ( ((unsigned __int8)v10 & 1) != 0 )
        v10 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v10 - 1);
    }
    if ( v10 )
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(v10, evt, pObject);
  }
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release(result.pObject);
}

// File Line: 1556
// RVA: 0x805220
void __fastcall Scaleform::GFx::AS3::MovieRoot::OnMovieFocus(Scaleform::GFx::AS3::MovieRoot *this, bool set)
{
  Scaleform::GFx::AS3::EventChains *p_mEventChains; // rcx
  bool v3; // zf
  signed int v4; // edx

  p_mEventChains = &this->mEventChains;
  v3 = !set;
  v4 = 16777233;
  if ( v3 )
    v4 = 16777234;
  Scaleform::GFx::AS3::EventChains::Dispatch(p_mEventChains, v4);
}

// File Line: 1566
// RVA: 0x805240
void __fastcall Scaleform::GFx::AS3::MovieRoot::OnNextFrame(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::EventChains::QueueEvents(&this->mEventChains, Event_EnterFrame);
}

// File Line: 1575
// RVA: 0x819960
void __fastcall Scaleform::GFx::AS3::MovieRoot::SetExternalInterfaceRetVal(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Value *retVal)
{
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(this, retVal, &this->ExternalIntfRetVal);
}

// File Line: 1582
// RVA: 0x7D1310
char __fastcall Scaleform::GFx::AS3::MovieRoot::ExtractPathAndName(
        Scaleform::GFx::AS3::MovieRoot *this,
        const char *fullPath,
        Scaleform::GFx::ASString *ppath,
        Scaleform::GFx::ASString *pname)
{
  __int64 v8; // rax
  const char *v9; // rcx
  unsigned __int64 v10; // rbp
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rbx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h] BYREF

  v8 = -1i64;
  do
    ++v8;
  while ( fullPath[v8] );
  if ( v8 )
  {
    while ( fullPath[v8] != 46 )
    {
      if ( !--v8 )
        goto LABEL_8;
    }
    v9 = &fullPath[v8];
  }
  else
  {
LABEL_8:
    v9 = 0i64;
    if ( *fullPath == 46 )
      v9 = fullPath;
  }
  if ( !v9 )
    return 0;
  v10 = (int)v9 - (int)fullPath;
  v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          &this->BuiltinsMgr,
          &result,
          &fullPath[v10 + 1]);
  pNode = v11->pNode;
  ++v11->pNode->RefCount;
  v13 = pname->pNode;
  v14 = pname->pNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  pname->pNode = pNode;
  v15 = result.pNode;
  v14 = result.pNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  v16 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          &this->BuiltinsMgr,
          &result,
          fullPath,
          v10);
  v17 = v16->pNode;
  ++v16->pNode->RefCount;
  v18 = ppath->pNode;
  v14 = ppath->pNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  ppath->pNode = v17;
  v19 = result.pNode;
  v14 = result.pNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  return 1;
}

// File Line: 1614
// RVA: 0x815E10
void __fastcall Scaleform::GFx::AS3::MovieRoot::ResolveStickyVariables(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *pch)
{
  Scaleform::GFx::CharacterHandle *pObject; // rax
  Scaleform::GFx::ASString *p_NamePath; // rsi
  char *v6; // rcx
  __int64 v7; // rax
  __int64 v8; // rbx
  Scaleform::GFx::ASStringHash<Scaleform::GFx::MovieImpl::StickyVarNode *> *p_StickyVariables; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v10; // rdi
  __int64 v11; // rax
  unsigned __int64 *v12; // rcx
  Scaleform::GFx::MovieImpl::StickyVarNode *v13; // r13
  __int64 v14; // r12
  unsigned int Flags; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // r14
  Scaleform::GFx::AS3::Value::V1U v17; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // r15
  Scaleform::GFx::AS3::Instances::fl::XMLList *v19; // rcx
  const char *pData; // rax
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v23; // zf
  Scaleform::GFx::ASStringNode *v24; // rcx
  unsigned int Size; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VStr; // rcx
  unsigned int RefCount; // eax
  __int64 v28; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v29; // rcx
  unsigned int v30; // eax
  Scaleform::GFx::AS3::Value other; // [rsp+20h] [rbp-69h] BYREF
  int v32; // [rsp+40h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v33; // [rsp+48h] [rbp-41h] BYREF
  Scaleform::GFx::AS3::Value v34; // [rsp+50h] [rbp-39h] BYREF
  Scaleform::GFx::ASString *key; // [rsp+70h] [rbp-19h]
  Scaleform::GFx::ASString v36; // [rsp+78h] [rbp-11h] BYREF
  Scaleform::GFx::MovieImpl::StickyVarNode *v37; // [rsp+80h] [rbp-9h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v38; // [rsp+88h] [rbp-1h]
  __int64 v39; // [rsp+90h] [rbp+7h]
  Scaleform::GFx::MovieImpl::StickyVarNode *value; // [rsp+F8h] [rbp+6Fh] BYREF
  Scaleform::GFx::ASString result; // [rsp+100h] [rbp+77h] BYREF
  __int64 v43; // [rsp+108h] [rbp+7Fh]

  v39 = -2i64;
  pObject = pch->pNameHandle.pObject;
  if ( !pObject )
    pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pch);
  p_NamePath = &pObject->NamePath;
  key = &pObject->NamePath;
  v6 = (char *)pch + 4 * (unsigned __int8)pch->AvmObjOffset;
  v7 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v6 + 8i64))(v6);
  if ( v7 )
    v7 -= 56i64;
  v8 = *(_QWORD *)(v7 + 16);
  if ( !v8 )
    v8 = *(_QWORD *)(v7 + 8);
  if ( (v8 & 1) != 0 )
    --v8;
  if ( v8 )
  {
    p_StickyVariables = &this->pMovieImpl->StickyVariables;
    v10.pTable = p_StickyVariables->mHash.pTable;
    if ( p_StickyVariables->mHash.pTable )
    {
      v11 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
              &p_StickyVariables->mHash,
              p_NamePath,
              p_NamePath->pNode->HashFlags & v10.pTable->SizeMask);
      if ( v11 >= 0 )
      {
        v12 = &v10.pTable[1].SizeMask + 3 * v11;
        if ( v12 )
        {
          v37 = (Scaleform::GFx::MovieImpl::StickyVarNode *)v12[1];
          v13 = 0i64;
          v43 = 0i64;
          v14 = (__int64)v37;
          if ( v37 )
          {
            do
            {
              Flags = 10;
              other.Flags = 10;
              pWeakProxy = 0i64;
              other.Bonus.pWeakProxy = 0i64;
              v17 = *(Scaleform::GFx::AS3::Value::V1U *)(v14 + 8);
              other.value.VS._1 = v17;
              if ( v17.VStr == &v17.VStr->pManager->NullStringNode )
              {
                v17.VStr = 0i64;
                other.value.VS._1.VStr = 0i64;
                VObj = v38;
                other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v38;
                Flags = 12;
                other.Flags = 12;
              }
              else
              {
                ++v17.VStr->RefCount;
                VObj = other.value.VS._2.VObj;
              }
              v19 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)this->pAVM.pObject->PublicNamespace.pObject;
              v32 = 0;
              v33.pObject = v19;
              if ( v19 )
                v19->RefCount = (v19->RefCount + 1) & 0x8FBFFFFF;
              v34.Flags = 0;
              v34.Bonus.pWeakProxy = 0i64;
              if ( (Flags & 0x1F) - 12 <= 3
                && v17.VStr
                && (pData = v17.VStr[1].pData, *((_DWORD *)pData + 30) == 17)
                && (pData[112] & 0x20) == 0 )
              {
                Scaleform::GFx::AS3::Value::Assign(&v34, (Scaleform::GFx::ASString *)&v17.VStr[1].16);
                Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                  &v33,
                  *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v17.VStr[1].RefCount);
                v32 &= 0xFFFFFFF9;
              }
              else
              {
                Scaleform::GFx::AS3::Value::AssignUnsafe(&v34, &other);
                if ( (v34.Flags & 0x1F) == 10 )
                {
                  Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v34, &result);
                  if ( result.pNode->Size )
                  {
                    if ( *result.pNode->pData == 64 )
                    {
                      v32 |= 8u;
                      v21 = Scaleform::GFx::ASString::Substring(&result, &v36, 1, result.pNode->Size);
                      Scaleform::GFx::AS3::Value::Assign(&v34, v21);
                      pNode = v36.pNode;
                      v23 = v36.pNode->RefCount-- == 1;
                      if ( v23 )
                        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
                    }
                  }
                  v24 = result.pNode;
                  v23 = result.pNode->RefCount-- == 1;
                  if ( v23 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
                }
                Flags = other.Flags;
                pWeakProxy = other.Bonus.pWeakProxy;
                VObj = other.value.VS._2.VObj;
                v17 = other.value.VS._1;
              }
              if ( (Flags & 0x1F) > 9 )
              {
                if ( (Flags & 0x200) != 0 )
                {
                  v23 = pWeakProxy->RefCount-- == 1;
                  if ( v23 )
                    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
                  memset(&other.Bonus, 0, 24);
                  other.Flags = Flags & 0xFFFFFDE0;
                }
                else
                {
                  switch ( Flags & 0x1F )
                  {
                    case 0xAu:
                      v23 = v17.VStr->RefCount-- == 1;
                      if ( v23 )
                        Scaleform::GFx::ASStringNode::ReleaseNode(v17.VStr);
                      break;
                    case 0xBu:
                    case 0xCu:
                    case 0xDu:
                    case 0xEu:
                    case 0xFu:
                      if ( other.value.VS._1.VBool )
                      {
                        other.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)((char *)v17.VStr - 1);
                      }
                      else if ( v17.VStr )
                      {
                        Size = v17.VStr->Size;
                        if ( (Size & 0x3FFFFF) != 0 )
                        {
                          v17.VStr->Size = Size - 1;
                          VStr = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v17.VStr;
                          goto LABEL_50;
                        }
                      }
                      break;
                    case 0x10u:
                    case 0x11u:
                      if ( ((__int64)other.value.VS._2.VObj & 1) != 0 )
                      {
                        other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)&VObj[-1].RefCount + 7);
                      }
                      else if ( VObj )
                      {
                        RefCount = VObj->RefCount;
                        if ( (RefCount & 0x3FFFFF) != 0 )
                        {
                          VObj->RefCount = RefCount - 1;
                          VStr = VObj;
LABEL_50:
                          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VStr);
                        }
                      }
                      break;
                    default:
                      break;
                  }
                }
              }
              (*(void (__fastcall **)(__int64, Scaleform::GFx::MovieImpl::StickyVarNode **, int *, __int64))(*(_QWORD *)v8 + 24i64))(
                v8,
                &value,
                &v32,
                v14 + 32);
              v28 = *(_QWORD *)(v14 + 16);
              if ( *(_BYTE *)(v14 + 24) )
              {
                if ( v13 )
                  *(_QWORD *)(v43 + 16) = v14;
                else
                  v13 = (Scaleform::GFx::MovieImpl::StickyVarNode *)v14;
                v43 = v14;
                *(_QWORD *)(v14 + 16) = 0i64;
              }
              else
              {
                (**(void (__fastcall ***)(__int64, __int64))v14)(v14, 1i64);
              }
              v14 = v28;
              if ( (v34.Flags & 0x1F) > 9 )
              {
                if ( (v34.Flags & 0x200) != 0 )
                {
                  v23 = v34.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v23 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                  memset(&v34.Bonus, 0, 24);
                  v34.Flags &= 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v34);
                }
              }
              v29 = v33.pObject;
              if ( v33.pObject )
              {
                if ( ((__int64)v33.pObject & 1) != 0 )
                {
                  --v33.pObject;
                }
                else
                {
                  v30 = v33.pObject->RefCount;
                  if ( (v30 & 0x3FFFFF) != 0 )
                  {
                    v33.pObject->RefCount = v30 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v29);
                  }
                }
              }
            }
            while ( v28 );
            if ( v13 )
            {
              if ( v13 != v37 )
              {
                value = v13;
                Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Set(
                  &this->pMovieImpl->StickyVariables,
                  key,
                  &value);
              }
              return;
            }
            p_NamePath = key;
          }
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString>(
            &this->pMovieImpl->StickyVariables.mHash,
            p_NamePath);
        }
      }
    }
  }
}

// File Line: 1705
// RVA: 0x7E4A70
char __fastcall Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::Value *pval,
        const char *ppathToVar)
{
  const char *v3; // rbx
  Scaleform::GFx::AS3::MovieRoot *v5; // rsi
  Scaleform::GFx::InteractiveObject *pMainMovie; // rcx
  char *v8; // rcx
  __int64 v9; // rax
  _QWORD *v10; // r14
  Scaleform::GFx::AS3::Value::V1U v11; // rax
  unsigned int Flags; // edi
  bool v13; // zf
  unsigned __int64 v14; // rdi
  unsigned __int64 v15; // rax
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *v16; // r15
  Scaleform::GFx::AS3::ASVM *pObject; // r13
  int v18; // ecx
  bool v19; // si
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VMAppDomain *pHeap; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *ctr; // rcx
  unsigned int v24; // edx
  Scaleform::GFx::AS3::Value::Extra v25; // rax
  Scaleform::GFx::AS3::Value::VU value; // kr00_16
  char v27; // bl
  unsigned int v28; // esi
  char v29; // r12
  char v30; // cl
  Scaleform::GFx::AS3::MovieRoot *v31; // r15
  Scaleform::GFx::ASString *v32; // rax
  Scaleform::GFx::DisplayObject *DisplayObjectByName; // rsi
  Scaleform::GFx::ASStringNode *v34; // rcx
  char *v35; // rcx
  __int64 v36; // rax
  Scaleform::GFx::AS3::Value::V1U *v37; // rcx
  Scaleform::GFx::AS3::Value::V1U v38; // rax
  unsigned int v39; // esi
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *p_BuiltinsMgr; // rbx
  Scaleform::GFx::AS3::Value::V1U v41; // r12
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // r13
  unsigned int v43; // r15d
  Scaleform::StringDataPtr *NextToken; // rax
  const char *pStr; // r8
  unsigned __int64 Size; // r9
  unsigned __int64 v47; // rax
  const char *v48; // rdx
  unsigned __int64 v49; // rcx
  _BOOL8 v50; // rax
  unsigned int v51; // edi
  Scaleform::GFx::AS3::WeakProxy *v52; // r14
  Scaleform::GFx::ASStringNode *VStr; // rbx
  Scaleform::String *VObj; // rsi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v55; // rcx
  const char *pData; // rax
  Scaleform::GFx::ASString *v57; // rax
  Scaleform::GFx::ASStringNode *v58; // rcx
  Scaleform::GFx::ASStringNode *v59; // rcx
  unsigned int v60; // eax
  int v61; // eax
  const char *v62; // rcx
  Scaleform::GFx::ASStringManager *pManager; // rdx
  char *v64; // rcx
  __int64 v65; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v66; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v67; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v68; // rcx
  unsigned int RefCount; // eax
  int v70; // ebx
  Scaleform::GFx::AS3::Value::V2U v71; // rcx
  Scaleform::GFx::ASStringNode *v72; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v73; // rcx
  unsigned int v74; // eax
  Scaleform::GFx::AS3::GASRefCountBase *v75; // rcx
  unsigned int v76; // eax
  Scaleform::GFx::ASStringNode *v77; // rcx
  Scaleform::Log *v78; // rbx
  char *v79; // rdx
  Scaleform::GFx::ASStringNode *v80; // rcx
  Scaleform::GFx::AS3::ASVM *v81; // rcx
  Scaleform::GFx::ASStringNode *v82; // rcx
  Scaleform::GFx::AS3::Value other; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::AS3::Value v84; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::GFx::AS3::Value v85; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::GFx::ASString name; // [rsp+90h] [rbp-70h] BYREF
  Scaleform::GFx::AS3::Multiname v87; // [rsp+98h] [rbp-68h] BYREF
  Scaleform::GFx::ASString v88; // [rsp+C8h] [rbp-38h] BYREF
  Scaleform::StringDataPtr v89; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::StringDataPtr v; // [rsp+E0h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::PropRef v91; // [rsp+F0h] [rbp-10h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> v92; // [rsp+120h] [rbp+20h] BYREF
  Scaleform::StringBuffer v93; // [rsp+128h] [rbp+28h] BYREF
  Scaleform::StringDataPtr qname; // [rsp+158h] [rbp+58h] BYREF
  Scaleform::GFx::ASString v95; // [rsp+168h] [rbp+68h] BYREF
  Scaleform::MsgFormat::Sink v96; // [rsp+170h] [rbp+70h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [rsp+188h] [rbp+88h] BYREF
  __int64 v98; // [rsp+1B8h] [rbp+B8h]
  Scaleform::MsgFormat v99; // [rsp+1C0h] [rbp+C0h] BYREF
  const char *v102; // [rsp+620h] [rbp+520h] BYREF
  Scaleform::GFx::ASString result; // [rsp+628h] [rbp+528h] BYREF

  v102 = ppathToVar;
  v98 = -2i64;
  v3 = ppathToVar;
  v5 = this;
  if ( !ppathToVar )
    return 0;
  ((void (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *))this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[4].__vecDelDtor)(this);
  Scaleform::GFx::AS3::Value::SetUndefined(pval);
  v85.Flags = 0;
  v85.Bonus.pWeakProxy = 0i64;
  pMainMovie = v5->pMovieImpl->pMainMovie;
  if ( !pMainMovie
    || (v8 = (char *)pMainMovie + 4 * (unsigned __int8)pMainMovie->AvmObjOffset,
        v9 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v8 + 40i64))(v8),
        v10 = (_QWORD *)(v9 - 72),
        !v9) )
  {
    v10 = 0i64;
  }
  v11 = (Scaleform::GFx::AS3::Value::V1U)v10[2];
  if ( !v11.VStr )
    v11 = (Scaleform::GFx::AS3::Value::V1U)v10[1];
  if ( v11.VBool )
    --v11.VStr;
  other.Flags = 12;
  other.Bonus.pWeakProxy = 0i64;
  other.value.VS._1 = v11;
  if ( v11.VStr )
    v11.VStr->Size = (v11.VStr->Size + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::Value::Assign(&v85, &other);
  Flags = other.Flags;
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags & 0x200) != 0 )
    {
      v13 = other.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&other.Bonus, 0, 24);
      other.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  qname.pStr = v3;
  v14 = -1i64;
  v15 = -1i64;
  do
    ++v15;
  while ( v3[v15] );
  qname.Size = v15;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, v5->pAVM.pObject, &qname);
  memset(&v91, 0, 20);
  v91.This.Bonus.pWeakProxy = 0i64;
  v16 = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *)v10[5];
  pObject = v5->pAVM.pObject;
  v18 = mn.Name.Flags & 0x1F;
  if ( (mn.Name.Flags & 0x1F) == 0 )
    goto LABEL_38;
  if ( (unsigned int)(v18 - 12) > 3 && v18 != 10 )
    goto LABEL_33;
  if ( !mn.Name.value.VS._1.VStr )
    goto LABEL_38;
  if ( v18 != 10 )
    goto LABEL_33;
  Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&mn.Name, &result);
  v19 = !result.pNode->Size || *result.pNode->pData == pattern[0] && !*((_BYTE *)result.pNode->pData + 1);
  pNode = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v13 = !v19;
  v5 = this;
  if ( v13 )
  {
LABEL_33:
    pHeap = (Scaleform::GFx::AS3::VMAppDomain *)v16[2].Entries.mHash.pHeap;
    if ( pHeap && (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(pHeap, &mn)) != 0i64
      || (ClassTrait = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                         v16 + 3,
                         &mn)) != 0i64 )
    {
      ctr = *ClassTrait;
    }
    else
    {
      ctr = 0i64;
    }
  }
  else
  {
LABEL_38:
    ctr = pObject->TraitsClassClass.pObject;
  }
  Scaleform::GFx::AS3::FindGOProperty(&v91, v5->pAVM.pObject, &v5->pAVM.pObject->GlobalObjects, &mn, ctr);
  if ( (v91.This.Flags & 0x1F) != 0
    && (((__int64)v91.pSI & 1) == 0 || ((unsigned __int64)v91.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
    && (((__int64)v91.pSI & 2) == 0 || ((unsigned __int64)v91.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0) )
  {
    other.Flags = 0;
    other.Bonus.pWeakProxy = 0i64;
    if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(
           &v91,
           (Scaleform::GFx::AS3::CheckResult *)&v102,
           v5->pAVM.pObject,
           &other,
           valGet)->Result )
    {
      v24 = other.Flags;
      v25.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)other.Bonus;
      value = other.value;
      other.Flags = pval->Flags;
      other.Bonus.pWeakProxy = pval->Bonus.pWeakProxy;
      other.value = pval->value;
      pval->Flags = v24;
      pval->Bonus = v25;
      pval->value = value;
      v27 = 1;
    }
    else
    {
      v27 = 0;
    }
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
      {
        v13 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&other.Bonus, 0, 24);
        other.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
    goto LABEL_232;
  }
  v28 = 0;
  v29 = 1;
  if ( *v3 == 95 )
  {
    if ( !strncmp(v3 + 1, "root", 4ui64) )
    {
      v28 = 5;
    }
    else if ( !strncmp(v3 + 1, "level0", 5ui64) )
    {
      v28 = 7;
    }
  }
  else if ( *v3 == 114 )
  {
    if ( !strncmp(v3 + 1, "oot", 3ui64) )
      v28 = 4;
  }
  else if ( *v3 == 115 && !strncmp(v3 + 1, "tage", 4ui64) )
  {
    v28 = 5;
    v29 = 0;
  }
  v30 = v3[v28];
  if ( v30 )
  {
    if ( v30 != 46 )
    {
      v31 = this;
      goto LABEL_88;
    }
    ++v28;
  }
  v3 += v28;
  v31 = this;
  if ( v29 )
  {
    v32 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            &this->BuiltinsMgr,
            &result,
            "root1");
    DisplayObjectByName = Scaleform::GFx::DisplayList::GetDisplayObjectByName(
                            (Scaleform::GFx::DisplayList *)(v10[3] + 216i64),
                            v32,
                            1);
    v34 = result.pNode;
    v13 = result.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v34);
    if ( !DisplayObjectByName || (DisplayObjectByName->Scaleform::GFx::DisplayObjectBase::Flags & 0x200) == 0 )
    {
      v27 = 0;
      goto LABEL_232;
    }
    v35 = (char *)DisplayObjectByName + 4 * (unsigned __int8)DisplayObjectByName->AvmObjOffset;
    v36 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v35 + 40i64))(v35);
    v37 = (Scaleform::GFx::AS3::Value::V1U *)(v36 - 72);
    if ( !v36 )
      v37 = 0i64;
    v38 = v37[2];
    if ( !v38.VStr )
      v38 = v37[1];
    if ( v38.VBool )
      --v38.VStr;
    other.Flags = 12;
    other.Bonus.pWeakProxy = 0i64;
    other.value.VS._1 = v38;
    if ( v38.VStr )
      v38.VStr->Size = (v38.VStr->Size + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::Value::Assign(&v85, &other);
    v39 = other.Flags;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
      {
        v13 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&other.Bonus, 0, 24);
        other.Flags = v39 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
  }
LABEL_88:
  v89.pStr = v3;
  if ( v3 )
  {
    do
      ++v14;
    while ( v3[v14] );
  }
  else
  {
    v14 = 0i64;
  }
  v89.Size = v14;
  v.pStr = 0i64;
  v.Size = 0i64;
  if ( v14 )
  {
    p_BuiltinsMgr = &v31->BuiltinsMgr;
    qname.pStr = (const char *)&v31->BuiltinsMgr;
    v41 = v85.value.VS._1;
    pWeakProxy = v85.Bonus.pWeakProxy;
    v43 = v85.Flags;
    while ( 1 )
    {
      NextToken = Scaleform::StringDataPtr::GetNextToken(&v89, (Scaleform::StringDataPtr *)&v96, 46);
      pStr = NextToken->pStr;
      v.pStr = NextToken->pStr;
      Size = NextToken->Size;
      v.Size = Size;
      v47 = Size;
      if ( v89.Size < Size )
        v47 = v89.Size;
      v48 = &v89.pStr[v47];
      v89.pStr = v48;
      v49 = v89.Size - v47;
      v89.Size -= v47;
      if ( *v48 == 46 )
      {
        v50 = v49 != 0;
        v89.pStr = &v48[v50];
        v89.Size = v49 - v50;
      }
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
        p_BuiltinsMgr,
        &name,
        pStr,
        Size);
      v51 = 10;
      other.Flags = 10;
      v52 = 0i64;
      other.Bonus.pWeakProxy = 0i64;
      VStr = name.pNode;
      *(Scaleform::GFx::ASString *)&other.value.VNumber = (Scaleform::GFx::ASString)name.pNode;
      if ( name.pNode == &name.pNode->pManager->NullStringNode )
      {
        VStr = 0i64;
        other.value.VS._1.VStr = 0i64;
        VObj = v96.SinkData.pStr;
        other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v96.SinkData.pStr;
        v51 = 12;
        other.Flags = 12;
      }
      else
      {
        ++name.pNode->RefCount;
        VObj = (Scaleform::String *)other.value.VS._2.VObj;
      }
      v55 = this->pAVM.pObject->PublicNamespace.pObject;
      v87.Kind = MN_QName;
      v87.Obj.pObject = v55;
      if ( v55 )
        v55->RefCount = (v55->RefCount + 1) & 0x8FBFFFFF;
      v87.Name.Flags = 0;
      v87.Name.Bonus.pWeakProxy = 0i64;
      if ( (v51 & 0x1F) - 12 <= 3
        && VStr
        && (pData = VStr[1].pData, *((_DWORD *)pData + 30) == 17)
        && (pData[112] & 0x20) == 0 )
      {
        Scaleform::GFx::AS3::Value::Assign(&v87.Name, (Scaleform::GFx::ASString *)&VStr[1].16);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v87.Obj,
          *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&VStr[1].RefCount);
        v87.Kind &= 0xFFFFFFF9;
      }
      else
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(&v87.Name, &other);
        if ( (v87.Name.Flags & 0x1F) == 10 )
        {
          Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v87.Name, &v88);
          if ( v88.pNode->Size )
          {
            if ( *v88.pNode->pData == 64 )
            {
              v87.Kind |= 8u;
              v57 = Scaleform::GFx::ASString::Substring(&v88, &v95, 1, v88.pNode->Size);
              Scaleform::GFx::AS3::Value::Assign(&v87.Name, v57);
              v58 = v95.pNode;
              v13 = v95.pNode->RefCount-- == 1;
              if ( v13 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v58);
            }
          }
          v59 = v88.pNode;
          v13 = v88.pNode->RefCount-- == 1;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v59);
        }
        v51 = other.Flags;
        v52 = other.Bonus.pWeakProxy;
        VObj = (Scaleform::String *)other.value.VS._2.VObj;
        VStr = other.value.VS._1.VStr;
      }
      if ( (v51 & 0x1F) > 9 )
      {
        if ( (v51 & 0x200) != 0 )
        {
          v13 = v52->RefCount-- == 1;
          if ( v13 )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v52);
          memset(&other.Bonus, 0, 24);
          other.Flags = v51 & 0xFFFFFDE0;
        }
        else
        {
          switch ( v51 & 0x1F )
          {
            case 0xAu:
              v13 = VStr->RefCount-- == 1;
              if ( v13 )
                Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
              break;
            case 0xBu:
            case 0xCu:
            case 0xDu:
            case 0xEu:
            case 0xFu:
              if ( other.value.VS._1.VBool )
              {
                other.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)((char *)VStr - 1);
              }
              else if ( VStr )
              {
                v60 = VStr->Size;
                if ( (v60 & 0x3FFFFF) != 0 )
                {
                  VStr->Size = v60 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)VStr);
                }
              }
              break;
            case 0x10u:
            case 0x11u:
              if ( ((__int64)other.value.VS._2.VObj & 1) != 0 )
              {
                other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)&VObj[-1].HeapTypeBits + 7);
              }
              else if ( VObj )
              {
                v61 = (int)VObj[4].pData;
                if ( (v61 & 0x3FFFFF) != 0 )
                {
                  LODWORD(VObj[4].pData) = v61 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)VObj);
                }
              }
              break;
            default:
              break;
          }
        }
      }
      v84.Flags = 0;
      v84.Bonus.pWeakProxy = 0i64;
      if ( !v41.VStr )
        break;
      if ( !*(_BYTE *)(*((__int64 (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))v41.VStr->pData
                       + 4))(
                        v41,
                        &result,
                        &v87,
                        &v84) )
      {
        v62 = v41.VStr[1].pData;
        if ( (unsigned int)(*((_DWORD *)v62 + 30) - 29) < 5 && (v62[112] & 0x20) == 0 )
        {
          pManager = 0i64;
          if ( (WORD1(v41.VStr[2].pManager->NullStringNode.pData) & 0x200) != 0 )
            pManager = v41.VStr[2].pManager;
          if ( !pManager
            || (v64 = (char *)pManager + 4 * BYTE5(pManager->NullStringNode.pData),
                v65 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v64 + 40i64))(v64),
                v66 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v65 - 72),
                !v65) )
          {
            v66 = 0i64;
          }
          v67 = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(v66, &v92, &name)->pObject;
          v68 = v92.pObject;
          if ( v92.pObject )
          {
            if ( ((__int64)v92.pObject & 1) != 0 )
            {
              --v92.pObject;
            }
            else
            {
              RefCount = v92.pObject->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v92.pObject->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v68);
              }
            }
          }
          if ( !v67 )
            goto LABEL_220;
          LODWORD(v93.pData) = 12;
          v93.Size = 0i64;
          v93.BufferSize = (unsigned __int64)v67;
          v67->RefCount = (v67->RefCount + 1) & 0x8FBFFFFF;
          Scaleform::GFx::AS3::Value::Assign(&v84, (Scaleform::GFx::AS3::Value *)&v93);
          v70 = (int)v93.pData;
          if ( (unsigned __int64)((__int64)v93.pData & 0x1F) > 9 )
          {
            if ( ((__int64)v93.pData & 0x200) != 0 )
            {
              v13 = (*(_DWORD *)v93.Size)-- == 1;
              if ( v13 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v93.Size, 0, 24);
              LODWORD(v93.pData) = v70 & 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v93);
            }
          }
        }
      }
      if ( (v43 & 0x1F) > 9 )
      {
        if ( (v43 & 0x200) != 0 )
        {
          v13 = pWeakProxy->RefCount-- == 1;
          if ( v13 )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          memset(&v85.Bonus, 0, 24);
          v85.Flags = v43 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v85);
        }
      }
      _mm_prefetch((const char *)&v84, 2);
      v85 = v84;
      pWeakProxy = v84.Bonus.pWeakProxy;
      v71.VObj = (Scaleform::GFx::AS3::Object *)v84.value.VS._2;
      v41 = v84.value.VS._1;
      if ( (v84.Flags & 0x1F) > 9 )
      {
        if ( (v84.Flags & 0x200) != 0 )
        {
          ++v84.Bonus.pWeakProxy->RefCount;
        }
        else if ( (v84.Flags & 0x1F) == 10 )
        {
          ++v84.value.VS._1.VStr->RefCount;
        }
        else if ( (v84.Flags & 0x1F) > 0xA )
        {
          if ( (v84.Flags & 0x1F) <= 0xF )
          {
            if ( v84.value.VS._1.VStr )
            {
              ++v84.value.VS._1.VStr->Size;
              v41.VStr->Size &= 0x8FBFFFFF;
            }
          }
          else if ( (v84.Flags & 0x1F) <= 0x11 && v84.value.VS._2.VObj )
          {
            ++v84.value.VS._2.VObj->RefCount;
            v71.VObj->RefCount &= 0x8FBFFFFF;
          }
        }
      }
      v43 = v85.Flags;
      if ( v89.Size && (v85.Flags & 0x1F) - 12 > 3 )
      {
        v78 = Scaleform::GFx::StateBag::GetLog(
                &this->pMovieImpl->Scaleform::GFx::StateBag,
                (Scaleform::Ptr<Scaleform::Log> *)&result)->pObject;
        if ( result.pNode )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pNode);
        if ( v78 )
        {
          Scaleform::StringBuffer::StringBuffer(&v93, Scaleform::Memory::pGlobalHeap);
          v96.Type = tStrBuffer;
          v96.SinkData.pStr = (Scaleform::String *)&v93;
          Scaleform::MsgFormat::MsgFormat(&v99, &v96);
          Scaleform::MsgFormat::Parse(
            &v99,
            "Token {0} in path {1} was not resolved to a valid Object! This may be caused by a property that is not o"
            "f Object type, or by using reserved words/properties for MovieClip names in the display tree.");
          Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&v99, &v);
          Scaleform::MsgFormat::FormatD1<char const *>(&v99, &v102);
          Scaleform::MsgFormat::FinishFormatD(&v99);
          Scaleform::MsgFormat::~MsgFormat(&v99);
          v79 = &customCaption;
          if ( v93.pData )
            v79 = v93.pData;
          Scaleform::Log::LogError(v78, v79);
          Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v93);
        }
        Scaleform::GFx::AS3::Value::SetNull(&v85);
        if ( (v84.Flags & 0x1F) > 9 )
        {
          if ( (v84.Flags & 0x200) != 0 )
          {
            v13 = v84.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v13 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v84.Bonus, 0, 24);
            v84.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v84);
          }
        }
        Scaleform::GFx::AS3::Multiname::~Multiname(&v87);
        v80 = name.pNode;
        v13 = name.pNode->RefCount-- == 1;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v80);
        goto LABEL_231;
      }
      if ( (v84.Flags & 0x1F) > 9 )
      {
        if ( (v84.Flags & 0x200) != 0 )
        {
          v13 = v84.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v84.Bonus, 0, 24);
          v84.Flags &= 0xFFFFFDE0;
        }
        else
        {
          switch ( v84.Flags & 0x1F )
          {
            case 0xA:
              v72 = v84.value.VS._1.VStr;
              v13 = v84.value.VS._1.VStr->RefCount-- == 1;
              if ( v13 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v72);
              break;
            case 0xB:
            case 0xC:
            case 0xD:
            case 0xE:
            case 0xF:
              v73 = v84.value.VS._1.VObj;
              if ( !v84.value.VS._1.VBool )
                goto LABEL_187;
              --v84.value.VS._1.VStr;
              break;
            case 0x10:
            case 0x11:
              v73 = v84.value.VS._2.VObj;
              if ( ((__int64)v84.value.VS._2.VObj & 1) != 0 )
              {
                --v84.value.VS._2.VObj;
              }
              else
              {
LABEL_187:
                if ( v73 )
                {
                  v74 = v73->RefCount;
                  if ( (v74 & 0x3FFFFF) != 0 )
                  {
                    v73->RefCount = v74 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v73);
                  }
                }
              }
              break;
            default:
              break;
          }
        }
      }
      if ( (v87.Name.Flags & 0x1F) > 9 )
      {
        if ( (v87.Name.Flags & 0x200) != 0 )
        {
          v13 = v87.Name.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v87.Name.Bonus, 0, 24);
          v87.Name.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v87.Name);
        }
      }
      v75 = v87.Obj.pObject;
      if ( v87.Obj.pObject )
      {
        if ( ((__int64)v87.Obj.pObject & 1) != 0 )
        {
          --v87.Obj.pObject;
        }
        else
        {
          v76 = v87.Obj.pObject->RefCount;
          if ( (v76 & 0x3FFFFF) != 0 )
          {
            v87.Obj.pObject->RefCount = v76 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v75);
          }
        }
      }
      v77 = name.pNode;
      v13 = name.pNode->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v77);
      if ( !v89.Size )
        goto LABEL_231;
      p_BuiltinsMgr = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)qname.pStr;
    }
    Scaleform::GFx::AS3::Value::SetUndefined(pval);
LABEL_220:
    v81 = this->pAVM.pObject;
    if ( v81->HandleException )
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v81);
    if ( (v84.Flags & 0x1F) > 9 )
    {
      if ( (v84.Flags & 0x200) != 0 )
      {
        v13 = v84.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v84.Bonus, 0, 24);
        v84.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v84);
      }
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&v87);
    v82 = name.pNode;
    v13 = name.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v82);
    v27 = 0;
    goto LABEL_233;
  }
LABEL_231:
  Scaleform::GFx::AS3::Value::Assign(pval, &v85);
  v27 = 1;
LABEL_232:
  v43 = v85.Flags;
  pWeakProxy = v85.Bonus.pWeakProxy;
LABEL_233:
  if ( (v91.This.Flags & 0x1F) > 9 )
  {
    if ( (v91.This.Flags & 0x200) != 0 )
    {
      v13 = v91.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v91.This.Bonus, 0, 24);
      v91.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v91.This);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  if ( (v43 & 0x1F) > 9 )
  {
    if ( (v43 & 0x200) != 0 )
    {
      v13 = pWeakProxy->RefCount-- == 1;
      if ( v13 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      memset(&v85.Bonus, 0, 24);
      v85.Flags = v43 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v85);
    }
  }
  return v27;
} v91.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v91.This.Bonus, 0, 24);
      v91.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::

// File Line: 1844
// RVA: 0x7F11F0
char __fastcall Scaleform::GFx::AS3::MovieRoot::GetVariable(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Value *pval,
        const char *ppathToVar)
{
  int v6; // ebx
  bool v7; // zf
  int v9; // ebx
  char pvala[34]; // [rsp+28h] [rbp-30h] BYREF

  *(_DWORD *)pvala = 0;
  *(_QWORD *)&pvala[8] = 0i64;
  if ( (pval->Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval->pObjectInterface->vfptr->gap8[8])(
      pval->pObjectInterface,
      pval,
      pval->mValue);
    pval->pObjectInterface = 0i64;
  }
  pval->Type = VT_Undefined;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, (Scaleform::GFx::AS3::Value *)pvala, ppathToVar) )
  {
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, (Scaleform::GFx::AS3::Value *)pvala, pval);
    v6 = *(_DWORD *)&pvala[2];
    if ( (pvala[2] & 0x1Fu) > 9 )
    {
      if ( (*(_WORD *)&pvala[2] & 0x200) != 0 )
      {
        v7 = (**(_DWORD **)&pvala[10])-- == 1;
        if ( v7 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&pvala[10], 0, 24);
        *(_DWORD *)&pvala[2] = v6 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&pvala[2]);
      }
    }
    return 1;
  }
  else
  {
    v9 = *(_DWORD *)pvala;
    if ( (pvala[0] & 0x1Fu) > 9 )
    {
      if ( (*(_WORD *)pvala & 0x200) != 0 )
      {
        v7 = (**(_DWORD **)&pvala[8])-- == 1;
        if ( v7 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&pvala[8], 0, 24);
        *(_DWORD *)pvala = v9 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)pvala);
      }
    }
    return 0;
  }
}

// File Line: 1868
// RVA: 0x81F020
char __fastcall Scaleform::GFx::AS3::MovieRoot::SetVariable(
        Scaleform::GFx::AS3::MovieRoot *this,
        const char *ppathToVar,
        Scaleform::GFx::Value *value,
        Scaleform::GFx::Movie::SetVarType setType)
{
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rdi
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rcx
  unsigned int Flags; // edi
  Scaleform::GFx::ASStringNode *v18; // rcx
  unsigned int v20; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // r14
  Scaleform::GFx::ASStringNode *v22; // rsi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx
  const char *pData; // rax
  Scaleform::GFx::ASString *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::ASStringNode *v27; // rcx
  __int64 v28; // rcx
  char v29; // si
  __int64 v30; // r8
  __int64 v31; // rax
  Scaleform::GFx::AS3::ASVM *v32; // rcx
  unsigned int v33; // edi
  Scaleform::GFx::ASStringNode *v34; // rcx
  _DWORD *v35; // [rsp+8h] [rbp-79h]
  __int64 v36; // [rsp+10h] [rbp-71h]
  __int64 v37; // [rsp+18h] [rbp-69h]
  Scaleform::GFx::ASString ppath; // [rsp+20h] [rbp-61h] BYREF
  Scaleform::GFx::AS3::Value pval; // [rsp+28h] [rbp-59h] BYREF
  Scaleform::GFx::AS3::Value other; // [rsp+48h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Multiname v41; // [rsp+68h] [rbp-19h] BYREF
  Scaleform::GFx::ASString v42; // [rsp+98h] [rbp+17h] BYREF
  Scaleform::GFx::AS3::Value::V2U v43; // [rsp+A0h] [rbp+1Fh]
  __int64 v44; // [rsp+A8h] [rbp+27h]
  Scaleform::GFx::ASString result; // [rsp+E8h] [rbp+67h] BYREF

  v44 = -2i64;
  ppath.pNode = this->BuiltinsMgr.Builtins[0].pNode;
  ++ppath.pNode->RefCount;
  ppath.pNode = this->BuiltinsMgr.Builtins[0].pNode;
  ++ppath.pNode->RefCount;
  if ( Scaleform::GFx::AS3::MovieRoot::ExtractPathAndName(this, ppathToVar, &ppath, &ppath) )
  {
    pNode = ppath.pNode;
  }
  else
  {
    v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
           &this->BuiltinsMgr,
           &result,
           ppathToVar);
    pNode = v8->pNode;
    ++v8->pNode->RefCount;
    v10 = ppath.pNode;
    v11 = ppath.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    ppath.pNode = pNode;
    v12 = result.pNode;
    v11 = result.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            &this->BuiltinsMgr,
            &result,
            "root");
    v14 = v13->pNode;
    ++v13->pNode->RefCount;
    v15 = ppath.pNode;
    v11 = ppath.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    ppath.pNode = v14;
    v16 = result.pNode;
    v11 = result.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
  pval.Flags = 0;
  pval.Bonus.pWeakProxy = 0i64;
  if ( !Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &pval, ppath.pNode->pData) )
  {
    Flags = pval.Flags;
    if ( (pval.Flags & 0x1F) > 9 )
    {
      if ( (pval.Flags & 0x200) != 0 )
      {
        v11 = pval.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v11 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&pval.Bonus, 0, 24);
        pval.Flags = Flags & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
      }
    }
    v11 = pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v18 = ppath.pNode;
    v11 = ppath.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    return 0;
  }
  v20 = 10;
  other.Flags = 10;
  pWeakProxy = 0i64;
  other.Bonus.pWeakProxy = 0i64;
  v22 = pNode;
  other.value.VS._1.VStr = pNode;
  if ( pNode == &pNode->pManager->NullStringNode )
  {
    v22 = 0i64;
    other.value.VS._1.VStr = 0i64;
    other.value.VS._2 = v43;
    v20 = 12;
    other.Flags = 12;
  }
  else
  {
    ++pNode->RefCount;
  }
  pObject = this->pAVM.pObject->PublicNamespace.pObject;
  v41.Kind = MN_QName;
  v41.Obj.pObject = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  v41.Name.Flags = 0;
  v41.Name.Bonus.pWeakProxy = 0i64;
  if ( (v20 & 0x1F) - 12 <= 3
    && v22
    && (pData = v22[1].pData, *((_DWORD *)pData + 30) == 17)
    && (pData[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v41.Name, (Scaleform::GFx::ASString *)&v22[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v41.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v22[1].RefCount);
    v41.Kind &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v41.Name, &other);
    if ( (v41.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v41.Name, &result);
      if ( result.pNode->Size )
      {
        if ( *result.pNode->pData == 64 )
        {
          v41.Kind |= 8u;
          v25 = Scaleform::GFx::ASString::Substring(&result, &v42, 1, result.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v41.Name, v25);
          v26 = v42.pNode;
          v11 = v42.pNode->RefCount-- == 1;
          if ( v11 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v26);
        }
      }
      v27 = result.pNode;
      v11 = result.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
    }
    v20 = other.Flags;
    pWeakProxy = other.Bonus.pWeakProxy;
  }
  if ( (v20 & 0x1F) > 9 )
  {
    if ( (v20 & 0x200) != 0 )
    {
      v11 = pWeakProxy->RefCount-- == 1;
      if ( v11 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      memset(&other.Bonus, 0, 24);
      other.Flags = v20 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  pval.Flags = 0;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(this, value, &pval);
  v29 = *(_BYTE *)(*((__int64 (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))pval.value.VS._1.VStr->pData
                   + 3))(
                    pval.value.VS._1,
                    &result,
                    &v41,
                    &pval);
  if ( (!v29 && setType || setType == SV_Permanent) && pNode->Size )
  {
    result.pNode = (Scaleform::GFx::ASStringNode *)this->pMovieImpl->pHeap;
    v30 = (*((__int64 (__fastcall **)(__int64, __int64))result.pNode->pData + 10))(v28, 64i64);
    v42.pNode = (Scaleform::GFx::ASStringNode *)v30;
    if ( v30 )
    {
      *(_QWORD *)v30 = &Scaleform::GFx::MovieImpl::StickyVarNode::`vftable;
      *(_QWORD *)(v30 + 8) = pNode;
      ++pNode->RefCount;
      *(_QWORD *)(v30 + 16) = 0i64;
      *(_BYTE *)(v30 + 24) = setType == SV_Permanent;
      *(_QWORD *)v30 = &Scaleform::GFx::AS3::MovieRoot::StickyVarNode::`vftable;
      *(_DWORD *)(v30 + 32) = pval.Flags;
      *(_QWORD *)(v30 + 40) = v35;
      *(_QWORD *)(v30 + 48) = v36;
      *(_QWORD *)(v30 + 56) = v37;
      if ( (pval.Flags & 0x1F) > 9 )
      {
        if ( (pval.Flags & 0x200) != 0 )
        {
          ++*v35;
          goto LABEL_66;
        }
        if ( (pval.Flags & 0x1F) == 10 )
        {
          ++*(_DWORD *)(v36 + 24);
        }
        else if ( (pval.Flags & 0x1F) > 0xA )
        {
          if ( (pval.Flags & 0x1F) <= 0xF )
          {
            v31 = v36;
LABEL_61:
            if ( v31 )
            {
              ++*(_DWORD *)(v31 + 32);
              *(_DWORD *)(v31 + 32) &= 0x8FBFFFFF;
            }
            goto LABEL_66;
          }
          if ( (pval.Flags & 0x1F) <= 0x11 )
          {
            v31 = v37;
            goto LABEL_61;
          }
        }
      }
    }
    else
    {
      v30 = 0i64;
    }
LABEL_66:
    if ( v30 )
      Scaleform::GFx::MovieImpl::AddStickyVariableNode(
        this->pMovieImpl,
        &ppath,
        (Scaleform::GFx::MovieImpl::StickyVarNode *)v30);
  }
  v32 = this->pAVM.pObject;
  if ( v32->HandleException )
    Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v32);
  if ( (pval.Flags & 0x1F) > 9 )
  {
    if ( (pval.Flags & 0x200) != 0 )
    {
      v11 = (*v35)-- == 1;
      if ( v11 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      pval.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&v41);
  v33 = pval.Flags;
  if ( (pval.Flags & 0x1F) > 9 )
  {
    if ( (pval.Flags & 0x200) != 0 )
    {
      v11 = pval.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&pval.Bonus, 0, 24);
      pval.Flags = v33 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
    }
  }
  v11 = pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v34 = ppath.pNode;
  v11 = ppath.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v34);
  return v29;
}

// File Line: 1916
// RVA: 0x7F18F0
__int64 __fastcall Scaleform::GFx::AS3::MovieRoot::GetVariableArraySize(
        Scaleform::GFx::AS3::MovieRoot *this,
        const char *ppathToVar)
{
  const char *pData; // rax
  Scaleform::GFx::ASStringNode *pLower; // rdi
  unsigned int Flags; // ebx
  bool v5; // zf
  unsigned int v7; // ebx
  Scaleform::GFx::AS3::Value pval; // [rsp+28h] [rbp-30h] BYREF

  pval.Flags = 0;
  pval.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &pval, ppathToVar)
    && pval.value.VS._1.VStr
    && (pData = pval.value.VS._1.VStr[1].pData, *((_DWORD *)pData + 30) == 7)
    && (pData[112] & 0x20) == 0 )
  {
    pLower = pval.value.VS._1.VStr[1].pLower;
    Flags = pval.Flags;
    if ( (pval.Flags & 0x1F) > 9 )
    {
      if ( (pval.Flags & 0x200) != 0 )
      {
        v5 = pval.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v5 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&pval.Bonus, 0, 24);
        pval.Flags = Flags & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
      }
    }
    return (unsigned int)pLower;
  }
  else
  {
    v7 = pval.Flags;
    if ( (pval.Flags & 0x1F) > 9 )
    {
      if ( (pval.Flags & 0x200) != 0 )
      {
        v5 = pval.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v5 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&pval.Bonus, 0, 24);
        pval.Flags = v7 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
      }
    }
    return 0i64;
  }
}

// File Line: 1941
// RVA: 0x7F1330
char __fastcall Scaleform::GFx::AS3::MovieRoot::GetVariableArray(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Movie::SetArrayType type,
        const char *ppathToVar,
        unsigned int index,
        char *pdata,
        unsigned int count)
{
  unsigned int v6; // esi
  char ASVariableAtPath; // al
  unsigned int Flags; // r14d
  bool v11; // zf
  Scaleform::GFx::AS3::Value::V1U v12; // r13
  const char *v13; // rax
  Scaleform::GFx::MovieImpl::ReturnValueHolder *RetValHolder; // rax
  Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *p_Data; // rbx
  Scaleform::GFx::AS3::Impl::SparseArray *v16; // r13
  unsigned __int64 Length; // r15
  Scaleform::GFx::Movie::SetArrayType v18; // kr00_4
  Scaleform::GFx::AS3::Value::Extra v19; // r12
  float *v20; // rdi
  unsigned int v21; // esi
  unsigned int v22; // eax
  int *v23; // rbx
  unsigned int v24; // r14d
  Scaleform::GFx::AS3::Value *v25; // rax
  unsigned int v26; // ebx
  Scaleform::GFx::AS3::Value *v27; // rax
  unsigned int v28; // edi
  unsigned int v29; // esi
  Scaleform::GFx::AS3::Value::V1U *v30; // rbx
  Scaleform::GFx::AS3::Value *v31; // rax
  unsigned int v32; // edi
  _QWORD *v33; // rbx
  Scaleform::GFx::AS3::Value *v34; // rsi
  unsigned int pWeakProxy; // eax
  unsigned int v36; // ebx
  __int64 v37; // r14
  Scaleform::GFx::AS3::Value *v38; // rax
  Scaleform::GFx::ASStringNode *pNode; // r15
  __int64 v40; // rcx
  Scaleform::GFx::ASStringNode *v41; // rax
  Scaleform::GFx::ASStringNode *v42; // rcx
  Scaleform::GFx::ASStringNode *v43; // rcx
  int v44; // r12d
  unsigned int v45; // ecx
  unsigned __int64 v46; // rdx
  unsigned int v47; // ebx
  __int64 v48; // rdi
  Scaleform::GFx::ASStringNode *v49; // r14
  Scaleform::GFx::AS3::Value *v50; // rax
  __int64 v51; // rax
  Scaleform::GFx::ASStringNode *v52; // r12
  Scaleform::GFx::ASStringNode *v53; // rcx
  unsigned int v54; // eax
  Scaleform::GFx::ASStringNode *v55; // rcx
  unsigned int v56; // ebx
  __int64 v57; // rdi
  unsigned int v58; // eax
  Scaleform::MemoryHeapVtbl *vfptr; // rax
  __int64 v60; // rax
  _WORD *v61; // rbx
  __int64 v62; // rdi
  __int64 v63; // rsi
  Scaleform::GFx::ASStringNode *v64; // r14
  _WORD *v65; // r15
  unsigned int Char_Advance0; // eax
  Scaleform::GFx::ASString v68; // [rsp+20h] [rbp-60h] BYREF
  int v69; // [rsp+28h] [rbp-58h]
  Scaleform::GFx::AS3::Value pval; // [rsp+30h] [rbp-50h] BYREF
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp-30h] BYREF
  __int64 v72; // [rsp+58h] [rbp-28h]
  unsigned int v73; // [rsp+60h] [rbp-20h]
  int v74; // [rsp+64h] [rbp-1Ch]
  const char *v75; // [rsp+68h] [rbp-18h]
  __int64 v76; // [rsp+70h] [rbp-10h]

  v76 = -2i64;
  v6 = index;
  pval.Flags = 0;
  pval.Bonus.pWeakProxy = 0i64;
  ASVariableAtPath = Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &pval, ppathToVar);
  Flags = pval.Flags;
  if ( !ASVariableAtPath )
    goto LABEL_99;
  v74 = pval.Flags & 0x1F;
  if ( (unsigned int)(v74 - 12) > 3 )
  {
    if ( (pval.Flags & 0x1F) <= 9 )
      return 0;
    if ( (pval.Flags & 0x200) != 0 )
    {
      v11 = pval.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&pval.Bonus, 0, 24);
        pval.Flags = Flags & 0xFFFFFDE0;
        return 0;
      }
LABEL_103:
      memset(&pval.Bonus, 0, 24);
      pval.Flags = Flags & 0xFFFFFDE0;
      return 0;
    }
    goto LABEL_104;
  }
  v12 = pval.value.VS._1;
  if ( !pval.value.VS._1.VStr
    || (v13 = pval.value.VS._1.VStr[1].pData, *((_DWORD *)v13 + 30) != 7)
    || (v13[112] & 0x20) != 0 )
  {
LABEL_99:
    if ( (pval.Flags & 0x1F) <= 9 )
      return 0;
    if ( (pval.Flags & 0x200) != 0 )
    {
      v11 = pval.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      goto LABEL_103;
    }
LABEL_104:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
    return 0;
  }
  RetValHolder = Scaleform::GFx::MovieImpl::GetRetValHolder(this->pMovieImpl);
  v72 = (__int64)RetValHolder;
  RetValHolder->StringArrayPos = 0;
  p_Data = &RetValHolder->StringArray.Data;
  result.pNode = (Scaleform::GFx::ASStringNode *)&RetValHolder->StringArray;
  Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
    &RetValHolder->StringArray.Data,
    1ui64);
  v16 = (Scaleform::GFx::AS3::Impl::SparseArray *)&v12.VStr[1].16;
  Length = v16->Length;
  v18 = type;
  v19.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)count;
  v20 = (float *)pdata;
  switch ( v18 )
  {
    case SA_Int:
      v21 = 0;
      v22 = count;
      if ( (unsigned int)Length < count )
        v22 = v16->Length;
      if ( v22 )
      {
        v23 = (int *)pdata;
        v24 = v22;
        do
        {
          v25 = Scaleform::GFx::AS3::Impl::SparseArray::At(v16, v21 + index);
          if ( (v25->Flags & 0x1F) != 0 )
            *v23 = v25->value.VS._1.VInt;
          else
            *v23 = 0;
          ++v21;
          ++v23;
        }
        while ( v21 < v24 );
        v20 = (float *)pdata;
        Flags = pval.Flags;
      }
      v6 = index;
      goto $LN37_18;
    case SA_Double:
      v19.pWeakProxy = 0i64;
      v28 = 0;
      v29 = count;
      if ( (unsigned int)Length < count )
        v29 = v16->Length;
      if ( v29 )
      {
        v30 = (Scaleform::GFx::AS3::Value::V1U *)pdata;
        do
        {
          v31 = Scaleform::GFx::AS3::Impl::SparseArray::At(v16, v28 + index);
          if ( (v31->Flags & 0x1F) != 0 )
            *v30 = v31->value.VS._1;
          else
            v30->VStr = 0i64;
          ++v28;
          ++v30;
        }
        while ( v28 < v29 );
        Flags = pval.Flags;
      }
      break;
    case SA_Float:
$LN37_18:
      v26 = 0;
      if ( (unsigned int)Length < count )
        LODWORD(v19.pWeakProxy) = Length;
      if ( LODWORD(v19.pWeakProxy) )
      {
        do
        {
          v27 = Scaleform::GFx::AS3::Impl::SparseArray::At(v16, v26 + v6);
          if ( (v27->Flags & 0x1F) != 0 )
            *v20 = v27->value.VNumber;
          else
            *v20 = 0.0;
          ++v26;
          ++v20;
        }
        while ( v26 < LODWORD(v19.pWeakProxy) );
      }
      goto LABEL_91;
    case SA_String:
      if ( (unsigned int)Length < count )
        LODWORD(v19.pWeakProxy) = v16->Length;
      pWeakProxy = (unsigned int)v19.pWeakProxy;
      if ( !LODWORD(v19.pWeakProxy) )
        pWeakProxy = 1;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        p_Data,
        pWeakProxy);
      v36 = 0;
      if ( LODWORD(v19.pWeakProxy) )
      {
        v37 = v72;
        do
        {
          v38 = Scaleform::GFx::AS3::Impl::SparseArray::At(v16, v36 + v6);
          if ( (v38->Flags & 0x1F) != 0 )
          {
            Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v38, &result);
            pNode = result.pNode;
            *(_QWORD *)v20 = result.pNode->pData;
            v40 = *(unsigned int *)(v37 + 48);
            v72 = v40;
            *(_DWORD *)(v37 + 48) = v40 + 1;
            v68.pNode = *(Scaleform::GFx::ASStringNode **)(v37 + 16);
            v41 = v68.pNode;
            ++pNode->RefCount;
            v42 = (Scaleform::GFx::ASStringNode *)*((_QWORD *)&v41->pData + v40);
            v11 = v42->RefCount-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v42);
            *((_QWORD *)&v68.pNode->pData + v72) = pNode;
            v43 = result.pNode;
            v11 = result.pNode->RefCount-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v43);
          }
          else
          {
            *(_QWORD *)v20 = 0i64;
          }
          ++v36;
          v20 += 2;
        }
        while ( v36 < LODWORD(v19.pWeakProxy) );
        Flags = pval.Flags;
      }
      goto LABEL_91;
    case SA_StringW:
      v44 = 0;
      v69 = 0;
      v45 = count;
      if ( (unsigned int)Length < count )
        v45 = Length;
      v73 = v45;
      v46 = v45;
      if ( !v45 )
        v46 = 1i64;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        p_Data,
        v46);
      v47 = 0;
      if ( (_DWORD)Length )
      {
        v48 = 0i64;
        v49 = result.pNode;
        do
        {
          v50 = Scaleform::GFx::AS3::Impl::SparseArray::At(v16, v47 + v6);
          if ( (v50->Flags & 0x1F) != 0 )
          {
            Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v50, &v68);
            v75 = v49->pData;
            v51 = (__int64)v75;
            v52 = v68.pNode;
            ++v68.pNode->RefCount;
            v53 = *(Scaleform::GFx::ASStringNode **)(v48 + v51);
            v11 = v53->RefCount-- == 1;
            if ( v11 )
            {
              Scaleform::GFx::ASStringNode::ReleaseNode(v53);
              v51 = (__int64)v75;
            }
            *(_QWORD *)(v48 + v51) = v52;
            v54 = Scaleform::GFx::ASConstString::GetLength(&v68);
            v44 = v54 + v69 + 1;
            v69 = v44;
            v55 = v68.pNode;
            v11 = v68.pNode->RefCount-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v55);
          }
          ++v47;
          v48 += 8i64;
        }
        while ( v47 < (unsigned int)Length );
        Flags = pval.Flags;
      }
      v56 = (2 * v44 + 4095) & 0xFFFFF000;
      v57 = v72;
      v58 = *(_DWORD *)(v72 + 8);
      if ( v58 < v56 || v58 > v56 && v58 - v56 > 0x1000 )
      {
        vfptr = Scaleform::Memory::pGlobalHeap->vfptr;
        if ( *(_QWORD *)v72 )
          v60 = (__int64)vfptr->Realloc(Scaleform::Memory::pGlobalHeap, *(void **)v72, v56);
        else
          v60 = (__int64)vfptr->Alloc(Scaleform::Memory::pGlobalHeap, v56, 0i64);
        *(_QWORD *)v57 = v60;
        *(_DWORD *)(v57 + 8) = v56;
      }
      v61 = *(_WORD **)v57;
      if ( v73 )
      {
        v62 = 0i64;
        v63 = v73;
        v64 = result.pNode;
        do
        {
          v68.pNode = **(Scaleform::GFx::ASStringNode ***)&v64->pData[v62];
          v65 = v61;
          while ( 1 )
          {
            Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v68);
            if ( !Char_Advance0 )
              break;
            *v61++ = Char_Advance0;
          }
          --v68.pNode;
          *v61++ = 0;
          *(_QWORD *)&pdata[v62] = v65;
          v62 += 8i64;
          --v63;
        }
        while ( v63 );
        Flags = pval.Flags;
      }
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        (Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)result.pNode,
        1ui64);
      goto LABEL_91;
    case SA_Value:
      v32 = 0;
      if ( (unsigned int)Length < count )
        LODWORD(v19.pWeakProxy) = v16->Length;
      if ( LODWORD(v19.pWeakProxy) )
      {
        v33 = pdata + 16;
        do
        {
          v34 = Scaleform::GFx::AS3::Impl::SparseArray::At(v16, v32 + v6);
          if ( (v33[1] & 0x40) != 0 )
          {
            (*(void (__fastcall **)(_QWORD, _QWORD *, _QWORD))(*(_QWORD *)*v33 + 16i64))(*v33, v33 - 2, v33[2]);
            *v33 = 0i64;
          }
          *((_DWORD *)v33 + 2) = 0;
          if ( (v34->Flags & 0x1F) != 0 )
            Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, v34, (Scaleform::GFx::Value *)(v33 - 2));
          else
            *((_DWORD *)v33 + 2) = 0;
          ++v32;
          v33 += 6;
          v6 = index;
        }
        while ( v32 < LODWORD(v19.pWeakProxy) );
        Flags = pval.Flags;
      }
LABEL_91:
      v19.pWeakProxy = 0i64;
      break;
    default:
      break;
  }
  if ( v74 > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      v11 = pval.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      pval.Bonus = v19;
      pval.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v19.pWeakProxy;
      pval.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v19.pWeakProxy;
      pval.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
    }
  }
  return 1;
}

// File Line: 2081
// RVA: 0x81FF70
__int64 __fastcall Scaleform::GFx::AS3::MovieRoot::SetVariableArraySize(
        Scaleform::GFx::AS3::MovieRoot *this,
        const char *ppathToVar,
        unsigned int count,
        unsigned int setType)
{
  unsigned __int64 v5; // rbx
  char ASVariableAtPath; // al
  unsigned int Flags; // edi
  const char *pData; // rax
  unsigned __int8 v11; // si
  unsigned int v12; // ebx
  bool v13; // zf
  Scaleform::GFx::AS3::Value value; // [rsp+8h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::Value pval; // [rsp+28h] [rbp-29h] BYREF
  Scaleform::GFx::Value pdestVal; // [rsp+48h] [rbp-9h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> result; // [rsp+78h] [rbp+27h] BYREF
  Scaleform::GFx::AS3::Value::V2U v19; // [rsp+80h] [rbp+2Fh]
  __int64 v20; // [rsp+88h] [rbp+37h]

  v20 = -2i64;
  v5 = count;
  pval.Flags = 0;
  pval.Bonus.pWeakProxy = 0i64;
  ASVariableAtPath = Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &pval, ppathToVar);
  Flags = pval.Flags;
  if ( ASVariableAtPath
    && (pval.Flags & 0x1F) - 12 <= 3
    && pval.value.VS._1.VStr
    && (pData = pval.value.VS._1.VStr[1].pData, *((_DWORD *)pData + 30) == 7)
    && (pData[112] & 0x20) == 0 )
  {
    if ( (_DWORD)v5 != LODWORD(pval.value.VS._1.VStr[1].pLower) )
      Scaleform::GFx::AS3::Impl::SparseArray::Resize(
        (Scaleform::GFx::AS3::Impl::SparseArray *)&pval.value.VS._1.VStr[1].16,
        (unsigned int)v5);
    v11 = 1;
  }
  else
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
      &result,
      (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pAVM.pObject->TraitsArray.pObject->ITraits.pObject);
    Scaleform::GFx::AS3::Impl::SparseArray::Resize(&result.pV->SA, v5);
    value.value.VS._2 = v19;
    pdestVal.pObjectInterface = 0i64;
    pdestVal.Type = VT_Undefined;
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, &value, &pdestVal);
    v11 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD))this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[48].__vecDelDtor)(
            this,
            ppathToVar,
            &pdestVal,
            setType,
            (Scaleform::GFx::AS3::Value::V2U)value.value.VS._2.VObj);
    if ( (pdestVal.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pdestVal.pObjectInterface->vfptr->gap8[8])(
        pdestVal.pObjectInterface,
        &pdestVal,
        pdestVal.mValue);
      pdestVal.pObjectInterface = 0i64;
    }
    pdestVal.Type = VT_Undefined;
    v12 = value.Flags;
    if ( (value.Flags & 0x1F) > 9 )
    {
      if ( (value.Flags & 0x200) != 0 )
      {
        v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&value.Bonus, 0, 24);
        value.Flags = v12 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
      }
    }
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      v13 = pval.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&pval.Bonus, 0, 24);
      pval.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
    }
  }
  return v11;
}

// File Line: 2112
// RVA: 0x81F560
char __fastcall Scaleform::GFx::AS3::MovieRoot::SetVariableArray(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Movie::SetArrayType type,
        const char *ppathToVar,
        unsigned int index,
        Scaleform::GFx::AS3::Value::V1U *pdata,
        unsigned int count,
        Scaleform::GFx::Movie::SetVarType setType)
{
  __int64 v10; // rsi
  char ASVariableAtPath; // al
  Scaleform::GFx::ASStringNode *v12; // rbx
  int v13; // r13d
  __int64 v14; // rax
  Scaleform::GFx::AS3::Impl::SparseArray *v15; // r15
  unsigned int v16; // edi
  int *v17; // rsi
  int v18; // eax
  bool v19; // zf
  unsigned int v20; // edi
  float *v21; // rsi
  long double v22; // xmm0_8
  unsigned int v23; // edi
  Scaleform::GFx::AS3::Value::V1U *v24; // rsi
  Scaleform::GFx::AS3::Value::V1U v25; // xmm0_8
  unsigned int v26; // edi
  Scaleform::GFx::Value *v27; // rsi
  unsigned int v28; // edi
  const char **v29; // rsi
  Scaleform::GFx::AS3::Value::V2U v30; // r15
  Scaleform::GFx::AS3::Impl::SparseArray *v31; // rbx
  Scaleform::GFx::AS3::Value::V1U *String; // rax
  Scaleform::GFx::AS3::Value::V1U v33; // rdx
  Scaleform::GFx::ASStringNode *v34; // rcx
  unsigned int v35; // edi
  const wchar_t **v36; // rsi
  Scaleform::GFx::AS3::Value::V2U v37; // r15
  Scaleform::GFx::AS3::Impl::SparseArray *v38; // r13
  Scaleform::GFx::AS3::Value::V1U *v39; // rax
  Scaleform::GFx::AS3::Value::V1U v40; // rdx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  char v42; // si
  int v43; // edi
  Scaleform::GFx::ASStringNode *v44; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v45; // rcx
  unsigned int RefCount; // eax
  unsigned int v47; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v48; // rcx
  int v49; // eax
  unsigned int Size; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v52; // rcx
  int v53; // eax
  int v54; // eax
  _QWORD pval[5]; // [rsp+20h] [rbp-E0h] BYREF
  Scaleform::GFx::ASString v56; // [rsp+48h] [rbp-B8h] BYREF
  __m256i v57; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v58; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::AS3::Value v59; // [rsp+78h] [rbp-88h] BYREF
  Scaleform::GFx::AS3::Value v60; // [rsp+98h] [rbp-68h] BYREF
  Scaleform::GFx::Value pdestVal; // [rsp+B8h] [rbp-48h] BYREF
  Scaleform::GFx::AS3::Value v; // [rsp+E8h] [rbp-18h] BYREF
  Scaleform::GFx::AS3::Value v63; // [rsp+108h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Value v64; // [rsp+128h] [rbp+28h] BYREF
  __int64 v65; // [rsp+148h] [rbp+48h]
  char v67; // [rsp+1A8h] [rbp+A8h]

  v65 = -2i64;
  v10 = 0i64;
  pval[4] = 0i64;
  v58 = 0i64;
  LODWORD(pval[0]) = 0;
  pval[1] = 0i64;
  ASVariableAtPath = Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(
                       this,
                       (Scaleform::GFx::AS3::Value *)pval,
                       ppathToVar);
  v12 = (Scaleform::GFx::ASStringNode *)pval[2];
  v13 = pval[0];
  if ( ASVariableAtPath )
  {
    if ( (pval[0] & 0x1F) - 12 <= 3 )
    {
      if ( pval[2] )
      {
        v14 = *(_QWORD *)(pval[2] + 40i64);
        if ( *(_DWORD *)(v14 + 120) == 7 && (*(_BYTE *)(v14 + 112) & 0x20) == 0 )
        {
          *(_DWORD *)(pval[2] + 32i64) = (*(_DWORD *)(pval[2] + 32i64) + 1) & 0x8FBFFFFF;
          v10 = (__int64)v12;
          pval[4] = v12;
          v58 = (__int64)v12;
        }
      }
    }
  }
  v67 = 1;
  if ( !v10 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)&v57.m256i_u64[3],
      (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pAVM.pObject->TraitsArray.pObject->ITraits.pObject);
    if ( v57.m256i_i64[3] )
      v10 = v57.m256i_i64[3];
    pval[4] = v10;
    v58 = v10;
    v67 = 0;
  }
  v15 = (Scaleform::GFx::AS3::Impl::SparseArray *)(v10 + 56);
  v57.m256i_i64[3] = v10 + 56;
  if ( index + count > *(_DWORD *)(v10 + 56) )
    Scaleform::GFx::AS3::Impl::SparseArray::Resize((Scaleform::GFx::AS3::Impl::SparseArray *)(v10 + 56), index + count);
  switch ( type )
  {
    case SA_Int:
      v16 = 0;
      if ( count )
      {
        v17 = (int *)pdata;
        do
        {
          v18 = *v17;
          v.Flags = 2;
          v.Bonus.pWeakProxy = 0i64;
          v.value.VS._1.VInt = v18;
          Scaleform::GFx::AS3::Impl::SparseArray::Set(v15, v16 + index, &v);
          if ( (v.Flags & 0x1F) > 9 )
          {
            if ( (v.Flags & 0x200) != 0 )
            {
              v19 = v.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v.Bonus, 0, 24);
              v.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
            }
          }
          ++v16;
          ++v17;
        }
        while ( v16 < count );
        v10 = pval[4];
      }
      break;
    case SA_Double:
      v23 = 0;
      if ( count )
      {
        v24 = pdata;
        do
        {
          v25 = *v24;
          v63.Flags = 4;
          v63.Bonus.pWeakProxy = 0i64;
          v63.value.VS._1 = v25;
          Scaleform::GFx::AS3::Impl::SparseArray::Set(v15, v23 + index, &v63);
          if ( (v63.Flags & 0x1F) > 9 )
          {
            if ( (v63.Flags & 0x200) != 0 )
            {
              v19 = v63.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v63.Bonus, 0, 24);
              v63.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v63);
            }
          }
          ++v23;
          ++v24;
        }
        while ( v23 < count );
        v10 = pval[4];
      }
      break;
    case SA_Float:
      v20 = 0;
      if ( count )
      {
        v21 = (float *)pdata;
        do
        {
          v22 = *v21;
          v64.Flags = 4;
          v64.Bonus.pWeakProxy = 0i64;
          v64.value.VNumber = v22;
          Scaleform::GFx::AS3::Impl::SparseArray::Set(v15, v20 + index, &v64);
          if ( (v64.Flags & 0x1F) > 9 )
          {
            if ( (v64.Flags & 0x200) != 0 )
            {
              v19 = v64.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v64.Bonus, 0, 24);
              v64.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v64);
            }
          }
          ++v20;
          ++v21;
        }
        while ( v20 < count );
        v10 = pval[4];
      }
      break;
    case SA_String:
      v28 = 0;
      if ( count )
      {
        v29 = (const char **)pdata;
        v30.VObj = (Scaleform::GFx::AS3::Object *)v57.m256i_i64[0];
        v31 = (Scaleform::GFx::AS3::Impl::SparseArray *)v57.m256i_i64[3];
        do
        {
          String = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                                        &this->BuiltinsMgr,
                                                        (Scaleform::GFx::ASString *)&v57.m256i_u64[3],
                                                        *v29);
          v59.Flags = 10;
          v59.Bonus.pWeakProxy = 0i64;
          v33 = *String;
          v59.value.VS._1 = *String;
          if ( String->VStr == &String->VStr->pManager->NullStringNode )
          {
            v59.value.VS._1.VStr = 0i64;
            v59.value.VS._2 = v30;
            v59.Flags = 12;
          }
          else
          {
            ++v33.VStr->RefCount;
          }
          Scaleform::GFx::AS3::Impl::SparseArray::Set(v31, v28 + index, &v59);
          if ( (v59.Flags & 0x1F) > 9 )
          {
            if ( (v59.Flags & 0x200) != 0 )
            {
              v19 = v59.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v59.Bonus, 0, 24);
              v59.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v59);
            }
          }
          v34 = (Scaleform::GFx::ASStringNode *)v57.m256i_i64[3];
          v19 = (*(_DWORD *)(v57.m256i_i64[3] + 24))-- == 1;
          if ( v19 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v34);
          ++v28;
          ++v29;
        }
        while ( v28 < count );
        goto LABEL_83;
      }
      break;
    case SA_StringW:
      v35 = 0;
      if ( count )
      {
        v36 = (const wchar_t **)pdata;
        v37.VObj = (Scaleform::GFx::AS3::Object *)v57.m256i_i64[0];
        v38 = (Scaleform::GFx::AS3::Impl::SparseArray *)v57.m256i_i64[3];
        do
        {
          v39 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                                     &this->BuiltinsMgr,
                                                     &v56,
                                                     *v36,
                                                     -1i64);
          v60.Flags = 10;
          v60.Bonus.pWeakProxy = 0i64;
          v40 = *v39;
          v60.value.VS._1 = *v39;
          if ( v39->VStr == &v39->VStr->pManager->NullStringNode )
          {
            v60.value.VS._1.VStr = 0i64;
            v60.value.VS._2 = v37;
            v60.Flags = 12;
          }
          else
          {
            ++v40.VStr->RefCount;
          }
          Scaleform::GFx::AS3::Impl::SparseArray::Set(v38, v35 + index, &v60);
          if ( (v60.Flags & 0x1F) > 9 )
          {
            if ( (v60.Flags & 0x200) != 0 )
            {
              v19 = v60.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v60.Bonus, 0, 24);
              v60.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v60);
            }
          }
          pNode = v56.pNode;
          v19 = v56.pNode->RefCount-- == 1;
          if ( v19 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          ++v35;
          ++v36;
        }
        while ( v35 < count );
LABEL_83:
        v10 = pval[4];
        v13 = pval[0];
        v12 = (Scaleform::GFx::ASStringNode *)pval[2];
      }
      break;
    case SA_Value:
      v26 = 0;
      if ( count )
      {
        v27 = (Scaleform::GFx::Value *)pdata;
        do
        {
          LODWORD(pdestVal.pPrev) = 0;
          pdestVal.pNext = 0i64;
          Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(this, v27, (Scaleform::GFx::AS3::Value *)&pdestVal);
          Scaleform::GFx::AS3::Impl::SparseArray::Set(v15, v26 + index, (Scaleform::GFx::AS3::Value *)&pdestVal);
          if ( (unsigned __int64)((__int64)pdestVal.pPrev & 0x1F) > 9 )
          {
            if ( ((__int64)pdestVal.pPrev & 0x200) != 0 )
            {
              v19 = LODWORD(pdestVal.pNext->Scaleform::ListNode<Scaleform::GFx::Value>::$41EDDC8CC4664C9FE26D4D23F9ACAEE4::pPrev)-- == 1;
              if ( v19 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&pdestVal.8, 0, 24);
              LODWORD(pdestVal.pPrev) &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&pdestVal);
            }
          }
          ++v26;
          ++v27;
        }
        while ( v26 < count );
        v13 = pval[0];
        v10 = pval[4];
      }
      break;
    default:
      break;
  }
  if ( v67 )
  {
    if ( (v13 & 0x1Fu) > 9 )
    {
      if ( (v13 & 0x200) != 0 )
      {
        v19 = (*(_DWORD *)pval[1])-- == 1;
        if ( v19 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&pval[1], 0, 24);
        LODWORD(pval[0]) = v13 & 0xFFFFFDE0;
      }
      else
      {
        switch ( v13 & 0x1F )
        {
          case 0xA:
            v19 = v12->RefCount-- == 1;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v12);
            break;
          case 0xB:
          case 0xC:
          case 0xD:
          case 0xE:
          case 0xF:
            if ( (pval[2] & 1) != 0 )
            {
              pval[2] = (char *)v12 - 1;
            }
            else if ( v12 )
            {
              Size = v12->Size;
              if ( (Size & 0x3FFFFF) != 0 )
              {
                v12->Size = Size - 1;
                v52 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v12;
                goto LABEL_142;
              }
            }
            break;
          case 0x10:
          case 0x11:
            if ( (pval[3] & 1) != 0 )
            {
              --pval[3];
            }
            else
            {
              v52 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)pval[3];
              if ( pval[3] )
              {
                v53 = *(_DWORD *)(pval[3] + 32i64);
                if ( (v53 & 0x3FFFFF) != 0 )
                {
                  *(_DWORD *)(pval[3] + 32i64) = v53 - 1;
LABEL_142:
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v52);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    if ( (v10 & 1) != 0 )
    {
      v58 = v10 - 1;
    }
    else
    {
      v54 = *(_DWORD *)(v10 + 32);
      if ( (v54 & 0x3FFFFF) != 0 )
      {
        *(_DWORD *)(v10 + 32) = v54 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v10);
      }
    }
    return 1;
  }
  else
  {
    v57.m256i_i64[0] = 0i64;
    LODWORD(v56.pNode) = 12;
    *(_OWORD *)&v57.m256i_u64[1] = (unsigned __int64)v10;
    v58 = 0i64;
    pdestVal.pObjectInterface = 0i64;
    pdestVal.Type = VT_Undefined;
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, (Scaleform::GFx::AS3::Value *)&v56, &pdestVal);
    v42 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, const char *, Scaleform::GFx::Value *, _QWORD))this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[48].__vecDelDtor)(
            this,
            ppathToVar,
            &pdestVal,
            (unsigned int)setType);
    if ( (pdestVal.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pdestVal.pObjectInterface->vfptr->gap8[8])(
        pdestVal.pObjectInterface,
        &pdestVal,
        pdestVal.mValue);
      pdestVal.pObjectInterface = 0i64;
    }
    pdestVal.Type = VT_Undefined;
    v43 = *(_DWORD *)((char *)&v56.pNode + 2);
    if ( (BYTE2(v56.pNode) & 0x1Fu) > 9 )
    {
      if ( (WORD1(v56.pNode) & 0x200) != 0 )
      {
        v19 = (**(_DWORD **)((char *)v57.m256i_i64 + 2))-- == 1;
        if ( v19 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v57.m256i_i16[1], 0, 24);
        *(_DWORD *)((char *)&v56.pNode + 2) = v43 & 0xFFFFFDE0;
      }
      else
      {
        switch ( BYTE2(v56.pNode) & 0x1F )
        {
          case 0xA:
            v44 = *(Scaleform::GFx::ASStringNode **)((char *)&v57.m256i_i64[1] + 2);
            v19 = (*(_DWORD *)(*(__int64 *)((char *)&v57.m256i_i64[1] + 2) + 24))-- == 1;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v44);
            break;
          case 0xB:
          case 0xC:
          case 0xD:
          case 0xE:
          case 0xF:
            if ( (v57.m256i_i8[10] & 1) == 0 )
            {
              v45 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)((char *)&v57.m256i_i64[1] + 2);
              goto LABEL_98;
            }
            --*(__int64 *)((char *)&v57.m256i_i64[1] + 2);
            break;
          case 0x10:
          case 0x11:
            if ( (v57.m256i_i8[18] & 1) != 0 )
            {
              --*(__int64 *)((char *)&v57.m256i_i64[2] + 2);
            }
            else
            {
              v45 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)((char *)&v57.m256i_i64[2] + 2);
LABEL_98:
              if ( v45 )
              {
                RefCount = v45->RefCount;
                if ( (RefCount & 0x3FFFFF) != 0 )
                {
                  v45->RefCount = RefCount - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v45);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    if ( (v13 & 0x1Fu) > 9 )
    {
      if ( (v13 & 0x200) != 0 )
      {
        v19 = (**(_DWORD **)((char *)&pval[1] + 2))-- == 1;
        if ( v19 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset((char *)&pval[1] + 2, 0, 24);
        *(_DWORD *)((char *)pval + 2) = v13 & 0xFFFFFDE0;
      }
      else
      {
        switch ( v13 & 0x1F )
        {
          case 0xA:
            v19 = v12->RefCount-- == 1;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v12);
            break;
          case 0xB:
          case 0xC:
          case 0xD:
          case 0xE:
          case 0xF:
            if ( (pval[2] & 0x10000i64) != 0 )
            {
              *(_QWORD *)((char *)&pval[2] + 2) = (char *)v12 - 1;
            }
            else if ( v12 )
            {
              v47 = v12->Size;
              if ( (v47 & 0x3FFFFF) != 0 )
              {
                v12->Size = v47 - 1;
                v48 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v12;
                goto LABEL_122;
              }
            }
            break;
          case 0x10:
          case 0x11:
            if ( (pval[3] & 0x10000i64) != 0 )
            {
              --*(_QWORD *)((char *)&pval[3] + 2);
            }
            else
            {
              v48 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)((char *)&pval[3] + 2);
              if ( *(_QWORD *)((char *)&pval[3] + 2) )
              {
                v49 = *(_DWORD *)(*(_QWORD *)((char *)&pval[3] + 2) + 32i64);
                if ( (v49 & 0x3FFFFF) != 0 )
                {
                  *(_DWORD *)(*(_QWORD *)((char *)&pval[3] + 2) + 32i64) = v49 - 1;
LABEL_122:
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v48);
                }
              }
            }
            break;
          default:
            return v42;
        }
      }
    }
    return v42;
  }
} }
            break;
          default:
            return v42;
        }
      }
    }
    return v42;
  }
}

// File Line: 2211
// RVA: 0x7F8160
__int64 __fastcall Scaleform::GFx::AS3::MovieRoot::IsAvailable(
        Scaleform::GFx::AS3::MovieRoot *this,
        const char *ppathToVar)
{
  unsigned __int8 ASVariableAtPath; // di
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::Value pval; // [rsp+28h] [rbp-30h] BYREF

  pval.Flags = 0;
  pval.Bonus.pWeakProxy = 0i64;
  ASVariableAtPath = Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &pval, ppathToVar);
  Flags = pval.Flags;
  if ( (pval.Flags & 0x1F) > 9 )
  {
    if ( (pval.Flags & 0x200) != 0 )
    {
      if ( pval.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&pval.Bonus, 0, 24);
      pval.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
    }
  }
  return ASVariableAtPath;
}

// File Line: 2222
// RVA: 0x7F7290
_BOOL8 __fastcall Scaleform::GFx::AS3::MovieRoot::Invoke(
        Scaleform::GFx::AS3::MovieRoot *this,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        Scaleform::GFx::Value *pargs)
{
  Scaleform::GFx::AS3::Value *v8; // rax
  Scaleform::GFx::AS3::Value::Extra v9; // rbx
  __int64 v10; // rsi
  Scaleform::GFx::AS3::Value *pWeakProxy; // r8
  Scaleform::GFx::AS3::Value *v12; // rbx
  Scaleform::GFx::AS3::Value::Extra v13; // rdi
  Scaleform::GFx::AS3::Value *v14; // rsi
  bool v15; // r15
  unsigned int Flags; // ebx
  bool v17; // zf
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::ASVM *pObject; // rcx
  Scaleform::GFx::AS3::Value *v22; // rbx
  Scaleform::GFx::AS3::WeakProxy *v23; // rdx
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v25; // rcx
  unsigned int Size; // eax
  unsigned int v27; // edx
  Scaleform::GFx::AS3::Value pval; // [rsp+40h] [rbp-98h] BYREF
  Scaleform::GFx::AS3::Value result; // [rsp+60h] [rbp-78h] BYREF
  Scaleform::GFx::AS3::Value *argv; // [rsp+2D8h] [rbp+200h]
  void *argc; // [rsp+2F8h] [rbp+220h]

  *(_QWORD *)&result.Flags = -2i64;
  if ( (unsigned int)argc <= 0xA )
    v8 = (Scaleform::GFx::AS3::Value *)&result.value.VS._2;
  else
    v8 = (Scaleform::GFx::AS3::Value *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         32i64 * (unsigned int)argc,
                                         0i64);
  argv = v8;
  if ( (_DWORD)argc )
  {
    v9.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v8;
    v10 = (unsigned int)argc;
    do
    {
      result.Bonus = v9;
      pval.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v9.pWeakProxy;
      if ( v9.pWeakProxy )
      {
        v9.pWeakProxy->RefCount = 0;
        v9.pWeakProxy->pObject = 0i64;
        pWeakProxy = (Scaleform::GFx::AS3::Value *)v9.pWeakProxy;
      }
      else
      {
        pWeakProxy = 0i64;
      }
      Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(this, pargs++, pWeakProxy);
      v9.pWeakProxy += 2;
      --v10;
    }
    while ( v10 );
  }
  result.Flags = 0;
  result.Bonus.pWeakProxy = 0i64;
  if ( this->pInvokeAliases )
  {
    v12 = Scaleform::GFx::AS3::MovieRoot::ResolveInvokeAlias(this, pmethodName);
    if ( v12 )
    {
      if ( (_S11_12 & 1) != 0 )
      {
        v13.pWeakProxy = 0i64;
      }
      else
      {
        _S11_12 |= 1u;
        v13.pWeakProxy = 0i64;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      v14 = argv;
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->pAVM.pObject, v12, &v, &result, (unsigned int)argc, argv, 0);
LABEL_40:
      pObject = this->pAVM.pObject;
      v15 = !pObject->HandleException;
      if ( pObject->HandleException )
        Scaleform::GFx::AS3::VM::OutputAndIgnoreException(pObject);
      if ( v15 && presult )
        Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, &result, presult);
      goto LABEL_45;
    }
  }
  pval.Flags = 0;
  pval.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &pval, pmethodName) )
  {
    if ( (_S11_12 & 1) != 0 )
    {
      v13.pWeakProxy = 0i64;
    }
    else
    {
      _S11_12 |= 1u;
      v13.pWeakProxy = 0i64;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    v14 = argv;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->pAVM.pObject, &pval, &v, &result, (unsigned int)argc, argv, 0);
    v15 = 1;
  }
  else
  {
    v15 = 0;
    v14 = argv;
    v13.pWeakProxy = 0i64;
  }
  Flags = pval.Flags;
  if ( (pval.Flags & 0x1F) > 9 )
  {
    if ( (pval.Flags & 0x200) != 0 )
    {
      v17 = pval.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&pval.Bonus, 0, 24);
      pval.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      switch ( pval.Flags & 0x1F )
      {
        case 0xA:
          VStr = pval.value.VS._1.VStr;
          v17 = pval.value.VS._1.VStr->RefCount-- == 1;
          if ( v17 )
            Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
          break;
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
          if ( !pval.value.VS._1.VBool )
          {
            VObj = pval.value.VS._1.VObj;
            goto LABEL_36;
          }
          --pval.value.VS._1.VStr;
          break;
        case 0x10:
        case 0x11:
          if ( ((__int64)pval.value.VS._2.VObj & 1) != 0 )
          {
            --pval.value.VS._2.VObj;
          }
          else
          {
            VObj = pval.value.VS._2.VObj;
LABEL_36:
            if ( VObj )
            {
              RefCount = VObj->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                VObj->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj);
              }
            }
          }
          break;
        default:
          break;
      }
    }
  }
  if ( v15 )
    goto LABEL_40;
LABEL_45:
  if ( (_DWORD)argc )
  {
    v22 = v14;
    v13.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)(unsigned int)argc;
    do
    {
      if ( (v22->Flags & 0x1F) > 9 )
      {
        if ( (v22->Flags & 0x200) != 0 )
        {
          v23 = v22->Bonus.pWeakProxy;
          v17 = v23->RefCount-- == 1;
          if ( v17 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          v22->Bonus.pWeakProxy = 0i64;
          v22->value.VS._1.VStr = 0i64;
          v22->value.VS._2.VObj = 0i64;
          v22->Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(v22);
        }
      }
      ++v22;
      --v13.pWeakProxy;
    }
    while ( v13.pWeakProxy );
  }
  if ( (unsigned int)argc > 0xA )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v14);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags & 0x200) != 0 )
    {
      v17 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      result.Bonus = v13;
      result.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v13.pWeakProxy;
      result.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v13.pWeakProxy;
      result.Flags &= 0xFFFFFDE0;
    }
    else
    {
      switch ( result.Flags & 0x1F )
      {
        case 0xA:
          v24 = result.value.VS._1.VStr;
          v17 = result.value.VS._1.VStr->RefCount-- == 1;
          if ( v17 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v24);
          break;
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
          v25 = result.value.VS._1.VObj;
          if ( result.value.VS._1.VBool )
          {
            --result.value.VS._1.VStr;
          }
          else if ( result.value.VS._1.VStr )
          {
            Size = result.value.VS._1.VStr->Size;
            if ( (Size & 0x3FFFFF) != 0 )
            {
              result.value.VS._1.VStr->Size = Size - 1;
              goto LABEL_74;
            }
          }
          break;
        case 0x10:
        case 0x11:
          v25 = result.value.VS._2.VObj;
          if ( ((__int64)result.value.VS._2.VObj & 1) != 0 )
          {
            --result.value.VS._2.VObj;
          }
          else if ( result.value.VS._2.VObj )
          {
            v27 = result.value.VS._2.VObj->RefCount;
            if ( (v27 & 0x3FFFFF) != 0 )
            {
              result.value.VS._2.VObj->RefCount = v27 - 1;
LABEL_74:
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v25);
            }
          }
          break;
        default:
          return v15;
      }
    }
  }
  return v15;
}

// File Line: 2294
// RVA: 0x7F7260
__int64 Scaleform::GFx::AS3::MovieRoot::Invoke(
        Scaleform::GFx::AS3::MovieRoot *this,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        const char *pargFmt,
        ...)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, const char *, Scaleform::GFx::Value *))this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[57].__vecDelDtor)(
           this,
           pmethodName,
           presult);
}

// File Line: 2307
// RVA: 0x806350
void __fastcall Scaleform::GFx::AS3::MovieRoot::ParseValueArguments(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::Array<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *arr,
        const char *pmethodName,
        const char *pargFmt,
        char *args)
{
  Scaleform::Array<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v5; // r15
  const char *v6; // rdx
  unsigned int Flags; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rbx
  char v9; // al
  const char *v10; // r14
  Scaleform::GFx::AS3::Value::V2U v11; // r12
  Scaleform::GFx::ASStringNode *VStr; // rsi
  __int64 v13; // r9
  char *v14; // r13
  char v15; // al
  int v16; // esi
  bool v17; // zf
  Scaleform::GFx::AS3::Value::V2U v18; // r13
  __int64 v19; // rcx
  __int64 v20; // rdx
  __int64 v21; // rdx
  __int64 v22; // rcx
  __int64 v23; // rdx
  __int64 v24; // rdx
  __int64 v25; // rcx
  __int64 v26; // rdx
  __int64 v27; // rdx
  __int64 v28; // rcx
  __int64 v29; // rdx
  __int64 v30; // rdx
  __int64 v31; // rcx
  __int64 v32; // rdx
  __int64 v33; // rdx
  char v34; // al
  __int64 v35; // rcx
  __int64 v36; // rdx
  __int64 v37; // rdx
  Scaleform::GFx::AS3::Value::V1U *v38; // rax
  int v39; // r14d
  Scaleform::GFx::AS3::Value::V1U v40; // r15
  Scaleform::GFx::AS3::Value::V2U v41; // r13
  unsigned __int64 Size; // rcx
  Scaleform::GFx::AS3::Value *v43; // rdx
  __int64 v44; // rdx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  char v46; // al
  Scaleform::GFx::AS3::Value::V1U *v47; // rax
  int v48; // r14d
  Scaleform::GFx::AS3::Value::V1U v49; // r15
  Scaleform::GFx::AS3::Value::V2U v50; // r13
  unsigned __int64 v51; // rcx
  Scaleform::GFx::AS3::Value *v52; // rdx
  __int64 v53; // rdx
  char i; // al
  unsigned int v55; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // rcx
  unsigned int RefCount; // eax
  __int64 v58; // [rsp+20h] [rbp-B1h]
  Scaleform::GFx::AS3::Value v59; // [rsp+30h] [rbp-A1h] BYREF
  const char *v60; // [rsp+50h] [rbp-81h]
  __int64 v61; // [rsp+58h] [rbp-79h]
  Scaleform::GFx::LogState *pObject; // [rsp+60h] [rbp-71h]
  Scaleform::GFx::AS3::Value::VU v63; // [rsp+68h] [rbp-69h]
  Scaleform::GFx::AS3::Value v64; // [rsp+78h] [rbp-59h] BYREF
  Scaleform::GFx::AS3::Value v65; // [rsp+98h] [rbp-39h] BYREF
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [rsp+B8h] [rbp-19h] BYREF
  Scaleform::GFx::ASString v67; // [rsp+C0h] [rbp-11h] BYREF
  Scaleform::GFx::ASString v68; // [rsp+C8h] [rbp-9h] BYREF
  __int64 v69; // [rsp+D0h] [rbp-1h]
  __int64 v70; // [rsp+D8h] [rbp+7h]

  v70 = -2i64;
  v5 = arr;
  pObject = Scaleform::GFx::StateBag::GetLogState(&this->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v5->Data,
    0i64);
  v6 = pargFmt;
  if ( pargFmt )
  {
    Flags = 0;
    v59.Flags = 0;
    pWeakProxy = 0i64;
    v59.Bonus.pWeakProxy = 0i64;
    v9 = *pargFmt;
    v10 = pargFmt + 1;
    v11.VObj = (Scaleform::GFx::AS3::Object *)v59.value.VS._2;
    VStr = v59.value.VS._1.VStr;
    if ( *pargFmt )
    {
      v13 = 0x100100000200i64;
      v14 = args;
      do
      {
        if ( v9 == 37 )
        {
          v15 = *v10++;
          v60 = v10;
          switch ( v15 )
          {
            case d:
              args += 8;
              v16 = *((_DWORD *)args - 2);
              if ( (Flags & 0x1F) > 9 )
              {
                if ( (Flags & 0x200) != 0 )
                {
                  v17 = pWeakProxy->RefCount-- == 1;
                  if ( v17 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, _QWORD, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
                      Scaleform::Memory::pGlobalHeap,
                      pWeakProxy,
                      0i64,
                      0x100100000200i64);
                  pWeakProxy = 0i64;
                  memset(&v59.Bonus, 0, 24);
                  Flags &= 0xFFFFFDE0;
                  v59.Flags = Flags;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v59);
                  pWeakProxy = v59.Bonus.pWeakProxy;
                  Flags = v59.Flags;
                }
              }
              Flags = Flags & 0xFFFFFFE0 | 2;
              v59.Flags = Flags;
              v63.VS._1.VInt = v16;
              VStr = v63.VS._1.VStr;
              v59.value = v63;
              v18.VObj = (Scaleform::GFx::AS3::Object *)v63.VS._2;
              v11.VObj = (Scaleform::GFx::AS3::Object *)v63.VS._2;
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                &v5->Data,
                v5,
                v5->Data.Size + 1);
              v19 = 32 * v5->Data.Size;
              v20 = (__int64)&v5->Data.Data[-1];
              v17 = v19 + v20 == 0;
              v21 = v19 + v20;
              v60 = (const char *)v21;
              v61 = v21;
              if ( !v17 )
              {
                *(_DWORD *)v21 = Flags;
                *(_QWORD *)(v21 + 8) = pWeakProxy;
                *(_QWORD *)(v21 + 16) = VStr;
                *(Scaleform::GFx::AS3::Value::V2U *)(v21 + 24) = v18;
                if ( (Flags & 0x1F) > 9 )
                {
                  if ( (Flags & 0x200) != 0 )
                  {
                    ++pWeakProxy->RefCount;
                  }
                  else if ( (Flags & 0x1F) == 10 )
                  {
                    ++VStr->RefCount;
                  }
                  else if ( (Flags & 0x1F) > 0xA )
                  {
                    if ( (Flags & 0x1F) <= 0xF )
                    {
                      if ( VStr )
                        VStr->Size = (VStr->Size + 1) & 0x8FBFFFFF;
                    }
                    else if ( (Flags & 0x1F) <= 0x11 && v18.VObj )
                    {
                      v18.VObj->RefCount = (v18.VObj->RefCount + 1) & 0x8FBFFFFF;
                    }
                  }
                }
              }
              goto LABEL_161;
            case u:
              if ( (Flags & 0x1F) > 9 )
              {
                if ( (Flags & 0x200) != 0 )
                {
                  v17 = pWeakProxy->RefCount-- == 1;
                  if ( v17 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, _QWORD, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
                      Scaleform::Memory::pGlobalHeap,
                      pWeakProxy,
                      0i64,
                      0x100100000200i64);
                  pWeakProxy = 0i64;
                  memset(&v59.Bonus, 0, 24);
                  VStr = 0i64;
                  v11.VObj = 0i64;
                  Flags &= 0xFFFFFDE0;
                  v59.Flags = Flags;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v59);
                  v11.VObj = (Scaleform::GFx::AS3::Object *)v59.value.VS._2;
                  VStr = v59.value.VS._1.VStr;
                  pWeakProxy = v59.Bonus.pWeakProxy;
                  Flags = v59.Flags;
                }
              }
              Flags &= 0xFFFFFFE0;
              v59.Flags = Flags;
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                &v5->Data,
                v5,
                v5->Data.Size + 1);
              v22 = 32 * v5->Data.Size;
              v23 = (__int64)&v5->Data.Data[-1];
              v17 = v22 + v23 == 0;
              v24 = v22 + v23;
              v61 = v24;
              v60 = (const char *)v24;
              if ( !v17 )
              {
                *(_DWORD *)v24 = Flags;
                *(_QWORD *)(v24 + 8) = pWeakProxy;
                *(_QWORD *)(v24 + 16) = VStr;
                *(Scaleform::GFx::AS3::Value::V2U *)(v24 + 24) = v11;
                if ( (Flags & 0x1F) > 9 )
                {
                  if ( (Flags & 0x200) != 0 )
                  {
                    ++pWeakProxy->RefCount;
                  }
                  else if ( (Flags & 0x1F) == 10 )
                  {
                    ++VStr->RefCount;
                  }
                  else if ( (Flags & 0x1F) > 0xA )
                  {
                    if ( (Flags & 0x1F) <= 0xF )
                    {
                      if ( VStr )
                        VStr->Size = (VStr->Size + 1) & 0x8FBFFFFF;
                    }
                    else if ( (Flags & 0x1F) <= 0x11 && v11.VObj )
                    {
                      v11.VObj->RefCount = (v11.VObj->RefCount + 1) & 0x8FBFFFFF;
                    }
                  }
                }
              }
              goto LABEL_162;
            case n:
              if ( (Flags & 0x1F) > 9 )
              {
                if ( (Flags & 0x200) != 0 )
                {
                  v17 = pWeakProxy->RefCount-- == 1;
                  if ( v17 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, _QWORD, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
                      Scaleform::Memory::pGlobalHeap,
                      pWeakProxy,
                      0i64,
                      0x100100000200i64);
                  pWeakProxy = 0i64;
                  memset(&v59.Bonus, 0, 24);
                  Flags &= 0xFFFFFDE0;
                  v59.Flags = Flags;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v59);
                  pWeakProxy = v59.Bonus.pWeakProxy;
                  Flags = v59.Flags;
                }
              }
              Flags = Flags & 0xFFFFFFE0 | 0xC;
              v59.Flags = Flags;
              VStr = 0i64;
              v59.value.VS._1.VStr = 0i64;
              v11.VObj = (Scaleform::GFx::AS3::Object *)v63.VS._2;
              v59.value.VS._2.VObj = v63.VS._2.VObj;
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                &v5->Data,
                v5,
                v5->Data.Size + 1);
              v25 = 32 * v5->Data.Size;
              v26 = (__int64)&v5->Data.Data[-1];
              v17 = v25 + v26 == 0;
              v27 = v25 + v26;
              v61 = v27;
              v60 = (const char *)v27;
              if ( !v17 )
              {
                *(_DWORD *)v27 = Flags;
                *(_QWORD *)(v27 + 8) = pWeakProxy;
                *(_QWORD *)(v27 + 16) = 0i64;
                *(Scaleform::GFx::AS3::Value::V2U *)(v27 + 24) = v11;
                if ( (Flags & 0x1F) > 9 )
                {
                  if ( (Flags & 0x200) != 0 )
                  {
                    ++pWeakProxy->RefCount;
                  }
                  else if ( (Flags & 0x1F) == 10 )
                  {
                    ++MEMORY[0x18];
                  }
                  else if ( (Flags & 0x1F) >= 0x10 && (Flags & 0x1F) <= 0x11 && v11.VObj )
                  {
                    v11.VObj->RefCount = (v11.VObj->RefCount + 1) & 0x8FBFFFFF;
                  }
                }
              }
              goto LABEL_162;
            case b:
              args += 8;
              Scaleform::GFx::AS3::Value::SetBool(&v59, *((_DWORD *)args - 2) != 0);
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                &v5->Data,
                v5,
                v5->Data.Size + 1);
              v28 = 32 * v5->Data.Size;
              v29 = (__int64)&v5->Data.Data[-1];
              v17 = v28 + v29 == 0;
              v30 = v28 + v29;
              v61 = v30;
              v60 = (const char *)v30;
              v11.VObj = (Scaleform::GFx::AS3::Object *)v59.value.VS._2;
              VStr = v59.value.VS._1.VStr;
              pWeakProxy = v59.Bonus.pWeakProxy;
              Flags = v59.Flags;
              if ( !v17 )
              {
                *(_DWORD *)v30 = v59.Flags;
                *(_QWORD *)(v30 + 8) = pWeakProxy;
                *(_QWORD *)(v30 + 16) = VStr;
                *(Scaleform::GFx::AS3::Value::V2U *)(v30 + 24) = v11;
                if ( (Flags & 0x1F) > 9 )
                {
                  if ( (Flags & 0x200) != 0 )
                  {
                    ++pWeakProxy->RefCount;
                  }
                  else if ( (Flags & 0x1F) == 10 )
                  {
                    ++VStr->RefCount;
                  }
                  else if ( (Flags & 0x1F) > 0xA )
                  {
                    if ( (Flags & 0x1F) <= 0xF )
                    {
                      if ( VStr )
                        VStr->Size = (VStr->Size + 1) & 0x8FBFFFFF;
                    }
                    else if ( (Flags & 0x1F) <= 0x11 && v11.VObj )
                    {
                      v11.VObj->RefCount = (v11.VObj->RefCount + 1) & 0x8FBFFFFF;
                    }
                  }
                }
              }
              goto LABEL_161;
            case f:
              args += 8;
              Scaleform::GFx::AS3::Value::SetNumber(&v59, *((long double *)args - 1));
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                &v5->Data,
                v5,
                v5->Data.Size + 1);
              v31 = 32 * v5->Data.Size;
              v32 = (__int64)&v5->Data.Data[-1];
              v17 = v31 + v32 == 0;
              v33 = v31 + v32;
              v61 = v33;
              v60 = (const char *)v33;
              v11.VObj = (Scaleform::GFx::AS3::Object *)v59.value.VS._2;
              VStr = v59.value.VS._1.VStr;
              pWeakProxy = v59.Bonus.pWeakProxy;
              Flags = v59.Flags;
              if ( !v17 )
              {
                *(_DWORD *)v33 = v59.Flags;
                *(_QWORD *)(v33 + 8) = pWeakProxy;
                *(_QWORD *)(v33 + 16) = VStr;
                *(Scaleform::GFx::AS3::Value::V2U *)(v33 + 24) = v11;
                if ( (Flags & 0x1F) > 9 )
                {
                  if ( (Flags & 0x200) != 0 )
                  {
                    ++pWeakProxy->RefCount;
                  }
                  else if ( (Flags & 0x1F) == 10 )
                  {
                    ++VStr->RefCount;
                  }
                  else if ( (Flags & 0x1F) > 0xA )
                  {
                    if ( (Flags & 0x1F) <= 0xF )
                    {
                      if ( VStr )
                        VStr->Size = (VStr->Size + 1) & 0x8FBFFFFF;
                    }
                    else if ( (Flags & 0x1F) <= 0x11 && v11.VObj )
                    {
                      v11.VObj->RefCount = (v11.VObj->RefCount + 1) & 0x8FBFFFFF;
                    }
                  }
                }
              }
              goto LABEL_161;
            case h:
              v34 = *v10++;
              if ( v34 == 102 )
              {
                v14 += 8;
                args = v14;
                Scaleform::GFx::AS3::Value::SetNumber(&v59, *((long double *)v14 - 1));
                Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                  &v5->Data,
                  v5,
                  v5->Data.Size + 1);
                v35 = 32 * v5->Data.Size;
                v36 = (__int64)&v5->Data.Data[-1];
                v17 = v35 + v36 == 0;
                v37 = v35 + v36;
                v61 = v37;
                v60 = (const char *)v37;
                v11.VObj = (Scaleform::GFx::AS3::Object *)v59.value.VS._2;
                VStr = v59.value.VS._1.VStr;
                pWeakProxy = v59.Bonus.pWeakProxy;
                Flags = v59.Flags;
                if ( !v17 )
                {
                  *(_DWORD *)v37 = v59.Flags;
                  *(_QWORD *)(v37 + 8) = pWeakProxy;
                  *(_QWORD *)(v37 + 16) = VStr;
                  *(Scaleform::GFx::AS3::Value::V2U *)(v37 + 24) = v11;
                  if ( (Flags & 0x1F) > 9 )
                  {
                    if ( (Flags & 0x200) != 0 )
                    {
                      ++pWeakProxy->RefCount;
                    }
                    else if ( (Flags & 0x1F) == 10 )
                    {
                      ++VStr->RefCount;
                    }
                    else if ( (Flags & 0x1F) > 0xA )
                    {
                      if ( (Flags & 0x1F) <= 0xF )
                      {
                        if ( VStr )
                          VStr->Size = (VStr->Size + 1) & 0x8FBFFFFF;
                      }
                      else if ( (Flags & 0x1F) <= 0x11 && v11.VObj )
                      {
                        v11.VObj->RefCount = (v11.VObj->RefCount + 1) & 0x8FBFFFFF;
                      }
                    }
                  }
                }
                goto LABEL_162;
              }
              if ( pObject )
              {
                LODWORD(v58) = v34;
                Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
                  &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
                  "ParseArguments(%s,%s) - invalid format %%h%c",
                  pmethodName,
                  v6,
                  v58);
                goto LABEL_162;
              }
              break;
            case s:
              args += 8;
              v38 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                                         &this->BuiltinsMgr,
                                                         &v67,
                                                         *((const char **)args - 1));
              v39 = 10;
              v65.Flags = 10;
              v65.Bonus.pWeakProxy = 0i64;
              v40 = *v38;
              v65.value.VS._1 = v40;
              if ( v40.VStr == &v40.VStr->pManager->NullStringNode )
              {
                v40.VStr = 0i64;
                v65.value.VS._1.VStr = 0i64;
                v41.VObj = (Scaleform::GFx::AS3::Object *)v63.VS._2;
                v65.value.VS._2.VObj = v63.VS._2.VObj;
                v39 = 12;
                v65.Flags = 12;
              }
              else
              {
                ++v40.VStr->RefCount;
                v41.VObj = (Scaleform::GFx::AS3::Object *)v65.value.VS._2;
              }
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                &arr->Data,
                arr,
                arr->Data.Size + 1);
              Size = arr->Data.Size;
              v43 = arr->Data.Data - 1;
              v17 = &v43[Size] == 0i64;
              v44 = (__int64)&v43[Size];
              v61 = v44;
              v69 = v44;
              if ( !v17 )
              {
                *(_DWORD *)v44 = v39;
                *(_QWORD *)(v44 + 8) = 0i64;
                *(Scaleform::GFx::AS3::Value::V1U *)(v44 + 16) = v40;
                *(Scaleform::GFx::AS3::Value::V2U *)(v44 + 24) = v41;
                if ( (v39 & 0x1Fu) > 9 )
                {
                  if ( (v39 & 0x1F) == 10 )
                  {
                    ++v40.VStr->RefCount;
                  }
                  else if ( (v39 & 0x1Fu) > 0xA )
                  {
                    if ( (v39 & 0x1Fu) <= 0xF )
                    {
                      if ( v40.VStr )
                        v40.VStr->Size = (v40.VStr->Size + 1) & 0x8FBFFFFF;
                    }
                    else if ( (v39 & 0x1Fu) <= 0x11 && v41.VObj )
                    {
                      v41.VObj->RefCount = (v41.VObj->RefCount + 1) & 0x8FBFFFFF;
                    }
                  }
                }
              }
              if ( (v39 & 0x1Fu) > 9 )
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v65);
              pNode = v67.pNode;
              goto LABEL_158;
            case l:
              v46 = *v10++;
              v60 = v10;
              if ( v46 == 115 )
              {
                args += 8;
                v47 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                                           &this->BuiltinsMgr,
                                                           &v68,
                                                           *((const wchar_t **)args - 1),
                                                           -1i64);
                v48 = 10;
                v64.Flags = 10;
                v64.Bonus.pWeakProxy = 0i64;
                v49 = *v47;
                v64.value.VS._1 = v49;
                if ( v49.VStr == &v49.VStr->pManager->NullStringNode )
                {
                  v49.VStr = 0i64;
                  v64.value.VS._1.VStr = 0i64;
                  v50.VObj = (Scaleform::GFx::AS3::Object *)v63.VS._2;
                  v64.value.VS._2.VObj = v63.VS._2.VObj;
                  v48 = 12;
                  v64.Flags = 12;
                }
                else
                {
                  ++v49.VStr->RefCount;
                  v50.VObj = (Scaleform::GFx::AS3::Object *)v64.value.VS._2;
                }
                Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                  &arr->Data,
                  arr,
                  arr->Data.Size + 1);
                v51 = arr->Data.Size;
                v52 = arr->Data.Data - 1;
                v17 = &v52[v51] == 0i64;
                v53 = (__int64)&v52[v51];
                v69 = v53;
                v61 = v53;
                if ( !v17 )
                {
                  *(_DWORD *)v53 = v48;
                  *(_QWORD *)(v53 + 8) = 0i64;
                  *(Scaleform::GFx::AS3::Value::V1U *)(v53 + 16) = v49;
                  *(Scaleform::GFx::AS3::Value::V2U *)(v53 + 24) = v50;
                  if ( (v48 & 0x1Fu) > 9 )
                  {
                    if ( (v48 & 0x1F) == 10 )
                    {
                      ++v49.VStr->RefCount;
                    }
                    else if ( (v48 & 0x1Fu) > 0xA )
                    {
                      if ( (v48 & 0x1Fu) <= 0xF )
                      {
                        if ( v49.VStr )
                          v49.VStr->Size = (v49.VStr->Size + 1) & 0x8FBFFFFF;
                      }
                      else if ( (v48 & 0x1Fu) <= 0x11 && v50.VObj )
                      {
                        v50.VObj->RefCount = (v50.VObj->RefCount + 1) & 0x8FBFFFFF;
                      }
                    }
                  }
                }
                if ( (v48 & 0x1Fu) > 9 )
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v64);
                pNode = v68.pNode;
LABEL_158:
                v17 = pNode->RefCount-- == 1;
                if ( v17 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
                v5 = arr;
                v10 = v60;
LABEL_161:
                v14 = args;
LABEL_162:
                v13 = 0x100100000200i64;
                v6 = pargFmt;
                break;
              }
              if ( pObject )
              {
                LODWORD(v58) = v46;
                Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
                  &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
                  "ParseArguments(%s,%s) - invalid format %%l%c",
                  pmethodName,
                  v6,
                  v58);
                goto LABEL_162;
              }
              break;
            default:
              if ( pObject )
              {
                LODWORD(v58) = v15;
                Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
                  &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
                  "ParseArguments(%s,%s) - invalid format %%%c",
                  pmethodName,
                  v6,
                  v58);
                goto LABEL_162;
              }
              break;
          }
        }
        else if ( pObject )
        {
          LODWORD(v58) = v9;
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
            &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
            "ParseArguments(%s,%s) - invalid char %c",
            pmethodName,
            v6,
            v58);
          goto LABEL_162;
        }
        for ( i = *v10; *v10; i = *++v10 )
        {
          if ( (unsigned __int8)i > 0x2Cu )
            break;
          if ( !_bittest64(&v13, i) )
            break;
        }
        v9 = *v10++;
      }
      while ( v9 );
    }
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        v17 = pWeakProxy->RefCount-- == 1;
        if ( v17 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        memset(&v59.Bonus, 0, 24);
        v59.Flags = Flags & 0xFFFFFDE0;
      }
      else
      {
        switch ( Flags & 0x1F )
        {
          case 0xAu:
            v17 = VStr->RefCount-- == 1;
            if ( v17 )
              Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
            break;
          case 0xBu:
          case 0xCu:
          case 0xDu:
          case 0xEu:
          case 0xFu:
            if ( v59.value.VS._1.VBool )
            {
              v59.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)((char *)VStr - 1);
            }
            else if ( VStr )
            {
              v55 = VStr->Size;
              if ( (v55 & 0x3FFFFF) != 0 )
              {
                VStr->Size = v55 - 1;
                VObj = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)VStr;
                goto LABEL_186;
              }
            }
            break;
          case 0x10u:
          case 0x11u:
            if ( ((__int64)v59.value.VS._2.VObj & 1) != 0 )
            {
              v59.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)v11.VObj - 1);
            }
            else if ( v11.VObj )
            {
              RefCount = v11.VObj->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v11.VObj->RefCount = RefCount - 1;
                VObj = v11.VObj;
LABEL_186:
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj);
              }
            }
            break;
          default:
            return;
        }
      }
    }
  }
}          }
            }
            break;
          default:
            return;
        }
      }
    }
  }
}

// File Line: 2432
// RVA: 0x7F7720
bool __fastcall Scaleform::GFx::AS3::MovieRoot::InvokeArgs(
        Scaleform::GFx::AS3::MovieRoot *this,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        const char *pargFmt)
{
  unsigned int Size; // r15d
  Scaleform::GFx::AS3::Value *Data; // r14
  Scaleform::GFx::AS3::Value *v9; // rbx
  unsigned int Flags; // ebx
  bool v11; // zf
  Scaleform::GFx::AS3::ASVM *pObject; // rax
  bool v13; // bl
  unsigned int v15; // ebx
  Scaleform::Array<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> arr; // [rsp+20h] [rbp-29h] BYREF
  Scaleform::GFx::AS3::Value result; // [rsp+38h] [rbp-11h] BYREF
  Scaleform::GFx::AS3::Value pval; // [rsp+58h] [rbp+Fh] BYREF
  void *p_value; // [rsp+A8h] [rbp+5Fh]
  char *retaddr; // [rsp+C8h] [rbp+7Fh]

  p_value = &result.value;
  arr.Data.Size = 0i64;
  arr.Data.Policy.Capacity = 0i64;
  Scaleform::GFx::AS3::MovieRoot::ParseValueArguments(this, &arr, pmethodName, pargFmt, retaddr);
  Size = arr.Data.Size;
  Data = 0i64;
  if ( LODWORD(arr.Data.Size) )
    Data = arr.Data.Data;
  result.Flags = 0;
  result.Bonus.pWeakProxy = 0i64;
  if ( this->pInvokeAliases )
  {
    v9 = Scaleform::GFx::AS3::MovieRoot::ResolveInvokeAlias(this, pmethodName);
    if ( v9 )
    {
      if ( (_S11_12 & 1) == 0 )
      {
        _S11_12 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->pAVM.pObject, v9, &v, &result, Size, Data, 0);
LABEL_17:
      pObject = this->pAVM.pObject;
      v13 = !pObject->HandleException;
      if ( pObject->HandleException )
        pObject->HandleException = 0;
      if ( v13 && presult )
        Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, &result, presult);
      if ( (result.Flags & 0x1F) > 9 )
      {
        if ( (result.Flags & 0x200) != 0 )
        {
          v11 = result.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v11 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&result.Bonus, 0, 24);
          result.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
        }
      }
      p_value = &arr;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(arr.Data.Data, arr.Data.Size);
      if ( arr.Data.Data )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      return v13;
    }
  }
  pval.Flags = 0;
  pval.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &pval, pmethodName) )
  {
    if ( (_S11_12 & 1) == 0 )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->pAVM.pObject, &pval, &v, &result, Size, Data, 0);
    Flags = pval.Flags;
    if ( (pval.Flags & 0x1F) > 9 )
    {
      if ( (pval.Flags & 0x200) != 0 )
      {
        v11 = pval.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v11 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&pval.Bonus, 0, 24);
        pval.Flags = Flags & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
      }
    }
    goto LABEL_17;
  }
  v15 = pval.Flags;
  if ( (pval.Flags & 0x1F) > 9 )
  {
    if ( (pval.Flags & 0x200) != 0 )
    {
      v11 = pval.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&pval.Bonus, 0, 24);
      pval.Flags = v15 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
    }
  }
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags & 0x200) != 0 )
    {
      v11 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&result.Bonus, 0, 24);
      result.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
  }
  p_value = &arr;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(arr.Data.Data, arr.Data.Size);
  if ( arr.Data.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return 0;
}

// File Line: 2491
// RVA: 0x7895E0
void __fastcall Scaleform::GFx::AS3::MovieRoot::ActionQueueType::~ActionQueueType(
        Scaleform::GFx::AS3::MovieRoot::ActionQueueType *this)
{
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pFreeEntry; // rbx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pNextEntry; // rdi

  Scaleform::GFx::AS3::MovieRoot::ActionQueueType::Clear(this);
  pFreeEntry = this->pFreeEntry;
  if ( pFreeEntry )
  {
    do
    {
      pNextEntry = pFreeEntry->pNextEntry;
      Scaleform::GFx::AS3::MovieRoot::ActionEntry::~ActionEntry(pFreeEntry);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pFreeEntry);
      pFreeEntry = pNextEntry;
    }
    while ( pNextEntry );
  }
}

// File Line: 2504
// RVA: 0x7EC840
Scaleform::GFx::AS3::MovieRoot::ActionEntry *__fastcall Scaleform::GFx::AS3::MovieRoot::ActionQueueType::GetNewEntry(
        Scaleform::GFx::AS3::MovieRoot::ActionQueueType *this)
{
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pFreeEntry; // rbx
  __int64 v2; // rax
  Scaleform::RefCountNTSImpl *v3; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::Render::RenderBuffer *v8; // rcx

  pFreeEntry = this->pFreeEntry;
  if ( pFreeEntry )
  {
    this->pFreeEntry = pFreeEntry->pNextEntry;
    pFreeEntry->pNextEntry = 0i64;
    --this->FreeEntriesCount;
  }
  else
  {
    v2 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::MovieRoot::ActionQueueType *, __int64))this->pHeap->vfptr->Alloc)(
           this,
           104i64);
    pFreeEntry = (Scaleform::GFx::AS3::MovieRoot::ActionEntry *)v2;
    if ( v2 )
    {
      *(_QWORD *)(v2 + 16) = 0i64;
      *(_QWORD *)(v2 + 24) = 0i64;
      *(_QWORD *)(v2 + 32) = 0i64;
      *(_DWORD *)(v2 + 40) = 0;
      *(_BYTE *)(v2 + 44) = 0;
      *(_DWORD *)(v2 + 48) = 65280;
      *(_DWORD *)(v2 + 56) = 0;
      *(_QWORD *)(v2 + 64) = 0i64;
      *(_QWORD *)(v2 + 96) = 0i64;
      *(_QWORD *)v2 = 0i64;
      *(_DWORD *)(v2 + 8) = 0;
      v3 = *(Scaleform::RefCountNTSImpl **)(v2 + 16);
      if ( v3 )
        Scaleform::RefCountNTSImpl::Release(v3);
      pFreeEntry->pCharacter.pObject = 0i64;
      pObject = pFreeEntry->pAS3Obj.pObject;
      if ( pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          pFreeEntry->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
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
        pFreeEntry->pAS3Obj.pObject = 0i64;
      }
      pFreeEntry->CFunction = 0i64;
      if ( (pFreeEntry->Function.Flags & 0x1F) > 9 )
      {
        if ( (pFreeEntry->Function.Flags & 0x200) != 0 )
        {
          pWeakProxy = pFreeEntry->Function.Bonus.pWeakProxy;
          if ( pWeakProxy->RefCount-- == 1 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          pFreeEntry->Function.Bonus.pWeakProxy = 0i64;
          pFreeEntry->Function.value.VS._1.VStr = 0i64;
          pFreeEntry->Function.value.VS._2.VObj = 0i64;
          pFreeEntry->Function.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&pFreeEntry->Function);
        }
      }
      pFreeEntry->Function.Flags &= 0xFFFFFFE0;
      v8 = (Scaleform::Render::RenderBuffer *)pFreeEntry->pNLoadInitCL.pObject;
      if ( v8 )
        Scaleform::RefCountImpl::Release(v8);
      pFreeEntry->pNLoadInitCL.pObject = 0i64;
    }
    else
    {
      pFreeEntry = 0i64;
    }
    if ( !pFreeEntry )
      return 0i64;
  }
  return pFreeEntry;
}

// File Line: 2582
// RVA: 0x7AF840
void __fastcall Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(
        Scaleform::GFx::AS3::MovieRoot::ActionQueueType *this,
        Scaleform::GFx::AS3::MovieRoot::ActionEntry *pentry)
{
  Scaleform::GFx::DisplayObject *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v5; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::Render::RenderBuffer *v9; // rcx

  pentry->Type = Entry_None;
  pObject = pentry->pCharacter.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  pentry->pCharacter.pObject = 0i64;
  v5 = pentry->pAS3Obj.pObject;
  if ( v5 )
  {
    if ( ((unsigned __int8)v5 & 1) != 0 )
    {
      pentry->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v5 - 1);
    }
    else
    {
      RefCount = v5->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v5->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
      }
    }
    pentry->pAS3Obj.pObject = 0i64;
  }
  pentry->CFunction = 0i64;
  if ( (pentry->Function.Flags & 0x1F) > 9 )
  {
    if ( (pentry->Function.Flags & 0x200) != 0 )
    {
      pWeakProxy = pentry->Function.Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      pentry->Function.Flags &= 0xFFFFFDE0;
      pentry->Function.Bonus.pWeakProxy = 0i64;
      pentry->Function.value.VS._1.VStr = 0i64;
      pentry->Function.value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pentry->Function);
    }
  }
  pentry->Function.Flags &= 0xFFFFFFE0;
  v9 = (Scaleform::Render::RenderBuffer *)pentry->pNLoadInitCL.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  pentry->pNLoadInitCL.pObject = 0i64;
  if ( this->FreeEntriesCount >= 0x32 )
  {
    Scaleform::GFx::AS3::MovieRoot::ActionEntry::~ActionEntry(pentry);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pentry);
  }
  else
  {
    pentry->pNextEntry = this->pFreeEntry;
    ++this->FreeEntriesCount;
    this->pFreeEntry = pentry;
  }
}

// File Line: 2595
// RVA: 0x7B45F0
void __fastcall Scaleform::GFx::AS3::MovieRoot::ActionQueueType::Clear(
        Scaleform::GFx::AS3::MovieRoot::ActionQueueType *this)
{
  Scaleform::GFx::AS3::MovieRoot::ActionLevel i; // ebx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator v3; // [rsp+28h] [rbp-40h] BYREF

  for ( i = AL_Highest; (unsigned int)i < AL_Total; ++i )
  {
    v3.pActionQueue = this;
    v3.Level = i;
    v3.ModId = 0;
    v3.pLastEntry = 0i64;
    v3.pRootEntry = 0i64;
    v3.pCurEntry = this->Entries[i].pActionRoot;
    while ( Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&v3) )
      ;
    if ( v3.pLastEntry )
      Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(v3.pActionQueue, v3.pLastEntry);
  }
}

// File Line: 2617
// RVA: 0x7895C0
void __fastcall Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::~ActionQueueIterator(
        Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator *this)
{
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pLastEntry; // rdx

  pLastEntry = this->pLastEntry;
  if ( pLastEntry )
    Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(this->pActionQueue, pLastEntry);
}

// File Line: 2623
// RVA: 0x84BC10
Scaleform::GFx::AS3::MovieRoot::ActionEntry *__fastcall Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(
        Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator *this)
{
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *pActionQueue; // rdx
  int ModId; // eax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pRootEntry; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pNextEntry; // rcx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pCurEntry; // rdi
  __int64 Level; // rax
  __int64 v8; // rcx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v9; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionQueueEntry *v10; // rdx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v11; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v12; // rcx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *v13; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pLastEntry; // rax

  pActionQueue = this->pActionQueue;
  ModId = pActionQueue->ModId;
  if ( ModId != this->ModId )
  {
    this->ModId = ModId;
    pRootEntry = this->pRootEntry;
    if ( pRootEntry )
      pNextEntry = pRootEntry->pNextEntry;
    else
      pNextEntry = pActionQueue->Entries[this->Level].pActionRoot;
    this->pCurEntry = pNextEntry;
  }
  pCurEntry = this->pCurEntry;
  if ( pCurEntry )
  {
    Level = this->Level;
    v8 = Level;
    if ( pCurEntry == pActionQueue->Entries[Level].pInsertEntry )
    {
      v9 = pCurEntry->pNextEntry;
      if ( !pCurEntry->pNextEntry )
        v9 = this->pRootEntry;
      pActionQueue->Entries[v8].pInsertEntry = v9;
    }
    v10 = &this->pActionQueue->Entries[this->Level];
    v11 = this->pCurEntry;
    if ( v11 == v10->pActionRoot )
    {
      v10->pActionRoot = v11->pNextEntry;
    }
    else
    {
      v12 = this->pRootEntry;
      if ( v12 )
        v12->pNextEntry = v11->pNextEntry;
    }
    this->pCurEntry = this->pCurEntry->pNextEntry;
  }
  v13 = this->pActionQueue;
  if ( !v13->Entries[this->Level].pActionRoot )
  {
    v13->Entries[this->Level].pInsertEntry = 0i64;
    this->pActionQueue->Entries[this->Level].pLastEntry = 0i64;
  }
  pLastEntry = this->pLastEntry;
  if ( pLastEntry )
  {
    pLastEntry->pNextEntry = 0i64;
    Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(this->pActionQueue, this->pLastEntry);
    this->ModId = ++this->pActionQueue->ModId;
  }
  this->pLastEntry = pCurEntry;
  return pCurEntry;
}

// File Line: 2686
// RVA: 0x7C9E30
void __fastcall Scaleform::GFx::AS3::MovieRoot::ActionEntry::Execute(
        Scaleform::GFx::AS3::MovieRoot::ActionEntry *this,
        Scaleform::GFx::AS3::MovieRoot *proot)
{
  Scaleform::GFx::DisplayObject *pObject; // r8
  __int32 v5; // ecx
  __int32 v6; // ecx
  void (__fastcall *CFunction)(Scaleform::GFx::AS3::MovieRoot::ActionEntry *); // rax
  Scaleform::GFx::AS3::Value::V1U *v8; // rcx
  Scaleform::GFx::AS3::Value::V1U v9; // rax
  Scaleform::GFx::AS3::ASVM *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::Value _this; // [rsp+40h] [rbp+Fh] BYREF
  Scaleform::GFx::AS3::Value result; // [rsp+60h] [rbp+2Fh] BYREF

  pObject = this->pCharacter.pObject;
  if ( pObject && (pObject->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0 )
  {
    v5 = this->Type - 1;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( v6 )
      {
        if ( v6 == 1 )
        {
          CFunction = this->CFunction;
          if ( CFunction )
            CFunction(this);
        }
      }
      else
      {
        v8 = (Scaleform::GFx::AS3::Value::V1U *)((char *)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset);
        v9 = v8[2];
        if ( !v9.VStr )
          v9 = v8[1];
        if ( v9.VBool )
          --v9.VStr;
        _this.Flags = 12;
        _this.Bonus.pWeakProxy = 0i64;
        _this.value.VS._1 = v9;
        if ( v9.VStr )
          v9.VStr->Size = (v9.VStr->Size + 1) & 0x8FBFFFFF;
        result.Flags = 0;
        result.Bonus.pWeakProxy = 0i64;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
          proot->pAVM.pObject,
          &this->Function,
          &_this,
          &result,
          0,
          0i64,
          0);
        v10 = proot->pAVM.pObject;
        if ( v10->HandleException )
        {
          Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v10);
          this->pCharacter.pObject->Flags |= 0x20u;
        }
        if ( (result.Flags & 0x1F) > 9 )
        {
          if ( (result.Flags & 0x200) != 0 )
          {
            v11 = result.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&result.Bonus, 0, 24);
            result.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
          }
        }
        if ( (_this.Flags & 0x1F) > 9 )
        {
          if ( (_this.Flags & 0x200) != 0 )
          {
            v11 = _this.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&_this.Bonus, 0, 24);
            _this.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
          }
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::AvmDisplayObj::FireEvent(
        (Scaleform::GFx::AS3::AvmDisplayObj *)((char *)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset),
        &this->mEventId);
    }
  }
}

// File Line: 2727
// RVA: 0x7ADC30
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddInvokeAlias(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::ASString *alias,
        Scaleform::GFx::AS3::Value *closure)
{
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS3::Value> *v6; // rax

  if ( !this->pInvokeAliases )
  {
    v6 = (Scaleform::GFx::ASStringHash<Scaleform::GFx::AS3::Value> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                                       Scaleform::Memory::pGlobalHeap,
                                                                       8i64);
    if ( v6 )
      v6->mHash.pTable = 0i64;
    this->pInvokeAliases = v6;
  }
  Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Set(
    this->pInvokeAliases,
    alias,
    closure);
}

// File Line: 2734
// RVA: 0x8159D0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::MovieRoot::ResolveInvokeAlias(
        Scaleform::GFx::AS3::MovieRoot *this,
        const char *pstr)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // r10
  unsigned __int64 SizeMask; // rbx
  __int64 v5; // r11
  __int64 EntryCount; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v7; // r9
  Scaleform::GFx::ASStringNode *v8; // rdx
  __int64 p_SizeMask; // rbx
  __int64 v10; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  if ( !this->pInvokeAliases )
    return 0i64;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    &this->BuiltinsMgr,
    &result,
    pstr);
  pTable = this->pInvokeAliases->mHash.pTable;
  if ( !pTable )
    goto LABEL_12;
  SizeMask = pTable->SizeMask;
  v5 = (unsigned int)SizeMask & result.pNode->HashFlags;
  EntryCount = v5;
  v7 = &pTable[3 * v5 + 1];
  if ( v7->EntryCount == -2i64 || ((unsigned int)SizeMask & *(_DWORD *)(v7->SizeMask + 28)) != v5 )
    goto LABEL_12;
  while ( 1 )
  {
    v8 = (Scaleform::GFx::ASStringNode *)v7->SizeMask;
    if ( ((unsigned int)SizeMask & v8->HashFlags) == v5 && v8 == result.pNode )
      break;
    EntryCount = v7->EntryCount;
    if ( v7->EntryCount == -1i64 )
      goto LABEL_12;
    v7 = &pTable[3 * EntryCount + 1];
  }
  if ( EntryCount >= 0 && (p_SizeMask = (__int64)&pTable[3 * EntryCount + 1].SizeMask) != 0 )
    v10 = p_SizeMask + 8;
  else
LABEL_12:
    v10 = 0i64;
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return (Scaleform::GFx::AS3::Value *)v10;
}

// File Line: 2745
// RVA: 0x7AE4B0
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddScriptableMovieClip(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::DisplayObjContainer *pspr)
{
  __int64 v3; // rdx
  unsigned int Flags; // ecx
  int v5; // eax

  if ( !pspr->pParent )
  {
    Scaleform::GFx::InteractiveObject::AddToPlayList(pspr);
    Flags = pspr->Scaleform::GFx::InteractiveObject::Flags;
    if ( (Flags & 0x200000) == 0 || (Flags & 0x400000) != 0 )
      v3 = 0i64;
    else
      LOBYTE(v3) = 1;
    v5 = (int)pspr->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[103].__vecDelDtor(
                pspr,
                v3);
    if ( v5 == -1 )
    {
      pspr->Scaleform::GFx::InteractiveObject::Flags |= 0x400000u;
    }
    else if ( v5 == 1 )
    {
      Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(pspr);
    }
  }
}

// File Line: 2787
// RVA: 0x7D1F40
__int64 __fastcall Scaleform::GFx::AS3::MovieRoot::FindExtensionContexts(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::ASString *extensionID,
        Scaleform::GFx::ASString *contextType)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *,2,Scaleform::ArrayDefaultPolicy> *pObject; // rdi
  __int64 v7; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *,2,Scaleform::ArrayDefaultPolicy> *v8; // rbx
  Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext **Data; // rax
  Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *v10; // rcx
  unsigned __int64 Size; // r8
  Scaleform::GFx::ASStringNode *pNode; // rcx

  pObject = this->ExtensionContextArray.pObject;
  if ( !pObject )
    return -1i64;
  v7 = pObject->Data.Size - 1;
  if ( v7 < 0 )
    return -1i64;
  while ( 1 )
  {
    v8 = this->ExtensionContextArray.pObject;
    Data = v8->Data.Data;
    v10 = v8->Data.Data[v7];
    if ( !v10 )
    {
      Size = v8->Data.Size;
      if ( Size == 1 )
      {
        if ( (v8->Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
        {
          if ( Data )
          {
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8->Data.Data);
            v8->Data.Data = 0i64;
          }
          v8->Data.Policy.Capacity = 0i64;
        }
        v8->Data.Size = 0i64;
      }
      else
      {
        memmove(&Data[v7], &Data[v7 + 1], 8 * (Size - v7) - 8);
        --v8->Data.Size;
      }
      goto LABEL_15;
    }
    if ( extensionID->pNode == v10->ExtensionID.pNode )
    {
      pNode = v10->ContextID.pNode;
      if ( contextType->pNode == pNode || !contextType->pNode->Size && pNode == &pNode->pManager->NullStringNode )
        return v7;
    }
LABEL_15:
    if ( --v7 < 0 )
      return -1i64;
  }
}

// File Line: 2811
// RVA: 0x8028D0
void __fastcall Scaleform::GFx::AS3::MovieRoot::NotifyStatusEvent(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::EventId *id)
{
  Scaleform::String *v4; // r8
  __int64 ExtensionContexts; // rax
  _QWORD *v6; // rdi
  _QWORD *v7; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  _QWORD *v11; // rdi
  _QWORD *v12; // rdi
  Scaleform::GFx::ASString contextType; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+18h] BYREF

  v4 = *(Scaleform::String **)&id[2].Id;
  if ( v4 )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
      &this->BuiltinsMgr,
      &result,
      v4);
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
      &this->BuiltinsMgr,
      &contextType,
      *(Scaleform::String **)&id[2].KeyCode);
    ExtensionContexts = Scaleform::GFx::AS3::MovieRoot::FindExtensionContexts(this, &result, &contextType);
    if ( ExtensionContexts != -1 )
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
        this->ExtensionContextArray.pObject->Data.Data[ExtensionContexts],
        id,
        0i64);
    v6 = *(_QWORD **)&id[2].Id;
    if ( v6 )
    {
      if ( !_InterlockedDecrement((volatile signed __int32 *)((*v6 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      Illusion::ShaderParam::operator delete(v6);
    }
    v7 = *(_QWORD **)&id[2].KeyCode;
    if ( v7 )
    {
      if ( !_InterlockedDecrement((volatile signed __int32 *)((*v7 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      Illusion::ShaderParam::operator delete(v7);
    }
    pNode = contextType.pNode;
    v9 = contextType.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v10 = result.pNode;
    v9 = result.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
  else
  {
    ((void (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *))this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[61].__vecDelDtor)(this);
  }
  v11 = *(_QWORD **)&id[1].WcharCode;
  if ( v11 )
  {
    if ( !_InterlockedDecrement((volatile signed __int32 *)((*v11 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    Illusion::ShaderParam::operator delete(v11);
  }
  v12 = *(_QWORD **)&id[1].AsciiCode;
  if ( v12 )
  {
    if ( !_InterlockedDecrement((volatile signed __int32 *)((*v12 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    Illusion::ShaderParam::operator delete(v12);
  }
}

// File Line: 2839
// RVA: 0x802570
void __fastcall Scaleform::GFx::AS3::MovieRoot::NotifyAccelerometerEvent(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::EventId *id,
        int evtIdAcc)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *,2,Scaleform::ArrayDefaultPolicy> *pObject; // rdi
  __int64 i; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *,2,Scaleform::ArrayDefaultPolicy> *v8; // rbx
  Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer **Data; // rax
  Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *v10; // rcx
  unsigned __int64 Size; // r8

  pObject = this->AccelerometerArray.pObject;
  if ( pObject )
  {
    for ( i = pObject->Data.Size - 1; i >= 0; --i )
    {
      v8 = this->AccelerometerArray.pObject;
      Data = v8->Data.Data;
      v10 = v8->Data.Data[i];
      if ( v10 )
      {
        if ( v10->AccelerometerId == evtIdAcc )
        {
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(v10, id, 0i64);
          return;
        }
      }
      else
      {
        Size = v8->Data.Size;
        if ( Size == 1 )
        {
          if ( (v8->Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
          {
            if ( Data )
            {
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8->Data.Data);
              v8->Data.Data = 0i64;
            }
            v8->Data.Policy.Capacity = 0i64;
          }
          v8->Data.Size = 0i64;
        }
        else
        {
          memmove(&Data[i], &Data[i + 1], 8 * (Size - i) - 8);
          --v8->Data.Size;
        }
      }
    }
  }
}

// File Line: 2862
// RVA: 0x7AF530
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddToAccelerometers(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS2::Object *pAccelerometer)
{
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *,2,Scaleform::ArrayDefaultPolicy> > *p_AccelerometerArray; // rdi
  unsigned __int64 v4; // rbx
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *v5; // rax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *pObject; // rdi
  unsigned __int64 Size; // rcx
  Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer **Data; // rax
  unsigned __int64 v9; // rbx
  unsigned __int64 v10; // r8
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v11; // rcx

  p_AccelerometerArray = &this->AccelerometerArray;
  v4 = 0i64;
  if ( !this->AccelerometerArray.pObject )
  {
    v5 = (Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *)this->pMovieImpl->pHeap->vfptr->Alloc(this, 24i64, 0i64);
    if ( v5 )
    {
      v5->Data.Data = 0i64;
      v5->Data.Size = 0i64;
      v5->Data.Policy.Capacity = 0i64;
    }
    else
    {
      v5 = 0i64;
    }
    Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *,2,Scaleform::ArrayDefaultPolicy>>::operator=(
      (Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> > *)p_AccelerometerArray,
      v5);
  }
  pObject = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)p_AccelerometerArray->pObject;
  if ( !pObject )
    goto LABEL_13;
  Size = pObject->Size;
  if ( !Size )
    goto LABEL_13;
  Data = (Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer **)pObject->Data;
  while ( *Data != (Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *)pAccelerometer )
  {
    ++v4;
    ++Data;
    if ( v4 >= Size )
      goto LABEL_13;
  }
  if ( v4 == -1i64 )
  {
LABEL_13:
    v9 = pObject->Size + 1;
    if ( v9 >= pObject->Size )
    {
      if ( v9 <= pObject->Policy.Capacity )
        goto LABEL_19;
      v10 = v9 + (v9 >> 2);
    }
    else
    {
      if ( v9 >= pObject->Policy.Capacity >> 1 )
        goto LABEL_19;
      v10 = pObject->Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      pObject,
      pObject,
      v10);
LABEL_19:
    pObject->Size = v9;
    v11 = &pObject->Data[v9 - 1];
    if ( v11 )
      v11->pObject = pAccelerometer;
  }
}

// File Line: 2886
// RVA: 0x8118D0
void __fastcall Scaleform::GFx::AS3::MovieRoot::RemoveFromAccelerometers(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *pAccelerometer)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *,2,Scaleform::ArrayDefaultPolicy> *pObject; // r9
  unsigned __int64 Size; // r8
  __int64 v4; // rax
  Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer **i; // rcx

  pObject = this->AccelerometerArray.pObject;
  if ( pObject )
  {
    Size = pObject->Data.Size;
    v4 = 0i64;
    if ( Size )
    {
      for ( i = pObject->Data.Data; *i != pAccelerometer; ++i )
      {
        if ( ++v4 >= Size )
          return;
      }
      if ( v4 != -1 )
        pObject->Data.Data[v4] = 0i64;
    }
  }
}

// File Line: 2897
// RVA: 0x802750
void __fastcall Scaleform::GFx::AS3::MovieRoot::NotifyGeolocationEvent(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::EventId *id,
        int evtIdGeo)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *pObject; // rdi
  __int64 i; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *v8; // rbx
  Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation **Data; // rax
  Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *v10; // rcx
  unsigned __int64 Size; // r8

  pObject = this->GeolocationArray.pObject;
  if ( pObject )
  {
    for ( i = pObject->Data.Size - 1; i >= 0; --i )
    {
      v8 = this->GeolocationArray.pObject;
      Data = v8->Data.Data;
      v10 = v8->Data.Data[i];
      if ( v10 )
      {
        if ( v10->GeolocationId == evtIdGeo )
        {
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(v10, id, 0i64);
          return;
        }
      }
      else
      {
        Size = v8->Data.Size;
        if ( Size == 1 )
        {
          if ( (v8->Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
          {
            if ( Data )
            {
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8->Data.Data);
              v8->Data.Data = 0i64;
            }
            v8->Data.Policy.Capacity = 0i64;
          }
          v8->Data.Size = 0i64;
        }
        else
        {
          memmove(&Data[i], &Data[i + 1], 8 * (Size - i) - 8);
          --v8->Data.Size;
        }
      }
    }
  }
}

// File Line: 2920
// RVA: 0x7B2240
void __fastcall Scaleform::GFx::AS3::MovieRoot::BroadcastGeolocationStatusEvent(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::EventId *id)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *pObject; // rdi
  __int64 i; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *v6; // rbx
  Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation **Data; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v8; // rcx
  unsigned __int64 Size; // r8

  pObject = this->GeolocationArray.pObject;
  if ( pObject )
  {
    for ( i = pObject->Data.Size - 1; i >= 0; --i )
    {
      v6 = this->GeolocationArray.pObject;
      Data = v6->Data.Data;
      v8 = v6->Data.Data[i];
      if ( v8 )
      {
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(v8, id, 0i64);
      }
      else
      {
        Size = v6->Data.Size;
        if ( Size == 1 )
        {
          if ( (v6->Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
          {
            if ( Data )
            {
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v6->Data.Data);
              v6->Data.Data = 0i64;
            }
            v6->Data.Policy.Capacity = 0i64;
          }
          v6->Data.Size = 0i64;
        }
        else
        {
          memmove(&Data[i], &Data[i + 1], 8 * (Size - i) - 8);
          --v6->Data.Size;
        }
      }
    }
  }
}

// File Line: 2940
// RVA: 0x7AF960
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddToGeolocations(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS2::Object *pGeolocation)
{
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> > *p_GeolocationArray; // rdi
  unsigned __int64 v4; // rbx
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *v5; // rax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *pObject; // rdi
  unsigned __int64 Size; // rcx
  Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation **Data; // rax
  unsigned __int64 v9; // rbx
  unsigned __int64 v10; // r8
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v11; // rcx

  p_GeolocationArray = &this->GeolocationArray;
  v4 = 0i64;
  if ( !this->GeolocationArray.pObject )
  {
    v5 = (Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *)this->pMovieImpl->pHeap->vfptr->Alloc(this, 24i64, 0i64);
    if ( v5 )
    {
      v5->Data.Data = 0i64;
      v5->Data.Size = 0i64;
      v5->Data.Policy.Capacity = 0i64;
    }
    else
    {
      v5 = 0i64;
    }
    Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *,2,Scaleform::ArrayDefaultPolicy>>::operator=(
      p_GeolocationArray,
      v5);
  }
  pObject = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)p_GeolocationArray->pObject;
  if ( !pObject )
    goto LABEL_13;
  Size = pObject->Size;
  if ( !Size )
    goto LABEL_13;
  Data = (Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation **)pObject->Data;
  while ( *Data != (Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *)pGeolocation )
  {
    ++v4;
    ++Data;
    if ( v4 >= Size )
      goto LABEL_13;
  }
  if ( v4 == -1i64 )
  {
LABEL_13:
    v9 = pObject->Size + 1;
    if ( v9 >= pObject->Size )
    {
      if ( v9 <= pObject->Policy.Capacity )
        goto LABEL_19;
      v10 = v9 + (v9 >> 2);
    }
    else
    {
      if ( v9 >= pObject->Policy.Capacity >> 1 )
        goto LABEL_19;
      v10 = pObject->Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      pObject,
      pObject,
      v10);
LABEL_19:
    pObject->Size = v9;
    v11 = &pObject->Data[v9 - 1];
    if ( v11 )
      v11->pObject = pGeolocation;
  }
}

// File Line: 2964
// RVA: 0x811A20
void __fastcall Scaleform::GFx::AS3::MovieRoot::RemoveFromGeolocations(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *pGeolocation)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *pObject; // r9
  unsigned __int64 Size; // r8
  __int64 v4; // rax
  Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation **i; // rcx

  pObject = this->GeolocationArray.pObject;
  if ( pObject )
  {
    Size = pObject->Data.Size;
    v4 = 0i64;
    if ( Size )
    {
      for ( i = pObject->Data.Data; *i != pGeolocation; ++i )
      {
        if ( ++v4 >= Size )
          return;
      }
      if ( v4 != -1 )
        pObject->Data.Data[v4] = 0i64;
    }
  }
}

// File Line: 2974
// RVA: 0x7AF630
void __fastcall Scaleform::GFx::AS3::EventChains::AddToChain(
        Scaleform::GFx::AS3::EventChains *this,
        int evtId,
        Scaleform::GFx::DisplayObject *obj)
{
  unsigned __int64 v4; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *pTable; // r10
  Scaleform::WeakPtrProxy *WeakProxy; // rbx
  unsigned __int64 SizeMask; // rdi
  __int64 v9; // r11
  __int64 v10; // r9
  __int64 v11; // rcx
  __int64 p_SizeMask; // rdi
  Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> **v13; // rdi
  Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> *v14; // rdi
  Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v15; // rax
  Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v16; // rsi
  Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v17; // rdx
  Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // [rsp+28h] [rbp-50h] BYREF
  char v20; // [rsp+30h] [rbp-48h]
  Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeRef key; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::EventChains *v22; // [rsp+80h] [rbp+8h] BYREF
  int v23; // [rsp+88h] [rbp+10h] BYREF
  Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v24; // [rsp+98h] [rbp+20h]

  v22 = this;
  v4 = evtId;
  pTable = this->Chains.mHash.pTable;
  WeakProxy = 0i64;
  if ( !this->Chains.mHash.pTable )
    goto LABEL_12;
  SizeMask = pTable->SizeMask;
  v9 = SizeMask & evtId;
  v10 = v9;
  v11 = (__int64)&pTable[2 * v9 + 1];
  if ( *(_QWORD *)v11 == -2i64 || (SizeMask & *(int *)(v11 + 8)) != v9 )
    goto LABEL_12;
  while ( (SizeMask & *(int *)(v11 + 8)) != v9 || *(_DWORD *)(v11 + 8) != evtId )
  {
    v10 = *(_QWORD *)v11;
    if ( *(_QWORD *)v11 == -1i64 )
      goto LABEL_12;
    v11 = (__int64)&pTable[2 * v10 + 1];
  }
  if ( v10 >= 0
    && (p_SizeMask = (__int64)&pTable[2 * v10 + 1].SizeMask) != 0
    && (v13 = (Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> **)(p_SizeMask + 8)) != 0i64 )
  {
    v14 = *v13;
  }
  else
  {
LABEL_12:
    v23 = 2;
    v15 = (Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::EventChains *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(Scaleform::Memory::pGlobalHeap, this, 24i64, &v23, -2i64);
    v14 = (Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> *)v15;
    v24 = v15;
    if ( v15 )
    {
      p_Data = v15;
      v15->Data = 0i64;
      v15->Size = 0i64;
      v15->Policy.Capacity = 0i64;
    }
    else
    {
      v14 = 0i64;
    }
    p_Data = &v14->Data;
    v20 = 1;
    LODWORD(v22) = v4;
    key.pFirst = (const int *)&v22;
    key.pSecond = (Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> > *)&p_Data;
    Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>::add<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeRef>(
      &this->Chains.mHash,
      this,
      &key,
      v4);
    v16 = p_Data;
    if ( p_Data )
    {
      if ( v20 )
      {
        v20 = 0;
        v24 = p_Data;
        Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>(p_Data);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v16);
      }
      p_Data = 0i64;
    }
    v20 = 0;
  }
  if ( Scaleform::GFx::AS3::EventChains::FindObjectIndexInChain(this, v14, obj) == -1i64 )
  {
    if ( obj )
      WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(obj);
    v22 = (Scaleform::GFx::AS3::EventChains *)WeakProxy;
    Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &v14->Data,
      v14,
      v14->Data.Size + 1);
    v17 = (Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *)&v14->Data.Data[v14->Data.Size - 1];
    v24 = v17;
    p_Data = v17;
    if ( v17 )
    {
      if ( WeakProxy )
        ++WeakProxy->RefCount;
      v17->Data = (Scaleform::WeakPtr<Scaleform::GFx::DisplayObject> *)WeakProxy;
    }
    if ( WeakProxy )
    {
      if ( WeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, WeakProxy);
    }
  }
}

// File Line: 2991
// RVA: 0x811920
void __fastcall Scaleform::GFx::AS3::EventChains::RemoveFromChain(
        Scaleform::GFx::AS3::EventChains *this,
        int evtId,
        Scaleform::GFx::DisplayObject *obj)
{
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *pTable; // r10
  unsigned __int64 SizeMask; // rbx
  __int64 v6; // r11
  __int64 v7; // r9
  __int64 v8; // r8
  __int64 p_SizeMask; // rax
  Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> **v10; // rax
  Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> *v11; // rbx
  __int64 ObjectIndexInChain; // rax
  Scaleform::WeakPtrProxy *pObject; // rdx
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject> *v14; // rbx

  pTable = this->Chains.mHash.pTable;
  if ( this->Chains.mHash.pTable )
  {
    SizeMask = pTable->SizeMask;
    v6 = SizeMask & evtId;
    v7 = v6;
    v8 = (__int64)&pTable[2 * v6 + 1];
    if ( *(_QWORD *)v8 != -2i64 && (SizeMask & *(int *)(v8 + 8)) == v6 )
    {
      while ( (SizeMask & *(int *)(v8 + 8)) != v6 || *(_DWORD *)(v8 + 8) != evtId )
      {
        v7 = *(_QWORD *)v8;
        if ( *(_QWORD *)v8 == -1i64 )
          return;
        v8 = (__int64)&pTable[2 * v7 + 1];
      }
      if ( v7 >= 0 )
      {
        p_SizeMask = (__int64)&pTable[2 * v7 + 1].SizeMask;
        if ( p_SizeMask )
        {
          v10 = (Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> **)(p_SizeMask + 8);
          if ( v10 )
          {
            v11 = *v10;
            ObjectIndexInChain = Scaleform::GFx::AS3::EventChains::FindObjectIndexInChain(this, *v10, obj);
            if ( ObjectIndexInChain != -1 )
            {
              pObject = v11->Data.Data[ObjectIndexInChain].pProxy.pObject;
              v14 = &v11->Data.Data[ObjectIndexInChain];
              if ( pObject )
              {
                if ( pObject->RefCount-- == 1 )
                  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              }
              v14->pProxy.pObject = 0i64;
            }
          }
        }
      }
    }
  }
}

// File Line: 3015
// RVA: 0x7C49C0
void __fastcall Scaleform::GFx::AS3::EventChains::Dispatch(Scaleform::GFx::AS3::EventChains *this, signed int evtId)
{
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *pTable; // r9
  unsigned __int64 SizeMask; // r11
  __int64 v5; // r10
  __int64 v6; // rcx
  __int64 v7; // r8
  __int64 p_SizeMask; // rax
  Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v9; // rdi
  unsigned __int64 v10; // rsi
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> *v11; // rbx
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> v12; // rdx
  Scaleform::GFx::Sprite *pObject; // rbx
  Scaleform::GFx::AS3::AvmDisplayObj *v14; // rcx
  bool v15; // zf
  Scaleform::WeakPtrProxy *v16; // rdx
  Scaleform::GFx::EventId id; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::Sprite *v19; // [rsp+80h] [rbp+18h]
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject> *v20; // [rsp+88h] [rbp+20h]

  pTable = this->Chains.mHash.pTable;
  if ( this->Chains.mHash.pTable )
  {
    SizeMask = pTable->SizeMask;
    v5 = SizeMask & evtId;
    v6 = v5;
    v7 = (__int64)&pTable[2 * v5 + 1];
    if ( *(_QWORD *)v7 != -2i64 && (SizeMask & *(int *)(v7 + 8)) == v5 )
    {
      while ( (SizeMask & *(int *)(v7 + 8)) != v5 || *(_DWORD *)(v7 + 8) != evtId )
      {
        v6 = *(_QWORD *)v7;
        if ( *(_QWORD *)v7 == -1i64 )
          return;
        v7 = (__int64)&pTable[2 * v6 + 1];
      }
      if ( v6 >= 0 )
      {
        p_SizeMask = (__int64)&pTable[2 * v6 + 1].SizeMask;
        if ( p_SizeMask )
        {
          if ( p_SizeMask != -8 )
          {
            v9 = *(Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> **)(p_SizeMask + 8);
            v10 = 0i64;
            if ( v9->Size )
            {
              while ( 1 )
              {
                v11 = (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v9->Data[v10];
                v12.pProxy.pObject = v11->pProxy.pObject;
                if ( !v11->pProxy.pObject )
                  goto LABEL_28;
                if ( !v12.pProxy.pObject->pObject )
                  break;
                if ( !v12.pProxy.pObject->pObject->RefCount )
                  goto LABEL_28;
                id.Id = evtId;
                *(_QWORD *)&id.WcharCode = 0i64;
                id.AsciiCode = 0;
                *(_DWORD *)&id.RollOverCnt = 65280;
                Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
                  v11,
                  &result);
                pObject = result.pObject;
                if ( result.pObject )
                {
                  ++result.pObject->RefCount;
                  pObject = result.pObject;
                }
                v19 = pObject;
                if ( result.pObject )
                  Scaleform::RefCountNTSImpl::Release(result.pObject);
                if ( pObject )
                  v14 = (Scaleform::GFx::AS3::AvmDisplayObj *)((char *)pObject
                                                             + 4 * (unsigned __int8)pObject->AvmObjOffset);
                else
                  v14 = 0i64;
                Scaleform::GFx::AS3::AvmDisplayObj::FireEvent(v14, &id);
                ++v10;
                if ( pObject )
                  Scaleform::RefCountNTSImpl::Release(pObject);
LABEL_34:
                if ( v10 >= v9->Size )
                  return;
              }
              if ( v12.pProxy.pObject )
              {
                v15 = v12.pProxy.pObject->RefCount-- == 1;
                if ( v15 )
                  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              }
              v11->pProxy.pObject = 0i64;
LABEL_28:
              if ( v9->Size == 1 )
              {
                Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                  v9,
                  v9,
                  0i64);
              }
              else
              {
                v20 = &v9->Data[v10];
                v16 = v20->pProxy.pObject;
                if ( v20->pProxy.pObject )
                {
                  v15 = v16->RefCount-- == 1;
                  if ( v15 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                }
                memmove(&v9->Data[v10], &v9->Data[v10 + 1], 8 * (v9->Size - v10) - 8);
                --v9->Size;
              }
              goto LABEL_34;
            }
          }
        }
      }
    }
  }
}

// File Line: 3037
// RVA: 0x80B750
void __fastcall Scaleform::GFx::AS3::EventChains::QueueEvents(Scaleform::GFx::AS3::EventChains *this, int evtId)
{
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *pTable; // r9
  unsigned __int64 SizeMask; // r11
  __int64 v5; // r10
  __int64 v6; // rcx
  __int64 v7; // r8
  __int64 p_SizeMask; // rax
  Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v9; // rdi
  unsigned __int64 v10; // rsi
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> *v11; // rbx
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> v12; // rdx
  Scaleform::GFx::Sprite *pObject; // rbx
  char *v14; // rcx
  bool v15; // zf
  Scaleform::WeakPtrProxy *v16; // rdx
  int v17; // [rsp+28h] [rbp-40h] BYREF
  __int64 v18; // [rsp+2Ch] [rbp-3Ch]
  char v19; // [rsp+34h] [rbp-34h]
  int v20; // [rsp+38h] [rbp-30h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::Sprite *v22; // [rsp+80h] [rbp+18h]
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject> *v23; // [rsp+88h] [rbp+20h]

  pTable = this->Chains.mHash.pTable;
  if ( this->Chains.mHash.pTable )
  {
    SizeMask = pTable->SizeMask;
    v5 = SizeMask & evtId;
    v6 = v5;
    v7 = (__int64)&pTable[2 * v5 + 1];
    if ( *(_QWORD *)v7 != -2i64 && (SizeMask & *(int *)(v7 + 8)) == v5 )
    {
      while ( (SizeMask & *(int *)(v7 + 8)) != v5 || *(_DWORD *)(v7 + 8) != evtId )
      {
        v6 = *(_QWORD *)v7;
        if ( *(_QWORD *)v7 == -1i64 )
          return;
        v7 = (__int64)&pTable[2 * v6 + 1];
      }
      if ( v6 >= 0 )
      {
        p_SizeMask = (__int64)&pTable[2 * v6 + 1].SizeMask;
        if ( p_SizeMask )
        {
          if ( p_SizeMask != -8 )
          {
            v9 = *(Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> **)(p_SizeMask + 8);
            v10 = 0i64;
            if ( v9->Size )
            {
              while ( 1 )
              {
                v11 = (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v9->Data[v10];
                v12.pProxy.pObject = v11->pProxy.pObject;
                if ( !v11->pProxy.pObject )
                  goto LABEL_28;
                if ( !v12.pProxy.pObject->pObject )
                  break;
                if ( !v12.pProxy.pObject->pObject->RefCount )
                  goto LABEL_28;
                v17 = evtId;
                v18 = 0i64;
                v19 = 0;
                v20 = 65280;
                Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
                  v11,
                  &result);
                pObject = result.pObject;
                if ( result.pObject )
                {
                  ++result.pObject->RefCount;
                  pObject = result.pObject;
                }
                v22 = pObject;
                if ( result.pObject )
                  Scaleform::RefCountNTSImpl::Release(result.pObject);
                if ( pObject )
                  v14 = (char *)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
                else
                  v14 = 0i64;
                (*(void (__fastcall **)(char *, int *))(*(_QWORD *)v14 + 64i64))(v14, &v17);
                ++v10;
                if ( pObject )
                  Scaleform::RefCountNTSImpl::Release(pObject);
LABEL_34:
                if ( v10 >= v9->Size )
                  return;
              }
              if ( v12.pProxy.pObject )
              {
                v15 = v12.pProxy.pObject->RefCount-- == 1;
                if ( v15 )
                  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              }
              v11->pProxy.pObject = 0i64;
LABEL_28:
              if ( v9->Size == 1 )
              {
                Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                  v9,
                  v9,
                  0i64);
              }
              else
              {
                v23 = &v9->Data[v10];
                v16 = v23->pProxy.pObject;
                if ( v23->pProxy.pObject )
                {
                  v15 = v16->RefCount-- == 1;
                  if ( v15 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                }
                memmove(&v9->Data[v10], &v9->Data[v10 + 1], 8 * (v9->Size - v10) - 8);
                --v9->Size;
              }
              goto LABEL_34;
            }
          }
        }
      }
    }
  }
}

// File Line: 3059
// RVA: 0x7D31F0
__int64 __fastcall Scaleform::GFx::AS3::EventChains::FindObjectIndexInChain(
        Scaleform::GFx::AS3::EventChains *this,
        Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> *chain,
        Scaleform::GFx::DisplayObject *obj)
{
  unsigned __int64 Size; // rbp
  __int64 v6; // rdi
  Scaleform::GFx::DisplayObject *v7; // rbx
  Scaleform::WeakPtrProxy *pObject; // rdx
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject> *v9; // rsi
  Scaleform::RefCountWeakSupportImpl *v10; // rax

  Size = chain->Data.Size;
  v6 = 0i64;
  if ( !Size )
    return -1i64;
  while ( 1 )
  {
    v7 = 0i64;
    pObject = chain->Data.Data[v6].pProxy.pObject;
    v9 = &chain->Data.Data[v6];
    if ( pObject )
    {
      v10 = pObject->pObject;
      if ( v10 )
      {
        v7 = (Scaleform::GFx::DisplayObject *)pObject->pObject;
        if ( !v10->RefCount )
          v7 = 0i64;
      }
      else
      {
        if ( pObject->RefCount-- == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v9->pProxy.pObject = 0i64;
      }
    }
    if ( v7 == obj )
      break;
    if ( ++v6 >= Size )
      return -1i64;
  }
  return v6;
}

// File Line: 3074
// RVA: 0x77F4B0
void __fastcall Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(
        Scaleform::GFx::AS3::LoadQueueEntry *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *request,
        Scaleform::GFx::AS3::Instances::fl::XMLList *loader,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        bool quietOpen)
{
  char *vfptr; // rdx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::String src; // [rsp+68h] [rbp+10h] BYREF

  if ( request )
    vfptr = (char *)request->TargetObject.pObject->vfptr;
  else
    vfptr = &customCaption;
  Scaleform::String::String(&src, vfptr);
  this->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable;
  Scaleform::String::String(&this->URL);
  this->Type = (src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) == -12i64;
  this->Method = method;
  this->pNext = 0i64;
  Scaleform::String::operator=(&this->URL, &src);
  this->EntryTime = -1;
  this->QuietOpen = quietOpen;
  this->Canceled = 0;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::AS3::LoadQueueEntry::`vftable;
  this->mLoader.pObject = 0i64;
  this->mURLLoader.pObject = 0i64;
  this->mURLRequest.pObject = 0i64;
  this->mBytes.pObject = 0i64;
  this->mBytes.Owner = 1;
  this->NotifyLoadInitCInterface.pObject = 0i64;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->mLoader,
    loader);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->mURLRequest,
    request);
  this->FirstExec = 1;
  pObject = (Scaleform::Render::RenderBuffer *)this->NotifyLoadInitCInterface.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->NotifyLoadInitCInterface.pObject = 0i64;
}

// File Line: 3083
// RVA: 0x77F340
void __fastcall Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(
        Scaleform::GFx::AS3::LoadQueueEntry *this,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *bytes,
        Scaleform::GFx::AS3::Instances::fl::XMLList *loader,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  __int64 v9; // rax
  Scaleform::String src; // [rsp+68h] [rbp+10h] BYREF
  int v11; // [rsp+78h] [rbp+20h] BYREF

  Scaleform::String::String(&src, &customCaption);
  this->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable;
  Scaleform::String::String(&this->URL);
  this->Type = (src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) == -12i64;
  this->Method = method;
  this->pNext = 0i64;
  Scaleform::String::operator=(&this->URL, &src);
  this->EntryTime = -1;
  *(_WORD *)&this->QuietOpen = 0;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::AS3::LoadQueueEntry::`vftable;
  this->mLoader.pObject = 0i64;
  this->mURLLoader.pObject = 0i64;
  this->mURLRequest.pObject = 0i64;
  this->mBytes.pObject = 0i64;
  this->mBytes.Owner = 1;
  this->NotifyLoadInitCInterface.pObject = 0i64;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->mLoader,
    loader);
  this->FirstExec = 1;
  pObject = (Scaleform::Render::RenderBuffer *)this->NotifyLoadInitCInterface.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->NotifyLoadInitCInterface.pObject = 0i64;
  v11 = 2;
  v9 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::LoadQueueEntry *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
         Scaleform::Memory::pGlobalHeap,
         this,
         24i64,
         &v11,
         -2i64);
  src.pData = (Scaleform::String::DataDesc *)v9;
  if ( v9 )
  {
    *(_QWORD *)v9 = 0i64;
    *(_QWORD *)(v9 + 8) = 0i64;
    *(_QWORD *)(v9 + 16) = 0i64;
  }
  else
  {
    v9 = 0i64;
  }
  Scaleform::AutoPtr<Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::operator=(
    &this->mBytes,
    (Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)v9);
  Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this->mBytes.pObject,
    bytes->Length);
  memmove(this->mBytes.pObject->Data.Data, bytes->Data.Data.Data, this->mBytes.pObject->Data.Size);
}

// File Line: 3094
// RVA: 0x77F5E0
void __fastcall Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(
        Scaleform::GFx::AS3::LoadQueueEntry *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *request,
        Scaleform::GFx::AS3::Instances::fl::XMLList *loader,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        bool quietOpen)
{
  char *vfptr; // rdx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::String src; // [rsp+58h] [rbp+10h] BYREF

  if ( request )
    vfptr = (char *)request->TargetObject.pObject->vfptr;
  else
    vfptr = &customCaption;
  Scaleform::String::String(&src, vfptr);
  this->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable;
  Scaleform::String::String(&this->URL);
  this->Type = LT_LoadText;
  this->Method = method;
  this->pNext = 0i64;
  Scaleform::String::operator=(&this->URL, &src);
  this->EntryTime = -1;
  this->QuietOpen = quietOpen;
  this->Canceled = 0;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::AS3::LoadQueueEntry::`vftable;
  this->mLoader.pObject = 0i64;
  this->mURLLoader.pObject = 0i64;
  this->mURLRequest.pObject = 0i64;
  this->mBytes.pObject = 0i64;
  this->mBytes.Owner = 1;
  this->NotifyLoadInitCInterface.pObject = 0i64;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->mURLLoader,
    loader);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->mURLRequest,
    request);
  this->FirstExec = 1;
  pObject = (Scaleform::Render::RenderBuffer *)this->NotifyLoadInitCInterface.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->NotifyLoadInitCInterface.pObject = 0i64;
}

// File Line: 3102
// RVA: 0x78C430
void __fastcall Scaleform::GFx::AS3::LoadQueueEntry::~LoadQueueEntry(Scaleform::GFx::AS3::LoadQueueEntry *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v4; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v6; // rcx
  unsigned int v7; // eax
  Scaleform::GFx::AS3::Instances::fl_display::Loader *v8; // rcx
  unsigned int v9; // eax

  this->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::AS3::LoadQueueEntry::`vftable;
  if ( this->NotifyLoadInitCInterface.pObject )
  {
    pObject = (Scaleform::Render::RenderBuffer *)this->NotifyLoadInitCInterface.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->NotifyLoadInitCInterface.pObject = 0i64;
  }
  v3 = (Scaleform::Render::RenderBuffer *)this->NotifyLoadInitCInterface.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  Scaleform::AutoPtr<Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::~AutoPtr<Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>(&this->mBytes);
  v4 = this->mURLRequest.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->mURLRequest.pObject = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)((char *)v4 - 1);
    }
    else
    {
      RefCount = v4->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v4->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
  }
  v6 = this->mURLLoader.pObject;
  if ( v6 )
  {
    if ( ((unsigned __int8)v6 & 1) != 0 )
    {
      this->mURLLoader.pObject = (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)((char *)v6 - 1);
    }
    else
    {
      v7 = v6->RefCount;
      if ( (v7 & 0x3FFFFF) != 0 )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
      }
    }
  }
  v8 = this->mLoader.pObject;
  if ( v8 )
  {
    if ( ((unsigned __int8)v8 & 1) != 0 )
    {
      this->mLoader.pObject = (Scaleform::GFx::AS3::Instances::fl_display::Loader *)((char *)v8 - 1);
    }
    else
    {
      v9 = v8->RefCount;
      if ( (v9 & 0x3FFFFF) != 0 )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
      }
    }
  }
  this->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->URL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 3110
// RVA: 0x77F700
void __fastcall Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie::LoadQueueEntryMT_LoadMovie(
        Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *this,
        Scaleform::GFx::AS3::LoadQueueEntry *pqueueEntry,
        Scaleform::GFx::MovieImpl *pmovieRoot)
{
  Scaleform::GFx::MoviePreloadTask *v5; // rbp
  bool v6; // di
  Scaleform::GFx::InteractiveObject *pMainMovie; // rcx
  __int64 v8; // rax
  Scaleform::GFx::TaskManager *v9; // rax
  Scaleform::GFx::MoviePreloadTask *v10; // rax
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Ptr<Scaleform::GFx::TaskManager> *TaskManager; // rax
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+78h] [rbp+20h] BYREF

  Scaleform::GFx::LoadQueueEntryMT::LoadQueueEntryMT(this, pqueueEntry, pmovieRoot);
  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie::`vftable;
  v5 = 0i64;
  this->pPreloadTask.pObject = 0i64;
  this->CharSwitched = 0;
  this->FirstFrameLoaded = 0;
  this->BytesLoaded = 0;
  v6 = 0;
  pMainMovie = this->pMovieImpl->pASMovieRoot.pObject->pMovieImpl->pMainMovie;
  if ( pMainMovie )
  {
    v8 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(pMainMovie);
    v6 = ((*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 88i64))(v8) & 0x10) != 0;
  }
  v9 = (Scaleform::GFx::TaskManager *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                        Scaleform::Memory::pGlobalHeap,
                                        80i64);
  result.pObject = v9;
  if ( v9 )
  {
    Scaleform::GFx::MoviePreloadTask::MoviePreloadTask(
      (Scaleform::GFx::MoviePreloadTask *)v9,
      this->pMovieImpl,
      &pqueueEntry->URL,
      v6,
      pqueueEntry->QuietOpen);
    v5 = v10;
  }
  pObject = (Scaleform::Render::RenderBuffer *)this->pPreloadTask.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pPreloadTask.pObject = v5;
  TaskManager = Scaleform::GFx::StateBag::GetTaskManager(&this->pMovieImpl->Scaleform::GFx::StateBag, &result);
  TaskManager->pObject->vfptr[1].__vecDelDtor(TaskManager->pObject, (unsigned int)this->pPreloadTask.pObject);
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
}

// File Line: 3133
// RVA: 0x7F9CE0
char __fastcall Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie::LoadFinished(
        Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *this)
{
  bool IsDone; // al
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // rbx
  Scaleform::GFx::AS3::MovieRoot *pObject; // r12
  SSExpressionBase *Heap; // rax
  Scaleform::GFx::MovieDefImpl *v6; // rdi
  Scaleform::GFx::LoadQueueEntryVtbl *vfptr; // rcx
  Scaleform::GFx::LogState *v8; // rdi
  const char *v9; // rdi
  Scaleform::GFx::LogState *v10; // rsi
  Scaleform::GFx::LoadQueueEntryVtbl *v11; // rcx
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *vecDelDtor; // rcx
  Scaleform::GFx::LoadQueueEntryVtbl *v13; // rcx
  unsigned __int64 BytesLoaded; // rdx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v15; // rcx
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v16; // r14
  Scaleform::GFx::AS3::ASVM *v17; // rcx
  Scaleform::GFx::ASSupport *v18; // rcx
  Scaleform::GFx::Sprite *v19; // r13
  Scaleform::GFx::AS3::AvmDisplayObj *v20; // r15
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v21; // rcx
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v22; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // rcx
  char *v25; // rcx
  __int64 v26; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v27; // rcx
  Scaleform::GFx::Resource *v28; // rcx
  unsigned int v29; // eax
  Scaleform::GFx::MovieDefImpl::BindTaskData *v30; // rcx
  void *(__fastcall *v31)(Scaleform::GFx::LoadQueueEntry *, unsigned int); // r15
  Scaleform::GFx::ASSupport *v32; // rcx
  Scaleform::GFx::AS3::AvmBitmap *v33; // rsi
  Scaleform::GFx::MovieDataDef *v34; // rdx
  Scaleform::GFx::Resource *Resource; // rax
  Scaleform::GFx::ImageResource *v36; // rdi
  Scaleform::GFx::AS3::AvmDisplayObj *v37; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v38; // rcx
  char *v39; // rcx
  __int64 v40; // rax
  Scaleform::GFx::Resource *v41; // rcx
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v43; // rcx
  Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC> v44; // [rsp+30h] [rbp-69h] BYREF
  Scaleform::GFx::ResourceHandle phandle; // [rsp+38h] [rbp-61h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC> pnLoadInitCL; // [rsp+48h] [rbp-51h] BYREF
  Scaleform::GFx::Sprite *v47; // [rsp+50h] [rbp-49h]
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [rsp+58h] [rbp-41h] BYREF
  Scaleform::Ptr<Scaleform::GFx::LogState> v49; // [rsp+60h] [rbp-39h] BYREF
  __int64 v50[3]; // [rsp+68h] [rbp-31h] BYREF
  __int64 v51[14]; // [rsp+80h] [rbp-19h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC> *p_pnLoadInitCL; // [rsp+100h] [rbp+67h] BYREF
  int v53; // [rsp+108h] [rbp+6Fh] BYREF
  void *(__fastcall *rid)(Scaleform::GFx::LoadQueueEntry *, unsigned int); // [rsp+110h] [rbp+77h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> v55; // [rsp+118h] [rbp+7Fh] BYREF

  v51[4] = -2i64;
  IsDone = Scaleform::GFx::MoviePreloadTask::IsDone(this->pPreloadTask.pObject);
  pQueueEntry = this->pQueueEntry;
  if ( pQueueEntry->Canceled && IsDone )
    return 1;
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieImpl->pASMovieRoot.pObject;
  if ( IsDone )
  {
    Heap = Scaleform::GFx::MovieImpl::GetHeap((SSClosureInfoMethod *)this->pPreloadTask.pObject);
    v6 = (Scaleform::GFx::MovieDefImpl *)Heap;
    if ( !Heap )
    {
      Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
        (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pQueueEntry[1].vfptr,
        **(const char ***)(*(_QWORD *)&pQueueEntry[1].Type + 56i64));
      vfptr = pQueueEntry[2].vfptr;
      if ( vfptr )
        (*((void (__fastcall **)(Scaleform::GFx::LoadQueueEntryVtbl *))vfptr->__vecDelDtor + 3))(vfptr);
      LOBYTE(pQueueEntry[2].pNext) = 0;
      return 1;
    }
    if ( LOBYTE(pQueueEntry[2].pNext) )
    {
      if ( ((unsigned int (__fastcall *)(SSExpressionBase *))Heap->vfptr->invoke)(Heap) != -1
        && (((unsigned int (__fastcall *)(Scaleform::GFx::MovieDefImpl *))v6->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[1].__vecDelDtor)(v6) < 9
         || (char)((v6->pBindData.pObject->pDataDef.pObject->pData.pObject->FileAttributes & 8 | 0x10) >> 3) < 3) )
      {
        this->pQueueEntry->Canceled = 1;
        v8 = Scaleform::GFx::StateBag::GetLogState(&pObject->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
        if ( result.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
        if ( v8 && !pQueueEntry->QuietOpen )
        {
          v9 = **(const char ***)(*(_QWORD *)&pQueueEntry[1].Type + 56i64);
          v10 = Scaleform::GFx::StateBag::GetLogState(&pObject->pMovieImpl->Scaleform::GFx::StateBag, &v49)->pObject;
          if ( v49.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v49.pObject);
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
            &v10->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
            "Failed loading SWF \"%s\": ActionScript version mismatch",
            v9);
        }
        Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
          (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pQueueEntry[1].vfptr,
          **(const char ***)(*(_QWORD *)&pQueueEntry[1].Type + 56i64));
        v11 = pQueueEntry[2].vfptr;
        if ( v11 )
          (*((void (__fastcall **)(Scaleform::GFx::LoadQueueEntryVtbl *))v11->__vecDelDtor + 3))(v11);
        return 1;
      }
      vecDelDtor = (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pQueueEntry[1].vfptr[14].__vecDelDtor;
      if ( vecDelDtor )
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteOpenEvent(vecDelDtor);
      v13 = pQueueEntry[2].vfptr;
      if ( v13 )
        (*((void (__fastcall **)(Scaleform::GFx::LoadQueueEntryVtbl *))v13->__vecDelDtor + 1))(v13);
      LOBYTE(pQueueEntry[2].pNext) = 0;
      Scaleform::GFx::AS3::MovieRoot::AddLoadedMovieDef(pObject, v6);
    }
    if ( !this->CharSwitched )
      this->CharSwitched = 1;
    if ( this->BytesLoaded != v6->pBindData.pObject->BytesLoaded )
    {
      BytesLoaded = v6->pBindData.pObject->BytesLoaded;
      this->BytesLoaded = BytesLoaded;
      v15 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)pQueueEntry[1].vfptr[14].__vecDelDtor;
      if ( v15 )
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteProgressEvent(
          v15,
          BytesLoaded,
          v6->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.FileLength);
    }
    v16 = 0i64;
    if ( !this->FirstFrameLoaded && (v6->pBindData.pObject->BindState & 0x100) != 0 )
    {
      if ( v6->pBindData.pObject->pDataDef.pObject->MovieType == MT_Flash )
      {
        rid = pQueueEntry[1].vfptr[11].__vecDelDtor;
        v47 = 0i64;
        v17 = pObject->pAVM.pObject;
        if ( v17 )
          Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(
            v17->GC.GC,
            (Scaleform::GFx::Resource *)this->pMovieImpl->AdvanceStats.pObject,
            0);
        v51[0] = (__int64)v6->pBindData.pObject->pDataDef.pObject;
        v51[1] = (__int64)v6;
        v51[2] = 0i64;
        v18 = pObject->pASSupport.pObject;
        LODWORD(p_pnLoadInitCL) = 0;
        v19 = (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, __int64 *, _QWORD, Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC> **, int))v18->vfptr[4].__vecDelDtor)(
                                          v18,
                                          this->pMovieImpl,
                                          v51,
                                          0i64,
                                          &p_pnLoadInitCL,
                                          3);
        v47 = v19;
        Scaleform::GFx::Sprite::SetLoadedSeparately(v19, 1);
        v19->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Flags |= 1u;
        ((void (__fastcall *)(Scaleform::GFx::Sprite *))v19->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[73].__vecDelDtor)(v19);
        Scaleform::GFx::InteractiveObject::AddToPlayList(v19);
        v20 = (Scaleform::GFx::AS3::AvmDisplayObj *)((char *)v19 + 4 * (unsigned __int8)v19->AvmObjOffset);
        v21 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)pQueueEntry[1].vfptr[14].__vecDelDtor;
        if ( v21 )
        {
          Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::applicationDomainGet(v21, &v55);
          if ( v55.pObject && Scaleform::GFx::AS3::VMAppDomain::Enabled )
            v20->AppDomain = v55.pObject->VMDomain.pObject;
          v22 = v55.pObject;
          if ( v55.pObject )
          {
            if ( ((__int64)v55.pObject & 1) != 0 )
            {
              --v55.pObject;
            }
            else
            {
              RefCount = v55.pObject->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v55.pObject->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v22);
              }
            }
          }
        }
        ((void (__fastcall *)(Scaleform::GFx::AS3::AvmDisplayObj *, _QWORD))v20->vfptr[2].ToAvmButttonBase)(v20, 0i64);
        ((void (__fastcall *)(Scaleform::GFx::Sprite *))v19->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[39].__vecDelDtor)(v19);
        if ( !v20->pAS3RawPtr
          && !v20->pAS3CollectiblePtr.pObject
          && Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(v20) )
        {
          pAS3RawPtr = v20->pAS3RawPtr;
          if ( !pAS3RawPtr )
            pAS3RawPtr = v20->pAS3CollectiblePtr.pObject;
          if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
            pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&pAS3RawPtr->pLoaderInfo,
            (Scaleform::GFx::AS3::Instances::fl::XMLList *)pQueueEntry[1].vfptr[14].__vecDelDtor);
          Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(v20, 1);
        }
        if ( !rid
          || (v25 = (char *)rid + 4 * *((unsigned __int8 *)rid + 109),
              v26 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v25 + 40i64))(v25),
              v27 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v26 - 72),
              !v26) )
        {
          v27 = 0i64;
        }
        Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(v27, v19);
        pObject->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[39].__vecDelDtor(
          pObject,
          (unsigned int)v19);
        Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Sprite>(v19);
        ((void (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *))pObject->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[7].__vecDelDtor)(pObject);
        p_pnLoadInitCL = &pnLoadInitCL;
        v28 = (Scaleform::GFx::Resource *)pQueueEntry[2].vfptr;
        if ( v28 )
          Scaleform::Render::RenderBuffer::AddRef(v28);
        pnLoadInitCL.pObject = (Scaleform::GFx::AS3::NotifyLoadInitC *)pQueueEntry[2].vfptr;
        Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueInitEvent(
          (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pQueueEntry[1].vfptr,
          v19,
          (Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC>)&pnLoadInitCL);
        Scaleform::RefCountNTSImpl::Release(v19);
      }
      this->FirstFrameLoaded = 1;
    }
    v29 = v6->pBindData.pObject->BindState & 0xF;
    if ( v29 > 1 )
    {
      if ( v29 == 2 )
      {
        v30 = v6->pBindData.pObject;
        if ( v30->pDataDef.pObject->MovieType == MT_Image )
        {
          v31 = pQueueEntry[1].vfptr[11].__vecDelDtor;
          v50[0] = (__int64)v30->pDataDef.pObject;
          v50[1] = (__int64)v6;
          v50[2] = 0i64;
          v32 = pObject->pASSupport.pObject;
          v53 = 0x40000;
          v33 = (Scaleform::GFx::AS3::AvmBitmap *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, __int64 *, _QWORD, int *, int))v32->vfptr[4].__vecDelDtor)(
                                                    v32,
                                                    pObject->pMovieImpl,
                                                    v50,
                                                    0i64,
                                                    &v53,
                                                    8);
          v51[3] = (__int64)v33;
          phandle.HType = RH_Pointer;
          phandle.pResource = 0i64;
          v34 = v6->pBindData.pObject->pDataDef.pObject;
          LODWORD(rid) = 0;
          if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
                 v34->pData.pObject,
                 &phandle,
                 (Scaleform::GFx::ResourceId)&rid) )
          {
            Resource = Scaleform::GFx::ResourceHandle::GetResource(&phandle, &v6->pBindData.pObject->ResourceBinding);
            v36 = (Scaleform::GFx::ImageResource *)Resource;
            if ( Resource )
            {
              if ( (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))Resource->vfptr->GetResourceTypeCode)(Resource) & 0xFF00) == 256 )
                Scaleform::GFx::AS3::AvmBitmap::SetImage(v33, v36);
            }
          }
          if ( v33 )
            v37 = (Scaleform::GFx::AS3::AvmDisplayObj *)((char *)v33 + 4 * (unsigned __int8)v33->AvmObjOffset);
          else
            v37 = 0i64;
          if ( !v37->pAS3RawPtr
            && !v37->pAS3CollectiblePtr.pObject
            && Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(v37) )
          {
            v38 = v37->pAS3RawPtr;
            if ( !v38 )
              v38 = v37->pAS3CollectiblePtr.pObject;
            if ( ((unsigned __int8)v38 & 1) != 0 )
              v38 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v38 - 1);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v38->pLoaderInfo,
              (Scaleform::GFx::AS3::Instances::fl::XMLList *)pQueueEntry[1].vfptr[14].__vecDelDtor);
            Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(v37, 1);
          }
          if ( v31 )
          {
            v39 = (char *)v31 + 4 * *((unsigned __int8 *)v31 + 109);
            v40 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v39 + 40i64))(v39);
            if ( v40 )
              v16 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v40 - 72);
          }
          Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(v16, (Scaleform::GFx::DisplayObjContainer *)v33);
          p_pnLoadInitCL = &v44;
          v41 = (Scaleform::GFx::Resource *)pQueueEntry[2].vfptr;
          if ( v41 )
            Scaleform::Render::RenderBuffer::AddRef(v41);
          v44.pObject = (Scaleform::GFx::AS3::NotifyLoadInitC *)pQueueEntry[2].vfptr;
          Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueInitEvent(
            (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pQueueEntry[1].vfptr,
            v33,
            (Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC>)&v44);
          if ( phandle.HType == RH_Pointer && phandle.pResource )
            Scaleform::GFx::Resource::Release(phandle.pResource);
          if ( v33 )
            Scaleform::RefCountNTSImpl::Release(v33);
        }
        Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueCompleteEvent((Scaleform::GFx::AS3::Instances::fl_display::Loader *)pQueueEntry[1].vfptr);
      }
      else if ( v29 - 3 <= 1 )
      {
        Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
          (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pQueueEntry[1].vfptr,
          **(const char ***)(*(_QWORD *)&pQueueEntry[1].Type + 56i64));
        LOBYTE(pQueueEntry[2].pNext) = 0;
      }
      return 1;
    }
  }
  else if ( LOBYTE(pQueueEntry[2].pNext) )
  {
    v43 = (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pQueueEntry[1].vfptr[14].__vecDelDtor;
    if ( v43 )
      Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteOpenEvent(v43);
    LOBYTE(pQueueEntry[2].pNext) = 0;
  }
  return 0;
}

// File Line: 3381
// RVA: 0x7ADCB0
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddLoadQueueEntryMT(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::LoadQueueEntry *pentry)
{
  Scaleform::GFx::LoadQueueEntry::LoadType Type; // eax
  Scaleform::GFx::LoadQueueEntryMT_LoadVars *v5; // rax
  Scaleform::GFx::LoadQueueEntryMT *v6; // rax
  Scaleform::GFx::LoadQueueEntryMT *v7; // rdx
  bool v8; // zf
  Scaleform::MemoryHeap *pHeap; // rcx
  Scaleform::MemoryHeapVtbl *vfptr; // rax
  Scaleform::GFx::LoadQueueEntryMT_LoadBinary *v11; // rax
  Scaleform::GFx::LoadQueueEntryMT *v12; // rax
  Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *v13; // rax
  Scaleform::GFx::LoadQueueEntryMT *v14; // rax
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // r9
  Scaleform::GFx::LoadQueueEntryMT *i; // rcx
  Scaleform::GFx::LoadQueueEntry *v17; // rax
  Scaleform::GFx::LoadQueueEntryVtbl *v18; // r8
  Scaleform::GFx::LoadQueueEntry *pNext; // r8

  Type = pentry->Type;
  if ( (Type & 4) != 0 )
  {
    v5 = (Scaleform::GFx::LoadQueueEntryMT_LoadVars *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, __int64))this->pMovieImpl->pHeap->vfptr->Alloc)(
                                                        this,
                                                        56i64);
    if ( v5 )
    {
      Scaleform::GFx::LoadQueueEntryMT_LoadVars::LoadQueueEntryMT_LoadVars(v5, pentry, this->pMovieImpl);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
  }
  else
  {
    v8 = (Type & 0x20) == 0;
    pHeap = this->pMovieImpl->pHeap;
    vfptr = pHeap->vfptr;
    if ( v8 )
    {
      v13 = (Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *)vfptr->Alloc(pHeap, 64ui64, 0i64);
      if ( v13 )
      {
        Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie::LoadQueueEntryMT_LoadMovie(v13, pentry, this->pMovieImpl);
        v7 = v14;
      }
      else
      {
        v7 = 0i64;
      }
      if ( !v7 )
        goto LABEL_22;
      pQueueEntry = v7->pQueueEntry;
      for ( i = this->pMovieImpl->pLoadQueueMTHead; i; i = i->pNext )
      {
        v17 = i->pQueueEntry;
        v18 = v17[1].vfptr;
        if ( !v18 || v18 != pQueueEntry[1].vfptr )
        {
          pNext = v17[1].pNext;
          if ( !pNext || pNext != pQueueEntry[1].pNext )
            continue;
        }
        v17->Canceled = 1;
      }
    }
    else
    {
      v11 = (Scaleform::GFx::LoadQueueEntryMT_LoadBinary *)vfptr->Alloc(pHeap, 56ui64, 0i64);
      if ( v11 )
      {
        Scaleform::GFx::LoadQueueEntryMT_LoadBinary::LoadQueueEntryMT_LoadBinary(v11, pentry, this->pMovieImpl);
        v7 = v12;
      }
      else
      {
        v7 = 0i64;
      }
    }
  }
  if ( v7 )
  {
    Scaleform::GFx::MovieImpl::AddLoadQueueEntryMT(this->pMovieImpl, v7);
    return;
  }
LABEL_22:
  pentry->vfptr->__vecDelDtor(pentry, 1i64);
}

// File Line: 3467
// RVA: 0x7AE170
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddNewLoadQueueEntry(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *urlRequest,
        Scaleform::GFx::AS3::Instances::fl::XMLList *loader,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  Scaleform::GFx::TaskManager *v8; // rbx
  Scaleform::GFx::TaskManager *v9; // rax
  Scaleform::GFx::AS3::LoadQueueEntry *v10; // rax
  Scaleform::GFx::AS3::LoadQueueEntry *v11; // rdi
  bool IsProtocolImage; // bp
  Scaleform::GFx::TaskManager *v13; // rbp
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdx
  Scaleform::GFx::LoaderImpl *pObject; // rbx
  Scaleform::GFx::StateBag *v16; // rax
  Scaleform::GFx::TaskManager *v17; // rax
  bool v18; // bp
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+38h] [rbp-30h] BYREF
  __int64 v20; // [rsp+40h] [rbp-28h]
  Scaleform::MemoryHeap *sync; // [rsp+70h] [rbp+8h] BYREF

  v20 = -2i64;
  v8 = 0i64;
  sync = this->pMovieImpl->pHeap;
  v9 = (Scaleform::GFx::TaskManager *)sync->vfptr->Alloc((Scaleform::MemoryHeap *)this, 96ui64, 0i64);
  result.pObject = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(
      (Scaleform::GFx::AS3::LoadQueueEntry *)v9,
      urlRequest,
      loader,
      method,
      0);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  if ( v11 )
  {
    IsProtocolImage = Scaleform::GFx::LoaderImpl::IsProtocolImage(&v11->URL, 0i64, (bool *)&sync);
    if ( IsProtocolImage && (_BYTE)sync )
    {
      v13 = (Scaleform::GFx::TaskManager *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                             Scaleform::Memory::pGlobalHeap,
                                             144i64,
                                             0i64);
      result.pObject = v13;
      if ( v13 )
      {
        pMovieImpl = this->pMovieImpl;
        pObject = pMovieImpl->pMainMovieDef.pObject->pLoaderImpl.pObject;
        v16 = (Scaleform::GFx::StateBag *)pMovieImpl->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::vfptr->GetStateBagImpl(&pMovieImpl->Scaleform::GFx::StateBag);
        Scaleform::GFx::LoadStates::LoadStates((Scaleform::GFx::LoadStates *)v13, pObject, v16, 0i64);
        v8 = v17;
      }
      result.pObject = v8;
      ((void (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, Scaleform::GFx::AS3::LoadQueueEntry *, Scaleform::GFx::TaskManager *))this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[35].__vecDelDtor)(
        this,
        v11,
        v8);
      v11->vfptr->__vecDelDtor(v11, 1u);
      if ( v8 )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v8);
    }
    else
    {
      v18 = 0;
      if ( Scaleform::String::GetLength(&v11->URL) )
      {
        if ( !IsProtocolImage )
        {
          LOBYTE(v8) = 1;
          if ( Scaleform::GFx::StateBag::GetTaskManager(&this->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject )
            v18 = 1;
        }
      }
      if ( ((unsigned __int8)v8 & 1) != 0 && result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
      if ( v18 )
        Scaleform::GFx::AS3::MovieRoot::AddLoadQueueEntryMT(this, v11);
      else
        Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, v11);
    }
  }
}

// File Line: 3497
// RVA: 0x7AE0E0
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddNewLoadQueueEntry(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *bytes,
        Scaleform::GFx::AS3::Instances::fl::XMLList *loader,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  Scaleform::GFx::AS3::LoadQueueEntry *v8; // rax

  v8 = (Scaleform::GFx::AS3::LoadQueueEntry *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, __int64))this->pMovieImpl->pHeap->vfptr->Alloc)(
                                                this,
                                                96i64);
  if ( v8 )
    Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(v8, bytes, loader, method);
  if ( v8 )
    Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, v8);
}

// File Line: 3510
// RVA: 0x7AE320
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddNewLoadQueueEntry(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *urlRequest,
        Scaleform::GFx::AS3::Instances::fl::XMLList *loader,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  char v8; // bl
  Scaleform::GFx::AS3::LoadQueueEntry *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rdi
  __int64 v12; // rax
  char v13; // cl
  bool v14; // zf
  int v15; // eax
  bool v16; // si
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+70h] [rbp+8h] BYREF

  v8 = 0;
  result.pObject = (Scaleform::GFx::TaskManager *)this->pMovieImpl->pHeap;
  v9 = (Scaleform::GFx::AS3::LoadQueueEntry *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, __int64, _QWORD))result.pObject->vfptr[10].__vecDelDtor)(
                                                this,
                                                96i64,
                                                0i64);
  if ( v9 )
  {
    Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(v9, urlRequest, loader, method, 0);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  if ( v11 )
  {
    v12 = 0i64;
    while ( 1 )
    {
      v13 = *((_BYTE *)&loader[1].pNext->Scaleform::GFx::AS3::Instances::fl::Object::Scaleform::GFx::AS3::Instance::Scaleform::GFx::AS3::Object::Scaleform::GFx::AS3::GASRefCountBase::Scaleform::GFx::AS3::RefCountBaseGC<328>::$CBB44125B27995AEB5908B7872D4CF4F::vfptr->ForEachChild_GC
            + v12++);
      v14 = v13 == aBinary_0[v12 - 1];
      if ( v13 != aBinary_0[v12 - 1] )
        break;
      if ( v12 == 7 )
      {
        v14 = v13 == aBinary_0[6];
        break;
      }
    }
    v15 = 4;
    if ( v14 )
      v15 = 32;
    *(_DWORD *)(v11 + 16) = v15;
    v16 = 0;
    if ( Scaleform::String::GetLength((Scaleform::String *)(v11 + 24)) )
    {
      v8 = 1;
      if ( Scaleform::GFx::StateBag::GetTaskManager(&this->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject )
        v16 = 1;
    }
    if ( (v8 & 1) != 0 && result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( v16 )
      Scaleform::GFx::AS3::MovieRoot::AddLoadQueueEntryMT(this, (Scaleform::GFx::AS3::LoadQueueEntry *)v11);
    else
      Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, (Scaleform::GFx::LoadQueueEntry *)v11);
  }
}

// File Line: 3549
// RVA: 0x7F0420
Scaleform::Render::Text::Allocator *__fastcall Scaleform::GFx::AS3::MovieRoot::GetTextAllocator(
        Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::MemoryContextImpl *pObject; // rcx
  Scaleform::Render::Text::Allocator *v3; // rax
  Scaleform::Render::Text::Allocator *v4; // rax
  Scaleform::Render::Text::Allocator *v5; // rsi
  Scaleform::GFx::AS3::MemoryContextImpl *v6; // rdi
  Scaleform::RefCountNTSImpl *v7; // rcx

  pObject = this->MemContext.pObject;
  if ( pObject->TextAllocator.pObject )
    return pObject->TextAllocator.pObject;
  v3 = (Scaleform::Render::Text::Allocator *)pObject->Heap->vfptr->Alloc(
                                               (Scaleform::MemoryHeap *)pObject,
                                               144ui64,
                                               0i64);
  if ( v3 )
  {
    Scaleform::Render::Text::Allocator::Allocator(v3, this->MemContext.pObject->Heap, 0);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = this->MemContext.pObject;
  v7 = v6->TextAllocator.pObject;
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
  v6->TextAllocator.pObject = v5;
  return this->MemContext.pObject->TextAllocator.pObject;
}

// File Line: 3558
// RVA: 0x809290
void __fastcall Scaleform::GFx::AS3::MovieRoot::ProcessLoadQueueEntry(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *pentry,
        Scaleform::GFx::LoadStates *pls)
{
  char v6; // si
  __int64 v7; // r14
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx
  const char *v9; // rax
  Scaleform::File *v10; // rbx
  Scaleform::GFx::LoadQueueEntry *pNext; // rdi
  __int64 v12; // rcx
  char v13; // al
  __int64 v14; // rcx
  char v15; // al
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v16; // rbx
  __int64 v17; // rcx
  char v18; // al
  char v19; // al
  Scaleform::String::DataDesc *v20; // rdx
  Scaleform::GFx::LogState *pObject; // rbx
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v22; // r14
  Scaleform::GFx::MovieDefImpl *ImageMovieDef; // rsi
  Scaleform::GFx::MovieImpl *v24; // rdx
  Scaleform::GFx::InteractiveObject *pMainMovie; // rcx
  __int64 v26; // rax
  Scaleform::String *UrlStrGfx; // rax
  Scaleform::MemoryHeap *pHeap; // rdx
  Scaleform::GFx::ImageFileHandlerRegistry *v29; // rsi
  Scaleform::MemoryHeap *v30; // rcx
  Scaleform::GFx::LogState *v31; // rax
  Scaleform::Log *GlobalLog; // rax
  __int64 v33; // rcx
  Scaleform::Render::Image *v34; // rsi
  Scaleform::GFx::ImageResource *v35; // rax
  Scaleform::GFx::ImageResource *v36; // rax
  Scaleform::GFx::ImageResource *v37; // rbx
  unsigned int v38; // esi
  Scaleform::String::DataDesc *v39; // rdx
  Scaleform::GFx::MovieImpl *v40; // rcx
  const char *v41; // rax
  Scaleform::GFx::LoadQueueEntryVtbl *v42; // rcx
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::LoadQueueEntry *, unsigned int); // rcx
  Scaleform::GFx::LoadQueueEntryVtbl *v44; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v45; // rcx
  Scaleform::GFx::ASSupport *v46; // rcx
  Scaleform::GFx::AS3::AvmBitmap *v47; // rbx
  Scaleform::GFx::MovieDataDef *v48; // rcx
  Scaleform::GFx::Resource *Resource; // rax
  Scaleform::GFx::ImageResource *v50; // r12
  Scaleform::GFx::AS3::AvmDisplayObj *v51; // r13
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // rcx
  char *v53; // rcx
  __int64 v54; // rax
  Scaleform::GFx::AS3::ASVM *v55; // rcx
  void *(__fastcall *v56)(Scaleform::GFx::LoadQueueEntry *, unsigned int); // rcx
  Scaleform::GFx::ASSupport *v57; // rcx
  Scaleform::GFx::AS3::AvmDisplayObj *v58; // r13
  Scaleform::GFx::LoadQueueEntryVtbl *v59; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v60; // rcx
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v61; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v63; // rcx
  char *v64; // rcx
  __int64 v65; // rax
  Scaleform::GFx::Resource *v66; // rcx
  void *(__fastcall *v67)(Scaleform::GFx::LoadQueueEntry *, unsigned int); // rcx
  Scaleform::GFx::LoadQueueEntryVtbl *v68; // rcx
  void *(__fastcall *v69)(Scaleform::GFx::LoadQueueEntry *, unsigned int); // rcx
  Scaleform::GFx::LoadQueueEntryVtbl *vfptr; // rcx
  Scaleform::String url; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::Resource *v72; // [rsp+38h] [rbp-C8h]
  int pfileLen; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::MemoryHeap *v74; // [rsp+48h] [rbp-B8h]
  Scaleform::String v75; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::String src; // [rsp+58h] [rbp-A8h] BYREF
  Scaleform::String ppath; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::String pdest; // [rsp+68h] [rbp-98h] BYREF
  Scaleform::GFx::MovieDefImpl *ImageCreator; // [rsp+70h] [rbp-90h]
  Scaleform::String pdata; // [rsp+78h] [rbp-88h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> v81; // [rsp+80h] [rbp-80h] BYREF
  int v82; // [rsp+88h] [rbp-78h] BYREF
  int v83; // [rsp+8Ch] [rbp-74h] BYREF
  Scaleform::GFx::ResourceId rid; // [rsp+90h] [rbp-70h] BYREF
  Scaleform::GFx::AS3::AvmBitmap *v85; // [rsp+98h] [rbp-68h]
  Scaleform::String v86; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::GFx::ResourceHandle phandle; // [rsp+A8h] [rbp-58h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC> pnLoadInitCL; // [rsp+B8h] [rbp-48h] BYREF
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> binaryData; // [rsp+C0h] [rbp-40h] BYREF
  Scaleform::String result; // [rsp+D8h] [rbp-28h] BYREF
  __int64 v91[3]; // [rsp+E0h] [rbp-20h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+F8h] [rbp-8h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo v93; // [rsp+110h] [rbp+10h] BYREF
  Scaleform::File *v94; // [rsp+128h] [rbp+28h]
  Scaleform::GFx::URLBuilder::LocationInfo v95; // [rsp+130h] [rbp+30h] BYREF
  Scaleform::GFx::AS3::AvmBitmap *v96; // [rsp+148h] [rbp+48h]
  int v97; // [rsp+150h] [rbp+50h] BYREF
  Scaleform::MemoryHeap *v98; // [rsp+158h] [rbp+58h]
  int v99; // [rsp+160h] [rbp+60h]
  int v100; // [rsp+164h] [rbp+64h]
  Scaleform::Log *v101; // [rsp+168h] [rbp+68h]
  Scaleform::MemoryHeap *v102; // [rsp+170h] [rbp+70h]
  Scaleform::GFx::ImageFileHandlerRegistry *v103; // [rsp+178h] [rbp+78h]
  Scaleform::GFx::MovieImpl *v104; // [rsp+180h] [rbp+80h]
  __int64 v105[3]; // [rsp+188h] [rbp+88h] BYREF
  __int64 v106[8]; // [rsp+1A0h] [rbp+A0h] BYREF
  char dest[240]; // [rsp+1E0h] [rbp+E0h] BYREF
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *bilinear; // [rsp+628h] [rbp+528h] BYREF
  void *p_binaryData; // [rsp+638h] [rbp+538h]

  v106[3] = -2i64;
  if ( !pentry->Canceled )
  {
    if ( (pentry->Type & 0x24) != 0 )
    {
      v6 = 0;
      Scaleform::String::String(&pdata);
      bilinear = &binaryData;
      v7 = 0i64;
      memset(&binaryData, 0, sizeof(binaryData));
      pfileLen = 0;
      Scaleform::String::String(&ppath);
      pMovieImpl = this->pMovieImpl;
      if ( !pMovieImpl->pMainMovie
        || (v9 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))pMovieImpl->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(pMovieImpl->pMainMovieDef.pObject),
            Scaleform::String::operator=(&ppath, v9),
            !Scaleform::GFx::URLBuilder::ExtractFilePath(&ppath)) )
      {
        Scaleform::String::Clear(&ppath);
      }
      loc.Use = File_LoadVars;
      Scaleform::String::String(&loc.FileName, &pentry->URL);
      Scaleform::String::String(&loc.ParentPath, &ppath);
      Scaleform::String::String(&pdest);
      Scaleform::GFx::LoadStates::BuildURL(pls, &pdest, &loc);
      v10 = 0i64;
      v94 = 0i64;
      bilinear = (Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)v91;
      memset(v91, 0, sizeof(v91));
      if ( Scaleform::GFx::URLBuilder::IsProtocol(&pdest)
        || (v10 = Scaleform::GFx::LoadStates::OpenFile(
                    pls,
                    (const char *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                    0),
            (v94 = v10) == 0i64) )
      {
        Scaleform::SFsprintf(
          dest,
          0x400ui64,
          "Cant open %s",
          (const char *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteErrorEvent(
          (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext,
          dest);
        v6 = 1;
      }
      else
      {
        pNext = pentry[1].pNext;
        if ( !strcmp((const char *)pNext[3].vfptr->__vecDelDtor, "variables") )
        {
          Scaleform::GFx::MovieImpl::ReadTextData(&pdata, v10, &pfileLen, 1);
        }
        else
        {
          v12 = 0i64;
          while ( 1 )
          {
            v13 = *((_BYTE *)pNext[3].vfptr->__vecDelDtor + v12++);
            if ( v13 != aText_0[v12 - 1] )
              break;
            if ( v12 == 5 )
            {
              Scaleform::GFx::MovieImpl::ReadTextData(&pdata, v10, &pfileLen, 0);
              goto LABEL_19;
            }
          }
          v14 = 0i64;
          while ( 1 )
          {
            v15 = *((_BYTE *)pNext[3].vfptr->__vecDelDtor + v14++);
            if ( v15 != aBinary_0[v14 - 1] )
              break;
            if ( v14 == 7 )
            {
              Scaleform::GFx::MovieImpl::ReadBinaryData(&binaryData, v10, &pfileLen);
              break;
            }
          }
        }
      }
LABEL_19:
      bilinear = (Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)v91;
      if ( v91[0] )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      if ( v10 )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      if ( !v6 )
      {
        v16 = (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext;
        if ( !strcmp(v16->dataFormat.pNode->pData, "variables") )
        {
          Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetVariablesDataString(
            v16,
            (const char *)((pdata.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        }
        else
        {
          v17 = 0i64;
          while ( 1 )
          {
            v18 = v16->dataFormat.pNode->pData[v17++];
            if ( v18 != aText_0[v17 - 1] )
              break;
            if ( v17 == 5 )
            {
              Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetTextString(
                v16,
                (const char *)((pdata.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
              goto LABEL_41;
            }
          }
          while ( 1 )
          {
            v19 = v16->dataFormat.pNode->pData[v7++];
            if ( v19 != aBinary_0[v7 - 1] )
              break;
            if ( v7 == 7 )
            {
              Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetBinaryData(v16, &binaryData);
              break;
            }
          }
        }
LABEL_41:
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteOpenEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext);
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteProgressEvent(
          (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext,
          pfileLen,
          pfileLen);
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteCompleteEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext);
      }
      p_binaryData = &binaryData;
      if ( binaryData.Data.Data )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v20 = pdata.pData;
      goto LABEL_192;
    }
    Scaleform::String::String(&url, &pentry->URL);
    Scaleform::String::String(&src);
    pObject = pls->pLog.pObject;
    v22 = 0i64;
    ImageMovieDef = 0i64;
    v72 = 0i64;
    v24 = this->pMovieImpl;
    LODWORD(v74) = v24->pMainMovieDef.pObject->pBindData.pObject->LoadFlags;
    pMainMovie = v24->pMainMovie;
    if ( pMainMovie )
    {
      v26 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(pMainMovie);
      if ( ((*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 88i64))(v26) & 0x10) != 0 )
      {
        UrlStrGfx = Scaleform::GFx::GetUrlStrGfx(&result, &url);
        Scaleform::String::operator=(&src, UrlStrGfx);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        ImageMovieDef = (Scaleform::GFx::MovieDefImpl *)v72;
      }
    }
    LOBYTE(bilinear) = 0;
    LOBYTE(p_binaryData) = Scaleform::GFx::LoaderImpl::IsProtocolImage(&url, (bool *)&bilinear, 0i64);
    if ( (_BYTE)p_binaryData )
    {
      ImageCreator = (Scaleform::GFx::MovieDefImpl *)Scaleform::GFx::LoadStates::GetImageCreator(pls);
      if ( !ImageCreator )
      {
        if ( pObject )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
            &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
            "ImageCreator is not installed, failed to load image \"%s\"",
            (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
          (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].vfptr,
          (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        goto LABEL_106;
      }
      pHeap = this->pMovieImpl->pHeap;
      v97 = 0;
      v98 = pHeap;
      v99 = 1;
      v100 = 1;
      v101 = 0i64;
      v102 = 0i64;
      v103 = 0i64;
      v104 = 0i64;
      v29 = pls->pImageFileHandlerRegistry.pObject;
      v30 = (Scaleform::MemoryHeap *)pls->pBindStates.pObject->pFileOpener.pObject;
      v74 = v30;
      v31 = pls->pLog.pObject;
      if ( v31 )
      {
        GlobalLog = v31->pLog.pObject;
        if ( !GlobalLog )
        {
          GlobalLog = Scaleform::Log::GetGlobalLog();
          v30 = v74;
        }
      }
      else
      {
        GlobalLog = 0i64;
      }
      v102 = v30;
      v101 = GlobalLog;
      v103 = v29;
      v104 = this->pMovieImpl;
      Scaleform::String::String(&v86, (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      v34 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *, int *, Scaleform::String *))ImageCreator->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->GetKey)(
                                          ImageCreator,
                                          &v97,
                                          &v86);
      ImageCreator = (Scaleform::GFx::MovieDefImpl *)v34;
      v106[7] = (__int64)v34;
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v86.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      if ( !v34 )
      {
        if ( pObject )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
            &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
            "ImageCreator::LoadProtocolImage failed to load image \"%s\"",
            (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
          (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].vfptr,
          (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        goto LABEL_189;
      }
      v74 = this->pMovieImpl->pHeap;
      v35 = (Scaleform::GFx::ImageResource *)((__int64 (__fastcall *)(__int64, __int64))v74->vfptr->Alloc)(v33, 104i64);
      v106[6] = (__int64)v35;
      if ( v35 )
      {
        Scaleform::GFx::ImageResource::ImageResource(v35, v34, Use_Bitmap);
        v37 = v36;
      }
      else
      {
        v37 = 0i64;
      }
      v106[5] = (__int64)v37;
      if ( v37 )
      {
        ImageMovieDef = Scaleform::GFx::MovieImpl::CreateImageMovieDef(
                          this->pMovieImpl,
                          v37,
                          (bool)bilinear,
                          (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                          pls);
        v72 = ImageMovieDef;
      }
      else
      {
        ImageMovieDef = (Scaleform::GFx::MovieDefImpl *)v72;
      }
      if ( v37 )
        Scaleform::GFx::Resource::Release(v37);
      ImageCreator->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->GetResourceTypeCode(ImageCreator);
    }
    else
    {
      v38 = (unsigned int)v74 | 0x10001;
      if ( pentry->QuietOpen )
        v38 = (unsigned int)v74 | 0x210001;
      v39 = pentry[1].URL.pData;
      if ( v39 )
      {
        ImageMovieDef = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(
                          pls,
                          (Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)v39,
                          v38,
                          0i64,
                          0i64);
        v72 = ImageMovieDef;
      }
      else
      {
        Scaleform::String::String(&v75);
        v40 = this->pMovieImpl;
        if ( !v40->pMainMovie
          || (v41 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))v40->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(v40->pMainMovieDef.pObject),
              Scaleform::String::operator=(&v75, v41),
              !Scaleform::GFx::URLBuilder::ExtractFilePath(&v75)) )
        {
          Scaleform::String::Clear(&v75);
        }
        if ( !Scaleform::String::GetLength(&src) )
          goto LABEL_86;
        v93.Use = File_LoadMovie;
        Scaleform::String::String(&v93.FileName, &src);
        Scaleform::String::String(&v93.ParentPath, &v75);
        ImageCreator = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(pls, &v93, v38, 0i64);
        v72 = ImageCreator;
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v93.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                              + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v93.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        if ( !ImageCreator )
        {
LABEL_86:
          v95.Use = File_LoadMovie;
          Scaleform::String::String(&v95.FileName, &url);
          Scaleform::String::String(&v95.ParentPath, &v75);
          v72 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(pls, &v95, v38, 0i64);
          if ( !_InterlockedDecrement((volatile signed __int32 *)((v95.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                                + 8)) )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          if ( !_InterlockedDecrement((volatile signed __int32 *)((v95.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                                + 8)) )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        }
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v75.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        ImageMovieDef = (Scaleform::GFx::MovieDefImpl *)v72;
      }
      if ( !ImageMovieDef )
      {
        if ( pObject && !pentry->QuietOpen )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
            &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
            "Failed loading URL \"%s\"",
            (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
          (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].vfptr,
          (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        vfptr = pentry[2].vfptr;
        if ( vfptr )
          (*((void (__fastcall **)(Scaleform::GFx::LoadQueueEntryVtbl *))vfptr->__vecDelDtor + 3))(vfptr);
        goto LABEL_189;
      }
      if ( ((unsigned int (__fastcall *)(Scaleform::GFx::MovieDefImpl *))ImageMovieDef->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[1].__vecDelDtor)(ImageMovieDef) != -1
        && (((unsigned int (__fastcall *)(Scaleform::GFx::MovieDefImpl *))ImageMovieDef->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[1].__vecDelDtor)(ImageMovieDef) < 9
         || (char)((ImageMovieDef->pBindData.pObject->pDataDef.pObject->pData.pObject->FileAttributes & 8 | 0x10) >> 3) < 3) )
      {
        if ( pObject && !pentry->QuietOpen )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
            &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
            "Failed loading SWF \"%s\": ActionScript version mismatch",
            (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
          (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].vfptr,
          (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        v42 = pentry[2].vfptr;
        if ( v42 )
          (*((void (__fastcall **)(Scaleform::GFx::LoadQueueEntryVtbl *))v42->__vecDelDtor + 3))(v42);
        Scaleform::GFx::Resource::Release(ImageMovieDef);
        v72 = 0i64;
        goto LABEL_189;
      }
    }
    if ( ImageMovieDef )
      Scaleform::GFx::AS3::MovieRoot::AddLoadedMovieDef(this, ImageMovieDef);
LABEL_106:
    vecDelDtor = pentry[1].vfptr[14].__vecDelDtor;
    if ( vecDelDtor )
      Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteOpenEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)vecDelDtor);
    v44 = pentry[2].vfptr;
    if ( v44 )
      (*((void (__fastcall **)(Scaleform::GFx::LoadQueueEntryVtbl *))v44->__vecDelDtor + 1))(v44);
    v74 = (Scaleform::MemoryHeap *)pentry[1].vfptr[11].__vecDelDtor;
    v85 = 0i64;
    if ( ImageMovieDef && (v45 = ImageMovieDef->pBindData.pObject, v45->pDataDef.pObject->MovieType == MT_Image) )
    {
      v105[0] = (__int64)v45->pDataDef.pObject;
      v105[1] = (__int64)ImageMovieDef;
      v105[2] = 0i64;
      v46 = this->pASSupport.pObject;
      v83 = 0x40000;
      v47 = (Scaleform::GFx::AS3::AvmBitmap *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, __int64 *, _QWORD, int *, int))v46->vfptr[4].__vecDelDtor)(
                                                v46,
                                                this->pMovieImpl,
                                                v105,
                                                0i64,
                                                &v83,
                                                8);
      v106[4] = (__int64)v47;
      phandle.HType = RH_Pointer;
      phandle.pResource = 0i64;
      v48 = ImageMovieDef->pBindData.pObject->pDataDef.pObject;
      rid.Id = 0;
      if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
             v48->pData.pObject,
             &phandle,
             (Scaleform::GFx::ResourceId)&rid) )
      {
        Resource = Scaleform::GFx::ResourceHandle::GetResource(
                     &phandle,
                     &ImageMovieDef->pBindData.pObject->ResourceBinding);
        v50 = (Scaleform::GFx::ImageResource *)Resource;
        if ( Resource )
        {
          if ( (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))Resource->vfptr->GetResourceTypeCode)(Resource) & 0xFF00) == 256 )
            Scaleform::GFx::AS3::AvmBitmap::SetImage(v47, v50);
        }
      }
      if ( v47 )
        v51 = (Scaleform::GFx::AS3::AvmDisplayObj *)((char *)v47 + 4 * (unsigned __int8)v47->AvmObjOffset);
      else
        v51 = 0i64;
      if ( !v51->pAS3RawPtr
        && !v51->pAS3CollectiblePtr.pObject
        && Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(v51) )
      {
        pAS3RawPtr = v51->pAS3RawPtr;
        if ( !pAS3RawPtr )
          pAS3RawPtr = v51->pAS3CollectiblePtr.pObject;
        if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
          pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&pAS3RawPtr->pLoaderInfo,
          (Scaleform::GFx::AS3::Instances::fl::XMLList *)pentry[1].vfptr[14].__vecDelDtor);
        Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(v51, 1);
      }
      if ( v74 )
      {
        v53 = (char *)v74 + 4 * BYTE5(v74->Info.Desc.HeapId);
        v54 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v53 + 40i64))(v53);
        if ( v54 )
          v22 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v54 - 72);
      }
      Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(v22, (Scaleform::GFx::DisplayObjContainer *)v47);
      if ( v47 )
        ++v47->RefCount;
      v85 = v47;
      if ( phandle.HType == RH_Pointer && phandle.pResource )
        Scaleform::GFx::Resource::Release(phandle.pResource);
    }
    else
    {
      v47 = 0i64;
      v96 = 0i64;
      if ( ImageMovieDef )
      {
        v55 = this->pAVM.pObject;
        if ( v55 )
          Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(
            v55->GC.GC,
            (Scaleform::GFx::Resource *)this->pMovieImpl->AdvanceStats.pObject,
            0);
        v56 = pentry[1].vfptr[14].__vecDelDtor;
        if ( v56 )
          Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteProgressEvent(
            (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)v56,
            ImageMovieDef->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.FileLength,
            ImageMovieDef->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.FileLength);
        v106[0] = (__int64)ImageMovieDef->pBindData.pObject->pDataDef.pObject;
        v106[1] = (__int64)ImageMovieDef;
        v106[2] = 0i64;
        v57 = this->pASSupport.pObject;
        v82 = 0;
        v47 = (Scaleform::GFx::AS3::AvmBitmap *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, __int64 *, _QWORD, int *, int))v57->vfptr[4].__vecDelDtor)(
                                                  v57,
                                                  this->pMovieImpl,
                                                  v106,
                                                  0i64,
                                                  &v82,
                                                  3);
        v96 = v47;
        Scaleform::GFx::Sprite::SetLoadedSeparately((Scaleform::GFx::Sprite *)v47, 1);
        v47->Scaleform::GFx::DisplayObject::Flags |= 1u;
        ((void (__fastcall *)(Scaleform::GFx::AS3::AvmBitmap *))v47->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[73].__vecDelDtor)(v47);
        Scaleform::GFx::InteractiveObject::AddToPlayList((Scaleform::GFx::InteractiveObject *)v47);
        v58 = (Scaleform::GFx::AS3::AvmDisplayObj *)((char *)v47 + 4 * (unsigned __int8)v47->AvmObjOffset);
        v59 = pentry[1].vfptr;
        if ( v59 )
        {
          v60 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)v59[14].__vecDelDtor;
          if ( v60 )
          {
            Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::applicationDomainGet(v60, &v81);
            if ( v81.pObject && Scaleform::GFx::AS3::VMAppDomain::Enabled )
              v58->AppDomain = v81.pObject->VMDomain.pObject;
            v61 = v81.pObject;
            if ( v81.pObject )
            {
              if ( ((__int64)v81.pObject & 1) != 0 )
              {
                --v81.pObject;
              }
              else
              {
                RefCount = v81.pObject->RefCount;
                if ( (RefCount & 0x3FFFFF) != 0 )
                {
                  v81.pObject->RefCount = RefCount - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v61);
                }
              }
            }
          }
        }
        ((void (__fastcall *)(Scaleform::GFx::AS3::AvmDisplayObj *, _QWORD))v58->vfptr[2].ToAvmButttonBase)(v58, 0i64);
        ((void (__fastcall *)(Scaleform::GFx::AS3::AvmBitmap *))v47->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[39].__vecDelDtor)(v47);
        if ( !v58->pAS3RawPtr
          && !v58->pAS3CollectiblePtr.pObject
          && Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(v58) )
        {
          v63 = v58->pAS3RawPtr;
          if ( !v63 )
            v63 = v58->pAS3CollectiblePtr.pObject;
          if ( ((unsigned __int8)v63 & 1) != 0 )
            v63 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v63 - 1);
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v63->pLoaderInfo,
            (Scaleform::GFx::AS3::Instances::fl::XMLList *)pentry[1].vfptr[14].__vecDelDtor);
          Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(v58, 1);
        }
        if ( v74 )
        {
          v64 = (char *)v74 + 4 * BYTE5(v74->Info.Desc.HeapId);
          v65 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v64 + 40i64))(v64);
          if ( v65 )
            v22 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v65 - 72);
        }
        Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(v22, (Scaleform::GFx::DisplayObjContainer *)v47);
        this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[39].__vecDelDtor(
          this,
          (unsigned int)v47);
        Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Sprite>((Scaleform::GFx::InteractiveObject *)v47);
      }
      if ( v47 )
        ((void (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *))this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[7].__vecDelDtor)(this);
      if ( v47 )
        ++v47->RefCount;
      v85 = v47;
    }
    if ( v47 )
      Scaleform::RefCountNTSImpl::Release(v47);
    if ( (_BYTE)p_binaryData )
    {
      v67 = pentry[1].vfptr[14].__vecDelDtor;
      if ( v67 )
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteInitEvent(
          (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)v67,
          v47);
      v68 = pentry[2].vfptr;
      if ( v68 )
        (*((void (__fastcall **)(Scaleform::GFx::LoadQueueEntryVtbl *))v68->__vecDelDtor + 2))(v68);
      v69 = pentry[1].vfptr[14].__vecDelDtor;
      if ( v69 )
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteCompleteEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v69);
    }
    else
    {
      p_binaryData = &pnLoadInitCL;
      v66 = (Scaleform::GFx::Resource *)pentry[2].vfptr;
      if ( v66 )
        Scaleform::Render::RenderBuffer::AddRef(v66);
      pnLoadInitCL.pObject = (Scaleform::GFx::AS3::NotifyLoadInitC *)pentry[2].vfptr;
      Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueInitEvent(
        (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].vfptr,
        v47,
        (Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC>)&pnLoadInitCL);
      Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueCompleteEvent((Scaleform::GFx::AS3::Instances::fl_display::Loader *)pentry[1].vfptr);
    }
    if ( v47 )
      Scaleform::RefCountNTSImpl::Release(v47);
    if ( ImageMovieDef )
      Scaleform::GFx::Resource::Release(ImageMovieDef);
LABEL_189:
    if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v20 = url.pData;
LABEL_192:
    if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v20 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 4003
// RVA: 0x80A0B0
void __fastcall Scaleform::GFx::AS3::MovieRoot::ProcessLoadVarsMT(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *pentry,
        Scaleform::GFx::LoadStates *__formal,
        Scaleform::String *data,
        unsigned __int64 fileLen,
        bool succeeded)
{
  Scaleform::GFx::LoadQueueEntry *v8; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *pNext; // rdi
  __int64 v12; // rax
  char v13; // dl
  Scaleform::String punescapedStr; // [rsp+20h] [rbp-418h] BYREF
  __int64 v15; // [rsp+28h] [rbp-410h]
  char dest[1024]; // [rsp+30h] [rbp-408h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> result; // [rsp+448h] [rbp+10h] BYREF

  v15 = -2i64;
  if ( succeeded )
  {
    pNext = (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext;
    if ( !strcmp(pNext->dataFormat.pNode->pData, "variables") )
    {
      Scaleform::String::String(&punescapedStr);
      Scaleform::GFx::ASUtils::Unescape(
        (const char *)((data->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        *(_QWORD *)(data->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
        &punescapedStr);
      Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetVariablesDataString(
        (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext,
        (const char *)((punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      if ( !_InterlockedDecrement((volatile signed __int32 *)((punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    else
    {
      v12 = 0i64;
      while ( 1 )
      {
        v13 = pNext->dataFormat.pNode->pData[v12++];
        if ( v13 != aText_0[v12 - 1] )
          break;
        if ( v12 == 5 )
        {
          Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetTextString(
            pNext,
            (const char *)((data->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
          break;
        }
      }
    }
    Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteOpenEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext);
    Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteProgressEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext,
      fileLen,
      fileLen);
    Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteCompleteEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext);
  }
  else
  {
    Scaleform::SFsprintf(dest, 0x400ui64, "Cant open %s", **(const char ***)(*(_QWORD *)&pentry[1].Type + 56i64));
    v8 = pentry[1].pNext;
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateIOErrorEventObject(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v8,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
      dest);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v8);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v8,
      result.pObject,
      0);
    pObject = result.pObject;
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
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
  }
}

// File Line: 4036
// RVA: 0x809190
void __fastcall Scaleform::GFx::AS3::MovieRoot::ProcessLoadBinaryMT(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *pentry,
        Scaleform::GFx::LoadStates *__formal,
        Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *data,
        unsigned __int64 fileLen,
        bool succeeded)
{
  Scaleform::GFx::LoadQueueEntry *pNext; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *pObject; // rcx
  unsigned int RefCount; // eax
  char dest[1032]; // [rsp+30h] [rbp-408h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> result; // [rsp+448h] [rbp+10h] BYREF

  if ( succeeded )
  {
    Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetBinaryData(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext,
      data);
    Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteOpenEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext);
    Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteProgressEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext,
      fileLen,
      fileLen);
    Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteCompleteEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext);
  }
  else
  {
    Scaleform::SFsprintf(dest, 0x400ui64, "Cant open %s", **(const char ***)(*(_QWORD *)&pentry[1].Type + 56i64));
    pNext = pentry[1].pNext;
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateIOErrorEventObject(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)pNext,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
      dest);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)pNext);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)pNext,
      result.pObject,
      0);
    pObject = result.pObject;
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
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
  }
}

// File Line: 4105
// RVA: 0x828A80
void __fastcall Scaleform::GFx::AS3::MovieRoot::UnloadMovie(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::Instances::fl_display::Loader *ploader,
        bool stop,
        bool gc)
{
  Scaleform::GFx::AS3::MovieRoot *v6; // r12
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *pObject; // r13
  Scaleform::GFx::DisplayObject *v8; // rdi
  Scaleform::GFx::DisplayObject *ContentDispObj; // rax
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v13; // rsi
  Scaleform::GFx::DisplayObject *v14; // rbx
  Scaleform::GFx::AS3::VMAppDomain *v15; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> >::TableType *pTable; // rax
  Scaleform::GFx::AS3::VM *pVM; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v18; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v20; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v21; // rcx
  unsigned int v22; // eax
  Scaleform::GFx::LoadQueueEntryMT *i; // rcx
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // rax
  Scaleform::GFx::LoadQueueEntry *j; // rcx
  char *v26; // rsi
  Scaleform::GFx::DisplayObjectBase *ChildAt; // rax
  Scaleform::GFx::Resource *v28; // rax
  Scaleform::GFx::MovieDefImpl *v29; // r13
  char v30; // al
  Scaleform::GFx::AS3::EventChains *p_mEventChains; // r12
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *v32; // rcx
  unsigned __int64 v33; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *v34; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *v35; // r15
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> > *EntryCount; // r15
  unsigned __int64 v37; // r14
  Scaleform::Render::Text::Allocator::TextFormatVisitorVtbl *v38; // rbx
  unsigned __int64 SizeMask; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *v40; // rcx
  Scaleform::GFx::AS3::Stage *v41; // rcx
  char *v42; // rcx
  __int64 v43; // rax
  __int64 v44; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v45; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *p_CaptureListeners; // r8
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *p_LastMouseOverObj; // r15
  __int64 v48; // r12
  Scaleform::GFx::InteractiveObject *v49; // r14
  __int64 v50; // rbx
  __int64 v51; // rbx
  __int64 v52; // rcx
  __int64 v53; // rax
  __int64 v54; // rax
  Scaleform::RefCountNTSImpl *v55; // rcx
  __int64 v56; // rcx
  __int64 v57; // rax
  __int64 v58; // rax
  unsigned __int8 *v59; // rbx
  __int64 v60; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v61; // rcx
  unsigned int v62; // eax
  unsigned int v63; // eax
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v64; // [rsp+38h] [rbp-38h]
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v66; // [rsp+48h] [rbp-28h]
  __int64 v67; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::MovieDefImpl *v68; // [rsp+58h] [rbp-18h]
  Scaleform::Render::Text::Allocator::TextFormatVisitor visitor; // [rsp+60h] [rbp-10h] BYREF
  Scaleform::GFx::MovieDefImpl *v70; // [rsp+68h] [rbp-8h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> v72; // [rsp+B8h] [rbp+48h] BYREF
  bool v73; // [rsp+C8h] [rbp+58h]

  v73 = gc;
  v67 = -2i64;
  v6 = this;
  pObject = ploader->pContentLoaderInfo.pObject;
  v64 = pObject;
  v66 = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  v8 = 0i64;
  if ( pObject )
  {
    ContentDispObj = Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::GetContentDispObj(pObject);
    if ( ContentDispObj )
    {
      ++ContentDispObj->RefCount;
      v8 = ContentDispObj;
    }
    v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            &v6->BuiltinsMgr,
            &result,
            "unload");
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
      pObject,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v72,
      v10,
      0,
      0);
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v13 = v72.pObject;
    v14 = Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::GetContentDispObj(pObject);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v13->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)pObject);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(pObject, v13, v14);
    v15 = pObject->AppDomain.pObject;
    pTable = v15->ClassTraitsSet.Entries.mHash.pTable;
    if ( (!pTable || !pTable->EntryCount) && !v15->ChildDomains.Data.Size )
    {
      pVM = pObject->pTraits.pObject->pVM;
      if ( !pVM->LoadingAbcFile )
        Scaleform::GFx::AS3::VMAppDomain::RemoveChild(pVM->SystemDomain.pObject, v15);
    }
    v18 = v72.pObject;
    if ( v72.pObject )
    {
      if ( ((__int64)v72.pObject & 1) != 0 )
      {
        --v72.pObject;
      }
      else
      {
        RefCount = v72.pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v72.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
        }
      }
    }
  }
  v20 = ploader->pContentLoaderInfo.pObject;
  if ( v20 )
  {
    v21 = v20->Content.pObject;
    if ( v21 )
    {
      if ( ((unsigned __int8)v21 & 1) != 0 )
      {
        v20->Content.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v21 - 1);
      }
      else
      {
        v22 = v21->RefCount;
        if ( (v22 & 0x3FFFFF) != 0 )
        {
          v21->RefCount = v22 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
        }
      }
      v20->Content.pObject = 0i64;
    }
  }
  for ( i = v6->pMovieImpl->pLoadQueueMTHead; i; i = i->pNext )
  {
    pQueueEntry = i->pQueueEntry;
    if ( (Scaleform::GFx::AS3::Instances::fl_display::Loader *)pQueueEntry[1].vfptr == ploader )
      pQueueEntry->Canceled = 1;
  }
  for ( j = v6->pMovieImpl->pLoadQueueHead; j; j = j->pNext )
  {
    if ( (Scaleform::GFx::AS3::Instances::fl_display::Loader *)j[1].vfptr == ploader )
      j->Canceled = 1;
  }
  v26 = (char *)ploader->pDispObj.pObject;
  result.pNode = (Scaleform::GFx::ASStringNode *)v26;
  if ( !v8 )
  {
    if ( !v26 )
      goto LABEL_132;
    if ( !*((_DWORD *)v26 + 56) )
      goto LABEL_132;
    ChildAt = Scaleform::GFx::DisplayObjContainer::GetChildAt((Scaleform::GFx::DisplayObjContainer *)v26, 0);
    if ( !ChildAt )
      goto LABEL_132;
    ++ChildAt->RefCount;
    v8 = (Scaleform::GFx::DisplayObject *)ChildAt;
  }
  ((void (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[75].__vecDelDtor)(v8);
  ((void (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[60].__vecDelDtor)(v8);
  v28 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(v8);
  v29 = (Scaleform::GFx::MovieDefImpl *)v28;
  if ( v28 )
    Scaleform::Render::RenderBuffer::AddRef(v28);
  v68 = v29;
  if ( v29 )
  {
    v30 = Scaleform::GFx::AS3::MovieRoot::RemoveLoadedMovieDef(this, v29);
    if ( stop && v30 )
    {
      p_mEventChains = &this->mEventChains;
      v32 = this->mEventChains.Chains.mHash.pTable;
      if ( v32 )
      {
        v33 = 0i64;
        v34 = v32 + 1;
        do
        {
          if ( v34->EntryCount != -2i64 )
            break;
          ++v33;
          v34 += 2;
        }
        while ( v33 <= v32->SizeMask );
      }
      else
      {
        p_mEventChains = 0i64;
        v33 = 0i64;
      }
      while ( p_mEventChains )
      {
        v35 = p_mEventChains->Chains.mHash.pTable;
        if ( !p_mEventChains->Chains.mHash.pTable || (signed __int64)v33 > (signed __int64)v35->SizeMask )
          break;
        EntryCount = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> > *)v35[2 * v33 + 2].EntryCount;
        if ( EntryCount )
        {
          v37 = 0i64;
          if ( EntryCount->Data.Size )
          {
            while ( 1 )
            {
              Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
                (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&EntryCount->Data.Data[v37],
                (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&v72);
              v38 = (Scaleform::Render::Text::Allocator::TextFormatVisitorVtbl *)v72.pObject;
              if ( v72.pObject )
              {
                ++LODWORD(v72.pObject->_pRCC);
                v38 = (Scaleform::Render::Text::Allocator::TextFormatVisitorVtbl *)v72.pObject;
              }
              visitor.vfptr = v38;
              if ( v72.pObject )
                Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v72.pObject);
              if ( v38
                && (Scaleform::GFx::MovieDefImpl *)(*((__int64 (__fastcall **)(Scaleform::Render::Text::Allocator::TextFormatVisitorVtbl *))v38->__vecDelDtor
                                                    + 66))(v38) == v29 )
              {
                break;
              }
              ++v37;
              if ( v38 )
                goto LABEL_61;
LABEL_62:
              if ( v37 >= EntryCount->Data.Size )
                goto LABEL_63;
            }
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
              EntryCount,
              v37);
LABEL_61:
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v38);
            goto LABEL_62;
          }
        }
LABEL_63:
        SizeMask = p_mEventChains->Chains.mHash.pTable->SizeMask;
        if ( (__int64)v33 <= (__int64)SizeMask && ++v33 <= SizeMask )
        {
          v40 = &p_mEventChains->Chains.mHash.pTable[2 * v33 + 1];
          do
          {
            if ( v40->EntryCount != -2i64 )
              break;
            ++v33;
            v40 += 2;
          }
          while ( v33 <= SizeMask );
        }
      }
      v41 = this->pStage.pObject;
      if ( v41
        && (v42 = (char *)v41 + 4 * (unsigned __int8)v41->AvmObjOffset,
            (v43 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v42 + 40i64))(v42)) != 0) )
      {
        v44 = v43 - 72;
      }
      else
      {
        v44 = 0i64;
      }
      v45 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v44 + 16);
      if ( !v45 )
        v45 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v44 + 8);
      if ( ((unsigned __int8)v45 & 1) != 0 )
        v45 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v45 - 1);
      if ( v45 )
      {
        p_CaptureListeners = &v45->pImpl.pObject->CaptureListeners;
        if ( p_CaptureListeners )
        {
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::RemoveListenersForMovieDef(
            v45,
            v29,
            p_CaptureListeners);
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::RemoveListenersForMovieDef(
            v45,
            v29,
            &v45->pImpl.pObject->Listeners);
        }
      }
      Scaleform::GFx::MovieImpl::ShutdownTimersForMovieDef(this->pMovieImpl, v29);
      Scaleform::GFx::MovieImpl::UnregisterFonts(this->pMovieImpl, v29);
      if ( this->MemContext.pObject->TextAllocator.pObject )
      {
        visitor.vfptr = (Scaleform::Render::Text::Allocator::TextFormatVisitorVtbl *)&`Scaleform::GFx::AS3::MovieRoot::UnloadMovie::`39::TextFormatVisitor::`vftable;
        v70 = v29;
        Scaleform::Render::Text::Allocator::VisitTextFormatCache(
          this->MemContext.pObject->TextAllocator.pObject,
          &visitor);
        visitor.vfptr = (Scaleform::Render::Text::Allocator::TextFormatVisitorVtbl *)&Scaleform::Render::Text::Allocator::TextFormatVisitor::`vftable;
      }
      p_LastMouseOverObj = &this->mMouseState[0].LastMouseOverObj;
      v48 = 6i64;
      do
      {
        v49 = 0i64;
        while ( v49 < p_LastMouseOverObj[-2].pObject )
        {
          v50 = (__int64)p_LastMouseOverObj[-3].pObject + 8 * (_QWORD)v49;
          if ( *(_QWORD *)v50 )
            ++*(_DWORD *)(*(_QWORD *)v50 + 8i64);
          v51 = *(_QWORD *)v50;
          v72.pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v51;
          if ( !v51 )
            goto LABEL_99;
          v52 = v51 + 4i64 * *(unsigned __int8 *)(v51 + 109);
          v53 = *(_QWORD *)(v52 + 16);
          if ( !v53 )
            v53 = *(_QWORD *)(v52 + 8);
          if ( (v53 & 1) != 0 )
            --v53;
          if ( v53
            && (v54 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)(v53 + 40) + 56i64))(*(_QWORD *)(v53 + 40))) != 0
            && *(Scaleform::GFx::MovieDefImpl **)(*(_QWORD *)(v54 + 152) + 368i64) == v29 )
          {
            if ( p_LastMouseOverObj[-2].pObject == (Scaleform::GFx::InteractiveObject *)1 )
            {
              Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *)&p_LastMouseOverObj[-3],
                &p_LastMouseOverObj[-3],
                0i64);
            }
            else
            {
              v55 = (Scaleform::RefCountNTSImpl *)(&p_LastMouseOverObj[-3].pObject->vfptr)[(_QWORD)v49];
              if ( v55 )
                Scaleform::RefCountNTSImpl::Release(v55);
              memmove(
                &(&p_LastMouseOverObj[-3].pObject->vfptr)[(_QWORD)v49],
                &p_LastMouseOverObj[-3].pObject->RefCount + 2 * (_QWORD)v49,
                8 * ((char *)p_LastMouseOverObj[-2].pObject-- - (char *)v49) - 8);
            }
          }
          else
          {
LABEL_99:
            v49 = (Scaleform::GFx::InteractiveObject *)((char *)v49 + 1);
          }
          if ( v51 )
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v51);
        }
        if ( p_LastMouseOverObj->pObject )
        {
          v56 = (__int64)p_LastMouseOverObj->pObject + 4 * (unsigned __int8)p_LastMouseOverObj->pObject->AvmObjOffset;
          v57 = *(_QWORD *)(v56 + 16);
          if ( !v57 )
            v57 = *(_QWORD *)(v56 + 8);
          if ( (v57 & 1) != 0 )
            --v57;
          if ( v57 )
          {
            v58 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)(v57 + 40) + 56i64))(*(_QWORD *)(v57 + 40));
            if ( v58 )
            {
              if ( *(Scaleform::GFx::MovieDefImpl **)(*(_QWORD *)(v58 + 152) + 368i64) == v29 )
              {
                if ( p_LastMouseOverObj->pObject )
                  Scaleform::RefCountNTSImpl::Release(p_LastMouseOverObj->pObject);
                p_LastMouseOverObj->pObject = 0i64;
              }
            }
          }
        }
        p_LastMouseOverObj += 28;
        --v48;
      }
      while ( v48 );
      v26 = (char *)result.pNode;
    }
    v6 = this;
  }
  v59 = (unsigned __int8 *)v8 + 4 * (unsigned __int8)v8->AvmObjOffset;
  v60 = *((_QWORD *)v59 + 2);
  if ( !v60 )
    v60 = *((_QWORD *)v59 + 1);
  if ( (v60 & 1) != 0 )
    --v60;
  *((_QWORD *)v59 + 2) = v60;
  v61 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*((_QWORD *)v59 + 1);
  if ( v61 )
  {
    if ( ((unsigned __int8)v61 & 1) != 0 )
    {
      *((_QWORD *)v59 + 1) = (char *)v61 - 1;
    }
    else
    {
      v62 = v61->RefCount;
      if ( (v62 & 0x3FFFFF) != 0 )
      {
        v61->RefCount = v62 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v61);
      }
    }
    *((_QWORD *)v59 + 1) = 0i64;
  }
  if ( v26 )
  {
    Scaleform::GFx::DisplayList::Clear(
      (Scaleform::GFx::DisplayList *)(v26 + 216),
      (Scaleform::GFx::DisplayObjectBase *)v26);
    _((AMD_HD3D *)v26);
  }
  if ( v29 )
    Scaleform::GFx::Resource::Release(v29);
  pObject = v64;
LABEL_132:
  if ( v73 )
    v6->pAVM.pObject->GC.GC->CollectionScheduledFlags = 10;
  if ( v8 && ((unsigned __int8)v8 & 1) == 0 )
    Scaleform::RefCountNTSImpl::Release(v8);
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      v66 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)((char *)pObject - 1);
    }
    else
    {
      v63 = pObject->RefCount;
      if ( (v63 & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = v63 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
}

// File Line: 4205
// RVA: 0x8299C0
bool __fastcall Scaleform::GFx::AS3::MovieRoot::UnloadMovie_::_39_::TextFormatVisitor::Visit(
        Scaleform::Render::Text::TextFormat *tf,
        Scaleform::Render::Text::TextFormat *a2)
{
  Scaleform::Render::RenderBuffer *FontHandle; // rax

  FontHandle = Scaleform::Render::Text::TextFormat::GetFontHandle(a2);
  return !FontHandle || *(_QWORD *)&FontHandle[1].RefCount != *(_QWORD *)&tf->RefCount;
}

// File Line: 4253
// RVA: 0x805200
void __fastcall Scaleform::GFx::AS3::MovieRoot::OnMovieDefRelease(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::MovieDefImpl *defImpl)
{
  Scaleform::GFx::MovieDefImpl *key; // [rsp+38h] [rbp+10h] BYREF

  key = defImpl;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::MovieDefImpl *>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> > *)&this->mMouseState[5].DblClick[11].PrevPosition,
    &key);
}

// File Line: 4258
// RVA: 0x7ADDF0
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddLoadedMovieDef(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::MovieDefImpl *defImpl)
{
  Scaleform::GFx::MovieDefImpl::ReleaseNotifier *v4; // rdx
  Scaleform::HashIdentityLH<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,2,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> > *p_LoadedMovieDefs; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> >::TableType *pTable; // r10
  unsigned __int64 SizeMask; // rbx
  unsigned __int64 v8; // r9
  __int64 v9; // rcx
  unsigned __int64 v10; // rdx
  bool v11; // zf
  unsigned __int64 *v12; // rdx
  unsigned __int64 v13; // r8
  unsigned __int64 *v14; // rax
  _DWORD *v15; // rax
  Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeRef key; // [rsp+20h] [rbp-18h] BYREF
  int v17; // [rsp+40h] [rbp+8h] BYREF
  unsigned __int64 hashValue; // [rsp+48h] [rbp+10h] BYREF

  hashValue = (unsigned __int64)defImpl;
  if ( this )
    v4 = &this->Scaleform::GFx::MovieDefImpl::ReleaseNotifier;
  else
    v4 = 0i64;
  Scaleform::GFx::MovieDefImpl::AddReleaseNotifier(defImpl, v4);
  p_LoadedMovieDefs = &this->LoadedMovieDefs;
  pTable = this->LoadedMovieDefs.mHash.pTable;
  if ( !pTable )
    goto LABEL_15;
  SizeMask = pTable->SizeMask;
  v8 = hashValue & SizeMask;
  v9 = v8;
  v10 = v8 + 2 * (v8 + 1);
  v11 = *(&pTable->EntryCount + v10) == -2i64;
  v12 = &pTable->EntryCount + v10;
  if ( v11 || (SizeMask & v12[1]) != v8 )
    goto LABEL_15;
  while ( 1 )
  {
    v13 = v12[1];
    if ( (v13 & SizeMask) == v8 && v13 == hashValue )
      break;
    v9 = *v12;
    if ( *v12 == -1i64 )
      goto LABEL_15;
    v12 = &pTable[v9 + 1].EntryCount + v9;
  }
  if ( v9 >= 0 && (v14 = &pTable[1].SizeMask + 3 * v9) != 0i64 && (v15 = v14 + 1) != 0i64 )
  {
    ++*v15;
  }
  else
  {
LABEL_15:
    key.pFirst = (Scaleform::GFx::MovieDefImpl *const *)&hashValue;
    v17 = 1;
    key.pSecond = (Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo *)&v17;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeRef>(
      &p_LoadedMovieDefs->mHash,
      p_LoadedMovieDefs,
      &key,
      hashValue);
  }
}

// File Line: 4275
// RVA: 0x811E10
char __fastcall Scaleform::GFx::AS3::MovieRoot::RemoveLoadedMovieDef(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::MovieDefImpl *defImpl)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> >::TableType *pTable; // r9
  unsigned __int64 SizeMask; // r11
  unsigned __int64 v6; // r10
  signed __int64 v7; // r8
  unsigned __int64 *v8; // rdx
  unsigned __int64 v9; // rcx
  unsigned __int64 *v10; // rax
  _DWORD *v11; // rax
  Scaleform::GFx::MovieDefImpl *key; // [rsp+38h] [rbp+10h] BYREF

  key = defImpl;
  pTable = this->LoadedMovieDefs.mHash.pTable;
  if ( !pTable )
    return 0;
  SizeMask = pTable->SizeMask;
  v6 = (unsigned __int64)defImpl & SizeMask;
  v7 = (unsigned __int64)defImpl & SizeMask;
  v8 = &pTable[1].EntryCount + 3 * ((unsigned __int64)defImpl & SizeMask);
  if ( *v8 == -2i64 || (SizeMask & v8[1]) != v6 )
    return 0;
  while ( 1 )
  {
    v9 = v8[1];
    if ( (v9 & SizeMask) == v6 && (Scaleform::GFx::MovieDefImpl *)v9 == defImpl )
      break;
    v7 = *v8;
    if ( *v8 == -1i64 )
      return 0;
    v8 = &pTable[v7 + 1].EntryCount + v7;
  }
  if ( v7 < 0 )
    return 0;
  v10 = &pTable[1].SizeMask + 3 * v7;
  if ( !v10 )
    return 0;
  v11 = v10 + 1;
  if ( !v11 )
    return 0;
  if ( (*v11)-- != 1 )
    return 0;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::MovieDefImpl *>(
    &this->LoadedMovieDefs.mHash,
    &key);
  Scaleform::GFx::MovieDefImpl::RemoveReleaseNotifier(defImpl, &this->Scaleform::GFx::MovieDefImpl::ReleaseNotifier);
  return 1;
}

// File Line: 4292
// RVA: 0x7EEFA0
Scaleform::GFx::DisplayObjContainer *__fastcall Scaleform::GFx::AS3::MovieRoot::GetRootMovie(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::DisplayObject *dobj)
{
  Scaleform::GFx::DisplayObjContainer *result; // rax

  if ( !dobj )
    return this->pStage.pObject->pRoot.pObject;
  result = (Scaleform::GFx::DisplayObjContainer *)Scaleform::GFx::AS3::AvmDisplayObj::GetRoot((Scaleform::GFx::AS3::AvmDisplayObj *)((char *)dobj + 4 * (unsigned __int8)dobj->AvmObjOffset));
  if ( !result )
    return this->pStage.pObject->pRoot.pObject;
  if ( (result->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x200) == 0 )
    return (Scaleform::GFx::DisplayObjContainer *)this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[16].__vecDelDtor(
                                                    this,
                                                    result->pParent);
  return result;
}

// File Line: 4362
// RVA: 0x81A710
void __fastcall Scaleform::GFx::AS3::MovieRoot::SetMouseCursorType(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::ASString *cursor,
        unsigned int mouseIndex)
{
  unsigned int v3; // ebx
  Scaleform::GFx::MouseState *v4; // rdi
  const char *pData; // r9
  __int64 v7; // rdx
  char v8; // al
  __int64 v9; // rcx
  char v10; // al
  __int64 v11; // rcx
  char v12; // al
  __int64 v13; // rax
  char v14; // cl
  bool v15; // zf

  v3 = -1;
  v4 = 0i64;
  pData = cursor->pNode->pData;
  v7 = 0i64;
  while ( 1 )
  {
    v8 = pData[v7++];
    if ( v8 != aArrow[v7 - 1] )
      break;
    if ( v7 == 6 )
    {
      v3 = 0;
      goto LABEL_19;
    }
  }
  v9 = 0i64;
  while ( 1 )
  {
    v10 = pData[v9++];
    if ( v10 != aButton_0[v9 - 1] )
      break;
    if ( v9 == 7 )
    {
      v3 = 3;
      goto LABEL_19;
    }
  }
  v11 = 0i64;
  while ( 1 )
  {
    v12 = pData[v11++];
    if ( v12 != aHand[v11 - 1] )
      break;
    if ( v11 == 5 )
    {
      v3 = 1;
      goto LABEL_19;
    }
  }
  v13 = 0i64;
  while ( 1 )
  {
    v14 = pData[v13++];
    v15 = v14 == aIbeam[v13 - 1];
    if ( v14 != aIbeam[v13 - 1] )
      break;
    if ( v13 == 6 )
    {
      v15 = v14 == aIbeam[5];
      break;
    }
  }
  if ( v15 )
    v3 = 2;
LABEL_19:
  if ( mouseIndex < 6 )
    v4 = &this->pMovieImpl->mMouseState[mouseIndex];
  ((void (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, _QWORD, _QWORD))this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[3].__vecDelDtor)(
    this,
    mouseIndex,
    v3);
  v4->mPresetCursorType = v3;
  v4->CursorType = v3;
}

// File Line: 4379
// RVA: 0x7EC490
void __fastcall Scaleform::GFx::AS3::MovieRoot::GetMouseCursorTypeString(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::ASString *result,
        unsigned int cursorType)
{
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  int v5; // r8d
  int v6; // r8d
  Scaleform::GFx::ASStringManager *v7; // rax
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rdi
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASStringManager *v13; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringManager *v17; // rax
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rdi
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASStringManager *v21; // rax
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rdi
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASStringManager *v25; // rax
  Scaleform::GFx::ASString *v26; // rax
  Scaleform::GFx::ASStringNode *v27; // rdi
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::ASString v29; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::GFx::ASString v30; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString v31; // [rsp+30h] [rbp-28h] BYREF
  Scaleform::GFx::ASString v32; // [rsp+38h] [rbp-20h] BYREF
  __int64 v33; // [rsp+40h] [rbp-18h]
  Scaleform::GFx::ASString resulta; // [rsp+78h] [rbp+20h] BYREF

  v33 = -2i64;
  vfptr = this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr;
  if ( cursorType )
  {
    v5 = cursorType - 1;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( v6 )
      {
        if ( v6 == 1 )
        {
          v13 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))vfptr[59].__vecDelDtor)();
          v14 = Scaleform::GFx::ASStringManager::CreateConstString(v13, &v29, "button");
          pNode = v14->pNode;
          ++v14->pNode->RefCount;
          v16 = result->pNode;
          v11 = result->pNode->RefCount-- == 1;
          if ( v11 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v16);
          result->pNode = pNode;
          v12 = v29.pNode;
        }
        else
        {
          v7 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))vfptr[59].__vecDelDtor)();
          v8 = Scaleform::GFx::ASStringManager::CreateConstString(v7, &resulta, "auto");
          v9 = v8->pNode;
          ++v8->pNode->RefCount;
          v10 = result->pNode;
          v11 = result->pNode->RefCount-- == 1;
          if ( v11 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v10);
          result->pNode = v9;
          v12 = resulta.pNode;
        }
      }
      else
      {
        v17 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))vfptr[59].__vecDelDtor)();
        v18 = Scaleform::GFx::ASStringManager::CreateConstString(v17, &v30, "ibeam");
        v19 = v18->pNode;
        ++v18->pNode->RefCount;
        v20 = result->pNode;
        v11 = result->pNode->RefCount-- == 1;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v20);
        result->pNode = v19;
        v12 = v30.pNode;
      }
    }
    else
    {
      v21 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))vfptr[59].__vecDelDtor)();
      v22 = Scaleform::GFx::ASStringManager::CreateConstString(v21, &v31, "hand");
      v23 = v22->pNode;
      ++v22->pNode->RefCount;
      v24 = result->pNode;
      v11 = result->pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      result->pNode = v23;
      v12 = v31.pNode;
    }
  }
  else
  {
    v25 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))vfptr[59].__vecDelDtor)();
    v26 = Scaleform::GFx::ASStringManager::CreateConstString(v25, &v32, "arrow");
    v27 = v26->pNode;
    ++v26->pNode->RefCount;
    v28 = result->pNode;
    v11 = result->pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v28);
    result->pNode = v27;
    v12 = v32.pNode;
  }
  v11 = v12->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
}

// File Line: 4391
// RVA: 0x7EC450
void __fastcall Scaleform::GFx::AS3::MovieRoot::GetMouseCursorType(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::ASString *result,
        unsigned int mouseIndex)
{
  if ( mouseIndex < 6 )
    Scaleform::GFx::AS3::MovieRoot::GetMouseCursorTypeString(
      this,
      result,
      this->pMovieImpl->mMouseState[mouseIndex].mPresetCursorType);
  else
    Scaleform::GFx::AS3::MovieRoot::GetMouseCursorTypeString(this, result, MEMORY[0x40]);
}

// File Line: 4398
// RVA: 0x7E9130
Scaleform::AmpMovieObjectDesc *__fastcall Scaleform::GFx::AS3::MovieRoot::GetDisplayObjectsTree(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::AmpMovieObjectDesc *v3; // rbx
  Scaleform::GFx::DisplayObjContainer *pMainMovie; // rsi
  Scaleform::GFx::ASStringNode *v5; // rax
  Scaleform::AmpMovieObjectDesc *v6; // rax
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::MemoryHeap *v12; // [rsp+48h] [rbp+10h]

  v12 = heap;
  v3 = 0i64;
  pMainMovie = (Scaleform::GFx::DisplayObjContainer *)this->pMovieImpl->pMainMovie;
  if ( pMainMovie )
  {
    v5 = (Scaleform::GFx::ASStringNode *)heap->vfptr->Alloc(heap, 48i64, 0i64);
    result.pNode = v5;
    if ( v5 )
    {
      Scaleform::AmpMovieObjectDesc::AmpMovieObjectDesc((Scaleform::AmpMovieObjectDesc *)v5);
      v3 = v6;
    }
    Name = Scaleform::GFx::DisplayObject::GetName(pMainMovie, &result);
    Scaleform::String::operator=(&v3->Description, Name->pNode->pData);
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    Scaleform::GFx::DisplayObjContainer::GetChildDescTree(pMainMovie, v3, heap);
  }
  return v3;
}

// File Line: 4445
// RVA: 0x8041B0
char __fastcall Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::OnExceedLimit(
        Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit *this,
        Scaleform::MemoryHeap *heap,
        unsigned __int64 overLimit)
{
  __int64 v6; // rax
  unsigned __int64 Limit; // r15
  unsigned __int64 v8; // rbp
  float v9; // xmm0_4
  float v10; // xmm0_4
  unsigned __int64 v11; // rax
  float v12; // xmm1_4
  unsigned __int64 v13; // rsi
  unsigned __int64 UserLevelLimit; // rax
  unsigned __int64 CurrentLimit; // rdx
  unsigned __int64 v16; // rax
  unsigned __int64 LastCollectionFootprint; // rcx

  v6 = heap->vfptr->GetFootprint(heap);
  Limit = heap->Info.Desc.Limit;
  v8 = v6;
  v9 = (float)(int)v6;
  if ( v6 < 0 )
    v9 = v9 + 1.8446744e19;
  v10 = v9 * this->HeapLimitMultiplier;
  v11 = 0i64;
  v12 = v10;
  if ( v10 >= 9.223372e18 )
  {
    v12 = v10 - 9.223372e18;
    if ( (float)(v10 - 9.223372e18) < 9.223372e18 )
      v11 = 0x8000000000000000ui64;
  }
  v13 = overLimit + Limit + v11 + (unsigned int)(int)v12;
  if ( (__int64)(v8 - this->LastCollectionFootprint) < (unsigned int)(int)v10 )
  {
    UserLevelLimit = this->UserLevelLimit;
    if ( !UserLevelLimit || v13 <= UserLevelLimit )
    {
      CurrentLimit = v13;
LABEL_17:
      heap->vfptr->SetLimit(heap, CurrentLimit);
      this->CurrentLimit = heap->Info.Desc.Limit;
      return 1;
    }
  }
  if ( this->AllocCount )
  {
    this->MemContext->ASGC.pObject->CollectionScheduledFlags = 10;
    this->LastCollectionFootprint = v8;
  }
  else
  {
    Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::Collect(this, heap);
    v16 = this->UserLevelLimit;
    if ( v16 && v13 > v16 )
    {
      LastCollectionFootprint = this->LastCollectionFootprint;
      if ( overLimit <= v8 - LastCollectionFootprint )
      {
        CurrentLimit = this->CurrentLimit;
      }
      else
      {
        CurrentLimit = overLimit + Limit + LastCollectionFootprint - v8;
        this->CurrentLimit = CurrentLimit;
      }
      goto LABEL_17;
    }
  }
  return 1;
}

// File Line: 4535
// RVA: 0x7B7690
void __fastcall Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::Collect(
        Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::Render::Text::Allocator *pObject; // rcx
  Scaleform::GFx::AS3::MemoryContextImpl *MemContext; // rax
  Scaleform::GFx::AS3::ASRefCountCollector *v6; // rbx

  pObject = this->MemContext->TextAllocator.pObject;
  if ( pObject )
  {
    Scaleform::Render::Text::Allocator::FlushTextFormatCache(pObject, 1);
    Scaleform::Render::Text::Allocator::FlushParagraphFormatCache(this->MemContext->TextAllocator.pObject, 1);
  }
  MemContext = this->MemContext;
  v6 = MemContext->ASGC.pObject;
  if ( v6->SuspendCnt )
  {
    v6->CollectionScheduledFlags = 10;
  }
  else
  {
    Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(MemContext->ASGC.pObject, 0i64, 2u);
    *(_QWORD *)&v6->MaxRootCount = v6->PresetMaxRootCount;
  }
  this->LastCollectionFootprint = heap->vfptr->GetFootprint(heap);
}

