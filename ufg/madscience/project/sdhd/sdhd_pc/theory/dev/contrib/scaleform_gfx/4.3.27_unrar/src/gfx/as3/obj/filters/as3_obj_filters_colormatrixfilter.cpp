// File Line: 35
// RVA: 0x1588480
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Array___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D9B0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>>::Method = Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixGet;
  return result;
}

// File Line: 36
// RVA: 0x158F560
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter_1_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl::Array_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D9C0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Array *>::Method = Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixSet;
  return result;
}

// File Line: 37
// RVA: 0x1588450
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter_2_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D9D0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter,2,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter>>::Method = Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::clone;
  return result;
}

// File Line: 45
// RVA: 0x77C160
void __fastcall Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::ColorMatrixFilter(
        Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::Render::Filter *v3; // rdi
  Scaleform::Render::ColorMatrixFilter *v4; // rax
  Scaleform::Render::Filter *v5; // rax
  Scaleform::Render::RenderBuffer *pObject; // rcx

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter::`vftable;
  v3 = 0i64;
  this->FilterData.pObject = 0i64;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::`vftable;
  v4 = (Scaleform::Render::ColorMatrixFilter *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 104i64,
                                                 0i64);
  if ( v4 )
  {
    Scaleform::Render::ColorMatrixFilter::ColorMatrixFilter(v4);
    v3 = v5;
  }
  pObject = (Scaleform::Render::RenderBuffer *)this->FilterData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->FilterData.pObject = v3;
}

// File Line: 52
// RVA: 0x853880
void __fastcall Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixGet(
        Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // rbx
  unsigned __int64 ValueHHighInd; // r8
  Scaleform::Render::Filter *pObject; // r12
  unsigned int v7; // edi
  unsigned __int64 v8; // r14
  Scaleform::GFx::AS3::Value::Extra v9; // xmm8_8
  Scaleform::GFx::AS3::Value::Extra v10; // xmm7_8
  unsigned int v11; // edx
  __int64 v12; // rdx
  float v13; // xmm6_4
  __int64 v14; // rax
  Scaleform::GFx::ASStringNode *VStr; // rcx
  bool v16; // zf
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v20; // rcx
  unsigned int v21; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v22; // rcx
  unsigned int v23; // eax
  unsigned int v24; // eax
  Scaleform::GFx::AS3::Value v; // [rsp+28h] [rbp-58h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Array *v26; // [rsp+C0h] [rbp+40h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+C8h] [rbp+48h] BYREF

  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject->pVM->TraitsArray.pObject->ITraits.pObject);
  pV = resulta.pV;
  v26 = resulta.pV;
  if ( resulta.pV->SA.ValueA.Data.Size < 0x14 )
  {
    if ( resulta.pV->SA.ValueHLowInd <= 0x14 )
    {
      ValueHHighInd = resulta.pV->SA.ValueHHighInd;
      if ( ValueHHighInd > 0x14 )
        Scaleform::GFx::AS3::Impl::SparseArray::CutHash(&resulta.pV->SA, 0x14ui64, ValueHHighInd - 19, 0i64);
    }
    else
    {
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Clear(&resulta.pV->SA.ValueH.mHash);
      pV->SA.ValueHLowInd = 0i64;
      pV->SA.ValueHHighInd = 0i64;
    }
  }
  else
  {
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &resulta.pV->SA.ValueA.Data,
      0x14ui64);
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Clear(&pV->SA.ValueH.mHash);
    pV->SA.ValueHLowInd = 0i64;
    pV->SA.ValueHHighInd = 0i64;
  }
  pV->SA.Length = 20i64;
  pObject = this->FilterData.pObject;
  v7 = 0;
  v8 = 0i64;
  v9.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v.Bonus;
  v10.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v.Bonus;
  do
  {
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    v11 = v7 / 5;
    if ( v7 == 5 * (v7 / 5) && v7 )
    {
      v12 = v11 + 16;
      if ( (unsigned int)v12 >= 0x14 )
        v13 = 0.0;
      else
        v13 = *((float *)&pObject[1].vfptr + v12);
      v.Flags = v.Flags & 0xFFFFFFE0 | 4;
      v.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v9.pWeakProxy;
    }
    else
    {
      v14 = v7 - v11;
      if ( (unsigned int)v14 >= 0x14 )
        v13 = 0.0;
      else
        v13 = *((float *)&pObject[1].vfptr + v14);
      if ( (v.Flags & 0x1F) > 9 )
      {
        switch ( v.Flags & 0x1F )
        {
          case 0xA:
            VStr = v.value.VS._1.VStr;
            v16 = v.value.VS._1.VStr->RefCount-- == 1;
            if ( v16 )
              Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
            break;
          case 0xB:
          case 0xC:
          case 0xD:
          case 0xE:
          case 0xF:
            VObj = v.value.VS._1.VObj;
            if ( !v.value.VS._1.VBool )
              goto LABEL_25;
            --v.value.VS._1.VStr;
            break;
          case 0x10:
          case 0x11:
            VObj = v.value.VS._2.VObj;
            if ( ((__int64)v.value.VS._2.VObj & 1) != 0 )
            {
              --v.value.VS._2.VObj;
            }
            else
            {
LABEL_25:
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
      v.Flags = v.Flags & 0xFFFFFFE0 | 4;
      v.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v10.pWeakProxy;
    }
    v.value.VNumber = v13;
    Scaleform::GFx::AS3::Impl::SparseArray::Set(&pV->SA, v8, &v);
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
      {
        v16 = v.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v16 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v.Bonus, 0, 24);
        v.Flags &= 0xFFFFFDE0;
      }
      else
      {
        switch ( v.Flags & 0x1F )
        {
          case 0xA:
            v19 = v.value.VS._1.VStr;
            v16 = v.value.VS._1.VStr->RefCount-- == 1;
            if ( v16 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v19);
            break;
          case 0xB:
          case 0xC:
          case 0xD:
          case 0xE:
          case 0xF:
            v20 = v.value.VS._1.VObj;
            if ( !v.value.VS._1.VBool )
              goto LABEL_41;
            --v.value.VS._1.VStr;
            break;
          case 0x10:
          case 0x11:
            v20 = v.value.VS._2.VObj;
            if ( ((__int64)v.value.VS._2.VObj & 1) != 0 )
            {
              --v.value.VS._2.VObj;
            }
            else
            {
LABEL_41:
              if ( v20 )
              {
                v21 = v20->RefCount;
                if ( (v21 & 0x3FFFFF) != 0 )
                {
                  v20->RefCount = v21 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    ++v7;
    ++v8;
  }
  while ( v7 < 0x14 );
  if ( &v26 != (Scaleform::GFx::AS3::Instances::fl::Array **)result )
  {
    if ( pV )
      pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
    v22 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v22 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v22 - 1);
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
    result->pObject = pV;
  }
  if ( pV )
  {
    if ( ((unsigned __int8)pV & 1) != 0 )
    {
      v26 = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pV - 1);
    }
    else
    {
      v24 = pV->RefCount;
      if ( (v24 & 0x3FFFFF) != 0 )
      {
        pV->RefCount = v24 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
      }
    }
  }
}

// File Line: 73
// RVA: 0x853EC0
void __fastcall Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixSet(
        Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl::Array *value)
{
  Scaleform::Render::Filter *pObject; // rbp
  unsigned int v4; // edi
  unsigned __int64 v6; // rax
  Scaleform::GFx::AS3::Value *p_DefaultValue; // rax
  signed __int64 Index; // rax
  char *v9; // rax
  float v10; // xmm0_4
  unsigned int v11; // edx
  __int64 v12; // rax
  unsigned __int64 key; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+70h] [rbp+18h] BYREF
  long double v15; // [rsp+78h] [rbp+20h] BYREF

  if ( value )
  {
    pObject = this->FilterData.pObject;
    v4 = 0;
    if ( value->SA.Length )
    {
      v6 = 0i64;
      do
      {
        key = v6;
        if ( v6 >= value->SA.ValueA.Data.Size )
        {
          if ( v6 < value->SA.ValueHLowInd
            || v6 > value->SA.ValueHHighInd
            || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                          &value->SA.ValueH.mHash,
                          &key),
                Index < 0)
            || (v9 = (char *)&value->SA.ValueH.mHash.pTable[2] + 56 * Index) == 0i64
            || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)(v9 + 8)) == 0i64 )
          {
            p_DefaultValue = &value->SA.DefaultValue;
          }
        }
        else
        {
          p_DefaultValue = &value->SA.ValueA.Data.Data[v6];
        }
        if ( !Scaleform::GFx::AS3::Value::Convert2Number(p_DefaultValue, &resulta, &v15)->Result )
          break;
        if ( v4 < 0x14 )
        {
          v10 = v15;
          v11 = v4 / 5;
          if ( v4 % 5 == 4 )
          {
            v10 = v10 * 0.0039215689;
            v12 = v11 + 16;
          }
          else
          {
            v12 = v4 - v11;
          }
          *((float *)&pObject[1].vfptr + v12) = v10;
        }
        v6 = ++v4;
      }
      while ( v4 < value->SA.Length );
    }
  }
}

// File Line: 98
// RVA: 0x82F490
void __fastcall Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::clone(
        Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter> *result)
{
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // rbx
  Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *pV; // rdi
  Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *v6; // rcx
  unsigned int RefCount; // eax
  unsigned int v8; // eax
  Scaleform::GFx::AS3::Value v9; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> v10; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter> resulta; // [rsp+68h] [rbp+10h] BYREF

  Scaleform::GFx::AS3::InstanceTraits::fl_filters::ColorMatrixFilter::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl_filters::ColorMatrixFilter *)this->pTraits.pObject);
  v10.pObject = 0i64;
  v9.Flags = 0;
  v9.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixGet(this, &v10);
  pObject = v10.pObject;
  pV = resulta.pV;
  Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixSet(resulta.pV, &v9, v10.pObject);
  v6 = result->pObject;
  if ( pV != result->pObject )
  {
    if ( v6 )
    {
      if ( ((unsigned __int8)v6 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter *)((char *)v6 - 1);
      }
      else
      {
        RefCount = v6->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v6->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
        }
      }
    }
    result->pObject = pV;
  }
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      v10.pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pObject - 1);
    }
    else
    {
      v8 = pObject->RefCount;
      if ( (v8 & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = v8 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
}

// File Line: 128
// RVA: 0x795770
void __fastcall Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM::Error *v4; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  Scaleform::GFx::AS3::Value::V1U v7; // rax
  const char *pData; // rcx
  Scaleform::GFx::AS3::Value v9; // [rsp+28h] [rbp-30h] BYREF

  if ( argc < 2 )
  {
    if ( argc )
    {
      if ( (argv->Flags & 0x1F) - 12 <= 3 )
      {
        v7 = argv->value.VS._1;
        if ( v7.VStr )
        {
          pData = v7.VStr[1].pData;
          if ( *((_DWORD *)pData + 30) == 7 && (pData[112] & 0x20) == 0 )
          {
            v9.Flags = 0;
            v9.Bonus.pWeakProxy = 0i64;
            Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixSet(
              this,
              &v9,
              (Scaleform::GFx::AS3::Instances::fl::Array *)argv->value.VS._1.VStr);
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v9, 1063, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v4,
      &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)v9.Bonus.pWeakProxy;
    if ( LODWORD(v9.Bonus.pWeakProxy[1].pObject)-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  }
}

// File Line: 182
// RVA: 0x7FF310
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_filters::ColorMatrixFilter::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_filters::ColorMatrixFilter *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_filters::ColorMatrixFilter *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_filters::ColorMatrixFilter::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 204
// RVA: 0x73B1E0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_filters::ColorMatrixFilter::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_filters::ColorMatrixFilterCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_filters::BitmapFilter::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_filters::ColorMatrixFilter::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_filters::ColorMatrixFilterCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_filters::BitmapFilter::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_filters::ColorMatrixFilter::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    result->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
  return result;
}

