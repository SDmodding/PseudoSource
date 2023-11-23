// File Line: 50
// RVA: 0x94D20
void __fastcall Illusion::RenderStateInit(Illusion *this)
{
  UFG::qResourceData *v1; // rbx
  UFG::qResourceWarehouse *v2; // rax
  UFG::qResourceData *v3; // rbx
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceData *v5; // rbx
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceData *v7; // rbx
  UFG::qResourceWarehouse *v8; // rax
  UFG::qResourceData *v9; // rbx
  UFG::qResourceWarehouse *v10; // rax
  UFG::qResourceData *v11; // rbx
  UFG::qResourceWarehouse *v12; // rax
  UFG::qResourceData *v13; // rbx
  UFG::qResourceWarehouse *v14; // rax
  UFG::qResourceData *v15; // rbx
  UFG::qResourceWarehouse *v16; // rax
  UFG::qResourceData *v17; // rbx
  UFG::qResourceWarehouse *v18; // rax
  UFG::qResourceData *v19; // rbx
  UFG::qResourceWarehouse *v20; // rax
  UFG::qResourceData *v21; // rbx
  UFG::qResourceWarehouse *v22; // rax
  UFG::qResourceData *v23; // rbx
  UFG::qResourceWarehouse *v24; // rax
  UFG::qResourceData *v25; // rbx
  UFG::qResourceWarehouse *v26; // rax
  UFG::qResourceData *v27; // rbx
  UFG::qResourceWarehouse *v28; // rax
  UFG::qResourceData *v29; // rbx
  UFG::qResourceWarehouse *v30; // rax
  UFG::qResourceData *v31; // rbx
  UFG::qResourceWarehouse *v32; // rax
  UFG::qResourceData *v33; // rbx
  UFG::qResourceWarehouse *v34; // rax
  UFG::qResourceData *v35; // rbx
  UFG::qResourceWarehouse *v36; // rax
  UFG::qResourceData *v37; // rbx
  UFG::qResourceWarehouse *v38; // rax
  UFG::qResourceData *v39; // rbx
  UFG::qResourceWarehouse *v40; // rax
  UFG::qResourceData *v41; // rbx
  UFG::qResourceWarehouse *v42; // rax
  UFG::qResourceData *v43; // rbx
  UFG::qResourceWarehouse *v44; // rax
  UFG::qResourceData *v45; // rbx
  UFG::qResourceWarehouse *v46; // rax
  UFG::qResourceData *v47; // rbx
  UFG::qResourceWarehouse *v48; // rax
  UFG::qResourceData *v49; // rbx
  UFG::qResourceWarehouse *v50; // rax
  UFG::qResourceData *v51; // rbx
  UFG::qResourceWarehouse *v52; // rax
  UFG::qResourceData *v53; // rbx
  UFG::qResourceWarehouse *v54; // rax
  UFG::qResourceData *v55; // rbx
  UFG::qResourceWarehouse *v56; // rax

  Illusion::HardwareState::Init();
  Illusion::HardwareState::sTextureSize[0] = 32;
  dword_142166E74 = 4;
  dword_142166E78 = 8;
  dword_142166E7C = 8;
  dword_142166E80 = 16;
  dword_142166E84 = 16;
  dword_142166E88 = 8;
  dword_142166E8C = 16;
  dword_142166E90 = 4;
  dword_142166E94 = 8;
  dword_142166EA8 = 32;
  dword_142166EAC = 64;
  dword_142166EB0 = 32;
  dword_142166EB4 = 32;
  dword_142166EB8 = 32;
  dword_142166EBC = 32;
  dword_142166EC0 = 32;
  dword_142166EC4 = 32;
  dword_142166EC8 = 64;
  dword_142166E98 = 8;
  dword_142166E9C = 8;
  dword_142166EA0 = 8;
  dword_142166EA4 = 8;
  *(_QWORD *)Illusion::HardwareState::sIndicesPerPrim = 1i64;
  dword_142166F78 = 2;
  qword_142166F7C = 3i64;
  dword_142166F84 = 0;
  dword_142166F8C = 1;
  dword_142166F90 = 2;
  dword_142166F94 = 3;
  dword_142166F98 = 4;
  dword_142166F9C = 5;
  dword_142166FA0 = 6;
  dword_142166FA4 = 7;
  dword_142166FA8 = 8;
  dword_142166FAC = 9;
  dword_142166FB0 = 10;
  dword_142166FB4 = 11;
  dword_142166FB8 = 12;
  dword_142166FBC = 13;
  dword_142166FC0 = 14;
  dword_142166FC4 = 15;
  dword_142166FC8 = 16;
  dword_142166FCC = 17;
  dword_142166FD0 = 18;
  dword_142166FD4 = 19;
  dword_142166FD8 = 20;
  dword_142166FDC = 21;
  dword_142166FE0 = 22;
  dword_142166FE4 = 23;
  dword_142166FE8 = 24;
  dword_142166FEC = 25;
  dword_142166FF0 = 26;
  dword_142166FF4 = 27;
  dword_142166FF8 = 28;
  dword_142166FFC = 29;
  dword_142167000 = 30;
  dword_142167004 = 31;
  dword_142167008 = 32;
  v1 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.None", 0x2782CCE6u, 0i64, 0i64, 0i64);
  LOBYTE(v1[1].mNode.mParent) = 0;
  BYTE5(v1[1].mNode.mParent) = 0;
  v2 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v2, v1);
  v3 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.Modulated", 0xA3833FDE, 0i64, 0i64, 0i64);
  LOWORD(v3[1].mNode.mParent) = 1025;
  BYTE2(v3[1].mNode.mParent) = 5;
  v4 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v4, v3);
  v5 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.ModulatedRGBSolidAlpha", 0x14CF26CEu, 0i64, 0i64, 0i64);
  LOWORD(v5[1].mNode.mParent) = 1025;
  LOWORD(v5[1].mNode.mChild[0]) = 257;
  BYTE2(v5[1].mNode.mParent) = 5;
  BYTE2(v5[1].mNode.mChild[0]) = 0;
  v6 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v6, v5);
  v7 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.Additive", 0x69DAE2D1u, 0i64, 0i64, 0i64);
  LOWORD(v7[1].mNode.mParent) = 1025;
  BYTE2(v7[1].mNode.mParent) = 1;
  v8 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v8, v7);
  v9 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.Premultipled", 0xFAB11CA1, 0i64, 0i64, 0i64);
  LOWORD(v9[1].mNode.mParent) = 257;
  BYTE2(v9[1].mNode.mParent) = 5;
  v10 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v10, v9);
  v11 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.PremultipledModulate", 0x8460BCBE, 0i64, 0i64, 0i64);
  LOWORD(v11[1].mNode.mChild[0]) = 257;
  LOWORD(v11[1].mNode.mParent) = 1025;
  BYTE2(v11[1].mNode.mParent) = 5;
  BYTE2(v11[1].mNode.mChild[0]) = 5;
  v12 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v12, v11);
  v13 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.PremultipledAdditive", 0xDA6C09DD, 0i64, 0i64, 0i64);
  LOWORD(v13[1].mNode.mChild[0]) = 1;
  LOWORD(v13[1].mNode.mParent) = 1025;
  BYTE2(v13[1].mNode.mParent) = 1;
  BYTE2(v13[1].mNode.mChild[0]) = 1;
  v14 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v14, v13);
  v15 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.PunchThru", 0x2B068C0Au, 0i64, 0i64, 0i64);
  LOBYTE(v15[1].mNode.mParent) = 0;
  BYTE5(v15[1].mNode.mParent) = 1;
  HIBYTE(v15[1].mNode.mParent) = 6;
  v16 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v16, v15);
  v17 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.FeatherPunchThru", 0xBBB46CC6, 0i64, 0i64, 0i64);
  LOBYTE(v17[1].mNode.mParent) = 0;
  BYTE5(v17[1].mNode.mParent) = 1;
  HIBYTE(v17[1].mNode.mParent) = 6;
  v18 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v18, v17);
  v19 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.Mask", 0x7C49699Cu, 0i64, 0i64, 0i64);
  LOWORD(v19[1].mNode.mParent) = 1;
  BYTE2(v19[1].mNode.mParent) = 4;
  LOWORD(v19[1].mNode.mChild[0]) = 1;
  BYTE2(v19[1].mNode.mChild[0]) = 4;
  v20 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v20, v19);
  v21 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.Overlay", 0xEDE83382, 0i64, 0i64, 0i64);
  LOWORD(v21[1].mNode.mParent) = 2049;
  BYTE2(v21[1].mNode.mParent) = 2;
  v22 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v22, v21);
  v23 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.Screen", 0xD668AB18, 0i64, 0i64, 0i64);
  LOWORD(v23[1].mNode.mParent) = 2305;
  BYTE2(v23[1].mNode.mParent) = 1;
  v24 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v24, v23);
  v25 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.Min", 0x5BAB9A58u, 0i64, 0i64, 0i64);
  LOBYTE(v25[1].mNode.mParent) = 1;
  *(_WORD *)((char *)&v25[1].mNode.mParent + 3) = 257;
  v26 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v26, v25);
  v27 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.Max", 0x87744FC8, 0i64, 0i64, 0i64);
  LOBYTE(v27[1].mNode.mParent) = 1;
  *(_WORD *)((char *)&v27[1].mNode.mParent + 3) = 514;
  v28 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v28, v27);
  v29 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.Subtract", 0x2AC01C02u, 0i64, 0i64, 0i64);
  LODWORD(v29[1].mNode.mParent) = 50397441;
  BYTE4(v29[1].mNode.mParent) = 3;
  v30 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v30, v29);
  v31 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.ReverseSubtract", 0x30CE6B08u, 0i64, 0i64, 0i64);
  LODWORD(v31[1].mNode.mParent) = 67174657;
  BYTE4(v31[1].mNode.mParent) = 4;
  v32 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v32, v31);
  v33 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.Copy", 0x7822A5ADu, 0i64, 0i64, 0i64);
  LOWORD(v33[1].mNode.mParent) = 257;
  BYTE5(v33[1].mNode.mParent) = 0;
  BYTE2(v33[1].mNode.mParent) = 0;
  v34 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v34, v33);
  v35 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.NoColourWrite", 0x91A2DD53, 0i64, 0i64, 0i64);
  BYTE3(v35[1].mNode.mChild[0]) = 0;
  v36 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v36, v35);
  v37 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.ModulatedMaskRGB", 0xD1E2A76B, 0i64, 0i64, 0i64);
  LOWORD(v37[1].mNode.mParent) = 1025;
  BYTE2(v37[1].mNode.mParent) = 5;
  BYTE3(v37[1].mNode.mChild[0]) = 7;
  v38 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v38, v37);
  v39 = Illusion::Factory::NewAlphaState("Illusion.AlphaState.ModulatedRGBSrcAlpha", 0x6EBDEDA0u, 0i64, 0i64, 0i64);
  LOWORD(v39[1].mNode.mParent) = 1281;
  LOWORD(v39[1].mNode.mChild[0]) = 1;
  BYTE2(v39[1].mNode.mParent) = 4;
  BYTE2(v39[1].mNode.mChild[0]) = 4;
  v40 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v40, v39);
  v41 = Illusion::Factory::NewRasterState("Illusion.RasterState.None", 0x62F81854u, 0i64, 0i64, 0i64);
  LOWORD(v41[1].mNode.mParent) = 0;
  BYTE3(v41[1].mNode.mParent) = 0;
  v42 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v42, v41);
  v43 = Illusion::Factory::NewRasterState("Illusion.RasterState.Normal", 0x20688F05u, 0i64, 0i64, 0i64);
  LOWORD(v43[1].mNode.mParent) = 257;
  BYTE3(v43[1].mNode.mParent) = 1;
  v44 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v44, v43);
  v45 = Illusion::Factory::NewRasterState("Illusion.RasterState.DisableWrite", 0xF05AB9A5, 0i64, 0i64, 0i64);
  LOWORD(v45[1].mNode.mParent) = 1;
  BYTE3(v45[1].mNode.mParent) = 1;
  v46 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v46, v45);
  v47 = Illusion::Factory::NewRasterState("Illusion.RasterState.InvertDisableWrite", 0x4B6C82C0u, 0i64, 0i64, 0i64);
  LOWORD(v47[1].mNode.mParent) = 1;
  BYTE3(v47[1].mNode.mParent) = 2;
  v48 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v48, v47);
  v49 = Illusion::Factory::NewRasterState("Illusion.RasterState.DisableDepthTest", 0xC533A5Du, 0i64, 0i64, 0i64);
  LOWORD(v49[1].mNode.mParent) = 0;
  BYTE3(v49[1].mNode.mParent) = 1;
  v50 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v50, v49);
  v51 = Illusion::Factory::NewRasterState("Illusion.RasterState.DoubleSided", 0x940FB8EC, 0i64, 0i64, 0i64);
  LOWORD(v51[1].mNode.mParent) = 257;
  BYTE3(v51[1].mNode.mParent) = 0;
  v52 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v52, v51);
  v53 = Illusion::Factory::NewRasterState("Illusion.RasterState.DoubleSidedAlpha", 0x418CAF43u, 0i64, 0i64, 0i64);
  LOWORD(v53[1].mNode.mParent) = 1;
  BYTE3(v53[1].mNode.mParent) = 0;
  v54 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v54, v53);
  v55 = Illusion::Factory::NewRasterState("Illusion.RasterState.InvertCulling", 0xBC9FAF09, 0i64, 0i64, 0i64);
  LOWORD(v55[1].mNode.mParent) = 257;
  BYTE3(v55[1].mNode.mParent) = 2;
  v56 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v56, v55);
}

// File Line: 369
// RVA: 0x1457C00
__int64 Illusion::_dynamic_initializer_for__gAlphaStateInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Illusion::gAlphaStateInventory,
    "AlphaStateInventory",
    0x12C800F2u,
    0x1BCFF4D5u,
    0,
    0);
  Illusion::gAlphaStateInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::AlphaStateInventory::`vftable;
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gAlphaStateInventory__);
}

// File Line: 377
// RVA: 0x8DC40
void __fastcall Illusion::AlphaStateInventory::Add(
        Illusion::AlphaStateInventory *this,
        Illusion::AlphaState *resource_data)
{
  Illusion::AlphaState::OnAddPlat(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 388
// RVA: 0x947E0
void __fastcall Illusion::AlphaStateInventory::Remove(
        Illusion::AlphaStateInventory *this,
        Illusion::AlphaState *resource_data)
{
  UFG::qResourceInventory::Remove(this, resource_data);
  Illusion::AlphaState::OnRemovePlat(resource_data);
}

// File Line: 399
// RVA: 0x92BD0
__int64 __fastcall Illusion::AlphaStateInventory::Load(Illusion::AlphaStateInventory *this, UFG::qChunk *chunk)
{
  if ( chunk->mUID != 466613461 )
  {
    if ( chunk->mUID != this->mChunkUID )
      return 0i64;
    this->vfptr->Add(this, (UFG::qResourceData *)((char *)&chunk[1] + chunk->mDataOffset));
  }
  return 1i64;
}

// File Line: 418
// RVA: 0x95AA0
__int64 __fastcall Illusion::AlphaStateInventory::Unload(Illusion::AlphaStateInventory *this, UFG::qChunk *chunk)
{
  if ( chunk->mUID != 466613461 )
  {
    if ( chunk->mUID != this->mChunkUID )
      return 0i64;
    this->vfptr->Remove(this, (UFG::qResourceData *)((char *)&chunk[1] + chunk->mDataOffset));
  }
  return 1i64;
}

// File Line: 457
// RVA: 0x1458070
__int64 Illusion::_dynamic_initializer_for__gRasterStateInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Illusion::gRasterStateInventory,
    "RasterStateInventory",
    0x3BC715E0u,
    0xB27A4B38,
    0,
    0);
  Illusion::gRasterStateInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::RasterStateInventory::`vftable;
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gRasterStateInventory__);
}

// File Line: 465
// RVA: 0x8DDD0
void __fastcall Illusion::RasterStateInventory::Add(
        Illusion::RasterStateInventory *this,
        Illusion::RasterState *resource_data)
{
  Illusion::RasterState::OnAddPlat(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 476
// RVA: 0x94930
void __fastcall Illusion::RasterStateInventory::Remove(
        Illusion::RasterStateInventory *this,
        Illusion::RasterState *resource_data)
{
  UFG::qResourceInventory::Remove(this, resource_data);
  Illusion::RasterState::OnRemovePlat(resource_data);
}

// File Line: 487
// RVA: 0x92C50
__int64 __fastcall Illusion::RasterStateInventory::Load(Illusion::RasterStateInventory *this, UFG::qChunk *chunk)
{
  if ( chunk->mUID != -1300608200 )
  {
    if ( chunk->mUID != this->mChunkUID )
      return 0i64;
    this->vfptr->Add(this, (UFG::qResourceData *)((char *)&chunk[1] + chunk->mDataOffset));
  }
  return 1i64;
}

// File Line: 506
// RVA: 0x95B20
__int64 __fastcall Illusion::RasterStateInventory::Unload(Illusion::RasterStateInventory *this, UFG::qChunk *chunk)
{
  if ( chunk->mUID != -1300608200 )
  {
    if ( chunk->mUID != this->mChunkUID )
      return 0i64;
    this->vfptr->Remove(this, (UFG::qResourceData *)((char *)&chunk[1] + chunk->mDataOffset));
  }
  return 1i64;
}

