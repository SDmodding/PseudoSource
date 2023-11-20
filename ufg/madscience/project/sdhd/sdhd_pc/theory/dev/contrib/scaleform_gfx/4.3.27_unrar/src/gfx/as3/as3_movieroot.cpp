// File Line: 52
// RVA: 0x77A120
void __fastcall Scaleform::GFx::AS3::ASVM::ASVM(Scaleform::GFx::AS3::ASVM *this, Scaleform::GFx::AS3::MovieRoot *pmr, Scaleform::GFx::AS3::FlashUI *_ui, Scaleform::GFx::AS3::StringManager *sm, Scaleform::GFx::AS3::ASRefCountCollector *gc)
{
  Scaleform::GFx::AS3::MovieRoot *v5; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // rax
  Scaleform::GFx::AS3::VM *v7; // rbx
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
  Scaleform::StringDataPtr gname; // [rsp+28h] [rbp-18h]
  Scaleform::GFx::AS3::ASVM *v33; // [rsp+70h] [rbp+30h]

  v33 = this;
  v5 = pmr;
  Scaleform::GFx::AS3::VM::VM((Scaleform::GFx::AS3::VM *)&this->vfptr, _ui, sm, gc);
  v33->vfptr = (Scaleform::GFx::AS3::VMVtbl *)&Scaleform::GFx::AS3::ASVM::`vftable;
  v33->pMovieRoot = v5;
  v33->GraphicsClass.pObject = 0i64;
  v33->TransformClass.pObject = 0i64;
  v33->MatrixClass.pObject = 0i64;
  v33->Matrix3DClass.pObject = 0i64;
  v33->PerspectiveProjectionClass.pObject = 0i64;
  v33->ColorTransformClass.pObject = 0i64;
  v33->EventClass.pObject = 0i64;
  v33->MouseEventClass.pObject = 0i64;
  v33->MouseEventExClass.pObject = 0i64;
  v33->KeyboardEventClass.pObject = 0i64;
  v33->KeyboardEventExClass.pObject = 0i64;
  v33->FocusEventClass.pObject = 0i64;
  v33->FocusEventExClass.pObject = 0i64;
  v33->TextEventClass.pObject = 0i64;
  v33->TextEventExClass.pObject = 0i64;
  v33->TimerEventClass.pObject = 0i64;
  v33->ProgressEventClass.pObject = 0i64;
  v33->StageOrientationEventClass.pObject = 0i64;
  v33->AppLifecycleEventClass.pObject = 0i64;
  v33->StatusEventClass.pObject = 0i64;
  v33->AccelerometerEventClass.pObject = 0i64;
  v33->GeolocationEventClass.pObject = 0i64;
  v33->PointClass.pObject = 0i64;
  v33->RectangleClass.pObject = 0i64;
  v33->TextFormatClass.pObject = 0i64;
  v33->EventDispatcherClass.pObject = 0i64;
  v33->Vector3DClass.pObject = 0i64;
  v33->GeneralClipboard.pObject = 0i64;
  v33->ExtensionsEnabled = 0;
  gname.pStr = "flash.display.Graphics";
  gname.Size = 22i64;
  v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                        (Scaleform::GFx::AS3::VM *)&v33->vfptr,
                                                        &gname,
                                                        v33->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->GraphicsClass,
    v6);
  gname.pStr = "flash.geom.Transform";
  gname.Size = 20i64;
  v7 = (Scaleform::GFx::AS3::VM *)&v33->vfptr;
  v8 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                        (Scaleform::GFx::AS3::VM *)&v33->vfptr,
                                                        &gname,
                                                        v33->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->TransformClass,
    v8);
  gname.pStr = "flash.geom.Matrix";
  gname.Size = 17i64;
  v9 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                        v7,
                                                        &gname,
                                                        v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->MatrixClass,
    v9);
  gname.pStr = "flash.geom.Matrix3D";
  gname.Size = 19i64;
  v10 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->Matrix3DClass,
    v10);
  gname.pStr = "flash.geom.PerspectiveProjection";
  gname.Size = 32i64;
  v11 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->PerspectiveProjectionClass,
    v11);
  gname.pStr = "flash.geom.ColorTransform";
  gname.Size = 25i64;
  v12 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->ColorTransformClass,
    v12);
  gname.pStr = "flash.events.Event";
  gname.Size = 18i64;
  v13 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->EventClass,
    v13);
  gname.pStr = "flash.events.MouseEvent";
  gname.Size = 23i64;
  v14 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->MouseEventClass,
    v14);
  gname.pStr = "flash.events.KeyboardEvent";
  gname.Size = 26i64;
  v15 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->KeyboardEventClass,
    v15);
  gname.pStr = "flash.events.FocusEvent";
  gname.Size = 23i64;
  v16 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->FocusEventClass,
    v16);
  gname.pStr = "flash.events.TextEvent";
  gname.Size = 22i64;
  v17 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->TextEventClass,
    v17);
  gname.pStr = "scaleform.gfx.MouseEventEx";
  gname.Size = 26i64;
  v18 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->MouseEventExClass,
    v18);
  gname.pStr = "scaleform.gfx.KeyboardEventEx";
  gname.Size = 29i64;
  v19 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->KeyboardEventExClass,
    v19);
  gname.pStr = "scaleform.gfx.FocusEventEx";
  gname.Size = 26i64;
  v20 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->FocusEventExClass,
    v20);
  gname.pStr = "scaleform.gfx.TextEventEx";
  gname.Size = 25i64;
  v21 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->TextEventExClass,
    v21);
  gname.pStr = "flash.events.TimerEvent";
  gname.Size = 23i64;
  v22 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->TimerEventClass,
    v22);
  gname.pStr = "flash.events.ProgressEvent";
  gname.Size = 26i64;
  v23 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->ProgressEventClass,
    v23);
  gname.pStr = "flash.events.StatusEvent";
  gname.Size = 24i64;
  v24 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->StatusEventClass,
    v24);
  gname.pStr = "flash.events.AccelerometerEvent";
  gname.Size = 31i64;
  v25 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->AccelerometerEventClass,
    v25);
  gname.pStr = "flash.events.GeolocationEvent";
  gname.Size = 29i64;
  v26 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->GeolocationEventClass,
    v26);
  gname.pStr = "flash.geom.Point";
  gname.Size = 16i64;
  v27 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->PointClass,
    v27);
  gname.pStr = "flash.geom.Rectangle";
  gname.Size = 20i64;
  v28 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->RectangleClass,
    v28);
  gname.pStr = "flash.text.TextFormat";
  gname.Size = 21i64;
  v29 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->TextFormatClass,
    v29);
  gname.pStr = "flash.events.EventDispatcher";
  gname.Size = 28i64;
  v30 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->EventDispatcherClass,
    v30);
  gname.pStr = "flash.geom.Vector3D";
  gname.Size = 19i64;
  v31 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::GetClass(
                                                         v7,
                                                         &gname,
                                                         v7->CurrentDomain.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v33->Vector3DClass,
    v31);
}

// File Line: 161
// RVA: 0x82A990
__int64 __fastcall Scaleform::GFx::AS3::ASVM::_constructInstance(Scaleform::GFx::AS3::ASVM *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *pobj, Scaleform::GFx::AS3::Object *classObj, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *v5; // rbx
  Scaleform::GFx::AS3::ASVM *v6; // rdi
  char v7; // ST20_1
  int v8; // ecx
  unsigned __int8 v9; // bl
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v10; // rcx
  unsigned int v11; // eax
  bool v12; // zf
  Scaleform::GFx::AS3::Value v14; // [rsp+38h] [rbp-30h]

  v5 = pobj;
  v6 = this;
  v14.Flags = 0;
  v14.Bonus.pWeakProxy = 0i64;
  v7 = 1;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Object *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *, char))classObj->vfptr[4].ForEachChild_GC)(
    classObj,
    &v14,
    argc,
    argv,
    v7);
  if ( !v6->HandleException
    && (v8 = v14.Flags & 0x1F) != 0
    && ((unsigned int)(v8 - 12) > 3 && v8 != 10 || *(_QWORD *)&v14.value.VNumber) )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v5,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v14.value.VS._1.VStr);
    v9 = 1;
  }
  else
  {
    v10.pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v5->pObject;
    if ( v5->pObject )
    {
      if ( (_QWORD)v10.pObject & 1 )
      {
        v5->pObject = (Scaleform::GFx::AS3::Object *)((char *)&v10.pObject[-1].List.Data.Policy.Capacity + 7);
      }
      else
      {
        v11 = v10.pObject->RefCount;
        if ( v11 & 0x3FFFFF )
        {
          v10.pObject->RefCount = v11 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v10.pObject->vfptr);
        }
      }
      v5->pObject = 0i64;
    }
    if ( v6->HandleException )
      v6->HandleException = 0;
    v9 = 0;
  }
  if ( (v14.Flags & 0x1F) > 9 )
  {
    if ( (v14.Flags >> 9) & 1 )
    {
      v12 = v14.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v14.Bonus.pWeakProxy = 0i64;
      v14.value = 0ui64;
      v14.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v14);
    }
  }
  return v9;
}

// File Line: 178
// RVA: 0x7EEDF0
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::AS3::ASVM::GetResourceMovieDef(Scaleform::GFx::AS3::ASVM *this, Scaleform::GFx::AS3::Instances::fl::Object *instance)
{
  Scaleform::GFx::AS3::Traits *v2; // rbx
  Scaleform::GFx::AS3::ASVM *v3; // rdi
  __int64 v4; // rax
  Scaleform::GFx::MovieDefImpl *result; // rax

  v2 = instance->pTraits.pObject;
  v3 = this;
  if ( !v2->pConstructor.pObject )
    v2->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&instance->pTraits.pObject->vfptr);
  v4 = ((__int64 (*)(void))v2->pConstructor.pObject->pTraits.pObject->vfptr[2].~RefCountBaseGC<328>)();
  if ( v4 )
    result = *(Scaleform::GFx::MovieDefImpl **)(*(_QWORD *)(v4 + 152) + 368i64);
  else
    result = v3->pMovieRoot->pMovieImpl->pMainMovieDef.pObject;
  return result;
}

// File Line: 195
// RVA: 0x78CA90
void __fastcall Scaleform::GFx::AS3::MovieDefRootNode::~MovieDefRootNode(Scaleform::GFx::AS3::MovieDefRootNode *this)
{
  Scaleform::GFx::AS3::MovieDefRootNode *v1; // rsi
  signed __int64 i; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v3; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v4; // rcx
  unsigned int v5; // eax
  unsigned __int64 v6; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328> **j; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v8; // rcx
  unsigned int v9; // eax
  Scaleform::Render::RenderBuffer *v10; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::MovieDefRootNodeVtbl *)&Scaleform::GFx::AS3::MovieDefRootNode::`vftable;
  for ( i = this->AbcFiles.Data.Size - 1; i >= 0; --i )
  {
    v3 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v1->AbcFiles.Data.Data[i];
    v4 = *v3;
    if ( *v3 )
    {
      if ( (unsigned __int8)v4 & 1 )
      {
        *v3 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v4 - 1);
      }
      else
      {
        v5 = v4->RefCount;
        if ( v5 & 0x3FFFFF )
        {
          v4->RefCount = v5 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
        }
      }
      *v3 = 0i64;
    }
  }
  v6 = v1->AbcFiles.Data.Size;
  for ( j = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v1->AbcFiles.Data.Data[v6 - 1]; v6; --v6 )
  {
    v8 = *j;
    if ( *j )
    {
      if ( (unsigned __int8)v8 & 1 )
      {
        *j = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v8 - 1);
      }
      else
      {
        v9 = v8->RefCount;
        if ( v9 & 0x3FFFFF )
        {
          v8->RefCount = v9 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
        }
      }
    }
    --j;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->AbcFiles.Data.Data);
  v1->vfptr = (Scaleform::GFx::MovieDefRootNodeVtbl *)&Scaleform::GFx::MovieDefRootNode::`vftable;
  v10 = (Scaleform::Render::RenderBuffer *)v1->pFontManager.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
}

// File Line: 216
// RVA: 0x77FD40
void __fastcall Scaleform::GFx::AS3::MovieRoot::MovieRoot(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::MemoryContextImpl *memContext, Scaleform::GFx::MovieImpl *pmovie, Scaleform::GFx::ASSupport *pas)
{
  Scaleform::GFx::MovieImpl *v4; // rsi
  Scaleform::GFx::Resource *v5; // rdi
  Scaleform::GFx::AS3::MovieRoot *v6; // rbx
  signed __int64 v7; // r15
  Scaleform::MemoryHeap *v8; // rax

  v4 = pmovie;
  v5 = (Scaleform::GFx::Resource *)memContext;
  v6 = this;
  Scaleform::GFx::ASMovieRootBase::ASMovieRootBase((Scaleform::GFx::ASMovieRootBase *)&this->vfptr, pas);
  v6->vfptr = (Scaleform::GFx::AS3::FlashUIVtbl *)&Scaleform::GFx::AS3::FlashUI::`vftable;
  v6->State = 0;
  v6->NeedToCheck = 0;
  v6->vfptr = (Scaleform::GFx::KeyboardState::IListenerVtbl *)&Scaleform::GFx::KeyboardState::IListener::`vftable;
  v6->vfptr = (Scaleform::GFx::MovieDefImpl::ReleaseNotifierVtbl *)&Scaleform::GFx::MovieDefImpl::ReleaseNotifier::`vftable;
  v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable{for `Scaleform::GFx::ASMovieRootBase};
  v6->vfptr = (Scaleform::GFx::AS3::FlashUIVtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable{for `Scaleform::GFx::AS3::FlashUI};
  v6->vfptr = (Scaleform::GFx::KeyboardState::IListenerVtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable{for `Scaleform::GFx::KeyboardState::IListener};
  v6->vfptr = (Scaleform::GFx::MovieDefImpl::ReleaseNotifierVtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable{for `Scaleform::GFx::MovieDefImpl::ReleaseNotifier};
  v7 = (signed __int64)&v6->MemContext;
  if ( v5 )
    Scaleform::Render::RenderBuffer::AddRef(v5);
  *(_QWORD *)v7 = v5;
  v6->pAVM.pObject = 0i64;
  v6->pAVM.Owner = 1;
  v6->ExternalIntfRetVal.Flags = 0;
  v6->ExternalIntfRetVal.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&v6->NumAdvancesSinceCollection = 0i64;
  v8 = (Scaleform::MemoryHeap *)v5->pLib;
  v6->ActionQueue.Entries[0].pInsertEntry = 0i64;
  v6->ActionQueue.Entries[0].pLastEntry = 0i64;
  v6->ActionQueue.Entries[0].pActionRoot = 0i64;
  v6->ActionQueue.Entries[1].pInsertEntry = 0i64;
  v6->ActionQueue.Entries[1].pLastEntry = 0i64;
  v6->ActionQueue.Entries[1].pActionRoot = 0i64;
  v6->ActionQueue.Entries[2].pInsertEntry = 0i64;
  v6->ActionQueue.Entries[2].pLastEntry = 0i64;
  v6->ActionQueue.Entries[2].pActionRoot = 0i64;
  v6->ActionQueue.Entries[3].pInsertEntry = 0i64;
  v6->ActionQueue.Entries[3].pLastEntry = 0i64;
  v6->ActionQueue.Entries[3].pActionRoot = 0i64;
  v6->ActionQueue.Entries[4].pInsertEntry = 0i64;
  v6->ActionQueue.Entries[4].pLastEntry = 0i64;
  v6->ActionQueue.Entries[4].pActionRoot = 0i64;
  v6->ActionQueue.Entries[5].pInsertEntry = 0i64;
  v6->ActionQueue.Entries[5].pLastEntry = 0i64;
  v6->ActionQueue.Entries[5].pActionRoot = 0i64;
  v6->ActionQueue.Entries[6].pInsertEntry = 0i64;
  v6->ActionQueue.Entries[6].pLastEntry = 0i64;
  v6->ActionQueue.Entries[6].pActionRoot = 0i64;
  v6->ActionQueue.pHeap = v8;
  v6->ActionQueue.ModId = 1;
  v6->ActionQueue.pFreeEntry = 0i64;
  v6->ActionQueue.FreeEntriesCount = 0;
  v6->mEventChains.Chains.mHash.pTable = 0i64;
  v6->pStage.pObject = 0i64;
  Scaleform::GFx::AS3::StringManager::StringManager(
    &v6->BuiltinsMgr,
    *(Scaleform::GFx::ASStringManager **)(*(_QWORD *)v7 + 24i64));
  `eh vector constructor iterator(
    v6->mMouseState,
    0xE0ui64,
    6,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::MovieRoot::MouseState::MouseState);
  v6->StageInvalidated = 0;
  v6->LoadedMovieDefs.mHash.pTable = 0i64;
  v6->Flags = 0;
  v6->AccelerometerArray.pObject = 0i64;
  v6->AccelerometerArray.Owner = 1;
  v6->GeolocationArray.pObject = 0i64;
  v6->GeolocationArray.Owner = 1;
  v6->ExtensionContextArray.pObject = 0i64;
  v6->ExtensionContextArray.Owner = 1;
  v6->ASFramesToExecute = 0;
  v6->pMovieImpl = v4;
  Scaleform::GFx::MovieImpl::SetASMovieRoot(v4, (Scaleform::GFx::ASMovieRootBase *)&v6->vfptr);
  Scaleform::GFx::AS3::MovieRoot::CreateObjectInterface(v6, v4);
  Scaleform::GFx::MovieImpl::SetKeyboardListener(v4, (Scaleform::GFx::KeyboardState::IListener *)&v6->vfptr);
  v6->pInvokeAliases = 0i64;
  v4->Flags &= 0xDF7FFFFF;
  v4->Flags |= 0x10400000u;
  v6->MainLoaderInfoEventsState = 0;
}

// File Line: 237
// RVA: 0x78CBA0
void __fastcall Scaleform::GFx::AS3::MovieRoot::~MovieRoot(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::MovieRoot *v1; // rdi
  Scaleform::RefCountNTSImpl *v2; // rcx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v3; // rsi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v4; // rbx
  Scaleform::GFx::AS3::WeakProxy *v5; // rdx
  bool v6; // zf
  Scaleform::GFx::AS3::ASVM *v7; // rcx
  Scaleform::Render::RenderBuffer *v8; // rcx
  Scaleform::Render::RenderBuffer *v9; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable{for `Scaleform::GFx::ASMovieRootBase};
  this->vfptr = (Scaleform::GFx::AS3::FlashUIVtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable{for `Scaleform::GFx::AS3::FlashUI};
  this->vfptr = (Scaleform::GFx::KeyboardState::IListenerVtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable{for `Scaleform::GFx::KeyboardState::IListener};
  this->vfptr = (Scaleform::GFx::MovieDefImpl::ReleaseNotifierVtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable{for `Scaleform::GFx::MovieDefImpl::ReleaseNotifier};
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy>>::~AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy>>((Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> > *)&this->ExtensionContextArray);
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy>>::~AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy>>(&v1->GeolocationArray);
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy>>::~AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy>>((Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> > *)&v1->AccelerometerArray);
  Scaleform::HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::~HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>((Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&v1->LoadedMovieDefs);
  `eh vector destructor iterator(
    v1->mMouseState,
    0xE0ui64,
    6,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::MovieRoot::MouseState::~MouseState);
  Scaleform::GFx::ASStringManager::ReleaseBuiltinArray(v1->BuiltinsMgr.pStringManager, v1->BuiltinsMgr.Builtins, 0x40u);
  v2 = (Scaleform::RefCountNTSImpl *)&v1->pStage.pObject->vfptr;
  if ( v2 )
    Scaleform::RefCountNTSImpl::Release(v2);
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> > *)&v1->mEventChains.Chains.mHash.pTable);
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType::Clear(&v1->ActionQueue);
  v3 = v1->ActionQueue.pFreeEntry;
  if ( v3 )
  {
    do
    {
      v4 = v3->pNextEntry;
      Scaleform::GFx::AS3::MovieRoot::ActionEntry::~ActionEntry(v3);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
      v3 = v4;
    }
    while ( v4 );
  }
  if ( (v1->ExternalIntfRetVal.Flags & 0x1F) > 9 )
  {
    if ( (v1->ExternalIntfRetVal.Flags >> 9) & 1 )
    {
      v5 = v1->ExternalIntfRetVal.Bonus.pWeakProxy;
      v6 = v5->RefCount-- == 1;
      if ( v6 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v1->ExternalIntfRetVal.Bonus.pWeakProxy = 0i64;
      v1->ExternalIntfRetVal.value.VNumber = 0.0;
      v1->ExternalIntfRetVal.value.VS._2.VObj = 0i64;
      v1->ExternalIntfRetVal.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v1->ExternalIntfRetVal);
    }
  }
  v7 = v1->pAVM.pObject;
  if ( v7 )
  {
    if ( v1->pAVM.Owner )
    {
      v1->pAVM.Owner = 0;
      v7->vfptr->__vecDelDtor((Scaleform::GFx::AS3::VM *)&v7->vfptr, 1u);
    }
    v1->pAVM.pObject = 0i64;
  }
  v1->pAVM.Owner = 0;
  Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(v1->MemContext.pObject->ASGC.pObject, 0i64, 1u);
  v8 = (Scaleform::Render::RenderBuffer *)v1->MemContext.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  v1->vfptr = (Scaleform::GFx::MovieDefImpl::ReleaseNotifierVtbl *)&Scaleform::GFx::MovieDefImpl::ReleaseNotifier::`vftable;
  v1->vfptr = (Scaleform::GFx::KeyboardState::IListenerVtbl *)&Scaleform::GFx::KeyboardState::IListener::`vftable;
  v1->vfptr = (Scaleform::GFx::AS3::FlashUIVtbl *)&Scaleform::GFx::AS3::FlashUI::`vftable;
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASMovieRootBase::`vftable;
  v9 = (Scaleform::Render::RenderBuffer *)v1->pASSupport.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 241
// RVA: 0x8212C0
void __fastcall Scaleform::GFx::AS3::MovieRoot::Shutdown(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::MovieRoot *v1; // rdi
  Scaleform::RefCountNTSImpl *v2; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v3; // rbx
  Scaleform::GFx::AS3::WeakProxy *v4; // rdx
  bool v5; // zf
  Scaleform::RefCountNTSImpl **v6; // rbx
  signed __int64 v7; // rsi
  signed __int64 v8; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> >::TableType *v9; // rcx
  unsigned __int64 v10; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> >::TableType *v11; // rax
  __int64 v12; // rcx
  Scaleform::GFx::MovieDefImpl *v13; // rcx
  unsigned __int64 v14; // rdx
  _QWORD *v15; // rcx
  Scaleform::GFx::MovieDefRootNode *i; // rbx
  signed __int64 v17; // rax
  Scaleform::GFx::AS3::ASVM *v18; // rcx

  v1 = this;
  Scaleform::GFx::MovieImpl::ClearPlayList(this->pMovieImpl);
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType::Clear(&v1->ActionQueue);
  v2 = (Scaleform::RefCountNTSImpl *)&v1->pStage.pObject->vfptr;
  if ( v2 )
    Scaleform::RefCountNTSImpl::Release(v2);
  v1->pStage.pObject = 0i64;
  v1->vfptr[9].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, 2u);
  v3 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v1->pInvokeAliases->mHash.pTable;
  if ( v3 )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Clear(v3);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
  v1->pInvokeAliases = 0i64;
  if ( (v1->ExternalIntfRetVal.Flags & 0x1F) > 9 )
  {
    if ( (v1->ExternalIntfRetVal.Flags >> 9) & 1 )
    {
      v4 = v1->ExternalIntfRetVal.Bonus.pWeakProxy;
      v5 = v4->RefCount-- == 1;
      if ( v5 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v1->ExternalIntfRetVal.Bonus.pWeakProxy = 0i64;
      v1->ExternalIntfRetVal.value.VNumber = 0.0;
      v1->ExternalIntfRetVal.value.VS._2.VObj = 0i64;
      v1->ExternalIntfRetVal.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v1->ExternalIntfRetVal);
    }
  }
  v1->ExternalIntfRetVal.Flags &= 0xFFFFFFE0;
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> > *)&v1->mEventChains.Chains.mHash.pTable);
  v6 = (Scaleform::RefCountNTSImpl **)&v1->mMouseState[0].LastMouseOverObj;
  v7 = 6i64;
  do
  {
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *)v6
    - 1,
      v6 - 3,
      0i64);
    if ( *v6 )
      Scaleform::RefCountNTSImpl::Release(*v6);
    *v6 = 0i64;
    v6 += 28;
    --v7;
  }
  while ( v7 );
  v8 = (signed __int64)&v1->LoadedMovieDefs;
  v9 = v1->LoadedMovieDefs.mHash.pTable;
  v10 = 0i64;
  if ( v9 )
  {
    v11 = v9 + 1;
    do
    {
      if ( v11->EntryCount != -2i64 )
        break;
      ++v10;
      v11 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> >::TableType *)((char *)v11 + 24);
    }
    while ( v10 <= v9->SizeMask );
  }
  else
  {
    v8 = 0i64;
  }
  while ( v8 )
  {
    v12 = *(_QWORD *)v8;
    if ( !*(_QWORD *)v8 || (signed __int64)v10 > *(_QWORD *)(v12 + 8) )
      break;
    v13 = *(Scaleform::GFx::MovieDefImpl **)(v12 + 24 * v10 + 24);
    if ( v13 )
      Scaleform::GFx::MovieDefImpl::RemoveReleaseNotifier(
        v13,
        (Scaleform::GFx::MovieDefImpl::ReleaseNotifier *)&v1->vfptr);
    v14 = *(_QWORD *)(*(_QWORD *)v8 + 8i64);
    if ( (signed __int64)v10 <= (signed __int64)v14 && ++v10 <= v14 )
    {
      v15 = (_QWORD *)(*(_QWORD *)v8 + 24 * v10 + 16);
      do
      {
        if ( *v15 != -2i64 )
          break;
        ++v10;
        v15 += 3;
      }
      while ( v10 <= v14 );
    }
  }
  for ( i = v1->pMovieImpl->RootMovieDefNodes.Root.pNext; ; i = i->pNext )
  {
    v17 = (signed __int64)(v1->pMovieImpl == (Scaleform::GFx::MovieImpl *)-112i64 ? 0i64 : &v1->pMovieImpl->MovieLevels.Data.Policy);
    if ( i == (Scaleform::GFx::MovieDefRootNode *)v17 )
      break;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&i[1],
      &i[1],
      0i64);
  }
  v1->vfptr[9].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, 2u);
  Scaleform::GFx::AS3::VM::UnregisterAllAbcFiles((Scaleform::GFx::AS3::VM *)&v1->pAVM.pObject->vfptr);
  v1->vfptr[9].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, 2u);
  v18 = v1->pAVM.pObject;
  if ( v18 )
  {
    if ( v1->pAVM.Owner )
    {
      v1->pAVM.Owner = 0;
      v18->vfptr->__vecDelDtor((Scaleform::GFx::AS3::VM *)&v18->vfptr, 1u);
    }
    v1->pAVM.pObject = 0i64;
  }
  v1->pAVM.Owner = 0;
}

// File Line: 286
// RVA: 0x7F2C20
char __fastcall Scaleform::GFx::AS3::MovieRoot::Init(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::MovieDefImpl *pmovieDef)
{
  Scaleform::GFx::MovieDefImpl *v2; // rbx
  Scaleform::GFx::AS3::MovieRoot *v3; // rdi

  v2 = pmovieDef;
  v3 = this;
  ((void (*)(void))this->vfptr[4].__vecDelDtor)();
  Scaleform::GFx::AS3::MovieRoot::CreateStage(v3, v2);
  Scaleform::GFx::MovieImpl::SetLevelMovie(
    v3->pMovieImpl,
    0,
    (Scaleform::GFx::DisplayObjContainer *)&v3->pStage.pObject->vfptr);
  v3->vfptr[39].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, (unsigned int)v3->pStage.pObject);
  return 1;
}

// File Line: 314
// RVA: 0x7B35C0
bool __fastcall Scaleform::GFx::AS3::MovieRoot::CheckAvm(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::MovieRoot *v1; // rbx
  Scaleform::GFx::ActionControl *v2; // rsi
  Scaleform::GFx::ActionControl *v3; // rcx
  Scaleform::GFx::AS3::ASVM *v4; // r10
  Scaleform::GFx::AS3::ASVM *v5; // rax
  Scaleform::GFx::AS3::ASVM *v6; // rsi
  Scaleform::GFx::AS3::ASVM *v7; // rcx
  Scaleform::Ptr<Scaleform::GFx::ActionControl> result; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::ASVM *v10; // [rsp+58h] [rbp+10h]

  v1 = this;
  if ( !this->pAVM.pObject )
  {
    v2 = Scaleform::GFx::StateBag::GetActionControl((Scaleform::GFx::StateBag *)&this->pMovieImpl->vfptr, &result)->pObject;
    v3 = result.pObject;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( v2 )
      v1->NeedToCheck = v2->ActionFlags & 1;
    else
      v1->NeedToCheck = 0;
    v1->State = 3;
    result.pObject = (Scaleform::GFx::ActionControl *)v1->pMovieImpl->pHeap;
    v4 = (Scaleform::GFx::AS3::ASVM *)((__int64 (__fastcall *)(Scaleform::GFx::ActionControl *, signed __int64, _QWORD))result.pObject->vfptr[10].__vecDelDtor)(
                                        v3,
                                        984i64,
                                        0i64);
    v10 = v4;
    if ( v4 )
    {
      Scaleform::GFx::AS3::ASVM::ASVM(
        v4,
        v1,
        (Scaleform::GFx::AS3::FlashUI *)&v1->vfptr,
        &v1->BuiltinsMgr,
        v1->MemContext.pObject->ASGC.pObject);
      v6 = v5;
    }
    else
    {
      v6 = 0i64;
    }
    v7 = v1->pAVM.pObject;
    if ( v7 != v6 )
    {
      if ( v7 && v1->pAVM.Owner )
      {
        v1->pAVM.Owner = 0;
        v7->vfptr->__vecDelDtor((Scaleform::GFx::AS3::VM *)&v7->vfptr, 1u);
      }
      v1->pAVM.pObject = v6;
    }
    v1->pAVM.Owner = v6 != 0i64;
    Scaleform::GFx::AS3::VM::ExecuteCode((Scaleform::GFx::AS3::VM *)&v1->pAVM.pObject->vfptr, 1u);
  }
  return v1->pAVM.pObject != 0i64;
}

// File Line: 336
// RVA: 0x7CAA70
_BOOL8 __fastcall Scaleform::GFx::AS3::MovieRoot::ExecuteAbc(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::AbcDataBuffer *pabc, Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::DisplayObjContainer *v3; // r12
  Scaleform::GFx::AS3::AbcDataBuffer *v4; // rdi
  Scaleform::GFx::AS3::MovieRoot *v5; // r13
  Scaleform::GFx::MovieDefImpl *v6; // rsi
  __int64 v7; // rax
  Scaleform::GFx::AS3::VMAppDomain *v8; // r14
  __int64 v9; // rcx
  Scaleform::GFx::AS3::VMAbcFile *v10; // rax
  __int64 v11; // rax
  __int64 v12; // rcx
  Scaleform::GFx::AS3::Abc::Reader *v13; // rbx
  Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef *v14; // rax
  Scaleform::GFx::AS3::Abc::File *v15; // rax
  Scaleform::GFx::AS3::Abc::File *v16; // rsi
  bool v17; // di
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v18; // r14
  Scaleform::GFx::AS3::VMAbcFile *v19; // rcx
  unsigned int v20; // eax
  Scaleform::GFx::AS3::VMAbcFile *v21; // rcx
  unsigned int v22; // eax
  Scaleform::GFx::AS3::VM *v23; // rcx
  Scaleform::GFx::MovieDefRootNode *v24; // rax
  Scaleform::GFx::MovieDefRootNode *v25; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v26; // rdx
  Scaleform::GFx::AS3::VMAbcFile *v27; // rax
  Scaleform::GFx::AS3::VMAbcFile *v28; // rcx
  unsigned int v29; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> result; // [rsp+B0h] [rbp+48h]
  Scaleform::String src; // [rsp+B8h] [rbp+50h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> v33; // [rsp+C0h] [rbp+58h]
  Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> file; // [rsp+C8h] [rbp+60h]

  v3 = m;
  v4 = pabc;
  v5 = this;
  v6 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))m->vfptr[66].__vecDelDtor)(m);
  Scaleform::String::String(&src, (Scaleform::String *)&v4->FileName.0);
  if ( *(_QWORD *)(v4->Name.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64 )
  {
    Scaleform::String::AppendString(&src, "[", -1i64);
    Scaleform::String::operator+=(&src, &v4->Name);
    Scaleform::String::AppendString(&src, "]", -1i64);
  }
  v7 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr
                                                                   + 4 * (unsigned __int8)v3->AvmObjOffset))[5].__vecDelDtor)();
  if ( v7 )
    v7 -= 72i64;
  v8 = *(Scaleform::GFx::AS3::VMAppDomain **)(v7 + 40);
  Scaleform::GFx::AS3::VM::FindVMAbcFileWeak(
    (Scaleform::GFx::AS3::VM *)&v5->pAVM.pObject->vfptr,
    &result,
    (const char *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    *(Scaleform::GFx::AS3::VMAppDomain **)(v7 + 40));
  v10 = result.pObject;
  if ( result.pObject )
  {
    v17 = 1;
  }
  else
  {
    v33.pObject = (Scaleform::GFx::AS3::VMAbcFile *)v5->pMovieImpl->pHeap;
    v11 = ((__int64 (__fastcall *)(__int64, signed __int64))v33.pObject->vfptr[3].~RefCountBaseGC<328>)(v9, 16i64);
    v13 = (Scaleform::GFx::AS3::Abc::Reader *)v11;
    file.pObject = (Scaleform::GFx::AS3::Abc::File *)v11;
    if ( v11 )
    {
      *(_QWORD *)v11 = v4->DataSize;
      *(_QWORD *)(v11 + 8) = (char *)v4 + 40;
    }
    else
    {
      v13 = 0i64;
    }
    v33.pObject = (Scaleform::GFx::AS3::VMAbcFile *)v5->pMovieImpl->pHeap;
    v14 = (Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef *)((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))v33.pObject->vfptr[3].~RefCountBaseGC<328>)(
                                                              v12,
                                                              384i64,
                                                              0i64);
    file.pObject = (Scaleform::GFx::AS3::Abc::File *)&v14->vfptr;
    if ( v14 )
    {
      Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef::AbcFileWithMovieDef(v14, v6, v4);
      v16 = v15;
    }
    else
    {
      v16 = 0i64;
    }
    file.pObject = v16;
    Scaleform::String::operator=(&v16->Source, &src);
    v16->DataSize = v4->DataSize;
    v17 = Scaleform::GFx::AS3::Abc::Reader::Read(v13, v16);
    if ( v17 )
    {
      Scaleform::GFx::AS3::MovieRoot::CheckAvm(v5);
      v18 = Scaleform::GFx::AS3::VM::LoadFile((Scaleform::GFx::AS3::VM *)&v5->pAVM.pObject->vfptr, &v33, &file, v8, 0);
      if ( v18 != &result )
      {
        if ( v18->pObject )
          v18->pObject->RefCount = (v18->pObject->RefCount + 1) & 0x8FBFFFFF;
        v19 = result.pObject;
        if ( result.pObject )
        {
          if ( (_QWORD)result.pObject & 1 )
          {
            --result.pObject;
          }
          else
          {
            v20 = result.pObject->RefCount;
            if ( v20 & 0x3FFFFF )
            {
              result.pObject->RefCount = v20 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v19->vfptr);
            }
          }
        }
        result.pObject = v18->pObject;
      }
      v21 = v33.pObject;
      if ( v33.pObject )
      {
        if ( (_QWORD)v33.pObject & 1 )
        {
          --v33.pObject;
        }
        else
        {
          v22 = v33.pObject->RefCount;
          if ( v22 & 0x3FFFFF )
          {
            v33.pObject->RefCount = v22 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v21->vfptr);
          }
        }
      }
      v23 = (Scaleform::GFx::AS3::VM *)&v5->pAVM.pObject->vfptr;
      if ( v23->HandleException )
      {
        Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v23);
        v17 = 0;
      }
    }
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v16);
    if ( v13 )
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v13);
    v10 = result.pObject;
  }
  if ( v10 )
  {
    v24 = Scaleform::GFx::DisplayObjContainer::FindRootNode(v3);
    v25 = v24 + 1;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v24[1],
      &v24[1],
      (unsigned __int64)&v24[1].pPrev->vfptr + 1);
    v26 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&v25->vfptr[(_QWORD)v25->pPrev - 1];
    if ( v26 )
    {
      v26->pObject = result.pObject;
      v27 = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        v27->RefCount &= 0x8FBFFFFF;
      }
    }
  }
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
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8), 0xFFFFFFFF) == 1 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  return v17;
}

// File Line: 408
// RVA: 0x805BB0
void __fastcall Scaleform::GFx::AS3::MovieRoot::Output(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::FlashUI::OutputMessageType type, const char *msg)
{
  const char *v3; // rdi
  Scaleform::GFx::AS3::FlashUI::OutputMessageType v4; // ebx
  Scaleform::GFx::LogState *v5; // r10
  int v6; // ebx
  int v7; // ebx
  int v8; // eax
  Scaleform::LogMessageId messageType; // [rsp+30h] [rbp+8h]

  v3 = msg;
  v4 = type;
  v5 = (Scaleform::GFx::LogState *)Scaleform::GFx::MovieImpl::GetCachedLog(*(Scaleform::GFx::MovieImpl **)&this[-1].GeolocationArray.Owner);
  if ( v5 )
  {
    v6 = v4 - 1;
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
    Scaleform::Log::LogMessageById(v5, (Scaleform::LogMessageId)&messageType, "%s", v3);
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
void __fastcall Scaleform::GFx::AS3::MovieRoot::GenerateMouseEvents(Scaleform::GFx::AS3::MovieRoot *this, unsigned int mouseIndex)
{
  __int64 v2; // r14
  Scaleform::GFx::AS3::MovieRoot *v3; // r13
  Scaleform::GFx::MouseState *v4; // r15
  __int64 v5; // rax
  Scaleform::GFx::AS3::AvmDisplayObj *v6; // rcx
  Scaleform::GFx::InteractiveObject *v7; // rbx
  Scaleform::GFx::InteractiveObject *v8; // rsi
  Scaleform::GFx::KeyboardState *v9; // rcx
  __int64 v10; // rdi
  Scaleform::GFx::InteractiveObject **v11; // r8
  signed int v12; // ecx
  unsigned int v13; // ecx
  Scaleform::GFx::InteractiveObject *v14; // rax
  char v15; // dl
  Scaleform::GFx::InteractiveObject *v16; // rbx
  char v17; // al
  char v18; // cl
  signed __int64 v19; // r13
  __int64 v20; // rcx
  Scaleform::GFx::InteractiveObject *v21; // rdx
  signed __int64 v22; // rbx
  __int64 v23; // rsi
  char v24; // r15
  __int64 v25; // rcx
  signed __int64 v26; // rcx
  __int64 v27; // r8
  char v28; // al
  char v29; // dl
  __int64 v30; // rcx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *v31; // r12
  unsigned __int64 v32; // r14
  unsigned __int64 v33; // rbx
  Scaleform::GFx::InteractiveObject *v34; // rcx
  unsigned __int64 i; // rbx
  __int64 v36; // rbx
  Scaleform::RefCountNTSImpl *v37; // rcx
  Scaleform::GFx::InteractiveObject *v38; // rcx
  __int64 v39; // rax
  signed __int64 v40; // rax
  char v41; // dl
  char v42; // r8
  Scaleform::RefCountNTSImpl *v43; // rcx
  unsigned __int8 v44; // r14
  Scaleform::GFx::InteractiveObject *v45; // rsi
  unsigned int v46; // eax
  signed __int64 v47; // r12
  signed __int64 v48; // r13
  Scaleform::GFx::InteractiveObject *v49; // rax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v50; // rax
  unsigned __int64 v51; // rax
  __int64 v52; // rdx
  unsigned __int64 v53; // rcx
  int v54; // eax
  __int64 v55; // rax
  char v56; // al
  int v57; // eax
  float v58; // xmm1_4
  int v59; // ecx
  unsigned int v60; // er12
  Scaleform::GFx::InteractiveObject *v61; // r14
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v62; // rax
  signed int v63; // ebx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v64; // rax
  bool v65; // r14
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v66; // rax
  bool v67; // bl
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v68; // rax
  Scaleform::GFx::InteractiveObject *v69; // r13
  __int64 v70; // r14
  __int64 v71; // rdx
  signed __int64 v72; // rdx
  Scaleform::GFx::InteractiveObject *v73; // rbx
  Scaleform::GFx::InteractiveObject *v74; // rax
  Scaleform::GFx::InteractiveObject *v75; // r13
  Scaleform::GFx::InteractiveObject *v76; // rsi
  Scaleform::GFx::InteractiveObject *v77; // r15
  char v78; // cl
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *v79; // r12
  unsigned __int64 v80; // r13
  Scaleform::GFx::InteractiveObject *v81; // rcx
  signed __int64 v82; // r14
  unsigned __int64 v83; // r8
  Scaleform::GFx::InteractiveObject *v84; // rcx
  Scaleform::GFx::InteractiveObject *v85; // r14
  bool v86; // zf
  __int64 v87; // rax
  signed __int64 v88; // rdx
  char v89; // cl
  Scaleform::RefCountNTSImpl *v90; // rcx
  __int64 v91; // r13
  unsigned __int8 v92; // r14
  char v93; // si
  Scaleform::WeakPtrProxy *v94; // rbx
  Scaleform::WeakPtrProxy *v95; // rdx
  Scaleform::WeakPtrProxy *v96; // rdx
  __int64 v97; // [rsp+20h] [rbp-A0h]
  int v98; // [rsp+28h] [rbp-98h]
  unsigned __int8 v99; // [rsp+2Ch] [rbp-94h]
  char v100; // [rsp+30h] [rbp-90h]
  char v101; // [rsp+31h] [rbp-8Fh]
  char v102; // [rsp+32h] [rbp-8Eh]
  char v103; // [rsp+33h] [rbp-8Dh]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> result; // [rsp+38h] [rbp-88h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> v105; // [rsp+40h] [rbp-80h]
  Scaleform::GFx::MouseState *v106; // [rsp+48h] [rbp-78h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> v107; // [rsp+50h] [rbp-70h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> v108; // [rsp+58h] [rbp-68h]
  Scaleform::GFx::MovieImpl::DragState st; // [rsp+60h] [rbp-60h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> v110; // [rsp+90h] [rbp-30h]
  Scaleform::GFx::InteractiveObject *v111; // [rsp+98h] [rbp-28h]
  __int64 v112; // [rsp+A0h] [rbp-20h]
  Scaleform::GFx::AS3::MovieRoot *v113; // [rsp+110h] [rbp+50h]
  unsigned int v114; // [rsp+118h] [rbp+58h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> v115; // [rsp+120h] [rbp+60h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> v116; // [rsp+128h] [rbp+68h]

  v112 = -2i64;
  v2 = mouseIndex;
  v3 = this;
  LODWORD(st.pCharacter) = 0;
  if ( mouseIndex < 6 )
    v4 = &this->pMovieImpl->mMouseState[mouseIndex];
  else
    v4 = 0i64;
  v106 = v4;
  Scaleform::GFx::MouseState::GetActiveEntity(v4, &result);
  Scaleform::GFx::MouseState::GetTopmostEntity(v4, &v105);
  st.pCharacter = 0i64;
  st.pTopmostEntity = 0i64;
  *(_WORD *)&st.LockCenter = 0;
  st.BoundLT = 0i64;
  st.BoundRB = 0i64;
  st.CenterDelta = 0i64;
  st.MouseIndex = -1;
  Scaleform::GFx::MovieImpl::GetDragState(v3->pMovieImpl, v2, &st);
  if ( st.MouseIndex != (_DWORD)v2 || !st.pCharacter || (st.pCharacter->Flags >> 12) & 1 )
    goto LABEL_17;
  if ( !st.pTopmostEntity )
    goto LABEL_199;
  v5 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&st.pTopmostEntity->vfptr
                                                                   + 4
                                                                   * (unsigned __int8)st.pTopmostEntity->AvmObjOffset))[1].__vecDelDtor)();
  v6 = (Scaleform::GFx::AS3::AvmDisplayObj *)(v5 - 56);
  if ( !v5 )
    v6 = 0i64;
  if ( !Scaleform::GFx::AS3::AvmDisplayObj::IsStageAccessible(v6) )
  {
LABEL_199:
    Scaleform::GFx::MovieImpl::SetDragStateTopmostEntity(v3->pMovieImpl, v2, v105.pObject);
LABEL_17:
    v7 = v105.pObject;
    goto LABEL_18;
  }
  v7 = st.pTopmostEntity;
  if ( st.pTopmostEntity )
    ++st.pTopmostEntity->RefCount;
  if ( v105.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v105.pObject->vfptr);
  v105.pObject = v7;
LABEL_18:
  v8 = result.pObject;
  st.pTopmostEntity = result.pObject;
  if ( result.pObject && (LOBYTE(result.pObject->Flags) >> 4) & 1 )
  {
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
    v8 = 0i64;
    st.pTopmostEntity = 0i64;
    result.pObject = 0i64;
    v7 = v105.pObject;
  }
  if ( v7 && (LOBYTE(v7->Flags) >> 4) & 1 )
  {
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v7->vfptr);
    v105.pObject = 0i64;
    v8 = result.pObject;
    st.pTopmostEntity = result.pObject;
  }
  if ( v8 )
  {
    ++v8->RefCount;
    v8 = result.pObject;
    st.pTopmostEntity = result.pObject;
  }
  v111 = v8;
  if ( (unsigned int)v2 >= 6 )
    v9 = 0i64;
  else
    v9 = &v3->pMovieImpl->KeyboardStates[v2];
  v10 = (unsigned __int8)Scaleform::GFx::KeyboardState::GetKeyModifiers(v9, (Scaleform::KeyModifiers *)&v115)->States;
  v12 = 1;
  if ( v3->pAVM.pObject->ExtensionsEnabled )
    v12 = 16;
  HIDWORD(st.pCharacter) = v12;
  v13 = v4->PrevButtonsState;
  LODWORD(st.BoundLT.y) = v13 ^ v4->CurButtonsState;
  v14 = v105.pObject;
  if ( !v105.pObject )
    v105.pObject = (Scaleform::GFx::InteractiveObject *)&v3->pStage.pObject->vfptr;
  if ( v13 & 1 )
  {
    if ( *((_BYTE *)v4 + 76) & 4 )
    {
      v16 = result.pObject;
      if ( v14 == result.pObject )
        goto LABEL_78;
      if ( result.pObject )
      {
        v17 = result.pObject->RollOverCnt;
        if ( v17 )
        {
          v18 = v17 - 1;
          result.pObject->RollOverCnt = v17 - 1;
          v16 = result.pObject;
        }
        else
        {
          v18 = -1;
        }
        v97 = 0x10000i64;
        v98 = 0;
        v103 = 0;
        v99 = 0;
        v101 = v2;
        v100 = v18;
        v102 = v10;
        v16->vfptr[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v16->vfptr, (unsigned int)&v97);
      }
      *((_BYTE *)v4 + 76) &= 0xFBu;
    }
    else
    {
      if ( v14 != result.pObject )
      {
LABEL_48:
        v19 = 224 * v2;
        v20 = (__int64)v113;
        v21 = (Scaleform::GFx::InteractiveObject *)v113->mMouseState[v2].RolloverStack.Data.Size;
        v115.pObject = v21;
        v22 = (signed __int64)&v21[-1].DisplayCallbackUserPtr + 7;
        if ( (signed __int64)&v21[-1].DisplayCallbackUserPtr + 7 >= 0 )
        {
          v23 = (__int64)v113;
          v24 = v114;
          while ( 1 )
          {
            if ( v14 )
            {
              v25 = *(_QWORD *)(224 * (v2 + 4) + v23);
              if ( *(Scaleform::GFx::InteractiveObject **)(v25 + 8 * v22) == v14
                || Scaleform::GFx::DisplayObjectBase::IsAncestor(
                     *(Scaleform::GFx::DisplayObjectBase **)(v25 + 8 * v22),
                     (Scaleform::GFx::DisplayObjectBase *)&v14->vfptr) )
              {
                break;
              }
            }
            v26 = 224 * (v2 + 4);
            v27 = *(_QWORD *)(*(_QWORD *)(v26 + v23) + 8 * v22);
            v28 = *(_BYTE *)(v27 + 192);
            if ( v28 )
            {
              v29 = v28 - 1;
              *(_BYTE *)(v27 + 192) = v28 - 1;
            }
            else
            {
              v29 = -1;
            }
            v97 = 0x4000i64;
            v98 = 0;
            v103 = 0;
            v99 = 0;
            v101 = v24;
            v100 = v29;
            v102 = v10;
            v30 = *(_QWORD *)(*(_QWORD *)(v26 + v23) + 8 * v22);
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v30 + 800i64))(v30, &v97);
            if ( --v22 < 0 )
              break;
            v14 = v105.pObject;
          }
          v8 = st.pTopmostEntity;
          v4 = v106;
          v21 = v115.pObject;
          v20 = (__int64)v113;
        }
        v31 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *)(v20 + 224 * (v2 + 4));
        v32 = v31->Size;
        v33 = v31->Size - (_QWORD)v21 + 1 + v22;
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          v31,
          v31,
          v33);
        if ( v33 > v32 )
        {
          v34 = (Scaleform::GFx::InteractiveObject *)&v31->Data[v32];
          v115.pObject = (Scaleform::GFx::InteractiveObject *)&v31->Data[v32];
          for ( i = v33 - v32; i; --i )
          {
            v116.pObject = v34;
            if ( v34 )
              v34->vfptr = 0i64;
            v34 = (Scaleform::GFx::InteractiveObject *)((char *)v34 + 8);
            v115.pObject = v34;
          }
        }
        v16 = result.pObject;
        if ( result.pObject )
        {
          ++result.pObject->RefCount;
          v36 = (__int64)v113;
          v37 = (Scaleform::RefCountNTSImpl *)&v113->mMouseState[(unsigned __int64)v19 / 0xE0].LastMouseOverObj.pObject->vfptr;
          if ( v37 )
            Scaleform::RefCountNTSImpl::Release(v37);
          v38 = result.pObject;
          *(Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)(v19 + v36 + 920) = result;
          if ( v38
            && (v39 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v38->vfptr
                                                                                  + 4
                                                                                  * (unsigned __int8)v38->AvmObjOffset))[1].__vecDelDtor)(),
                v38 = result.pObject,
                v39) )
          {
            v40 = v39 - 56;
          }
          else
          {
            v40 = 0i64;
          }
          v41 = *(_BYTE *)(v40 + 64);
          if ( v41 )
          {
            v42 = v41 - 1;
            *(_BYTE *)(v40 + 64) = v41 - 1;
            v38 = result.pObject;
          }
          else
          {
            v42 = -1;
          }
          v97 = 16777227i64;
          v98 = 0;
          v103 = 0;
          v99 = 0;
          v101 = v114;
          v100 = v42;
          v102 = v10;
          v38->vfptr[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v38->vfptr, (unsigned int)&v97);
          v43 = *(Scaleform::RefCountNTSImpl **)(v19 + v36 + 920);
          if ( v43 )
            Scaleform::RefCountNTSImpl::Release(v43);
          *(_QWORD *)(v19 + v36 + 920) = 0i64;
          v16 = result.pObject;
        }
        v3 = v113;
        v14 = v105.pObject;
        goto LABEL_78;
      }
      if ( result.pObject )
      {
        v15 = result.pObject->RollOverCnt;
        result.pObject->RollOverCnt = v15 + 1;
        v97 = 0x8000i64;
        v98 = 0;
        v103 = 0;
        v99 = 0;
        v101 = v2;
        v100 = v15;
        v102 = v10;
        result.pObject->vfptr[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)result.pObject, (unsigned int)&v97);
      }
      *((_BYTE *)v4 + 76) |= 4u;
    }
    v14 = v105.pObject;
  }
  v16 = result.pObject;
  if ( v14 != result.pObject )
    goto LABEL_48;
LABEL_78:
  v44 = 0;
  if ( !BYTE4(st.pCharacter) )
    goto LABEL_110;
  v11 = (Scaleform::GFx::InteractiveObject **)dword_141864B20;
  v45 = v105.pObject;
  do
  {
    if ( (LODWORD(st.BoundLT.y) >> v44) & 1 && (1 << v44) & v4->PrevButtonsState )
    {
      if ( v44 <= 4u )
        v46 = dword_141864B20[v44];
      else
        v46 = (signed int)logf((float)v44);
      v47 = 3i64 * v46;
      v48 = (signed __int64)v3 + 224 * v114;
      v49 = Scaleform::GFx::MouseState::GetMouseButtonDownEntity(v4, &v110, v44)->pObject;
      v115.pObject = v49;
      if ( v110.pObject )
      {
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v110.pObject->vfptr);
        v49 = v115.pObject;
      }
      if ( v49 )
      {
        v97 = 4096i64;
        v98 = 0;
        v103 = 0;
        v99 = v44;
        v101 = v114;
        v100 = 0;
        v102 = v10;
        v50 = Scaleform::GFx::MouseState::GetMouseButtonDownEntity(v4, &v107, v44);
        v50->pObject->vfptr[100].__vecDelDtor(
          (Scaleform::RefCountNTSImplCore *)&v50->pObject->vfptr,
          (unsigned int)&v97);
        if ( v107.pObject )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v107.pObject->vfptr);
      }
      v106 = (Scaleform::GFx::MouseState *)32;
      LODWORD(v107.pObject) = 0;
      BYTE4(v107.pObject) = v44;
      BYTE1(v108.pObject) = v114;
      LOBYTE(v108.pObject) = 0;
      WORD1(v108.pObject) = (unsigned __int8)v10;
      v45->vfptr[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v45->vfptr, (unsigned int)&v106);
      if ( !(*((_BYTE *)v4 + 76) & 4) )
        goto LABEL_107;
      LOBYTE(v115.pObject) = 0;
      v51 = Scaleform::Timer::GetTicks();
      v52 = v51 * (unsigned __int128)0x624DD2F1A9FBE77ui64 >> 64;
      v53 = (v52 + ((v51 - v52) >> 1)) >> 9;
      *(_QWORD *)&st.LockCenter = (v52 + ((v51 - v52) >> 1)) >> 9;
      v54 = *(_DWORD *)(v48 + 4 * v47 + 928);
      if ( !v54
        || (unsigned int)v53 > v54 + 300
        || COERCE_SIGNED_INT(*(float *)(v48 + 4 * v47 + 932) * 0.050000001) != COERCE_SIGNED_INT(v4->LastPosition.x * 0.050000001)
        || COERCE_SIGNED_INT(*(float *)(v48 + 4 * v47 + 936) * 0.050000001) != COERCE_SIGNED_INT(v4->LastPosition.y * 0.050000001) )
      {
        goto LABEL_200;
      }
      LOBYTE(v115.pObject) = 1;
      v55 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v45->vfptr
                                                                        + 4 * (unsigned __int8)v45->AvmObjOffset))[1].__vecDelDtor)();
      if ( v55 )
        v55 -= 56i64;
      if ( *(_BYTE *)(v55 + 65) & 2 )
      {
        v97 = 16777229i64;
        v98 = 0;
        v103 = 0;
        v99 = v44;
        v101 = v114;
        v100 = 0;
        v102 = v10;
        v45->vfptr[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v45->vfptr, (unsigned int)&v97);
      }
      else
      {
LABEL_200:
        v56 = v45 == Scaleform::GFx::MouseState::GetMouseButtonDownEntity(v4, &v108, v44)->pObject;
        LOBYTE(v116.pObject) = v56;
        if ( v108.pObject )
        {
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v108.pObject->vfptr);
          v56 = (char)v116.pObject;
        }
        if ( v56 )
        {
          v97 = 16777228i64;
          v98 = 0;
          v103 = 0;
          v99 = v44;
          v101 = v114;
          v100 = 0;
          v102 = v10;
          v45->vfptr[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v45->vfptr, (unsigned int)&v97);
        }
        if ( !LOBYTE(v115.pObject) )
        {
          v57 = *(_DWORD *)&st.LockCenter;
          goto LABEL_106;
        }
      }
      v57 = 0;
LABEL_106:
      *(_DWORD *)(v48 + 4 * v47 + 928) = v57;
      v58 = v4->LastPosition.y;
      *(float *)(v48 + 4 * v47 + 932) = v4->LastPosition.x;
      *(float *)(v48 + 4 * v47 + 936) = v58;
LABEL_107:
      Scaleform::GFx::MouseState::SetMouseButtonDownEntity(v4, v44, 0i64);
      v11 = (Scaleform::GFx::InteractiveObject **)dword_141864B20;
    }
    ++v44;
    v3 = v113;
  }
  while ( v44 < BYTE4(st.pCharacter) );
  v16 = result.pObject;
  v14 = v105.pObject;
  v8 = st.pTopmostEntity;
LABEL_110:
  v59 = v4->WheelDelta;
  v60 = v114;
  v61 = v105.pObject;
  if ( v59 )
  {
    v106 = (Scaleform::GFx::MouseState *)16777230;
    LODWORD(v107.pObject) = 0;
    BYTE4(v107.pObject) = 0;
    BYTE1(v108.pObject) = v114;
    LOBYTE(v108.pObject) = 0;
    BYTE2(v108.pObject) = v10;
    BYTE3(v108.pObject) = v59;
    v105.pObject->vfptr[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)v105.pObject, (unsigned int)&v106);
    v16 = result.pObject;
    v14 = v105.pObject;
  }
  if ( *((_BYTE *)v4 + 76) & 8 )
  {
    v106 = (Scaleform::GFx::MouseState *)8;
    LODWORD(v107.pObject) = 0;
    BYTE4(v107.pObject) = 0;
    BYTE1(v108.pObject) = v60;
    LOBYTE(v108.pObject) = 0;
    BYTE2(v108.pObject) = v10;
    BYTE3(v108.pObject) = v4->WheelDelta;
    v61->vfptr[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v61->vfptr, (unsigned int)&v106);
    v62 = Scaleform::GFx::MouseState::GetMouseButtonDownEntity(v4, &v116, 0);
    v63 = 1;
    LODWORD(st.pCharacter) = 1;
    v65 = 0;
    if ( v62->pObject )
    {
      v64 = Scaleform::GFx::MouseState::GetMouseButtonDownEntity(v4, &v115, 0);
      v63 = 3;
      LODWORD(st.pCharacter) = 3;
      if ( v64->pObject != v61 )
        v65 = 1;
    }
    if ( v63 & 2 )
    {
      v63 &= 0xFFFFFFFD;
      LODWORD(st.pCharacter) = v63;
      if ( v115.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v115.pObject->vfptr);
    }
    if ( v63 & 1 )
    {
      LODWORD(st.pCharacter) = v63 & 0xFFFFFFFE;
      if ( v116.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v116.pObject->vfptr);
    }
    if ( v65 )
    {
      v66 = Scaleform::GFx::MouseState::GetMouseButtonDownEntity(v4, &v115, 0);
      v67 = ((unsigned int (*)(void))v66->pObject->vfptr[81].__vecDelDtor)() == 4;
      if ( v115.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v115.pObject->vfptr);
      if ( v67 )
      {
        v97 = 8i64;
        v98 = 0;
        v103 = 0;
        v99 = 0;
        v101 = v60;
        v100 = 0;
        v102 = v10;
        v68 = Scaleform::GFx::MouseState::GetMouseButtonDownEntity(v4, &v115, 0);
        v68->pObject->vfptr[99].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v68->pObject->vfptr, (unsigned int)&v97);
        if ( v115.pObject )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v115.pObject->vfptr);
      }
    }
    v14 = v105.pObject;
    v16 = result.pObject;
  }
  if ( v14 == v16 )
  {
    if ( v14 )
      goto LABEL_172;
    v91 = (__int64)v113;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *)((char *)v113 + 224 * (v60 + 4i64)),
      (char *)v113 + 224 * (v60 + 4i64),
      0i64);
    v16 = result.pObject;
  }
  else
  {
    if ( v14 )
    {
      ++v14->RefCount;
      v16 = result.pObject;
      v14 = v105.pObject;
    }
    if ( v16 )
    {
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v16->vfptr);
      v14 = v105.pObject;
    }
    result.pObject = v14;
    if ( v14 )
    {
      v116.pObject = (Scaleform::GFx::InteractiveObject *)v60;
      v69 = (Scaleform::GFx::InteractiveObject *)(224i64 * v60);
      v115.pObject = v69;
      v70 = (__int64)v113;
      v71 = *(unsigned __int64 *)((char *)&v113->mMouseState[0].RolloverStack.Data.Size + (_QWORD)v69);
      if ( v71 && (v72 = v71 - 1, v72 >= 0) )
      {
        v11 = (Scaleform::GFx::InteractiveObject **)&(&v113->vfptr)[28 * (v60 + 4i64)][v72];
        while ( *v11 != v14 )
        {
          --v11;
          if ( --v72 < 0 )
            goto LABEL_141;
        }
      }
      else
      {
LABEL_141:
        ++v14->RefCount;
        v73 = result.pObject;
        v107.pObject = result.pObject;
        v74 = *(Scaleform::GFx::InteractiveObject **)(v70 + 352);
        v75 = *(Scaleform::GFx::InteractiveObject **)((char *)&v69[4].Id.Id + v70);
        v108.pObject = v75;
        if ( result.pObject )
        {
          v76 = v116.pObject;
          v77 = v74;
          do
          {
            if ( v73 == v77
              || v75
              && *(Scaleform::GFx::InteractiveObject **)(*(_QWORD *)(224i64 * ((_QWORD)v76 + 4) + v70)
                                                       + 8i64 * (_QWORD)v75
                                                       - 8) == v73 )
            {
              break;
            }
            v78 = v73->RollOverCnt;
            v73->RollOverCnt = v78 + 1;
            v106 = (Scaleform::GFx::MouseState *)0x2000;
            LODWORD(v107.pObject) = 0;
            BYTE4(v107.pObject) = 0;
            BYTE1(v108.pObject) = v60;
            LOBYTE(v108.pObject) = v78;
            WORD1(v108.pObject) = (unsigned __int8)v10;
            ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::MouseState **, Scaleform::GFx::InteractiveObject **))v73->vfptr[100].__vecDelDtor)(
              v73,
              &v106,
              v11);
            v79 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *)(v70 + 224i64 * ((_QWORD)v76 + 4));
            v80 = v79->Size;
            Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
              v79,
              v79,
              v80 + 1);
            if ( v80 + 1 > v80 )
            {
              v81 = (Scaleform::GFx::InteractiveObject *)&v79->Data[v80];
              v116.pObject = (Scaleform::GFx::InteractiveObject *)&v79->Data[v80];
              v82 = 1i64;
              do
              {
                *(_QWORD *)&st.LockCenter = v81;
                if ( v81 )
                  v81->vfptr = 0i64;
                v81 = (Scaleform::GFx::InteractiveObject *)((char *)v81 + 8);
                v116.pObject = v81;
                --v82;
              }
              while ( v82 );
            }
            v83 = v79->Size;
            v75 = v108.pObject;
            if ( (unsigned __int64)v108.pObject < v83 - 1 )
              memmove(
                &v79->Data[(_QWORD)v108.pObject + 1],
                &v79->Data[(_QWORD)v108.pObject],
                8 * (v83 - (unsigned __int64)v108.pObject) - 8);
            v84 = (Scaleform::GFx::InteractiveObject *)&v79->Data[(_QWORD)v75];
            v116.pObject = v84;
            *(_QWORD *)&st.LockCenter = v84;
            if ( v84 )
            {
              ++v73->RefCount;
              v84->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)v73;
            }
            v85 = v73->pParent;
            if ( v85 )
              ++v85->RefCount;
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v73->vfptr);
            v73 = v85;
            v107.pObject = v85;
            v86 = v85 == 0i64;
            v70 = (__int64)v113;
            LOBYTE(v60) = v114;
          }
          while ( !v86 );
          v8 = st.pTopmostEntity;
          v4 = v106;
        }
        if ( v73 )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v73->vfptr);
        v69 = v115.pObject;
        v14 = result.pObject;
      }
      if ( v14
        && (v87 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v14->vfptr
                                                                              + 4 * (unsigned __int8)v14->AvmObjOffset))[1].__vecDelDtor)()) != 0 )
      {
        v88 = v87 - 56;
      }
      else
      {
        v88 = 0i64;
      }
      v89 = *(_BYTE *)(v88 + 64);
      *(_BYTE *)(v88 + 64) = v89 + 1;
      v97 = 16777226i64;
      v98 = 0;
      v103 = 0;
      v99 = 0;
      v101 = v60;
      v100 = v89;
      v102 = v10;
      result.pObject->vfptr[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)result.pObject, (unsigned int)&v97);
      v90 = *(Scaleform::RefCountNTSImpl **)((char *)&v69[4].pParent + v70);
      if ( v90 )
        Scaleform::RefCountNTSImpl::Release(v90);
      *(Scaleform::GFx::InteractiveObject **)((char *)&v69[4].pParent + v70) = 0i64;
    }
    *((_BYTE *)v4 + 76) |= 4u;
    v16 = result.pObject;
LABEL_172:
    v91 = (__int64)v113;
  }
  v92 = 0;
  if ( BYTE4(st.pCharacter) )
  {
    v93 = v114;
    do
    {
      if ( (LODWORD(st.BoundLT.y) >> v92) & 1 && !((1 << v92) & v4->PrevButtonsState) )
      {
        v106 = (Scaleform::GFx::MouseState *)16;
        LODWORD(v107.pObject) = 0;
        BYTE1(v108.pObject) = v93;
        LOBYTE(v108.pObject) = 0;
        WORD1(v108.pObject) = (unsigned __int8)v10;
        if ( !v16 )
          v16 = *(Scaleform::GFx::InteractiveObject **)(v91 + 352);
        BYTE4(v107.pObject) = v92;
        v16->vfptr[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v16->vfptr, (unsigned int)&v106);
        Scaleform::GFx::MouseState::SetMouseButtonDownEntity(v4, v92, v16);
        *((_BYTE *)v4 + 76) |= 4u;
        v16 = result.pObject;
      }
      ++v92;
    }
    while ( v92 < BYTE4(st.pCharacter) );
    v8 = st.pTopmostEntity;
  }
  if ( v16 )
  {
    v94 = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy((Scaleform::RefCountWeakSupportImpl *)&v16->vfptr);
    v95 = v4->ActiveEntity.pProxy.pObject;
    if ( v95 )
    {
      v86 = v95->RefCount-- == 1;
      if ( v86 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    v4->ActiveEntity.pProxy.pObject = v94;
  }
  else
  {
    v96 = v4->ActiveEntity.pProxy.pObject;
    if ( v96 )
    {
      v86 = v96->RefCount-- == 1;
      if ( v86 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    v4->ActiveEntity.pProxy.pObject = 0i64;
  }
  *((_BYTE *)v4 + 76) &= 0xF7u;
  v4->WheelDelta = 0;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v8->vfptr);
  if ( v105.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v105.pObject->vfptr);
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
}f ( v86 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    v4->ActiveEntity.pProxy.pObject = v94;
  }
  else
  {
    v96 = v4->ActiveEntity.pProxy.pObject;
    if ( v96 )
    {
      v86 = v96->RefCount-- == 1;
      if ( v86 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    v4->ActiveEntity.pProxy.pObject = 0i64;
  }
  *((_BYTE *)v4 + 76) &= 0xF7u;
  v4->WheelDelta = 0;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release((S

// File Line: 1122
// RVA: 0x7BCA20
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *__fastcall Scaleform::GFx::AS3::MovieRoot::CreateEventObject(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *result, Scaleform::GFx::ASString *type, bool bubbles, bool cancelable)
{
  bool v5; // di
  Scaleform::GFx::ASString *v6; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *v7; // rbp
  Scaleform::GFx::AS3::MovieRoot *v8; // rbx

  v5 = bubbles;
  v6 = type;
  v7 = result;
  v8 = this;
  ((void (*)(void))this->vfptr[4].__vecDelDtor)();
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
    (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *)v8->pAVM.pObject->EventDispatcherClass.pObject,
    v7,
    v6,
    v5,
    cancelable);
  return v7;
}

// File Line: 1130
// RVA: 0x7C63C0
void __fastcall Scaleform::GFx::AS3::MovieRoot::DoActions(Scaleform::GFx::AS3::MovieRoot *this)
{
  unsigned int v1; // edx
  Scaleform::GFx::AS3::MovieRoot *v2; // rbx
  Scaleform::GFx::AS3::ASVM *v3; // rax
  Scaleform::GFx::AS3::ASVM *v4; // rax

  v1 = this->ASFramesToExecute;
  v2 = this;
  if ( v1 )
  {
    Scaleform::GFx::AS3::VM::ExecuteCode((Scaleform::GFx::AS3::VM *)&this->pAVM.pObject->vfptr, v1);
    v3 = v2->pAVM.pObject;
    if ( v3->HandleException )
      v3->HandleException = 0;
    v2->ASFramesToExecute = 0;
  }
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueues(v2);
  v4 = v2->pAVM.pObject;
  if ( v4->HandleException )
    v4->HandleException = 0;
}

// File Line: 1156
// RVA: 0x7CADA0
void __fastcall Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::MovieRoot::ActionLevel lvl)
{
  Scaleform::GFx::AS3::MovieRoot *v2; // rbx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *i; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator v4; // [rsp+28h] [rbp-40h]

  v2 = this;
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
    Scaleform::GFx::AS3::MovieRoot::ActionEntry::Execute(i, v2);
  }
  if ( v4.pLastEntry )
    Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(v4.pActionQueue, v4.pLastEntry);
}

// File Line: 1169
// RVA: 0x812880
void __fastcall Scaleform::GFx::AS3::MovieRoot::RequeueActionQueue(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::MovieRoot::ActionLevel srclvl, Scaleform::GFx::AS3::MovieRoot::ActionLevel dstlvl)
{
  __int64 v3; // rbx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *v4; // r12
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v5; // rdi
  Scaleform::GFx::AS3::MovieRoot::ActionQueueEntry *v6; // rsi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v7; // rbx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry **v8; // rax
  Scaleform::GFx::DisplayObject *v9; // rax
  Scaleform::RefCountNTSImpl *v10; // rcx
  signed __int64 v11; // r15
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v12; // r14
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::Resource *v15; // rcx
  Scaleform::Render::RenderBuffer *v16; // rcx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator v17; // [rsp+28h] [rbp-50h]

  v3 = dstlvl;
  if ( this->ActionQueue.Entries[srclvl].pActionRoot )
  {
    v4 = &this->ActionQueue;
    v17.pActionQueue = &this->ActionQueue;
    v17.Level = srclvl;
    v17.ModId = 0;
    v17.pLastEntry = 0i64;
    v17.pRootEntry = 0i64;
    v17.pCurEntry = this->ActionQueue.Entries[srclvl].pActionRoot;
    v5 = Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&v17);
    if ( v5 )
    {
      v6 = &v4->Entries[v3];
      do
      {
        v7 = Scaleform::GFx::AS3::MovieRoot::ActionQueueType::GetNewEntry(v4);
        v8 = &v6->pInsertEntry->pNextEntry;
        if ( v8 )
        {
          v7->pNextEntry = *v8;
          v6->pInsertEntry->pNextEntry = v7;
        }
        else
        {
          v7->pNextEntry = v6->pActionRoot;
          v6->pActionRoot = v7;
        }
        v6->pInsertEntry = v7;
        if ( !v7->pNextEntry )
          v6->pLastEntry = v7;
        ++v4->ModId;
        v7->Type = v5->Type;
        v9 = v5->pCharacter.pObject;
        if ( v9 )
          ++v9->RefCount;
        v10 = (Scaleform::RefCountNTSImpl *)&v7->pCharacter.pObject->vfptr;
        if ( v10 )
          Scaleform::RefCountNTSImpl::Release(v10);
        v7->pCharacter.pObject = v5->pCharacter.pObject;
        v11 = (signed __int64)&v5->pAS3Obj;
        v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v7->pAS3Obj;
        if ( &v5->pAS3Obj != &v7->pAS3Obj )
        {
          if ( *(_QWORD *)v11 )
            *(_DWORD *)(*(_QWORD *)v11 + 32i64) = (*(_DWORD *)(*(_QWORD *)v11 + 32i64) + 1) & 0x8FBFFFFF;
          v13 = *v12;
          if ( *v12 )
          {
            if ( (unsigned __int8)v13 & 1 )
            {
              *v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v13 - 1);
            }
            else
            {
              v14 = v13->RefCount;
              if ( v14 & 0x3FFFFF )
              {
                v13->RefCount = v14 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
              }
            }
          }
          *v12 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)v11;
        }
        v7->mEventId.Id = v5->mEventId.Id;
        v7->mEventId.WcharCode = v5->mEventId.WcharCode;
        v7->mEventId.KeyCode = v5->mEventId.KeyCode;
        v7->mEventId.AsciiCode = v5->mEventId.AsciiCode;
        v7->mEventId.RollOverCnt = v5->mEventId.RollOverCnt;
        v7->mEventId.ControllerIndex = v5->mEventId.ControllerIndex;
        v7->mEventId.KeysState.States = v5->mEventId.KeysState.States;
        v7->mEventId.MouseWheelDelta = v5->mEventId.MouseWheelDelta;
        v7->CFunction = v5->CFunction;
        v15 = (Scaleform::GFx::Resource *)v5->pNLoadInitCL.pObject;
        if ( v15 )
          Scaleform::Render::RenderBuffer::AddRef(v15);
        v16 = (Scaleform::Render::RenderBuffer *)v7->pNLoadInitCL.pObject;
        if ( v16 )
          Scaleform::RefCountImpl::Release(v16);
        v7->pNLoadInitCL.pObject = v5->pNLoadInitCL.pObject;
        v5 = Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&v17);
      }
      while ( v5 );
    }
    if ( v17.pLastEntry )
      Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(v17.pActionQueue, v17.pLastEntry);
  }
}

// File Line: 1182
// RVA: 0x811250
void __fastcall Scaleform::GFx::AS3::MovieRoot::RemoveActionQueueEntriesFor(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::MovieRoot::ActionLevel lvl, Scaleform::GFx::DisplayObject *dobj)
{
  Scaleform::GFx::DisplayObject *v3; // rdi
  Scaleform::RefCountImplCoreVtbl *i; // rbx
  Scaleform::RefCountNTSImpl *v5; // rcx

  v3 = dobj;
  for ( i = (&this->vfptr)[3 * ((signed int)lvl + 6i64)]; i; i = (Scaleform::RefCountImplCoreVtbl *)i->__vecDelDtor )
  {
    v5 = (Scaleform::RefCountNTSImpl *)i[2].__vecDelDtor;
    if ( v5 == (Scaleform::RefCountNTSImpl *)v3 )
    {
      if ( v5 )
        Scaleform::RefCountNTSImpl::Release(v5);
      i[2].__vecDelDtor = 0i64;
    }
  }
}

// File Line: 1245
// RVA: 0x7CAE30
void __fastcall Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueues(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::MovieRoot *v1; // rdi
  Scaleform::GFx::AS3::MovieRoot::ActionLevel v2; // ebx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *v3; // rsi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *i; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator v5; // [rsp+28h] [rbp-40h]

  v1 = this;
  v2 = 0;
  v3 = &this->ActionQueue;
  do
  {
    v5.pActionQueue = v3;
    v5.Level = v2;
    v5.ModId = 0;
    v5.pLastEntry = 0i64;
    v5.pRootEntry = 0i64;
    v5.pCurEntry = v3->Entries[v2].pActionRoot;
    for ( i = Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&v5);
          i;
          i = Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&v5) )
    {
      Scaleform::GFx::AS3::MovieRoot::ActionEntry::Execute(i, v1);
    }
    if ( v5.pLastEntry )
      Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(v5.pActionQueue, v5.pLastEntry);
    ++v2;
  }
  while ( (unsigned int)v2 < 6 );
}

// File Line: 1260
// RVA: 0x7B33E0
void __fastcall Scaleform::GFx::AS3::MovieRoot::ChangeMouseCursorType(Scaleform::GFx::AS3::MovieRoot *this, unsigned int mouseIdx, unsigned int newCursorType)
{
  unsigned int v3; // esi
  int v4; // ebp
  Scaleform::GFx::AS3::MovieRoot *v5; // rdi
  Scaleform::GFx::AS3::Stage *v6; // rax
  Scaleform::GFx::AS3::ASVM *v7; // rbx
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *v8; // rbx
  Scaleform::GFx::AS3::Stage *v9; // rcx
  signed __int64 v10; // rcx
  __int64 v11; // rax
  signed __int64 v12; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v13; // rcx
  Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent *v14; // rcx
  unsigned int v15; // eax
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent *v18; // rcx
  unsigned int v19; // eax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::MovieImpl *v21; // rdx
  Scaleform::GFx::UserEventHandler *v22; // rcx
  int v23; // [rsp+28h] [rbp-30h]
  char v24; // [rsp+2Ch] [rbp-2Ch]
  unsigned int v25; // [rsp+30h] [rbp-28h]
  int v26; // [rsp+34h] [rbp-24h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_gfx::MouseCursorEvent> v27; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+20h]

  v3 = newCursorType;
  v4 = mouseIdx;
  v5 = this;
  v6 = this->pStage.pObject;
  if ( v6 )
  {
    v7 = this->pAVM.pObject;
    if ( v7 )
    {
      if ( v7->ExtensionsEnabled && v6->MouseCursorEventCnt )
      {
        v8 = (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *)v7->EventDispatcherClass.pObject;
        result.pNode = this->BuiltinsMgr.Builtins[0].pNode;
        ++result.pNode->RefCount;
        Scaleform::GFx::AS3::MovieRoot::GetMouseCursorTypeString(this, &result, newCursorType);
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseCursorEventObject(v8, &v27, &result, v4);
        v9 = v5->pStage.pObject;
        if ( v9
          && (v10 = (signed __int64)v9 + 4 * (unsigned __int8)v9->AvmObjOffset,
              (v11 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v10 + 8i64))(v10)) != 0) )
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
        if ( (unsigned __int8)v13 & 1 )
          v13 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v13 - 1);
        if ( v13
          && !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
                v13,
                (Scaleform::GFx::AS3::Instances::fl_events::Event *)&v27.pObject->vfptr,
                (Scaleform::GFx::DisplayObject *)&v5->pStage.pObject->vfptr) )
        {
          v14 = v27.pObject;
          if ( v27.pObject )
          {
            if ( (_QWORD)v27.pObject & 1 )
            {
              --v27.pObject;
            }
            else
            {
              v15 = v27.pObject->RefCount;
              if ( v15 & 0x3FFFFF )
              {
                v27.pObject->RefCount = v15 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v14->vfptr);
              }
            }
          }
          v16 = result.pNode;
          v17 = result.pNode->RefCount == 1;
          --v16->RefCount;
          if ( v17 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v16);
          return;
        }
        v18 = v27.pObject;
        if ( v27.pObject )
        {
          if ( (_QWORD)v27.pObject & 1 )
          {
            --v27.pObject;
          }
          else
          {
            v19 = v27.pObject->RefCount;
            if ( v19 & 0x3FFFFF )
            {
              v27.pObject->RefCount = v19 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v18->vfptr);
            }
          }
        }
        v20 = result.pNode;
        v17 = result.pNode->RefCount == 1;
        --v20->RefCount;
        if ( v17 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v20);
      }
    }
  }
  v21 = v5->pMovieImpl;
  v22 = v21->pUserEventHandler.pObject;
  if ( v22 )
  {
    v24 = 0;
    v23 = 23;
    v25 = v3;
    v26 = v4;
    ((void (__fastcall *)(Scaleform::GFx::UserEventHandler *, Scaleform::GFx::MovieImpl *, int *))v22->vfptr[1].__vecDelDtor)(
      v22,
      v21,
      &v23);
  }
}

// File Line: 1296
// RVA: 0x802830
bool __fastcall Scaleform::GFx::AS3::MovieRoot::NotifyOnFocusChange(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::InteractiveObject *curFocused, Scaleform::GFx::InteractiveObject *toBeFocused, unsigned int controllerIdx, Scaleform::GFx::FocusMovedType fmt, Scaleform::GFx::ProcessFocusKeyInfo *pfocusKeyInfo)
{
  unsigned int v6; // ebx
  Scaleform::GFx::InteractiveObject *v7; // rdi
  char *v8; // rcx
  Scaleform::GFx::AS3::Stage *v9; // rcx
  __int64 v10; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v11; // rcx

  v6 = controllerIdx;
  v7 = toBeFocused;
  if ( curFocused )
  {
    v8 = (char *)curFocused + 4 * (unsigned __int8)curFocused->AvmObjOffset;
  }
  else
  {
    v9 = this->pStage.pObject;
    if ( !v9 )
    {
LABEL_7:
      v11 = 0i64;
      return Scaleform::GFx::AS3::AvmInteractiveObj::OnFocusChange(v11, v7, v6, fmt, pfocusKeyInfo);
    }
    v8 = (char *)v9 + 4 * (unsigned __int8)v9->AvmObjOffset;
  }
  v10 = (*(__int64 (**)(void))(*(_QWORD *)v8 + 8i64))();
  if ( !v10 )
    goto LABEL_7;
  v11 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v10 - 56);
  return Scaleform::GFx::AS3::AvmInteractiveObj::OnFocusChange(v11, v7, v6, fmt, pfocusKeyInfo);
}

// File Line: 1310
// RVA: 0x8028C0
void __fastcall Scaleform::GFx::AS3::MovieRoot::NotifyQueueSetFocus(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::InteractiveObject *ch, unsigned int controllerIdx, Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::MovieImpl::TransferFocus(this->pMovieImpl, ch, controllerIdx, fmt);
}

// File Line: 1352
// RVA: 0x7BE8E0
Scaleform::GFx::AS3::AvmStage *__fastcall Scaleform::GFx::AS3::MovieRoot::CreateStage(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::MovieDefImpl *pdefImpl)
{
  Scaleform::GFx::MovieDefImpl *v2; // rsi
  Scaleform::GFx::AS3::MovieRoot *v3; // rdi
  char *v4; // rbx
  Scaleform::GFx::AS3::Stage *v5; // rax
  Scaleform::GFx::AS3::Stage *v6; // rsi
  Scaleform::RefCountNTSImpl *v7; // rcx
  Scaleform::GFx::AS3::AvmStage *v8; // rax
  Scaleform::GFx::AS3::AvmStage *v9; // rbp
  Scaleform::GFx::AS3::ASVM *v10; // rax
  Scaleform::GFx::AS3::VMAppDomain *v11; // rax
  Scaleform::GFx::AS3::Stage *v12; // rsi
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *v13; // rdi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v14; // rbx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v15; // rax
  Scaleform::RefCountNTSImpl *v16; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v17; // rcx
  unsigned int v18; // eax
  Scaleform::GFx::AS3::WeakProxy *v19; // rdx
  bool v20; // zf
  Scaleform::Render::RenderBuffer *v21; // rcx
  Scaleform::GFx::AS3::AvmStage *result; // rax
  Scaleform::GFx::ResourceId v23; // [rsp+70h] [rbp+8h]
  char *v24; // [rsp+80h] [rbp+18h]
  char *v25; // [rsp+88h] [rbp+20h]

  v2 = pdefImpl;
  v3 = this;
  v4 = (char *)this->pMovieImpl->pHeap->vfptr->Alloc(this->pMovieImpl->pHeap, 384ui64, 0i64);
  v24 = v4;
  v25 = v4;
  if ( v4 )
  {
    v23.Id = 0x40000;
    Scaleform::GFx::AS3::Stage::Stage(
      (Scaleform::GFx::AS3::Stage *)v4,
      v2,
      (Scaleform::GFx::ASMovieRootBase *)&v3->vfptr,
      0i64,
      (Scaleform::GFx::ResourceId)&v23);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = (Scaleform::RefCountNTSImpl *)&v3->pStage.pObject->vfptr;
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
  v3->pStage.pObject = v6;
  *(_QWORD *)&v23.Id = v4 + 304;
  if ( v4 == (char *)-304i64 )
  {
    v9 = 0i64;
  }
  else
  {
    Scaleform::GFx::AS3::AvmStage::AvmStage(
      (Scaleform::GFx::AS3::AvmStage *)(v4 + 304),
      (Scaleform::GFx::DisplayObjContainer *)&v3->pStage.pObject->vfptr);
    v9 = v8;
  }
  v10 = v3->pAVM.pObject;
  if ( v10->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    v11 = v10->CallStack.Pages[(v10->CallStack.Size - 1) >> 6][(LODWORD(v10->CallStack.Size) - 1) & 0x3F].pFile->AppDomain.pObject;
  else
    v11 = v10->CurrentDomain.pObject;
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
    v9->AppDomain = v11;
  v12 = v3->pStage.pObject;
  v13 = &v3->ActionQueue;
  v14 = Scaleform::GFx::AS3::MovieRoot::ActionQueueType::GetNewEntry(v13);
  v15 = v13->Entries[0].pInsertEntry;
  if ( v15 )
  {
    v14->pNextEntry = v15->pNextEntry;
    v13->Entries[0].pInsertEntry->pNextEntry = v14;
  }
  else
  {
    v14->pNextEntry = v13->Entries[0].pActionRoot;
    v13->Entries[0].pActionRoot = v14;
  }
  v13->Entries[0].pInsertEntry = v14;
  if ( !v14->pNextEntry )
    v13->Entries[0].pLastEntry = v14;
  ++v13->ModId;
  v14->Type = 1;
  if ( v12 )
    ++v12->RefCount;
  v16 = (Scaleform::RefCountNTSImpl *)&v14->pCharacter.pObject->vfptr;
  if ( v16 )
    Scaleform::RefCountNTSImpl::Release(v16);
  v14->pCharacter.pObject = (Scaleform::GFx::DisplayObject *)&v12->vfptr;
  *(_QWORD *)&v14->mEventId.Id = 1i64;
  v14->mEventId.KeyCode = 0;
  v14->mEventId.AsciiCode = 0;
  *(_DWORD *)&v14->mEventId.RollOverCnt = 65280;
  v14->CFunction = 0i64;
  v17 = v14->pAS3Obj.pObject;
  if ( v17 )
  {
    if ( (unsigned __int8)v17 & 1 )
    {
      v14->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v17 - 1);
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
    v14->pAS3Obj.pObject = 0i64;
  }
  if ( (v14->Function.Flags & 0x1F) > 9 )
  {
    if ( (v14->Function.Flags >> 9) & 1 )
    {
      v19 = v14->Function.Bonus.pWeakProxy;
      v20 = v19->RefCount-- == 1;
      if ( v20 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v14->Function.Bonus.pWeakProxy = 0i64;
      v14->Function.value.VNumber = 0.0;
      v14->Function.value.VS._2.VObj = 0i64;
      v14->Function.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v14->Function);
    }
  }
  v14->Function.Flags &= 0xFFFFFFE0;
  v21 = (Scaleform::Render::RenderBuffer *)v14->pNLoadInitCL.pObject;
  if ( v21 )
    Scaleform::RefCountImpl::Release(v21);
  result = v9;
  v14->pNLoadInitCL.pObject = 0i64;
  return result;
}

// File Line: 1365
// RVA: 0x7B0220
void __fastcall Scaleform::GFx::AS3::MovieRoot::AdvanceFrame(Scaleform::GFx::AS3::MovieRoot *this, bool nextFrame)
{
  bool v2; // bp
  Scaleform::GFx::AS3::MovieRoot *v3; // rsi
  _QWORD *v4; // r14
  __int64 v5; // rax
  Scaleform::GFx::DisplayObject *v6; // rdi
  signed __int64 v7; // rcx
  __int64 v8; // rax
  signed __int64 v9; // rcx
  __int64 v10; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v11; // rcx
  unsigned int v12; // edi
  bool v13; // di
  int v14; // eax
  Scaleform::GFx::AS3::ASRefCountCollector *v15; // rcx
  Scaleform::AmpStats *v16; // rdx
  unsigned int v17; // er8

  v2 = nextFrame;
  v3 = this;
  if ( this->MainLoaderInfoEventsState & 2 )
    goto LABEL_25;
  v4 = (_QWORD *)((__int64 (__cdecl *)(Scaleform::GFx::InteractiveObject *))this->pMovieImpl->pMainMovie->vfptr[66].__vecDelDtor)(this->pMovieImpl->pMainMovie);
  v5 = (__int64)v3->vfptr[16].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 0);
  v6 = (Scaleform::GFx::DisplayObject *)v5;
  if ( v5
    && (v7 = v5 + 4i64 * *(unsigned __int8 *)(v5 + 109),
        (v8 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v7 + 40i64))(v7)) != 0) )
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
  if ( v10 & 1 )
    --v10;
  if ( v10 )
    *(_DWORD *)(v10 + 32) = (*(_DWORD *)(v10 + 32) + 1) & 0x8FBFFFFF;
  if ( v10 )
  {
    v11 = *(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo **)(v10 + 80);
    if ( v11 )
    {
      if ( !(v3->MainLoaderInfoEventsState & 1) )
      {
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteInitEvent(v11, v6);
        v3->MainLoaderInfoEventsState |= 1u;
      }
      v12 = (*(__int64 (__fastcall **)(_QWORD *))(*v4 + 64i64))(v4);
      v13 = (*(unsigned int (__fastcall **)(_QWORD *))(*v4 + 40i64))(v4) >= v12;
      if ( !v2 && !v13 )
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
  v3->MainLoaderInfoEventsState |= 2u;
LABEL_21:
  if ( v10 )
  {
    if ( !(v10 & 1) )
    {
      v14 = *(_DWORD *)(v10 + 32);
      if ( v14 & 0x3FFFFF )
      {
        *(_DWORD *)(v10 + 32) = v14 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v10);
      }
    }
  }
LABEL_25:
  if ( v3->StageInvalidated )
  {
    Scaleform::GFx::AS3::EventChains::QueueEvents(&v3->mEventChains, Event_Render);
    ((void (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *))v3->vfptr[7].__vecDelDtor)(v3);
    v3->StageInvalidated = 0;
  }
  if ( v2 )
  {
    v15 = v3->MemContext.pObject->ASGC.pObject;
    if ( v15 )
    {
      v16 = v3->pMovieImpl->AdvanceStats.pObject;
      v17 = v15->CollectionScheduledFlags;
      if ( v17 )
      {
        v15->CollectionScheduledFlags = 0;
        Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(v15, v16, v17);
      }
      Scaleform::GFx::AS3::ASRefCountCollector::AdvanceFrame(
        v3->MemContext.pObject->ASGC.pObject,
        &v3->NumAdvancesSinceCollection,
        &v3->LastCollectionFrame,
        v3->pMovieImpl->AdvanceStats.pObject);
    }
  }
}

// File Line: 1428
// RVA: 0x7B4B90
void __fastcall Scaleform::GFx::AS3::MovieRoot::ClearDisplayList(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::MovieRoot *v1; // rdi
  Scaleform::GFx::InteractiveObject *v2; // rbx

  v1 = this;
  v2 = this->pMovieImpl->pMainMovie;
  Scaleform::GFx::DisplayList::Clear(
    (Scaleform::GFx::DisplayList *)&v2[1],
    (Scaleform::GFx::DisplayObjectBase *)&v2->vfptr);
  _((AMD_HD3D *)v2);
  ((void (*)(void))v1->pMovieImpl->pMainMovie->vfptr[75].__vecDelDtor)();
  ((void (*)(void))v1->pMovieImpl->pMainMovie->vfptr[60].__vecDelDtor)();
  Scaleform::ArrayData<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v1->pMovieImpl->MovieLevels.Data,
    0i64);
}

// File Line: 1451
// RVA: 0x7BDFF0
Scaleform::GFx::AS3::MovieDefRootNode *__fastcall Scaleform::GFx::AS3::MovieRoot::CreateMovieDefRootNode(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::MemoryHeap *pheap, Scaleform::GFx::MovieDefImpl *pdefImpl, bool importFlag)
{
  bool v4; // bl
  Scaleform::GFx::MovieDefImpl *v5; // rdi
  __int64 v6; // rcx
  _QWORD *v7; // ST30_8

  v4 = importFlag;
  v5 = pdefImpl;
  v6 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))pheap->vfptr->Alloc)(pheap, 88i64);
  if ( !v6 )
    return 0i64;
  *(_QWORD *)v6 = &Scaleform::GFx::MovieDefRootNode::`vftable;
  *(_DWORD *)(v6 + 24) = 1;
  *(_QWORD *)(v6 + 32) = v5;
  *(_BYTE *)(v6 + 48) = v4;
  *(_QWORD *)(v6 + 56) = 0i64;
  *(_QWORD *)v6 = &Scaleform::GFx::AS3::MovieDefRootNode::`vftable;
  v7 = (_QWORD *)(v6 + 64);
  *v7 = 0i64;
  v7[1] = 0i64;
  v7[2] = 0i64;
  return (Scaleform::GFx::AS3::MovieDefRootNode *)v6;
}

// File Line: 1457
// RVA: 0x7D74F0
void __fastcall Scaleform::GFx::AS3::MovieRoot::ForceCollect(Scaleform::GFx::AS3::MovieRoot *this, unsigned int gcFlags)
{
  unsigned int v2; // edx
  unsigned int v3; // er8
  Scaleform::GFx::MovieImpl *v4; // rdx

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
  v4 = this->pMovieImpl;
  if ( !v4->pRenderRoot.pObject || (v4->Flags2 >> 2) & 1 )
    v3 |= 1u;
  Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(
    this->MemContext.pObject->ASGC.pObject,
    v4->AdvanceStats.pObject,
    v3);
}

// File Line: 1474
// RVA: 0x7D7550
void __fastcall Scaleform::GFx::AS3::MovieRoot::ForceEmergencyCollect(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::MemoryContextImpl *v1; // rax
  Scaleform::GFx::AS3::ASRefCountCollector *v2; // rbx

  v1 = this->MemContext.pObject;
  v2 = v1->ASGC.pObject;
  if ( v2->SuspendCnt )
  {
    v2->CollectionScheduledFlags = 10;
  }
  else
  {
    Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(v1->ASGC.pObject, this->pMovieImpl->AdvanceStats.pObject, 2u);
    *(_QWORD *)&v2->MaxRootCount = v2->PresetMaxRootCount;
  }
}

// File Line: 1479
// RVA: 0x8250F0
void __fastcall Scaleform::GFx::AS3::MovieRoot::SuspendGC(Scaleform::GFx::AS3::MovieRoot *this, bool suspend)
{
  Scaleform::GFx::AS3::ASRefCountCollector *v2; // rcx

  v2 = this->MemContext.pObject->ASGC.pObject;
  if ( suspend )
    ++v2->SuspendCnt;
  else
    --v2->SuspendCnt;
}

// File Line: 1484
// RVA: 0x8174E0
void __fastcall Scaleform::GFx::AS3::MovieRoot::ScheduleGC(Scaleform::GFx::AS3::MovieRoot *this, unsigned int gcFlags)
{
  unsigned int v2; // edx
  signed int v3; // edx

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
  this->MemContext.pObject->ASGC.pObject->CollectionScheduledFlags = v3 & 0xFFFFFFFB | 8;
}

// File Line: 1497
// RVA: 0x804AA0
void __fastcall Scaleform::GFx::AS3::MovieRoot::OnKeyDown(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::InteractiveObject *pmovie, Scaleform::GFx::EventId *evt, int keyMask)
{
  int v4; // ebx
  Scaleform::GFx::EventId *v5; // rsi
  Scaleform::GFx::AS3::MovieRoot *v6; // rdi
  Scaleform::GFx::InteractiveObject *v7; // r8
  char *v8; // rcx
  __int64 v9; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v10; // rcx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v11; // rcx
  signed __int64 v12; // rcx
  __int64 v13; // rax
  signed __int64 v14; // rax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> result; // [rsp+40h] [rbp+8h]

  v4 = keyMask;
  v5 = evt;
  v6 = this;
  Scaleform::GFx::MovieImpl::GetFocusedCharacter(
    *(Scaleform::GFx::MovieImpl **)&this[-1].AccelerometerArray.Owner,
    &result,
    evt->ControllerIndex);
  if ( !_bittest(
          &v4,
          *(unsigned __int8 *)((unsigned int)v5->ControllerIndex + *(_QWORD *)&v6[-1].AccelerometerArray.Owner + 21156i64)) )
  {
    v7 = result.pObject;
    if ( result.pObject )
    {
      v8 = (char *)result.pObject + 4 * (unsigned __int8)result.pObject->AvmObjOffset;
      v9 = (*(__int64 (__cdecl **)(char *))(*(_QWORD *)v8 + 8i64))(v8);
      if ( v9 )
        v9 -= 56i64;
      v10 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v9 + 16);
      if ( !v10 )
        v10 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v9 + 8);
      if ( (unsigned __int8)v10 & 1 )
        v10 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v10 - 1);
      v7 = result.pObject;
    }
    else
    {
      v11 = v6->ActionQueue.Entries[6].pInsertEntry;
      if ( v11
        && (v12 = (signed __int64)v11 + 4 * BYTE5(v11[1].pNextEntry),
            v13 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v12 + 40i64))(v12),
            v7 = result.pObject,
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
      if ( (unsigned __int8)v10 & 1 )
        v10 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v10 - 1);
    }
    if ( v10 )
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
        v10,
        v5,
        (Scaleform::GFx::DisplayObject *)&v7->vfptr);
  }
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
}

// File Line: 1556
// RVA: 0x805220
void __fastcall Scaleform::GFx::AS3::MovieRoot::OnMovieFocus(Scaleform::GFx::AS3::MovieRoot *this, bool set)
{
  Scaleform::GFx::AS3::EventChains *v2; // rcx
  bool v3; // zf
  Scaleform::GFx::EventId::IdCode v4; // edx

  v2 = &this->mEventChains;
  v3 = set == 0;
  v4 = 16777233;
  if ( v3 )
    v4 = 16777234;
  Scaleform::GFx::AS3::EventChains::Dispatch(v2, v4);
}

// File Line: 1566
// RVA: 0x805240
void __fastcall Scaleform::GFx::AS3::MovieRoot::OnNextFrame(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::EventChains::QueueEvents(&this->mEventChains, Event_EnterFrame);
}

// File Line: 1575
// RVA: 0x819960
void __fastcall Scaleform::GFx::AS3::MovieRoot::SetExternalInterfaceRetVal(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::Value *retVal)
{
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(this, retVal, &this->ExternalIntfRetVal);
}

// File Line: 1582
// RVA: 0x7D1310
char __fastcall Scaleform::GFx::AS3::MovieRoot::ExtractPathAndName(Scaleform::GFx::AS3::MovieRoot *this, const char *fullPath, Scaleform::GFx::ASString *ppath, Scaleform::GFx::ASString *pname)
{
  Scaleform::GFx::ASString *v4; // r14
  Scaleform::GFx::ASString *v5; // rsi
  const char *v6; // rbx
  Scaleform::GFx::AS3::MovieRoot *v7; // r15
  signed __int64 v8; // rax
  const char *v9; // rcx
  unsigned __int64 v10; // rbp
  Scaleform::GFx::ASStringNode *v11; // rdi
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rbx
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h]

  v4 = pname;
  v5 = ppath;
  v6 = fullPath;
  v7 = this;
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
  v10 = (signed int)v9 - (signed int)fullPath;
  v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->BuiltinsMgr.Builtins,
          &result,
          &fullPath[v10 + 1])->pNode;
  ++v11->RefCount;
  v12 = v4->pNode;
  v13 = v4->pNode->RefCount == 1;
  --v12->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v4->pNode = v11;
  v14 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v15 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->BuiltinsMgr.Builtins,
          &result,
          v6,
          v10)->pNode;
  ++v15->RefCount;
  v16 = v5->pNode;
  v13 = v5->pNode->RefCount == 1;
  --v16->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  v5->pNode = v15;
  v17 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v17->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  return 1;
}

// File Line: 1614
// RVA: 0x815E10
void __fastcall Scaleform::GFx::AS3::MovieRoot::ResolveStickyVariables(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::InteractiveObject *pch)
{
  Scaleform::GFx::InteractiveObject *v2; // rbx
  Scaleform::GFx::AS3::MovieRoot *v3; // rdi
  Scaleform::GFx::CharacterHandle *v4; // rax
  Scaleform::GFx::ASString *v5; // rsi
  __int64 v6; // rax
  __int64 v7; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v8; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v9; // rdi
  signed __int64 v10; // rax
  signed __int64 v11; // rcx
  Scaleform::GFx::MovieImpl::StickyVarNode *v12; // r13
  __int64 v13; // r12
  unsigned int v14; // esi
  Scaleform::GFx::AS3::WeakProxy *v15; // r14
  long double v16; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v17; // r15
  Scaleform::GFx::AS3::Instances::fl::XMLList *v18; // rcx
  __int64 v19; // rax
  Scaleform::GFx::ASString *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  bool v22; // zf
  Scaleform::GFx::ASStringNode *v23; // rcx
  int v24; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v25; // rcx
  unsigned int v26; // eax
  __int64 v27; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v28; // rcx
  unsigned int v29; // eax
  Scaleform::GFx::AS3::Value other; // [rsp+20h] [rbp-69h]
  int v31; // [rsp+40h] [rbp-49h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v32; // [rsp+48h] [rbp-41h]
  Scaleform::GFx::AS3::Value v33; // [rsp+50h] [rbp-39h]
  Scaleform::GFx::ASString *key; // [rsp+70h] [rbp-19h]
  Scaleform::GFx::ASString v35; // [rsp+78h] [rbp-11h]
  Scaleform::GFx::MovieImpl::StickyVarNode *v36; // [rsp+80h] [rbp-9h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v37; // [rsp+88h] [rbp-1h]
  __int64 v38; // [rsp+90h] [rbp+7h]
  Scaleform::GFx::AS3::MovieRoot *v39; // [rsp+F0h] [rbp+67h]
  Scaleform::GFx::MovieImpl::StickyVarNode *value; // [rsp+F8h] [rbp+6Fh]
  Scaleform::GFx::ASString result; // [rsp+100h] [rbp+77h]
  __int64 v42; // [rsp+108h] [rbp+7Fh]

  v39 = this;
  v38 = -2i64;
  v2 = pch;
  v3 = this;
  v4 = pch->pNameHandle.pObject;
  if ( !v4 )
    v4 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&pch->vfptr);
  v5 = &v4->NamePath;
  key = &v4->NamePath;
  v6 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v2->vfptr
                                                                   + 4 * (unsigned __int8)v2->AvmObjOffset))[1].__vecDelDtor)();
  if ( v6 )
    v6 -= 56i64;
  v7 = *(_QWORD *)(v6 + 16);
  if ( !v7 )
    v7 = *(_QWORD *)(v6 + 8);
  if ( v7 & 1 )
    --v7;
  if ( v7 )
  {
    v8 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v3->pMovieImpl->StickyVariables.mHash.pTable;
    v9.pTable = v8->pTable;
    if ( v8->pTable )
    {
      v10 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
              v8,
              v5,
              v5->pNode->HashFlags & v9.pTable->SizeMask);
      if ( v10 >= 0 )
      {
        v11 = (signed __int64)v9.pTable + 8 * (3 * v10 + 3);
        if ( v11 )
        {
          v36 = *(Scaleform::GFx::MovieImpl::StickyVarNode **)(v11 + 8);
          v12 = 0i64;
          v42 = 0i64;
          v13 = (__int64)v36;
          if ( v36 )
          {
            do
            {
              v14 = 10;
              other.Flags = 10;
              v15 = 0i64;
              other.Bonus.pWeakProxy = 0i64;
              v16 = *(double *)(v13 + 8);
              other.value.VNumber = v16;
              if ( *(_QWORD *)&v16 == *(_QWORD *)(*(_QWORD *)&v16 + 8i64) + 104i64 )
              {
                v16 = 0.0;
                other.value.VNumber = 0.0;
                v17 = v37;
                other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v37;
                v14 = 12;
                other.Flags = 12;
              }
              else
              {
                ++*(_DWORD *)(*(_QWORD *)&v16 + 24i64);
                v17 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&other.value.VS._2.VObj->vfptr;
              }
              v18 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v39->pAVM.pObject->PublicNamespace.pObject;
              v31 = 0;
              v32.pObject = v18;
              if ( v18 )
                v18->RefCount = (v18->RefCount + 1) & 0x8FBFFFFF;
              v33.Flags = 0;
              v33.Bonus.pWeakProxy = 0i64;
              if ( (v14 & 0x1F) - 12 <= 3
                && v16 != 0.0
                && (v19 = *(_QWORD *)(*(_QWORD *)&v16 + 40i64), *(_DWORD *)(v19 + 120) == 17)
                && ~(*(_BYTE *)(v19 + 112) >> 5) & 1 )
              {
                Scaleform::GFx::AS3::Value::Assign(&v33, (Scaleform::GFx::ASString *)(*(_QWORD *)&v16 + 56i64));
                Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                  &v32,
                  *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v16 + 64i64));
                v31 &= 0xFFFFFFF9;
              }
              else
              {
                Scaleform::GFx::AS3::Value::AssignUnsafe(&v33, &other);
                if ( (v33.Flags & 0x1F) == 10 )
                {
                  Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v33, &result);
                  if ( result.pNode->Size )
                  {
                    if ( *result.pNode->pData == 64 )
                    {
                      v31 |= 8u;
                      v20 = Scaleform::GFx::ASString::Substring(&result, &v35, 1, result.pNode->Size);
                      Scaleform::GFx::AS3::Value::Assign(&v33, v20);
                      v21 = v35.pNode;
                      v22 = v35.pNode->RefCount == 1;
                      --v21->RefCount;
                      if ( v22 )
                        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
                    }
                  }
                  v23 = result.pNode;
                  v22 = result.pNode->RefCount == 1;
                  --v23->RefCount;
                  if ( v22 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
                }
                v14 = other.Flags;
                v15 = other.Bonus.pWeakProxy;
                v17 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&other.value.VS._2.VObj->vfptr;
                v16 = other.value.VNumber;
              }
              if ( (signed int)(v14 & 0x1F) > 9 )
              {
                if ( (v14 >> 9) & 1 )
                {
                  v22 = v15->RefCount-- == 1;
                  if ( v22 )
                    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v15);
                  other.Bonus.pWeakProxy = 0i64;
                  other.value = 0ui64;
                  other.Flags = v14 & 0xFFFFFDE0;
                }
                else
                {
                  switch ( 0x40000000 )
                  {
                    case 0:
                      v22 = (*(_DWORD *)(*(_QWORD *)&v16 + 24i64))-- == 1;
                      if ( v22 )
                        Scaleform::GFx::ASStringNode::ReleaseNode(*(Scaleform::GFx::ASStringNode **)&v16);
                      break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                      if ( other.value.VS._1.VBool )
                      {
                        *(_QWORD *)&other.value.VNumber = *(_QWORD *)&v16 - 1i64;
                      }
                      else if ( v16 != 0.0 )
                      {
                        v24 = *(_DWORD *)(*(_QWORD *)&v16 + 32i64);
                        if ( v24 & 0x3FFFFF )
                        {
                          *(_DWORD *)(*(_QWORD *)&v16 + 32i64) = v24 - 1;
                          v25 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v16;
                          goto LABEL_50;
                        }
                      }
                      break;
                    case 6:
                    case 7:
                      if ( (_QWORD)other.value.VS._2.VObj & 1 )
                      {
                        other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)&v17[-1].RefCount + 7);
                      }
                      else if ( v17 )
                      {
                        v26 = v17->RefCount;
                        if ( v26 & 0x3FFFFF )
                        {
                          v17->RefCount = v26 - 1;
                          v25 = v17;
LABEL_50:
                          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v25);
                        }
                      }
                      break;
                    default:
                      break;
                  }
                }
              }
              (*(void (__fastcall **)(__int64, Scaleform::GFx::MovieImpl::StickyVarNode **, int *, __int64))(*(_QWORD *)v7 + 24i64))(
                v7,
                &value,
                &v31,
                v13 + 32);
              v27 = *(_QWORD *)(v13 + 16);
              if ( *(_BYTE *)(v13 + 24) )
              {
                if ( v12 )
                  *(_QWORD *)(v42 + 16) = v13;
                else
                  v12 = (Scaleform::GFx::MovieImpl::StickyVarNode *)v13;
                v42 = v13;
                *(_QWORD *)(v13 + 16) = 0i64;
              }
              else
              {
                (**(void (__fastcall ***)(__int64, signed __int64))v13)(v13, 1i64);
              }
              v13 = v27;
              if ( (v33.Flags & 0x1F) > 9 )
              {
                if ( (v33.Flags >> 9) & 1 )
                {
                  v22 = v33.Bonus.pWeakProxy->RefCount-- == 1;
                  if ( v22 )
                    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                  v33.Bonus.pWeakProxy = 0i64;
                  v33.value = 0ui64;
                  v33.Flags &= 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v33);
                }
              }
              v28 = v32.pObject;
              if ( v32.pObject )
              {
                if ( (_QWORD)v32.pObject & 1 )
                {
                  --v32.pObject;
                }
                else
                {
                  v29 = v32.pObject->RefCount;
                  if ( v29 & 0x3FFFFF )
                  {
                    v32.pObject->RefCount = v29 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v28->vfptr);
                  }
                }
              }
            }
            while ( v27 );
            if ( v12 )
            {
              if ( v12 != v36 )
              {
                value = v12;
                Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Set(
                  (Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::All)&v39->pMovieImpl->StickyVariables.mHash,
                  key,
                  &value);
              }
              return;
            }
            v5 = key;
          }
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString>(
            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v39->pMovieImpl->StickyVariables.mHash.pTable,
            v5);
          return;
        }
      }
    }
  }
}

// File Line: 1705
// RVA: 0x7E4A70
char __fastcall Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::Value *pval, const char *ppathToVar)
{
  const char *v3; // rbx
  Scaleform::GFx::AS3::Value *v4; // r12
  Scaleform::GFx::AS3::MovieRoot *v5; // rsi
  Scaleform::GFx::InteractiveObject *v7; // rcx
  __int64 v8; // rax
  _QWORD *v9; // r14
  long double v10; // rax
  unsigned int v11; // edi
  bool v12; // zf
  unsigned __int64 v13; // rdi
  unsigned __int64 v14; // rax
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *v15; // r15
  Scaleform::GFx::AS3::ASVM *v16; // r13
  int v17; // ecx
  bool v18; // si
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::VMAppDomain *v20; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **v21; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *ctr; // rcx
  unsigned int v23; // edx
  Scaleform::GFx::AS3::Value::Extra v24; // rax
  Scaleform::GFx::AS3::Value::VU v25; // kr00_16
  char v26; // bl
  unsigned int v27; // esi
  char v28; // r12
  char v29; // cl
  Scaleform::GFx::AS3::MovieRoot *v30; // r15
  Scaleform::GFx::ASString *v31; // rax
  Scaleform::GFx::DisplayObject *v32; // rsi
  Scaleform::GFx::ASStringNode *v33; // rcx
  __int64 v34; // rax
  signed __int64 v35; // rcx
  long double v36; // rax
  unsigned int v37; // esi
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v38; // rbx
  long double v39; // r12
  Scaleform::GFx::AS3::WeakProxy *v40; // r13
  unsigned int v41; // er15
  Scaleform::StringDataPtr *v42; // rax
  const char *v43; // r8
  unsigned __int64 v44; // r9
  unsigned __int64 v45; // rax
  const char *v46; // rdx
  unsigned __int64 v47; // rcx
  signed __int64 v48; // rax
  unsigned int v49; // edi
  Scaleform::GFx::AS3::WeakProxy *v50; // r14
  long double v51; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v52; // rsi
  Scaleform::GFx::AS3::GASRefCountBase *v53; // rcx
  __int64 v54; // rax
  Scaleform::GFx::ASString *v55; // rax
  Scaleform::GFx::ASStringNode *v56; // rcx
  Scaleform::GFx::ASStringNode *v57; // rcx
  int v58; // ecx
  int v59; // eax
  unsigned int v60; // eax
  __int64 v61; // rcx
  __int64 v62; // rdx
  __int64 v63; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v64; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v65; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v66; // rcx
  unsigned int v67; // eax
  unsigned int v68; // ebx
  Scaleform::GFx::AS3::Value::V2U v69; // rcx
  int v70; // eax
  int v71; // eax
  Scaleform::GFx::ASStringNode *v72; // rcx
  long double v73; // rcx
  int v74; // eax
  Scaleform::GFx::AS3::GASRefCountBase *v75; // rcx
  unsigned int v76; // eax
  Scaleform::GFx::ASStringNode *v77; // rcx
  Scaleform::Log *v78; // rbx
  const char *v79; // rdx
  Scaleform::GFx::ASStringNode *v80; // rcx
  Scaleform::GFx::AS3::VM *v81; // rcx
  Scaleform::GFx::ASStringNode *v82; // rcx
  Scaleform::GFx::AS3::Value other; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::AS3::Value v84; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::AS3::Value v85; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::ASString name; // [rsp+90h] [rbp-70h]
  Scaleform::GFx::AS3::Multiname v87; // [rsp+98h] [rbp-68h]
  Scaleform::GFx::ASString v88; // [rsp+C8h] [rbp-38h]
  Scaleform::StringDataPtr v89; // [rsp+D0h] [rbp-30h]
  Scaleform::StringDataPtr v; // [rsp+E0h] [rbp-20h]
  Scaleform::GFx::AS3::PropRef v91; // [rsp+F0h] [rbp-10h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> v92; // [rsp+120h] [rbp+20h]
  Scaleform::GFx::AS3::Value v93; // [rsp+128h] [rbp+28h]
  Scaleform::StringDataPtr qname; // [rsp+158h] [rbp+58h]
  Scaleform::GFx::ASString v95; // [rsp+168h] [rbp+68h]
  Scaleform::StringDataPtr v96; // [rsp+170h] [rbp+70h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+188h] [rbp+88h]
  __int64 v98; // [rsp+1B8h] [rbp+B8h]
  Scaleform::MsgFormat v99; // [rsp+1C0h] [rbp+C0h]
  Scaleform::GFx::AS3::MovieRoot *v100; // [rsp+610h] [rbp+510h]
  Scaleform::GFx::AS3::Value *v101; // [rsp+618h] [rbp+518h]
  const char *v102; // [rsp+620h] [rbp+520h]
  Scaleform::GFx::ASString result; // [rsp+628h] [rbp+528h]

  v102 = ppathToVar;
  v101 = pval;
  v100 = this;
  v98 = -2i64;
  v3 = ppathToVar;
  v4 = pval;
  v5 = this;
  if ( !ppathToVar )
    return 0;
  ((void (*)(void))this->vfptr[4].__vecDelDtor)();
  Scaleform::GFx::AS3::Value::SetUndefined(v4);
  v85.Flags = 0;
  v85.Bonus.pWeakProxy = 0i64;
  v7 = v5->pMovieImpl->pMainMovie;
  if ( !v7
    || (v8 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v7->vfptr
                                                                         + 4 * (unsigned __int8)v7->AvmObjOffset))[5].__vecDelDtor)(),
        v9 = (_QWORD *)(v8 - 72),
        !v8) )
  {
    v9 = 0i64;
  }
  v10 = *((double *)v9 + 2);
  if ( v10 == 0.0 )
    v10 = *((double *)v9 + 1);
  if ( LOBYTE(v10) & 1 )
    --*(_QWORD *)&v10;
  other.Flags = 12;
  other.Bonus.pWeakProxy = 0i64;
  other.value.VNumber = v10;
  if ( v10 != 0.0 )
    *(_DWORD *)(*(_QWORD *)&v10 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v10 + 32i64) + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::Value::Assign(&v85, &other);
  v11 = other.Flags;
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags >> 9) & 1 )
    {
      v12 = other.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      other.Bonus.pWeakProxy = 0i64;
      other.value = 0ui64;
      other.Flags = v11 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  qname.pStr = v3;
  v13 = -1i64;
  v14 = -1i64;
  do
    ++v14;
  while ( v3[v14] );
  qname.Size = v14;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, (Scaleform::GFx::AS3::VM *)&v5->pAVM.pObject->vfptr, &qname);
  v91.pSI = 0i64;
  v91.SlotIndex = 0i64;
  v91.This.Flags = 0;
  v91.This.Bonus.pWeakProxy = 0i64;
  v15 = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *)v9[5];
  v16 = v5->pAVM.pObject;
  v17 = mn.Name.Flags & 0x1F;
  if ( !(mn.Name.Flags & 0x1F) )
    goto LABEL_250;
  if ( (unsigned int)(v17 - 12) > 3 && v17 != 10 )
    goto LABEL_251;
  if ( !*(_QWORD *)&mn.Name.value.VNumber )
    goto LABEL_250;
  if ( v17 != 10 )
    goto LABEL_251;
  Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&mn.Name, &result);
  v18 = !result.pNode->Size || *result.pNode->pData == pattern[0] && !*((_BYTE *)result.pNode->pData + 1);
  v19 = result.pNode;
  v12 = result.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  v12 = v18 == 0;
  v5 = v100;
  if ( v12 )
  {
LABEL_251:
    v20 = (Scaleform::GFx::AS3::VMAppDomain *)v15[2].Entries.mHash.pHeap;
    if ( v20 && (v21 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v20, &mn)) != 0i64
      || (v21 = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(v15 + 3, &mn)) != 0i64 )
    {
      ctr = *v21;
    }
    else
    {
      ctr = 0i64;
    }
  }
  else
  {
LABEL_250:
    ctr = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v16->TraitsClassClass.pObject->vfptr;
  }
  Scaleform::GFx::AS3::FindGOProperty(
    &v91,
    (Scaleform::GFx::AS3::VM *)&v5->pAVM.pObject->vfptr,
    &v5->pAVM.pObject->GlobalObjects,
    &mn,
    ctr);
  if ( v91.This.Flags & 0x1F
    && (!((_QWORD)v91.pSI & 1) || (_QWORD)v91.pSI & 0xFFFFFFFFFFFFFFFEui64)
    && (!((LOBYTE(v91.pSI) >> 1) & 1) || (_QWORD)v91.pSI & 0xFFFFFFFFFFFFFFFDui64) )
  {
    other.Flags = 0;
    other.Bonus.pWeakProxy = 0i64;
    if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(
           &v91,
           (Scaleform::GFx::AS3::CheckResult *)&v102,
           (Scaleform::GFx::AS3::VM *)&v5->pAVM.pObject->vfptr,
           &other,
           0)->Result )
    {
      v23 = other.Flags;
      v24.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)other.Bonus;
      v25 = other.value;
      other.Flags = v4->Flags;
      other.Bonus.pWeakProxy = v4->Bonus.pWeakProxy;
      other.value = v4->value;
      v4->Flags = v23;
      v4->Bonus = v24;
      v4->value = v25;
      v26 = 1;
    }
    else
    {
      v26 = 0;
    }
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags >> 9) & 1 )
      {
        v12 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v12 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        other.Bonus.pWeakProxy = 0i64;
        other.value = 0ui64;
        other.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
    goto LABEL_234;
  }
  v27 = 0;
  v28 = 1;
  if ( *v3 == 95 )
  {
    if ( !strncmp(v3 + 1, "root", 4ui64) )
    {
      v27 = 5;
    }
    else if ( !strncmp(v3 + 1, "level0", 5ui64) )
    {
      v27 = 7;
    }
  }
  else if ( *v3 == 114 )
  {
    if ( !strncmp(v3 + 1, "oot", 3ui64) )
      v27 = 4;
  }
  else if ( *v3 == 115 && !strncmp(v3 + 1, "tage", 4ui64) )
  {
    v27 = 5;
    v28 = 0;
  }
  v29 = v3[v27];
  if ( v29 )
  {
    if ( v29 != 46 )
    {
      v30 = v100;
      goto LABEL_88;
    }
    ++v27;
  }
  v3 += v27;
  v30 = v100;
  if ( v28 )
  {
    v31 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v100->BuiltinsMgr.Builtins,
            &result,
            "root1");
    v32 = Scaleform::GFx::DisplayList::GetDisplayObjectByName((Scaleform::GFx::DisplayList *)(v9[3] + 216i64), v31, 1);
    v33 = result.pNode;
    v12 = result.pNode->RefCount == 1;
    --v33->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v33);
    if ( !v32 || !((v32->Flags >> 9) & 1) )
    {
      v26 = 0;
      goto LABEL_234;
    }
    v34 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v32->vfptr
                                                                      + 4 * (unsigned __int8)v32->AvmObjOffset))[5].__vecDelDtor)();
    v35 = v34 - 72;
    if ( !v34 )
      v35 = 0i64;
    v36 = *(double *)(v35 + 16);
    if ( v36 == 0.0 )
      v36 = *(double *)(v35 + 8);
    if ( LOBYTE(v36) & 1 )
      --*(_QWORD *)&v36;
    other.Flags = 12;
    other.Bonus.pWeakProxy = 0i64;
    other.value.VNumber = v36;
    if ( v36 != 0.0 )
      *(_DWORD *)(*(_QWORD *)&v36 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v36 + 32i64) + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::Value::Assign(&v85, &other);
    v37 = other.Flags;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags >> 9) & 1 )
      {
        v12 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v12 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        other.Bonus.pWeakProxy = 0i64;
        other.value = 0ui64;
        other.Flags = v37 & 0xFFFFFDE0;
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
      ++v13;
    while ( v3[v13] );
  }
  else
  {
    v13 = 0i64;
  }
  v89.Size = v13;
  v.pStr = 0i64;
  v.Size = 0i64;
  if ( v13 )
  {
    v38 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v30->BuiltinsMgr.Builtins;
    qname.pStr = (const char *)&v30->BuiltinsMgr;
    v39 = v85.value.VNumber;
    v40 = v85.Bonus.pWeakProxy;
    v41 = v85.Flags;
    while ( 1 )
    {
      v42 = Scaleform::StringDataPtr::GetNextToken(&v89, &v96, 46);
      v43 = v42->pStr;
      v.pStr = v42->pStr;
      v44 = v42->Size;
      v.Size = v44;
      v45 = v44;
      if ( v89.Size < v44 )
        v45 = v89.Size;
      v46 = &v89.pStr[v45];
      v89.pStr = v46;
      v47 = v89.Size - v45;
      v89.Size -= v45;
      if ( *v46 == 46 )
      {
        v48 = 1i64;
        if ( v47 < 1 )
          v48 = v47;
        v89.pStr = &v46[v48];
        v89.Size = v47 - v48;
      }
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
        v38,
        &name,
        v43,
        v44);
      v49 = 10;
      other.Flags = 10;
      v50 = 0i64;
      other.Bonus.pWeakProxy = 0i64;
      v51 = *(double *)&name.pNode;
      *(Scaleform::GFx::ASString *)&other.value.VNumber = name;
      if ( name.pNode == &name.pNode->pManager->NullStringNode )
      {
        v51 = 0.0;
        other.value.VNumber = 0.0;
        v52 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v96.Size;
        other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v96.Size;
        v49 = 12;
        other.Flags = 12;
      }
      else
      {
        ++name.pNode->RefCount;
        v52 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&other.value.VS._2.VObj->vfptr;
      }
      v53 = (Scaleform::GFx::AS3::GASRefCountBase *)&v100->pAVM.pObject->PublicNamespace.pObject->vfptr;
      v87.Kind = 0;
      v87.Obj.pObject = v53;
      if ( v53 )
        v53->RefCount = (v53->RefCount + 1) & 0x8FBFFFFF;
      v87.Name.Flags = 0;
      v87.Name.Bonus.pWeakProxy = 0i64;
      if ( (v49 & 0x1F) - 12 <= 3
        && v51 != 0.0
        && (v54 = *(_QWORD *)(*(_QWORD *)&v51 + 40i64), *(_DWORD *)(v54 + 120) == 17)
        && ~(*(_BYTE *)(v54 + 112) >> 5) & 1 )
      {
        Scaleform::GFx::AS3::Value::Assign(&v87.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v51 + 56i64));
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v87.Obj,
          *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v51 + 64i64));
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
              v55 = Scaleform::GFx::ASString::Substring(&v88, &v95, 1, v88.pNode->Size);
              Scaleform::GFx::AS3::Value::Assign(&v87.Name, v55);
              v56 = v95.pNode;
              v12 = v95.pNode->RefCount == 1;
              --v56->RefCount;
              if ( v12 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v56);
            }
          }
          v57 = v88.pNode;
          v12 = v88.pNode->RefCount == 1;
          --v57->RefCount;
          if ( v12 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v57);
        }
        v49 = other.Flags;
        v50 = other.Bonus.pWeakProxy;
        v52 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&other.value.VS._2.VObj->vfptr;
        v51 = other.value.VNumber;
      }
      v58 = v49 & 0x1F;
      if ( v58 > 9 )
      {
        if ( (v49 >> 9) & 1 )
        {
          v12 = v50->RefCount-- == 1;
          if ( v12 )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v50);
          other.Bonus.pWeakProxy = 0i64;
          other.value = 0ui64;
          other.Flags = v49 & 0xFFFFFDE0;
        }
        else
        {
          switch ( v58 )
          {
            case 10:
              v12 = (*(_DWORD *)(*(_QWORD *)&v51 + 24i64))-- == 1;
              if ( v12 )
                Scaleform::GFx::ASStringNode::ReleaseNode(*(Scaleform::GFx::ASStringNode **)&v51);
              break;
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
              if ( other.value.VS._1.VBool )
              {
                *(_QWORD *)&other.value.VNumber = *(_QWORD *)&v51 - 1i64;
              }
              else if ( v51 != 0.0 )
              {
                v59 = *(_DWORD *)(*(_QWORD *)&v51 + 32i64);
                if ( v59 & 0x3FFFFF )
                {
                  *(_DWORD *)(*(_QWORD *)&v51 + 32i64) = v59 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v51);
                }
              }
              break;
            case 16:
            case 17:
              if ( (_QWORD)other.value.VS._2.VObj & 1 )
              {
                other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)&v52[-1].RefCount + 7);
              }
              else if ( v52 )
              {
                v60 = v52->RefCount;
                if ( v60 & 0x3FFFFF )
                {
                  v52->RefCount = v60 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v52);
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
      if ( v39 == 0.0 )
        break;
      if ( !*(_BYTE *)(*(__int64 (__fastcall **)(long double, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v39 + 32i64))(
                        COERCE_LONG_DOUBLE(*(_QWORD *)&v39),
                        &result,
                        &v87,
                        &v84) )
      {
        v61 = *(_QWORD *)(*(_QWORD *)&v39 + 40i64);
        if ( (unsigned int)(*(_DWORD *)(v61 + 120) - 29) < 5 )
        {
          if ( ~(*(_BYTE *)(v61 + 112) >> 5) & 1 )
          {
            v62 = 0i64;
            if ( (*(_WORD *)(*(_QWORD *)(*(_QWORD *)&v39 + 88i64) + 106i64) >> 9) & 1 )
              v62 = *(_QWORD *)(*(_QWORD *)&v39 + 88i64);
            if ( !v62
              || (v63 = (*(__int64 (**)(void))(*(_QWORD *)(v62 + 4i64 * *(unsigned __int8 *)(v62 + 109)) + 40i64))(),
                  v64 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v63 - 72),
                  !v63) )
            {
              v64 = 0i64;
            }
            v65 = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(v64, &v92, &name)->pObject;
            v66 = v92.pObject;
            if ( v92.pObject )
            {
              if ( (_QWORD)v92.pObject & 1 )
              {
                --v92.pObject;
              }
              else
              {
                v67 = v92.pObject->RefCount;
                if ( v67 & 0x3FFFFF )
                {
                  v92.pObject->RefCount = v67 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v66->vfptr);
                }
              }
            }
            if ( !v65 )
              goto LABEL_222;
            v93.Flags = 12;
            v93.Bonus.pWeakProxy = 0i64;
            *(_QWORD *)&v93.value.VNumber = v65;
            v65->RefCount = (v65->RefCount + 1) & 0x8FBFFFFF;
            Scaleform::GFx::AS3::Value::Assign(&v84, &v93);
            v68 = v93.Flags;
            if ( (v93.Flags & 0x1F) > 9 )
            {
              if ( (v93.Flags >> 9) & 1 )
              {
                v12 = v93.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v12 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                v93.Bonus.pWeakProxy = 0i64;
                v93.value = 0ui64;
                v93.Flags = v68 & 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v93);
              }
            }
          }
        }
      }
      if ( (char)(v41 & 0x1F) > 9 )
      {
        if ( (v41 >> 9) & 1 )
        {
          v12 = v40->RefCount-- == 1;
          if ( v12 )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v40);
          v85.Bonus.pWeakProxy = 0i64;
          v85.value = 0ui64;
          v85.Flags = v41 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v85);
        }
      }
      __asm { prefetcht1 byte ptr [rsp+600h+var_5B0.Flags]; Prefetch to all cache levels }
      v85 = v84;
      v40 = v84.Bonus.pWeakProxy;
      v69.VObj = (Scaleform::GFx::AS3::Object *)v84.value.VS._2;
      v39 = v84.value.VNumber;
      v70 = v84.Flags & 0x1F;
      if ( v70 > 9 )
      {
        if ( (v84.Flags >> 9) & 1 )
        {
          ++v84.Bonus.pWeakProxy->RefCount;
        }
        else if ( v70 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v84.value.VNumber + 24i64);
        }
        else if ( v70 > 10 )
        {
          if ( v70 <= 15 )
          {
            if ( *(_QWORD *)&v84.value.VNumber )
            {
              ++*(_DWORD *)(*(_QWORD *)&v84.value.VNumber + 32i64);
              *(_DWORD *)(*(_QWORD *)&v39 + 32i64) &= 0x8FBFFFFF;
            }
          }
          else if ( v70 <= 17 && v84.value.VS._2.VObj )
          {
            ++v84.value.VS._2.VObj->RefCount;
            v69.VObj->RefCount &= 0x8FBFFFFF;
          }
        }
      }
      v41 = v85.Flags;
      if ( v89.Size && (v85.Flags & 0x1F) - 12 > 3 )
      {
        v78 = Scaleform::GFx::StateBag::GetLog(
                (Scaleform::GFx::StateBag *)&v100->pMovieImpl->vfptr,
                (Scaleform::Ptr<Scaleform::Log> *)&result)->pObject;
        if ( result.pNode )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pNode);
        if ( v78 )
        {
          Scaleform::StringBuffer::StringBuffer((Scaleform::StringBuffer *)&v93, Scaleform::Memory::pGlobalHeap);
          LODWORD(v96.pStr) = 1;
          v96.Size = (unsigned __int64)&v93;
          Scaleform::MsgFormat::MsgFormat(&v99, (Scaleform::MsgFormat::Sink *)&v96);
          Scaleform::MsgFormat::Parse(
            &v99,
            "Token {0} in path {1} was not resolved to a valid Object! This may be caused by a property that is not o"
            "f Object type, or by using reserved words/properties for MovieClip names in the display tree.");
          Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(&v99, &v);
          Scaleform::MsgFormat::FormatD1<char const *>(&v99, &v102);
          Scaleform::MsgFormat::FinishFormatD(&v99);
          Scaleform::MsgFormat::~MsgFormat(&v99);
          v79 = &customWorldMapCaption;
          if ( *(_QWORD *)&v93.Flags )
            v79 = *(const char **)&v93.Flags;
          Scaleform::Log::LogError(v78, v79);
          Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v93);
        }
        Scaleform::GFx::AS3::Value::SetNull(&v85);
        if ( (v84.Flags & 0x1F) > 9 )
        {
          if ( (v84.Flags >> 9) & 1 )
          {
            v12 = v84.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v12 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v84.Bonus.pWeakProxy = 0i64;
            v84.value = 0ui64;
            v84.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v84);
          }
        }
        Scaleform::GFx::AS3::Multiname::~Multiname(&v87);
        v80 = name.pNode;
        v12 = name.pNode->RefCount == 1;
        --v80->RefCount;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v80);
        goto LABEL_233;
      }
      v71 = v84.Flags & 0x1F;
      if ( v71 > 9 )
      {
        if ( (v84.Flags >> 9) & 1 )
        {
          v12 = v84.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v84.Bonus.pWeakProxy = 0i64;
          v84.value = 0ui64;
          v84.Flags &= 0xFFFFFDE0;
        }
        else
        {
          switch ( v71 )
          {
            case 10:
              v72 = v84.value.VS._1.VStr;
              v12 = *(_DWORD *)(*(_QWORD *)&v84.value.VNumber + 24i64) == 1;
              --v72->RefCount;
              if ( v12 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v72);
              break;
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
              v73 = v84.value.VNumber;
              if ( !v84.value.VS._1.VBool )
                goto LABEL_189;
              --*(_QWORD *)&v84.value.VNumber;
              break;
            case 16:
            case 17:
              v73 = *(double *)&v84.value.VS._2.VObj;
              if ( (_QWORD)v84.value.VS._2.VObj & 1 )
              {
                --v84.value.VS._2.VObj;
              }
              else
              {
LABEL_189:
                if ( v73 != 0.0 )
                {
                  v74 = *(_DWORD *)(*(_QWORD *)&v73 + 32i64);
                  if ( v74 & 0x3FFFFF )
                  {
                    *(_DWORD *)(*(_QWORD *)&v73 + 32i64) = v74 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v73);
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
        if ( (v87.Name.Flags >> 9) & 1 )
        {
          v12 = v87.Name.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v87.Name.Bonus.pWeakProxy = 0i64;
          v87.Name.value = 0ui64;
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
        if ( (_QWORD)v87.Obj.pObject & 1 )
        {
          --v87.Obj.pObject;
        }
        else
        {
          v76 = v87.Obj.pObject->RefCount;
          if ( v76 & 0x3FFFFF )
          {
            v87.Obj.pObject->RefCount = v76 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v75->vfptr);
          }
        }
      }
      v77 = name.pNode;
      v12 = name.pNode->RefCount == 1;
      --v77->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v77);
      if ( !v89.Size )
        goto LABEL_233;
      v38 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)qname.pStr;
    }
    Scaleform::GFx::AS3::Value::SetUndefined(v101);
LABEL_222:
    v81 = (Scaleform::GFx::AS3::VM *)&v100->pAVM.pObject->vfptr;
    if ( v81->HandleException )
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v81);
    if ( (v84.Flags & 0x1F) > 9 )
    {
      if ( (v84.Flags >> 9) & 1 )
      {
        v12 = v84.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v12 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v84.Bonus.pWeakProxy = 0i64;
        v84.value = 0ui64;
        v84.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v84);
      }
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&v87);
    v82 = name.pNode;
    v12 = name.pNode->RefCount == 1;
    --v82->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v82);
    v26 = 0;
    goto LABEL_235;
  }
LABEL_233:
  Scaleform::GFx::AS3::Value::Assign(v101, &v85);
  v26 = 1;
LABEL_234:
  v41 = v85.Flags;
  v40 = v85.Bonus.pWeakProxy;
LABEL_235:
  if ( (v91.This.Flags & 0x1F) > 9 )
  {
    if ( (v91.This.Flags >> 9) & 1 )
    {
      v12 = v91.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v91.This.Bonus.pWeakProxy = 0i64;
      v91.This.value = 0ui64;
      v91.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v91.This);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  if ( (char)(v41 & 0x1F) > 9 )
  {
    if ( (v41 >> 9) & 1 )
    {
      v12 = v40->RefCount-- == 1;
      if ( v12 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v40);
      v85.Bonus.pWeakProxy = 0i64;
      v85.value = 0ui64;
      v85.Flags = v41 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v85);
    }
  }
  return v26;
}This.Flags >> 9) & 1 

// File Line: 1844
// RVA: 0x7F11F0
char __fastcall Scaleform::GFx::AS3::MovieRoot::GetVariable(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::Value *pval, const char *ppathToVar)
{
  const char *v3; // rsi
  Scaleform::GFx::Value *v4; // rbx
  Scaleform::GFx::AS3::MovieRoot *v5; // rdi
  int v6; // ebx
  bool v7; // zf
  char result; // al
  unsigned int v9; // ebx
  Scaleform::GFx::AS3::Value pvala; // [rsp+28h] [rbp-30h]

  v3 = ppathToVar;
  v4 = pval;
  v5 = this;
  pvala.Flags = 0;
  pvala.Bonus.pWeakProxy = 0i64;
  if ( ((unsigned int)pval->Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval->pObjectInterface->vfptr->gap8[8])(
      pval->pObjectInterface,
      pval,
      *(_QWORD *)&pval->mValue.NValue);
    v4->pObjectInterface = 0i64;
  }
  v4->Type = 0;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(v5, &pvala, v3) )
  {
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v5, &pvala, v4);
    v6 = *(unsigned int *)((char *)&pvala.Flags + 2);
    if ( (BYTE2(pvala.Flags) & 0x1F) > 9 )
    {
      if ( (*(unsigned int *)((char *)&pvala.Flags + 2) >> 9) & 1 )
      {
        v7 = (**(_DWORD **)((char *)&pvala.Bonus.pWeakProxy + 2))-- == 1;
        if ( v7 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        *(_OWORD *)((char *)&pvala.Bonus.pWeakProxy + 2) = 0ui64;
        *(Scaleform::GFx::AS3::Traits **)((char *)&pvala.value.VS._2.pTraits + 2) = 0i64;
        *(unsigned int *)((char *)&pvala.Flags + 2) = v6 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)((char *)&pvala + 2));
      }
    }
    result = 1;
  }
  else
  {
    v9 = pvala.Flags;
    if ( (pvala.Flags & 0x1F) > 9 )
    {
      if ( (pvala.Flags >> 9) & 1 )
      {
        v7 = pvala.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v7 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        pvala.Bonus.pWeakProxy = 0i64;
        pvala.value = 0ui64;
        pvala.Flags = v9 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&pvala);
      }
    }
    result = 0;
  }
  return result;
}

// File Line: 1868
// RVA: 0x81F020
bool __fastcall Scaleform::GFx::AS3::MovieRoot::SetVariable(Scaleform::GFx::AS3::MovieRoot *this, const char *ppathToVar, Scaleform::GFx::Value *value, Scaleform::GFx::Movie::SetVarType setType)
{
  Scaleform::GFx::Movie::SetVarType v4; // er12
  Scaleform::GFx::Value *v5; // r13
  const char *v6; // rbx
  Scaleform::GFx::AS3::MovieRoot *v7; // r15
  Scaleform::GFx::ASStringNode *v8; // rbx
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASStringNode *v12; // rdi
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASStringNode *v14; // rcx
  unsigned int v15; // edi
  Scaleform::GFx::ASStringNode *v16; // rcx
  unsigned int v18; // edi
  Scaleform::GFx::AS3::WeakProxy *v19; // r14
  Scaleform::GFx::ASStringNode *v20; // rsi
  Scaleform::GFx::AS3::GASRefCountBase *v21; // rcx
  const char *v22; // rax
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // rcx
  __int64 v26; // rcx
  __int64 v27; // rsi
  __int64 v28; // r8
  int v29; // eax
  __int64 v30; // rax
  Scaleform::GFx::AS3::VM *v31; // rcx
  unsigned int v32; // edi
  Scaleform::GFx::ASStringNode *v33; // rcx
  _DWORD *v34; // [rsp+8h] [rbp-79h]
  __int64 v35; // [rsp+10h] [rbp-71h]
  __int64 v36; // [rsp+18h] [rbp-69h]
  Scaleform::GFx::ASString ppath; // [rsp+20h] [rbp-61h]
  Scaleform::GFx::AS3::Value pval; // [rsp+28h] [rbp-59h]
  Scaleform::GFx::AS3::Value other; // [rsp+48h] [rbp-39h]
  Scaleform::GFx::AS3::Multiname v40; // [rsp+68h] [rbp-19h]
  Scaleform::GFx::ASString v41; // [rsp+98h] [rbp+17h]
  Scaleform::GFx::AS3::Value::V2U v42; // [rsp+A0h] [rbp+1Fh]
  __int64 v43; // [rsp+A8h] [rbp+27h]
  Scaleform::GFx::ASString result; // [rsp+E8h] [rbp+67h]

  v43 = -2i64;
  v4 = setType;
  v5 = value;
  v6 = ppathToVar;
  v7 = this;
  ppath.pNode = this->BuiltinsMgr.Builtins[0].pNode;
  ++ppath.pNode->RefCount;
  ppath.pNode = this->BuiltinsMgr.Builtins[0].pNode;
  ++ppath.pNode->RefCount;
  if ( Scaleform::GFx::AS3::MovieRoot::ExtractPathAndName(this, ppathToVar, &ppath, &ppath) )
  {
    v8 = ppath.pNode;
  }
  else
  {
    v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->BuiltinsMgr.Builtins,
           &result,
           v6)->pNode;
    ++v8->RefCount;
    v9 = ppath.pNode;
    v10 = ppath.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    ppath.pNode = v8;
    v11 = result.pNode;
    v10 = result.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->BuiltinsMgr.Builtins,
            &result,
            "root")->pNode;
    ++v12->RefCount;
    v13 = ppath.pNode;
    v10 = ppath.pNode->RefCount == 1;
    --v13->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    ppath.pNode = v12;
    v14 = result.pNode;
    v10 = result.pNode->RefCount == 1;
    --v14->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
  pval.Flags = 0;
  pval.Bonus.pWeakProxy = 0i64;
  if ( !Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(v7, &pval, ppath.pNode->pData) )
  {
    v15 = pval.Flags;
    if ( (pval.Flags & 0x1F) > 9 )
    {
      if ( (pval.Flags >> 9) & 1 )
      {
        v10 = pval.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        pval.Bonus.pWeakProxy = 0i64;
        pval.value = 0ui64;
        pval.Flags = v15 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
      }
    }
    v10 = v8->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    v16 = ppath.pNode;
    v10 = ppath.pNode->RefCount == 1;
    --v16->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    return 0;
  }
  v18 = 10;
  other.Flags = 10;
  v19 = 0i64;
  other.Bonus.pWeakProxy = 0i64;
  v20 = v8;
  *(_QWORD *)&other.value.VNumber = v8;
  if ( v8 == &v8->pManager->NullStringNode )
  {
    v20 = 0i64;
    other.value.VNumber = 0.0;
    other.value.VS._2 = v42;
    v18 = 12;
    other.Flags = 12;
  }
  else
  {
    ++v8->RefCount;
  }
  v21 = (Scaleform::GFx::AS3::GASRefCountBase *)&v7->pAVM.pObject->PublicNamespace.pObject->vfptr;
  v40.Kind = 0;
  v40.Obj.pObject = v21;
  if ( v21 )
    v21->RefCount = (v21->RefCount + 1) & 0x8FBFFFFF;
  v40.Name.Flags = 0;
  v40.Name.Bonus.pWeakProxy = 0i64;
  if ( (v18 & 0x1F) - 12 <= 3
    && v20
    && (v22 = v20[1].pData, *((_DWORD *)v22 + 30) == 17)
    && ~((const unsigned __int8)v22[112] >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v40.Name, (Scaleform::GFx::ASString *)&v20[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v40.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v20[1].RefCount);
    v40.Kind &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v40.Name, &other);
    if ( (v40.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v40.Name, &result);
      if ( result.pNode->Size )
      {
        if ( *result.pNode->pData == 64 )
        {
          v40.Kind |= 8u;
          v23 = Scaleform::GFx::ASString::Substring(&result, &v41, 1, result.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v40.Name, v23);
          v24 = v41.pNode;
          v10 = v41.pNode->RefCount == 1;
          --v24->RefCount;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v24);
        }
      }
      v25 = result.pNode;
      v10 = result.pNode->RefCount == 1;
      --v25->RefCount;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    }
    v18 = other.Flags;
    v19 = other.Bonus.pWeakProxy;
  }
  if ( (char)(v18 & 0x1F) > 9 )
  {
    if ( (v18 >> 9) & 1 )
    {
      v10 = v19->RefCount-- == 1;
      if ( v10 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v19);
      other.Bonus.pWeakProxy = 0i64;
      other.value = 0ui64;
      other.Flags = v18 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  pval.Flags = 0;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(v7, v5, &pval);
  v27 = *(unsigned __int8 *)(*((__int64 (__fastcall **)(_QWORD, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))pval.value.VS._1.VStr->pData
                             + 3))(
                              *(_QWORD *)&pval.value.VNumber,
                              &result,
                              &v40,
                              &pval);
  if ( (!(_BYTE)v27 && v4 || v4 == 2) && v8->Size )
  {
    result.pNode = (Scaleform::GFx::ASStringNode *)v7->pMovieImpl->pHeap;
    v28 = (*((__int64 (__fastcall **)(__int64, signed __int64))result.pNode->pData + 10))(v26, 64i64);
    v41.pNode = (Scaleform::GFx::ASStringNode *)v28;
    if ( !v28 )
    {
      v28 = 0i64;
      goto LABEL_66;
    }
    *(_QWORD *)v28 = &Scaleform::GFx::MovieImpl::StickyVarNode::`vftable;
    *(_QWORD *)(v28 + 8) = v8;
    ++v8->RefCount;
    *(_QWORD *)(v28 + 16) = 0i64;
    *(_BYTE *)(v28 + 24) = v4 == 2;
    *(_QWORD *)v28 = &Scaleform::GFx::AS3::MovieRoot::StickyVarNode::`vftable;
    *(_DWORD *)(v28 + 32) = pval.Flags;
    *(_QWORD *)(v28 + 40) = v34;
    *(_QWORD *)(v28 + 48) = v35;
    *(_QWORD *)(v28 + 56) = v36;
    v29 = pval.Flags & 0x1F;
    if ( v29 > 9 )
    {
      if ( (pval.Flags >> 9) & 1 )
      {
        ++*v34;
        goto LABEL_66;
      }
      if ( v29 == 10 )
      {
        ++*(_DWORD *)(v35 + 24);
      }
      else if ( v29 > 10 )
      {
        if ( v29 <= 15 )
        {
          v30 = v35;
LABEL_61:
          if ( v30 )
          {
            ++*(_DWORD *)(v30 + 32);
            *(_DWORD *)(v30 + 32) &= 0x8FBFFFFF;
          }
          goto LABEL_66;
        }
        if ( v29 <= 17 )
        {
          v30 = v36;
          goto LABEL_61;
        }
      }
    }
LABEL_66:
    if ( v28 )
      Scaleform::GFx::MovieImpl::AddStickyVariableNode(
        v7->pMovieImpl,
        &ppath,
        (Scaleform::GFx::MovieImpl::StickyVarNode *)v28);
  }
  v31 = (Scaleform::GFx::AS3::VM *)&v7->pAVM.pObject->vfptr;
  if ( v31->HandleException )
    Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v31);
  if ( (pval.Flags & 0x1F) > 9 )
  {
    if ( (pval.Flags >> 9) & 1 )
    {
      v10 = (*v34)-- == 1;
      if ( v10 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      pval.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&v40);
  v32 = pval.Flags;
  if ( (pval.Flags & 0x1F) > 9 )
  {
    if ( (pval.Flags >> 9) & 1 )
    {
      v10 = pval.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      pval.Bonus.pWeakProxy = 0i64;
      pval.value = 0ui64;
      pval.Flags = v32 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
    }
  }
  v10 = v8->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v33 = ppath.pNode;
  v10 = ppath.pNode->RefCount == 1;
  --v33->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  return v27;
}

// File Line: 1916
// RVA: 0x7F18F0
__int64 __fastcall Scaleform::GFx::AS3::MovieRoot::GetVariableArraySize(Scaleform::GFx::AS3::MovieRoot *this, const char *ppathToVar)
{
  __int64 v2; // rax
  __int64 v3; // rdi
  unsigned int v4; // ebx
  bool v5; // zf
  __int64 result; // rax
  unsigned int v7; // ebx
  Scaleform::GFx::AS3::Value pval; // [rsp+28h] [rbp-30h]

  pval.Flags = 0;
  pval.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &pval, ppathToVar)
    && *(_QWORD *)&pval.value.VNumber
    && (v2 = *(_QWORD *)(*(_QWORD *)&pval.value.VNumber + 40i64), *(_DWORD *)(v2 + 120) == 7)
    && ~(*(_BYTE *)(v2 + 112) >> 5) & 1 )
  {
    v3 = *(_QWORD *)(*(_QWORD *)&pval.value.VNumber + 56i64);
    v4 = pval.Flags;
    if ( (pval.Flags & 0x1F) > 9 )
    {
      if ( (pval.Flags >> 9) & 1 )
      {
        v5 = pval.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v5 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        pval.Bonus.pWeakProxy = 0i64;
        pval.value = 0ui64;
        pval.Flags = v4 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
      }
    }
    result = (unsigned int)v3;
  }
  else
  {
    v7 = pval.Flags;
    if ( (pval.Flags & 0x1F) > 9 )
    {
      if ( (pval.Flags >> 9) & 1 )
      {
        v5 = pval.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v5 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        pval.Bonus.pWeakProxy = 0i64;
        pval.value = 0ui64;
        pval.Flags = v7 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
      }
    }
    result = 0i64;
  }
  return result;
}

// File Line: 1941
// RVA: 0x7F1330
char __fastcall Scaleform::GFx::AS3::MovieRoot::GetVariableArray(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::Movie::SetArrayType type, const char *ppathToVar, unsigned int index, void *pdata, unsigned int count)
{
  unsigned int v6; // esi
  Scaleform::GFx::AS3::MovieRoot *v7; // rbx
  char v8; // al
  unsigned int v9; // er14
  int v10; // ecx
  bool v11; // zf
  long double v12; // r13
  __int64 v13; // rax
  Scaleform::GFx::MovieImpl::ReturnValueHolder *v14; // rax
  Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *v15; // rbx
  Scaleform::GFx::AS3::Impl::SparseArray *v16; // r13
  unsigned __int64 v17; // r15
  long double v18; // r12
  float *v19; // rdi
  unsigned int v20; // esi
  unsigned int v21; // eax
  _DWORD *v22; // rbx
  unsigned int v23; // er14
  Scaleform::GFx::AS3::Value *v24; // rax
  unsigned int v25; // ebx
  Scaleform::GFx::AS3::Value *v26; // rax
  unsigned int v27; // edi
  unsigned int v28; // esi
  _QWORD *v29; // rbx
  Scaleform::GFx::AS3::Value *v30; // rax
  unsigned int v31; // edi
  _QWORD *v32; // rbx
  Scaleform::GFx::AS3::Value *v33; // rsi
  unsigned int v34; // eax
  unsigned int v35; // ebx
  __int64 v36; // r14
  Scaleform::GFx::AS3::Value *v37; // rax
  Scaleform::GFx::ASStringNode *v38; // r15
  __int64 v39; // rcx
  Scaleform::GFx::ASStringNode *v40; // rax
  Scaleform::GFx::ASStringNode *v41; // rcx
  Scaleform::GFx::ASStringNode *v42; // rcx
  int v43; // er12
  unsigned int v44; // ecx
  unsigned __int64 v45; // rdx
  unsigned int v46; // ebx
  __int64 v47; // rdi
  Scaleform::GFx::ASStringNode *v48; // r14
  Scaleform::GFx::AS3::Value *v49; // rax
  __int64 v50; // rax
  Scaleform::GFx::ASStringNode *v51; // r12
  Scaleform::GFx::ASStringNode *v52; // rcx
  unsigned int v53; // eax
  Scaleform::GFx::ASStringNode *v54; // rcx
  unsigned int v55; // ebx
  __int64 v56; // rdi
  unsigned int v57; // eax
  Scaleform::MemoryHeapVtbl *v58; // rax
  __int64 v59; // rax
  _WORD *v60; // rbx
  __int64 v61; // rdi
  __int64 v62; // rsi
  Scaleform::GFx::ASStringNode *v63; // r14
  _WORD *v64; // r15
  unsigned int v65; // eax
  Scaleform::GFx::ASString v67; // [rsp+20h] [rbp-60h]
  int v68; // [rsp+28h] [rbp-58h]
  Scaleform::GFx::AS3::Value pval; // [rsp+30h] [rbp-50h]
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp-30h]
  __int64 v71; // [rsp+58h] [rbp-28h]
  unsigned int v72; // [rsp+60h] [rbp-20h]
  int v73; // [rsp+64h] [rbp-1Ch]
  const char *v74; // [rsp+68h] [rbp-18h]
  __int64 v75; // [rsp+70h] [rbp-10h]
  Scaleform::GFx::AS3::MovieRoot *v76; // [rsp+C0h] [rbp+40h]
  unsigned int v77; // [rsp+D8h] [rbp+58h]

  v77 = index;
  v76 = this;
  v75 = -2i64;
  v6 = index;
  v7 = this;
  pval.Flags = 0;
  pval.Bonus.pWeakProxy = 0i64;
  v8 = Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &pval, ppathToVar);
  v9 = pval.Flags;
  if ( !v8 )
    goto LABEL_108;
  v10 = pval.Flags & 0x1F;
  v73 = v10;
  if ( (unsigned int)(v10 - 12) > 3 )
  {
    if ( v10 <= 9 )
      return 0;
    if ( (pval.Flags >> 9) & 1 )
    {
      v11 = pval.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
      {
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        pval.Bonus.pWeakProxy = 0i64;
        pval.value = 0ui64;
        pval.Flags = v9 & 0xFFFFFDE0;
        return 0;
      }
LABEL_103:
      pval.Bonus.pWeakProxy = 0i64;
      pval.value = 0ui64;
      pval.Flags = v9 & 0xFFFFFDE0;
      return 0;
    }
    goto LABEL_104;
  }
  v12 = pval.value.VNumber;
  if ( !*(_QWORD *)&pval.value.VNumber
    || (v13 = *(_QWORD *)(*(_QWORD *)&pval.value.VNumber + 40i64), *(_DWORD *)(v13 + 120) != 7)
    || !(~(*(_BYTE *)(v13 + 112) >> 5) & 1) )
  {
LABEL_108:
    if ( (pval.Flags & 0x1F) <= 9 )
      return 0;
    if ( (pval.Flags >> 9) & 1 )
    {
      v11 = pval.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      goto LABEL_103;
    }
LABEL_104:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
    return 0;
  }
  v14 = Scaleform::GFx::MovieImpl::GetRetValHolder(v7->pMovieImpl);
  v71 = (__int64)v14;
  v14->StringArrayPos = 0;
  v15 = &v14->StringArray.Data;
  result.pNode = (Scaleform::GFx::ASStringNode *)&v14->StringArray;
  Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v14->StringArray.Data,
    1ui64);
  v16 = (Scaleform::GFx::AS3::Impl::SparseArray *)(*(_QWORD *)&v12 + 56i64);
  v17 = v16->Length;
  *(_QWORD *)&v18 = count;
  v19 = (float *)pdata;
  switch ( (_DWORD)pdata )
  {
    case 0:
      v20 = 0;
      v21 = count;
      if ( (unsigned int)v17 < count )
        v21 = v16->Length;
      if ( v21 )
      {
        v22 = pdata;
        v23 = v21;
        do
        {
          v24 = Scaleform::GFx::AS3::Impl::SparseArray::At(v16, v20 + v77);
          if ( v24->Flags & 0x1F )
            *v22 = v24->value.VS._1.VInt;
          else
            *v22 = 0;
          ++v20;
          ++v22;
        }
        while ( v20 < v23 );
        v19 = (float *)pdata;
        v9 = pval.Flags;
      }
      v6 = v77;
      goto $LN37_18;
    case 1:
      v18 = 0.0;
      v27 = 0;
      v28 = count;
      if ( (unsigned int)v17 < count )
        v28 = v16->Length;
      if ( v28 )
      {
        v29 = pdata;
        do
        {
          v30 = Scaleform::GFx::AS3::Impl::SparseArray::At(v16, v27 + v77);
          if ( v30->Flags & 0x1F )
            *v29 = *(_QWORD *)&v30->value.VNumber;
          else
            *v29 = 0i64;
          ++v27;
          ++v29;
        }
        while ( v27 < v28 );
        v9 = pval.Flags;
      }
      break;
    case 2:
$LN37_18:
      v25 = 0;
      if ( (unsigned int)v17 < count )
        LODWORD(v18) = v17;
      if ( LODWORD(v18) )
      {
        do
        {
          v26 = Scaleform::GFx::AS3::Impl::SparseArray::At(v16, v25 + v6);
          if ( v26->Flags & 0x1F )
            *v19 = v26->value.VNumber;
          else
            *v19 = 0.0;
          ++v25;
          ++v19;
        }
        while ( v25 < LODWORD(v18) );
      }
      goto LABEL_91;
    case 3:
      if ( (unsigned int)v17 < count )
        LODWORD(v18) = v16->Length;
      v34 = LODWORD(v18);
      if ( LODWORD(v18) < 1 )
        v34 = 1;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        v15,
        v34);
      v35 = 0;
      if ( LODWORD(v18) )
      {
        v36 = v71;
        do
        {
          v37 = Scaleform::GFx::AS3::Impl::SparseArray::At(v16, v35 + v6);
          if ( v37->Flags & 0x1F )
          {
            Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v37, &result);
            v38 = result.pNode;
            *(_QWORD *)v19 = result.pNode->pData;
            v39 = *(unsigned int *)(v36 + 48);
            v71 = v39;
            *(_DWORD *)(v36 + 48) = v39 + 1;
            v67.pNode = *(Scaleform::GFx::ASStringNode **)(v36 + 16);
            v40 = v67.pNode;
            ++v38->RefCount;
            v41 = (Scaleform::GFx::ASStringNode *)*((_QWORD *)&v40->pData + v39);
            v11 = v41->RefCount-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v41);
            *((_QWORD *)&v67.pNode->pData + v71) = v38;
            v42 = result.pNode;
            v11 = result.pNode->RefCount == 1;
            --v42->RefCount;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v42);
          }
          else
          {
            *(_QWORD *)v19 = 0i64;
          }
          ++v35;
          v19 += 2;
        }
        while ( v35 < LODWORD(v18) );
        v9 = pval.Flags;
      }
      goto LABEL_91;
    case 4:
      v43 = 0;
      v68 = 0;
      v44 = count;
      if ( (unsigned int)v17 < count )
        v44 = v17;
      v72 = v44;
      v45 = v44;
      if ( v44 < 1 )
        v45 = 1i64;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        v15,
        v45);
      v46 = 0;
      if ( (_DWORD)v17 )
      {
        v47 = 0i64;
        v48 = result.pNode;
        do
        {
          v49 = Scaleform::GFx::AS3::Impl::SparseArray::At(v16, v46 + v6);
          if ( v49->Flags & 0x1F )
          {
            Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v49, &v67);
            v74 = v48->pData;
            v50 = (__int64)v74;
            v51 = v67.pNode;
            ++v51->RefCount;
            v52 = *(Scaleform::GFx::ASStringNode **)(v47 + v50);
            v11 = v52->RefCount-- == 1;
            if ( v11 )
            {
              Scaleform::GFx::ASStringNode::ReleaseNode(v52);
              v50 = (__int64)v74;
            }
            *(_QWORD *)(v47 + v50) = v51;
            v53 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&v67.pNode);
            v43 = v53 + v68 + 1;
            v68 += v53 + 1;
            v54 = v67.pNode;
            v11 = v67.pNode->RefCount == 1;
            --v54->RefCount;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v54);
          }
          ++v46;
          v47 += 8i64;
        }
        while ( v46 < (unsigned int)v17 );
        v9 = pval.Flags;
      }
      v55 = (2 * v43 + 4095) & 0xFFFFF000;
      v56 = v71;
      v57 = *(_DWORD *)(v71 + 8);
      if ( v57 < v55 || v57 > v55 && v57 - v55 > 0x1000 )
      {
        v58 = Scaleform::Memory::pGlobalHeap->vfptr;
        if ( *(_QWORD *)v71 )
          v59 = (__int64)v58->Realloc(Scaleform::Memory::pGlobalHeap, *(void **)v71, v55);
        else
          v59 = (__int64)v58->Alloc(Scaleform::Memory::pGlobalHeap, v55, 0i64);
        *(_QWORD *)v56 = v59;
        *(_DWORD *)(v56 + 8) = v55;
      }
      v60 = *(_WORD **)v56;
      if ( v72 )
      {
        v61 = 0i64;
        v62 = v72;
        v63 = result.pNode;
        do
        {
          v67.pNode = **(Scaleform::GFx::ASStringNode ***)&v63->pData[v61];
          v64 = v60;
          while ( 1 )
          {
            v65 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v67);
            if ( !v65 )
              break;
            *v60 = v65;
            ++v60;
          }
          --v67.pNode;
          *v60 = 0;
          ++v60;
          *(_QWORD *)((char *)pdata + v61) = v64;
          v61 += 8i64;
          --v62;
        }
        while ( v62 );
        v9 = pval.Flags;
      }
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        (Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)result.pNode,
        1ui64);
      goto LABEL_91;
    case 5:
      v31 = 0;
      if ( (unsigned int)v17 < count )
        LODWORD(v18) = v16->Length;
      if ( LODWORD(v18) )
      {
        v32 = (char *)pdata + 16;
        do
        {
          v33 = Scaleform::GFx::AS3::Impl::SparseArray::At(v16, v31 + v6);
          if ( (*((_DWORD *)v32 + 2) >> 6) & 1 )
          {
            (*(void (__fastcall **)(_QWORD, _QWORD *, _QWORD))(*(_QWORD *)*v32 + 16i64))(*v32, v32 - 2, v32[2]);
            *v32 = 0i64;
          }
          *((_DWORD *)v32 + 2) = 0;
          if ( v33->Flags & 0x1F )
            Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v76, v33, (Scaleform::GFx::Value *)(v32 - 2));
          else
            *((_DWORD *)v32 + 2) = 0;
          ++v31;
          v32 += 6;
          v6 = v77;
        }
        while ( v31 < LODWORD(v18) );
        v9 = pval.Flags;
      }
LABEL_91:
      v18 = 0.0;
      break;
    default:
      break;
  }
  if ( v73 > 9 )
  {
    if ( (v9 >> 9) & 1 )
    {
      v11 = pval.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      *(long double *)&pval.Bonus.pWeakProxy = v18;
      pval.value.VNumber = v18;
      *(long double *)&pval.value.VS._2.VObj = v18;
      pval.Flags = v9 & 0xFFFFFDE0;
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
__int64 __fastcall Scaleform::GFx::AS3::MovieRoot::SetVariableArraySize(Scaleform::GFx::AS3::MovieRoot *this, const char *ppathToVar, unsigned int count, Scaleform::GFx::Movie::SetVarType setType)
{
  Scaleform::GFx::Movie::SetVarType v4; // er15
  unsigned __int64 v5; // rbx
  const char *v6; // r14
  Scaleform::GFx::AS3::MovieRoot *v7; // rsi
  char v8; // al
  unsigned int v9; // edi
  __int64 v10; // rax
  __int64 v11; // rsi
  unsigned int v12; // ebx
  bool v13; // zf
  Scaleform::GFx::AS3::Value value; // [rsp+8h] [rbp-49h]
  Scaleform::GFx::AS3::Value pval; // [rsp+28h] [rbp-29h]
  Scaleform::GFx::Value pdestVal; // [rsp+48h] [rbp-9h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> result; // [rsp+78h] [rbp+27h]
  Scaleform::GFx::AS3::Value::V2U v19; // [rsp+80h] [rbp+2Fh]
  __int64 v20; // [rsp+88h] [rbp+37h]

  v20 = -2i64;
  v4 = setType;
  v5 = count;
  v6 = ppathToVar;
  v7 = this;
  pval.Flags = 0;
  pval.Bonus.pWeakProxy = 0i64;
  v8 = Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &pval, ppathToVar);
  v9 = pval.Flags;
  if ( v8
    && (pval.Flags & 0x1F) - 12 <= 3
    && *(_QWORD *)&pval.value.VNumber
    && (v10 = *(_QWORD *)(*(_QWORD *)&pval.value.VNumber + 40i64), *(_DWORD *)(v10 + 120) == 7)
    && ~(*(_BYTE *)(v10 + 112) >> 5) & 1 )
  {
    if ( (_DWORD)v5 != *(_DWORD *)(*(_QWORD *)&pval.value.VNumber + 56i64) )
      Scaleform::GFx::AS3::Impl::SparseArray::Resize(
        (Scaleform::GFx::AS3::Impl::SparseArray *)(*(_QWORD *)&pval.value.VNumber + 56i64),
        (unsigned int)v5);
    LOBYTE(v11) = 1;
  }
  else
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
      &result,
      (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)v7->pAVM.pObject->TraitsArray.pObject->ITraits.pObject);
    Scaleform::GFx::AS3::Impl::SparseArray::Resize(&result.pV->SA, v5);
    value.value.VS._2 = v19;
    pdestVal.pObjectInterface = 0i64;
    pdestVal.Type = 0;
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v7, &value, &pdestVal);
    v11 = ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, const char *, Scaleform::GFx::Value *, _QWORD))v7->vfptr[48].__vecDelDtor)(
            v7,
            v6,
            &pdestVal,
            (unsigned int)v4);
    if ( ((unsigned int)pdestVal.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pdestVal.pObjectInterface->vfptr->gap8[8])(
        pdestVal.pObjectInterface,
        &pdestVal,
        *(_QWORD *)&pdestVal.mValue.NValue);
      pdestVal.pObjectInterface = 0i64;
    }
    pdestVal.Type = 0;
    v12 = value.Flags;
    if ( (value.Flags & 0x1F) > 9 )
    {
      if ( (value.Flags >> 9) & 1 )
      {
        v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        value.Bonus.pWeakProxy = 0i64;
        value.value = 0ui64;
        value.Flags = v12 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
      }
    }
  }
  if ( (char)(v9 & 0x1F) > 9 )
  {
    if ( (v9 >> 9) & 1 )
    {
      v13 = pval.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      pval.Bonus.pWeakProxy = 0i64;
      pval.value = 0ui64;
      pval.Flags = v9 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
    }
  }
  return (unsigned __int8)v11;
}

// File Line: 2112
// RVA: 0x81F560
char __fastcall Scaleform::GFx::AS3::MovieRoot::SetVariableArray(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::Movie::SetArrayType type, const char *ppathToVar, unsigned int index, const void *pdata, unsigned int count, Scaleform::GFx::Movie::SetVarType setType)
{
  unsigned int v7; // er12
  Scaleform::GFx::Movie::SetArrayType v8; // edi
  Scaleform::GFx::AS3::MovieRoot *v9; // r14
  __int64 v10; // rsi
  char v11; // al
  Scaleform::GFx::ASStringNode *v12; // rbx
  unsigned int v13; // er13
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
  long double *v24; // rsi
  long double v25; // xmm0_8
  unsigned int v26; // edi
  Scaleform::GFx::Value *v27; // rsi
  unsigned int v28; // edi
  const char **v29; // rsi
  Scaleform::GFx::AS3::Value::V2U v30; // r15
  Scaleform::GFx::AS3::Impl::SparseArray *v31; // rbx
  long double *v32; // rax
  long double v33; // rdx
  Scaleform::GFx::ASStringNode *v34; // rcx
  unsigned int v35; // edi
  const wchar_t **v36; // rsi
  Scaleform::GFx::AS3::Value::V2U v37; // r15
  Scaleform::GFx::AS3::Impl::SparseArray *v38; // r13
  long double *v39; // rax
  long double v40; // rdx
  Scaleform::GFx::ASStringNode *v41; // rcx
  __int64 v42; // rsi
  int v43; // edi
  int v44; // ecx
  Scaleform::GFx::ASStringNode *v45; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v46; // rcx
  unsigned int v47; // eax
  int v48; // ecx
  unsigned int v49; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v50; // rcx
  unsigned int v51; // eax
  char result; // al
  int v53; // ecx
  Scaleform::GFx::AS3::WeakProxy *v54; // rdx
  unsigned int v55; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v56; // rcx
  unsigned int v57; // eax
  int v58; // eax
  Scaleform::GFx::AS3::Value pval; // [rsp+20h] [rbp-E0h]
  Scaleform::GFx::ASStringNode *v60; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::ASString v61; // [rsp+48h] [rbp-B8h]
  char v62[18]; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v63; // [rsp+62h] [rbp-9Eh]
  Scaleform::GFx::ASStringNode *v64; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::AS3::Value v65; // [rsp+78h] [rbp-88h]
  Scaleform::GFx::AS3::Value v66; // [rsp+98h] [rbp-68h]
  Scaleform::GFx::AS3::Value pdestVal; // [rsp+B8h] [rbp-48h]
  __int64 v68; // [rsp+D8h] [rbp-28h]
  Scaleform::GFx::AS3::Value v; // [rsp+E8h] [rbp-18h]
  Scaleform::GFx::AS3::Value v70; // [rsp+108h] [rbp+8h]
  Scaleform::GFx::AS3::Value v71; // [rsp+128h] [rbp+28h]
  __int64 v72; // [rsp+148h] [rbp+48h]
  Scaleform::GFx::AS3::MovieRoot *v73; // [rsp+1A0h] [rbp+A0h]
  char v74; // [rsp+1A8h] [rbp+A8h]
  const char *v75; // [rsp+1B0h] [rbp+B0h]
  unsigned int v76; // [rsp+1B8h] [rbp+B8h]

  v76 = index;
  v75 = ppathToVar;
  v73 = this;
  v72 = -2i64;
  v7 = index;
  v8 = type;
  v9 = this;
  v10 = 0i64;
  v60 = 0i64;
  v64 = 0i64;
  pval.Flags = 0;
  pval.Bonus.pWeakProxy = 0i64;
  v11 = Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &pval, ppathToVar);
  v12 = pval.value.VS._1.VStr;
  v13 = pval.Flags;
  if ( v11 )
  {
    if ( (pval.Flags & 0x1F) - 12 <= 3 )
    {
      if ( *(_QWORD *)&pval.value.VNumber )
      {
        v14 = *(_QWORD *)(*(_QWORD *)&pval.value.VNumber + 40i64);
        if ( *(_DWORD *)(v14 + 120) == 7 )
        {
          if ( ~(*(_BYTE *)(v14 + 112) >> 5) & 1 )
          {
            *(_DWORD *)(*(_QWORD *)&pval.value.VNumber + 32i64) = (*(_DWORD *)(*(_QWORD *)&pval.value.VNumber + 32i64)
                                                                 + 1) & 0x8FBFFFFF;
            v10 = (__int64)v12;
            v60 = v12;
            v64 = v12;
          }
        }
      }
    }
  }
  v74 = 1;
  if ( !v10 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)((char *)&v63 + 6),
      (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)v9->pAVM.pObject->TraitsArray.pObject->ITraits.pObject);
    if ( *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)((char *)&v63 + 6) )
      v10 = *(__int64 *)((char *)&v63 + 6);
    v60 = (Scaleform::GFx::ASStringNode *)v10;
    v64 = (Scaleform::GFx::ASStringNode *)v10;
    v74 = 0;
  }
  v15 = (Scaleform::GFx::AS3::Impl::SparseArray *)(v10 + 56);
  *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)((char *)&v63 + 6) = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)(v10 + 56);
  if ( v7 + count > *(_DWORD *)(v10 + 56) )
    Scaleform::GFx::AS3::Impl::SparseArray::Resize((Scaleform::GFx::AS3::Impl::SparseArray *)(v10 + 56), v7 + count);
  switch ( v8 )
  {
    case 0:
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
          Scaleform::GFx::AS3::Impl::SparseArray::Set(v15, v16 + v7, &v);
          if ( (v.Flags & 0x1F) > 9 )
          {
            if ( (v.Flags >> 9) & 1 )
            {
              v19 = v.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v.Bonus.pWeakProxy = 0i64;
              v.value = 0ui64;
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
        v10 = (__int64)v60;
      }
      break;
    case 1:
      v23 = 0;
      if ( count )
      {
        v24 = (long double *)pdata;
        do
        {
          v25 = *v24;
          v70.Flags = 4;
          v70.Bonus.pWeakProxy = 0i64;
          v70.value.VNumber = v25;
          Scaleform::GFx::AS3::Impl::SparseArray::Set(v15, v23 + v7, &v70);
          if ( (v70.Flags & 0x1F) > 9 )
          {
            if ( (v70.Flags >> 9) & 1 )
            {
              v19 = v70.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v70.Bonus.pWeakProxy = 0i64;
              v70.value = 0ui64;
              v70.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v70);
            }
          }
          ++v23;
          ++v24;
        }
        while ( v23 < count );
        v10 = (__int64)v60;
      }
      break;
    case 2:
      v20 = 0;
      if ( count )
      {
        v21 = (float *)pdata;
        do
        {
          v22 = *v21;
          v71.Flags = 4;
          v71.Bonus.pWeakProxy = 0i64;
          v71.value.VNumber = v22;
          Scaleform::GFx::AS3::Impl::SparseArray::Set(v15, v20 + v7, &v71);
          if ( (v71.Flags & 0x1F) > 9 )
          {
            if ( (v71.Flags >> 9) & 1 )
            {
              v19 = v71.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v71.Bonus.pWeakProxy = 0i64;
              v71.value = 0ui64;
              v71.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v71);
            }
          }
          ++v20;
          ++v21;
        }
        while ( v20 < count );
        v10 = (__int64)v60;
      }
      break;
    case 3:
      v28 = 0;
      if ( count )
      {
        v29 = (const char **)pdata;
        v30.VObj = *(Scaleform::GFx::AS3::Object **)v62;
        v31 = *(Scaleform::GFx::AS3::Impl::SparseArray **)((char *)&v63 + 6);
        do
        {
          v32 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                 (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v73->BuiltinsMgr.Builtins,
                                 (Scaleform::GFx::ASString *)((char *)&v63 + 6),
                                 *v29);
          v65.Flags = 10;
          v65.Bonus.pWeakProxy = 0i64;
          v33 = *v32;
          v65.value.VNumber = *v32;
          if ( *(_QWORD *)v32 == *(_QWORD *)(*(_QWORD *)v32 + 8i64) + 104i64 )
          {
            v65.value.VNumber = 0.0;
            v65.value.VS._2 = v30;
            v65.Flags = 12;
          }
          else
          {
            ++*(_DWORD *)(*(_QWORD *)&v33 + 24i64);
          }
          Scaleform::GFx::AS3::Impl::SparseArray::Set(v31, v28 + v76, &v65);
          if ( (v65.Flags & 0x1F) > 9 )
          {
            if ( (v65.Flags >> 9) & 1 )
            {
              v19 = v65.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v65.Bonus.pWeakProxy = 0i64;
              v65.value = 0ui64;
              v65.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v65);
            }
          }
          v34 = *(Scaleform::GFx::ASStringNode **)((char *)&v63 + 6);
          v19 = LODWORD((*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)((char *)&v63 + 6))->pPrev) == 1;
          --v34->RefCount;
          if ( v19 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v34);
          ++v28;
          ++v29;
        }
        while ( v28 < count );
        goto LABEL_83;
      }
      break;
    case 4:
      v35 = 0;
      if ( count )
      {
        v36 = (const wchar_t **)pdata;
        v37.VObj = *(Scaleform::GFx::AS3::Object **)v62;
        v38 = *(Scaleform::GFx::AS3::Impl::SparseArray **)((char *)&v63 + 6);
        do
        {
          v39 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                 (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v73->BuiltinsMgr.Builtins,
                                 &v61,
                                 *v36,
                                 -1i64);
          v66.Flags = 10;
          v66.Bonus.pWeakProxy = 0i64;
          v40 = *v39;
          v66.value.VNumber = *v39;
          if ( *(_QWORD *)v39 == *(_QWORD *)(*(_QWORD *)v39 + 8i64) + 104i64 )
          {
            v66.value.VNumber = 0.0;
            v66.value.VS._2 = v37;
            v66.Flags = 12;
          }
          else
          {
            ++*(_DWORD *)(*(_QWORD *)&v40 + 24i64);
          }
          Scaleform::GFx::AS3::Impl::SparseArray::Set(v38, v35 + v76, &v66);
          if ( (v66.Flags & 0x1F) > 9 )
          {
            if ( (v66.Flags >> 9) & 1 )
            {
              v19 = v66.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v66.Bonus.pWeakProxy = 0i64;
              v66.value = 0ui64;
              v66.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v66);
            }
          }
          v41 = v61.pNode;
          v19 = v61.pNode->RefCount == 1;
          --v41->RefCount;
          if ( v19 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v41);
          ++v35;
          ++v36;
        }
        while ( v35 < count );
LABEL_83:
        v10 = (__int64)v60;
        v13 = pval.Flags;
        v12 = pval.value.VS._1.VStr;
      }
      break;
    case 5:
      v26 = 0;
      if ( count )
      {
        v27 = (Scaleform::GFx::Value *)pdata;
        do
        {
          pdestVal.Flags = 0;
          pdestVal.Bonus.pWeakProxy = 0i64;
          Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(v73, v27, &pdestVal);
          Scaleform::GFx::AS3::Impl::SparseArray::Set(v15, v26 + v7, &pdestVal);
          if ( (pdestVal.Flags & 0x1F) > 9 )
          {
            if ( (pdestVal.Flags >> 9) & 1 )
            {
              v19 = pdestVal.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              pdestVal.Bonus.pWeakProxy = 0i64;
              pdestVal.value = 0ui64;
              pdestVal.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&pdestVal);
            }
          }
          ++v26;
          ++v27;
        }
        while ( v26 < count );
        v13 = pval.Flags;
        v10 = (__int64)v60;
      }
      break;
    default:
      break;
  }
  if ( v74 )
  {
    v53 = v13 & 0x1F;
    if ( v53 > 9 )
    {
      if ( (v13 >> 9) & 1 )
      {
        v54 = pval.Bonus.pWeakProxy;
        v19 = pval.Bonus.pWeakProxy->RefCount == 1;
        --v54->RefCount;
        if ( v19 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
            Scaleform::Memory::pGlobalHeap,
            v54,
            5368709120i64);
        pval.Bonus.pWeakProxy = 0i64;
        pval.value = 0ui64;
        pval.Flags = v13 & 0xFFFFFDE0;
      }
      else
      {
        switch ( v53 )
        {
          case 10:
            v19 = v12->RefCount-- == 1;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v12);
            break;
          case 11:
          case 12:
          case 13:
          case 14:
          case 15:
            if ( pval.value.VS._1.VBool )
            {
              *(_QWORD *)&pval.value.VNumber = (char *)v12 - 1;
            }
            else if ( v12 )
            {
              v55 = v12->Size;
              if ( v55 & 0x3FFFFF )
              {
                v12->Size = v55 - 1;
                v56 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v12;
                goto LABEL_142;
              }
            }
            break;
          case 16:
          case 17:
            if ( (_QWORD)pval.value.VS._2.VObj & 1 )
            {
              --pval.value.VS._2.VObj;
            }
            else
            {
              v56 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&pval.value.VS._2.VObj->vfptr;
              if ( pval.value.VS._2.VObj )
              {
                v57 = pval.value.VS._2.VObj->RefCount;
                if ( v57 & 0x3FFFFF )
                {
                  pval.value.VS._2.VObj->RefCount = v57 - 1;
LABEL_142:
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v56);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    if ( v10 & 1 )
    {
      v64 = (Scaleform::GFx::ASStringNode *)(v10 - 1);
    }
    else
    {
      v58 = *(_DWORD *)(v10 + 32);
      if ( v58 & 0x3FFFFF )
      {
        *(_DWORD *)(v10 + 32) = v58 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v10);
      }
    }
    result = 1;
  }
  else
  {
    *(_QWORD *)v62 = 0i64;
    LODWORD(v61.pNode) = 12;
    *(_QWORD *)&v62[8] = v10;
    *(_QWORD *)&v62[16] = 0i64;
    v64 = 0i64;
    pdestVal.value.VNumber = 0.0;
    LODWORD(pdestVal.value.VS._2.VObj) = 0;
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(
      v73,
      (Scaleform::GFx::AS3::Value *)&v61,
      (Scaleform::GFx::Value *)&pdestVal);
    v42 = ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, const char *, Scaleform::GFx::AS3::Value *, _QWORD))v73->vfptr[48].__vecDelDtor)(
            v73,
            v75,
            &pdestVal,
            (unsigned int)setType);
    if ( (LODWORD(pdestVal.value.VS._2.VObj) >> 6) & 1 )
    {
      (*((void (__fastcall **)(_QWORD, Scaleform::GFx::AS3::Value *, __int64))pdestVal.value.VS._1.VStr->pData + 2))(
        *(_QWORD *)&pdestVal.value.VNumber,
        &pdestVal,
        v68);
      pdestVal.value.VNumber = 0.0;
    }
    LODWORD(pdestVal.value.VS._2.VObj) = 0;
    v43 = *(_DWORD *)((char *)&v61.pNode + 2);
    v44 = BYTE2(v61.pNode) & 0x1F;
    if ( v44 > 9 )
    {
      if ( (*(_DWORD *)((char *)&v61.pNode + 2) >> 9) & 1 )
      {
        v19 = (**(_DWORD **)&v62[2])-- == 1;
        if ( v19 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        *(_OWORD *)&v62[2] = 0ui64;
        v63 = 0i64;
        *(_DWORD *)((char *)&v61.pNode + 2) = v43 & 0xFFFFFDE0;
      }
      else
      {
        switch ( v44 )
        {
          case 10:
            v45 = *(Scaleform::GFx::ASStringNode **)&v62[10];
            v19 = *(_DWORD *)(*(_QWORD *)&v62[10] + 24i64) == 1;
            --v45->RefCount;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v45);
            break;
          case 11:
          case 12:
          case 13:
          case 14:
          case 15:
            if ( !(v62[10] & 1) )
            {
              v46 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v62[10];
              goto LABEL_98;
            }
            --*(_QWORD *)&v62[10];
            break;
          case 16:
          case 17:
            if ( (unsigned __int8)v63 & 1 )
            {
              v63 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v63 - 1);
            }
            else
            {
              v46 = v63;
LABEL_98:
              if ( v46 )
              {
                v47 = v46->RefCount;
                if ( v47 & 0x3FFFFF )
                {
                  v46->RefCount = v47 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v46);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    v48 = v13 & 0x1F;
    if ( v48 > 9 )
    {
      if ( (v13 >> 9) & 1 )
      {
        v19 = (**(_DWORD **)((char *)&pval.Bonus.pWeakProxy + 2))-- == 1;
        if ( v19 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        *(_OWORD *)((char *)&pval.Bonus.pWeakProxy + 2) = 0ui64;
        *(Scaleform::GFx::AS3::Traits **)((char *)&pval.value.VS._2.pTraits + 2) = 0i64;
        *(unsigned int *)((char *)&pval.Flags + 2) = v13 & 0xFFFFFDE0;
      }
      else
      {
        switch ( v48 )
        {
          case 10:
            v19 = v12->RefCount-- == 1;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v12);
            break;
          case 11:
          case 12:
          case 13:
          case 14:
          case 15:
            if ( pval.value.VS._1.VInt & 0x10000 )
            {
              *(Scaleform::GFx::AS3::Value::V1U *)((char *)&pval.value.VS._1 + 2) = (Scaleform::GFx::AS3::Value::V1U)((char *)&v12[-1].Size + 7);
            }
            else if ( v12 )
            {
              v49 = v12->Size;
              if ( v49 & 0x3FFFFF )
              {
                v12->Size = v49 - 1;
                v50 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v12;
                goto LABEL_122;
              }
            }
            break;
          case 16:
          case 17:
            if ( BYTE2(pval.value.VS._2.pTraits) & 1 )
            {
              --*(Scaleform::GFx::AS3::Traits **)((char *)&pval.value.VS._2.pTraits + 2);
            }
            else
            {
              v50 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)((char *)&pval.value.VS._2.pTraits + 2);
              if ( *(Scaleform::GFx::AS3::Traits **)((char *)&pval.value.VS._2.pTraits + 2) )
              {
                v51 = (*(Scaleform::GFx::AS3::Traits **)((char *)&pval.value.VS._2.pTraits + 2))->RefCount;
                if ( v51 & 0x3FFFFF )
                {
                  (*(Scaleform::GFx::AS3::Traits **)((char *)&pval.value.VS._2.pTraits + 2))->RefCount = v51 - 1;
LABEL_122:
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v50);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    result = v42;
  }
  return result;
}:AS3::Traits **)((char *)&pval.value.VS._2.pTraits + 2) )
              {
                v51 = (*(Scaleform::GFx::AS3::Traits **)((char *)&pval.value.VS._2.pTraits + 2))->RefCount;
                if ( v51 & 0x3FFFFF )
                {
              

// File Line: 2211
// RVA: 0x7F8160
__int64 __fastcall Scaleform::GFx::AS3::MovieRoot::IsAvailable(Scaleform::GFx::AS3::MovieRoot *this, const char *ppathToVar)
{
  unsigned __int8 v2; // di
  unsigned int v3; // ebx
  bool v4; // zf
  Scaleform::GFx::AS3::Value pval; // [rsp+28h] [rbp-30h]

  pval.Flags = 0;
  pval.Bonus.pWeakProxy = 0i64;
  v2 = Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &pval, ppathToVar);
  v3 = pval.Flags;
  if ( (pval.Flags & 0x1F) > 9 )
  {
    if ( (pval.Flags >> 9) & 1 )
    {
      v4 = pval.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v4 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      pval.Bonus.pWeakProxy = 0i64;
      pval.value = 0ui64;
      pval.Flags = v3 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
    }
  }
  return v2;
}

// File Line: 2222
// RVA: 0x7F7290
_BOOL8 __fastcall Scaleform::GFx::AS3::MovieRoot::Invoke(Scaleform::GFx::AS3::MovieRoot *this, const char *pmethodName, Scaleform::GFx::Value *presult, Scaleform::GFx::Value *pargs)
{
  Scaleform::GFx::Value *v4; // rdi
  Scaleform::GFx::Value *v5; // r13
  const char *v6; // r15
  Scaleform::GFx::AS3::MovieRoot *v7; // r14
  Scaleform::GFx::AS3::Value *v8; // rax
  Scaleform::GFx::AS3::Value::Extra v9; // rbx
  __int64 v10; // rsi
  Scaleform::GFx::AS3::Value *v11; // r8
  Scaleform::GFx::AS3::Value *v12; // rbx
  long double v13; // rdi
  Scaleform::GFx::AS3::Value *v14; // rsi
  bool v15; // r15
  unsigned int v16; // ebx
  int v17; // ecx
  bool v18; // zf
  Scaleform::GFx::ASStringNode *v19; // rcx
  long double v20; // rcx
  int v21; // eax
  Scaleform::GFx::AS3::VM *v22; // rcx
  Scaleform::GFx::AS3::Value *v23; // rbx
  Scaleform::GFx::AS3::WeakProxy *v24; // rdx
  int v25; // eax
  Scaleform::GFx::ASStringNode *v26; // rcx
  long double v27; // rcx
  int v28; // eax
  unsigned int v29; // edx
  Scaleform::GFx::AS3::Value pval; // [rsp+40h] [rbp-98h]
  Scaleform::GFx::AS3::Value result; // [rsp+60h] [rbp-78h]
  Scaleform::GFx::AS3::Value *argv; // [rsp+2D8h] [rbp+200h]
  void *argc; // [rsp+2F8h] [rbp+220h]

  *(_QWORD *)&result.Flags = -2i64;
  v4 = pargs;
  v5 = presult;
  v6 = pmethodName;
  v7 = this;
  if ( (unsigned int)argc <= 0xA )
    v8 = (Scaleform::GFx::AS3::Value *)((char *)&result + 24);
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
        v11 = (Scaleform::GFx::AS3::Value *)v9.pWeakProxy;
      }
      else
      {
        v11 = 0i64;
      }
      Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(v7, v4, v11);
      ++v4;
      v9.pWeakProxy += 2;
      --v10;
    }
    while ( v10 );
  }
  result.Flags = 0;
  result.Bonus.pWeakProxy = 0i64;
  if ( v7->pInvokeAliases )
  {
    v12 = Scaleform::GFx::AS3::MovieRoot::ResolveInvokeAlias(v7, v6);
    if ( v12 )
    {
      if ( _S11_12 & 1 )
      {
        v13 = 0.0;
      }
      else
      {
        _S11_12 |= 1u;
        v13 = 0.0;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      v14 = argv;
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
        (Scaleform::GFx::AS3::VM *)&v7->pAVM.pObject->vfptr,
        v12,
        &v,
        &result,
        (unsigned int)argc,
        argv,
        0);
LABEL_40:
      v22 = (Scaleform::GFx::AS3::VM *)&v7->pAVM.pObject->vfptr;
      v15 = v22->HandleException == 0;
      if ( v22->HandleException )
        Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v22);
      if ( v15 && v5 )
        Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v7, &result, v5);
      goto LABEL_45;
    }
  }
  pval.Flags = 0;
  pval.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(v7, &pval, v6) )
  {
    if ( _S11_12 & 1 )
    {
      v13 = 0.0;
    }
    else
    {
      _S11_12 |= 1u;
      v13 = 0.0;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    v14 = argv;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
      (Scaleform::GFx::AS3::VM *)&v7->pAVM.pObject->vfptr,
      &pval,
      &v,
      &result,
      (unsigned int)argc,
      argv,
      0);
    v15 = 1;
  }
  else
  {
    v15 = 0;
    v14 = argv;
    v13 = 0.0;
  }
  v16 = pval.Flags;
  v17 = pval.Flags & 0x1F;
  if ( v17 > 9 )
  {
    if ( (pval.Flags >> 9) & 1 )
    {
      v18 = pval.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v18 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      pval.Bonus.pWeakProxy = 0i64;
      pval.value = 0ui64;
      pval.Flags = v16 & 0xFFFFFDE0;
    }
    else
    {
      switch ( v17 )
      {
        case 10:
          v19 = pval.value.VS._1.VStr;
          v18 = *(_DWORD *)(*(_QWORD *)&pval.value.VNumber + 24i64) == 1;
          --v19->RefCount;
          if ( v18 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v19);
          break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
          if ( !pval.value.VS._1.VBool )
          {
            v20 = pval.value.VNumber;
            goto LABEL_36;
          }
          --*(_QWORD *)&pval.value.VNumber;
          break;
        case 16:
        case 17:
          if ( (_QWORD)pval.value.VS._2.VObj & 1 )
          {
            --pval.value.VS._2.VObj;
          }
          else
          {
            v20 = *(double *)&pval.value.VS._2.VObj;
LABEL_36:
            if ( v20 != 0.0 )
            {
              v21 = *(_DWORD *)(*(_QWORD *)&v20 + 32i64);
              if ( v21 & 0x3FFFFF )
              {
                *(_DWORD *)(*(_QWORD *)&v20 + 32i64) = v21 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v20);
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
    v23 = v14;
    *(_QWORD *)&v13 = (unsigned int)argc;
    do
    {
      if ( (v23->Flags & 0x1F) > 9 )
      {
        if ( (v23->Flags >> 9) & 1 )
        {
          v24 = v23->Bonus.pWeakProxy;
          v18 = v24->RefCount-- == 1;
          if ( v18 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v23->Bonus.pWeakProxy = 0i64;
          v23->value.VNumber = 0.0;
          v23->value.VS._2.VObj = 0i64;
          v23->Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(v23);
        }
      }
      ++v23;
      --*(_QWORD *)&v13;
    }
    while ( v13 != 0.0 );
  }
  if ( (unsigned int)argc > 0xA )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v14);
  v25 = result.Flags & 0x1F;
  if ( v25 > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v18 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v18 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      *(long double *)&result.Bonus.pWeakProxy = v13;
      result.value.VNumber = v13;
      *(long double *)&result.value.VS._2.VObj = v13;
      result.Flags &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v25 )
      {
        case 10:
          v26 = result.value.VS._1.VStr;
          v18 = *(_DWORD *)(*(_QWORD *)&result.value.VNumber + 24i64) == 1;
          --v26->RefCount;
          if ( v18 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v26);
          break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
          v27 = result.value.VNumber;
          if ( result.value.VS._1.VBool )
          {
            --*(_QWORD *)&result.value.VNumber;
          }
          else if ( *(_QWORD *)&result.value.VNumber )
          {
            v28 = *(_DWORD *)(*(_QWORD *)&result.value.VNumber + 32i64);
            if ( v28 & 0x3FFFFF )
            {
              *(_DWORD *)(*(_QWORD *)&result.value.VNumber + 32i64) = v28 - 1;
              goto LABEL_74;
            }
          }
          break;
        case 16:
        case 17:
          v27 = *(double *)&result.value.VS._2.VObj;
          if ( (_QWORD)result.value.VS._2.VObj & 1 )
          {
            --result.value.VS._2.VObj;
          }
          else if ( result.value.VS._2.VObj )
          {
            v29 = result.value.VS._2.VObj->RefCount;
            if ( v29 & 0x3FFFFF )
            {
              result.value.VS._2.VObj->RefCount = v29 - 1;
LABEL_74:
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v27);
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
__int64 Scaleform::GFx::AS3::MovieRoot::Invoke(Scaleform::GFx::AS3::MovieRoot *this, const char *pmethodName, Scaleform::GFx::Value *presult, const char *pargFmt, ...)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, const char *, Scaleform::GFx::Value *))this->vfptr[57].__vecDelDtor)(
           this,
           pmethodName,
           presult);
}

// File Line: 2307
// RVA: 0x806350
void __fastcall Scaleform::GFx::AS3::MovieRoot::ParseValueArguments(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::Array<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *arr, const char *pmethodName, const char *pargFmt, char *args)
{
  Scaleform::Array<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v5; // r15
  const char *v6; // rdx
  unsigned int v7; // edi
  Scaleform::GFx::AS3::WeakProxy *v8; // rbx
  char v9; // al
  char *v10; // r14
  Scaleform::GFx::AS3::Value::V2U v11; // r12
  long double v12; // rsi
  signed __int64 v13; // r9
  char *v14; // r13
  char v15; // al
  int v16; // esi
  bool v17; // zf
  Scaleform::GFx::AS3::Value::V2U v18; // r13
  signed __int64 v19; // rcx
  signed __int64 v20; // rdx
  __int64 v21; // rdx
  int v22; // ecx
  signed __int64 v23; // rcx
  signed __int64 v24; // rdx
  __int64 v25; // rdx
  int v26; // ecx
  signed __int64 v27; // rcx
  signed __int64 v28; // rdx
  __int64 v29; // rdx
  int v30; // ecx
  signed __int64 v31; // rcx
  signed __int64 v32; // rdx
  __int64 v33; // rdx
  int v34; // ecx
  signed __int64 v35; // rcx
  signed __int64 v36; // rdx
  __int64 v37; // rdx
  int v38; // ecx
  char v39; // al
  signed __int64 v40; // rcx
  signed __int64 v41; // rdx
  __int64 v42; // rdx
  int v43; // ecx
  long double *v44; // rax
  unsigned int v45; // er14
  long double v46; // r15
  Scaleform::GFx::AS3::Value::V2U v47; // r13
  signed __int64 v48; // rcx
  signed __int64 v49; // rdx
  __int64 v50; // rdx
  int v51; // ecx
  Scaleform::GFx::ASStringNode *v52; // rcx
  char v53; // al
  long double *v54; // rax
  unsigned int v55; // er14
  long double v56; // r15
  Scaleform::GFx::AS3::Value::V2U v57; // r13
  signed __int64 v58; // rcx
  signed __int64 v59; // rdx
  __int64 v60; // rdx
  int v61; // ecx
  unsigned __int8 i; // al
  unsigned int v63; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v64; // rcx
  unsigned int v65; // eax
  __int64 v66[2]; // [rsp+20h] [rbp-B1h]
  Scaleform::GFx::AS3::Value v67; // [rsp+30h] [rbp-A1h]
  char *v68; // [rsp+50h] [rbp-81h]
  __int64 v69; // [rsp+58h] [rbp-79h]
  Scaleform::GFx::LogState *v70; // [rsp+60h] [rbp-71h]
  Scaleform::GFx::AS3::Value::VU v71; // [rsp+68h] [rbp-69h]
  Scaleform::GFx::AS3::Value v72; // [rsp+78h] [rbp-59h]
  Scaleform::GFx::AS3::Value v73; // [rsp+98h] [rbp-39h]
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [rsp+B8h] [rbp-19h]
  Scaleform::GFx::ASString v75; // [rsp+C0h] [rbp-11h]
  Scaleform::GFx::ASString v76; // [rsp+C8h] [rbp-9h]
  __int64 v77; // [rsp+D0h] [rbp-1h]
  __int64 v78; // [rsp+D8h] [rbp+7h]
  Scaleform::GFx::AS3::MovieRoot *v79; // [rsp+130h] [rbp+5Fh]
  Scaleform::Array<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v80; // [rsp+138h] [rbp+67h]
  const char *v81; // [rsp+140h] [rbp+6Fh]
  const char *v82; // [rsp+148h] [rbp+77h]

  v82 = pargFmt;
  v81 = pmethodName;
  v80 = arr;
  v79 = this;
  v78 = -2i64;
  v5 = arr;
  v70 = Scaleform::GFx::StateBag::GetLogState((Scaleform::GFx::StateBag *)&this->pMovieImpl->vfptr, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v5->Data,
    0i64);
  v6 = v82;
  if ( v82 )
  {
    v7 = 0;
    v67.Flags = 0;
    v8 = 0i64;
    v67.Bonus.pWeakProxy = 0i64;
    v9 = *v82;
    v10 = (char *)(v82 + 1);
    v11.VObj = (Scaleform::GFx::AS3::Object *)v67.value.VS._2;
    v12 = v67.value.VNumber;
    if ( *v82 )
    {
      v13 = 17596481012224i64;
      v14 = args;
      do
      {
        if ( v9 == 37 )
        {
          v15 = *v10++;
          v68 = v10;
          switch ( v15 )
          {
            case 100:
              args += 8;
              v16 = *((_DWORD *)args - 2);
              if ( (char)(v7 & 0x1F) > 9 )
              {
                if ( (v7 >> 9) & 1 )
                {
                  v17 = v8->RefCount-- == 1;
                  if ( v17 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, _QWORD, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
                      Scaleform::Memory::pGlobalHeap,
                      v8,
                      0i64,
                      17596481012224i64);
                  v8 = 0i64;
                  v67.Bonus.pWeakProxy = 0i64;
                  v67.value = 0ui64;
                  v7 &= 0xFFFFFDE0;
                  v67.Flags = v7;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v67);
                  v8 = v67.Bonus.pWeakProxy;
                  v7 = v67.Flags;
                }
              }
              v7 = v7 & 0xFFFFFFE2 | 2;
              v67.Flags = v7;
              v71.VS._1.VInt = v16;
              v12 = v71.VNumber;
              v67.value = v71;
              v18.VObj = (Scaleform::GFx::AS3::Object *)v71.VS._2;
              v11.VObj = (Scaleform::GFx::AS3::Object *)v71.VS._2;
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v5->Data.Data,
                v5,
                v5->Data.Size + 1);
              v19 = 32 * v5->Data.Size;
              v20 = (signed __int64)&v5->Data.Data[-1];
              v17 = v19 + v20 == 0;
              v21 = v19 + v20;
              v68 = (char *)v21;
              v69 = v21;
              if ( !v17 )
              {
                *(_DWORD *)v21 = v7;
                *(_QWORD *)(v21 + 8) = v8;
                *(long double *)(v21 + 16) = v12;
                *(Scaleform::GFx::AS3::Value::V2U *)(v21 + 24) = v18;
                v22 = v7 & 0x1F;
                if ( v22 > 9 )
                {
                  if ( (v7 >> 9) & 1 )
                  {
                    ++v8->RefCount;
                  }
                  else if ( v22 == 10 )
                  {
                    ++*(_DWORD *)(*(_QWORD *)&v12 + 24i64);
                  }
                  else if ( v22 > 10 )
                  {
                    if ( v22 <= 15 )
                    {
                      if ( v12 != 0.0 )
                        *(_DWORD *)(*(_QWORD *)&v12 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v12 + 32i64) + 1) & 0x8FBFFFFF;
                    }
                    else if ( v22 <= 17 && v18.VObj )
                    {
                      v18.VObj->RefCount = (v18.VObj->RefCount + 1) & 0x8FBFFFFF;
                    }
                  }
                }
              }
              goto LABEL_174;
            case 117:
              if ( (char)(v7 & 0x1F) > 9 )
              {
                if ( (v7 >> 9) & 1 )
                {
                  v17 = v8->RefCount-- == 1;
                  if ( v17 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, _QWORD, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
                      Scaleform::Memory::pGlobalHeap,
                      v8,
                      0i64,
                      17596481012224i64);
                  v8 = 0i64;
                  v67.Bonus.pWeakProxy = 0i64;
                  v12 = 0.0;
                  v67.value = 0ui64;
                  v11.VObj = 0i64;
                  v7 &= 0xFFFFFDE0;
                  v67.Flags = v7;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v67);
                  v11.VObj = (Scaleform::GFx::AS3::Object *)v67.value.VS._2;
                  v12 = v67.value.VNumber;
                  v8 = v67.Bonus.pWeakProxy;
                  v7 = v67.Flags;
                }
              }
              v7 &= 0xFFFFFFE0;
              v67.Flags = v7;
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v5->Data.Data,
                v5,
                v5->Data.Size + 1);
              v23 = 32 * v5->Data.Size;
              v24 = (signed __int64)&v5->Data.Data[-1];
              v17 = v23 + v24 == 0;
              v25 = v23 + v24;
              v69 = v25;
              v68 = (char *)v25;
              if ( !v17 )
              {
                *(_DWORD *)v25 = v7;
                *(_QWORD *)(v25 + 8) = v8;
                *(long double *)(v25 + 16) = v12;
                *(Scaleform::GFx::AS3::Value::V2U *)(v25 + 24) = v11;
                v26 = v7 & 0x1F;
                if ( v26 > 9 )
                {
                  if ( (v7 >> 9) & 1 )
                  {
                    ++v8->RefCount;
                  }
                  else if ( v26 == 10 )
                  {
                    ++*(_DWORD *)(*(_QWORD *)&v12 + 24i64);
                  }
                  else if ( v26 > 10 )
                  {
                    if ( v26 <= 15 )
                    {
                      if ( v12 != 0.0 )
                        *(_DWORD *)(*(_QWORD *)&v12 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v12 + 32i64) + 1) & 0x8FBFFFFF;
                    }
                    else if ( v26 <= 17 && v11.VObj )
                    {
                      v11.VObj->RefCount = (v11.VObj->RefCount + 1) & 0x8FBFFFFF;
                    }
                  }
                }
              }
              goto LABEL_175;
            case 110:
              if ( (char)(v7 & 0x1F) > 9 )
              {
                if ( (v7 >> 9) & 1 )
                {
                  v17 = v8->RefCount-- == 1;
                  if ( v17 )
                    ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, _QWORD, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
                      Scaleform::Memory::pGlobalHeap,
                      v8,
                      0i64,
                      17596481012224i64);
                  v8 = 0i64;
                  v67.Bonus.pWeakProxy = 0i64;
                  v67.value = 0ui64;
                  v7 &= 0xFFFFFDE0;
                  v67.Flags = v7;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v67);
                  v8 = v67.Bonus.pWeakProxy;
                  v7 = v67.Flags;
                }
              }
              v7 = v7 & 0xFFFFFFEC | 0xC;
              v67.Flags = v7;
              v12 = 0.0;
              v67.value.VNumber = 0.0;
              v11.VObj = (Scaleform::GFx::AS3::Object *)v71.VS._2;
              v67.value.VS._2.VObj = v71.VS._2.VObj;
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v5->Data.Data,
                v5,
                v5->Data.Size + 1);
              v27 = 32 * v5->Data.Size;
              v28 = (signed __int64)&v5->Data.Data[-1];
              v17 = v27 + v28 == 0;
              v29 = v27 + v28;
              v69 = v29;
              v68 = (char *)v29;
              if ( !v17 )
              {
                *(_DWORD *)v29 = v7;
                *(_QWORD *)(v29 + 8) = v8;
                *(_QWORD *)(v29 + 16) = 0i64;
                *(Scaleform::GFx::AS3::Value::V2U *)(v29 + 24) = v11;
                v30 = v7 & 0x1F;
                if ( v30 > 9 )
                {
                  if ( (v7 >> 9) & 1 )
                  {
                    ++v8->RefCount;
                  }
                  else if ( v30 == 10 )
                  {
                    ++MEMORY[0x18];
                  }
                  else if ( v30 > 10 && v30 > 15 && v30 <= 17 && v11.VObj )
                  {
                    v11.VObj->RefCount = (v11.VObj->RefCount + 1) & 0x8FBFFFFF;
                  }
                }
              }
              goto LABEL_175;
            case 98:
              args += 8;
              Scaleform::GFx::AS3::Value::SetBool(&v67, *((_DWORD *)args - 2) != 0);
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v5->Data.Data,
                v5,
                v5->Data.Size + 1);
              v31 = 32 * v5->Data.Size;
              v32 = (signed __int64)&v5->Data.Data[-1];
              v17 = v31 + v32 == 0;
              v33 = v31 + v32;
              v69 = v33;
              v68 = (char *)v33;
              v11.VObj = (Scaleform::GFx::AS3::Object *)v67.value.VS._2;
              v12 = v67.value.VNumber;
              v8 = v67.Bonus.pWeakProxy;
              v7 = v67.Flags;
              if ( !v17 )
              {
                *(_DWORD *)v33 = v67.Flags;
                *(_QWORD *)(v33 + 8) = v8;
                *(long double *)(v33 + 16) = v12;
                *(Scaleform::GFx::AS3::Value::V2U *)(v33 + 24) = v11;
                v34 = v7 & 0x1F;
                if ( v34 > 9 )
                {
                  if ( (v7 >> 9) & 1 )
                  {
                    ++v8->RefCount;
                  }
                  else if ( v34 == 10 )
                  {
                    ++*(_DWORD *)(*(_QWORD *)&v12 + 24i64);
                  }
                  else if ( v34 > 10 )
                  {
                    if ( v34 <= 15 )
                    {
                      if ( v12 != 0.0 )
                        *(_DWORD *)(*(_QWORD *)&v12 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v12 + 32i64) + 1) & 0x8FBFFFFF;
                    }
                    else if ( v34 <= 17 && v11.VObj )
                    {
                      v11.VObj->RefCount = (v11.VObj->RefCount + 1) & 0x8FBFFFFF;
                    }
                  }
                }
              }
              goto LABEL_174;
            case 102:
              args += 8;
              Scaleform::GFx::AS3::Value::SetNumber(&v67, *((long double *)args - 1));
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v5->Data.Data,
                v5,
                v5->Data.Size + 1);
              v35 = 32 * v5->Data.Size;
              v36 = (signed __int64)&v5->Data.Data[-1];
              v17 = v35 + v36 == 0;
              v37 = v35 + v36;
              v69 = v37;
              v68 = (char *)v37;
              v11.VObj = (Scaleform::GFx::AS3::Object *)v67.value.VS._2;
              v12 = v67.value.VNumber;
              v8 = v67.Bonus.pWeakProxy;
              v7 = v67.Flags;
              if ( !v17 )
              {
                *(_DWORD *)v37 = v67.Flags;
                *(_QWORD *)(v37 + 8) = v8;
                *(long double *)(v37 + 16) = v12;
                *(Scaleform::GFx::AS3::Value::V2U *)(v37 + 24) = v11;
                v38 = v7 & 0x1F;
                if ( v38 > 9 )
                {
                  if ( (v7 >> 9) & 1 )
                  {
                    ++v8->RefCount;
                  }
                  else if ( v38 == 10 )
                  {
                    ++*(_DWORD *)(*(_QWORD *)&v12 + 24i64);
                  }
                  else if ( v38 > 10 )
                  {
                    if ( v38 <= 15 )
                    {
                      if ( v12 != 0.0 )
                        *(_DWORD *)(*(_QWORD *)&v12 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v12 + 32i64) + 1) & 0x8FBFFFFF;
                    }
                    else if ( v38 <= 17 && v11.VObj )
                    {
                      v11.VObj->RefCount = (v11.VObj->RefCount + 1) & 0x8FBFFFFF;
                    }
                  }
                }
              }
              goto LABEL_174;
            case 104:
              v39 = *v10++;
              if ( v39 == 102 )
              {
                v14 += 8;
                args = v14;
                Scaleform::GFx::AS3::Value::SetNumber(&v67, *((long double *)v14 - 1));
                Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                  (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v5->Data.Data,
                  v5,
                  v5->Data.Size + 1);
                v40 = 32 * v5->Data.Size;
                v41 = (signed __int64)&v5->Data.Data[-1];
                v17 = v40 + v41 == 0;
                v42 = v40 + v41;
                v69 = v42;
                v68 = (char *)v42;
                v11.VObj = (Scaleform::GFx::AS3::Object *)v67.value.VS._2;
                v12 = v67.value.VNumber;
                v8 = v67.Bonus.pWeakProxy;
                v7 = v67.Flags;
                if ( !v17 )
                {
                  *(_DWORD *)v42 = v67.Flags;
                  *(_QWORD *)(v42 + 8) = v8;
                  *(long double *)(v42 + 16) = v12;
                  *(Scaleform::GFx::AS3::Value::V2U *)(v42 + 24) = v11;
                  v43 = v7 & 0x1F;
                  if ( v43 > 9 )
                  {
                    if ( (v7 >> 9) & 1 )
                    {
                      ++v8->RefCount;
                    }
                    else if ( v43 == 10 )
                    {
                      ++*(_DWORD *)(*(_QWORD *)&v12 + 24i64);
                    }
                    else if ( v43 > 10 )
                    {
                      if ( v43 <= 15 )
                      {
                        if ( v12 != 0.0 )
                          *(_DWORD *)(*(_QWORD *)&v12 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v12 + 32i64) + 1) & 0x8FBFFFFF;
                      }
                      else if ( v43 <= 17 && v11.VObj )
                      {
                        v11.VObj->RefCount = (v11.VObj->RefCount + 1) & 0x8FBFFFFF;
                      }
                    }
                  }
                }
                goto LABEL_175;
              }
              if ( v70 )
              {
                LODWORD(v66[0]) = v39;
                Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
                  (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v70->vfptr,
                  "ParseArguments(%s,%s) - invalid format %%h%c",
                  v81,
                  v6,
                  v66[0]);
                goto LABEL_175;
              }
              break;
            case 115:
              args += 8;
              v44 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                     (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v79->BuiltinsMgr.Builtins,
                                     &v75,
                                     *((const char **)args - 1));
              v45 = 10;
              v73.Flags = 10;
              v73.Bonus.pWeakProxy = 0i64;
              v46 = *v44;
              v73.value.VNumber = v46;
              if ( *(_QWORD *)&v46 == *(_QWORD *)(*(_QWORD *)&v46 + 8i64) + 104i64 )
              {
                v46 = 0.0;
                v73.value.VNumber = 0.0;
                v47.VObj = (Scaleform::GFx::AS3::Object *)v71.VS._2;
                v73.value.VS._2.VObj = v71.VS._2.VObj;
                v45 = 12;
                v73.Flags = 12;
              }
              else
              {
                ++*(_DWORD *)(*(_QWORD *)&v46 + 24i64);
                v47.VObj = (Scaleform::GFx::AS3::Object *)v73.value.VS._2;
              }
              Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v80->Data.Data,
                v80,
                v80->Data.Size + 1);
              v48 = 32 * v80->Data.Size;
              v49 = (signed __int64)&v80->Data.Data[-1];
              v17 = v48 + v49 == 0;
              v50 = v48 + v49;
              v69 = v50;
              v77 = v50;
              if ( !v17 )
              {
                *(_DWORD *)v50 = v45;
                *(_QWORD *)(v50 + 8) = 0i64;
                *(long double *)(v50 + 16) = v46;
                *(Scaleform::GFx::AS3::Value::V2U *)(v50 + 24) = v47;
                v51 = v45 & 0x1F;
                if ( v51 > 9 )
                {
                  if ( (v45 >> 9) & 1 )
                  {
                    LODWORD(MEMORY[0]) = MEMORY[0] + 1;
                  }
                  else if ( v51 == 10 )
                  {
                    ++*(_DWORD *)(*(_QWORD *)&v46 + 24i64);
                  }
                  else if ( v51 > 10 )
                  {
                    if ( v51 <= 15 )
                    {
                      if ( v46 != 0.0 )
                        *(_DWORD *)(*(_QWORD *)&v46 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v46 + 32i64) + 1) & 0x8FBFFFFF;
                    }
                    else if ( v51 <= 17 && v47.VObj )
                    {
                      v47.VObj->RefCount = (v47.VObj->RefCount + 1) & 0x8FBFFFFF;
                    }
                  }
                }
              }
              if ( (char)(v45 & 0x1F) > 9 )
              {
                if ( (v45 >> 9) & 1 )
                {
                  LODWORD(MEMORY[0]) = MEMORY[0] - 1;
                  if ( !(_DWORD)MEMORY[0] )
                    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
                  v73.Bonus.pWeakProxy = 0i64;
                  v73.value = 0ui64;
                  v73.Flags = v45 & 0xFFFFFDE0;
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v73);
                }
              }
              v52 = v75.pNode;
              goto LABEL_171;
            case 108:
              v53 = *v10++;
              v68 = v10;
              if ( v53 == 115 )
              {
                args += 8;
                v54 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                       (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v79->BuiltinsMgr.Builtins,
                                       &v76,
                                       *((const wchar_t **)args - 1),
                                       -1i64);
                v55 = 10;
                v72.Flags = 10;
                v72.Bonus.pWeakProxy = 0i64;
                v56 = *v54;
                v72.value.VNumber = v56;
                if ( *(_QWORD *)&v56 == *(_QWORD *)(*(_QWORD *)&v56 + 8i64) + 104i64 )
                {
                  v56 = 0.0;
                  v72.value.VNumber = 0.0;
                  v57.VObj = (Scaleform::GFx::AS3::Object *)v71.VS._2;
                  v72.value.VS._2.VObj = v71.VS._2.VObj;
                  v55 = 12;
                  v72.Flags = 12;
                }
                else
                {
                  ++*(_DWORD *)(*(_QWORD *)&v56 + 24i64);
                  v57.VObj = (Scaleform::GFx::AS3::Object *)v72.value.VS._2;
                }
                Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                  (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v80->Data.Data,
                  v80,
                  v80->Data.Size + 1);
                v58 = 32 * v80->Data.Size;
                v59 = (signed __int64)&v80->Data.Data[-1];
                v17 = v58 + v59 == 0;
                v60 = v58 + v59;
                v77 = v60;
                v69 = v60;
                if ( !v17 )
                {
                  *(_DWORD *)v60 = v55;
                  *(_QWORD *)(v60 + 8) = 0i64;
                  *(long double *)(v60 + 16) = v56;
                  *(Scaleform::GFx::AS3::Value::V2U *)(v60 + 24) = v57;
                  v61 = v55 & 0x1F;
                  if ( v61 > 9 )
                  {
                    if ( (v55 >> 9) & 1 )
                    {
                      LODWORD(MEMORY[0]) = MEMORY[0] + 1;
                    }
                    else if ( v61 == 10 )
                    {
                      ++*(_DWORD *)(*(_QWORD *)&v56 + 24i64);
                    }
                    else if ( v61 > 10 )
                    {
                      if ( v61 <= 15 )
                      {
                        if ( v56 != 0.0 )
                          *(_DWORD *)(*(_QWORD *)&v56 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v56 + 32i64) + 1) & 0x8FBFFFFF;
                      }
                      else if ( v61 <= 17 && v57.VObj )
                      {
                        v57.VObj->RefCount = (v57.VObj->RefCount + 1) & 0x8FBFFFFF;
                      }
                    }
                  }
                }
                if ( (char)(v55 & 0x1F) > 9 )
                {
                  if ( (v55 >> 9) & 1 )
                  {
                    LODWORD(MEMORY[0]) = MEMORY[0] - 1;
                    if ( !(_DWORD)MEMORY[0] )
                      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
                    v72.Bonus.pWeakProxy = 0i64;
                    v72.value = 0ui64;
                    v72.Flags = v55 & 0xFFFFFDE0;
                  }
                  else
                  {
                    Scaleform::GFx::AS3::Value::ReleaseInternal(&v72);
                  }
                }
                v52 = v76.pNode;
LABEL_171:
                v17 = v52->RefCount-- == 1;
                if ( v17 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v52);
                v5 = v80;
                v10 = v68;
LABEL_174:
                v14 = args;
LABEL_175:
                v13 = 17596481012224i64;
                v6 = v82;
                break;
              }
              if ( v70 )
              {
                LODWORD(v66[0]) = v53;
                Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
                  (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v70->vfptr,
                  "ParseArguments(%s,%s) - invalid format %%l%c",
                  v81,
                  v6,
                  v66[0]);
                goto LABEL_175;
              }
              break;
            default:
              if ( v70 )
              {
                LODWORD(v66[0]) = v15;
                Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
                  (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v70->vfptr,
                  "ParseArguments(%s,%s) - invalid format %%%c",
                  v81,
                  v6,
                  v66[0]);
                goto LABEL_175;
              }
              break;
          }
        }
        else if ( v70 )
        {
          LODWORD(v66[0]) = v9;
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
            (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v70->vfptr,
            "ParseArguments(%s,%s) - invalid char %c",
            v81,
            v6,
            v66[0]);
          goto LABEL_175;
        }
        for ( i = *v10; *v10; i = *++v10 )
        {
          if ( i > 0x2Cu )
            break;
          if ( !_bittest64(&v13, (char)i) )
            break;
        }
        v9 = *v10++;
      }
      while ( v9 );
    }
    if ( (signed int)(v7 & 0x1F) > 9 )
    {
      if ( (v7 >> 9) & 1 )
      {
        v17 = v8->RefCount-- == 1;
        if ( v17 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
        v67.Bonus.pWeakProxy = 0i64;
        v67.value = 0ui64;
        v67.Flags = v7 & 0xFFFFFDE0;
      }
      else
      {
        switch ( 0x40000000 )
        {
          case 0:
            v17 = (*(_DWORD *)(*(_QWORD *)&v12 + 24i64))-- == 1;
            if ( v17 )
              Scaleform::GFx::ASStringNode::ReleaseNode(*(Scaleform::GFx::ASStringNode **)&v12);
            break;
          case 1:
          case 2:
          case 3:
          case 4:
          case 5:
            if ( v67.value.VS._1.VBool )
            {
              *(_QWORD *)&v67.value.VNumber = *(_QWORD *)&v12 - 1i64;
            }
            else if ( v12 != 0.0 )
            {
              v63 = *(_DWORD *)(*(_QWORD *)&v12 + 32i64);
              if ( v63 & 0x3FFFFF )
              {
                *(_DWORD *)(*(_QWORD *)&v12 + 32i64) = v63 - 1;
                v64 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v12;
                goto LABEL_199;
              }
            }
            break;
          case 6:
          case 7:
            if ( (_QWORD)v67.value.VS._2.VObj & 1 )
            {
              v67.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)v11.VObj - 1);
            }
            else if ( v11.VObj )
            {
              v65 = v11.VObj->RefCount;
              if ( v65 & 0x3FFFFF )
              {
                v11.VObj->RefCount = v65 - 1;
                v64 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v11.VObj->vfptr;
LABEL_199:
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v64);
              }
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
bool __fastcall Scaleform::GFx::AS3::MovieRoot::InvokeArgs(Scaleform::GFx::AS3::MovieRoot *this, const char *pmethodName, Scaleform::GFx::Value *presult, const char *pargFmt)
{
  Scaleform::GFx::Value *v4; // r12
  const char *v5; // rsi
  Scaleform::GFx::AS3::MovieRoot *v6; // rdi
  unsigned int v7; // er15
  Scaleform::GFx::AS3::Value *v8; // r14
  Scaleform::GFx::AS3::Value *v9; // rbx
  unsigned int v10; // ebx
  bool v11; // zf
  Scaleform::GFx::AS3::ASVM *v12; // rax
  bool v13; // bl
  unsigned int v15; // ebx
  Scaleform::Array<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> arr; // [rsp+20h] [rbp-29h]
  Scaleform::GFx::AS3::Value result; // [rsp+38h] [rbp-11h]
  Scaleform::GFx::AS3::Value pval; // [rsp+58h] [rbp+Fh]
  void *v19; // [rsp+A8h] [rbp+5Fh]
  char *retaddr; // [rsp+C8h] [rbp+7Fh]

  v4 = presult;
  v5 = pmethodName;
  v6 = this;
  v19 = &result.value;
  *(_OWORD *)&arr.Data.Size = 0ui64;
  Scaleform::GFx::AS3::MovieRoot::ParseValueArguments(this, &arr, pmethodName, pargFmt, retaddr);
  v7 = arr.Data.Size;
  v8 = 0i64;
  if ( LODWORD(arr.Data.Size) )
    v8 = arr.Data.Data;
  result.Flags = 0;
  result.Bonus.pWeakProxy = 0i64;
  if ( v6->pInvokeAliases )
  {
    v9 = Scaleform::GFx::AS3::MovieRoot::ResolveInvokeAlias(v6, v5);
    if ( v9 )
    {
      if ( !(_S11_12 & 1) )
      {
        _S11_12 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
        (Scaleform::GFx::AS3::VM *)&v6->pAVM.pObject->vfptr,
        v9,
        &v,
        &result,
        v7,
        v8,
        0);
LABEL_17:
      v12 = v6->pAVM.pObject;
      v13 = v12->HandleException == 0;
      if ( v12->HandleException )
        v12->HandleException = 0;
      if ( v13 && v4 )
        Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v6, &result, v4);
      if ( (result.Flags & 0x1F) > 9 )
      {
        if ( (result.Flags >> 9) & 1 )
        {
          v11 = result.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v11 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          result.Bonus.pWeakProxy = 0i64;
          result.value = 0ui64;
          result.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
        }
      }
      v19 = &arr;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(arr.Data.Data, arr.Data.Size);
      if ( arr.Data.Data )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      return v13;
    }
  }
  pval.Flags = 0;
  pval.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(v6, &pval, v5) )
  {
    if ( !(_S11_12 & 1) )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
      (Scaleform::GFx::AS3::VM *)&v6->pAVM.pObject->vfptr,
      &pval,
      &v,
      &result,
      v7,
      v8,
      0);
    v10 = pval.Flags;
    if ( (pval.Flags & 0x1F) > 9 )
    {
      if ( (pval.Flags >> 9) & 1 )
      {
        v11 = pval.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v11 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        pval.Bonus.pWeakProxy = 0i64;
        pval.value = 0ui64;
        pval.Flags = v10 & 0xFFFFFDE0;
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
    if ( (pval.Flags >> 9) & 1 )
    {
      v11 = pval.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      pval.Bonus.pWeakProxy = 0i64;
      pval.value = 0ui64;
      pval.Flags = v15 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pval);
    }
  }
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v11 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      result.Bonus.pWeakProxy = 0i64;
      result.value = 0ui64;
      result.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
  }
  v19 = &arr;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(arr.Data.Data, arr.Data.Size);
  if ( arr.Data.Data )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  return 0;
}

// File Line: 2491
// RVA: 0x7895E0
void __fastcall Scaleform::GFx::AS3::MovieRoot::ActionQueueType::~ActionQueueType(Scaleform::GFx::AS3::MovieRoot::ActionQueueType *this)
{
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *v1; // rbx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v2; // rbx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v3; // rdi

  v1 = this;
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType::Clear(this);
  v2 = v1->pFreeEntry;
  if ( v2 )
  {
    do
    {
      v3 = v2->pNextEntry;
      Scaleform::GFx::AS3::MovieRoot::ActionEntry::~ActionEntry(v2);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
      v2 = v3;
    }
    while ( v3 );
  }
}

// File Line: 2504
// RVA: 0x7EC840
Scaleform::GFx::AS3::MovieRoot::ActionEntry *__fastcall Scaleform::GFx::AS3::MovieRoot::ActionQueueType::GetNewEntry(Scaleform::GFx::AS3::MovieRoot::ActionQueueType *this)
{
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v1; // rbx
  __int64 v2; // rax
  Scaleform::RefCountNTSImpl *v3; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // rcx
  unsigned int v5; // eax
  Scaleform::GFx::AS3::WeakProxy *v6; // rdx
  bool v7; // zf
  Scaleform::Render::RenderBuffer *v8; // rcx

  v1 = this->pFreeEntry;
  if ( v1 )
  {
    this->pFreeEntry = v1->pNextEntry;
    v1->pNextEntry = 0i64;
    --this->FreeEntriesCount;
  }
  else
  {
    v2 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::MovieRoot::ActionQueueType *, signed __int64))this->pHeap->vfptr->Alloc)(
           this,
           104i64);
    v1 = (Scaleform::GFx::AS3::MovieRoot::ActionEntry *)v2;
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
      v1->pCharacter.pObject = 0i64;
      v4 = v1->pAS3Obj.pObject;
      if ( v4 )
      {
        if ( (unsigned __int8)v4 & 1 )
        {
          v1->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v4 - 1);
        }
        else
        {
          v5 = v4->RefCount;
          if ( v5 & 0x3FFFFF )
          {
            v4->RefCount = v5 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
          }
        }
        v1->pAS3Obj.pObject = 0i64;
      }
      v1->CFunction = 0i64;
      if ( (v1->Function.Flags & 0x1F) > 9 )
      {
        if ( (v1->Function.Flags >> 9) & 1 )
        {
          v6 = v1->Function.Bonus.pWeakProxy;
          v7 = v6->RefCount-- == 1;
          if ( v7 )
            ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          v1->Function.Bonus.pWeakProxy = 0i64;
          v1->Function.value.VNumber = 0.0;
          v1->Function.value.VS._2.VObj = 0i64;
          v1->Function.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v1->Function);
        }
      }
      v1->Function.Flags &= 0xFFFFFFE0;
      v8 = (Scaleform::Render::RenderBuffer *)v1->pNLoadInitCL.pObject;
      if ( v8 )
        Scaleform::RefCountImpl::Release(v8);
      v1->pNLoadInitCL.pObject = 0i64;
    }
    else
    {
      v1 = 0i64;
    }
    if ( !v1 )
      return 0i64;
  }
  return v1;
}

// File Line: 2582
// RVA: 0x7AF840
void __fastcall Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(Scaleform::GFx::AS3::MovieRoot::ActionQueueType *this, Scaleform::GFx::AS3::MovieRoot::ActionEntry *pentry)
{
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *v2; // rsi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v3; // rbx
  Scaleform::GFx::DisplayObject *v4; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v5; // rcx
  unsigned int v6; // eax
  Scaleform::GFx::AS3::WeakProxy *v7; // rdx
  bool v8; // zf
  Scaleform::Render::RenderBuffer *v9; // rcx

  v2 = this;
  v3 = pentry;
  pentry->Type = 0;
  v4 = pentry->pCharacter.pObject;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
  v3->pCharacter.pObject = 0i64;
  v5 = v3->pAS3Obj.pObject;
  if ( v5 )
  {
    if ( (unsigned __int8)v5 & 1 )
    {
      v3->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v5 - 1);
    }
    else
    {
      v6 = v5->RefCount;
      if ( v6 & 0x3FFFFF )
      {
        v5->RefCount = v6 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
      }
    }
    v3->pAS3Obj.pObject = 0i64;
  }
  v3->CFunction = 0i64;
  if ( (v3->Function.Flags & 0x1F) > 9 )
  {
    if ( (v3->Function.Flags >> 9) & 1 )
    {
      v7 = v3->Function.Bonus.pWeakProxy;
      v8 = v7->RefCount-- == 1;
      if ( v8 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v3->Function.Flags &= 0xFFFFFDE0;
      v3->Function.Bonus.pWeakProxy = 0i64;
      v3->Function.value.VNumber = 0.0;
      v3->Function.value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v3->Function);
    }
  }
  v3->Function.Flags &= 0xFFFFFFE0;
  v9 = (Scaleform::Render::RenderBuffer *)v3->pNLoadInitCL.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v3->pNLoadInitCL.pObject = 0i64;
  if ( v2->FreeEntriesCount >= 0x32 )
  {
    Scaleform::GFx::AS3::MovieRoot::ActionEntry::~ActionEntry(v3);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
  else
  {
    v3->pNextEntry = v2->pFreeEntry;
    ++v2->FreeEntriesCount;
    v2->pFreeEntry = v3;
  }
}

// File Line: 2595
// RVA: 0x7B45F0
void __fastcall Scaleform::GFx::AS3::MovieRoot::ActionQueueType::Clear(Scaleform::GFx::AS3::MovieRoot::ActionQueueType *this)
{
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *v1; // rdi
  Scaleform::GFx::AS3::MovieRoot::ActionLevel v2; // ebx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator v3; // [rsp+28h] [rbp-40h]

  v1 = this;
  v2 = 0;
  do
  {
    v3.pActionQueue = v1;
    v3.Level = v2;
    v3.ModId = 0;
    v3.pLastEntry = 0i64;
    v3.pRootEntry = 0i64;
    v3.pCurEntry = v1->Entries[v2].pActionRoot;
    while ( Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&v3) )
      ;
    if ( v3.pLastEntry )
      Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(v3.pActionQueue, v3.pLastEntry);
    ++v2;
  }
  while ( (unsigned int)v2 < 7 );
}

// File Line: 2617
// RVA: 0x7895C0
void __fastcall Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::~ActionQueueIterator(Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator *this)
{
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v1; // rdx

  v1 = this->pLastEntry;
  if ( v1 )
    Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(this->pActionQueue, v1);
}

// File Line: 2623
// RVA: 0x84BC10
Scaleform::GFx::AS3::MovieRoot::ActionEntry *__fastcall Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator *this)
{
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *v1; // rdx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator *v2; // rbx
  int v3; // eax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v4; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v5; // rcx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v6; // rdi
  signed __int64 v7; // rax
  signed __int64 v8; // rcx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v9; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionQueueEntry *v10; // rdx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v11; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v12; // rcx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *v13; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v14; // rax

  v1 = this->pActionQueue;
  v2 = this;
  v3 = v1->ModId;
  if ( v3 != this->ModId )
  {
    this->ModId = v3;
    v4 = this->pRootEntry;
    if ( v4 )
      v5 = v4->pNextEntry;
    else
      v5 = v1->Entries[this->Level].pActionRoot;
    v2->pCurEntry = v5;
  }
  v6 = v2->pCurEntry;
  if ( v6 )
  {
    v7 = v2->Level;
    v8 = v7;
    if ( v6 == v1->Entries[v7].pInsertEntry )
    {
      v9 = v6->pNextEntry;
      if ( !v6->pNextEntry )
        v9 = v2->pRootEntry;
      v1->Entries[v8].pInsertEntry = v9;
    }
    v10 = &v2->pActionQueue->Entries[v2->Level];
    v11 = v2->pCurEntry;
    if ( v11 == v10->pActionRoot )
    {
      v10->pActionRoot = v11->pNextEntry;
    }
    else
    {
      v12 = v2->pRootEntry;
      if ( v12 )
        v12->pNextEntry = v11->pNextEntry;
    }
    v2->pCurEntry = v2->pCurEntry->pNextEntry;
  }
  v13 = v2->pActionQueue;
  if ( !v13->Entries[v2->Level].pActionRoot )
  {
    v13->Entries[v2->Level].pInsertEntry = 0i64;
    v2->pActionQueue->Entries[v2->Level].pLastEntry = 0i64;
  }
  v14 = v2->pLastEntry;
  if ( v14 )
  {
    v14->pNextEntry = 0i64;
    Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(v2->pActionQueue, v2->pLastEntry);
    v2->ModId = ++v2->pActionQueue->ModId;
  }
  v2->pLastEntry = v6;
  return v6;
}

// File Line: 2686
// RVA: 0x7C9E30
void __fastcall Scaleform::GFx::AS3::MovieRoot::ActionEntry::Execute(Scaleform::GFx::AS3::MovieRoot::ActionEntry *this, Scaleform::GFx::AS3::MovieRoot *proot)
{
  Scaleform::GFx::AS3::MovieRoot *v2; // rsi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v3; // rdi
  Scaleform::GFx::DisplayObject *v4; // r8
  __int32 v5; // ecx
  int v6; // ecx
  void (__fastcall *v7)(Scaleform::GFx::AS3::MovieRoot::ActionEntry *); // rax
  signed __int64 v8; // rcx
  long double v9; // rax
  Scaleform::GFx::AS3::VM *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::AvmDisplayObj *v12; // rbx
  __int64 v13; // [rsp+38h] [rbp+7h]
  Scaleform::GFx::AS3::Value _this; // [rsp+40h] [rbp+Fh]
  Scaleform::GFx::AS3::Value result; // [rsp+60h] [rbp+2Fh]

  v13 = -2i64;
  v2 = proot;
  v3 = this;
  v4 = this->pCharacter.pObject;
  if ( v4 && !((LOBYTE(v4->Flags) >> 4) & 1) )
  {
    v5 = this->Type - 1;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( v6 )
      {
        if ( v6 == 1 )
        {
          v7 = v3->CFunction;
          if ( v7 )
            v7(v3);
        }
      }
      else
      {
        if ( v4 )
          v8 = (signed __int64)v4 + 4 * (unsigned __int8)v4->AvmObjOffset;
        else
          v8 = 0i64;
        v9 = *(double *)(v8 + 16);
        if ( v9 == 0.0 )
          v9 = *(double *)(v8 + 8);
        if ( LOBYTE(v9) & 1 )
          --*(_QWORD *)&v9;
        _this.Flags = 12;
        _this.Bonus.pWeakProxy = 0i64;
        _this.value.VNumber = v9;
        if ( v9 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v9 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v9 + 32i64) + 1) & 0x8FBFFFFF;
        result.Flags = 0;
        result.Bonus.pWeakProxy = 0i64;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
          (Scaleform::GFx::AS3::VM *)&proot->pAVM.pObject->vfptr,
          &v3->Function,
          &_this,
          &result,
          0,
          0i64,
          0);
        v10 = (Scaleform::GFx::AS3::VM *)&v2->pAVM.pObject->vfptr;
        if ( v10->HandleException )
        {
          Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v10);
          v3->pCharacter.pObject->Flags |= 0x20u;
        }
        if ( (result.Flags & 0x1F) > 9 )
        {
          if ( (result.Flags >> 9) & 1 )
          {
            v11 = result.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            result.Bonus.pWeakProxy = 0i64;
            result.value = 0ui64;
            result.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
          }
        }
        if ( (_this.Flags & 0x1F) > 9 )
        {
          if ( (_this.Flags >> 9) & 1 )
          {
            v11 = _this.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            _this.Bonus.pWeakProxy = 0i64;
            _this.value = 0ui64;
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
      if ( v4 )
        v12 = (Scaleform::GFx::AS3::AvmDisplayObj *)((char *)v4 + 4 * (unsigned __int8)v4->AvmObjOffset);
      else
        v12 = 0i64;
      Scaleform::GFx::AS3::AvmDisplayObj::FireEvent(v12, &v3->mEventId);
    }
  }
}

// File Line: 2727
// RVA: 0x7ADC30
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddInvokeAlias(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::ASString *alias, Scaleform::GFx::AS3::Value *closure)
{
  Scaleform::GFx::AS3::Value *v3; // rdi
  Scaleform::GFx::ASString *v4; // rsi
  Scaleform::GFx::AS3::MovieRoot *v5; // rbx
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS3::Value> *v6; // rax

  v3 = closure;
  v4 = alias;
  v5 = this;
  if ( !this->pInvokeAliases )
  {
    v6 = (Scaleform::GFx::ASStringHash<Scaleform::GFx::AS3::Value> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                                       Scaleform::Memory::pGlobalHeap,
                                                                       8i64);
    if ( v6 )
      v6->mHash.pTable = 0i64;
    v5->pInvokeAliases = v6;
  }
  Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Set(
    (Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,)&v5->pInvokeAliases->mHash,
    v4,
    v3);
}

// File Line: 2734
// RVA: 0x8159D0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::MovieRoot::ResolveInvokeAlias(Scaleform::GFx::AS3::MovieRoot *this, const char *pstr)
{
  Scaleform::GFx::AS3::MovieRoot *v2; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v3; // r10
  unsigned __int64 v4; // rbx
  __int64 v5; // r11
  signed __int64 v6; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v7; // r9
  Scaleform::GFx::ASStringNode *v8; // rdx
  signed __int64 v9; // rbx
  signed __int64 v10; // rbx
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v2 = this;
  if ( !this->pInvokeAliases )
    return 0i64;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->BuiltinsMgr.Builtins,
    &result,
    pstr);
  v3 = v2->pInvokeAliases->mHash.pTable;
  if ( !v3 )
    goto LABEL_12;
  v4 = v3->SizeMask;
  v5 = (unsigned int)v4 & result.pNode->HashFlags;
  v6 = v5;
  v7 = &v3[3 * v5 + 1];
  if ( v7->EntryCount == -2i64 || ((unsigned int)v4 & *(_DWORD *)(v7->SizeMask + 28)) != v5 )
    goto LABEL_12;
  while ( 1 )
  {
    v8 = (Scaleform::GFx::ASStringNode *)v7->SizeMask;
    if ( ((unsigned int)v4 & v8->HashFlags) == v5 && v8 == result.pNode )
      break;
    v6 = v7->EntryCount;
    if ( v7->EntryCount == -1i64 )
      goto LABEL_12;
    v7 = &v3[3 * v6 + 1];
  }
  if ( v6 >= 0 && (v9 = (signed __int64)&v3[3 * v6 + 1].SizeMask) != 0 )
    v10 = v9 + 8;
  else
LABEL_12:
    v10 = 0i64;
  v11 = result.pNode;
  v12 = result.pNode->RefCount == 1;
  --v11->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  return (Scaleform::GFx::AS3::Value *)v10;
}

// File Line: 2745
// RVA: 0x7AE4B0
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddScriptableMovieClip(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::DisplayObjContainer *pspr)
{
  Scaleform::GFx::DisplayObjContainer *v2; // rbx
  __int64 v3; // rdx
  int v4; // eax

  v2 = pspr;
  if ( !pspr->pParent )
  {
    Scaleform::GFx::InteractiveObject::AddToPlayList((Scaleform::GFx::InteractiveObject *)&pspr->vfptr);
    if ( !((v2->Flags >> 21) & 1) || (v2->Flags >> 22) & 1 )
      v3 = 0i64;
    else
      LOBYTE(v3) = 1;
    v4 = (__int64)v2->vfptr[103].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, v3);
    if ( v4 == -1 )
    {
      v2->Flags |= 0x400000u;
    }
    else if ( v4 == 1 )
    {
      Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList((Scaleform::GFx::InteractiveObject *)&v2->vfptr);
    }
  }
}

// File Line: 2787
// RVA: 0x7D1F40
signed __int64 __fastcall Scaleform::GFx::AS3::MovieRoot::FindExtensionContexts(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::ASString *extensionID, Scaleform::GFx::ASString *contextType)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *,2,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  Scaleform::GFx::ASString *v4; // r14
  Scaleform::GFx::ASString *v5; // rbp
  Scaleform::GFx::AS3::MovieRoot *v6; // rsi
  signed __int64 v7; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *,2,Scaleform::ArrayDefaultPolicy> *v8; // rbx
  Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext **v9; // rax
  Scaleform::GFx::AS3::Instances::fl_external::ExtensionContext *v10; // rcx
  unsigned __int64 v11; // r8
  Scaleform::GFx::ASStringNode *v12; // rcx

  v3 = this->ExtensionContextArray.pObject;
  v4 = contextType;
  v5 = extensionID;
  v6 = this;
  if ( !v3 )
    return -1i64;
  v7 = v3->Data.Size - 1;
  if ( v7 < 0 )
    return -1i64;
  while ( 1 )
  {
    v8 = v6->ExtensionContextArray.pObject;
    v9 = v8->Data.Data;
    v10 = v8->Data.Data[v7];
    if ( !v10 )
    {
      v11 = v8->Data.Size;
      if ( v11 == 1 )
      {
        if ( v8->Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
        {
          if ( v9 )
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
        memmove(&v9[v7], &v9[v7 + 1], 8 * (v11 - v7) - 8);
        --v8->Data.Size;
      }
      goto LABEL_15;
    }
    if ( v5->pNode == v10->ExtensionID.pNode )
    {
      v12 = v10->ContextID.pNode;
      if ( v4->pNode == v12 || !v4->pNode->Size && v12 == &v12->pManager->NullStringNode )
        return v7;
    }
LABEL_15:
    if ( --v7 < 0 )
      return -1i64;
  }
}

// File Line: 2811
// RVA: 0x8028D0
void __fastcall Scaleform::GFx::AS3::MovieRoot::NotifyStatusEvent(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::EventId *v2; // rsi
  Scaleform::GFx::AS3::MovieRoot *v3; // r14
  Scaleform::String *v4; // r8
  signed __int64 v5; // rax
  _QWORD *v6; // rdi
  _QWORD *v7; // rdi
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  _QWORD *v11; // rdi
  _QWORD *v12; // rdi
  Scaleform::GFx::ASString contextType; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+18h]

  v2 = id;
  v3 = this;
  v4 = *(Scaleform::String **)&id[2].Id;
  if ( v4 )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->BuiltinsMgr.Builtins,
      &result,
      v4);
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->BuiltinsMgr.Builtins,
      &contextType,
      *(Scaleform::String **)&v2[2].KeyCode);
    v5 = Scaleform::GFx::AS3::MovieRoot::FindExtensionContexts(v3, &result, &contextType);
    if ( v5 != -1 )
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
        (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v3->ExtensionContextArray.pObject->Data.Data[v5]->vfptr,
        v2,
        0i64);
    v6 = *(_QWORD **)&v2[2].Id;
    if ( v6 )
    {
      if ( !_InterlockedDecrement((volatile signed __int32 *)((*v6 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      Illusion::ShaderParam::operator delete(v6);
    }
    v7 = *(_QWORD **)&v2[2].KeyCode;
    if ( v7 )
    {
      if ( !_InterlockedDecrement((volatile signed __int32 *)((*v7 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      Illusion::ShaderParam::operator delete(v7);
    }
    v8 = contextType.pNode;
    v9 = contextType.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    v10 = result.pNode;
    v9 = result.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
  else
  {
    ((void (__cdecl *)(Scaleform::GFx::AS3::MovieRoot *))this->vfptr[61].__vecDelDtor)(this);
  }
  v11 = *(_QWORD **)&v2[1].WcharCode;
  if ( v11 )
  {
    if ( !_InterlockedDecrement((volatile signed __int32 *)((*v11 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    Illusion::ShaderParam::operator delete(v11);
  }
  v12 = *(_QWORD **)&v2[1].AsciiCode;
  if ( v12 )
  {
    if ( !_InterlockedDecrement((volatile signed __int32 *)((*v12 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    Illusion::ShaderParam::operator delete(v12);
  }
}

// File Line: 2839
// RVA: 0x802570
void __fastcall Scaleform::GFx::AS3::MovieRoot::NotifyAccelerometerEvent(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::EventId *id, int evtIdAcc)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *,2,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  int v4; // ebp
  Scaleform::GFx::EventId *v5; // r14
  Scaleform::GFx::AS3::MovieRoot *v6; // rsi
  signed __int64 i; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *,2,Scaleform::ArrayDefaultPolicy> *v8; // rbx
  Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer **v9; // rax
  Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *v10; // rcx
  unsigned __int64 v11; // r8

  v3 = this->AccelerometerArray.pObject;
  v4 = evtIdAcc;
  v5 = id;
  v6 = this;
  if ( v3 )
  {
    for ( i = v3->Data.Size - 1; i >= 0; --i )
    {
      v8 = v6->AccelerometerArray.pObject;
      v9 = v8->Data.Data;
      v10 = v8->Data.Data[i];
      if ( v10 )
      {
        if ( v10->AccelerometerId == v4 )
        {
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
            (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v10->vfptr,
            v5,
            0i64);
          return;
        }
      }
      else
      {
        v11 = v8->Data.Size;
        if ( v11 == 1 )
        {
          if ( v8->Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
          {
            if ( v9 )
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
          memmove(&v9[i], &v9[i + 1], 8 * (v11 - i) - 8);
          --v8->Data.Size;
        }
      }
    }
  }
}

// File Line: 2862
// RVA: 0x7AF530
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddToAccelerometers(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *pAccelerometer)
{
  Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *v2; // rsi
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> > *v3; // rdi
  unsigned __int64 v4; // rbx
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *v5; // rax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v6; // rdi
  unsigned __int64 v7; // rcx
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v8; // rax
  unsigned __int64 v9; // rbx
  unsigned __int64 v10; // r8
  _QWORD *v11; // rcx

  v2 = pAccelerometer;
  v3 = (Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> > *)&this->AccelerometerArray;
  v4 = 0i64;
  if ( !this->AccelerometerArray.pObject )
  {
    v5 = (Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *)this->pMovieImpl->pHeap->vfptr->Alloc((Scaleform::MemoryHeap *)this, 24ui64, 0i64);
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
      v3,
      v5);
  }
  v6 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)v3->pObject;
  if ( !v6 )
    goto LABEL_13;
  v7 = v6->Size;
  if ( !v7 )
    goto LABEL_13;
  v8 = v6->Data;
  while ( (Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *)v8->pObject != v2 )
  {
    ++v4;
    ++v8;
    if ( v4 >= v7 )
      goto LABEL_13;
  }
  if ( v4 == -1i64 )
  {
LABEL_13:
    v9 = v6->Size + 1;
    if ( v9 >= v6->Size )
    {
      if ( v9 <= v6->Policy.Capacity )
        goto LABEL_19;
      v10 = v9 + (v9 >> 2);
    }
    else
    {
      if ( v9 >= v6->Policy.Capacity >> 1 )
        goto LABEL_19;
      v10 = v6->Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v6,
      v6,
      v10);
LABEL_19:
    v6->Size = v9;
    v11 = &v6->Data[v9 - 1].pObject;
    if ( v11 )
      *v11 = v2;
  }
}

// File Line: 2886
// RVA: 0x8118D0
void __fastcall Scaleform::GFx::AS3::MovieRoot::RemoveFromAccelerometers(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *pAccelerometer)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *,2,Scaleform::ArrayDefaultPolicy> *v2; // r9
  unsigned __int64 v3; // r8
  unsigned __int64 v4; // rax
  Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer **v5; // rcx

  v2 = this->AccelerometerArray.pObject;
  if ( v2 )
  {
    v3 = v2->Data.Size;
    v4 = 0i64;
    if ( v3 )
    {
      v5 = v2->Data.Data;
      while ( *v5 != pAccelerometer )
      {
        ++v4;
        ++v5;
        if ( v4 >= v3 )
          return;
      }
      if ( v4 != -1i64 )
        v2->Data.Data[v4] = 0i64;
    }
  }
}

// File Line: 2897
// RVA: 0x802750
void __fastcall Scaleform::GFx::AS3::MovieRoot::NotifyGeolocationEvent(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::EventId *id, int evtIdGeo)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  int v4; // ebp
  Scaleform::GFx::EventId *v5; // r14
  Scaleform::GFx::AS3::MovieRoot *v6; // rsi
  signed __int64 i; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *v8; // rbx
  Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation **v9; // rax
  Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *v10; // rcx
  unsigned __int64 v11; // r8

  v3 = this->GeolocationArray.pObject;
  v4 = evtIdGeo;
  v5 = id;
  v6 = this;
  if ( v3 )
  {
    for ( i = v3->Data.Size - 1; i >= 0; --i )
    {
      v8 = v6->GeolocationArray.pObject;
      v9 = v8->Data.Data;
      v10 = v8->Data.Data[i];
      if ( v10 )
      {
        if ( v10->GeolocationId == v4 )
        {
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
            (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v10->vfptr,
            v5,
            0i64);
          return;
        }
      }
      else
      {
        v11 = v8->Data.Size;
        if ( v11 == 1 )
        {
          if ( v8->Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
          {
            if ( v9 )
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
          memmove(&v9[i], &v9[i + 1], 8 * (v11 - i) - 8);
          --v8->Data.Size;
        }
      }
    }
  }
}

// File Line: 2920
// RVA: 0x7B2240
void __fastcall Scaleform::GFx::AS3::MovieRoot::BroadcastGeolocationStatusEvent(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::EventId *id)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *v2; // rdi
  Scaleform::GFx::EventId *v3; // rbp
  Scaleform::GFx::AS3::MovieRoot *v4; // rsi
  signed __int64 i; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *v6; // rbx
  Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation **v7; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v8; // rcx
  unsigned __int64 v9; // r8

  v2 = this->GeolocationArray.pObject;
  v3 = id;
  v4 = this;
  if ( v2 )
  {
    for ( i = v2->Data.Size - 1; i >= 0; --i )
    {
      v6 = v4->GeolocationArray.pObject;
      v7 = v6->Data.Data;
      v8 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v6->Data.Data[i]->vfptr;
      if ( v8 )
      {
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(v8, v3, 0i64);
      }
      else
      {
        v9 = v6->Data.Size;
        if ( v9 == 1 )
        {
          if ( v6->Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
          {
            if ( v7 )
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
          memmove(&v7[i], &v7[i + 1], 8 * (v9 - i) - 8);
          --v6->Data.Size;
        }
      }
    }
  }
}

// File Line: 2940
// RVA: 0x7AF960
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddToGeolocations(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *pGeolocation)
{
  Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *v2; // rsi
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> > *v3; // rdi
  unsigned __int64 v4; // rbx
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *v5; // rax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v6; // rdi
  unsigned __int64 v7; // rcx
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v8; // rax
  unsigned __int64 v9; // rbx
  unsigned __int64 v10; // r8
  _QWORD *v11; // rcx

  v2 = pGeolocation;
  v3 = &this->GeolocationArray;
  v4 = 0i64;
  if ( !this->GeolocationArray.pObject )
  {
    v5 = (Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *)this->pMovieImpl->pHeap->vfptr->Alloc((Scaleform::MemoryHeap *)this, 24ui64, 0i64);
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
      v3,
      v5);
  }
  v6 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)v3->pObject;
  if ( !v6 )
    goto LABEL_13;
  v7 = v6->Size;
  if ( !v7 )
    goto LABEL_13;
  v8 = v6->Data;
  while ( (Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *)v8->pObject != v2 )
  {
    ++v4;
    ++v8;
    if ( v4 >= v7 )
      goto LABEL_13;
  }
  if ( v4 == -1i64 )
  {
LABEL_13:
    v9 = v6->Size + 1;
    if ( v9 >= v6->Size )
    {
      if ( v9 <= v6->Policy.Capacity )
        goto LABEL_19;
      v10 = v9 + (v9 >> 2);
    }
    else
    {
      if ( v9 >= v6->Policy.Capacity >> 1 )
        goto LABEL_19;
      v10 = v6->Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v6,
      v6,
      v10);
LABEL_19:
    v6->Size = v9;
    v11 = &v6->Data[v9 - 1].pObject;
    if ( v11 )
      *v11 = v2;
  }
}

// File Line: 2964
// RVA: 0x811A20
void __fastcall Scaleform::GFx::AS3::MovieRoot::RemoveFromGeolocations(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *pGeolocation)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *v2; // r9
  unsigned __int64 v3; // r8
  unsigned __int64 v4; // rax
  Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation **v5; // rcx

  v2 = this->GeolocationArray.pObject;
  if ( v2 )
  {
    v3 = v2->Data.Size;
    v4 = 0i64;
    if ( v3 )
    {
      v5 = v2->Data.Data;
      while ( *v5 != pGeolocation )
      {
        ++v4;
        ++v5;
        if ( v4 >= v3 )
          return;
      }
      if ( v4 != -1i64 )
        v2->Data.Data[v4] = 0i64;
    }
  }
}

// File Line: 2974
// RVA: 0x7AF630
void __fastcall Scaleform::GFx::AS3::EventChains::AddToChain(Scaleform::GFx::AS3::EventChains *this, Scaleform::GFx::EventId::IdCode evtId, Scaleform::GFx::DisplayObject *obj)
{
  Scaleform::GFx::DisplayObject *v3; // rbp
  unsigned __int64 v4; // rsi
  Scaleform::GFx::AS3::EventChains *v5; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *v6; // r10
  Scaleform::WeakPtrProxy *v7; // rbx
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // r11
  signed __int64 v10; // r9
  signed __int64 v11; // rcx
  signed __int64 v12; // rdi
  Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> **v13; // rdi
  Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> *v14; // rdi
  Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v15; // rax
  Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v16; // rsi
  Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v17; // rdx
  bool v18; // zf
  Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v19; // [rsp+28h] [rbp-50h]
  char v20; // [rsp+30h] [rbp-48h]
  Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeRef key; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS3::EventChains *v22; // [rsp+80h] [rbp+8h]
  int v23; // [rsp+88h] [rbp+10h]
  Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v24; // [rsp+98h] [rbp+20h]

  v22 = this;
  v3 = obj;
  v4 = evtId;
  v5 = this;
  v6 = this->Chains.mHash.pTable;
  v7 = 0i64;
  if ( !this->Chains.mHash.pTable )
    goto LABEL_12;
  v8 = v6->SizeMask;
  v9 = v8 & (signed int)evtId;
  v10 = v8 & (signed int)evtId;
  v11 = (signed __int64)&v6[2 * (v8 & (signed int)evtId) + 1];
  if ( *(_QWORD *)v11 == -2i64 || (v8 & *(signed int *)(v11 + 8)) != v9 )
    goto LABEL_12;
  while ( (v8 & *(signed int *)(v11 + 8)) != v9 || *(_DWORD *)(v11 + 8) != evtId )
  {
    v10 = *(_QWORD *)v11;
    if ( *(_QWORD *)v11 == -1i64 )
      goto LABEL_12;
    v11 = (signed __int64)&v6[2 * v10 + 1];
  }
  if ( v10 >= 0
    && (v12 = (signed __int64)&v6[2 * v10 + 1].SizeMask) != 0
    && (v13 = (Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> **)(v12 + 8)) != 0i64 )
  {
    v14 = *v13;
  }
  else
  {
LABEL_12:
    v23 = 2;
    v15 = (Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::EventChains *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(Scaleform::Memory::pGlobalHeap, v5, 24i64, &v23, -2i64);
    v14 = (Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> *)v15;
    v24 = v15;
    if ( v15 )
    {
      v19 = v15;
      v15->Data = 0i64;
      v15->Size = 0i64;
      v15->Policy.Capacity = 0i64;
    }
    else
    {
      v14 = 0i64;
    }
    v19 = (Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *)&v14->Data.Data;
    v20 = 1;
    LODWORD(v22) = v4;
    key.pFirst = (const int *)&v22;
    key.pSecond = (Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> > *)&v19;
    Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>::add<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> > *)&v5->Chains.mHash.pTable,
      v5,
      &key,
      v4);
    v16 = v19;
    if ( v19 )
    {
      if ( v20 )
      {
        v20 = 0;
        v24 = v19;
        Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>(v19);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v16);
      }
      v19 = 0i64;
    }
    v20 = 0;
  }
  if ( Scaleform::GFx::AS3::EventChains::FindObjectIndexInChain(v5, v14, v3) == -1i64 )
  {
    if ( v3 )
      v7 = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy((Scaleform::RefCountWeakSupportImpl *)&v3->vfptr);
    v22 = (Scaleform::GFx::AS3::EventChains *)v7;
    Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *)&v14->Data.Data,
      v14,
      v14->Data.Size + 1);
    v17 = (Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *)&v14->Data.Data[v14->Data.Size - 1];
    v24 = v17;
    v19 = v17;
    if ( v17 )
    {
      if ( v7 )
        ++v7->RefCount;
      v17->Data = (Scaleform::WeakPtr<Scaleform::GFx::DisplayObject> *)v7;
    }
    if ( v7 )
    {
      v18 = v7->RefCount-- == 1;
      if ( v18 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v7);
    }
  }
}

// File Line: 2991
// RVA: 0x811920
void __fastcall Scaleform::GFx::AS3::EventChains::RemoveFromChain(Scaleform::GFx::AS3::EventChains *this, Scaleform::GFx::EventId::IdCode evtId, Scaleform::GFx::DisplayObject *obj)
{
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *v3; // r10
  Scaleform::GFx::DisplayObject *v4; // rsi
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // r11
  signed __int64 v7; // r9
  signed __int64 v8; // r8
  signed __int64 v9; // rax
  Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> **v10; // rax
  Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> *v11; // rbx
  __int64 v12; // rax
  Scaleform::WeakPtrProxy *v13; // rdx
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject> *v14; // rbx
  bool v15; // zf

  v3 = this->Chains.mHash.pTable;
  v4 = obj;
  if ( this->Chains.mHash.pTable )
  {
    v5 = v3->SizeMask;
    v6 = v5 & (signed int)evtId;
    v7 = v5 & (signed int)evtId;
    v8 = (signed __int64)&v3[2 * v6 + 1];
    if ( *(_QWORD *)v8 != -2i64 && (v5 & *(signed int *)(v8 + 8)) == v6 )
    {
      while ( (v5 & *(signed int *)(v8 + 8)) != v6 || *(_DWORD *)(v8 + 8) != evtId )
      {
        v7 = *(_QWORD *)v8;
        if ( *(_QWORD *)v8 == -1i64 )
          return;
        v8 = (signed __int64)&v3[2 * v7 + 1];
      }
      if ( v7 >= 0 )
      {
        v9 = (signed __int64)&v3[2 * v7 + 1].SizeMask;
        if ( v9 )
        {
          v10 = (Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> **)(v9 + 8);
          if ( v10 )
          {
            v11 = *v10;
            v12 = Scaleform::GFx::AS3::EventChains::FindObjectIndexInChain(this, *v10, v4);
            if ( v12 != -1 )
            {
              v13 = v11->Data.Data[v12].pProxy.pObject;
              v14 = &v11->Data.Data[v12];
              if ( v13 )
              {
                v15 = v13->RefCount-- == 1;
                if ( v15 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
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
void __fastcall Scaleform::GFx::AS3::EventChains::Dispatch(Scaleform::GFx::AS3::EventChains *this, Scaleform::GFx::EventId::IdCode evtId)
{
  unsigned int v2; // ebp
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *v3; // r9
  unsigned __int64 v4; // r11
  unsigned __int64 v5; // r10
  signed __int64 v6; // rcx
  signed __int64 v7; // r8
  signed __int64 v8; // rax
  Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v9; // rdi
  unsigned __int64 v10; // rsi
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> *v11; // rbx
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> v12; // rdx
  Scaleform::GFx::Sprite *v13; // rbx
  Scaleform::GFx::AS3::AvmDisplayObj *v14; // rcx
  bool v15; // zf
  Scaleform::WeakPtrProxy *v16; // rdx
  Scaleform::GFx::EventId id; // [rsp+28h] [rbp-40h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::Sprite *v19; // [rsp+80h] [rbp+18h]
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject> *v20; // [rsp+88h] [rbp+20h]

  v2 = evtId;
  v3 = this->Chains.mHash.pTable;
  if ( this->Chains.mHash.pTable )
  {
    v4 = v3->SizeMask;
    v5 = v4 & (signed int)evtId;
    v6 = v4 & (signed int)evtId;
    v7 = (signed __int64)&v3[2 * (v4 & (signed int)evtId) + 1];
    if ( *(_QWORD *)v7 != -2i64 && (v4 & *(signed int *)(v7 + 8)) == v5 )
    {
      while ( (v4 & *(signed int *)(v7 + 8)) != v5 || *(_DWORD *)(v7 + 8) != evtId )
      {
        v6 = *(_QWORD *)v7;
        if ( *(_QWORD *)v7 == -1i64 )
          return;
        v7 = (signed __int64)&v3[2 * v6 + 1];
      }
      if ( v6 >= 0 )
      {
        v8 = (signed __int64)&v3[2 * v6 + 1].SizeMask;
        if ( v8 )
        {
          if ( v8 != -8 )
          {
            v9 = *(Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> **)(v8 + 8);
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
                id.Id = v2;
                *(_QWORD *)&id.WcharCode = 0i64;
                id.AsciiCode = 0;
                *(_DWORD *)&id.RollOverCnt = 65280;
                Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
                  v11,
                  &result);
                v13 = result.pObject;
                if ( result.pObject )
                {
                  ++result.pObject->RefCount;
                  v13 = result.pObject;
                }
                v19 = v13;
                if ( result.pObject )
                  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
                if ( v13 )
                  v14 = (Scaleform::GFx::AS3::AvmDisplayObj *)((char *)v13 + 4 * (unsigned __int8)v13->AvmObjOffset);
                else
                  v14 = 0i64;
                Scaleform::GFx::AS3::AvmDisplayObj::FireEvent(v14, &id);
                ++v10;
                if ( v13 )
                  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v13->vfptr);
LABEL_34:
                if ( v10 >= v9->Size )
                  return;
              }
              if ( v12.pProxy.pObject )
              {
                v15 = v12.pProxy.pObject->RefCount-- == 1;
                if ( v15 )
                  ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
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
                    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
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
void __fastcall Scaleform::GFx::AS3::EventChains::QueueEvents(Scaleform::GFx::AS3::EventChains *this, Scaleform::GFx::EventId::IdCode evtId)
{
  Scaleform::GFx::EventId::IdCode v2; // ebp
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *v3; // r9
  unsigned __int64 v4; // r11
  unsigned __int64 v5; // r10
  signed __int64 v6; // rcx
  signed __int64 v7; // r8
  signed __int64 v8; // rax
  Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *v9; // rdi
  unsigned __int64 v10; // rsi
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> *v11; // rbx
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> v12; // rdx
  Scaleform::GFx::Sprite *v13; // rbx
  signed __int64 v14; // rcx
  bool v15; // zf
  Scaleform::WeakPtrProxy *v16; // rdx
  Scaleform::GFx::EventId::IdCode v17; // [rsp+28h] [rbp-40h]
  __int64 v18; // [rsp+2Ch] [rbp-3Ch]
  char v19; // [rsp+34h] [rbp-34h]
  int v20; // [rsp+38h] [rbp-30h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::Sprite *v22; // [rsp+80h] [rbp+18h]
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject> *v23; // [rsp+88h] [rbp+20h]

  v2 = evtId;
  v3 = this->Chains.mHash.pTable;
  if ( this->Chains.mHash.pTable )
  {
    v4 = v3->SizeMask;
    v5 = v4 & (signed int)evtId;
    v6 = v4 & (signed int)evtId;
    v7 = (signed __int64)&v3[2 * (v4 & (signed int)evtId) + 1];
    if ( *(_QWORD *)v7 != -2i64 && (v4 & *(signed int *)(v7 + 8)) == v5 )
    {
      while ( (v4 & *(signed int *)(v7 + 8)) != v5 || *(_DWORD *)(v7 + 8) != evtId )
      {
        v6 = *(_QWORD *)v7;
        if ( *(_QWORD *)v7 == -1i64 )
          return;
        v7 = (signed __int64)&v3[2 * v6 + 1];
      }
      if ( v6 >= 0 )
      {
        v8 = (signed __int64)&v3[2 * v6 + 1].SizeMask;
        if ( v8 )
        {
          if ( v8 != -8 )
          {
            v9 = *(Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> **)(v8 + 8);
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
                v17 = v2;
                v18 = 0i64;
                v19 = 0;
                v20 = 65280;
                Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
                  v11,
                  &result);
                v13 = result.pObject;
                if ( result.pObject )
                {
                  ++result.pObject->RefCount;
                  v13 = result.pObject;
                }
                v22 = v13;
                if ( result.pObject )
                  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
                if ( v13 )
                  v14 = (signed __int64)v13 + 4 * (unsigned __int8)v13->AvmObjOffset;
                else
                  v14 = 0i64;
                (*(void (__fastcall **)(signed __int64, Scaleform::GFx::EventId::IdCode *))(*(_QWORD *)v14 + 64i64))(
                  v14,
                  &v17);
                ++v10;
                if ( v13 )
                  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v13->vfptr);
LABEL_34:
                if ( v10 >= v9->Size )
                  return;
              }
              if ( v12.pProxy.pObject )
              {
                v15 = v12.pProxy.pObject->RefCount-- == 1;
                if ( v15 )
                  ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
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
                    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
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
__int64 __fastcall Scaleform::GFx::AS3::EventChains::FindObjectIndexInChain(Scaleform::GFx::AS3::EventChains *this, Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> *chain, Scaleform::GFx::DisplayObject *obj)
{
  unsigned __int64 v3; // rbp
  Scaleform::GFx::DisplayObject *v4; // r14
  Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> *v5; // r15
  __int64 v6; // rdi
  Scaleform::GFx::DisplayObject *v7; // rbx
  Scaleform::WeakPtrProxy *v8; // rdx
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject> *v9; // rsi
  Scaleform::RefCountWeakSupportImpl *v10; // rax
  bool v11; // zf

  v3 = chain->Data.Size;
  v4 = obj;
  v5 = chain;
  v6 = 0i64;
  if ( !v3 )
    return -1i64;
  while ( 1 )
  {
    v7 = 0i64;
    v8 = v5->Data.Data[v6].pProxy.pObject;
    v9 = &v5->Data.Data[v6];
    if ( v8 )
    {
      v10 = v8->pObject;
      if ( v10 )
      {
        v7 = (Scaleform::GFx::DisplayObject *)v8->pObject;
        if ( !v10->RefCount )
          v7 = 0i64;
      }
      else
      {
        v11 = v8->RefCount-- == 1;
        if ( v11 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v9->pProxy.pObject = 0i64;
      }
    }
    if ( v7 == v4 )
      break;
    if ( ++v6 >= v3 )
      return -1i64;
  }
  return v6;
}

// File Line: 3074
// RVA: 0x77F4B0
void __fastcall Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(Scaleform::GFx::AS3::LoadQueueEntry *this, Scaleform::GFx::AS3::Instances::fl_net::URLRequest *request, Scaleform::GFx::AS3::Instances::fl_display::Loader *loader, Scaleform::GFx::LoadQueueEntry::LoadMethod method, bool quietOpen)
{
  Scaleform::GFx::LoadQueueEntry::LoadMethod v5; // er14
  Scaleform::GFx::AS3::Instances::fl_display::Loader *v6; // rbp
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v7; // rsi
  Scaleform::GFx::AS3::LoadQueueEntry *v8; // rdi
  char *v9; // rdx
  Scaleform::Render::RenderBuffer *v10; // rcx
  Scaleform::String src; // [rsp+68h] [rbp+10h]

  v5 = method;
  v6 = loader;
  v7 = request;
  v8 = this;
  if ( request )
    v9 = (char *)request->Url.pNode->pData;
  else
    v9 = &customWorldMapCaption;
  Scaleform::String::String(&src, v9);
  v8->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable;
  Scaleform::String::String(&v8->URL);
  v8->Type = (src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) == -12i64;
  v8->Method = v5;
  v8->pNext = 0i64;
  Scaleform::String::operator=(&v8->URL, &src);
  v8->EntryTime = -1;
  v8->QuietOpen = quietOpen;
  v8->Canceled = 0;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v8->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::AS3::LoadQueueEntry::`vftable;
  v8->mLoader.pObject = 0i64;
  v8->mURLLoader.pObject = 0i64;
  v8->mURLRequest.pObject = 0i64;
  v8->mBytes.pObject = 0i64;
  v8->mBytes.Owner = 1;
  v8->NotifyLoadInitCInterface.pObject = 0i64;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v8->mLoader,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v6);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v8->mURLRequest,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7);
  v8->FirstExec = 1;
  v10 = (Scaleform::Render::RenderBuffer *)v8->NotifyLoadInitCInterface.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  v8->NotifyLoadInitCInterface.pObject = 0i64;
}

// File Line: 3083
// RVA: 0x77F340
void __fastcall Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(Scaleform::GFx::AS3::LoadQueueEntry *this, Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *bytes, Scaleform::GFx::AS3::Instances::fl_display::Loader *loader, Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  Scaleform::GFx::LoadQueueEntry::LoadMethod v4; // edi
  Scaleform::GFx::AS3::Instances::fl_display::Loader *v5; // r14
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v6; // rbp
  Scaleform::GFx::AS3::LoadQueueEntry *v7; // rsi
  Scaleform::Render::RenderBuffer *v8; // rcx
  __int64 v9; // rax
  Scaleform::String src; // [rsp+68h] [rbp+10h]
  int v11; // [rsp+78h] [rbp+20h]

  v4 = method;
  v5 = loader;
  v6 = bytes;
  v7 = this;
  Scaleform::String::String(&src, &customWorldMapCaption);
  v7->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable;
  Scaleform::String::String(&v7->URL);
  v7->Type = (src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) == -12i64;
  v7->Method = v4;
  v7->pNext = 0i64;
  Scaleform::String::operator=(&v7->URL, &src);
  v7->EntryTime = -1;
  *(_WORD *)&v7->QuietOpen = 0;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v7->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::AS3::LoadQueueEntry::`vftable;
  v7->mLoader.pObject = 0i64;
  v7->mURLLoader.pObject = 0i64;
  v7->mURLRequest.pObject = 0i64;
  v7->mBytes.pObject = 0i64;
  v7->mBytes.Owner = 1;
  v7->NotifyLoadInitCInterface.pObject = 0i64;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v7->mLoader,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v5);
  v7->FirstExec = 1;
  v8 = (Scaleform::Render::RenderBuffer *)v7->NotifyLoadInitCInterface.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  v7->NotifyLoadInitCInterface.pObject = 0i64;
  v11 = 2;
  v9 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::LoadQueueEntry *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
         Scaleform::Memory::pGlobalHeap,
         v7,
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
    &v7->mBytes,
    (Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)v9);
  Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)v7->mBytes.pObject,
    v6->Length);
  memmove(v7->mBytes.pObject->Data.Data, v6->Data.Data.Data, v7->mBytes.pObject->Data.Size);
}

// File Line: 3094
// RVA: 0x77F5E0
void __fastcall Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(Scaleform::GFx::AS3::LoadQueueEntry *this, Scaleform::GFx::AS3::Instances::fl_net::URLRequest *request, Scaleform::GFx::AS3::Instances::fl_net::URLLoader *loader, Scaleform::GFx::LoadQueueEntry::LoadMethod method, bool quietOpen)
{
  Scaleform::GFx::LoadQueueEntry::LoadMethod v5; // ebp
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v6; // r14
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v7; // rsi
  Scaleform::GFx::AS3::LoadQueueEntry *v8; // rdi
  char *v9; // rdx
  Scaleform::Render::RenderBuffer *v10; // rcx
  Scaleform::String src; // [rsp+58h] [rbp+10h]

  v5 = method;
  v6 = loader;
  v7 = request;
  v8 = this;
  if ( request )
    v9 = (char *)request->Url.pNode->pData;
  else
    v9 = &customWorldMapCaption;
  Scaleform::String::String(&src, v9);
  v8->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable;
  Scaleform::String::String(&v8->URL);
  v8->Type = 4;
  v8->Method = v5;
  v8->pNext = 0i64;
  Scaleform::String::operator=(&v8->URL, &src);
  v8->EntryTime = -1;
  v8->QuietOpen = quietOpen;
  v8->Canceled = 0;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v8->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::AS3::LoadQueueEntry::`vftable;
  v8->mLoader.pObject = 0i64;
  v8->mURLLoader.pObject = 0i64;
  v8->mURLRequest.pObject = 0i64;
  v8->mBytes.pObject = 0i64;
  v8->mBytes.Owner = 1;
  v8->NotifyLoadInitCInterface.pObject = 0i64;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v8->mURLLoader,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v6);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v8->mURLRequest,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7);
  v8->FirstExec = 1;
  v10 = (Scaleform::Render::RenderBuffer *)v8->NotifyLoadInitCInterface.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  v8->NotifyLoadInitCInterface.pObject = 0i64;
}

// File Line: 3102
// RVA: 0x78C430
void __fastcall Scaleform::GFx::AS3::LoadQueueEntry::~LoadQueueEntry(Scaleform::GFx::AS3::LoadQueueEntry *this)
{
  Scaleform::GFx::AS3::LoadQueueEntry *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v4; // rcx
  unsigned int v5; // eax
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v6; // rcx
  unsigned int v7; // eax
  Scaleform::GFx::AS3::Instances::fl_display::Loader *v8; // rcx
  unsigned int v9; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::AS3::LoadQueueEntry::`vftable;
  if ( this->NotifyLoadInitCInterface.pObject )
  {
    v2 = (Scaleform::Render::RenderBuffer *)this->NotifyLoadInitCInterface.pObject;
    if ( v2 )
      Scaleform::RefCountImpl::Release(v2);
    v1->NotifyLoadInitCInterface.pObject = 0i64;
  }
  v3 = (Scaleform::Render::RenderBuffer *)v1->NotifyLoadInitCInterface.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  Scaleform::AutoPtr<Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::~AutoPtr<Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>(&v1->mBytes);
  v4 = v1->mURLRequest.pObject;
  if ( v4 )
  {
    if ( (unsigned __int8)v4 & 1 )
    {
      v1->mURLRequest.pObject = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( v5 & 0x3FFFFF )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
  }
  v6 = v1->mURLLoader.pObject;
  if ( v6 )
  {
    if ( (unsigned __int8)v6 & 1 )
    {
      v1->mURLLoader.pObject = (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)((char *)v6 - 1);
    }
    else
    {
      v7 = v6->RefCount;
      if ( v7 & 0x3FFFFF )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->vfptr);
      }
    }
  }
  v8 = v1->mLoader.pObject;
  if ( v8 )
  {
    if ( (unsigned __int8)v8 & 1 )
    {
      v1->mLoader.pObject = (Scaleform::GFx::AS3::Instances::fl_display::Loader *)((char *)v8 - 1);
    }
    else
    {
      v9 = v8->RefCount;
      if ( v9 & 0x3FFFFF )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
      }
    }
  }
  v1->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->URL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 3110
// RVA: 0x77F700
void __fastcall Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie::LoadQueueEntryMT_LoadMovie(Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *this, Scaleform::GFx::AS3::LoadQueueEntry *pqueueEntry, Scaleform::GFx::MovieImpl *pmovieRoot)
{
  Scaleform::GFx::AS3::LoadQueueEntry *v3; // rsi
  Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *v4; // rbx
  Scaleform::GFx::MoviePreloadTask *v5; // rbp
  bool v6; // di
  Scaleform::GFx::InteractiveObject *v7; // rcx
  __int64 v8; // rax
  Scaleform::GFx::TaskManager *v9; // rax
  Scaleform::GFx::MoviePreloadTask *v10; // rax
  Scaleform::Render::RenderBuffer *v11; // rcx
  Scaleform::Ptr<Scaleform::GFx::TaskManager> *v12; // rax
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+78h] [rbp+20h]

  v3 = pqueueEntry;
  v4 = this;
  Scaleform::GFx::LoadQueueEntryMT::LoadQueueEntryMT(
    (Scaleform::GFx::LoadQueueEntryMT *)&this->vfptr,
    (Scaleform::GFx::LoadQueueEntry *)&pqueueEntry->vfptr,
    pmovieRoot);
  v4->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie::`vftable;
  v5 = 0i64;
  v4->pPreloadTask.pObject = 0i64;
  v4->CharSwitched = 0;
  v4->FirstFrameLoaded = 0;
  v4->BytesLoaded = 0;
  v6 = 0;
  v7 = v4->pMovieImpl->pASMovieRoot.pObject->pMovieImpl->pMainMovie;
  if ( v7 )
  {
    v8 = ((__int64 (*)(void))v7->vfptr[66].__vecDelDtor)();
    v6 = ((*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v8 + 88i64))(v8) >> 4) & 1;
  }
  v9 = (Scaleform::GFx::TaskManager *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                        Scaleform::Memory::pGlobalHeap,
                                        80i64);
  result.pObject = v9;
  if ( v9 )
  {
    Scaleform::GFx::MoviePreloadTask::MoviePreloadTask(
      (Scaleform::GFx::MoviePreloadTask *)v9,
      v4->pMovieImpl,
      &v3->URL,
      v6,
      v3->QuietOpen);
    v5 = v10;
  }
  v11 = (Scaleform::Render::RenderBuffer *)v4->pPreloadTask.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  v4->pPreloadTask.pObject = v5;
  v12 = Scaleform::GFx::StateBag::GetTaskManager((Scaleform::GFx::StateBag *)&v4->pMovieImpl->vfptr, &result);
  v12->pObject->vfptr[1].__vecDelDtor(
    (Scaleform::RefCountImplCore *)v12->pObject,
    (unsigned int)v4->pPreloadTask.pObject);
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
}

// File Line: 3133
// RVA: 0x7F9CE0
char __fastcall Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie::LoadFinished(Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *this)
{
  Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *v1; // rsi
  bool v2; // al
  Scaleform::GFx::LoadQueueEntry *v3; // rbx
  Scaleform::GFx::AS3::MovieRoot *v4; // r12
  SSExpressionBase *v5; // rax
  Scaleform::GFx::MovieDefImpl *v6; // rdi
  Scaleform::GFx::LoadQueueEntryVtbl *v7; // rcx
  Scaleform::GFx::LogState *v8; // rdi
  __int64 v9; // rdi
  Scaleform::GFx::LogState *v10; // rsi
  Scaleform::GFx::LoadQueueEntryVtbl *v11; // rcx
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v12; // rcx
  Scaleform::GFx::LoadQueueEntryVtbl *v13; // rcx
  unsigned __int64 v14; // rdx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v15; // rcx
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v16; // r14
  volatile unsigned int v17; // ecx
  Scaleform::GFx::AS3::ASVM *v18; // rcx
  Scaleform::GFx::ASSupport *v19; // rcx
  Scaleform::GFx::Sprite *v20; // r13
  Scaleform::GFx::AS3::AvmDisplayObj *v21; // r15
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v22; // rcx
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v23; // rcx
  unsigned int v24; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v25; // rcx
  __int64 v26; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v27; // rcx
  Scaleform::GFx::Resource *v28; // rcx
  int v29; // eax
  Scaleform::GFx::MovieDefImpl::BindTaskData *v30; // rcx
  void *(__fastcall *v31)(Scaleform::GFx::LoadQueueEntry *, unsigned int); // r15
  Scaleform::GFx::ASSupport *v32; // rcx
  Scaleform::GFx::AS3::AvmBitmap *v33; // rsi
  Scaleform::GFx::MovieDataDef *v34; // rdx
  Scaleform::GFx::Resource *v35; // rax
  Scaleform::GFx::ImageResource *v36; // rdi
  Scaleform::GFx::AS3::AvmDisplayObj *v37; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v38; // rcx
  __int64 v39; // rax
  Scaleform::GFx::Resource *v40; // rcx
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v42; // rcx
  __int64 v43; // [rsp+28h] [rbp-71h]
  Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC> v44; // [rsp+30h] [rbp-69h]
  Scaleform::GFx::ResourceHandle phandle; // [rsp+38h] [rbp-61h]
  Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC> pnLoadInitCL; // [rsp+48h] [rbp-51h]
  Scaleform::GFx::Sprite *v47; // [rsp+50h] [rbp-49h]
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [rsp+58h] [rbp-41h]
  Scaleform::Ptr<Scaleform::GFx::LogState> v49; // [rsp+60h] [rbp-39h]
  Scaleform::GFx::MovieDataDef *v50; // [rsp+68h] [rbp-31h]
  Scaleform::GFx::MovieDefImpl *v51; // [rsp+70h] [rbp-29h]
  __int64 v52; // [rsp+78h] [rbp-21h]
  Scaleform::GFx::MovieDataDef *v53; // [rsp+80h] [rbp-19h]
  Scaleform::GFx::MovieDefImpl *v54; // [rsp+88h] [rbp-11h]
  __int64 v55; // [rsp+90h] [rbp-9h]
  Scaleform::GFx::AS3::AvmBitmap *v56; // [rsp+98h] [rbp-1h]
  __int64 v57; // [rsp+A0h] [rbp+7h]
  Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC> *v58; // [rsp+100h] [rbp+67h]
  int v59; // [rsp+108h] [rbp+6Fh]
  void *(__fastcall *rid)(Scaleform::GFx::LoadQueueEntry *, unsigned int); // [rsp+110h] [rbp+77h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> v61; // [rsp+118h] [rbp+7Fh]

  v57 = -2i64;
  v1 = this;
  v2 = Scaleform::GFx::MoviePreloadTask::IsDone(this->pPreloadTask.pObject);
  v3 = v1->pQueueEntry;
  if ( v3->Canceled && v2 )
    return 1;
  v4 = (Scaleform::GFx::AS3::MovieRoot *)v1->pMovieImpl->pASMovieRoot.pObject;
  if ( v2 )
  {
    v5 = Scaleform::GFx::MovieImpl::GetHeap((SSClosureInfoMethod *)v1->pPreloadTask.pObject);
    v6 = (Scaleform::GFx::MovieDefImpl *)v5;
    if ( !v5 )
    {
      Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
        (Scaleform::GFx::AS3::Instances::fl_display::Loader *)v3[1].vfptr,
        **(const char ***)(*(_QWORD *)&v3[1].Type + 56i64));
      v7 = v3[2].vfptr;
      if ( v7 )
        (*((void (**)(void))v7->__vecDelDtor + 3))();
      LOBYTE(v3[2].pNext) = 0;
      return 1;
    }
    if ( LOBYTE(v3[2].pNext) )
    {
      if ( ((unsigned int (__fastcall *)(SSExpressionBase *))v5->vfptr->invoke)(v5) != -1
        && (((unsigned int (__fastcall *)(Scaleform::GFx::MovieDefImpl *))v6->vfptr[1].__vecDelDtor)(v6) < 9
         || (char)((v6->pBindData.pObject->pDataDef.pObject->pData.pObject->FileAttributes & 8 | 0x10) >> 3) < 3) )
      {
        v1->pQueueEntry->Canceled = 1;
        v8 = Scaleform::GFx::StateBag::GetLogState((Scaleform::GFx::StateBag *)&v4->pMovieImpl->vfptr, &result)->pObject;
        if ( result.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
        if ( v8 && !v3->QuietOpen )
        {
          v9 = **(_QWORD **)(*(_QWORD *)&v3[1].Type + 56i64);
          v10 = Scaleform::GFx::StateBag::GetLogState((Scaleform::GFx::StateBag *)&v4->pMovieImpl->vfptr, &v49)->pObject;
          if ( v49.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v49.pObject);
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
            (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v10->vfptr,
            "Failed loading SWF \"%s\": ActionScript version mismatch",
            v9);
        }
        Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
          (Scaleform::GFx::AS3::Instances::fl_display::Loader *)v3[1].vfptr,
          **(const char ***)(*(_QWORD *)&v3[1].Type + 56i64));
        v11 = v3[2].vfptr;
        if ( v11 )
          (*((void (**)(void))v11->__vecDelDtor + 3))();
        return 1;
      }
      v12 = (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v3[1].vfptr[14].__vecDelDtor;
      if ( v12 )
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteOpenEvent(v12);
      v13 = v3[2].vfptr;
      if ( v13 )
        (*((void (**)(void))v13->__vecDelDtor + 1))();
      LOBYTE(v3[2].pNext) = 0;
      Scaleform::GFx::AS3::MovieRoot::AddLoadedMovieDef(v4, v6);
    }
    if ( !v1->CharSwitched )
      v1->CharSwitched = 1;
    if ( v1->BytesLoaded != v6->pBindData.pObject->BytesLoaded )
    {
      v14 = v6->pBindData.pObject->BytesLoaded;
      v1->BytesLoaded = v14;
      v15 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)v3[1].vfptr[14].__vecDelDtor;
      if ( v15 )
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteProgressEvent(
          v15,
          v14,
          v6->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.FileLength);
    }
    v16 = 0i64;
    if ( !v1->FirstFrameLoaded )
    {
      v17 = v6->pBindData.pObject->BindState;
      if ( _bittest((const signed int *)&v17, 8u) )
      {
        if ( v6->pBindData.pObject->pDataDef.pObject->MovieType == 1 )
        {
          rid = v3[1].vfptr[11].__vecDelDtor;
          v47 = 0i64;
          v18 = v4->pAVM.pObject;
          if ( v18 )
            Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(v18->GC.GC, v1->pMovieImpl->AdvanceStats.pObject, 0);
          v53 = v6->pBindData.pObject->pDataDef.pObject;
          v54 = v6;
          v55 = 0i64;
          v19 = v4->pASSupport.pObject;
          LODWORD(v58) = 0;
          v20 = (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::MovieDataDef **, _QWORD, Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC> **, signed int))v19->vfptr[4].__vecDelDtor)(
                                            v19,
                                            v1->pMovieImpl,
                                            &v53,
                                            0i64,
                                            &v58,
                                            3);
          v47 = v20;
          Scaleform::GFx::Sprite::SetLoadedSeparately(v20, 1);
          v20->Flags |= 1u;
          ((void (__fastcall *)(Scaleform::GFx::Sprite *))v20->vfptr[73].__vecDelDtor)(v20);
          Scaleform::GFx::InteractiveObject::AddToPlayList((Scaleform::GFx::InteractiveObject *)&v20->vfptr);
          v21 = (Scaleform::GFx::AS3::AvmDisplayObj *)((char *)v20 + 4 * (unsigned __int8)v20->AvmObjOffset);
          v22 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)v3[1].vfptr[14].__vecDelDtor;
          if ( v22 )
          {
            Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::applicationDomainGet(v22, &v61);
            if ( v61.pObject && Scaleform::GFx::AS3::VMAppDomain::Enabled )
              v21->AppDomain = v61.pObject->VMDomain.pObject;
            v23 = v61.pObject;
            if ( v61.pObject )
            {
              if ( (_QWORD)v61.pObject & 1 )
              {
                --v61.pObject;
              }
              else
              {
                v24 = v61.pObject->RefCount;
                if ( v24 & 0x3FFFFF )
                {
                  v61.pObject->RefCount = v24 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v23->vfptr);
                }
              }
            }
          }
          ((void (__fastcall *)(Scaleform::GFx::AS3::AvmDisplayObj *, _QWORD))v21->vfptr[2].ToAvmButttonBase)(v21, 0i64);
          ((void (__fastcall *)(Scaleform::GFx::Sprite *))v20->vfptr[39].__vecDelDtor)(v20);
          if ( !v21->pAS3RawPtr
            && !v21->pAS3CollectiblePtr.pObject
            && Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(v21) )
          {
            v25 = v21->pAS3RawPtr;
            if ( !v25 )
              v25 = v21->pAS3CollectiblePtr.pObject;
            if ( (unsigned __int8)v25 & 1 )
              v25 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v25 - 1);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v25->pLoaderInfo,
              (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3[1].vfptr[14].__vecDelDtor);
            Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(v21, 1);
          }
          if ( !rid
            || (v26 = (*(__int64 (**)(void))(*(_QWORD *)((char *)rid + 4 * *((unsigned __int8 *)rid + 109)) + 40i64))(),
                v27 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v26 - 72),
                !v26) )
          {
            v27 = 0i64;
          }
          Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(v27, (Scaleform::GFx::DisplayObjectBase *)&v20->vfptr);
          v4->vfptr[39].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, (unsigned int)v20);
          Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Sprite>((Scaleform::GFx::InteractiveObject *)&v20->vfptr);
          ((void (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *))v4->vfptr[7].__vecDelDtor)(v4);
          v58 = &pnLoadInitCL;
          v28 = (Scaleform::GFx::Resource *)v3[2].vfptr;
          if ( v28 )
            Scaleform::Render::RenderBuffer::AddRef(v28);
          pnLoadInitCL.pObject = (Scaleform::GFx::AS3::NotifyLoadInitC *)v3[2].vfptr;
          Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueInitEvent(
            (Scaleform::GFx::AS3::Instances::fl_display::Loader *)v3[1].vfptr,
            (Scaleform::GFx::DisplayObject *)&v20->vfptr,
            (Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC>)&pnLoadInitCL);
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v20->vfptr);
        }
        v1->FirstFrameLoaded = 1;
      }
    }
    v29 = v6->pBindData.pObject->BindState & 0xF;
    if ( v29 < 0 )
      return 1;
    if ( v29 > 1 )
    {
      if ( v29 == 2 )
      {
        v30 = v6->pBindData.pObject;
        if ( v30->pDataDef.pObject->MovieType == 2 )
        {
          v31 = v3[1].vfptr[11].__vecDelDtor;
          v50 = v30->pDataDef.pObject;
          v51 = v6;
          v52 = 0i64;
          v32 = v4->pASSupport.pObject;
          v59 = 0x40000;
          LODWORD(v43) = 8;
          v33 = (Scaleform::GFx::AS3::AvmBitmap *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::MovieDataDef **, _QWORD, int *, __int64))v32->vfptr[4].__vecDelDtor)(
                                                    v32,
                                                    v4->pMovieImpl,
                                                    &v50,
                                                    0i64,
                                                    &v59,
                                                    v43);
          v56 = v33;
          phandle.HType = 0;
          phandle.pResource = 0i64;
          v34 = v6->pBindData.pObject->pDataDef.pObject;
          LODWORD(rid) = 0;
          if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
                 v34->pData.pObject,
                 &phandle,
                 (Scaleform::GFx::ResourceId)&rid) )
          {
            v35 = Scaleform::GFx::ResourceHandle::GetResource(&phandle, &v6->pBindData.pObject->ResourceBinding);
            v36 = (Scaleform::GFx::ImageResource *)v35;
            if ( v35 )
            {
              if ( (v35->vfptr->GetResourceTypeCode(v35) & 0xFF00) == 256 )
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
            if ( (unsigned __int8)v38 & 1 )
              v38 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v38 - 1);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v38->pLoaderInfo,
              (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3[1].vfptr[14].__vecDelDtor);
            Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(v37, 1);
          }
          if ( v31 )
          {
            v39 = (*(__int64 (**)(void))(*(_QWORD *)((char *)v31 + 4 * *((unsigned __int8 *)v31 + 109)) + 40i64))();
            if ( v39 )
              v16 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v39 - 72);
          }
          Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(v16, (Scaleform::GFx::DisplayObjectBase *)&v33->vfptr);
          v58 = &v44;
          v40 = (Scaleform::GFx::Resource *)v3[2].vfptr;
          if ( v40 )
            Scaleform::Render::RenderBuffer::AddRef(v40);
          v44.pObject = (Scaleform::GFx::AS3::NotifyLoadInitC *)v3[2].vfptr;
          Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueInitEvent(
            (Scaleform::GFx::AS3::Instances::fl_display::Loader *)v3[1].vfptr,
            (Scaleform::GFx::DisplayObject *)&v33->vfptr,
            (Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC>)&v44);
          if ( phandle.HType == RH_Pointer && phandle.pResource )
            Scaleform::GFx::Resource::Release(phandle.pResource);
          if ( v33 )
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v33->vfptr);
        }
        Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueCompleteEvent((Scaleform::GFx::AS3::Instances::fl_display::Loader *)v3[1].vfptr);
      }
      else if ( (unsigned int)(v29 - 3) <= 1 )
      {
        Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
          (Scaleform::GFx::AS3::Instances::fl_display::Loader *)v3[1].vfptr,
          **(const char ***)(*(_QWORD *)&v3[1].Type + 56i64));
        LOBYTE(v3[2].pNext) = 0;
      }
      return 1;
    }
  }
  else if ( LOBYTE(v3[2].pNext) )
  {
    v42 = (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v3[1].vfptr[14].__vecDelDtor;
    if ( v42 )
      Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteOpenEvent(v42);
    LOBYTE(v3[2].pNext) = 0;
  }
  return 0;
}xt) = 0;
      }


// File Line: 3381
// RVA: 0x7ADCB0
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddLoadQueueEntryMT(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::LoadQueueEntry *pentry)
{
  Scaleform::GFx::AS3::LoadQueueEntry *v2; // rdi
  Scaleform::GFx::AS3::MovieRoot *v3; // rbx
  Scaleform::GFx::LoadQueueEntry::LoadType v4; // eax
  Scaleform::GFx::LoadQueueEntryMT_LoadVars *v5; // rax
  Scaleform::GFx::LoadQueueEntryMT *v6; // rax
  Scaleform::GFx::LoadQueueEntryMT *v7; // rdx
  bool v8; // zf
  Scaleform::MemoryHeap *v9; // rcx
  Scaleform::MemoryHeapVtbl *v10; // rax
  Scaleform::GFx::LoadQueueEntryMT_LoadBinary *v11; // rax
  Scaleform::GFx::LoadQueueEntryMT *v12; // rax
  Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *v13; // rax
  Scaleform::GFx::LoadQueueEntryMT *v14; // rax
  Scaleform::GFx::LoadQueueEntry *v15; // r9
  Scaleform::GFx::LoadQueueEntryMT *i; // rcx
  Scaleform::GFx::LoadQueueEntry *v17; // rax
  Scaleform::GFx::LoadQueueEntryVtbl *v18; // r8
  Scaleform::GFx::LoadQueueEntry *v19; // r8

  v2 = pentry;
  v3 = this;
  v4 = pentry->Type;
  if ( v4 & 4 )
  {
    v5 = (Scaleform::GFx::LoadQueueEntryMT_LoadVars *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, signed __int64))this->pMovieImpl->pHeap->vfptr->Alloc)(
                                                        this,
                                                        56i64);
    if ( v5 )
    {
      Scaleform::GFx::LoadQueueEntryMT_LoadVars::LoadQueueEntryMT_LoadVars(
        v5,
        (Scaleform::GFx::LoadQueueEntry *)&v2->vfptr,
        v3->pMovieImpl);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
  }
  else
  {
    v8 = (v4 & 0x20) == 0;
    v9 = this->pMovieImpl->pHeap;
    v10 = v9->vfptr;
    if ( v8 )
    {
      v13 = (Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *)v10->Alloc(v9, 64ui64, 0i64);
      if ( v13 )
      {
        Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie::LoadQueueEntryMT_LoadMovie(v13, v2, v3->pMovieImpl);
        v7 = v14;
      }
      else
      {
        v7 = 0i64;
      }
      if ( !v7 )
        goto LABEL_24;
      v15 = v7->pQueueEntry;
      for ( i = v3->pMovieImpl->pLoadQueueMTHead; i; i = i->pNext )
      {
        v17 = i->pQueueEntry;
        v18 = v17[1].vfptr;
        if ( !v18 || v18 != v15[1].vfptr )
        {
          v19 = v17[1].pNext;
          if ( !v19 || v19 != v15[1].pNext )
            continue;
        }
        v17->Canceled = 1;
      }
    }
    else
    {
      v11 = (Scaleform::GFx::LoadQueueEntryMT_LoadBinary *)v10->Alloc(v9, 56ui64, 0i64);
      if ( v11 )
      {
        Scaleform::GFx::LoadQueueEntryMT_LoadBinary::LoadQueueEntryMT_LoadBinary(
          v11,
          (Scaleform::GFx::LoadQueueEntry *)&v2->vfptr,
          v3->pMovieImpl);
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
    Scaleform::GFx::MovieImpl::AddLoadQueueEntryMT(v3->pMovieImpl, v7);
    return;
  }
LABEL_24:
  v2->vfptr->__vecDelDtor((Scaleform::GFx::LoadQueueEntry *)&v2->vfptr, 1u);
}

// File Line: 3467
// RVA: 0x7AE170
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddNewLoadQueueEntry(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::Instances::fl_net::URLRequest *urlRequest, Scaleform::GFx::AS3::Instances::fl_display::Loader *loader, Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  Scaleform::GFx::LoadQueueEntry::LoadMethod v4; // edi
  Scaleform::GFx::AS3::Instances::fl_display::Loader *v5; // rbp
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v6; // r14
  Scaleform::GFx::AS3::MovieRoot *v7; // rsi
  Scaleform::GFx::TaskManager *v8; // rbx
  Scaleform::GFx::TaskManager *v9; // rax
  Scaleform::GFx::AS3::LoadQueueEntry *v10; // rax
  Scaleform::GFx::AS3::LoadQueueEntry *v11; // rdi
  bool v12; // bp
  Scaleform::GFx::TaskManager *v13; // rbp
  Scaleform::GFx::MovieImpl *v14; // rdx
  Scaleform::GFx::LoaderImpl *v15; // rbx
  Scaleform::GFx::StateBag *v16; // rax
  Scaleform::GFx::TaskManager *v17; // rax
  bool v18; // bp
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+38h] [rbp-30h]
  __int64 v20; // [rsp+40h] [rbp-28h]
  Scaleform::MemoryHeap *sync; // [rsp+70h] [rbp+8h]

  v20 = -2i64;
  v4 = method;
  v5 = loader;
  v6 = urlRequest;
  v7 = this;
  v8 = 0i64;
  sync = this->pMovieImpl->pHeap;
  v9 = (Scaleform::GFx::TaskManager *)sync->vfptr->Alloc((Scaleform::MemoryHeap *)this, 96ui64, 0i64);
  result.pObject = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry((Scaleform::GFx::AS3::LoadQueueEntry *)v9, v6, v5, v4, 0);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  if ( v11 )
  {
    v12 = Scaleform::GFx::LoaderImpl::IsProtocolImage(&v11->URL, 0i64, (bool *)&sync);
    if ( v12 && (_BYTE)sync )
    {
      v13 = (Scaleform::GFx::TaskManager *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                             Scaleform::Memory::pGlobalHeap,
                                             144ui64,
                                             0i64);
      result.pObject = v13;
      if ( v13 )
      {
        v14 = v7->pMovieImpl;
        v15 = v14->pMainMovieDef.pObject->pLoaderImpl.pObject;
        v16 = (Scaleform::GFx::StateBag *)((__int64 (*)(void))v14->vfptr->GetStateBagImpl)();
        Scaleform::GFx::LoadStates::LoadStates((Scaleform::GFx::LoadStates *)v13, v15, v16, 0i64);
        v8 = v17;
      }
      result.pObject = v8;
      ((void (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, Scaleform::GFx::AS3::LoadQueueEntry *, Scaleform::GFx::TaskManager *))v7->vfptr[35].__vecDelDtor)(
        v7,
        v11,
        v8);
      v11->vfptr->__vecDelDtor((Scaleform::GFx::LoadQueueEntry *)&v11->vfptr, 1u);
      if ( v8 )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v8);
    }
    else
    {
      v18 = 0;
      if ( Scaleform::String::GetLength(&v11->URL) )
      {
        if ( !v12 )
        {
          LOBYTE(v8) = 1;
          if ( Scaleform::GFx::StateBag::GetTaskManager((Scaleform::GFx::StateBag *)&v7->pMovieImpl->vfptr, &result)->pObject )
            v18 = 1;
        }
      }
      if ( (unsigned __int8)v8 & 1 && result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
      if ( v18 )
        Scaleform::GFx::AS3::MovieRoot::AddLoadQueueEntryMT(v7, v11);
      else
        Scaleform::GFx::MovieImpl::AddLoadQueueEntry(v7->pMovieImpl, (Scaleform::GFx::LoadQueueEntry *)&v11->vfptr);
    }
  }
}

// File Line: 3497
// RVA: 0x7AE0E0
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddNewLoadQueueEntry(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *bytes, Scaleform::GFx::AS3::Instances::fl_display::Loader *loader, Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  Scaleform::GFx::LoadQueueEntry::LoadMethod v4; // edi
  Scaleform::GFx::AS3::Instances::fl_display::Loader *v5; // rsi
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v6; // rbp
  Scaleform::GFx::AS3::MovieRoot *v7; // rbx
  Scaleform::GFx::AS3::LoadQueueEntry *v8; // rax

  v4 = method;
  v5 = loader;
  v6 = bytes;
  v7 = this;
  v8 = (Scaleform::GFx::AS3::LoadQueueEntry *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, signed __int64))this->pMovieImpl->pHeap->vfptr->Alloc)(
                                                this,
                                                96i64);
  if ( v8 )
    Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(v8, v6, v5, v4);
  if ( v8 )
    Scaleform::GFx::MovieImpl::AddLoadQueueEntry(v7->pMovieImpl, (Scaleform::GFx::LoadQueueEntry *)&v8->vfptr);
}

// File Line: 3510
// RVA: 0x7AE320
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddNewLoadQueueEntry(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::Instances::fl_net::URLRequest *urlRequest, Scaleform::GFx::AS3::Instances::fl_net::URLLoader *loader, Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  Scaleform::GFx::LoadQueueEntry::LoadMethod v4; // edi
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v5; // rsi
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v6; // r14
  Scaleform::GFx::AS3::MovieRoot *v7; // rbp
  char v8; // bl
  Scaleform::GFx::AS3::LoadQueueEntry *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rdi
  __int64 v12; // rax
  char v13; // cl
  bool v14; // zf
  signed int v15; // eax
  bool v16; // si
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+70h] [rbp+8h]

  v4 = method;
  v5 = loader;
  v6 = urlRequest;
  v7 = this;
  v8 = 0;
  result.pObject = (Scaleform::GFx::TaskManager *)this->pMovieImpl->pHeap;
  v9 = (Scaleform::GFx::AS3::LoadQueueEntry *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, signed __int64, _QWORD))result.pObject->vfptr[10].__vecDelDtor)(
                                                this,
                                                96i64,
                                                0i64);
  if ( v9 )
  {
    Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(v9, v6, v5, v4, 0);
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
      v13 = v5->dataFormat.pNode->pData[v12++];
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
      if ( Scaleform::GFx::StateBag::GetTaskManager((Scaleform::GFx::StateBag *)&v7->pMovieImpl->vfptr, &result)->pObject )
        v16 = 1;
    }
    if ( v8 & 1 && result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( v16 )
      Scaleform::GFx::AS3::MovieRoot::AddLoadQueueEntryMT(v7, (Scaleform::GFx::AS3::LoadQueueEntry *)v11);
    else
      Scaleform::GFx::MovieImpl::AddLoadQueueEntry(v7->pMovieImpl, (Scaleform::GFx::LoadQueueEntry *)v11);
  }
}

// File Line: 3549
// RVA: 0x7F0420
Scaleform::Render::Text::Allocator *__fastcall Scaleform::GFx::AS3::MovieRoot::GetTextAllocator(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::MovieRoot *v1; // rbx
  Scaleform::GFx::AS3::MemoryContextImpl *v2; // rcx
  Scaleform::Render::Text::Allocator *v3; // rax
  Scaleform::Render::Text::Allocator *v4; // rax
  Scaleform::Render::Text::Allocator *v5; // rsi
  Scaleform::GFx::AS3::MemoryContextImpl *v6; // rdi
  Scaleform::RefCountNTSImpl *v7; // rcx

  v1 = this;
  v2 = this->MemContext.pObject;
  if ( v2->TextAllocator.pObject )
    return v2->TextAllocator.pObject;
  v3 = (Scaleform::Render::Text::Allocator *)v2->Heap->vfptr->Alloc((Scaleform::MemoryHeap *)v2, 144ui64, 0i64);
  if ( v3 )
  {
    Scaleform::Render::Text::Allocator::Allocator(v3, v1->MemContext.pObject->Heap, 0);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = v1->MemContext.pObject;
  v7 = (Scaleform::RefCountNTSImpl *)&v6->TextAllocator.pObject->vfptr;
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
  v6->TextAllocator.pObject = v5;
  return v1->MemContext.pObject->TextAllocator.pObject;
}

// File Line: 3558
// RVA: 0x809290
void __fastcall Scaleform::GFx::AS3::MovieRoot::ProcessLoadQueueEntry(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::LoadQueueEntry *pentry, Scaleform::GFx::LoadStates *pls)
{
  Scaleform::GFx::LoadStates *v3; // r13
  Scaleform::GFx::LoadQueueEntry *v4; // r15
  Scaleform::GFx::AS3::MovieRoot *v5; // r12
  char v6; // si
  __int64 v7; // r14
  Scaleform::GFx::MovieImpl *v8; // rcx
  const char *v9; // rax
  Scaleform::File *v10; // rbx
  Scaleform::GFx::LoadQueueEntry *v11; // rdi
  __int64 v12; // rcx
  char v13; // al
  __int64 v14; // rcx
  char v15; // al
  Scaleform::GFx::LoadQueueEntry *v16; // rbx
  __int64 v17; // rcx
  char v18; // al
  char v19; // al
  Scaleform::String::DataDesc *v20; // rdx
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v21; // rbx
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v22; // r14
  Scaleform::GFx::MovieDefImpl *v23; // rsi
  Scaleform::GFx::MovieImpl *v24; // rdx
  Scaleform::GFx::InteractiveObject *v25; // rcx
  __int64 v26; // rax
  Scaleform::String *v27; // rax
  __int64 v28; // rdx
  __int64 v29; // rsi
  unsigned __int8 *v30; // rcx
  Scaleform::GFx::LogState *v31; // rax
  Scaleform::Log *v32; // rax
  __int64 v33; // rcx
  Scaleform::Render::Image *v34; // rsi
  Scaleform::GFx::ImageResource *v35; // rax
  Scaleform::GFx::ImageResource *v36; // rax
  Scaleform::GFx::ImageResource *v37; // rbx
  unsigned int v38; // esi
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v39; // rdx
  Scaleform::GFx::MovieImpl *v40; // rcx
  const char *v41; // rax
  Scaleform::GFx::LoadQueueEntryVtbl *v42; // rcx
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v43; // rcx
  Scaleform::GFx::LoadQueueEntryVtbl *v44; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v45; // rcx
  Scaleform::GFx::ASSupport *v46; // rcx
  Scaleform::GFx::AS3::AvmBitmap *v47; // rbx
  Scaleform::GFx::MovieDataDef *v48; // rcx
  Scaleform::GFx::Resource *v49; // rax
  Scaleform::GFx::ImageResource *v50; // r12
  Scaleform::GFx::AS3::AvmDisplayObj *v51; // r13
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v52; // rcx
  __int64 v53; // rax
  Scaleform::GFx::AS3::ASVM *v54; // rcx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v55; // rcx
  unsigned __int64 v56; // r8
  unsigned __int64 v57; // rdx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v58; // rcx
  Scaleform::GFx::ASSupport *v59; // rcx
  Scaleform::GFx::AS3::AvmDisplayObj *v60; // r13
  Scaleform::GFx::LoadQueueEntryVtbl *v61; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v62; // rcx
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v63; // rcx
  unsigned int v64; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v65; // rcx
  __int64 v66; // rax
  Scaleform::GFx::Resource *v67; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v68; // rcx
  Scaleform::GFx::LoadQueueEntryVtbl *v69; // rcx
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v70; // rcx
  Scaleform::GFx::LoadQueueEntryVtbl *v71; // rcx
  Scaleform::String url; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::Resource *v73; // [rsp+38h] [rbp-C8h]
  int pfileLen; // [rsp+40h] [rbp-C0h]
  unsigned __int8 *v75; // [rsp+48h] [rbp-B8h]
  Scaleform::String v76; // [rsp+50h] [rbp-B0h]
  Scaleform::String src; // [rsp+58h] [rbp-A8h]
  Scaleform::String ppath; // [rsp+60h] [rbp-A0h]
  Scaleform::String pdest; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::MovieDefImpl *v80; // [rsp+70h] [rbp-90h]
  Scaleform::String pdata; // [rsp+78h] [rbp-88h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> v82; // [rsp+80h] [rbp-80h]
  int v83; // [rsp+88h] [rbp-78h]
  int v84; // [rsp+8Ch] [rbp-74h]
  Scaleform::GFx::ResourceId rid; // [rsp+90h] [rbp-70h]
  Scaleform::GFx::AS3::AvmBitmap *v86; // [rsp+98h] [rbp-68h]
  Scaleform::String v87; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::ResourceHandle phandle; // [rsp+A8h] [rbp-58h]
  Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC> pnLoadInitCL; // [rsp+B8h] [rbp-48h]
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> binaryData; // [rsp+C0h] [rbp-40h]
  Scaleform::String result; // [rsp+D8h] [rbp-28h]
  __int64 v92; // [rsp+E0h] [rbp-20h]
  __int64 v93; // [rsp+E8h] [rbp-18h]
  __int64 v94; // [rsp+F0h] [rbp-10h]
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+F8h] [rbp-8h]
  Scaleform::GFx::URLBuilder::LocationInfo v96; // [rsp+110h] [rbp+10h]
  Scaleform::File *v97; // [rsp+128h] [rbp+28h]
  Scaleform::GFx::URLBuilder::LocationInfo v98; // [rsp+130h] [rbp+30h]
  Scaleform::GFx::AS3::AvmBitmap *v99; // [rsp+148h] [rbp+48h]
  int v100; // [rsp+150h] [rbp+50h]
  __int64 v101; // [rsp+158h] [rbp+58h]
  int v102; // [rsp+160h] [rbp+60h]
  int v103; // [rsp+164h] [rbp+64h]
  Scaleform::Log *v104; // [rsp+168h] [rbp+68h]
  unsigned __int8 *v105; // [rsp+170h] [rbp+70h]
  __int64 v106; // [rsp+178h] [rbp+78h]
  Scaleform::GFx::MovieImpl *v107; // [rsp+180h] [rbp+80h]
  Scaleform::GFx::MovieDataDef *v108; // [rsp+188h] [rbp+88h]
  Scaleform::GFx::MovieDefImpl *v109; // [rsp+190h] [rbp+90h]
  __int64 v110; // [rsp+198h] [rbp+98h]
  Scaleform::GFx::MovieDataDef *v111; // [rsp+1A0h] [rbp+A0h]
  Scaleform::GFx::MovieDefImpl *v112; // [rsp+1A8h] [rbp+A8h]
  __int64 v113; // [rsp+1B0h] [rbp+B0h]
  __int64 v114; // [rsp+1B8h] [rbp+B8h]
  Scaleform::GFx::AS3::AvmBitmap *v115; // [rsp+1C0h] [rbp+C0h]
  Scaleform::GFx::ImageResource *v116; // [rsp+1C8h] [rbp+C8h]
  Scaleform::GFx::ImageResource *v117; // [rsp+1D0h] [rbp+D0h]
  Scaleform::Render::Image *v118; // [rsp+1D8h] [rbp+D8h]
  char dest; // [rsp+1E0h] [rbp+E0h]
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *bilinear; // [rsp+628h] [rbp+528h]
  void *v121; // [rsp+638h] [rbp+538h]

  v114 = -2i64;
  v3 = pls;
  v4 = pentry;
  v5 = this;
  if ( !pentry->Canceled )
  {
    if ( pentry->Type & 0x24 )
    {
      v6 = 0;
      Scaleform::String::String(&pdata);
      bilinear = &binaryData;
      v7 = 0i64;
      binaryData.Data.Data = 0i64;
      binaryData.Data.Size = 0i64;
      binaryData.Data.Policy.Capacity = 0i64;
      pfileLen = 0;
      Scaleform::String::String(&ppath);
      v8 = v5->pMovieImpl;
      if ( !v8->pMainMovie
        || (v9 = (const char *)((__int64 (*)(void))v8->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(),
            Scaleform::String::operator=(&ppath, v9),
            !Scaleform::GFx::URLBuilder::ExtractFilePath(&ppath)) )
      {
        Scaleform::String::Clear(&ppath);
      }
      loc.Use = 4;
      Scaleform::String::String(&loc.FileName, &v4->URL);
      Scaleform::String::String(&loc.ParentPath, &ppath);
      Scaleform::String::String(&pdest);
      Scaleform::GFx::LoadStates::BuildURL(v3, &pdest, &loc);
      v10 = 0i64;
      v97 = 0i64;
      bilinear = (Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)&v92;
      v92 = 0i64;
      v93 = 0i64;
      v94 = 0i64;
      if ( Scaleform::GFx::URLBuilder::IsProtocol(&pdest)
        || (v10 = Scaleform::GFx::LoadStates::OpenFile(
                    v3,
                    (const char *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                    0),
            (v97 = v10) == 0i64) )
      {
        Scaleform::SFsprintf(&dest, 0x400ui64, "Cant open %s", (pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteErrorEvent(
          (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v4[1].pNext,
          &dest);
        v6 = 1;
      }
      else
      {
        v11 = v4[1].pNext;
        if ( !strcmp((const char *)v11[3].vfptr->__vecDelDtor, "variables") )
        {
          Scaleform::GFx::MovieImpl::ReadTextData(&pdata, v10, &pfileLen, 1);
        }
        else
        {
          v12 = 0i64;
          while ( 1 )
          {
            v13 = *((_BYTE *)v11[3].vfptr->__vecDelDtor + v12++);
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
            v15 = *((_BYTE *)v11[3].vfptr->__vecDelDtor + v14++);
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
      bilinear = (Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)&v92;
      if ( v92 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      if ( v10 )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      if ( !_InterlockedDecrement((volatile signed __int32 *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      if ( !v6 )
      {
        v16 = v4[1].pNext;
        if ( !strcmp((const char *)v16[3].vfptr->__vecDelDtor, "variables") )
        {
          Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetVariablesDataString(
            (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v16,
            (const char *)((pdata.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        }
        else
        {
          v17 = 0i64;
          while ( 1 )
          {
            v18 = *((_BYTE *)v16[3].vfptr->__vecDelDtor + v17++);
            if ( v18 != aText_0[v17 - 1] )
              break;
            if ( v17 == 5 )
            {
              Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetTextString(
                (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v16,
                (const char *)((pdata.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
              goto LABEL_41;
            }
          }
          while ( 1 )
          {
            v19 = *((_BYTE *)v16[3].vfptr->__vecDelDtor + v7++);
            if ( v19 != aBinary_0[v7 - 1] )
              break;
            if ( v7 == 7 )
            {
              Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetBinaryData(
                (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v16,
                &binaryData);
              break;
            }
          }
        }
LABEL_41:
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteOpenEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v4[1].pNext);
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteProgressEvent(
          (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v4[1].pNext,
          pfileLen,
          pfileLen);
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteCompleteEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v4[1].pNext);
      }
      v121 = &binaryData;
      if ( binaryData.Data.Data )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v20 = pdata.pData;
      goto LABEL_192;
    }
    Scaleform::String::String(&url, &pentry->URL);
    Scaleform::String::String(&src);
    v21 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)v3->pLog.pObject;
    v22 = 0i64;
    v23 = 0i64;
    v73 = 0i64;
    v24 = v5->pMovieImpl;
    LODWORD(v75) = v24->pMainMovieDef.pObject->pBindData.pObject->LoadFlags;
    v25 = v24->pMainMovie;
    if ( v25 )
    {
      v26 = ((__int64 (*)(void))v25->vfptr[66].__vecDelDtor)();
      if ( ((*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v26 + 88i64))(v26) >> 4) & 1 )
      {
        v27 = Scaleform::GFx::GetUrlStrGfx(&result, &url);
        Scaleform::String::operator=(&src, v27);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v23 = (Scaleform::GFx::MovieDefImpl *)v73;
      }
    }
    LOBYTE(bilinear) = 0;
    LOBYTE(v121) = Scaleform::GFx::LoaderImpl::IsProtocolImage(&url, (bool *)&bilinear, 0i64);
    if ( (_BYTE)v121 )
    {
      v80 = (Scaleform::GFx::MovieDefImpl *)Scaleform::GFx::LoadStates::GetImageCreator(v3);
      if ( !v80 )
      {
        if ( v21 )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
            v21 + 3,
            "ImageCreator is not installed, failed to load image \"%s\"",
            (url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
        Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
          (Scaleform::GFx::AS3::Instances::fl_display::Loader *)v4[1].vfptr,
          (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        goto LABEL_106;
      }
      v28 = (__int64)v5->pMovieImpl->pHeap;
      v100 = 0;
      v101 = v28;
      v102 = 1;
      v103 = 1;
      v104 = 0i64;
      v105 = 0i64;
      v106 = 0i64;
      v107 = 0i64;
      v29 = (__int64)v3->pImageFileHandlerRegistry.pObject;
      v30 = (unsigned __int8 *)v3->pBindStates.pObject->pFileOpener.pObject;
      v75 = (unsigned __int8 *)v3->pBindStates.pObject->pFileOpener.pObject;
      v31 = v3->pLog.pObject;
      if ( v31 )
      {
        v32 = v31->pLog.pObject;
        if ( !v32 )
        {
          v32 = Scaleform::Log::GetGlobalLog();
          v30 = v75;
        }
      }
      else
      {
        v32 = 0i64;
      }
      v105 = v30;
      v104 = v32;
      v106 = v29;
      v107 = v5->pMovieImpl;
      Scaleform::String::String(&v87, (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      v34 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *, int *, Scaleform::String *))v80->vfptr->GetKey)(
                                          v80,
                                          &v100,
                                          &v87);
      v80 = (Scaleform::GFx::MovieDefImpl *)v34;
      v118 = v34;
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v87.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      if ( !v34 )
      {
        if ( v21 )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
            v21 + 3,
            "ImageCreator::LoadProtocolImage failed to load image \"%s\"",
            (url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
        Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
          (Scaleform::GFx::AS3::Instances::fl_display::Loader *)v4[1].vfptr,
          (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        goto LABEL_189;
      }
      v75 = (unsigned __int8 *)v5->pMovieImpl->pHeap;
      v35 = (Scaleform::GFx::ImageResource *)(*(__int64 (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v75 + 80i64))(
                                               v33,
                                               104i64);
      v117 = v35;
      if ( v35 )
      {
        Scaleform::GFx::ImageResource::ImageResource(v35, v34, Use_Bitmap);
        v37 = v36;
      }
      else
      {
        v37 = 0i64;
      }
      v116 = v37;
      if ( v37 )
      {
        v23 = Scaleform::GFx::MovieImpl::CreateImageMovieDef(
                v5->pMovieImpl,
                v37,
                (bool)bilinear,
                (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                v3);
        v73 = (Scaleform::GFx::Resource *)&v23->vfptr;
      }
      else
      {
        v23 = (Scaleform::GFx::MovieDefImpl *)v73;
      }
      if ( v37 )
        Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&v37->vfptr);
      ((void (*)(void))v80->vfptr->GetResourceTypeCode)();
    }
    else
    {
      v38 = (unsigned int)v75 | 0x10001;
      if ( v4->QuietOpen )
        v38 = (unsigned int)v75 | 0x210001;
      v39 = (Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)v4[1].URL.pData;
      if ( v39 )
      {
        v23 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v3, v39, v38, 0i64, 0i64);
        v73 = (Scaleform::GFx::Resource *)&v23->vfptr;
      }
      else
      {
        Scaleform::String::String(&v76);
        v40 = v5->pMovieImpl;
        if ( !v40->pMainMovie
          || (v41 = (const char *)((__int64 (*)(void))v40->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(),
              Scaleform::String::operator=(&v76, v41),
              !Scaleform::GFx::URLBuilder::ExtractFilePath(&v76)) )
        {
          Scaleform::String::Clear(&v76);
        }
        if ( !Scaleform::String::GetLength(&src) )
          goto LABEL_196;
        v96.Use = 3;
        Scaleform::String::String(&v96.FileName, &src);
        Scaleform::String::String(&v96.ParentPath, &v76);
        v80 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v3, &v96, v38, 0i64);
        v73 = (Scaleform::GFx::Resource *)&v80->vfptr;
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v96.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                              + 8)) )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v96.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        if ( !v80 )
        {
LABEL_196:
          v98.Use = 3;
          Scaleform::String::String(&v98.FileName, &url);
          Scaleform::String::String(&v98.ParentPath, &v76);
          v73 = (Scaleform::GFx::Resource *)Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v3, &v98, v38, 0i64);
          if ( !_InterlockedDecrement((volatile signed __int32 *)((v98.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                                + 8)) )
            ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          if ( !_InterlockedDecrement((volatile signed __int32 *)((v98.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                                + 8)) )
            ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        }
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v76.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v23 = (Scaleform::GFx::MovieDefImpl *)v73;
      }
      if ( !v23 )
      {
        if ( v21 && !v4->QuietOpen )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
            v21 + 3,
            "Failed loading URL \"%s\"",
            (url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
        Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
          (Scaleform::GFx::AS3::Instances::fl_display::Loader *)v4[1].vfptr,
          (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        v71 = v4[2].vfptr;
        if ( v71 )
          (*((void (__cdecl **)(Scaleform::GFx::LoadQueueEntryVtbl *))v71->__vecDelDtor + 3))(v71);
        goto LABEL_189;
      }
      if ( ((unsigned int (__fastcall *)(Scaleform::GFx::MovieDefImpl *))v23->vfptr[1].__vecDelDtor)(v23) != -1
        && (((unsigned int (__fastcall *)(Scaleform::GFx::MovieDefImpl *))v23->vfptr[1].__vecDelDtor)(v23) < 9
         || (char)((v23->pBindData.pObject->pDataDef.pObject->pData.pObject->FileAttributes & 8 | 0x10) >> 3) < 3) )
      {
        if ( v21 && !v4->QuietOpen )
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
            v21 + 3,
            "Failed loading SWF \"%s\": ActionScript version mismatch",
            (url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
        Scaleform::GFx::AS3::Instances::fl_display::Loader::ExecuteErrorEvent(
          (Scaleform::GFx::AS3::Instances::fl_display::Loader *)v4[1].vfptr,
          (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
        v42 = v4[2].vfptr;
        if ( v42 )
          (*((void (__cdecl **)(Scaleform::GFx::LoadQueueEntryVtbl *))v42->__vecDelDtor + 3))(v42);
        Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&v23->vfptr);
        v73 = 0i64;
        goto LABEL_189;
      }
    }
    if ( v23 )
      Scaleform::GFx::AS3::MovieRoot::AddLoadedMovieDef(v5, v23);
LABEL_106:
    v43 = (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v4[1].vfptr[14].__vecDelDtor;
    if ( v43 )
      Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteOpenEvent(v43);
    v44 = v4[2].vfptr;
    if ( v44 )
      (*((void (__cdecl **)(Scaleform::GFx::LoadQueueEntryVtbl *))v44->__vecDelDtor + 1))(v44);
    v75 = (unsigned __int8 *)v4[1].vfptr[11].__vecDelDtor;
    v86 = 0i64;
    if ( v23 && (v45 = v23->pBindData.pObject, v45->pDataDef.pObject->MovieType == 2) )
    {
      v108 = v45->pDataDef.pObject;
      v109 = v23;
      v110 = 0i64;
      v46 = v5->pASSupport.pObject;
      v84 = 0x40000;
      v47 = (Scaleform::GFx::AS3::AvmBitmap *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::MovieDataDef **, _QWORD, int *, signed int))v46->vfptr[4].__vecDelDtor)(
                                                v46,
                                                v5->pMovieImpl,
                                                &v108,
                                                0i64,
                                                &v84,
                                                8);
      v115 = v47;
      phandle.HType = 0;
      phandle.pResource = 0i64;
      v48 = v23->pBindData.pObject->pDataDef.pObject;
      rid.Id = 0;
      if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
             v48->pData.pObject,
             &phandle,
             (Scaleform::GFx::ResourceId)&rid) )
      {
        v49 = Scaleform::GFx::ResourceHandle::GetResource(&phandle, &v23->pBindData.pObject->ResourceBinding);
        v50 = (Scaleform::GFx::ImageResource *)v49;
        if ( v49 )
        {
          if ( (v49->vfptr->GetResourceTypeCode(v49) & 0xFF00) == 256 )
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
        v52 = v51->pAS3RawPtr;
        if ( !v52 )
          v52 = v51->pAS3CollectiblePtr.pObject;
        if ( (unsigned __int8)v52 & 1 )
          v52 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v52 - 1);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v52->pLoaderInfo,
          (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4[1].vfptr[14].__vecDelDtor);
        Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(v51, 1);
      }
      if ( v75 )
      {
        v53 = (*(__int64 (**)(void))(*(_QWORD *)&v75[4 * v75[109]] + 40i64))();
        if ( v53 )
          v22 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v53 - 72);
      }
      Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(v22, (Scaleform::GFx::DisplayObjectBase *)&v47->vfptr);
      if ( v47 )
        ++v47->RefCount;
      v86 = v47;
      if ( phandle.HType == RH_Pointer && phandle.pResource )
        Scaleform::GFx::Resource::Release(phandle.pResource);
    }
    else
    {
      v47 = 0i64;
      v99 = 0i64;
      if ( v23 )
      {
        v54 = v5->pAVM.pObject;
        if ( v54 )
          Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(v54->GC.GC, v5->pMovieImpl->AdvanceStats.pObject, 0);
        v55 = v23->pBindData.pObject->pDataDef.pObject->pData.pObject;
        v56 = v55->Header.FileLength;
        v57 = v55->Header.FileLength;
        v58 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)v4[1].vfptr[14].__vecDelDtor;
        if ( v58 )
          Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteProgressEvent(v58, v57, v56);
        v111 = v23->pBindData.pObject->pDataDef.pObject;
        v112 = v23;
        v113 = 0i64;
        v59 = v5->pASSupport.pObject;
        v83 = 0;
        v47 = (Scaleform::GFx::AS3::AvmBitmap *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::MovieDataDef **, _QWORD, int *, signed int))v59->vfptr[4].__vecDelDtor)(
                                                  v59,
                                                  v5->pMovieImpl,
                                                  &v111,
                                                  0i64,
                                                  &v83,
                                                  3);
        v99 = v47;
        Scaleform::GFx::Sprite::SetLoadedSeparately((Scaleform::GFx::Sprite *)v47, 1);
        v47->Flags |= 1u;
        ((void (__fastcall *)(Scaleform::GFx::AS3::AvmBitmap *))v47->vfptr[73].__vecDelDtor)(v47);
        Scaleform::GFx::InteractiveObject::AddToPlayList((Scaleform::GFx::InteractiveObject *)v47);
        v60 = (Scaleform::GFx::AS3::AvmDisplayObj *)((char *)v47 + 4 * (unsigned __int8)v47->AvmObjOffset);
        v61 = v4[1].vfptr;
        if ( v61 )
        {
          v62 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)v61[14].__vecDelDtor;
          if ( v62 )
          {
            Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::applicationDomainGet(v62, &v82);
            if ( v82.pObject && Scaleform::GFx::AS3::VMAppDomain::Enabled )
              v60->AppDomain = v82.pObject->VMDomain.pObject;
            v63 = v82.pObject;
            if ( v82.pObject )
            {
              if ( (_QWORD)v82.pObject & 1 )
              {
                --v82.pObject;
              }
              else
              {
                v64 = v82.pObject->RefCount;
                if ( v64 & 0x3FFFFF )
                {
                  v82.pObject->RefCount = v64 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v63->vfptr);
                }
              }
            }
          }
        }
        ((void (__fastcall *)(Scaleform::GFx::AS3::AvmDisplayObj *, _QWORD))v60->vfptr[2].ToAvmButttonBase)(v60, 0i64);
        ((void (__fastcall *)(Scaleform::GFx::AS3::AvmBitmap *))v47->vfptr[39].__vecDelDtor)(v47);
        if ( !v60->pAS3RawPtr
          && !v60->pAS3CollectiblePtr.pObject
          && Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(v60) )
        {
          v65 = v60->pAS3RawPtr;
          if ( !v65 )
            v65 = v60->pAS3CollectiblePtr.pObject;
          if ( (unsigned __int8)v65 & 1 )
            v65 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v65 - 1);
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v65->pLoaderInfo,
            (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4[1].vfptr[14].__vecDelDtor);
          Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(v60, 1);
        }
        if ( v75 )
        {
          v66 = (*(__int64 (**)(void))(*(_QWORD *)&v75[4 * v75[109]] + 40i64))();
          if ( v66 )
            v22 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v66 - 72);
        }
        Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(v22, (Scaleform::GFx::DisplayObjectBase *)&v47->vfptr);
        v5->vfptr[39].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)v47);
        Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Sprite>((Scaleform::GFx::InteractiveObject *)v47);
      }
      if ( v47 )
        ((void (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *))v5->vfptr[7].__vecDelDtor)(v5);
      if ( v47 )
        ++v47->RefCount;
      v86 = v47;
    }
    if ( v47 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v47->vfptr);
    if ( (_BYTE)v121 )
    {
      v68 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)v4[1].vfptr[14].__vecDelDtor;
      if ( v68 )
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteInitEvent(
          v68,
          (Scaleform::GFx::DisplayObject *)&v47->vfptr);
      v69 = v4[2].vfptr;
      if ( v69 )
        (*((void (__cdecl **)(Scaleform::GFx::LoadQueueEntryVtbl *))v69->__vecDelDtor + 2))(v69);
      v70 = (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v4[1].vfptr[14].__vecDelDtor;
      if ( v70 )
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteCompleteEvent(v70);
    }
    else
    {
      v121 = &pnLoadInitCL;
      v67 = (Scaleform::GFx::Resource *)v4[2].vfptr;
      if ( v67 )
        Scaleform::Render::RenderBuffer::AddRef(v67);
      pnLoadInitCL.pObject = (Scaleform::GFx::AS3::NotifyLoadInitC *)v4[2].vfptr;
      Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueInitEvent(
        (Scaleform::GFx::AS3::Instances::fl_display::Loader *)v4[1].vfptr,
        (Scaleform::GFx::DisplayObject *)&v47->vfptr,
        (Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC>)&pnLoadInitCL);
      Scaleform::GFx::AS3::Instances::fl_display::Loader::QueueCompleteEvent((Scaleform::GFx::AS3::Instances::fl_display::Loader *)v4[1].vfptr);
    }
    if ( v47 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v47->vfptr);
    if ( v23 )
      Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&v23->vfptr);
LABEL_189:
    if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v20 = url.pData;
LABEL_192:
    if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v20 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 4003
// RVA: 0x80A0B0
void __fastcall Scaleform::GFx::AS3::MovieRoot::ProcessLoadVarsMT(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::LoadQueueEntry *pentry, Scaleform::GFx::LoadStates *__formal, Scaleform::String *data, unsigned __int64 fileLen, bool succeeded)
{
  Scaleform::String *v6; // rsi
  Scaleform::GFx::LoadQueueEntry *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v8; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *v9; // rcx
  unsigned int v10; // eax
  Scaleform::GFx::LoadQueueEntry *v11; // rdi
  __int64 v12; // rax
  char v13; // dl
  Scaleform::String punescapedStr; // [rsp+20h] [rbp-418h]
  __int64 v15; // [rsp+28h] [rbp-410h]
  char dest; // [rsp+30h] [rbp-408h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> result; // [rsp+448h] [rbp+10h]

  v15 = -2i64;
  v6 = data;
  v7 = pentry;
  if ( succeeded )
  {
    v11 = pentry[1].pNext;
    if ( !strcmp((const char *)v11[3].vfptr->__vecDelDtor, "variables") )
    {
      Scaleform::String::String(&punescapedStr);
      Scaleform::GFx::ASUtils::Unescape(
        (const char *)((v6->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        *(_QWORD *)(v6->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
        &punescapedStr);
      Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetVariablesDataString(
        (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v7[1].pNext,
        (const char *)((punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      if ( !_InterlockedDecrement((volatile signed __int32 *)((punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    else
    {
      v12 = 0i64;
      while ( 1 )
      {
        v13 = *((_BYTE *)v11[3].vfptr->__vecDelDtor + v12++);
        if ( v13 != aText_0[v12 - 1] )
          break;
        if ( v12 == 5 )
        {
          Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetTextString(
            (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v11,
            (const char *)((v6->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
          break;
        }
      }
    }
    Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteOpenEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v7[1].pNext);
    Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteProgressEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v7[1].pNext,
      fileLen,
      fileLen);
    Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteCompleteEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v7[1].pNext);
  }
  else
  {
    Scaleform::SFsprintf(&dest, 0x400ui64, "Cant open %s", **(_QWORD **)(*(_QWORD *)&pentry[1].Type + 56i64));
    v8 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v7[1].pNext;
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateIOErrorEventObject(v8, &result, &dest);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v8);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
      v8,
      (Scaleform::GFx::AS3::Instances::fl_events::Event *)&result.pObject->vfptr,
      0);
    v9 = result.pObject;
    if ( result.pObject )
    {
      if ( (_QWORD)result.pObject & 1 )
      {
        --result.pObject;
      }
      else
      {
        v10 = result.pObject->RefCount;
        if ( v10 & 0x3FFFFF )
        {
          result.pObject->RefCount = v10 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr);
        }
      }
    }
  }
}

// File Line: 4036
// RVA: 0x809190
void __fastcall Scaleform::GFx::AS3::MovieRoot::ProcessLoadBinaryMT(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::LoadQueueEntry *pentry, Scaleform::GFx::LoadStates *__formal, Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *data, unsigned __int64 fileLen, bool succeeded)
{
  Scaleform::GFx::LoadQueueEntry *v6; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *v8; // rcx
  unsigned int v9; // eax
  char dest; // [rsp+30h] [rbp-408h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> result; // [rsp+448h] [rbp+10h]

  v6 = pentry;
  if ( succeeded )
  {
    Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetBinaryData(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext,
      data);
    Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteOpenEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v6[1].pNext);
    Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteProgressEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v6[1].pNext,
      fileLen,
      fileLen);
    Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteCompleteEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)v6[1].pNext);
  }
  else
  {
    Scaleform::SFsprintf(&dest, 0x400ui64, "Cant open %s", **(_QWORD **)(*(_QWORD *)&pentry[1].Type + 56i64), -2i64);
    v7 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v6[1].pNext;
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateIOErrorEventObject(v7, &result, &dest);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
      v7,
      (Scaleform::GFx::AS3::Instances::fl_events::Event *)&result.pObject->vfptr,
      0);
    v8 = result.pObject;
    if ( result.pObject )
    {
      if ( (_QWORD)result.pObject & 1 )
      {
        --result.pObject;
      }
      else
      {
        v9 = result.pObject->RefCount;
        if ( v9 & 0x3FFFFF )
        {
          result.pObject->RefCount = v9 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
        }
      }
    }
  }
}

// File Line: 4105
// RVA: 0x828A80
void __fastcall Scaleform::GFx::AS3::MovieRoot::UnloadMovie(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::Instances::fl_display::Loader *ploader, bool stop, bool gc)
{
  bool v4; // r15
  Scaleform::GFx::AS3::Instances::fl_display::Loader *v5; // r14
  Scaleform::GFx::AS3::MovieRoot *v6; // r12
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v7; // r13
  unsigned __int8 *v8; // rdi
  Scaleform::RefCountNTSImpl *v9; // rax
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::AS3::Instances::fl_events::Event *v13; // rsi
  Scaleform::GFx::DisplayObject *v14; // rbx
  Scaleform::GFx::AS3::VMAppDomain *v15; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> >::TableType *v16; // rax
  Scaleform::GFx::AS3::VM *v17; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v18; // rcx
  unsigned int v19; // eax
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v20; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v21; // rcx
  unsigned int v22; // eax
  Scaleform::GFx::LoadQueueEntryMT *i; // rcx
  Scaleform::GFx::LoadQueueEntry *v24; // rax
  Scaleform::GFx::LoadQueueEntry *j; // rcx
  Scaleform::GFx::ASStringNode *v26; // rsi
  Scaleform::GFx::DisplayObjectBase *v27; // rax
  Scaleform::GFx::Resource *v28; // rax
  Scaleform::GFx::MovieDefImpl *v29; // r13
  char v30; // al
  signed __int64 v31; // r12
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *v32; // rcx
  unsigned __int64 v33; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *v34; // rax
  __int64 v35; // r15
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> > *v36; // r15
  unsigned __int64 v37; // r14
  Scaleform::Render::Text::Allocator::TextFormatVisitorVtbl *v38; // rbx
  unsigned __int64 v39; // rdx
  _QWORD *v40; // rcx
  Scaleform::GFx::AS3::Stage *v41; // rcx
  __int64 v42; // rax
  signed __int64 v43; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v44; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::ListenersHash *v45; // r8
  Scaleform::RefCountNTSImpl **v46; // r15
  signed __int64 v47; // r12
  unsigned __int64 v48; // r14
  signed __int64 v49; // rbx
  __int64 v50; // rbx
  signed __int64 v51; // rcx
  __int64 v52; // rax
  __int64 v53; // rax
  Scaleform::RefCountNTSImpl *v54; // rcx
  signed __int64 v55; // rcx
  __int64 v56; // rax
  __int64 v57; // rax
  signed __int64 v58; // rbx
  __int64 v59; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v60; // rcx
  unsigned int v61; // eax
  unsigned int v62; // eax
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v63; // [rsp+38h] [rbp-38h]
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v65; // [rsp+48h] [rbp-28h]
  __int64 v66; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::MovieDefImpl *v67; // [rsp+58h] [rbp-18h]
  Scaleform::Render::Text::Allocator::TextFormatVisitor visitor; // [rsp+60h] [rbp-10h]
  Scaleform::GFx::MovieDefImpl *v69; // [rsp+68h] [rbp-8h]
  Scaleform::GFx::AS3::MovieRoot *v70; // [rsp+B0h] [rbp+40h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> v71; // [rsp+B8h] [rbp+48h]
  bool v72; // [rsp+C8h] [rbp+58h]

  v72 = gc;
  v70 = this;
  v66 = -2i64;
  v4 = stop;
  v5 = ploader;
  v6 = this;
  v7 = ploader->pContentLoaderInfo.pObject;
  v63 = v7;
  v65 = ploader->pContentLoaderInfo.pObject;
  if ( v7 )
    v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
  v8 = 0i64;
  if ( v7 )
  {
    v9 = Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::GetContentDispObj(v7);
    if ( v9 )
    {
      ++v9->RefCount;
      v8 = (unsigned __int8 *)v9;
    }
    v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->BuiltinsMgr.Builtins,
            &result,
            "unload");
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateEventObject(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v7->vfptr,
      &v71,
      v10,
      0,
      0);
    v11 = result.pNode;
    v12 = result.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v13 = v71.pObject;
    v14 = (Scaleform::GFx::DisplayObject *)Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::GetContentDispObj(v7);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v13->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v7->vfptr,
      v13,
      v14);
    v15 = v7->AppDomain.pObject;
    v16 = v15->ClassTraitsSet.Entries.mHash.pTable;
    if ( (!v16 || !v16->EntryCount) && !v15->ChildDomains.Data.Size )
    {
      v17 = v7->pTraits.pObject->pVM;
      if ( !v17->LoadingAbcFile )
        Scaleform::GFx::AS3::VMAppDomain::RemoveChild(v17->SystemDomain.pObject, v15);
    }
    v18 = v71.pObject;
    if ( v71.pObject )
    {
      if ( (_QWORD)v71.pObject & 1 )
      {
        --v71.pObject;
      }
      else
      {
        v19 = v71.pObject->RefCount;
        if ( v19 & 0x3FFFFF )
        {
          v71.pObject->RefCount = v19 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v18->vfptr);
        }
      }
    }
  }
  v20 = v5->pContentLoaderInfo.pObject;
  if ( v20 )
  {
    v21 = v20->Content.pObject;
    if ( v21 )
    {
      if ( (unsigned __int8)v21 & 1 )
      {
        v20->Content.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v21 - 1);
      }
      else
      {
        v22 = v21->RefCount;
        if ( v22 & 0x3FFFFF )
        {
          v21->RefCount = v22 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v21->vfptr);
        }
      }
      v20->Content.pObject = 0i64;
    }
  }
  for ( i = v6->pMovieImpl->pLoadQueueMTHead; i; i = i->pNext )
  {
    v24 = i->pQueueEntry;
    if ( (Scaleform::GFx::AS3::Instances::fl_display::Loader *)v24[1].vfptr == v5 )
      v24->Canceled = 1;
  }
  for ( j = v6->pMovieImpl->pLoadQueueHead; j; j = j->pNext )
  {
    if ( (Scaleform::GFx::AS3::Instances::fl_display::Loader *)j[1].vfptr == v5 )
      j->Canceled = 1;
  }
  v26 = (Scaleform::GFx::ASStringNode *)v5->pDispObj.pObject;
  result.pNode = (Scaleform::GFx::ASStringNode *)v5->pDispObj.pObject;
  if ( !v8 )
  {
    if ( !v26 )
      goto LABEL_132;
    if ( v26[5].RefCount <= 0 )
      goto LABEL_132;
    v27 = Scaleform::GFx::DisplayObjContainer::GetChildAt((Scaleform::GFx::DisplayObjContainer *)v26, 0);
    if ( !v27 )
      goto LABEL_132;
    ++v27->RefCount;
    v8 = (unsigned __int8 *)v27;
  }
  (*(void (__fastcall **)(unsigned __int8 *))(*(_QWORD *)v8 + 600i64))(v8);
  (*(void (__fastcall **)(unsigned __int8 *))(*(_QWORD *)v8 + 480i64))(v8);
  v28 = (Scaleform::GFx::Resource *)(*(__int64 (__fastcall **)(unsigned __int8 *))(*(_QWORD *)v8 + 528i64))(v8);
  v29 = (Scaleform::GFx::MovieDefImpl *)v28;
  if ( v28 )
    Scaleform::Render::RenderBuffer::AddRef(v28);
  v67 = v29;
  if ( v29 )
  {
    v30 = Scaleform::GFx::AS3::MovieRoot::RemoveLoadedMovieDef(v70, v29);
    if ( v4 && v30 )
    {
      v31 = (signed __int64)&v70->mEventChains;
      v32 = v70->mEventChains.Chains.mHash.pTable;
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
        v31 = 0i64;
        v33 = 0i64;
      }
      while ( v31 )
      {
        v35 = *(_QWORD *)v31;
        if ( !*(_QWORD *)v31 || (signed __int64)v33 > *(_QWORD *)(v35 + 8) )
          break;
        v36 = *(Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> > **)(32 * (v33 + 1) + v35);
        if ( v36 )
        {
          v37 = 0i64;
          if ( v36->Data.Size )
          {
            while ( 1 )
            {
              Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
                (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v36->Data.Data[v37],
                (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&v71);
              v38 = (Scaleform::Render::Text::Allocator::TextFormatVisitorVtbl *)v71.pObject;
              if ( v71.pObject )
              {
                ++LODWORD(v71.pObject->_pRCC);
                v38 = (Scaleform::Render::Text::Allocator::TextFormatVisitorVtbl *)v71.pObject;
              }
              visitor.vfptr = v38;
              if ( v71.pObject )
                Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v71.pObject);
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
              if ( v37 >= v36->Data.Size )
                goto LABEL_63;
            }
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
              v36,
              v37);
LABEL_61:
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v38);
            goto LABEL_62;
          }
        }
LABEL_63:
        v39 = *(_QWORD *)(*(_QWORD *)v31 + 8i64);
        if ( (signed __int64)v33 <= (signed __int64)v39 && ++v33 <= v39 )
        {
          v40 = (_QWORD *)(32 * v33 + *(_QWORD *)v31 + 16i64);
          do
          {
            if ( *v40 != -2i64 )
              break;
            ++v33;
            v40 += 4;
          }
          while ( v33 <= v39 );
        }
      }
      v41 = v70->pStage.pObject;
      if ( v41
        && (v42 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v41->vfptr
                                                                              + 4 * (unsigned __int8)v41->AvmObjOffset))[5].__vecDelDtor)()) != 0 )
      {
        v43 = v42 - 72;
      }
      else
      {
        v43 = 0i64;
      }
      v44 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v43 + 16);
      if ( !v44 )
        v44 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)(v43 + 8);
      if ( (unsigned __int8)v44 & 1 )
        v44 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v44 - 1);
      if ( v44 )
      {
        v45 = &v44->pImpl.pObject->CaptureListeners;
        if ( v45 )
        {
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::RemoveListenersForMovieDef(v44, v29, v45);
          Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::RemoveListenersForMovieDef(
            v44,
            v29,
            &v44->pImpl.pObject->Listeners);
        }
      }
      Scaleform::GFx::MovieImpl::ShutdownTimersForMovieDef(v70->pMovieImpl, v29);
      Scaleform::GFx::MovieImpl::UnregisterFonts(v70->pMovieImpl, v29);
      if ( v70->MemContext.pObject->TextAllocator.pObject )
      {
        visitor.vfptr = (Scaleform::Render::Text::Allocator::TextFormatVisitorVtbl *)&`Scaleform::GFx::AS3::MovieRoot::UnloadMovie::`39::TextFormatVisitor::`vftable;
        v69 = v29;
        Scaleform::Render::Text::Allocator::VisitTextFormatCache(
          v70->MemContext.pObject->TextAllocator.pObject,
          &visitor);
        visitor.vfptr = (Scaleform::Render::Text::Allocator::TextFormatVisitorVtbl *)&Scaleform::Render::Text::Allocator::TextFormatVisitor::`vftable;
      }
      v46 = (Scaleform::RefCountNTSImpl **)&v70->mMouseState[0].LastMouseOverObj;
      v47 = 6i64;
      do
      {
        v48 = 0i64;
        if ( *(v46 - 2) )
        {
          do
          {
            v49 = (signed __int64)*(v46 - 3) + 8 * v48;
            if ( *(_QWORD *)v49 )
              ++*(_DWORD *)(*(_QWORD *)v49 + 8i64);
            v50 = *(_QWORD *)v49;
            v71.pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v50;
            if ( !v50 )
              goto LABEL_144;
            v51 = v50 + 4i64 * *(unsigned __int8 *)(v50 + 109);
            v52 = *(_QWORD *)(v51 + 16);
            if ( !v52 )
              v52 = *(_QWORD *)(v51 + 8);
            if ( v52 & 1 )
              --v52;
            if ( v52
              && (v53 = (*(__int64 (**)(void))(**(_QWORD **)(v52 + 40) + 56i64))()) != 0
              && *(Scaleform::GFx::MovieDefImpl **)(*(_QWORD *)(v53 + 152) + 368i64) == v29 )
            {
              if ( *(v46 - 2) == (Scaleform::RefCountNTSImpl *)1 )
              {
                Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                  (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *)v46
                - 1,
                  v46 - 3,
                  0i64);
              }
              else
              {
                v54 = (Scaleform::RefCountNTSImpl *)(&(*(v46 - 3))->vfptr)[v48];
                if ( v54 )
                  Scaleform::RefCountNTSImpl::Release(v54);
                memmove(
                  &(&(*(v46 - 3))->vfptr)[v48],
                  &(*(v46 - 3))->RefCount + 2 * v48,
                  8 * ((_QWORD)*(v46 - 2) - v48) - 8);
                *(v46 - 2) = (Scaleform::RefCountNTSImpl *)((char *)*(v46 - 2) - 1);
              }
            }
            else
            {
LABEL_144:
              ++v48;
            }
            if ( v50 )
              Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v50);
          }
          while ( v48 < (unsigned __int64)*(v46 - 2) );
        }
        if ( *v46 )
        {
          v55 = (signed __int64)*v46 + 4 * *((unsigned __int8 *)&(*v46)[6].RefCount + 5);
          v56 = *(_QWORD *)(v55 + 16);
          if ( !v56 )
            v56 = *(_QWORD *)(v55 + 8);
          if ( v56 & 1 )
            --v56;
          if ( v56 )
          {
            v57 = (*(__int64 (**)(void))(**(_QWORD **)(v56 + 40) + 56i64))();
            if ( v57 )
            {
              if ( *(Scaleform::GFx::MovieDefImpl **)(*(_QWORD *)(v57 + 152) + 368i64) == v29 )
              {
                if ( *v46 )
                  Scaleform::RefCountNTSImpl::Release(*v46);
                *v46 = 0i64;
              }
            }
          }
        }
        v46 += 28;
        --v47;
      }
      while ( v47 );
      v26 = result.pNode;
    }
    v6 = v70;
  }
  v58 = (signed __int64)&v8[4 * v8[109]];
  v59 = *(_QWORD *)(v58 + 16);
  if ( !v59 )
    v59 = *(_QWORD *)(v58 + 8);
  if ( v59 & 1 )
    --v59;
  *(_QWORD *)(v58 + 16) = v59;
  v60 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v58 + 8);
  if ( v60 )
  {
    if ( (unsigned __int8)v60 & 1 )
    {
      *(_QWORD *)(v58 + 8) = (char *)v60 - 1;
    }
    else
    {
      v61 = v60->RefCount;
      if ( v61 & 0x3FFFFF )
      {
        v60->RefCount = v61 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v60);
      }
    }
    *(_QWORD *)(v58 + 8) = 0i64;
  }
  if ( v26 )
  {
    Scaleform::GFx::DisplayList::Clear(
      (Scaleform::GFx::DisplayList *)&v26[5].16,
      (Scaleform::GFx::DisplayObjectBase *)v26);
    _((AMD_HD3D *)v26);
  }
  if ( v29 )
    Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&v29->vfptr);
  v7 = v63;
LABEL_132:
  if ( v72 )
    v6->pAVM.pObject->GC.GC->CollectionScheduledFlags = 10;
  if ( v8 && !((unsigned __int8)v8 & 1) )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v8);
  if ( v7 )
  {
    if ( (unsigned __int8)v7 & 1 )
    {
      v65 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)((char *)v7 - 1);
    }
    else
    {
      v62 = v7->RefCount;
      if ( v62 & 0x3FFFFF )
      {
        v7->RefCount = v62 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v7->vfptr);
      }
    }
  }
}

// File Line: 4205
// RVA: 0x8299C0
bool __fastcall Scaleform::GFx::AS3::MovieRoot::UnloadMovie_::_39_::TextFormatVisitor::Visit(Scaleform::Render::Text::TextFormat *tf, Scaleform::Render::Text::TextFormat *a2)
{
  Scaleform::Render::Text::TextFormat *v2; // rbx
  Scaleform::Render::RenderBuffer *v3; // rax

  v2 = tf;
  v3 = Scaleform::Render::Text::TextFormat::GetFontHandle(a2);
  return !v3 || *(_QWORD *)&v3[1].RefCount != *(_QWORD *)&v2->RefCount;
}

// File Line: 4253
// RVA: 0x805200
void __fastcall Scaleform::GFx::AS3::MovieRoot::OnMovieDefRelease(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::MovieDefImpl *defImpl)
{
  Scaleform::GFx::MovieDefImpl *key; // [rsp+38h] [rbp+10h]

  key = defImpl;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::MovieDefImpl *>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> > *)&this->mMouseState[5].DblClick[11].PrevPosition,
    &key);
}

// File Line: 4258
// RVA: 0x7ADDF0
void __fastcall Scaleform::GFx::AS3::MovieRoot::AddLoadedMovieDef(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::MovieDefImpl *defImpl)
{
  Scaleform::GFx::MovieDefImpl *v2; // rax
  Scaleform::GFx::AS3::MovieRoot *v3; // rbx
  Scaleform::GFx::MovieDefImpl::ReleaseNotifier *v4; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> > *v5; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> >::TableType *v6; // r10
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // r9
  signed __int64 v9; // rcx
  signed __int64 v10; // rdx
  bool v11; // zf
  unsigned __int64 *v12; // rdx
  unsigned __int64 v13; // r8
  signed __int64 v14; // rax
  _DWORD *v15; // rax
  Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeRef key; // [rsp+20h] [rbp-18h]
  int v17; // [rsp+40h] [rbp+8h]
  unsigned __int64 hashValue; // [rsp+48h] [rbp+10h]

  hashValue = (unsigned __int64)defImpl;
  v2 = defImpl;
  v3 = this;
  if ( this )
    v4 = (Scaleform::GFx::MovieDefImpl::ReleaseNotifier *)&this->vfptr;
  else
    v4 = 0i64;
  Scaleform::GFx::MovieDefImpl::AddReleaseNotifier(v2, v4);
  v5 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> > *)&v3->LoadedMovieDefs.mHash.pTable;
  v6 = v3->LoadedMovieDefs.mHash.pTable;
  if ( !v6 )
    goto LABEL_15;
  v7 = v6->SizeMask;
  v8 = hashValue & v6->SizeMask;
  v9 = v8;
  v10 = v8 + 2 * (v8 + 1);
  v11 = *(&v6->EntryCount + v10) == -2i64;
  v12 = &v6->EntryCount + v10;
  if ( v11 || (v7 & v12[1]) != v8 )
    goto LABEL_15;
  while ( 1 )
  {
    v13 = v12[1];
    if ( (v13 & v7) == v8 && v13 == hashValue )
      break;
    v9 = *v12;
    if ( *v12 == -1i64 )
      goto LABEL_15;
    v12 = &v6->EntryCount + v9 + 2 * (v9 + 1);
  }
  if ( v9 >= 0 && (v14 = (signed __int64)v6 + 24 * (v9 + 1)) != 0 && (v15 = (_DWORD *)(v14 + 8)) != 0i64 )
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
      v5,
      v5,
      &key,
      hashValue);
  }
}

// File Line: 4275
// RVA: 0x811E10
char __fastcall Scaleform::GFx::AS3::MovieRoot::RemoveLoadedMovieDef(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::MovieDefImpl *defImpl)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> >::TableType *v2; // r9
  Scaleform::GFx::MovieDefImpl *v3; // rbx
  Scaleform::GFx::AS3::MovieRoot *v4; // rdi
  unsigned __int64 v5; // r11
  unsigned __int64 v6; // r10
  signed __int64 v7; // r8
  unsigned __int64 *v8; // rdx
  unsigned __int64 v9; // rcx
  signed __int64 v10; // rax
  _DWORD *v11; // rax
  bool v12; // zf
  Scaleform::GFx::MovieDefImpl *key; // [rsp+38h] [rbp+10h]

  key = defImpl;
  v2 = this->LoadedMovieDefs.mHash.pTable;
  v3 = defImpl;
  v4 = this;
  if ( !v2 )
    return 0;
  v5 = v2->SizeMask;
  v6 = (unsigned __int64)defImpl & v2->SizeMask;
  v7 = (unsigned __int64)defImpl & v2->SizeMask;
  v8 = &v2[1].EntryCount + 3 * v6;
  if ( *v8 == -2i64 || (v5 & v8[1]) != v6 )
    return 0;
  while ( 1 )
  {
    v9 = v8[1];
    if ( (v9 & v5) == v6 && (Scaleform::GFx::MovieDefImpl *)v9 == v3 )
      break;
    v7 = *v8;
    if ( *v8 == -1i64 )
      return 0;
    v8 = &v2->EntryCount + v7 + 2 * (v7 + 1);
  }
  if ( v7 < 0 )
    return 0;
  v10 = (signed __int64)v2 + 24 * (v7 + 1);
  if ( !v10 )
    return 0;
  v11 = (_DWORD *)(v10 + 8);
  if ( !v11 )
    return 0;
  v12 = (*v11)-- == 1;
  if ( !v12 )
    return 0;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::MovieDefImpl *>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> > *)&v4->LoadedMovieDefs.mHash.pTable,
    &key);
  Scaleform::GFx::MovieDefImpl::RemoveReleaseNotifier(v3, (Scaleform::GFx::MovieDefImpl::ReleaseNotifier *)&v4->vfptr);
  return 1;
}

// File Line: 4292
// RVA: 0x7EEFA0
Scaleform::GFx::DisplayObjContainer *__fastcall Scaleform::GFx::AS3::MovieRoot::GetRootMovie(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::DisplayObject *dobj)
{
  Scaleform::GFx::AS3::MovieRoot *v2; // rbx
  Scaleform::GFx::DisplayObjContainer *result; // rax

  v2 = this;
  if ( !dobj )
    return this->pStage.pObject->pRoot.pObject;
  result = (Scaleform::GFx::DisplayObjContainer *)Scaleform::GFx::AS3::AvmDisplayObj::GetRoot((Scaleform::GFx::AS3::AvmDisplayObj *)((char *)dobj + 4 * (unsigned __int8)dobj->AvmObjOffset));
  if ( !result )
    return v2->pStage.pObject->pRoot.pObject;
  if ( !((result->Flags >> 9) & 1) )
    result = (Scaleform::GFx::DisplayObjContainer *)v2->vfptr[16].__vecDelDtor(
                                                      (Scaleform::RefCountImplCore *)&v2->vfptr,
                                                      (unsigned int)result->pParent);
  return result;
}

// File Line: 4362
// RVA: 0x81A710
void __fastcall Scaleform::GFx::AS3::MovieRoot::SetMouseCursorType(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::ASString *cursor, unsigned int mouseIndex)
{
  unsigned int v3; // ebx
  signed __int64 v4; // rdi
  const char *v5; // r9
  Scaleform::GFx::AS3::MovieRoot *v6; // r11
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
  v5 = cursor->pNode->pData;
  v6 = this;
  v7 = 0i64;
  while ( 1 )
  {
    v8 = v5[v7++];
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
    v10 = v5[v9++];
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
    v12 = v5[v11++];
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
    v14 = v5[v13++];
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
    v4 = (signed __int64)&v6->pMovieImpl->mMouseState[mouseIndex];
  ((void (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, _QWORD, _QWORD))v6->vfptr[3].__vecDelDtor)(v6, mouseIndex, v3);
  *(_DWORD *)(v4 + 64) = v3;
  *(_DWORD *)(v4 + 68) = v3;
}

// File Line: 4379
// RVA: 0x7EC490
void __fastcall Scaleform::GFx::AS3::MovieRoot::GetMouseCursorTypeString(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::ASString *result, unsigned int cursorType)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::RefCountImplCoreVtbl *v4; // rax
  unsigned int v5; // er8
  int v6; // er8
  Scaleform::GFx::ASStringManager *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rdi
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASStringManager *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rdi
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringManager *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rdi
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringManager *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rdi
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASStringManager *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rdi
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASString v24; // [rsp+20h] [rbp-38h]
  Scaleform::GFx::ASString v25; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString v26; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::ASString v27; // [rsp+38h] [rbp-20h]
  __int64 v28; // [rsp+40h] [rbp-18h]
  Scaleform::GFx::ASString resulta; // [rsp+78h] [rbp+20h]

  v28 = -2i64;
  v3 = result;
  v4 = this->vfptr;
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
          v12 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))v4[59].__vecDelDtor)();
          v13 = Scaleform::GFx::ASStringManager::CreateConstString(v12, &v24, "button")->pNode;
          ++v13->RefCount;
          v14 = v3->pNode;
          v10 = v3->pNode->RefCount == 1;
          --v14->RefCount;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v14);
          v3->pNode = v13;
          v11 = v24.pNode;
        }
        else
        {
          v7 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))v4[59].__vecDelDtor)();
          v8 = Scaleform::GFx::ASStringManager::CreateConstString(v7, &resulta, "auto")->pNode;
          ++v8->RefCount;
          v9 = v3->pNode;
          v10 = v3->pNode->RefCount == 1;
          --v9->RefCount;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v9);
          v3->pNode = v8;
          v11 = resulta.pNode;
        }
      }
      else
      {
        v15 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))v4[59].__vecDelDtor)();
        v16 = Scaleform::GFx::ASStringManager::CreateConstString(v15, &v25, "ibeam")->pNode;
        ++v16->RefCount;
        v17 = v3->pNode;
        v10 = v3->pNode->RefCount == 1;
        --v17->RefCount;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
        v3->pNode = v16;
        v11 = v25.pNode;
      }
    }
    else
    {
      v18 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))v4[59].__vecDelDtor)();
      v19 = Scaleform::GFx::ASStringManager::CreateConstString(v18, &v26, "hand")->pNode;
      ++v19->RefCount;
      v20 = v3->pNode;
      v10 = v3->pNode->RefCount == 1;
      --v20->RefCount;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
      v3->pNode = v19;
      v11 = v26.pNode;
    }
  }
  else
  {
    v21 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))v4[59].__vecDelDtor)();
    v22 = Scaleform::GFx::ASStringManager::CreateConstString(v21, &v27, "arrow")->pNode;
    ++v22->RefCount;
    v23 = v3->pNode;
    v10 = v3->pNode->RefCount == 1;
    --v23->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v23);
    v3->pNode = v22;
    v11 = v27.pNode;
  }
  v10 = v11->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
}

// File Line: 4391
// RVA: 0x7EC450
void __fastcall Scaleform::GFx::AS3::MovieRoot::GetMouseCursorType(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::ASString *result, unsigned int mouseIndex)
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
Scaleform::AmpMovieObjectDesc *__fastcall Scaleform::GFx::AS3::MovieRoot::GetDisplayObjectsTree(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v2; // rdi
  Scaleform::AmpMovieObjectDesc *v3; // rbx
  Scaleform::GFx::DisplayObjContainer *v4; // rsi
  Scaleform::GFx::ASStringNode *v5; // rax
  Scaleform::AmpMovieObjectDesc *v6; // rax
  const char ***v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]
  Scaleform::MemoryHeap *v12; // [rsp+48h] [rbp+10h]

  v12 = heap;
  v2 = heap;
  v3 = 0i64;
  v4 = (Scaleform::GFx::DisplayObjContainer *)this->pMovieImpl->pMainMovie;
  if ( v4 )
  {
    v5 = (Scaleform::GFx::ASStringNode *)heap->vfptr->Alloc(heap, 48ui64, 0i64);
    result.pNode = v5;
    if ( v5 )
    {
      Scaleform::AmpMovieObjectDesc::AmpMovieObjectDesc((Scaleform::AmpMovieObjectDesc *)v5);
      v3 = v6;
    }
    v7 = (const char ***)Scaleform::GFx::DisplayObject::GetName((Scaleform::GFx::DisplayObject *)&v4->vfptr, &result);
    Scaleform::String::operator=((Scaleform::String *)&v3->Description.0, **v7);
    v8 = result.pNode;
    v9 = result.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    Scaleform::GFx::DisplayObjContainer::GetChildDescTree(v4, v3, v2);
  }
  return v3;
}

// File Line: 4445
// RVA: 0x8041B0
char __fastcall Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::OnExceedLimit(Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit *this, Scaleform::MemoryHeap *heap, unsigned __int64 overLimit)
{
  Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit *v3; // rbx
  unsigned __int64 v4; // r14
  Scaleform::MemoryHeap *v5; // rdi
  signed __int64 v6; // rax
  unsigned __int64 v7; // r15
  signed __int64 v8; // rbp
  float v9; // xmm0_4
  float v10; // xmm0_4
  signed __int64 v11; // rax
  float v12; // xmm1_4
  unsigned __int64 v13; // rsi
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rdx
  unsigned __int64 v16; // rax
  unsigned __int64 v17; // rcx

  v3 = this;
  v4 = overLimit;
  v5 = heap;
  v6 = heap->vfptr->GetFootprint(heap);
  v7 = v5->Info.Desc.Limit;
  v8 = v6;
  v9 = (float)(signed int)v6;
  if ( v6 < 0 )
    v9 = v9 + 1.8446744e19;
  v10 = v9 * v3->HeapLimitMultiplier;
  v11 = 0i64;
  v12 = v10;
  if ( v10 >= 9.223372e18 )
  {
    v12 = v10 - 9.223372e18;
    if ( (float)(v10 - 9.223372e18) < 9.223372e18 )
      v11 = 0x8000000000000000i64;
  }
  v13 = v4 + v7 + v11 + (unsigned int)(signed int)v12;
  if ( (signed __int64)(v8 - v3->LastCollectionFootprint) < (unsigned int)(signed int)v10 )
  {
    v14 = v3->UserLevelLimit;
    if ( !v14 || v13 <= v14 )
    {
      v15 = v13;
LABEL_17:
      v5->vfptr->SetLimit(v5, v15);
      v3->CurrentLimit = v5->Info.Desc.Limit;
      return 1;
    }
  }
  if ( v3->AllocCount )
  {
    v3->MemContext->ASGC.pObject->CollectionScheduledFlags = 10;
    v3->LastCollectionFootprint = v8;
  }
  else
  {
    Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::Collect(v3, v5);
    v16 = v3->UserLevelLimit;
    if ( v16 && v13 > v16 )
    {
      v17 = v3->LastCollectionFootprint;
      if ( v4 <= v8 - v17 )
      {
        v15 = v3->CurrentLimit;
      }
      else
      {
        v15 = v4 + v7 + v17 - v8;
        v3->CurrentLimit = v15;
      }
      goto LABEL_17;
    }
  }
  return 1;
}

// File Line: 4535
// RVA: 0x7B7690
void __fastcall Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::Collect(Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit *this, Scaleform::MemoryHeap *heap)
{
  Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit *v2; // rdi
  Scaleform::MemoryHeap *v3; // rsi
  Scaleform::Render::Text::Allocator *v4; // rcx
  Scaleform::GFx::AS3::MemoryContextImpl *v5; // rax
  Scaleform::GFx::AS3::ASRefCountCollector *v6; // rbx

  v2 = this;
  v3 = heap;
  v4 = this->MemContext->TextAllocator.pObject;
  if ( v4 )
  {
    Scaleform::Render::Text::Allocator::FlushTextFormatCache(v4, 1);
    Scaleform::Render::Text::Allocator::FlushParagraphFormatCache(v2->MemContext->TextAllocator.pObject, 1);
  }
  v5 = v2->MemContext;
  v6 = v5->ASGC.pObject;
  if ( v6->SuspendCnt )
  {
    v6->CollectionScheduledFlags = 10;
  }
  else
  {
    Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(v5->ASGC.pObject, 0i64, 2u);
    *(_QWORD *)&v6->MaxRootCount = v6->PresetMaxRootCount;
  }
  v2->LastCollectionFootprint = v3->vfptr->GetFootprint(v3);
}

