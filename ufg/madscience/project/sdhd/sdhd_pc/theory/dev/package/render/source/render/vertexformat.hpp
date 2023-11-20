// File Line: 128
// RVA: 0x1A810
void __fastcall Render::vFBXDescriptor::vFBXDescriptor(Render::vFBXDescriptor *this)
{
  Render::vFBXDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.FBX",
    0xEE711E17);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vFBXDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD1,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    0,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TANGENT,
    0,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_COLOR0,
    VERTEX_TYPE_COLOR4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDINDEX,
    VERTEX_TYPE_UBYTE4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDWEIGHT,
    VERTEX_TYPE_UBYTE4N,
    1,
    0i64);
}

// File Line: 164
// RVA: 0x1A700
void __fastcall Render::vFBX2Descriptor::vFBX2Descriptor(Render::vFBX2Descriptor *this)
{
  Render::vFBX2Descriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.FBX2",
    0x5589C78Du);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vFBX2Descriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD1,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_COLOR0,
    VERTEX_TYPE_COLOR4,
    2,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    0,
    3,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TANGENT,
    0,
    3,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDINDEX,
    VERTEX_TYPE_UBYTE4,
    3,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDWEIGHT,
    VERTEX_TYPE_UBYTE4N,
    3,
    0i64);
}

// File Line: 223
// RVA: 0x1A630
void __fastcall Render::vDynamicDescriptor::vDynamicDescriptor(Render::vDynamicDescriptor *this)
{
  Render::vDynamicDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.Dynamic",
    0x64A43DAEu);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vDynamicDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD1,
    VERTEX_TYPE_HALF2,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    0,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TANGENT,
    0,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_COLOR0,
    VERTEX_TYPE_COLOR4,
    0,
    0i64);
}

// File Line: 253
// RVA: 0x1AF40
void __fastcall Render::vSkinnedDescriptor::vSkinnedDescriptor(Render::vSkinnedDescriptor *this)
{
  Render::vSkinnedDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.Skinned",
    0x276B9567u);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vSkinnedDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    0,
    VERTEX_TYPE_FLOAT4,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TANGENT,
    VERTEX_TYPE_BYTE4N,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDINDEX,
    VERTEX_TYPE_UBYTE4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDWEIGHT,
    VERTEX_TYPE_UBYTE4N,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    2,
    0i64);
}

// File Line: 265
// RVA: 0x1BD30
void __fastcall Render::vSkinnedDescriptor::ApplyUserRemapping(Render::vSkinnedDescriptor *this, UFG::qVector4 *vertex_element)
{
  float v2; // xmm1_4

  v2 = vertex_element[3].x;
  if ( v2 <= 0.19611764 )
  {
    v2 = FLOAT_0_19611764;
  }
  else if ( v2 >= 1.0 )
  {
    vertex_element[2].w = 1.0 * vertex_element[2].w;
    return;
  }
  vertex_element[2].w = v2 * vertex_element[2].w;
}

// File Line: 322
// RVA: 0x1AE00
void __fastcall Render::vScreenParticleDescriptor::vScreenParticleDescriptor(Render::vScreenParticleDescriptor *this)
{
  Render::vScreenParticleDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.ScreenParticle",
    0x3D339245u);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vScreenParticleDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD1,
    VERTEX_TYPE_FLOAT4,
    0,
    0i64);
}

// File Line: 341
// RVA: 0x1AAB0
void __fastcall Render::vLightCardDescriptor::vLightCardDescriptor(Render::vLightCardDescriptor *this)
{
  Render::vLightCardDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.LightCard",
    0x6FA1A436u);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vLightCardDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD1,
    VERTEX_TYPE_FLOAT4,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDWEIGHT,
    VERTEX_TYPE_UBYTE4N,
    0,
    0i64);
}

// File Line: 379
// RVA: 0x1AE90
void __fastcall Render::vSkinnedDecalDescriptor::vSkinnedDecalDescriptor(Render::vSkinnedDecalDescriptor *this)
{
  Render::vSkinnedDecalDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.SkinnedDecal",
    0x23F36527u);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vSkinnedDecalDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    0,
    VERTEX_TYPE_FLOAT4,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TANGENT,
    VERTEX_TYPE_BYTE4N,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    0,
    0i64);
}

// File Line: 399
// RVA: 0x1BBB0
void __fastcall Render::vVehicleUVNTDescriptor::vVehicleUVNTDescriptor(Render::vVehicleUVNTDescriptor *this)
{
  Render::vVehicleUVNTDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.VehicleUVNTC",
    0xE234EF7A);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vVehicleUVNTDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    0,
    VERTEX_TYPE_FLOAT4,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TANGENT,
    VERTEX_TYPE_BYTE4N,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDINDEX,
    VERTEX_TYPE_UBYTE4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDWEIGHT,
    VERTEX_TYPE_UBYTE4N,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    2,
    0i64);
}

// File Line: 423
// RVA: 0x1BAC0
void __fastcall Render::vVehicleUV2NTDescriptor::vVehicleUV2NTDescriptor(Render::vVehicleUV2NTDescriptor *this)
{
  Render::vVehicleUV2NTDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.VehicleUV2NTC",
    0xBF900E9E);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vVehicleUV2NTDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    0,
    VERTEX_TYPE_FLOAT4,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TANGENT,
    VERTEX_TYPE_BYTE4N,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDINDEX,
    VERTEX_TYPE_UBYTE4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDWEIGHT,
    VERTEX_TYPE_UBYTE4N,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    2,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD1,
    VERTEX_TYPE_HALF2,
    2,
    0i64);
}

// File Line: 449
// RVA: 0x1B9B0
void __fastcall Render::vVehicleGlassUV2NTCDescriptor::vVehicleGlassUV2NTCDescriptor(Render::vVehicleGlassUV2NTCDescriptor *this)
{
  Render::vVehicleGlassUV2NTCDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.VehicleGlassUV2NTC",
    0xD08FF31A);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vVehicleGlassUV2NTCDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    0,
    VERTEX_TYPE_FLOAT4,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TANGENT,
    VERTEX_TYPE_BYTE4N,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDINDEX,
    VERTEX_TYPE_UBYTE4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDWEIGHT,
    VERTEX_TYPE_UBYTE4N,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    2,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD1,
    VERTEX_TYPE_HALF2,
    2,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_COLOR0,
    VERTEX_TYPE_COLOR4,
    2,
    0i64);
}

// File Line: 475
// RVA: 0x1B020
void __fastcall Render::vSkinnedUVNTDescriptor::vSkinnedUVNTDescriptor(Render::vSkinnedUVNTDescriptor *this)
{
  Render::vSkinnedUVNTDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.SkinnedUVNT",
    0xAC5D89E2);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vSkinnedUVNTDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    0,
    VERTEX_TYPE_FLOAT4,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TANGENT,
    VERTEX_TYPE_BYTE4N,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDINDEX,
    VERTEX_TYPE_UBYTE4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDWEIGHT,
    VERTEX_TYPE_UBYTE4N,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    2,
    0i64);
}

// File Line: 499
// RVA: 0x1B1B0
void __fastcall Render::vUV2Descriptor::vUV2Descriptor(Render::vUV2Descriptor *this)
{
  Render::vUV2Descriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.UV2",
    0x27C88915u);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUV2Descriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD1,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
}

// File Line: 510
// RVA: 0x1B3C0
void __fastcall Render::vUV2NTCDescriptor::vUV2NTCDescriptor(Render::vUV2NTCDescriptor *this)
{
  Render::vUV2NTCDescriptor *v1; // rbx
  UFG::qVector4 default_value; // [rsp+38h] [rbp-20h]

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.UV2NTC",
    0x78921EA0u);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUV2NTCDescriptor::`vftable;
  *(_QWORD *)&default_value.x = 0i64;
  default_value.z = 0.0;
  LODWORD(default_value.w) = (_DWORD)FLOAT_1_0;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD1,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TANGENT,
    VERTEX_TYPE_BYTE4N,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_COLOR0,
    VERTEX_TYPE_COLOR4,
    1,
    &default_value);
}

// File Line: 531
// RVA: 0x1B4C0
void __fastcall Render::vUV2NTDescriptor::vUV2NTDescriptor(Render::vUV2NTDescriptor *this)
{
  Render::vUV2NTDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.UV2NT",
    0xA0B0781E);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUV2NTDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD1,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TANGENT,
    VERTEX_TYPE_BYTE4N,
    1,
    0i64);
}

// File Line: 550
// RVA: 0x1B250
void __fastcall Render::vUV2NCDescriptor::vUV2NCDescriptor(Render::vUV2NCDescriptor *this)
{
  Render::vUV2NCDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.UV2NC",
    0xF2E6F36B);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUV2NCDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD1,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_COLOR0,
    VERTEX_TYPE_COLOR4,
    1,
    0i64);
}

// File Line: 570
// RVA: 0x1B310
void __fastcall Render::vUV2NDescriptor::vUV2NDescriptor(Render::vUV2NDescriptor *this)
{
  Render::vUV2NDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.UV2N",
    0x46E52398u);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUV2NDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD1,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    1,
    0i64);
}

// File Line: 588
// RVA: 0x1B810
void __fastcall Render::vUVNTCDescriptor::vUVNTCDescriptor(Render::vUVNTCDescriptor *this)
{
  Render::vUVNTCDescriptor *v1; // rbx
  UFG::qVector4 default_value; // [rsp+38h] [rbp-20h]

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.UVNTC",
    0x911E1A51);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUVNTCDescriptor::`vftable;
  *(_QWORD *)&default_value.x = 0i64;
  default_value.z = 0.0;
  LODWORD(default_value.w) = (_DWORD)FLOAT_1_0;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TANGENT,
    VERTEX_TYPE_BYTE4N,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_COLOR0,
    VERTEX_TYPE_COLOR4,
    1,
    &default_value);
}

// File Line: 608
// RVA: 0x1B900
void __fastcall Render::vUVNTDescriptor::vUVNTDescriptor(Render::vUVNTDescriptor *this)
{
  Render::vUVNTDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.UVNT",
    0x9BA68DBC);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUVNTDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TANGENT,
    VERTEX_TYPE_BYTE4N,
    1,
    0i64);
}

// File Line: 626
// RVA: 0x1B6D0
void __fastcall Render::vUVNDescriptor::vUVNDescriptor(Render::vUVNDescriptor *this)
{
  Render::vUVNDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.UVN",
    0xF2700F96);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUVNDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    1,
    0i64);
}

// File Line: 644
// RVA: 0x1B580
void __fastcall Render::vUVCDescriptor::vUVCDescriptor(Render::vUVCDescriptor *this)
{
  Render::vUVCDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.UVC",
    0xC3BD8945);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUVCDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_COLOR0,
    VERTEX_TYPE_COLOR4,
    1,
    0i64);
}

// File Line: 662
// RVA: 0x1B620
void __fastcall Render::vUVCNPackedDescriptor::vUVCNPackedDescriptor(Render::vUVCNPackedDescriptor *this)
{
  Render::vUVCNPackedDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.UVCNPacked",
    0xF0D9B822);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUVCNPackedDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    0,
    VERTEX_TYPE_HALF4,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_COLOR0,
    VERTEX_TYPE_COLOR4,
    1,
    0i64);
}

// File Line: 670
// RVA: 0x1BD80
void __fastcall Render::vUVCNPackedDescriptor::ApplyUserRemapping(Render::vUVCNPackedDescriptor *this, UFG::qVector4 *vertex_element)
{
  vertex_element->w = 1.0;
}

// File Line: 680
// RVA: 0x1B770
void __fastcall Render::vUVNPackedDescriptor::vUVNPackedDescriptor(Render::vUVNPackedDescriptor *this)
{
  Render::vUVNPackedDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.UVNPacked",
    0x720788F7u);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUVNPackedDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    0,
    VERTEX_TYPE_HALF4,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    1,
    0i64);
}

// File Line: 687
// RVA: 0x1BD90
void __fastcall Render::vUVNPackedDescriptor::ApplyUserRemapping(Render::vUVNPackedDescriptor *this, UFG::qVector4 *vertex_element)
{
  vertex_element[1].w = 1.0;
}

// File Line: 698
// RVA: 0x1B100
void __fastcall Render::vUV2CDescriptor::vUV2CDescriptor(Render::vUV2CDescriptor *this)
{
  Render::vUV2CDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.UV2C",
    0x7728A54Bu);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUV2CDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD1,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_COLOR0,
    VERTEX_TYPE_COLOR4,
    1,
    0i64);
}

// File Line: 706
// RVA: 0x1BD70
void __fastcall Render::vUV2NTCDescriptor::ApplyUserRemapping(Render::vUVNTDescriptor *this, UFG::qVector4 *vertex_element)
{
  vertex_element[1].w = vertex_element[3].w;
}

// File Line: 716
// RVA: 0x1AC10
void __fastcall Render::vNCDescriptor::vNCDescriptor(Render::vNCDescriptor *this)
{
  Render::vNCDescriptor *v1; // rbx
  UFG::qVector4 default_value; // [rsp+38h] [rbp-20h]

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.NC",
    0x34AB04E6u);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vNCDescriptor::`vftable;
  default_value.x = 0.5;
  default_value.y = 0.5;
  default_value.z = 0.5;
  LODWORD(default_value.w) = (_DWORD)FLOAT_1_0;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_COLOR0,
    VERTEX_TYPE_COLOR4,
    1,
    &default_value);
}

// File Line: 736
// RVA: 0x1A4B0
void __fastcall Render::vCloudWispDescriptor::vCloudWispDescriptor(Render::vCloudWispDescriptor *this)
{
  Render::vCloudWispDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.CloudWisp",
    0xE7CFFC61);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vCloudWispDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    0,
    VERTEX_TYPE_FLOAT4,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_FLOAT4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD1,
    VERTEX_TYPE_FLOAT4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD2,
    VERTEX_TYPE_FLOAT4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD3,
    VERTEX_TYPE_FLOAT4,
    1,
    0i64);
}

// File Line: 765
// RVA: 0x1BC90
void __fastcall Render::vWaterSurfaceDescriptor::vWaterSurfaceDescriptor(Render::vWaterSurfaceDescriptor *this)
{
  Render::vWaterSurfaceDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.WaterSurface",
    0xD3798DFD);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vWaterSurfaceDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    0,
    VERTEX_TYPE_FLOAT4,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_FLOAT4,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
}

// File Line: 787
// RVA: 0x1ACD0
void __fastcall Render::vParticleDescriptor::vParticleDescriptor(Render::vParticleDescriptor *this)
{
  Render::vParticleDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.Particle",
    0xD7A5C4C7);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vParticleDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    0,
    VERTEX_TYPE_FLOAT4,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::SetStreamRuntimeFlag((Illusion::VertexStreamDescriptor *)&v1->vfptr, 1);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_FLOAT4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD1,
    VERTEX_TYPE_HALF4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD2,
    VERTEX_TYPE_HALF4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD3,
    VERTEX_TYPE_FLOAT4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD4,
    0,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD5,
    0,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD6,
    VERTEX_TYPE_HALF4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDWEIGHT,
    VERTEX_TYPE_UBYTE4N,
    1,
    0i64);
}

// File Line: 819
// RVA: 0x1A920
void __fastcall Render::vGeoParticleDescriptor::vGeoParticleDescriptor(Render::vGeoParticleDescriptor *this)
{
  Render::vGeoParticleDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.GeoParticle",
    0x25586179u);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vGeoParticleDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::SetIndexStreamMultiplier((Illusion::VertexStreamDescriptor *)&v1->vfptr, 4);
  Illusion::VertexStreamDescriptor::SetIndexStreamAsVertexStream((Illusion::VertexStreamDescriptor *)&v1->vfptr);
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    0,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TANGENT,
    0,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::SetStreamRuntimeFlag((Illusion::VertexStreamDescriptor *)&v1->vfptr, 1);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD1,
    VERTEX_TYPE_FLOAT4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD2,
    VERTEX_TYPE_HALF4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD3,
    VERTEX_TYPE_HALF4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD4,
    VERTEX_TYPE_FLOAT4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD5,
    0,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD6,
    0,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD7,
    VERTEX_TYPE_HALF4,
    1,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_BLENDWEIGHT,
    VERTEX_TYPE_UBYTE4N,
    1,
    0i64);
}

// File Line: 868
// RVA: 0x1A580
void __fastcall Render::vDecalDescriptor::vDecalDescriptor(Render::vDecalDescriptor *this)
{
  Render::vDecalDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.Decal",
    0x128206B2u);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vDecalDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_UBYTE4N,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TANGENT,
    VERTEX_TYPE_UBYTE4N,
    0,
    0i64);
}

// File Line: 883
// RVA: 0x1AB60
void __fastcall Render::vLightningDescriptor::vLightningDescriptor(Render::vLightningDescriptor *this)
{
  Render::vLightningDescriptor *v1; // rbx

  v1 = this;
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    (Illusion::VertexStreamDescriptor *)&this->vfptr,
    "VertexDecl.Lightning",
    0x811776u);
  v1->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vLightningDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement((Illusion::VertexStreamDescriptor *)&v1->vfptr, 0, 0, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_NORMAL,
    0,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    (Illusion::VertexStreamDescriptor *)&v1->vfptr,
    VERTEX_ELEMENT_COLOR0,
    VERTEX_TYPE_COLOR4,
    0,
    0i64);
}

