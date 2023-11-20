// File Line: 12
// RVA: 0x1458F40
__int64 UFG::_dynamic_initializer_for__gCollisionLayerInfo__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::gCollisionLayerInfo.mTree);
  return atexit(UFG::_dynamic_atexit_destructor_for__gCollisionLayerInfo__);
}

// File Line: 39
// RVA: 0xA98B0
char *__fastcall UFG::GetCollisionLayerName(unsigned int layerNumber)
{
  unsigned int v1; // ebx
  UFG::qBaseTreeRB *v2; // rax

  v1 = layerNumber;
  v2 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::gCollisionLayerInfo);
  if ( !v2 )
    return 0i64;
  while ( HIDWORD(v2->mNULL.mParent) != v1 )
  {
    v2 = UFG::qBaseTreeRB::GetNext(&UFG::gCollisionLayerInfo.mTree, &v2->mRoot);
    if ( !v2 )
      return 0i64;
  }
  return UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2->mNULL);
}

// File Line: 55
// RVA: 0xAE840
void __fastcall UFG::RegisterCollisionLayers(UFG *this)
{
  char *v1; // rax
  char *v2; // rsi
  char *v3; // rax
  char *v4; // rsi
  char *v5; // rax
  char *v6; // rsi
  char *v7; // rax
  char *v8; // rsi
  char *v9; // rax
  char *v10; // rsi
  char *v11; // rax
  char *v12; // rsi
  char *v13; // rax
  char *v14; // rsi
  char *v15; // rax
  char *v16; // rsi
  char *v17; // rax
  char *v18; // rsi
  char *v19; // rax
  char *v20; // rsi
  char *v21; // rax
  char *v22; // rsi
  char *v23; // rax
  char *v24; // rsi
  char *v25; // rax
  char *v26; // rsi
  char *v27; // rax
  char *v28; // rsi
  char *v29; // rax
  char *v30; // rsi
  char *v31; // rax
  char *v32; // rsi
  char *v33; // rax
  char *v34; // rsi
  char *v35; // rax
  char *v36; // rsi
  char *v37; // rax
  char *v38; // rsi
  char *v39; // rax
  char *v40; // rsi
  char *v41; // rax
  char *v42; // rsi
  char *v43; // rax
  char *v44; // rsi
  char *v45; // rax
  char *v46; // rsi
  char *v47; // rax
  char *v48; // rsi
  char *v49; // rax
  char *v50; // rsi
  char *v51; // rax
  char *v52; // rsi
  char *v53; // rax
  char *v54; // rsi
  char *v55; // rax
  char *v56; // rsi
  char *v57; // rax
  char *v58; // rsi
  char *v59; // rax
  char *v60; // rsi
  char *v61; // rax
  char *v62; // rsi
  char *v63; // rax
  char *v64; // rsi

  v1 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v2 = v1;
  if ( v1 )
  {
    *(_QWORD *)v1 = 0i64;
    *((_QWORD *)v1 + 1) = 0i64;
    *((_QWORD *)v1 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v1 + 8, "DEFAULT_LAYER");
    *((_DWORD *)v2 + 9) = 0;
    *((_DWORD *)v2 + 6) = *((_DWORD *)v2 + 8);
  }
  else
  {
    v2 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v2);
  v3 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v4 = v3;
  if ( v3 )
  {
    *(_QWORD *)v3 = 0i64;
    *((_QWORD *)v3 + 1) = 0i64;
    *((_QWORD *)v3 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v3 + 8, "PLAYER_LAYER");
    *((_DWORD *)v4 + 9) = 1;
    *((_DWORD *)v4 + 6) = *((_DWORD *)v4 + 8);
  }
  else
  {
    v4 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v4);
  v5 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v6 = v5;
  if ( v5 )
  {
    *(_QWORD *)v5 = 0i64;
    *((_QWORD *)v5 + 1) = 0i64;
    *((_QWORD *)v5 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v5 + 8, "PLAYER_LAYER2");
    *((_DWORD *)v6 + 9) = 2;
    *((_DWORD *)v6 + 6) = *((_DWORD *)v6 + 8);
  }
  else
  {
    v6 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v6);
  v7 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v8 = v7;
  if ( v7 )
  {
    *(_QWORD *)v7 = 0i64;
    *((_QWORD *)v7 + 1) = 0i64;
    *((_QWORD *)v7 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v7 + 8, "PLAYER_DEAD_LAYER");
    *((_DWORD *)v8 + 9) = 4;
    *((_DWORD *)v8 + 6) = *((_DWORD *)v8 + 8);
  }
  else
  {
    v8 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v8);
  v9 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v10 = v9;
  if ( v9 )
  {
    *(_QWORD *)v9 = 0i64;
    *((_QWORD *)v9 + 1) = 0i64;
    *((_QWORD *)v9 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v9 + 8, "PLAYER_ENTER_EXIT_VEHICLE_LAYER");
    *((_DWORD *)v10 + 9) = 5;
    *((_DWORD *)v10 + 6) = *((_DWORD *)v10 + 8);
  }
  else
  {
    v10 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v10);
  v11 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v12 = v11;
  if ( v11 )
  {
    *(_QWORD *)v11 = 0i64;
    *((_QWORD *)v11 + 1) = 0i64;
    *((_QWORD *)v11 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v11 + 8, "PLAYER_COMBAT_LAYER");
    *((_DWORD *)v12 + 9) = 3;
    *((_DWORD *)v12 + 6) = *((_DWORD *)v12 + 8);
  }
  else
  {
    v12 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v12);
  v13 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v14 = v13;
  if ( v13 )
  {
    *(_QWORD *)v13 = 0i64;
    *((_QWORD *)v13 + 1) = 0i64;
    *((_QWORD *)v13 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v13 + 8, "PLAYER_SITTING_LAYER");
    *((_DWORD *)v14 + 9) = 6;
    *((_DWORD *)v14 + 6) = *((_DWORD *)v14 + 8);
  }
  else
  {
    v14 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v14);
  v15 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v16 = v15;
  if ( v15 )
  {
    *(_QWORD *)v15 = 0i64;
    *((_QWORD *)v15 + 1) = 0i64;
    *((_QWORD *)v15 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v15 + 8, "RAGDOLL_LAYER");
    *((_DWORD *)v16 + 9) = 7;
    *((_DWORD *)v16 + 6) = *((_DWORD *)v16 + 8);
  }
  else
  {
    v16 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v16);
  v17 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v18 = v17;
  if ( v17 )
  {
    *(_QWORD *)v17 = 0i64;
    *((_QWORD *)v17 + 1) = 0i64;
    *((_QWORD *)v17 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v17 + 8, "RAGDOLL_LAYER_2");
    *((_DWORD *)v18 + 9) = 8;
    *((_DWORD *)v18 + 6) = *((_DWORD *)v18 + 8);
  }
  else
  {
    v18 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v18);
  v19 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v20 = v19;
  if ( v19 )
  {
    *(_QWORD *)v19 = 0i64;
    *((_QWORD *)v19 + 1) = 0i64;
    *((_QWORD *)v19 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v19 + 8, "TERRAIN_LAYER");
    *((_DWORD *)v20 + 9) = 9;
    *((_DWORD *)v20 + 6) = *((_DWORD *)v20 + 8);
  }
  else
  {
    v20 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v20);
  v21 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v22 = v21;
  if ( v21 )
  {
    *(_QWORD *)v21 = 0i64;
    *((_QWORD *)v21 + 1) = 0i64;
    *((_QWORD *)v21 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v21 + 8, "DESTRUCTABLE_TERRAIN_LAYER");
    *((_DWORD *)v22 + 9) = 10;
    *((_DWORD *)v22 + 6) = *((_DWORD *)v22 + 8);
  }
  else
  {
    v22 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v22);
  v23 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v24 = v23;
  if ( v23 )
  {
    *(_QWORD *)v23 = 0i64;
    *((_QWORD *)v23 + 1) = 0i64;
    *((_QWORD *)v23 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v23 + 8, "WHEELRAYCAST_LAYER");
    *((_DWORD *)v24 + 9) = 11;
    *((_DWORD *)v24 + 6) = *((_DWORD *)v24 + 8);
  }
  else
  {
    v24 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v24);
  v25 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v26 = v25;
  if ( v25 )
  {
    *(_QWORD *)v25 = 0i64;
    *((_QWORD *)v25 + 1) = 0i64;
    *((_QWORD *)v25 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v25 + 8, "USER_RAYCAST_LAYER_1");
    *((_DWORD *)v26 + 9) = 12;
    *((_DWORD *)v26 + 6) = *((_DWORD *)v26 + 8);
  }
  else
  {
    v26 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v26);
  v27 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v28 = v27;
  if ( v27 )
  {
    *(_QWORD *)v27 = 0i64;
    *((_QWORD *)v27 + 1) = 0i64;
    *((_QWORD *)v27 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v27 + 8, "USER_RAYCAST_LAYER_2");
    *((_DWORD *)v28 + 9) = 13;
    *((_DWORD *)v28 + 6) = *((_DWORD *)v28 + 8);
  }
  else
  {
    v28 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v28);
  v29 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v30 = v29;
  if ( v29 )
  {
    *(_QWORD *)v29 = 0i64;
    *((_QWORD *)v29 + 1) = 0i64;
    *((_QWORD *)v29 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v29 + 8, "USER_RAYCAST_LAYER_3");
    *((_DWORD *)v30 + 9) = 14;
    *((_DWORD *)v30 + 6) = *((_DWORD *)v30 + 8);
  }
  else
  {
    v30 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v30);
  v31 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v32 = v31;
  if ( v31 )
  {
    *(_QWORD *)v31 = 0i64;
    *((_QWORD *)v31 + 1) = 0i64;
    *((_QWORD *)v31 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v31 + 8, "USER_RAYCAST_LAYER_4");
    *((_DWORD *)v32 + 9) = 15;
    *((_DWORD *)v32 + 6) = *((_DWORD *)v32 + 8);
  }
  else
  {
    v32 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v32);
  v33 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v34 = v33;
  if ( v33 )
  {
    *(_QWORD *)v33 = 0i64;
    *((_QWORD *)v33 + 1) = 0i64;
    *((_QWORD *)v33 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v33 + 8, "USER_RAYCAST_LAYER_5");
    *((_DWORD *)v34 + 9) = 16;
    *((_DWORD *)v34 + 6) = *((_DWORD *)v34 + 8);
  }
  else
  {
    v34 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v34);
  v35 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v36 = v35;
  if ( v35 )
  {
    *(_QWORD *)v35 = 0i64;
    *((_QWORD *)v35 + 1) = 0i64;
    *((_QWORD *)v35 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v35 + 8, "USER_RAYCAST_LAYER_6");
    *((_DWORD *)v36 + 9) = 17;
    *((_DWORD *)v36 + 6) = *((_DWORD *)v36 + 8);
  }
  else
  {
    v36 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v36);
  v37 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v38 = v37;
  if ( v37 )
  {
    *(_QWORD *)v37 = 0i64;
    *((_QWORD *)v37 + 1) = 0i64;
    *((_QWORD *)v37 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v37 + 8, "CAMERA_LAYER");
    *((_DWORD *)v38 + 9) = 18;
    *((_DWORD *)v38 + 6) = *((_DWORD *)v38 + 8);
  }
  else
  {
    v38 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v38);
  v39 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v40 = v39;
  if ( v39 )
  {
    *(_QWORD *)v39 = 0i64;
    *((_QWORD *)v39 + 1) = 0i64;
    *((_QWORD *)v39 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v39 + 8, "LIGHT_DEBRIS_LAYER");
    *((_DWORD *)v40 + 9) = 19;
    *((_DWORD *)v40 + 6) = *((_DWORD *)v40 + 8);
  }
  else
  {
    v40 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v40);
  v41 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v42 = v41;
  if ( v41 )
  {
    *(_QWORD *)v41 = 0i64;
    *((_QWORD *)v41 + 1) = 0i64;
    *((_QWORD *)v41 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v41 + 8, "HEAVY_DEBRIS_LAYER");
    *((_DWORD *)v42 + 9) = 20;
    *((_DWORD *)v42 + 6) = *((_DWORD *)v42 + 8);
  }
  else
  {
    v42 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v42);
  v43 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v44 = v43;
  if ( v43 )
  {
    *(_QWORD *)v43 = 0i64;
    *((_QWORD *)v43 + 1) = 0i64;
    *((_QWORD *)v43 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v43 + 8, "NO_COLLISION_LAYER");
    *((_DWORD *)v44 + 9) = 21;
    *((_DWORD *)v44 + 6) = *((_DWORD *)v44 + 8);
  }
  else
  {
    v44 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v44);
  v45 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v46 = v45;
  if ( v45 )
  {
    *(_QWORD *)v45 = 0i64;
    *((_QWORD *)v45 + 1) = 0i64;
    *((_QWORD *)v45 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v45 + 8, "VEHICLE_LAYER");
    *((_DWORD *)v46 + 9) = 22;
    *((_DWORD *)v46 + 6) = *((_DWORD *)v46 + 8);
  }
  else
  {
    v46 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v46);
  v47 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v48 = v47;
  if ( v47 )
  {
    *(_QWORD *)v47 = 0i64;
    *((_QWORD *)v47 + 1) = 0i64;
    *((_QWORD *)v47 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v47 + 8, "WORLD_AVOIDANCE_LAYER");
    *((_DWORD *)v48 + 9) = 23;
    *((_DWORD *)v48 + 6) = *((_DWORD *)v48 + 8);
  }
  else
  {
    v48 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v48);
  v49 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v50 = v49;
  if ( v49 )
  {
    *(_QWORD *)v49 = 0i64;
    *((_QWORD *)v49 + 1) = 0i64;
    *((_QWORD *)v49 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v49 + 8, "OBJECT_AVOIDANCE_LAYER");
    *((_DWORD *)v50 + 9) = 24;
    *((_DWORD *)v50 + 6) = *((_DWORD *)v50 + 8);
  }
  else
  {
    v50 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v50);
  v51 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v52 = v51;
  if ( v51 )
  {
    *(_QWORD *)v51 = 0i64;
    *((_QWORD *)v51 + 1) = 0i64;
    *((_QWORD *)v51 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v51 + 8, "BULLET_LAYER");
    *((_DWORD *)v52 + 9) = 25;
    *((_DWORD *)v52 + 6) = *((_DWORD *)v52 + 8);
  }
  else
  {
    v52 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v52);
  v53 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v54 = v53;
  if ( v53 )
  {
    *(_QWORD *)v53 = 0i64;
    *((_QWORD *)v53 + 1) = 0i64;
    *((_QWORD *)v53 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v53 + 8, "WEAPON_LAYER");
    *((_DWORD *)v54 + 9) = 26;
    *((_DWORD *)v54 + 6) = *((_DWORD *)v54 + 8);
  }
  else
  {
    v54 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v54);
  v55 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v56 = v55;
  if ( v55 )
  {
    *(_QWORD *)v55 = 0i64;
    *((_QWORD *)v55 + 1) = 0i64;
    *((_QWORD *)v55 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v55 + 8, "BULLET_REACTION_LAYER");
    *((_DWORD *)v56 + 9) = 27;
    *((_DWORD *)v56 + 6) = *((_DWORD *)v56 + 8);
  }
  else
  {
    v56 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v56);
  v57 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v58 = v57;
  if ( v57 )
  {
    *(_QWORD *)v57 = 0i64;
    *((_QWORD *)v57 + 1) = 0i64;
    *((_QWORD *)v57 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v57 + 8, "WATER_LAYER");
    *((_DWORD *)v58 + 9) = 28;
    *((_DWORD *)v58 + 6) = *((_DWORD *)v58 + 8);
  }
  else
  {
    v58 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v58);
  v59 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v60 = v59;
  if ( v59 )
  {
    *(_QWORD *)v59 = 0i64;
    *((_QWORD *)v59 + 1) = 0i64;
    *((_QWORD *)v59 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v59 + 8, "SENSOR_COMPONENT_LAYER");
    *((_DWORD *)v60 + 9) = 29;
    *((_DWORD *)v60 + 6) = *((_DWORD *)v60 + 8);
  }
  else
  {
    v60 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v60);
  v61 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v62 = v61;
  if ( v61 )
  {
    *(_QWORD *)v61 = 0i64;
    *((_QWORD *)v61 + 1) = 0i64;
    *((_QWORD *)v61 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v61 + 8, "CAMERA_BARRIER_LAYER");
    *((_DWORD *)v62 + 9) = 30;
    *((_DWORD *)v62 + 6) = *((_DWORD *)v62 + 8);
  }
  else
  {
    v62 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v62);
  v63 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v64 = v63;
  if ( v63 )
  {
    *(_QWORD *)v63 = 0i64;
    *((_QWORD *)v63 + 1) = 0i64;
    *((_QWORD *)v63 + 2) = 0i64;
    UFG::qSymbol::create_from_string((UFG::qSymbol *)v63 + 8, "SEETHROUGH_SHOOTTHROUGH_LAYER");
    *((_DWORD *)v64 + 9) = 31;
    *((_DWORD *)v64 + 6) = *((_DWORD *)v64 + 8);
  }
  else
  {
    v64 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v64);
}
  UFG::qBaseTreeRB::Add(&UFG::gCollisionLayerInfo.mTree, (UFG::qBaseNodeRB *)v62);
  v63 = UFG::qMalloc(0x28ui64, "CollisionLayerInfo", 0i64);
  v64 = v63;
  if ( v63 )
  {
    *(_QWORD *)v63 = 0i64;


