// File Line: 128
// RVA: 0x1A810
void __fastcall Render::vFBXDescriptor::vFBXDescriptor(Render::vFBXDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.FBX", 0xEE711E17);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vFBXDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD1, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_FLOAT3, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TANGENT, VERTEX_TYPE_FLOAT3, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_COLOR0, VERTEX_TYPE_COLOR4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDINDEX, VERTEX_TYPE_UBYTE4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDWEIGHT, VERTEX_TYPE_UBYTE4N, 1, 0i64);
}

// File Line: 164
// RVA: 0x1A700
void __fastcall Render::vFBX2Descriptor::vFBX2Descriptor(Render::vFBX2Descriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.FBX2", 0x5589C78Du);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vFBX2Descriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD1, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_COLOR0, VERTEX_TYPE_COLOR4, 2, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_FLOAT3, 3, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TANGENT, VERTEX_TYPE_FLOAT3, 3, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDINDEX, VERTEX_TYPE_UBYTE4, 3, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDWEIGHT, VERTEX_TYPE_UBYTE4N, 3, 0i64);
}

// File Line: 223
// RVA: 0x1A630
void __fastcall Render::vDynamicDescriptor::vDynamicDescriptor(Render::vDynamicDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.Dynamic", 0x64A43DAEu);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vDynamicDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD1, VERTEX_TYPE_HALF2, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TANGENT, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_COLOR0, VERTEX_TYPE_COLOR4, 0, 0i64);
}

// File Line: 253
// RVA: 0x1AF40
void __fastcall Render::vSkinnedDescriptor::vSkinnedDescriptor(Render::vSkinnedDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.Skinned", 0x276B9567u);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vSkinnedDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT4, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_BYTE4N, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TANGENT, VERTEX_TYPE_BYTE4N, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDINDEX, VERTEX_TYPE_UBYTE4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDWEIGHT, VERTEX_TYPE_UBYTE4N, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 2, 0i64);
}

// File Line: 265
// RVA: 0x1BD30
void __fastcall Render::vSkinnedDescriptor::ApplyUserRemapping(
        Render::vSkinnedDescriptor *this,
        UFG::qVector4 *vertex_element)
{
  float x; // xmm1_4

  x = vertex_element[3].x;
  if ( x <= 0.19611764 )
  {
    x = FLOAT_0_19611764;
  }
  else if ( x >= 1.0 )
  {
    vertex_element[2].w = 1.0 * vertex_element[2].w;
    return;
  }
  vertex_element[2].w = x * vertex_element[2].w;
}

// File Line: 322
// RVA: 0x1AE00
void __fastcall Render::vScreenParticleDescriptor::vScreenParticleDescriptor(Render::vScreenParticleDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.ScreenParticle", 0x3D339245u);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vScreenParticleDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD1, VERTEX_TYPE_FLOAT4, 0, 0i64);
}

// File Line: 341
// RVA: 0x1AAB0
void __fastcall Render::vLightCardDescriptor::vLightCardDescriptor(Render::vLightCardDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.LightCard", 0x6FA1A436u);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vLightCardDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD1, VERTEX_TYPE_FLOAT4, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDWEIGHT, VERTEX_TYPE_UBYTE4N, 0, 0i64);
}

// File Line: 379
// RVA: 0x1AE90
void __fastcall Render::vSkinnedDecalDescriptor::vSkinnedDecalDescriptor(Render::vSkinnedDecalDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.SkinnedDecal", 0x23F36527u);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vSkinnedDecalDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT4, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_BYTE4N, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TANGENT, VERTEX_TYPE_BYTE4N, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 0, 0i64);
}

// File Line: 399
// RVA: 0x1BBB0
void __fastcall Render::vVehicleUVNTDescriptor::vVehicleUVNTDescriptor(Render::vVehicleUVNTDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.VehicleUVNTC", 0xE234EF7A);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vVehicleUVNTDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT4, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_BYTE4N, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TANGENT, VERTEX_TYPE_BYTE4N, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDINDEX, VERTEX_TYPE_UBYTE4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDWEIGHT, VERTEX_TYPE_UBYTE4N, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 2, 0i64);
}

// File Line: 423
// RVA: 0x1BAC0
void __fastcall Render::vVehicleUV2NTDescriptor::vVehicleUV2NTDescriptor(Render::vVehicleUV2NTDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.VehicleUV2NTC", 0xBF900E9E);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vVehicleUV2NTDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT4, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_BYTE4N, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TANGENT, VERTEX_TYPE_BYTE4N, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDINDEX, VERTEX_TYPE_UBYTE4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDWEIGHT, VERTEX_TYPE_UBYTE4N, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 2, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD1, VERTEX_TYPE_HALF2, 2, 0i64);
}

// File Line: 449
// RVA: 0x1B9B0
void __fastcall Render::vVehicleGlassUV2NTCDescriptor::vVehicleGlassUV2NTCDescriptor(
        Render::vVehicleGlassUV2NTCDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.VehicleGlassUV2NTC", 0xD08FF31A);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vVehicleGlassUV2NTCDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT4, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_BYTE4N, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TANGENT, VERTEX_TYPE_BYTE4N, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDINDEX, VERTEX_TYPE_UBYTE4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDWEIGHT, VERTEX_TYPE_UBYTE4N, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 2, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD1, VERTEX_TYPE_HALF2, 2, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_COLOR0, VERTEX_TYPE_COLOR4, 2, 0i64);
}

// File Line: 475
// RVA: 0x1B020
void __fastcall Render::vSkinnedUVNTDescriptor::vSkinnedUVNTDescriptor(Render::vSkinnedUVNTDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.SkinnedUVNT", 0xAC5D89E2);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vSkinnedUVNTDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT4, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_BYTE4N, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TANGENT, VERTEX_TYPE_BYTE4N, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDINDEX, VERTEX_TYPE_UBYTE4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDWEIGHT, VERTEX_TYPE_UBYTE4N, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 2, 0i64);
}

// File Line: 499
// RVA: 0x1B1B0
void __fastcall Render::vUV2Descriptor::vUV2Descriptor(Render::vUV2Descriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.UV2", 0x27C88915u);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUV2Descriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD1, VERTEX_TYPE_HALF2, 1, 0i64);
}

// File Line: 510
// RVA: 0x1B3C0
void __fastcall Render::vUV2NTCDescriptor::vUV2NTCDescriptor(Render::vUV2NTCDescriptor *this)
{
  UFG::qVector4 default_value; // [rsp+38h] [rbp-20h] BYREF

  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.UV2NTC", 0x78921EA0u);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUV2NTCDescriptor::`vftable;
  *(_QWORD *)&default_value.x = 0i64;
  default_value.z = 0.0;
  LODWORD(default_value.w) = (_DWORD)FLOAT_1_0;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD1, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_BYTE4N, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TANGENT, VERTEX_TYPE_BYTE4N, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_COLOR0, VERTEX_TYPE_COLOR4, 1, &default_value);
}

// File Line: 531
// RVA: 0x1B4C0
void __fastcall Render::vUV2NTDescriptor::vUV2NTDescriptor(Render::vUV2NTDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.UV2NT", 0xA0B0781E);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUV2NTDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD1, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_BYTE4N, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TANGENT, VERTEX_TYPE_BYTE4N, 1, 0i64);
}

// File Line: 550
// RVA: 0x1B250
void __fastcall Render::vUV2NCDescriptor::vUV2NCDescriptor(Render::vUV2NCDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.UV2NC", 0xF2E6F36B);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUV2NCDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD1, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_BYTE4N, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_COLOR0, VERTEX_TYPE_COLOR4, 1, 0i64);
}

// File Line: 570
// RVA: 0x1B310
void __fastcall Render::vUV2NDescriptor::vUV2NDescriptor(Render::vUV2NDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.UV2N", 0x46E52398u);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUV2NDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD1, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_BYTE4N, 1, 0i64);
}

// File Line: 588
// RVA: 0x1B810
void __fastcall Render::vUVNTCDescriptor::vUVNTCDescriptor(Render::vUVNTCDescriptor *this)
{
  UFG::qVector4 default_value; // [rsp+38h] [rbp-20h] BYREF

  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.UVNTC", 0x911E1A51);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUVNTCDescriptor::`vftable;
  *(_QWORD *)&default_value.x = 0i64;
  default_value.z = 0.0;
  LODWORD(default_value.w) = (_DWORD)FLOAT_1_0;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_BYTE4N, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TANGENT, VERTEX_TYPE_BYTE4N, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_COLOR0, VERTEX_TYPE_COLOR4, 1, &default_value);
}

// File Line: 608
// RVA: 0x1B900
void __fastcall Render::vUVNTDescriptor::vUVNTDescriptor(Render::vUVNTDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.UVNT", 0x9BA68DBC);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUVNTDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_BYTE4N, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TANGENT, VERTEX_TYPE_BYTE4N, 1, 0i64);
}

// File Line: 626
// RVA: 0x1B6D0
void __fastcall Render::vUVNDescriptor::vUVNDescriptor(Render::vUVNDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.UVN", 0xF2700F96);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUVNDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_BYTE4N, 1, 0i64);
}

// File Line: 644
// RVA: 0x1B580
void __fastcall Render::vUVCDescriptor::vUVCDescriptor(Render::vUVCDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.UVC", 0xC3BD8945);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUVCDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_COLOR0, VERTEX_TYPE_COLOR4, 1, 0i64);
}

// File Line: 662
// RVA: 0x1B620
void __fastcall Render::vUVCNPackedDescriptor::vUVCNPackedDescriptor(Render::vUVCNPackedDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.UVCNPacked", 0xF0D9B822);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUVCNPackedDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_HALF4, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_BYTE4N, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_COLOR0, VERTEX_TYPE_COLOR4, 1, 0i64);
}

// File Line: 670
// RVA: 0x1BD80
void __fastcall Render::vUVCNPackedDescriptor::ApplyUserRemapping(
        Render::vUVCNPackedDescriptor *this,
        UFG::qVector4 *vertex_element)
{
  vertex_element->w = 1.0;
}

// File Line: 680
// RVA: 0x1B770
void __fastcall Render::vUVNPackedDescriptor::vUVNPackedDescriptor(Render::vUVNPackedDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.UVNPacked", 0x720788F7u);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUVNPackedDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_HALF4, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_BYTE4N, 1, 0i64);
}

// File Line: 687
// RVA: 0x1BD90
void __fastcall Render::vUVNPackedDescriptor::ApplyUserRemapping(
        Render::vUVNPackedDescriptor *this,
        UFG::qVector4 *vertex_element)
{
  vertex_element[1].w = 1.0;
}

// File Line: 698
// RVA: 0x1B100
void __fastcall Render::vUV2CDescriptor::vUV2CDescriptor(Render::vUV2CDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.UV2C", 0x7728A54Bu);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vUV2CDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD1, VERTEX_TYPE_HALF2, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_COLOR0, VERTEX_TYPE_COLOR4, 1, 0i64);
}

// File Line: 706
// RVA: 0x1BD70
void __fastcall Render::vUV2NTCDescriptor::ApplyUserRemapping(
        Render::vUVNTDescriptor *this,
        UFG::qVector4 *vertex_element)
{
  vertex_element[1].w = vertex_element[3].w;
}

// File Line: 716
// RVA: 0x1AC10
void __fastcall Render::vNCDescriptor::vNCDescriptor(Render::vNCDescriptor *this)
{
  UFG::qVector4 default_value; // [rsp+38h] [rbp-20h] BYREF

  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.NC", 0x34AB04E6u);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vNCDescriptor::`vftable;
  default_value.x = 0.5;
  default_value.y = 0.5;
  default_value.z = 0.5;
  LODWORD(default_value.w) = (_DWORD)FLOAT_1_0;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_BYTE4N, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_COLOR0, VERTEX_TYPE_COLOR4, 1, &default_value);
}

// File Line: 736
// RVA: 0x1A4B0
void __fastcall Render::vCloudWispDescriptor::vCloudWispDescriptor(Render::vCloudWispDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.CloudWisp", 0xE7CFFC61);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vCloudWispDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT4, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_FLOAT4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD1, VERTEX_TYPE_FLOAT4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD2, VERTEX_TYPE_FLOAT4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD3, VERTEX_TYPE_FLOAT4, 1, 0i64);
}

// File Line: 765
// RVA: 0x1BC90
void __fastcall Render::vWaterSurfaceDescriptor::vWaterSurfaceDescriptor(Render::vWaterSurfaceDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.WaterSurface", 0xD3798DFD);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vWaterSurfaceDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT4, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_FLOAT4, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 1, 0i64);
}

// File Line: 787
// RVA: 0x1ACD0
void __fastcall Render::vParticleDescriptor::vParticleDescriptor(Render::vParticleDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.Particle", 0xD7A5C4C7);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vParticleDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT4, 0, 0i64);
  Illusion::VertexStreamDescriptor::SetStreamRuntimeFlag(this, 1);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_FLOAT4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD1, VERTEX_TYPE_HALF4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD2, VERTEX_TYPE_HALF4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD3, VERTEX_TYPE_FLOAT4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD4, VERTEX_TYPE_FLOAT3, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD5, VERTEX_TYPE_FLOAT3, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD6, VERTEX_TYPE_HALF4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDWEIGHT, VERTEX_TYPE_UBYTE4N, 1, 0i64);
}

// File Line: 819
// RVA: 0x1A920
void __fastcall Render::vGeoParticleDescriptor::vGeoParticleDescriptor(Render::vGeoParticleDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.GeoParticle", 0x25586179u);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vGeoParticleDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::SetIndexStreamMultiplier(this, 4);
  Illusion::VertexStreamDescriptor::SetIndexStreamAsVertexStream(this);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TANGENT, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 0, 0i64);
  Illusion::VertexStreamDescriptor::SetStreamRuntimeFlag(this, 1);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD1, VERTEX_TYPE_FLOAT4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD2, VERTEX_TYPE_HALF4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD3, VERTEX_TYPE_HALF4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD4, VERTEX_TYPE_FLOAT4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD5, VERTEX_TYPE_FLOAT3, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD6, VERTEX_TYPE_FLOAT3, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD7, VERTEX_TYPE_HALF4, 1, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_BLENDWEIGHT, VERTEX_TYPE_UBYTE4N, 1, 0i64);
}

// File Line: 868
// RVA: 0x1A580
void __fastcall Render::vDecalDescriptor::vDecalDescriptor(Render::vDecalDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.Decal", 0x128206B2u);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vDecalDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_UBYTE4N, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TANGENT, VERTEX_TYPE_UBYTE4N, 0, 0i64);
}

// File Line: 883
// RVA: 0x1AB60
void __fastcall Render::vLightningDescriptor::vLightningDescriptor(Render::vLightningDescriptor *this)
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(this, "VertexDecl.Lightning", 0x811776u);
  this->vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vLightningDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_POSITION, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_NORMAL, VERTEX_TYPE_FLOAT3, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_TEXCOORD0, VERTEX_TYPE_HALF2, 0, 0i64);
  Illusion::VertexStreamDescriptor::AddElement(this, VERTEX_ELEMENT_COLOR0, VERTEX_TYPE_COLOR4, 0, 0i64);
}

