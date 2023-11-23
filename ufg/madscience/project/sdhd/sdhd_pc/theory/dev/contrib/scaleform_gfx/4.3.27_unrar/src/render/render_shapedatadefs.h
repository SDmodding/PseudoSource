// File Line: 119
// RVA: 0x77C260
void __fastcall Scaleform::Render::ComplexFill::ComplexFill(Scaleform::Render::ComplexFill *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ComplexFill,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ComplexFill::`vftable;
  this->pImage.pObject = 0i64;
  this->pGradient.pObject = 0i64;
  *(_OWORD *)&this->ImageMatrix.M[0][0] = 0x3F800000ui64;
  this->ImageMatrix.M[1][0] = 0.0;
  *(_QWORD *)&this->ImageMatrix.M[1][1] = 1065353216i64;
  this->ImageMatrix.M[1][3] = 0.0;
  this->FillMode.Fill = 0;
  this->BindIndex = -1;
}

// File Line: 121
// RVA: 0x895130
void __fastcall Scaleform::Render::ComplexFill::ComplexFill(
        Scaleform::Render::ComplexFill *this,
        Scaleform::Render::ComplexFill *o)
{
  Scaleform::Render::Image *pObject; // rcx
  Scaleform::Render::GradientData *v5; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ComplexFill,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ComplexFill::`vftable;
  pObject = o->pImage.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::Image *))pObject->vfptr[1].__vecDelDtor)(pObject);
  this->pImage.pObject = o->pImage.pObject;
  v5 = o->pGradient.pObject;
  if ( v5 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v5);
  this->pGradient.pObject = o->pGradient.pObject;
  this->ImageMatrix.M[0][0] = o->ImageMatrix.M[0][0];
  this->ImageMatrix.M[0][1] = o->ImageMatrix.M[0][1];
  this->ImageMatrix.M[0][2] = o->ImageMatrix.M[0][2];
  this->ImageMatrix.M[0][3] = o->ImageMatrix.M[0][3];
  this->ImageMatrix.M[1][0] = o->ImageMatrix.M[1][0];
  this->ImageMatrix.M[1][1] = o->ImageMatrix.M[1][1];
  this->ImageMatrix.M[1][2] = o->ImageMatrix.M[1][2];
  this->ImageMatrix.M[1][3] = o->ImageMatrix.M[1][3];
  this->FillMode.Fill = o->FillMode.Fill;
  this->BindIndex = o->BindIndex;
}

// File Line: 246
// RVA: 0x821780
void __fastcall Scaleform::Render::ShapeDataInterface::SkipPathData(
        Scaleform::Render::ShapeDataInterface *this,
        Scaleform::Render::ShapePosInfo *pos)
{
  char v4[40]; // [rsp+20h] [rbp-28h] BYREF

  while ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, char *))this->vfptr[9].__vecDelDtor)(
            this,
            pos,
            v4) )
    ;
}

