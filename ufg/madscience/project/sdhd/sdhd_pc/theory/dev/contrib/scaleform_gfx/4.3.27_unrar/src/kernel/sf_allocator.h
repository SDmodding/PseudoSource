// File Line: 322
// RVA: 0x962640
void __fastcall Scaleform::ConstructorMov<Scaleform::Render::Matrix4x4<float>>::Construct(void *p, Scaleform::Render::Matrix4x4<float> *source)
{
  if ( p )
    *(Scaleform::Render::Matrix4x4<float> *)p = *source;
}

// File Line: 334
// RVA: 0x8BDAB0
void __fastcall Scaleform::ConstructorMov<Scaleform::Render::TextureGlyph>::ConstructArray(void *p, unsigned __int64 count)
{
  for ( ; count; --count )
  {
    if ( p )
    {
      *(_QWORD *)p = &Scaleform::RefCountImplCore::`vftable;
      *((_DWORD *)p + 2) = 1;
      *(_QWORD *)p = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)p = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)p = &Scaleform::RefCountBase<Scaleform::Render::TextureGlyph,2>::`vftable;
      *(_QWORD *)p = &Scaleform::Render::TextureGlyph::`vftable;
      *((_QWORD *)p + 2) = 0i64;
      *((_QWORD *)p + 4) = 0i64;
      *((_QWORD *)p + 5) = 0i64;
      *((_DWORD *)p + 14) = -1;
    }
    p = (char *)p + 64;
  }
}

// File Line: 348
// RVA: 0x7B96C0
void __fastcall Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::ConstructArray(void *p, unsigned __int64 count, Scaleform::GFx::AS3::Value *psource)
{
  unsigned __int64 v3; // r10
  _QWORD *v4; // r9
  _QWORD *v5; // rax
  int v6; // ecx
  __int64 v7; // rdx

  if ( count )
  {
    v3 = count;
    v4 = p;
    v5 = (_QWORD *)&psource->value.VNumber;
    do
    {
      if ( v4 )
      {
        *(_DWORD *)v4 = *((_DWORD *)v5 - 4);
        v4[1] = *(v5 - 1);
        v4[2] = *v5;
        v4[3] = v5[1];
        v6 = *(_DWORD *)(v5 - 2) & 0x1F;
        if ( v6 > 9 )
        {
          if ( (*((_DWORD *)v5 - 4) >> 9) & 1 )
          {
            ++*(_DWORD *)*(v5 - 1);
          }
          else if ( v6 == 10 )
          {
            ++*(_DWORD *)(*v5 + 24i64);
          }
          else if ( v6 > 10 )
          {
            if ( v6 <= 15 )
            {
              if ( *v5 )
                *(_DWORD *)(*v5 + 32i64) = (*(_DWORD *)(*v5 + 32i64) + 1) & 0x8FBFFFFF;
            }
            else if ( v6 <= 17 )
            {
              v7 = v5[1];
              if ( v7 )
                *(_DWORD *)(v7 + 32) = (*(_DWORD *)(v7 + 32) + 1) & 0x8FBFFFFF;
            }
          }
        }
      }
      v5 += 4;
      v4 += 4;
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 361
// RVA: 0x6E22D0
void __fastcall Scaleform::ConstructorMov<Scaleform::Render::Text::DocView::ImageSubstitutor::Element>::DestructArray(Scaleform::Render::Text::DocView::ImageSubstitutor::Element *p, unsigned __int64 count)
{
  unsigned __int64 v2; // rdi
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *v3; // rbx
  Scaleform::RefCountNTSImpl *v4; // rcx

  if ( count )
  {
    v2 = count;
    v3 = &p[count - 1];
    do
    {
      v4 = (Scaleform::RefCountNTSImpl *)&v3->pImageDesc.pObject->vfptr;
      if ( v4 )
        Scaleform::RefCountNTSImpl::Release(v4);
      --v3;
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 395
// RVA: 0x6DEFA0
void __fastcall Scaleform::ConstructorCPP<Scaleform::GFx::Value>::Construct(void *p, Scaleform::GFx::Value *source)
{
  Scaleform::GFx::Value *v2; // r8
  _QWORD *v3; // rdx
  Scaleform::GFx::Value::ObjectInterface *v4; // rcx

  v2 = source;
  v3 = p;
  if ( p )
  {
    *((_QWORD *)p + 2) = 0i64;
    *((_DWORD *)p + 6) = v2->Type;
    *((_QWORD *)p + 4) = *(_QWORD *)&v2->mValue.NValue;
    *((_QWORD *)p + 5) = v2->DataAux;
    if ( ((unsigned int)v2->Type >> 6) & 1 )
    {
      v4 = v2->pObjectInterface;
      v3[2] = v4;
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD *, _QWORD))v4->vfptr->gap8)(
        v4,
        v3,
        v3[4]);
    }
  }
}

// File Line: 434
// RVA: 0x7C42E0
void __fastcall Scaleform::ConstructorCPP<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr>::DestructArray(Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *p, unsigned __int64 count)
{
  unsigned __int64 v2; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *v3; // rbx
  Scaleform::GFx::AS3::WeakProxy *v4; // rdx
  bool v5; // zf

  if ( count )
  {
    v2 = count;
    v3 = &p[count - 1];
    do
    {
      if ( (v3->Method.Flags & 0x1F) > 9 )
      {
        if ( (v3->Method.Flags >> 9) & 1 )
        {
          v4 = v3->Method.Bonus.pWeakProxy;
          v5 = v4->RefCount-- == 1;
          if ( v5 )
            ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          v3->Method.Bonus.pWeakProxy = 0i64;
          v3->Method.value.VNumber = 0.0;
          v3->Method.value.VS._2.VObj = 0i64;
          v3->Method.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v3->Method);
        }
      }
      --v3;
      --v2;
    }
    while ( v2 );
  }
}

