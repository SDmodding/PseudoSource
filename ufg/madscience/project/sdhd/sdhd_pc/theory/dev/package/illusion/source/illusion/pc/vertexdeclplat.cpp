// File Line: 34
// RVA: 0xA1E860
void __fastcall Illusion::IVertexDeclPlat::OnLoad(Illusion::IVertexDeclPlat *this)
{
  __int64 v1; // rax
  Illusion::IVertexDeclPlat *v2; // rbx
  AMD_HD3D *v3; // rdi
  unsigned int v4; // eax
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // kr00_8
  UFG::allocator::free_link *v7; // rax
  size_t v8; // r8
  int v9; // esi
  __int64 v10; // r11
  __int64 v11; // r10
  __int64 v12; // rax
  __int64 v13; // rdx
  signed __int64 v14; // rcx
  signed __int64 v15; // r9
  const char *v16; // rax
  unsigned int v17; // ecx
  int v18; // eax
  char v19; // r8
  BOOL v20; // eax

  v1 = *(_QWORD *)&this[144];
  v2 = this;
  if ( v1 )
    v3 = (AMD_HD3D *)&this[v1 + 144];
  else
    v3 = 0i64;
  v4 = *(_DWORD *)&this[96];
  *(_DWORD *)&this[128] = v4;
  v6 = v4;
  v5 = 32i64 * v4;
  if ( !is_mul_ok(v6, 0x20ui64) )
    v5 = -1i64;
  v7 = UFG::qMalloc(v5, "VertexDeclPlat element desc array", 0i64);
  v8 = 32i64 * *(unsigned int *)&v2[128];
  *(_QWORD *)&v2[136] = v7;
  memset(v7, 0, v8);
  v9 = 0;
  if ( *(_DWORD *)&v2[96] > 0 )
  {
    v10 = 0i64;
    v11 = 0i64;
    do
    {
      v12 = *(_QWORD *)&v2[88];
      v13 = v11 + *(_QWORD *)&v2[136];
      if ( v12 )
        v14 = (signed __int64)&v2[v12 + 88];
      else
        v14 = 0i64;
      v15 = v10 + v14;
      switch ( *(_DWORD *)(v10 + v14) )
      {
        case 0:
          *(_QWORD *)v13 = "POSITION";
          goto LABEL_29;
        case 1:
          *(_QWORD *)v13 = "NORMAL";
          goto LABEL_29;
        case 2:
          *(_QWORD *)v13 = "TANGENT";
          goto LABEL_29;
        case 3:
          *(_QWORD *)v13 = "COLOR";
          goto LABEL_29;
        case 4:
          *(_QWORD *)v13 = "COLOR";
          *(_DWORD *)(v13 + 8) = 1;
          break;
        case 5:
          *(_QWORD *)v13 = "TEXCOORD";
          goto LABEL_29;
        case 6:
          *(_QWORD *)v13 = "TEXCOORD";
          *(_DWORD *)(v13 + 8) = 1;
          break;
        case 7:
          *(_QWORD *)v13 = "TEXCOORD";
          *(_DWORD *)(v13 + 8) = 2;
          break;
        case 8:
          *(_QWORD *)v13 = "TEXCOORD";
          *(_DWORD *)(v13 + 8) = 3;
          break;
        case 9:
          *(_QWORD *)v13 = "TEXCOORD";
          *(_DWORD *)(v13 + 8) = 4;
          break;
        case 0xA:
          *(_QWORD *)v13 = "TEXCOORD";
          *(_DWORD *)(v13 + 8) = 5;
          break;
        case 0xB:
          *(_QWORD *)v13 = "TEXCOORD";
          *(_DWORD *)(v13 + 8) = 6;
          break;
        case 0xC:
          *(_QWORD *)v13 = "TEXCOORD";
          *(_DWORD *)(v13 + 8) = 7;
          break;
        case 0xD:
          v16 = "BLENDINDICES";
          goto LABEL_28;
        case 0xE:
          v16 = "BLENDWEIGHT";
          goto LABEL_28;
        case 0xF:
          v16 = "BINORMAL";
LABEL_28:
          *(_QWORD *)v13 = v16;
LABEL_29:
          *(_DWORD *)(v13 + 8) = 0;
          break;
        default:
          break;
      }
      switch ( *(_DWORD *)(v15 + 4) )
      {
        case 0:
          *(_DWORD *)(v13 + 12) = 6;
          break;
        case 1:
          *(_DWORD *)(v13 + 12) = 2;
          break;
        case 2:
          *(_DWORD *)(v13 + 12) = 34;
          break;
        case 3:
          *(_DWORD *)(v13 + 12) = 30;
          break;
        case 4:
        case 5:
        case 6:
        case 0xF:
        case 0x10:
          *(_DWORD *)(v13 + 12) = 28;
          break;
        case 7:
          *(_DWORD *)(v13 + 12) = 10;
          break;
        case 9:
          *(_DWORD *)(v13 + 12) = 38;
          break;
        case 0xA:
        case 0xC:
        case 0xD:
          *(_DWORD *)(v13 + 12) = 14;
          break;
        case 0xB:
          *(_DWORD *)(v13 + 12) = 13;
          break;
        case 0xE:
          *(_DWORD *)(v13 + 12) = 42;
          break;
        default:
          break;
      }
      v17 = *(signed __int16 *)(v15 + 8);
      v18 = *(_DWORD *)&v2[116];
      v19 = 0;
      if ( _bittest(&v18, v17) )
      {
        v19 = 1;
        v17 = 4;
      }
      *(_DWORD *)(v13 + 16) = v17;
      v20 = v19 != 0;
      ++v9;
      *(_DWORD *)(v13 + 20) = -1;
      *(_DWORD *)(v13 + 24) = v20;
      *(_DWORD *)(v13 + 28) = v20;
      v11 += 32i64;
      v10 += 36i64;
    }
    while ( v9 < *(_DWORD *)&v2[96] );
  }
  _(v3);
}

// File Line: 116
// RVA: 0xA1F2F0
void __fastcall Illusion::IVertexDeclPlat::OnUnload(Illusion::IVertexDeclPlat *this)
{
  Illusion::VertexDecl *v1; // rbx
  __int64 v2; // rax
  AMD_HD3D *v3; // rdi
  UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor *v4; // rax
  UFG::qBaseNodeRB *v5; // rcx
  UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor result; // [rsp+28h] [rbp-20h]

  v1 = (Illusion::VertexDecl *)this;
  v2 = *(_QWORD *)&this[144];
  if ( v2 )
    v3 = (AMD_HD3D *)&this[v2 + 144];
  else
    v3 = 0i64;
  v4 = UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>>::operator->(
         &unk_14249AF60,
         &result);
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::RemoveObject(v4->mObj, v1);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)result.mLock.mMutex);
  _(v3);
  v5 = v1[1].mNode.mChild[0];
  if ( v5 )
  {
    operator delete[](v5);
    v1[1].mNode.mChild[0] = 0i64;
  }
}

