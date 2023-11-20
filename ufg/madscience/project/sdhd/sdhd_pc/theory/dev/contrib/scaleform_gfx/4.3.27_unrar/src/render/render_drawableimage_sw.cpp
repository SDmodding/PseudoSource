// File Line: 51
// RVA: 0x974490
void __fastcall Scaleform::Render::DICommand_Clear::ExecuteSW(Scaleform::Render::DICommand_Clear *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::DICommand_Clear *v4; // rbx
  Scaleform::Render::ImageData *v5; // rdi
  __int64 v6; // rax
  __int64 v7; // rax
  unsigned int v8; // ebp
  unsigned int i; // esi
  unsigned int j; // ebx
  __int64 v11; // [rsp+20h] [rbp-38h]
  __int64 v12; // [rsp+28h] [rbp-30h]
  Scaleform::Render::ImageData *v13; // [rsp+30h] [rbp-28h]
  int v14; // [rsp+38h] [rbp-20h]
  __int64 v15; // [rsp+40h] [rbp-18h]
  __int64 v16; // [rsp+48h] [rbp-10h]

  v4 = this;
  v5 = dest;
  v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::DICommandContext *, Scaleform::Render::ImageData *, Scaleform::Render::ImageData **))context->pHAL->vfptr[61].__vecDelDtor)(
         context->pHAL,
         context,
         dest,
         __formal);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 120i64))(v6);
  v13 = v5;
  v12 = 0i64;
  v14 = 0;
  v15 = 0i64;
  v11 = v7;
  v16 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v7 + 8i64))(v7, &v11);
  v8 = v4->FillColor.Raw;
  for ( i = 0; i < v5->pPlanes->Height; ++i )
  {
    (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v11 + 16i64))(v11, &v11, i);
    for ( j = 0; j < v5->pPlanes->Width; ++j )
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v11 + 24i64))(v11, &v11, j, v8);
  }
}

// File Line: 87
// RVA: 0x974580
void __fastcall Scaleform::Render::DICommand_ColorTransform::ExecuteSW(Scaleform::Render::DICommand_ColorTransform *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImagePlane *v4; // rax
  Scaleform::Render::ImageData **v5; // rsi
  signed int v6; // ebx
  signed int v7; // edi
  Scaleform::Render::ImagePlane *v8; // r10
  int v9; // eax
  signed int v10; // er11
  int v11; // er10
  int v12; // er12
  Scaleform::Render::ImageData *v13; // r14
  int v14; // er8
  Scaleform::Render::DICommandContext *v15; // r15
  int v16; // er9
  Scaleform::Render::DICommand_ColorTransform *v17; // r13
  int v18; // ecx
  int v19; // edx
  int v20; // edx
  int v21; // ecx
  int v22; // eax
  int v23; // er8
  __int128 v24; // xmm0
  __int128 v25; // xmm1
  int v26; // er9
  int v27; // er12
  Scaleform::Render::DrawableImage *v28; // rax
  float v29; // xmm9_4
  float v30; // xmm10_4
  bool v31; // zf
  float v32; // xmm11_4
  float v33; // xmm13_4
  float v34; // xmm14_4
  float v35; // xmm15_4
  __int64 v36; // rax
  __int64 v37; // rax
  __int64 v38; // rax
  Scaleform::Render::ImageData *v39; // rbx
  __int64 v40; // rax
  int v41; // er15
  signed int v42; // esi
  int v43; // er14
  int v44; // ebx
  int v45; // edi
  unsigned __int8 v46; // cl
  float v47; // xmm3_4
  float v48; // xmm2_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  char v51; // dl
  __int64 v52; // rax
  int v53; // [rsp+20h] [rbp-E0h]
  float v54; // [rsp+24h] [rbp-DCh]
  __int128 v55; // [rsp+30h] [rbp-D0h]
  __int128 v56; // [rsp+40h] [rbp-C0h]
  __int64 v57; // [rsp+50h] [rbp-B0h]
  __int64 v58; // [rsp+58h] [rbp-A8h]
  int v59; // [rsp+60h] [rbp-A0h]
  int v60; // [rsp+64h] [rbp-9Ch]
  __int64 *v61; // [rsp+68h] [rbp-98h]
  __int64 v62; // [rsp+70h] [rbp-90h]
  Scaleform::Render::ImageData *v63; // [rsp+78h] [rbp-88h]
  int v64; // [rsp+80h] [rbp-80h]
  __int64 v65; // [rsp+88h] [rbp-78h]
  __int64 v66; // [rsp+90h] [rbp-70h]
  int v67; // [rsp+180h] [rbp+80h]
  unsigned int v68; // [rsp+190h] [rbp+90h]
  float v69; // [rsp+198h] [rbp+98h]

  v4 = dest->pPlanes;
  v5 = psrc;
  v6 = v4->Width;
  v7 = v4->Height;
  v8 = (*psrc)->pPlanes;
  v9 = this->SourceRect.x1;
  v10 = v8->Width;
  v11 = v8->Height;
  v12 = this->DestPoint.x - v9;
  v13 = dest;
  v14 = this->SourceRect.y1;
  v15 = context;
  v16 = this->DestPoint.y - v14;
  v17 = this;
  v59 = this->DestPoint.x - v9;
  v67 = v16;
  if ( v11 >= v14 )
  {
    v18 = this->SourceRect.y2;
    if ( v18 >= 0 )
    {
      v19 = v17->SourceRect.x2;
      if ( v19 >= 0 && v10 >= v9 )
      {
        if ( v9 < 0 )
          v9 = 0;
        if ( v10 > v19 )
          v10 = v17->SourceRect.x2;
        if ( v14 < 0 )
          v14 = 0;
        v20 = v10 + v12;
        if ( v11 > v18 )
          v11 = v18;
        v21 = v9 + v12;
        v22 = v14 + v16;
        v23 = v11 + v16;
        if ( v11 + v16 >= 0 && v7 >= v22 && v6 >= v21 && v20 >= 0 )
        {
          v24 = *(_OWORD *)&v17->Cx.M[0][0];
          v25 = *(_OWORD *)&v17->Cx.M[1][0];
          v26 = 0;
          v27 = 0;
          if ( v21 > 0 )
            v26 = v21;
          if ( v20 > v6 )
            v20 = v6;
          v60 = v26;
          if ( v22 > 0 )
            v27 = v22;
          v28 = v17->pImage.pObject;
          v55 = v24;
          v56 = v25;
          v29 = *(float *)&v25;
          v30 = *((float *)&v56 + 1);
          if ( v23 > v7 )
            v23 = v7;
          v31 = v28->Transparent == 0;
          v68 = v20;
          v32 = *((float *)&v56 + 2);
          v33 = *(float *)&v55;
          v53 = v23;
          v35 = *((float *)&v55 + 2);
          v34 = *((float *)&v55 + 1);
          if ( v31 )
          {
            v54 = 0.0;
            v33 = *(float *)&v55 * (float)(*((float *)&v25 + 3) + *((float *)&v55 + 3));
            v29 = *(float *)&v25 * (float)(*((float *)&v25 + 3) + *((float *)&v55 + 3));
            v34 = *((float *)&v55 + 1) * (float)(*((float *)&v25 + 3) + *((float *)&v55 + 3));
            v69 = *(float *)&FLOAT_1_0;
            v30 = *((float *)&v56 + 1) * (float)(*((float *)&v25 + 3) + *((float *)&v55 + 3));
            v35 = *((float *)&v55 + 2) * (float)(*((float *)&v25 + 3) + *((float *)&v55 + 3));
            v32 = *((float *)&v56 + 2) * (float)(*((float *)&v25 + 3) + *((float *)&v55 + 3));
          }
          else
          {
            v54 = *((float *)&v25 + 3);
            v69 = *((float *)&v55 + 3);
          }
          v36 = ((__int64 (*)(void))v15->pHAL->vfptr[61].__vecDelDtor)();
          v37 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v36 + 120i64))(v36);
          v63 = v13;
          v62 = 0i64;
          v64 = 0;
          v65 = 0i64;
          v66 = 0i64;
          v61 = (__int64 *)v37;
          (*(void (__fastcall **)(__int64, __int64 **))(*(_QWORD *)v37 + 8i64))(v37, &v61);
          v38 = ((__int64 (*)(void))v15->pHAL->vfptr[61].__vecDelDtor)();
          v39 = *v5;
          v40 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v38 + 120i64))(v38);
          *(_QWORD *)&v56 = v39;
          DWORD2(v56) = 0;
          v57 = 0i64;
          v58 = 0i64;
          v55 = (unsigned __int64)v40;
          (*(void (__fastcall **)(__int64, __int128 *))(*(_QWORD *)v40 + 8i64))(v40, &v55);
          v41 = v53;
          if ( v27 < v53 )
          {
            v42 = v68;
            v43 = -v67;
            do
            {
              (*(void (__fastcall **)(__int64 *, __int64 **, _QWORD))(*v61 + 16))(v61, &v61, (unsigned int)v27);
              (*(void (__fastcall **)(_QWORD, __int128 *, _QWORD))(*(_QWORD *)v55 + 16i64))(
                v55,
                &v55,
                (unsigned int)(v43 + v27));
              v44 = v60;
              if ( v60 < v42 )
              {
                v45 = -v59;
                do
                {
                  (*(void (__fastcall **)(_QWORD, int *, __int128 *, _QWORD))(*(_QWORD *)v55 + 40i64))(
                    v55,
                    &v67,
                    &v55,
                    (unsigned int)(v45 + v44));
                  v46 = HIBYTE(v67);
                  if ( !v17->pSource.pObject->Transparent )
                    v46 = -1;
                  HIBYTE(v67) = v46;
                  v47 = (float)(v54 + (float)((float)((float)v46 * 0.0039215689) * v69)) * 256.0;
                  if ( v47 >= 255.0 )
                  {
                    v47 = FLOAT_255_0;
                  }
                  else if ( v47 < 0.0 )
                  {
                    v47 = 0.0;
                  }
                  v48 = (float)(v32 + (float)((float)((float)(unsigned __int8)v67 * 0.0039215689) * v35)) * 256.0;
                  if ( v48 >= 255.0 )
                  {
                    v48 = FLOAT_255_0;
                  }
                  else if ( v48 < 0.0 )
                  {
                    v48 = 0.0;
                  }
                  v49 = (float)(v30 + (float)((float)((float)BYTE1(v67) * 0.0039215689) * v34)) * 256.0;
                  if ( v49 >= 255.0 )
                  {
                    v49 = FLOAT_255_0;
                  }
                  else if ( v49 < 0.0 )
                  {
                    v49 = 0.0;
                  }
                  v50 = (float)(v29 + (float)((float)((float)BYTE2(v67) * 0.0039215689) * v33)) * 256.0;
                  if ( v50 >= 255.0 )
                  {
                    v50 = FLOAT_255_0;
                  }
                  else if ( v50 < 0.0 )
                  {
                    v50 = 0.0;
                  }
                  v31 = v17->pImage.pObject->Transparent == 0;
                  BYTE2(v68) = (signed int)v50;
                  BYTE1(v68) = (signed int)v49;
                  LOBYTE(v68) = (signed int)v48;
                  v51 = (signed int)v47;
                  v52 = *v61;
                  if ( v31 )
                    v51 = -1;
                  HIBYTE(v68) = v51;
                  (*(void (__fastcall **)(__int64 *, __int64 **, _QWORD, _QWORD))(v52 + 24))(
                    v61,
                    &v61,
                    (unsigned int)v44++,
                    v68);
                }
                while ( v44 < v42 );
                v41 = v53;
              }
              ++v27;
            }
            while ( v27 < v41 );
          }
        }
      }
    }
  }
}

// File Line: 156
// RVA: 0x974A90
void __fastcall Scaleform::Render::DICommand_Compare::ExecuteSW(Scaleform::Render::DICommand_Compare *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImageData *v4; // r14
  Scaleform::Render::DICommand_Compare *v5; // r15
  Scaleform::Render::ImageData **v6; // rsi
  Scaleform::Render::ImageData *v7; // rbx
  Scaleform::Render::DICommandContext *v8; // rdi
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rbx
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rbx
  __int64 v16; // rax
  unsigned int i; // edi
  unsigned int j; // ebx
  char v19; // al
  char v20; // r8
  char v21; // cl
  char v22; // dl
  char v23; // al
  char v24; // r9
  __int64 v25; // rax
  __int64 v26; // [rsp+20h] [rbp-69h]
  __int64 v27; // [rsp+28h] [rbp-61h]
  __int64 v28; // [rsp+30h] [rbp-59h]
  int v29; // [rsp+38h] [rbp-51h]
  __int64 v30; // [rsp+40h] [rbp-49h]
  __int64 v31; // [rsp+48h] [rbp-41h]
  __int64 v32; // [rsp+50h] [rbp-39h]
  __int64 v33; // [rsp+58h] [rbp-31h]
  __int64 v34; // [rsp+60h] [rbp-29h]
  int v35; // [rsp+68h] [rbp-21h]
  __int64 v36; // [rsp+70h] [rbp-19h]
  __int64 v37; // [rsp+78h] [rbp-11h]
  __int64 *v38; // [rsp+80h] [rbp-9h]
  __int64 v39; // [rsp+88h] [rbp-1h]
  Scaleform::Render::ImageData *v40; // [rsp+90h] [rbp+7h]
  int v41; // [rsp+98h] [rbp+Fh]
  __int64 v42; // [rsp+A0h] [rbp+17h]
  __int64 v43; // [rsp+A8h] [rbp+1Fh]
  char v44; // [rsp+F8h] [rbp+6Fh]
  char v45; // [rsp+F9h] [rbp+70h]
  char v46; // [rsp+FAh] [rbp+71h]
  char v47; // [rsp+FBh] [rbp+72h]
  char v48; // [rsp+100h] [rbp+77h]
  char v49; // [rsp+101h] [rbp+78h]
  char v50; // [rsp+102h] [rbp+79h]
  char v51; // [rsp+103h] [rbp+7Ah]
  unsigned int v52; // [rsp+108h] [rbp+7Fh]

  v4 = *psrc;
  v5 = this;
  v6 = psrc;
  v7 = dest;
  v8 = context;
  v9 = ((__int64 (*)(void))context->pHAL->vfptr[61].__vecDelDtor)();
  v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 120i64))(v9);
  v40 = v7;
  v39 = 0i64;
  v41 = 0;
  v42 = 0i64;
  v38 = (__int64 *)v10;
  v43 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 **))(*(_QWORD *)v10 + 8i64))(v10, &v38);
  v11 = ((__int64 (*)(void))v8->pHAL->vfptr[61].__vecDelDtor)();
  v12 = (__int64)*v6;
  v13 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 120i64))(v11);
  v33 = 0i64;
  v34 = v12;
  v35 = 0;
  v36 = 0i64;
  v37 = 0i64;
  v32 = v13;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v13 + 8i64))(v13, &v32);
  v14 = ((__int64 (*)(void))v8->pHAL->vfptr[61].__vecDelDtor)();
  v15 = (__int64)v6[1];
  v16 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 120i64))(v14);
  v27 = 0i64;
  v28 = v15;
  v29 = 0;
  v30 = 0i64;
  v31 = 0i64;
  v26 = v16;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v16 + 8i64))(v16, &v26);
  for ( i = 0; i < v4->pPlanes->Height; ++i )
  {
    (*(void (__fastcall **)(__int64 *, __int64 **, _QWORD))(*v38 + 16))(v38, &v38, i);
    (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v32 + 16i64))(v32, &v32, i);
    (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v26 + 16i64))(v26, &v26, i);
    for ( j = 0; j < v4->pPlanes->Width; ++j )
    {
      (*(void (__fastcall **)(__int64, char *, __int64 *, _QWORD))(*(_QWORD *)v32 + 40i64))(v32, &v44, &v32, j);
      (*(void (__fastcall **)(__int64, char *, __int64 *, _QWORD))(*(_QWORD *)v26 + 40i64))(v26, &v48, &v26, j);
      v19 = -1;
      v20 = -1;
      if ( v5->pSource.pObject->Transparent )
        v19 = v47;
      if ( v5->pImageCompare1.pObject->Transparent )
        v20 = v51;
      v21 = v45 - v49;
      v22 = v44 - v48;
      v23 = v19 - v20;
      v24 = v46 - v50;
      if ( v46 == v50 && v45 == v49 && v44 == v48 && v23 )
      {
        v24 = -1;
        v21 = -1;
        v22 = -1;
      }
      else
      {
        v23 = -1;
      }
      BYTE1(v52) = v21;
      HIBYTE(v52) = v23;
      v25 = *v38;
      LOBYTE(v52) = v22;
      BYTE2(v52) = v24;
      (*(void (__fastcall **)(__int64 *, __int64 **, _QWORD, _QWORD))(v25 + 24))(v38, &v38, j, v52);
    }
  }
}

// File Line: 212
// RVA: 0x974CD0
void __fastcall Scaleform::Render::DICommand_CopyChannel::ExecuteSW(Scaleform::Render::DICommand_CopyChannel *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImagePlane *v4; // rax
  Scaleform::Render::DICommand_CopyChannel *v5; // r14
  signed int v6; // ebx
  signed int v7; // edi
  Scaleform::Render::ImagePlane *v8; // rax
  signed int v9; // er11
  signed int v10; // er10
  int v11; // eax
  int v12; // ecx
  int v13; // er9
  int v14; // er13
  int v15; // edx
  int v16; // er8
  int v17; // er12
  int v18; // er15
  int v19; // edx
  int v20; // eax
  int v21; // esi
  int v22; // ebx
  __int64 v23; // rax
  char v24; // cl
  __int64 v25; // rax
  char v26; // al
  __int64 v27; // rax
  __int64 v28; // rax
  __int64 v29; // rax
  __int64 v30; // rdi
  __int64 v31; // rax
  int v32; // er13
  unsigned int v33; // esi
  int v34; // edi
  char v35; // cl
  char v36; // cl
  bool v37; // zf
  unsigned __int8 v38; // [rsp+20h] [rbp-79h]
  char v39; // [rsp+24h] [rbp-75h]
  char v40; // [rsp+25h] [rbp-74h]
  char v41; // [rsp+26h] [rbp-73h]
  char v42; // [rsp+27h] [rbp-72h]
  char v43; // [rsp+28h] [rbp-71h]
  char v44; // [rsp+29h] [rbp-70h]
  char v45; // [rsp+2Ah] [rbp-6Fh]
  char v46; // [rsp+2Bh] [rbp-6Eh]
  int v47; // [rsp+2Ch] [rbp-6Dh]
  int v48; // [rsp+30h] [rbp-69h]
  int v49; // [rsp+34h] [rbp-65h]
  int v50; // [rsp+38h] [rbp-61h]
  int v51; // [rsp+3Ch] [rbp-5Dh]
  __int64 v52; // [rsp+40h] [rbp-59h]
  __int64 v53; // [rsp+48h] [rbp-51h]
  Scaleform::Render::ImageData *v54; // [rsp+50h] [rbp-49h]
  int v55; // [rsp+58h] [rbp-41h]
  __int64 v56; // [rsp+60h] [rbp-39h]
  __int64 v57; // [rsp+68h] [rbp-31h]
  char *v58; // [rsp+70h] [rbp-29h]
  __int64 v59; // [rsp+80h] [rbp-19h]
  __int64 v60; // [rsp+88h] [rbp-11h]
  __int64 v61; // [rsp+90h] [rbp-9h]
  int v62; // [rsp+98h] [rbp-1h]
  __int64 v63; // [rsp+A0h] [rbp+7h]
  __int64 v64; // [rsp+A8h] [rbp+Fh]
  unsigned __int8 v65; // [rsp+100h] [rbp+67h]
  Scaleform::Render::DICommandContext *v66; // [rsp+108h] [rbp+6Fh]
  Scaleform::Render::ImageData *v67; // [rsp+110h] [rbp+77h]
  Scaleform::Render::ImageData **v68; // [rsp+118h] [rbp+7Fh]

  v68 = psrc;
  v67 = dest;
  v66 = context;
  v4 = dest->pPlanes;
  v5 = this;
  v6 = v4->Width;
  v7 = v4->Height;
  v8 = (*psrc)->pPlanes;
  v9 = v8->Height;
  v10 = v8->Width;
  v11 = this->SourceRect.x1;
  v12 = this->SourceRect.y1;
  v13 = v5->DestPoint.x - v11;
  v14 = v5->DestPoint.y - v12;
  v51 = v5->DestPoint.x - v11;
  if ( v9 >= v12 )
  {
    v15 = v5->SourceRect.y2;
    if ( v15 >= 0 )
    {
      v16 = v5->SourceRect.x2;
      if ( v16 >= 0 && v10 >= v11 )
      {
        v17 = 0;
        if ( v11 < 0 )
          v11 = 0;
        if ( v10 > v16 )
          v10 = v5->SourceRect.x2;
        if ( v12 < 0 )
          v12 = 0;
        v18 = v10 + v13;
        if ( v9 > v15 )
          v9 = v5->SourceRect.y2;
        v19 = v11 + v13;
        v20 = v12 + v14;
        v21 = v9 + v14;
        if ( v9 + v14 >= 0 && v7 >= v20 && v6 >= v19 && v18 >= 0 )
        {
          if ( v19 > 0 )
            v17 = v19;
          if ( v18 > v6 )
            v18 = v6;
          v22 = 0;
          if ( v20 > 0 )
            v22 = v12 + v14;
          v23 = v5->SourceChannel;
          if ( v21 > v7 )
            v21 = v7;
          v48 = v17;
          v47 = v22;
          v50 = v21;
          if ( (signed int)v23 > 8 )
            v24 = -1;
          else
            v24 = Scaleform::Render::ChannelIndexMap[v23];
          v25 = v5->DestChannel;
          v65 = v24;
          if ( (signed int)v25 > 8 )
            v26 = -1;
          else
            v26 = Scaleform::Render::ChannelIndexMap[v25];
          v38 = v26;
          if ( v24 != -1 && v26 != -1 )
          {
            v27 = (__int64)v66->pHAL->vfptr[61].__vecDelDtor(
                             (Scaleform::RefCountImplCore *)&v66->pHAL->vfptr,
                             (unsigned int)Scaleform::Render::ChannelIndexMap);
            v28 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v27 + 120i64))(v27);
            v53 = 0i64;
            v55 = 0;
            v56 = 0i64;
            v54 = v67;
            v57 = 0i64;
            v52 = v28;
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v28 + 8i64))(v28, &v52);
            v29 = ((__int64 (*)(void))v66->pHAL->vfptr[61].__vecDelDtor)();
            v30 = (__int64)*v68;
            v31 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v29 + 120i64))(v29);
            v61 = v30;
            v60 = 0i64;
            v62 = 0;
            v63 = 0i64;
            v64 = 0i64;
            v59 = v31;
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v31 + 8i64))(v31, &v59);
            if ( v22 < v21 )
            {
              v32 = -v14;
              v49 = v32;
              do
              {
                (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v52 + 16i64))(
                  v52,
                  &v52,
                  (unsigned int)v22);
                (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v59 + 16i64))(
                  v59,
                  &v59,
                  (unsigned int)(v22 + v32));
                v33 = v17;
                if ( v17 < v18 )
                {
                  v58 = &v43 + v65;
                  v34 = -v51;
                  do
                  {
                    (*(void (__fastcall **)(__int64, Scaleform::Render::ImageData **, __int64 *, _QWORD))(*(_QWORD *)v52 + 40i64))(
                      v52,
                      &v67,
                      &v52,
                      v33);
                    (*(void (__fastcall **)(__int64, char *, __int64 *, _QWORD))(*(_QWORD *)v59 + 40i64))(
                      v59,
                      &v39,
                      &v59,
                      v34 + v33);
                    v35 = v42;
                    LOBYTE(v68) = BYTE2(v67);
                    BYTE1(v68) = BYTE1(v67);
                    BYTE2(v68) = (_BYTE)v67;
                    BYTE3(v68) = BYTE3(v67);
                    v43 = v41;
                    v44 = v40;
                    v45 = v39;
                    if ( !v5->pSource.pObject->Transparent )
                      v35 = -1;
                    v46 = v35;
                    *((_BYTE *)&v68 + v38) = *(&v43 + v65);
                    v36 = BYTE3(v68);
                    v37 = v5->pImage.pObject->Transparent == 0;
                    BYTE2(v67) = (_BYTE)v68;
                    if ( v37 )
                      v36 = -1;
                    BYTE3(v67) = v36;
                    LOBYTE(v67) = BYTE2(v68);
                    BYTE1(v67) = BYTE1(v68);
                    (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v52 + 24i64))(
                      v52,
                      &v52,
                      v33++,
                      (unsigned int)v67);
                  }
                  while ( (signed int)v33 < v18 );
                  v22 = v47;
                  v17 = v48;
                  v32 = v49;
                }
                v47 = ++v22;
              }
              while ( v22 < v50 );
            }
          }
        }
      }
    }
  }
}

// File Line: 268
// RVA: 0x975020
void __fastcall Scaleform::Render::DICommand_CopyPixels::ExecuteSW(Scaleform::Render::DICommand_CopyPixels *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImagePlane *v4; // rax
  Scaleform::Render::ImageData *v5; // r15
  Scaleform::Render::DICommand_CopyPixels *v6; // rdi
  unsigned int v7; // ecx
  signed int v8; // er14
  Scaleform::Render::ImagePlane *v9; // rax
  signed int v10; // ebx
  int v11; // edx
  signed int v12; // er10
  int v13; // er11
  int v14; // esi
  int v15; // er12
  int v16; // er9
  int v17; // er8
  int v18; // er13
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // er12
  bool v23; // sf
  int v24; // ebx
  int v25; // er10
  int v26; // er13
  bool v27; // r14
  __int64 *v28; // rbx
  int v29; // ecx
  int v30; // er9
  int v31; // edx
  int v32; // er12
  int v33; // er13
  Scaleform::Render::ImagePlane *v34; // rax
  int v35; // er10
  int v36; // er11
  Scaleform::Render::ImagePlane *v37; // rax
  int v38; // er9
  int v39; // er8
  int v40; // eax
  int v41; // eax
  int v42; // ecx
  int v43; // edx
  int v44; // er13
  __int64 v45; // rax
  __int64 v46; // rax
  __int64 v47; // rax
  __int64 v48; // rbx
  __int64 v49; // rax
  __int64 v50; // rax
  __int64 v51; // rax
  int v52; // er15
  int v53; // ebx
  unsigned int v54; // ebx
  unsigned int v55; // esi
  signed int v56; // er13
  int v57; // er15
  int v58; // er12
  char v59; // cl
  int *v60; // rax
  int v61; // eax
  int v62; // edx
  signed int v63; // ecx
  float v64; // xmm2_4
  __int64 v65; // [rsp+20h] [rbp-E0h]
  int v66; // [rsp+20h] [rbp-E0h]
  __int64 v67; // [rsp+28h] [rbp-D8h]
  int v68; // [rsp+30h] [rbp-D0h]
  int v69; // [rsp+34h] [rbp-CCh]
  int v70; // [rsp+38h] [rbp-C8h]
  int v71; // [rsp+3Ch] [rbp-C4h]
  int v72; // [rsp+40h] [rbp-C0h]
  int v73; // [rsp+48h] [rbp-B8h]
  char v74; // [rsp+4Ch] [rbp-B4h]
  __int64 v75; // [rsp+50h] [rbp-B0h]
  __int64 v76; // [rsp+58h] [rbp-A8h]
  Scaleform::Render::ImageData *v77; // [rsp+60h] [rbp-A0h]
  int v78; // [rsp+68h] [rbp-98h]
  __int64 v79; // [rsp+70h] [rbp-90h]
  __int64 v80; // [rsp+78h] [rbp-88h]
  __int64 v81; // [rsp+80h] [rbp-80h]
  __int64 v82; // [rsp+88h] [rbp-78h]
  __int64 v83; // [rsp+90h] [rbp-70h]
  int v84; // [rsp+98h] [rbp-68h]
  __int64 v85; // [rsp+A0h] [rbp-60h]
  __int64 v86; // [rsp+A8h] [rbp-58h]
  __int64 v87; // [rsp+B0h] [rbp-50h]
  __int64 v88; // [rsp+B8h] [rbp-48h]
  Scaleform::Render::ImageData *v89; // [rsp+C0h] [rbp-40h]
  int v90; // [rsp+C8h] [rbp-38h]
  __int64 v91; // [rsp+D0h] [rbp-30h]
  __int64 v92; // [rsp+D8h] [rbp-28h]
  int v93; // [rsp+150h] [rbp+50h]
  int v94; // [rsp+150h] [rbp+50h]
  int v95; // [rsp+150h] [rbp+50h]
  Scaleform::Render::DICommandContext *v96; // [rsp+158h] [rbp+58h]
  Scaleform::Render::ImageData *v97; // [rsp+160h] [rbp+60h]
  Scaleform::Render::ImageData **v98; // [rsp+168h] [rbp+68h]

  v98 = psrc;
  v97 = dest;
  v96 = context;
  v4 = dest->pPlanes;
  v5 = *psrc;
  v6 = this;
  v7 = v4->Height;
  v8 = v4->Width;
  v9 = (*psrc)->pPlanes;
  v10 = v9->Height;
  v11 = v6->SourceRect.y1;
  v12 = v9->Width;
  v13 = v6->SourceRect.x1;
  LODWORD(v65) = v7;
  v93 = v6->DestPoint.y;
  v14 = v93 - v11;
  HIDWORD(v65) = v6->DestPoint.x;
  v15 = HIDWORD(v65) - v13;
  v70 = HIDWORD(v65) - v13;
  if ( v10 >= v11 )
  {
    v16 = v6->SourceRect.y2;
    if ( v16 >= 0 )
    {
      v17 = v6->SourceRect.x2;
      if ( v17 >= 0 && v12 >= v13 )
      {
        v18 = 0;
        v19 = v6->SourceRect.x1;
        v20 = v6->SourceRect.y1;
        if ( v13 < 0 )
          v19 = 0;
        if ( v12 > v17 )
          v12 = v6->SourceRect.x2;
        if ( v11 < 0 )
          v20 = 0;
        if ( v10 > v16 )
          v10 = v6->SourceRect.y2;
        v21 = v15 + v19;
        v22 = v12 + v15;
        v23 = v14 + v10 < 0;
        v24 = v14 + v10;
        v25 = v20 + v14;
        if ( !v23 && (signed int)v65 >= v25 && v8 >= v21 && v22 >= 0 )
        {
          if ( v21 > 0 )
            v18 = v21;
          if ( v22 > v8 )
            v22 = v8;
          v71 = v18;
          v26 = 0;
          HIDWORD(v67) = v22;
          if ( v25 > 0 )
            v26 = v20 + v14;
          if ( v24 > (signed int)v65 )
            v24 = v65;
          v69 = v26;
          v27 = v6->pAlphaSource.pObject != 0i64;
          v68 = v24;
          v28 = (__int64 *)v98;
          if ( !v6->pAlphaSource.pObject )
          {
            v94 = v93 - v11;
            HIDWORD(v65) -= v13;
LABEL_52:
            v45 = ((__int64 (*)(void))v96->pHAL->vfptr[61].__vecDelDtor)();
            v46 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v45 + 120i64))(v45);
            v76 = 0i64;
            v78 = 0;
            v79 = 0i64;
            v77 = v97;
            v80 = 0i64;
            v75 = v46;
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v46 + 8i64))(v46, &v75);
            v47 = ((__int64 (*)(void))v96->pHAL->vfptr[61].__vecDelDtor)();
            v48 = *v28;
            v49 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v47 + 120i64))(v47);
            v83 = v48;
            v82 = 0i64;
            v81 = v49;
            v84 = 0;
            v85 = 0i64;
            v86 = 0i64;
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v49 + 8i64))(v49, &v81);
            if ( !v27 )
              v5 = *v98;
            v50 = ((__int64 (*)(void))v96->pHAL->vfptr[61].__vecDelDtor)();
            v51 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v50 + 120i64))(v50);
            v88 = 0i64;
            v89 = v5;
            v90 = 0;
            v91 = 0i64;
            v92 = 0i64;
            v87 = v51;
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v51 + 8i64))(v51, &v87);
            if ( v26 < v68 )
            {
              v52 = v94 - v14;
              v53 = -v94;
              v95 = -v94;
              v72 = v52;
              do
              {
                (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v75 + 16i64))(
                  v75,
                  &v75,
                  (unsigned int)v26);
                v54 = v26 + v53;
                (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v81 + 16i64))(v81, &v81, v54 + v52);
                (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v87 + 16i64))(v87, &v87, v54);
                v55 = v71;
                if ( v71 < v22 )
                {
                  v56 = HIDWORD(v67);
                  v57 = HIDWORD(v65) - v70;
                  v58 = -HIDWORD(v65);
                  do
                  {
                    (*(void (__fastcall **)(__int64, Scaleform::Render::ImageData ***, __int64 *, _QWORD))(*(_QWORD *)v81 + 40i64))(
                      v81,
                      &v98,
                      &v81,
                      v58 + v55 + v57);
                    v59 = BYTE3(v98);
                    if ( !v6->pSource.pObject->Transparent )
                      v59 = -1;
                    BYTE3(v98) = v59;
                    if ( v27 )
                    {
                      (*(void (__fastcall **)(__int64, char *, __int64 *, _QWORD))(*(_QWORD *)v87 + 40i64))(
                        v87,
                        &v74,
                        &v87,
                        v58 + v55);
                      v60 = (int *)&v74;
                    }
                    else
                    {
                      v73 = (signed int)v98;
                      v60 = &v73;
                    }
                    v66 = *v60;
                    (*(void (__fastcall **)(__int64, Scaleform::Render::ImageData **, __int64 *, _QWORD))(*(_QWORD *)v75 + 40i64))(
                      v75,
                      &v97,
                      &v75,
                      v55);
                    if ( v27 )
                      v61 = HIBYTE(v66) + 1;
                    else
                      v61 = 256;
                    v62 = v61 * BYTE3(v98) >> 8;
                    LOBYTE(v63) = (unsigned __int16)(v61 * BYTE3(v98)) >> 8;
                    if ( v6->MergeAlpha )
                      v63 = (signed int)(float)((float)((float)((float)BYTE3(v97) * 0.0039215689)
                                                      * (float)(255 - (unsigned __int8)v62))
                                              + (float)(unsigned __int8)v62);
                    if ( !v6->pImage.pObject->Transparent )
                      LOBYTE(v63) = -1;
                    v64 = (float)(unsigned __int8)v62 / (float)(unsigned __int8)v63;
                    BYTE2(v67) = (signed int)(float)((float)((float)((float)((float)BYTE2(v98) - (float)BYTE2(v97)) * v64)
                                                           + (float)BYTE2(v97))
                                                   + 0.5);
                    BYTE1(v67) = (signed int)(float)((float)((float)((float)((float)BYTE1(v98) - (float)BYTE1(v97)) * v64)
                                                           + (float)BYTE1(v97))
                                                   + 0.5);
                    LOBYTE(v67) = (signed int)(float)((float)((float)((float)((float)(unsigned __int8)v98
                                                                            - (float)(unsigned __int8)v97)
                                                                    * v64)
                                                            + (float)(unsigned __int8)v97)
                                                    + 0.5);
                    BYTE3(v67) = (signed int)(float)((float)((float)((float)((float)BYTE3(v98) - (float)BYTE3(v97)) * v64)
                                                           + (float)BYTE3(v97))
                                                   + 0.5);
                    LODWORD(v65) = v67;
                    BYTE3(v65) = v63;
                    (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD, __int64, __int64))(*(_QWORD *)v75 + 24i64))(
                      v75,
                      &v75,
                      v55++,
                      (unsigned int)v65,
                      v65,
                      v67);
                  }
                  while ( (signed int)v55 < v56 );
                  v26 = v69;
                  v22 = HIDWORD(v67);
                  v52 = v72;
                }
                v53 = v95;
                v69 = ++v26;
              }
              while ( v26 < v68 );
            }
            return;
          }
          v29 = v6->AlphaPoint.x;
          v5 = v98[1];
          v30 = v16 - v11;
          v31 = v6->AlphaPoint.y;
          v32 = v17 - v13 + v29;
          v94 = v93 - v31;
          v33 = v30 + v31;
          v34 = v97->pPlanes;
          v35 = v34->Width;
          v36 = v34->Height;
          v37 = v5->pPlanes;
          v38 = v37->Height;
          v39 = v37->Width;
          v40 = HIDWORD(v65) - v29;
          HIDWORD(v65) -= v29;
          if ( v38 >= v31 && v33 >= 0 && v32 >= 0 && v39 >= v29 )
          {
            if ( v29 < 0 )
              v29 = 0;
            if ( v39 > v32 )
              v39 = v32;
            if ( v31 < 0 )
              v31 = 0;
            if ( v38 > v33 )
              v38 = v33;
            v22 = v39 + HIDWORD(v65);
            v41 = v29 + v40;
            v42 = v31 + v94;
            v43 = v38 + v94;
            if ( v38 + v94 >= 0 && v36 >= v42 && v35 >= v41 && v22 >= 0 )
            {
              v44 = 0;
              if ( v41 > 0 )
                v44 = v41;
              if ( v22 > v35 )
                v22 = v35;
              v71 = v44;
              v26 = 0;
              HIDWORD(v67) = v22;
              if ( v42 > 0 )
                v26 = v42;
              if ( v43 > v36 )
                v43 = v36;
              v69 = v26;
              v68 = v43;
              goto LABEL_52;
            }
          }
        }
      }
    }
  }
}              v71 = v44;
              v26 = 0;
              HIDWORD(v67) = v22;
              if ( v42 > 0 )
                v26 = v42;
              if ( v43 > v36 )
                v43 = v36;
              v69 = v26;
              v68 = v43;
              goto LABEL_52;
   

// File Line: 337
// RVA: 0x975630
void __fastcall Scaleform::Render::DICommand_FillRect::ExecuteSW(Scaleform::Render::DICommand_FillRect *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::DICommand_FillRect *v4; // r13
  Scaleform::Render::ImageData *v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rax
  Scaleform::Render::ImagePlane *v8; // rax
  int v9; // edi
  int v10; // er15
  int v11; // esi
  int v12; // eax
  int v13; // ecx
  int v14; // er14
  unsigned int v15; // ebp
  int i; // ebx
  __int64 v17; // [rsp+20h] [rbp-48h]
  __int64 v18; // [rsp+28h] [rbp-40h]
  Scaleform::Render::ImageData *v19; // [rsp+30h] [rbp-38h]
  int v20; // [rsp+38h] [rbp-30h]
  __int64 v21; // [rsp+40h] [rbp-28h]
  __int64 v22; // [rsp+48h] [rbp-20h]

  v4 = this;
  v5 = dest;
  v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::DICommandContext *, Scaleform::Render::ImageData *, Scaleform::Render::ImageData **))context->pHAL->vfptr[61].__vecDelDtor)(
         context->pHAL,
         context,
         dest,
         __formal);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 120i64))(v6);
  v19 = v5;
  v18 = 0i64;
  v20 = 0;
  v21 = 0i64;
  v17 = v7;
  v22 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v7 + 8i64))(v7, &v17);
  v8 = v5->pPlanes;
  v9 = v4->ApplyRect.y1;
  v10 = v8->Height;
  v11 = v8->Width;
  if ( v10 >= v9 )
  {
    v12 = v4->ApplyRect.y2;
    if ( v12 >= 0 )
    {
      v13 = v4->ApplyRect.x2;
      if ( v13 >= 0 )
      {
        v14 = v4->ApplyRect.x1;
        if ( v11 >= v14 )
        {
          if ( v14 < 0 )
            v14 = 0;
          if ( v11 > v13 )
            v11 = v4->ApplyRect.x2;
          if ( v9 < 0 )
            v9 = 0;
          v15 = v4->FillColor.Raw;
          if ( v10 > v12 )
            v10 = v4->ApplyRect.y2;
          if ( !v4->pImage.pObject->Transparent )
            v15 |= 0xFF000000;
          for ( ; v9 < v10; ++v9 )
          {
            (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v17 + 16i64))(v17, &v17, (unsigned int)v9);
            for ( i = v14; i < v11; ++i )
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v17 + 24i64))(
                v17,
                &v17,
                (unsigned int)i,
                v15);
          }
        }
      }
    }
  }
}

// File Line: 365
// RVA: 0x975780
void __fastcall Scaleform::Render::DICommand_FloodFill::ExecuteSW(Scaleform::Render::DICommand_FloodFill *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::ImageData *v4; // rdi
  Scaleform::Render::DICommandContext *v5; // rsi
  Scaleform::Render::DICommand_FloodFill *v6; // rbx
  Scaleform::Render::ImagePlane *v7; // rax
  int v8; // er13
  signed int v9; // er12
  int v10; // eax
  int v11; // eax
  unsigned int v12; // ecx
  __int64 v13; // rax
  __int64 v14; // rax
  int v15; // edi
  int v16; // esi
  unsigned __int64 v18; // r8
  Scaleform::String *v19; // rcx
  unsigned __int64 i; // rcx
  int v21; // edi
  signed int v22; // esi
  signed int v23; // edx
  int v24; // er8
  int v25; // ecx
  int v26; // eax
  int v27; // er14
  int v28; // er15
  int v29; // ebx
  unsigned __int64 v30; // rbx
  unsigned __int64 v31; // r8
  Scaleform::String *v32; // rcx
  unsigned __int64 v33; // rbx
  unsigned __int64 v34; // r8
  Scaleform::String *v35; // rcx
  unsigned __int64 v36; // rbx
  unsigned __int64 v37; // r8
  Scaleform::String *v38; // rcx
  unsigned __int64 v39; // rbx
  unsigned __int64 v40; // r8
  Scaleform::String *v41; // rcx
  Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+20h] [rbp-79h]
  Scaleform::String *v43; // [rsp+38h] [rbp-61h]
  Scaleform::String *v44; // [rsp+40h] [rbp-59h]
  int v45; // [rsp+48h] [rbp-51h]
  void *v46; // [rsp+50h] [rbp-49h]
  __int128 v47; // [rsp+58h] [rbp-41h]
  Scaleform::Render::ImageData *v48; // [rsp+68h] [rbp-31h]
  int v49; // [rsp+70h] [rbp-29h]
  __int64 v50; // [rsp+78h] [rbp-21h]
  __int64 v51; // [rsp+80h] [rbp-19h]
  __int128 v52; // [rsp+88h] [rbp-11h]
  Scaleform::Render::ImageData *v53; // [rsp+98h] [rbp-1h]
  int v54; // [rsp+A0h] [rbp+7h]
  __int64 v55; // [rsp+A8h] [rbp+Fh]
  __int64 v56; // [rsp+B0h] [rbp+17h]
  __int64 v57; // [rsp+B8h] [rbp+1Fh]
  unsigned int v58; // [rsp+100h] [rbp+67h]
  int v59; // [rsp+110h] [rbp+77h]

  v57 = -2i64;
  v4 = dest;
  v5 = context;
  v6 = this;
  v7 = dest->pPlanes;
  v8 = v7->Height;
  v45 = v7->Height;
  v9 = v7->Width;
  v10 = this->Pt.x;
  if ( v10 <= v9 && v10 >= 0 )
  {
    v11 = this->Pt.y;
    if ( v11 <= v8 && v11 >= 0 )
    {
      v12 = this->FillColor.Raw;
      v58 = v12;
      if ( !v6->pImage.pObject->Transparent )
        v58 = v12 | 0xFF000000;
      v13 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::DICommandContext *, Scaleform::Render::ImageData *, Scaleform::Render::ImageData **))context->pHAL->vfptr[61].__vecDelDtor)(
              context->pHAL,
              context,
              dest,
              __formal);
      v52 = (unsigned __int64)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v13 + 120i64))(v13);
      v53 = v4;
      v54 = 0;
      v55 = 0i64;
      v56 = 0i64;
      (*(void (__fastcall **)(_QWORD, __int128 *))(*(_QWORD *)v52 + 8i64))(v52, &v52);
      v14 = ((__int64 (*)(void))v5->pHAL->vfptr[61].__vecDelDtor)();
      v47 = (unsigned __int64)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 120i64))(v14);
      v48 = v4;
      v49 = 0;
      v50 = 0i64;
      v51 = 0i64;
      (*(void (__fastcall **)(_QWORD, __int128 *))(*(_QWORD *)v47 + 8i64))(v47, &v47);
      (*(void (__fastcall **)(_QWORD, __int128 *, _QWORD))(*(_QWORD *)v47 + 16i64))(v47, &v47, (unsigned int)v6->Pt.y);
      (*(void (__fastcall **)(_QWORD, int *, __int128 *, _QWORD))(*(_QWORD *)v47 + 40i64))(
        v47,
        &v59,
        &v47,
        (unsigned int)v6->Pt.x);
      v46 = &pheapAddr;
      pheapAddr.Data = 0i64;
      pheapAddr.Size = 0i64;
      pheapAddr.Policy.Capacity = 0i64;
      v15 = v6->Pt.y;
      v16 = v6->Pt.x;
      if ( pheapAddr.Policy.Capacity < 1 )
      {
        v18 = 1i64;
        Scaleform::ArrayDataBase<Scaleform::Render::ImageFileHandler *,Scaleform::AllocatorGH<Scaleform::Render::ImageFileHandler *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v18);
      }
      pheapAddr.Size = 1i64;
      v19 = pheapAddr.Data;
      v46 = pheapAddr.Data;
      v43 = pheapAddr.Data;
      if ( pheapAddr.Data )
      {
        LODWORD(pheapAddr.Data->pData) = v16;
        HIDWORD(v19->HeapTypeBits) = v15;
      }
      for ( i = pheapAddr.Size; pheapAddr.Size; i = pheapAddr.Size )
      {
        v21 = *((_DWORD *)&pheapAddr.Data[i] - 1);
        v22 = (signed int)pheapAddr.Data[i - 1].pData;
        Scaleform::ArrayData<Scaleform::Render::Point<long>,Scaleform::AllocatorGH<Scaleform::Render::Point<long>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
          (Scaleform::ArrayData<Scaleform::Render::Point<long>,Scaleform::AllocatorGH<Scaleform::Render::Point<long>,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
          i - 1);
        v23 = 0;
        v24 = 0;
        v25 = 0;
        v26 = 0;
        v27 = v21 + 1;
        v28 = v22 + 1;
        if ( v8 >= v21 && v27 >= 0 && v28 >= 0 && v9 >= v22 )
        {
          v23 = v22;
          if ( v22 < 0 )
            v23 = 0;
          v25 = v9;
          if ( v9 > v28 )
            v25 = v22 + 1;
          v24 = v21;
          if ( v21 < 0 )
            v24 = 0;
          v26 = v8;
          if ( v8 > v27 )
            v26 = v21 + 1;
        }
        if ( (v25 - v23) * (v26 - v24) <= 0 )
          continue;
        (*(void (__fastcall **)(_QWORD, __int128 *, _QWORD))(*(_QWORD *)v47 + 16i64))(v47, &v47, (unsigned int)v21);
        v29 = v59;
        (*(void (__fastcall **)(_QWORD, void **, __int128 *, _QWORD))(*(_QWORD *)v47 + 40i64))(
          v47,
          &v46,
          &v47,
          (unsigned int)v22);
        if ( (_DWORD)v46 != v29 )
          continue;
        (*(void (__fastcall **)(_QWORD, __int128 *, _QWORD))(*(_QWORD *)v52 + 16i64))(v52, &v52, (unsigned int)v21);
        (*(void (__fastcall **)(_QWORD, __int128 *, _QWORD, _QWORD))(*(_QWORD *)v52 + 24i64))(
          v52,
          &v52,
          (unsigned int)v22,
          v58);
        v30 = pheapAddr.Size + 1;
        if ( pheapAddr.Size + 1 >= pheapAddr.Size )
        {
          if ( v30 <= pheapAddr.Policy.Capacity )
            goto LABEL_36;
          v31 = v30 + (v30 >> 2);
        }
        else
        {
          if ( v30 >= pheapAddr.Policy.Capacity >> 1 )
            goto LABEL_36;
          v31 = pheapAddr.Size + 1;
        }
        Scaleform::ArrayDataBase<Scaleform::Render::ImageFileHandler *,Scaleform::AllocatorGH<Scaleform::Render::ImageFileHandler *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v31);
LABEL_36:
        pheapAddr.Size = v30;
        v32 = &pheapAddr.Data[v30 - 1];
        v43 = &pheapAddr.Data[v30 - 1];
        v44 = &pheapAddr.Data[v30 - 1];
        if ( v32 )
        {
          LODWORD(v32->pData) = v22 - 1;
          HIDWORD(v32->HeapTypeBits) = v21;
        }
        v33 = pheapAddr.Size + 1;
        if ( pheapAddr.Size + 1 >= pheapAddr.Size )
        {
          if ( v33 <= pheapAddr.Policy.Capacity )
            goto LABEL_44;
          v34 = v33 + (v33 >> 2);
        }
        else
        {
          if ( v33 >= pheapAddr.Policy.Capacity >> 1 )
            goto LABEL_44;
          v34 = pheapAddr.Size + 1;
        }
        Scaleform::ArrayDataBase<Scaleform::Render::ImageFileHandler *,Scaleform::AllocatorGH<Scaleform::Render::ImageFileHandler *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v34);
LABEL_44:
        pheapAddr.Size = v33;
        v35 = &pheapAddr.Data[v33 - 1];
        v44 = &pheapAddr.Data[v33 - 1];
        v43 = &pheapAddr.Data[v33 - 1];
        if ( v35 )
        {
          LODWORD(v35->pData) = v22;
          HIDWORD(v35->HeapTypeBits) = v21 - 1;
        }
        v36 = pheapAddr.Size + 1;
        if ( pheapAddr.Size + 1 >= pheapAddr.Size )
        {
          if ( v36 <= pheapAddr.Policy.Capacity )
            goto LABEL_52;
          v37 = v36 + (v36 >> 2);
        }
        else
        {
          if ( v36 >= pheapAddr.Policy.Capacity >> 1 )
            goto LABEL_52;
          v37 = pheapAddr.Size + 1;
        }
        Scaleform::ArrayDataBase<Scaleform::Render::ImageFileHandler *,Scaleform::AllocatorGH<Scaleform::Render::ImageFileHandler *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v37);
LABEL_52:
        pheapAddr.Size = v36;
        v38 = &pheapAddr.Data[v36 - 1];
        v44 = &pheapAddr.Data[v36 - 1];
        v43 = &pheapAddr.Data[v36 - 1];
        if ( v38 )
        {
          LODWORD(v38->pData) = v22;
          HIDWORD(v38->HeapTypeBits) = v27;
        }
        v39 = pheapAddr.Size + 1;
        if ( pheapAddr.Size + 1 >= pheapAddr.Size )
        {
          if ( v39 > pheapAddr.Policy.Capacity )
          {
            v40 = v39 + (v39 >> 2);
            goto LABEL_59;
          }
        }
        else if ( v39 < pheapAddr.Policy.Capacity >> 1 )
        {
          v40 = pheapAddr.Size + 1;
LABEL_59:
          Scaleform::ArrayDataBase<Scaleform::Render::ImageFileHandler *,Scaleform::AllocatorGH<Scaleform::Render::ImageFileHandler *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            v40);
          goto LABEL_60;
        }
LABEL_60:
        pheapAddr.Size = v39;
        v41 = &pheapAddr.Data[v39 - 1];
        v44 = &pheapAddr.Data[v39 - 1];
        v43 = &pheapAddr.Data[v39 - 1];
        if ( v41 )
        {
          LODWORD(v41->pData) = v28;
          HIDWORD(v41->HeapTypeBits) = v21;
        }
        v8 = v45;
      }
      if ( pheapAddr.Data )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
  }
}

// File Line: 407
// RVA: 0x975BE0
void __fastcall Scaleform::Render::DICommand_GetColorBoundsRect::ExecuteSW(Scaleform::Render::DICommand_GetColorBoundsRect *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::DICommand_GetColorBoundsRect *v4; // rdi
  Scaleform::Render::ImageData *v5; // rbp
  __int64 v6; // rax
  __int64 v7; // rax
  unsigned int v8; // ebx
  Scaleform::Render::ImagePlane *v9; // rax
  char v10; // cl
  int v11; // er14
  int v12; // er15
  int v13; // er12
  int v14; // er13
  unsigned int v15; // esi
  int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  int v19; // eax
  int v20; // eax
  Scaleform::Render::Rect<long> *v21; // rax
  __int64 v22; // [rsp+20h] [rbp-68h]
  __int64 v23; // [rsp+28h] [rbp-60h]
  Scaleform::Render::ImageData *v24; // [rsp+30h] [rbp-58h]
  int v25; // [rsp+38h] [rbp-50h]
  __int64 v26; // [rsp+40h] [rbp-48h]
  __int64 v27; // [rsp+48h] [rbp-40h]
  char v28; // [rsp+90h] [rbp+8h]
  int v29; // [rsp+98h] [rbp+10h]

  v4 = this;
  v5 = dest;
  v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::DICommandContext *, Scaleform::Render::ImageData *, Scaleform::Render::ImageData **))context->pHAL->vfptr[61].__vecDelDtor)(
         context->pHAL,
         context,
         dest,
         __formal);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 120i64))(v6);
  v8 = 0;
  v24 = v5;
  v23 = 0i64;
  v25 = 0;
  v26 = 0i64;
  v22 = v7;
  v27 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v7 + 8i64))(v7, &v22);
  v9 = v5->pPlanes;
  v10 = 0;
  v11 = v9->Height;
  v12 = v9->Width;
  v28 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  if ( v11 )
  {
    do
    {
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v22 + 16i64))(v22, &v22, v15);
      if ( v5->pPlanes->Width )
      {
        do
        {
          (*(void (__fastcall **)(__int64, int *, __int64 *, _QWORD))(*(_QWORD *)v22 + 40i64))(v22, &v29, &v22, v8);
          v16 = v29 & v4->Mask;
          if ( v4->FindColor )
          {
            if ( v16 == v4->SearchColor )
              goto LABEL_7;
          }
          else if ( v16 != v4->SearchColor )
          {
LABEL_7:
            v17 = v8;
            v28 = 1;
            if ( v12 < (signed int)v8 )
              v17 = v12;
            v12 = v17;
            v18 = v15;
            if ( v11 < (signed int)v15 )
              v18 = v11;
            v11 = v18;
            v19 = v8 + 1;
            if ( (signed int)(v8 + 1) < v13 )
              v19 = v13;
            v13 = v19;
            v20 = v15 + 1;
            if ( (signed int)(v15 + 1) < v14 )
              v20 = v14;
            v14 = v20;
            goto LABEL_16;
          }
LABEL_16:
          ++v8;
        }
        while ( v8 < v5->pPlanes->Width );
      }
      ++v15;
      v8 = 0;
    }
    while ( v15 < v5->pPlanes->Height );
    v10 = v28;
  }
  v21 = v4->Result;
  if ( v21 )
  {
    if ( v10 )
    {
      v21->x1 = v12;
      v21->y1 = v11;
      v21->x2 = v13;
      v21->y2 = v14;
    }
    else
    {
      *(_QWORD *)&v21->x1 = 0i64;
      *(_QWORD *)&v21->x2 = 0i64;
    }
  }
}

// File Line: 442
// RVA: 0x975D70
void __fastcall Scaleform::Render::DICommand_GetPixel32::ExecuteSW(Scaleform::Render::DICommand_GetPixel32 *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::DICommand_GetPixel32 *v4; // rdi
  Scaleform::Render::ImageData *v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rax
  __int128 v8; // [rsp+20h] [rbp-38h]
  Scaleform::Render::ImageData *v9; // [rsp+30h] [rbp-28h]
  int v10; // [rsp+38h] [rbp-20h]
  __int64 v11; // [rsp+40h] [rbp-18h]
  __int64 v12; // [rsp+48h] [rbp-10h]
  Scaleform::Render::Color v13; // [rsp+60h] [rbp+8h]

  v4 = this;
  v5 = dest;
  v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::DICommandContext *, Scaleform::Render::ImageData *, Scaleform::Render::ImageData **))context->pHAL->vfptr[61].__vecDelDtor)(
         context->pHAL,
         context,
         dest,
         __formal);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 120i64))(v6);
  v9 = v5;
  v10 = 0;
  v11 = 0i64;
  v12 = 0i64;
  v8 = (unsigned __int64)v7;
  (*(void (__fastcall **)(__int64, __int128 *))(*(_QWORD *)v7 + 8i64))(v7, &v8);
  (*(void (__fastcall **)(_QWORD, __int128 *, _QWORD))(*(_QWORD *)v8 + 16i64))(v8, &v8, v4->Y);
  if ( v4->Result )
  {
    (*(void (__fastcall **)(_QWORD, Scaleform::Render::Color *, __int128 *, _QWORD))(*(_QWORD *)v8 + 40i64))(
      v8,
      &v13,
      &v8,
      v4->X);
    *v4->Result = v13;
  }
}

// File Line: 450
// RVA: 0x975E10
void __fastcall Scaleform::Render::DICommand_GetPixels::ExecuteSW(Scaleform::Render::DICommand_GetPixels *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::DICommand_GetPixels *v4; // rdi
  Scaleform::Render::ImageData *v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rax
  int i; // esi
  int j; // ebx
  __int64 v10; // [rsp+20h] [rbp-38h]
  __int64 v11; // [rsp+28h] [rbp-30h]
  Scaleform::Render::ImageData *v12; // [rsp+30h] [rbp-28h]
  int v13; // [rsp+38h] [rbp-20h]
  __int64 v14; // [rsp+40h] [rbp-18h]
  __int64 v15; // [rsp+48h] [rbp-10h]
  unsigned int v16; // [rsp+60h] [rbp+8h]

  v4 = this;
  v5 = dest;
  v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::DICommandContext *, Scaleform::Render::ImageData *, Scaleform::Render::ImageData **))context->pHAL->vfptr[61].__vecDelDtor)(
         context->pHAL,
         context,
         dest,
         __formal);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 120i64))(v6);
  v12 = v5;
  v11 = 0i64;
  v13 = 0;
  v14 = 0i64;
  v15 = 0i64;
  v10 = v7;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v7 + 8i64))(v7, &v10);
  for ( i = v4->SourceRect.y1; i < v4->SourceRect.y2; ++i )
  {
    (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v10 + 16i64))(v10, &v10, (unsigned int)i);
    for ( j = v4->SourceRect.x1; j < v4->SourceRect.x2; ++j )
    {
      (*(void (__fastcall **)(__int64, unsigned int *, __int64 *, _QWORD))(*(_QWORD *)v10 + 40i64))(
        v10,
        &v16,
        &v10,
        (unsigned int)j);
      v4->Provider->vfptr->WriteNextPixel(v4->Provider, v16);
    }
  }
}

// File Line: 466
// RVA: 0x975EF0
void __fastcall Scaleform::Render::DICommand_Histogram::ExecuteSW(Scaleform::Render::DICommand_Histogram *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dst, Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::DICommand_Histogram *v4; // rdi
  Scaleform::Render::ImageData *v5; // rbp
  __int64 v6; // rax
  __int64 v7; // rax
  int v8; // esi
  Scaleform::Render::ImagePlane *v9; // rax
  int v10; // edx
  int v11; // ebx
  Scaleform::Render::ImagePlane *v12; // rax
  int v13; // edx
  unsigned int v14; // edx
  __int64 v15; // rcx
  Scaleform::Render::ImagePlane *v16; // rax
  int v17; // edx
  Scaleform::Render::ImagePlane *v18; // rax
  int v19; // edx
  __int64 v20; // [rsp+20h] [rbp-48h]
  __int64 v21; // [rsp+28h] [rbp-40h]
  Scaleform::Render::ImageData *v22; // [rsp+30h] [rbp-38h]
  int v23; // [rsp+38h] [rbp-30h]
  __int64 v24; // [rsp+40h] [rbp-28h]
  __int64 v25; // [rsp+48h] [rbp-20h]
  unsigned int v26; // [rsp+70h] [rbp+8h]

  v4 = this;
  v5 = dst;
  v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::DICommandContext *, Scaleform::Render::ImageData *, Scaleform::Render::ImageData **))context->pHAL->vfptr[61].__vecDelDtor)(
         context->pHAL,
         context,
         dst,
         __formal);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 120i64))(v6);
  v22 = v5;
  v21 = 0i64;
  v23 = 0;
  v24 = 0i64;
  v20 = v7;
  v25 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v7 + 8i64))(v7, &v20);
  v8 = v4->SourceRect.y1;
  v9 = v5->pPlanes;
  v10 = v4->SourceRect.y2;
  if ( v8 < 0 )
    v8 = 0;
  if ( (signed int)v9->Height < v10 )
    v10 = v9->Height;
  if ( v8 < v10 )
  {
    do
    {
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v20 + 16i64))(v20, &v20, (unsigned int)v8);
      v11 = v4->SourceRect.x1;
      v12 = v5->pPlanes;
      v13 = v4->SourceRect.x2;
      if ( v11 < 0 )
        v11 = 0;
      if ( (signed int)v12->Width < v13 )
        v13 = v12->Width;
      if ( v11 < v13 )
      {
        do
        {
          (*(void (__fastcall **)(__int64, unsigned int *, __int64 *, _QWORD))(*(_QWORD *)v20 + 40i64))(
            v20,
            &v26,
            &v20,
            (unsigned int)v11);
          v14 = v26 >> 8;
          ++v11;
          ++v4->Result[(unsigned __int8)v26 + 512];
          v15 = (unsigned int)(unsigned __int8)v14 + 256;
          v14 >>= 8;
          ++v4->Result[v15];
          ++v4->Result[(unsigned __int8)v14];
          ++v4->Result[BYTE1(v14) + 768];
          v16 = v5->pPlanes;
          v17 = v4->SourceRect.x2;
          if ( (signed int)v16->Width < v17 )
            v17 = v16->Width;
        }
        while ( v11 < v17 );
      }
      v18 = v5->pPlanes;
      v19 = v4->SourceRect.y2;
      ++v8;
      if ( (signed int)v18->Height < v19 )
        v19 = v18->Height;
    }
    while ( v8 < v19 );
  }
}

// File Line: 487
// RVA: 0x976040
void __fastcall Scaleform::Render::DICommand_HitTest::ExecuteSW(Scaleform::Render::DICommand_HitTest *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::DICommand_HitTest *v4; // r14
  Scaleform::RefCountImplCoreVtbl *v5; // rax
  Scaleform::Render::ImageData **v6; // r12
  Scaleform::Render::ImageData *v7; // r15
  Scaleform::Render::DICommandContext *v8; // rbx
  __int64 v9; // rax
  __int64 v10; // rax
  Scaleform::Render::ImagePlane *v11; // rax
  int v12; // ecx
  int v13; // esi
  int v14; // eax
  int v15; // er12
  int v16; // eax
  int v17; // edi
  int v18; // eax
  int v19; // ebx
  bool *v20; // rax
  __int64 v21; // rax
  __int64 v22; // rax
  __int64 v23; // rax
  __int64 v24; // rbx
  __int64 v25; // rax
  Scaleform::Render::Image *v26; // rdi
  unsigned int v27; // esi
  unsigned int v28; // ebx
  unsigned int *v29; // rax
  unsigned int v30; // er8
  int v31; // ecx
  unsigned int v32; // er13
  int v33; // ebx
  int v34; // eax
  int v35; // esi
  int v36; // ebx
  int v37; // ecx
  int v38; // ebx
  int v39; // eax
  int v40; // edi
  int v41; // ebx
  bool *v42; // rax
  __int64 v43; // [rsp+20h] [rbp-39h]
  __int64 v44; // [rsp+28h] [rbp-31h]
  Scaleform::Render::ImageData *v45; // [rsp+30h] [rbp-29h]
  int v46; // [rsp+38h] [rbp-21h]
  __int64 v47; // [rsp+40h] [rbp-19h]
  __int64 v48; // [rsp+48h] [rbp-11h]
  char v49; // [rsp+50h] [rbp-9h]
  unsigned __int8 v50; // [rsp+53h] [rbp-6h]
  char v51; // [rsp+58h] [rbp-1h]
  unsigned __int8 v52; // [rsp+5Bh] [rbp+2h]
  __int64 v53; // [rsp+60h] [rbp+7h]
  __int64 v54; // [rsp+68h] [rbp+Fh]
  __int64 v55; // [rsp+70h] [rbp+17h]
  int v56; // [rsp+78h] [rbp+1Fh]
  __int64 v57; // [rsp+80h] [rbp+27h]
  __int64 v58; // [rsp+88h] [rbp+2Fh]
  unsigned int v59; // [rsp+C0h] [rbp+67h]

  v4 = this;
  v5 = context->pHAL->vfptr;
  v6 = psrc;
  v7 = dest;
  v8 = context;
  if ( this->SecondImage.pObject )
  {
    v21 = ((__int64 (*)(void))v5[61].__vecDelDtor)();
    v22 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v21 + 120i64))(v21);
    v45 = v7;
    v44 = 0i64;
    v46 = 0;
    v47 = 0i64;
    v43 = v22;
    v48 = 0i64;
    (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v22 + 8i64))(v22, &v43);
    v23 = ((__int64 (*)(void))v8->pHAL->vfptr[61].__vecDelDtor)();
    v24 = (__int64)*v6;
    v25 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v23 + 120i64))(v23);
    v54 = 0i64;
    v55 = v24;
    v56 = 0;
    v57 = 0i64;
    v58 = 0i64;
    v53 = v25;
    (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v25 + 8i64))(v25, &v53);
    v26 = v4->SecondImage.pObject;
    v27 = v7->pPlanes->Height;
    v59 = *(_DWORD *)((__int64)v26->vfptr[5].__vecDelDtor(
                                 (Scaleform::RefCountImplCore *)&v4->SecondImage.pObject->vfptr,
                                 (unsigned int)&v49)
                    + 4);
    v28 = v7->pPlanes->Width;
    v29 = (unsigned int *)v26->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v26->vfptr, (unsigned int)&v51);
    v30 = v59;
    v31 = v4->SecondPoint.y;
    v32 = *v29;
    if ( v28 < *v29 )
      v32 = v28;
    v33 = v4->FirstPoint.y;
    if ( v27 < v59 )
      v30 = v27;
    v34 = v4->SecondPoint.y - v33;
    v35 = v34;
    v59 = v30;
    if ( v34 < 0 )
      v35 = 0;
    if ( v35 < (signed int)(v30 + v34) )
    {
      do
      {
        v36 = v35 + v33 - v31;
        if ( v35 < 0 || v35 >= (signed int)v7->pPlanes->Height || v36 < 0 || v36 >= (signed int)(*v6)->pPlanes->Height )
          break;
        (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v43 + 16i64))(v43, &v43, (unsigned int)v35);
        (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v53 + 16i64))(v53, &v53, (unsigned int)v36);
        v37 = v4->SecondPoint.x;
        v38 = v4->FirstPoint.x;
        v39 = v4->SecondPoint.x - v38;
        v40 = v39;
        if ( v39 < 0 )
          v40 = 0;
        if ( v40 < (signed int)(v32 + v39) )
        {
          do
          {
            v41 = v40 + v38 - v37;
            if ( v40 < 0 || v40 >= (signed int)v7->pPlanes->Width || v41 < 0 || v41 >= (signed int)(*v6)->pPlanes->Width )
              break;
            (*(void (__fastcall **)(__int64, char *, __int64 *, _QWORD))(*(_QWORD *)v43 + 40i64))(
              v43,
              &v51,
              &v43,
              (unsigned int)v40);
            if ( v52 >= v4->FirstThreshold )
            {
              (*(void (__fastcall **)(__int64, char *, __int64 *, _QWORD))(*(_QWORD *)v53 + 40i64))(
                v53,
                &v49,
                &v53,
                (unsigned int)v41);
              if ( v50 >= v4->SecondThreshold )
              {
LABEL_20:
                v20 = v4->Result;
                if ( v20 )
                  *v20 = 1;
                return;
              }
            }
            v37 = v4->SecondPoint.x;
            v38 = v4->FirstPoint.x;
          }
          while ( ++v40 < (signed int)(v32 + v4->SecondPoint.x - v38) );
        }
        v31 = v4->SecondPoint.y;
        v33 = v4->FirstPoint.y;
        ++v35;
      }
      while ( v35 < (signed int)(v59 + v4->SecondPoint.y - v33) );
    }
  }
  else
  {
    v9 = ((__int64 (*)(void))v5[61].__vecDelDtor)();
    v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 120i64))(v9);
    v45 = v7;
    v44 = 0i64;
    v46 = 0;
    v47 = 0i64;
    v43 = v10;
    v48 = 0i64;
    (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v10 + 8i64))(v10, &v43);
    v11 = v7->pPlanes;
    v12 = v11->Height;
    v13 = v4->SecondArea.x2 - v4->SecondArea.x1;
    v14 = v11->Width;
    v15 = v4->SecondArea.y2 - v4->SecondArea.y1;
    if ( v14 < v13 )
      v13 = v14;
    if ( v12 < v15 )
      v15 = v12;
    v16 = v4->SecondArea.y1 - v4->FirstPoint.y;
    v17 = v16;
    if ( v16 < 0 )
      v17 = 0;
    if ( v17 < v15 + v16 )
    {
      do
      {
        if ( v17 < 0 || v17 >= (signed int)v7->pPlanes->Height )
          break;
        (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v43 + 16i64))(v43, &v43, (unsigned int)v17);
        v18 = v4->SecondArea.x1 - v4->FirstPoint.x;
        v19 = v18;
        if ( v18 < 0 )
          v19 = 0;
        if ( v19 < v13 + v18 )
        {
          do
          {
            if ( v19 < 0 || v19 >= (signed int)v7->pPlanes->Width )
              break;
            (*(void (__fastcall **)(__int64, unsigned int *, __int64 *, _QWORD))(*(_QWORD *)v43 + 40i64))(
              v43,
              &v59,
              &v43,
              (unsigned int)v19);
            if ( HIBYTE(v59) >= v4->FirstThreshold )
              goto LABEL_20;
            ++v19;
          }
          while ( v19 < v13 + v4->SecondArea.x1 - v4->FirstPoint.x );
        }
        ++v17;
      }
      while ( v17 < v15 + v4->SecondArea.y1 - v4->FirstPoint.y );
    }
  }
  v42 = v4->Result;
  if ( v42 )
    *v42 = 0;
}

// File Line: 559
// RVA: 0x9763B0
void __fastcall Scaleform::Render::DICommand_Merge::ExecuteSW(Scaleform::Render::DICommand_Merge *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImagePlane *v4; // rax
  Scaleform::Render::DICommand_Merge *v5; // r13
  signed int v6; // ebx
  signed int v7; // edi
  Scaleform::Render::ImagePlane *v8; // r10
  int v9; // eax
  int v10; // ecx
  signed int v11; // er11
  signed int v12; // er10
  int v13; // er12
  int v14; // er14
  int v15; // edx
  int v16; // er8
  int v17; // esi
  __int64 v18; // rdx
  __int64 v19; // r8
  int v20; // eax
  int v21; // er15
  int v22; // ebx
  __int64 v23; // rax
  __int64 v24; // rax
  __int64 v25; // rax
  __int64 v26; // rdi
  __int64 v27; // rax
  int v28; // er14
  int v29; // edi
  int v30; // ebx
  unsigned int v31; // er8
  unsigned int v32; // er11
  unsigned int v33; // er15
  signed __int16 v34; // r14
  signed __int16 v35; // r12
  bool v36; // r13
  char v37; // al
  unsigned int v38; // ST20_4
  unsigned int v39; // [rsp+24h] [rbp-75h]
  int v40; // [rsp+28h] [rbp-71h]
  int v41; // [rsp+2Ch] [rbp-6Dh]
  int v42; // [rsp+30h] [rbp-69h]
  int v43; // [rsp+34h] [rbp-65h]
  int v44; // [rsp+38h] [rbp-61h]
  int v45; // [rsp+3Ch] [rbp-5Dh]
  __int64 v46; // [rsp+48h] [rbp-51h]
  __int64 v47; // [rsp+50h] [rbp-49h]
  Scaleform::Render::ImageData *v48; // [rsp+58h] [rbp-41h]
  int v49; // [rsp+60h] [rbp-39h]
  __int64 v50; // [rsp+68h] [rbp-31h]
  __int64 v51; // [rsp+70h] [rbp-29h]
  __int64 v52; // [rsp+78h] [rbp-21h]
  __int64 v53; // [rsp+80h] [rbp-19h]
  __int64 v54; // [rsp+88h] [rbp-11h]
  int v55; // [rsp+90h] [rbp-9h]
  __int64 v56; // [rsp+98h] [rbp-1h]
  __int64 v57; // [rsp+A0h] [rbp+7h]
  Scaleform::Render::DICommand_Merge *v58; // [rsp+100h] [rbp+67h]
  Scaleform::Render::DICommandContext *v59; // [rsp+108h] [rbp+6Fh]
  Scaleform::Render::ImageData *v60; // [rsp+110h] [rbp+77h]
  Scaleform::Render::ImageData **v61; // [rsp+118h] [rbp+7Fh]

  v61 = psrc;
  v60 = dest;
  v59 = context;
  v58 = this;
  v4 = dest->pPlanes;
  v5 = this;
  v6 = v4->Width;
  v7 = v4->Height;
  v8 = (*psrc)->pPlanes;
  v9 = this->SourceRect.x1;
  v10 = this->SourceRect.y1;
  v11 = v8->Width;
  v12 = v8->Height;
  v13 = v5->DestPoint.x - v9;
  v14 = v5->DestPoint.y - v10;
  v44 = v5->DestPoint.x - v9;
  if ( v12 >= v10 )
  {
    v15 = v5->SourceRect.y2;
    if ( v15 >= 0 )
    {
      v16 = v5->SourceRect.x2;
      if ( v16 >= 0 && v11 >= v9 )
      {
        if ( v9 < 0 )
          v9 = 0;
        if ( v11 > v16 )
          v11 = v5->SourceRect.x2;
        if ( v10 < 0 )
          v10 = 0;
        v17 = v11 + v13;
        if ( v12 > v15 )
          v12 = v5->SourceRect.y2;
        v18 = (unsigned int)(v9 + v13);
        v19 = (unsigned int)(v10 + v14);
        v20 = v12 + v14;
        if ( v12 + v14 >= 0 && v7 >= (signed int)v19 && v6 >= (signed int)v18 && v17 >= 0 )
        {
          v21 = 0;
          if ( (signed int)v18 > 0 )
            v21 = v18;
          if ( v17 > v6 )
            v17 = v6;
          v22 = 0;
          if ( (signed int)v19 > 0 )
            v22 = v10 + v14;
          v43 = v21;
          if ( v20 > v7 )
            v20 = v7;
          v42 = v17;
          v41 = v20;
          v40 = v22;
          v23 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, __int64, __int64, _QWORD))v59->pHAL->vfptr[61].__vecDelDtor)(
                  v59->pHAL,
                  v18,
                  v19,
                  0i64);
          v24 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v23 + 120i64))(v23);
          v47 = 0i64;
          v49 = 0;
          v50 = 0i64;
          v48 = v60;
          v51 = 0i64;
          v46 = v24;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v24 + 8i64))(v24, &v46);
          v25 = ((__int64 (*)(void))v59->pHAL->vfptr[61].__vecDelDtor)();
          v26 = (__int64)*v61;
          v27 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v25 + 120i64))(v25);
          v54 = v26;
          v53 = 0i64;
          v55 = 0;
          v56 = 0i64;
          v57 = 0i64;
          v52 = v27;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v27 + 8i64))(v27, &v52);
          if ( v22 < v41 )
          {
            v28 = -v14;
            v45 = v28;
            do
            {
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v46 + 16i64))(
                v46,
                &v46,
                (unsigned int)v22);
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v52 + 16i64))(
                v52,
                &v52,
                (unsigned int)(v28 + v22));
              v29 = v21;
              v39 = v21;
              if ( v21 < v17 )
              {
                v30 = -v13;
                do
                {
                  (*(void (__fastcall **)(__int64, Scaleform::Render::ImageData ***, __int64 *, _QWORD))(*(_QWORD *)v46 + 40i64))(
                    v46,
                    &v61,
                    &v46,
                    (unsigned int)v29);
                  (*(void (__fastcall **)(__int64, Scaleform::Render::ImageData **, __int64 *, _QWORD))(*(_QWORD *)v52 + 40i64))(
                    v52,
                    &v60,
                    &v52,
                    (unsigned int)(v30 + v29));
                  v31 = v5->RedMultiplier;
                  v32 = v5->GreenMultiplier;
                  v33 = v5->BlueMultiplier;
                  v34 = BYTE3(v60);
                  v35 = BYTE3(v61);
                  if ( !v5->pSource.pObject->Transparent )
                    v34 = 255;
                  v36 = v5->pImage.pObject->Transparent;
                  if ( !v36 )
                    v35 = 255;
                  v37 = (unsigned __int16)(v58->AlphaMultiplier * v34 + v35 * (256 - v58->AlphaMultiplier)) >> 8;
                  if ( !v36 )
                    v37 = -1;
                  HIBYTE(v38) = v37;
                  BYTE1(v38) = (unsigned __int16)(v32 * BYTE1(v60) + BYTE1(v61) * (256 - v32)) >> 8;
                  LOBYTE(v38) = (unsigned __int16)(v33 * (unsigned __int8)v60 + (unsigned __int8)v61 * (256 - v33)) >> 8;
                  BYTE2(v38) = (unsigned __int16)(v31 * BYTE2(v60) + BYTE2(v61) * (256 - v31)) >> 8;
                  (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v46 + 24i64))(
                    v46,
                    &v46,
                    v39,
                    v38);
                  v17 = v42;
                  v5 = v58;
                  v29 = v39 + 1;
                  v39 = v29;
                }
                while ( v29 < v42 );
                v22 = v40;
                v28 = v45;
                v21 = v43;
                v13 = v44;
              }
              v40 = ++v22;
            }
            while ( v22 < v41 );
          }
        }
      }
    }
  }
}

// File Line: 612
// RVA: 0x976720
void __fastcall Scaleform::Render::DICommand_Noise::ExecuteSW(Scaleform::Render::DICommand_Noise *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::ImageData *v4; // r14
  Scaleform::Render::DICommandContext *v5; // rbx
  Scaleform::Render::DICommand_Noise *v6; // rdi
  unsigned int v7; // eax
  unsigned int v8; // edx
  __int64 v9; // rax
  __int64 v10; // rax
  Scaleform::Render::ImagePlane *v11; // rax
  unsigned int i; // esi
  unsigned int v13; // ebx
  __int64 v14; // rax
  __int64 v15; // r8
  unsigned __int64 v16; // rcx
  unsigned __int64 v17; // rax
  int v18; // edx
  float v19; // xmm1_4
  __int64 v20; // rax
  __int64 v21; // r8
  unsigned __int64 v22; // rcx
  unsigned __int64 v23; // rax
  int v24; // edx
  float v25; // xmm0_4
  float v26; // xmm1_4
  signed int v27; // ecx
  unsigned int v28; // edx
  __int64 v29; // rax
  __int64 v30; // r9
  unsigned __int64 v31; // rcx
  unsigned __int64 v32; // rax
  int v33; // er8
  __int64 v34; // rax
  __int64 v35; // r9
  unsigned __int64 v36; // rcx
  unsigned __int64 v37; // rax
  int v38; // er8
  __int64 v39; // rax
  __int64 v40; // r9
  unsigned __int64 v41; // rcx
  unsigned __int64 v42; // rax
  int v43; // er8
  __int64 v44; // rax
  __int64 v45; // r8
  unsigned __int64 v46; // rcx
  unsigned __int64 v47; // rax
  int v48; // edx
  Scaleform::Alg::Random::Generator v49; // [rsp+20h] [rbp-59h]
  __int64 v50; // [rsp+48h] [rbp-31h]
  __int64 v51; // [rsp+50h] [rbp-29h]
  Scaleform::Render::ImageData *v52; // [rsp+58h] [rbp-21h]
  int v53; // [rsp+60h] [rbp-19h]
  __int64 v54; // [rsp+68h] [rbp-11h]
  __int64 v55; // [rsp+70h] [rbp-9h]
  unsigned int v56; // [rsp+E0h] [rbp+67h]

  v4 = dest;
  v5 = context;
  v6 = this;
  v49.C = 362436;
  v49.I = 7;
  v7 = timeGetTime();
  v8 = v7;
  if ( TimerOverrideInstance )
    v8 = TimerOverrideInstance->vfptr->GetTicksMs(TimerOverrideInstance, v7);
  Scaleform::Alg::Random::Generator::SeedRandom(&v49, v8);
  Scaleform::Alg::Random::Generator::SeedRandom(&v49, v6->RandomSeed);
  v9 = ((__int64 (*)(void))v5->pHAL->vfptr[61].__vecDelDtor)();
  v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 120i64))(v9);
  v52 = v4;
  v51 = 0i64;
  v53 = 0;
  v54 = 0i64;
  v50 = v10;
  v55 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v10 + 8i64))(v10, &v50);
  v11 = v4->pPlanes;
  for ( i = 0; i < v11->Width; ++i )
  {
    v13 = 0;
    if ( v11->Height > 0 )
    {
      do
      {
        (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v50 + 16i64))(v50, &v50, v13);
        v56 = 0;
        if ( v6->GrayScale )
        {
          v14 = (LOBYTE(v49.I) + 1) & 7;
          v49.I = v14;
          v15 = (unsigned int)v14;
          v16 = v49.C + 716514398i64 * v49.Q[v14];
          v17 = v16 >> 32;
          v49.C = v17;
          v18 = v16 + v17;
          if ( (signed int)v16 + (signed int)v17 < (unsigned int)v17 )
          {
            ++v18;
            v49.C = v17 + 1;
          }
          v49.Q[v15] = -2 - v18;
          v19 = (float)((unsigned int)(-2 - v18) >> 8) * 0.000000059604652;
          if ( v6->ChannelMask & 8 )
          {
            v20 = (LOBYTE(v49.I) + 1) & 7;
            v49.I = v20;
            v21 = (unsigned int)v20;
            v22 = v49.C + 716514398i64 * v49.Q[v20];
            v23 = v22 >> 32;
            v49.C = v23;
            v24 = v22 + v23;
            if ( (signed int)v22 + (signed int)v23 < (unsigned int)v23 )
            {
              ++v24;
              v49.C = v23 + 1;
            }
            v49.Q[v21] = -2 - v24;
            v25 = (float)((unsigned int)(-2 - v24) >> 8) * 0.000000059604652;
          }
          else
          {
            v25 = *(float *)&FLOAT_1_0;
          }
          v26 = v19 * 255.0;
          v27 = (signed int)(float)(v25 * 255.0);
          BYTE2(v56) = (signed int)v26;
          BYTE1(v56) = (signed int)v26;
          LOBYTE(v56) = (signed int)v26;
        }
        else
        {
          v28 = v6->ChannelMask;
          if ( v28 & 1 )
          {
            v29 = (LOBYTE(v49.I) + 1) & 7;
            v49.I = v29;
            v30 = (unsigned int)v29;
            v31 = v49.C + 716514398i64 * v49.Q[v29];
            v32 = v31 >> 32;
            v49.C = v32;
            v33 = v31 + v32;
            if ( (signed int)v31 + (signed int)v32 < (unsigned int)v32 )
            {
              ++v33;
              v49.C = v32 + 1;
            }
            v49.Q[v30] = -2 - v33;
            BYTE2(v56) = (signed int)(float)((float)((float)((unsigned int)(-2 - v33) >> 8) * 0.000000059604652) * 255.0);
          }
          if ( v28 & 2 )
          {
            v34 = (LOBYTE(v49.I) + 1) & 7;
            v49.I = v34;
            v35 = (unsigned int)v34;
            v36 = v49.C + 716514398i64 * v49.Q[v34];
            v37 = v36 >> 32;
            v49.C = v37;
            v38 = v36 + v37;
            if ( (signed int)v36 + (signed int)v37 < (unsigned int)v37 )
            {
              ++v38;
              v49.C = v37 + 1;
            }
            v49.Q[v35] = -2 - v38;
            BYTE1(v56) = (signed int)(float)((float)((float)((unsigned int)(-2 - v38) >> 8) * 0.000000059604652) * 255.0);
          }
          if ( v28 & 4 )
          {
            v39 = (LOBYTE(v49.I) + 1) & 7;
            v49.I = v39;
            v40 = (unsigned int)v39;
            v41 = v49.C + 716514398i64 * v49.Q[v39];
            v42 = v41 >> 32;
            v49.C = v42;
            v43 = v41 + v42;
            if ( (signed int)v41 + (signed int)v42 < (unsigned int)v42 )
            {
              ++v43;
              v49.C = v42 + 1;
            }
            v49.Q[v40] = -2 - v43;
            LOBYTE(v56) = (signed int)(float)((float)((float)((unsigned int)(-2 - v43) >> 8) * 0.000000059604652) * 255.0);
          }
          if ( v28 & 8 )
          {
            v44 = (LOBYTE(v49.I) + 1) & 7;
            v49.I = v44;
            v45 = (unsigned int)v44;
            v46 = v49.C + 716514398i64 * v49.Q[v44];
            v47 = v46 >> 32;
            v49.C = v47;
            v48 = v46 + v47;
            if ( (signed int)v46 + (signed int)v47 < (unsigned int)v47 )
            {
              ++v48;
              v49.C = v47 + 1;
            }
            v49.Q[v45] = -2 - v48;
            v27 = (signed int)(float)((float)((float)((unsigned int)(-2 - v48) >> 8) * 0.000000059604652) * 255.0);
          }
          else
          {
            LOBYTE(v27) = -1;
          }
        }
        if ( !v6->pImage.pObject->Transparent )
          LOBYTE(v27) = -1;
        HIBYTE(v56) = v27;
        (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v50 + 24i64))(v50, &v50, i, v56);
        ++v13;
      }
      while ( v13 < v4->pPlanes->Height );
    }
    v11 = v4->pPlanes;
  }
}

// File Line: 653
// RVA: 0x976B30
void __fastcall Scaleform::Render::DICommand_PaletteMap::ExecuteSW(Scaleform::Render::DICommand_PaletteMap *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImagePlane *v4; // rax
  Scaleform::Render::DICommand_PaletteMap *v5; // rdi
  signed int v6; // ebx
  signed int v7; // esi
  Scaleform::Render::ImagePlane *v8; // rax
  signed int v9; // er11
  signed int v10; // er10
  int v11; // eax
  int v12; // ecx
  Scaleform::Render::ImageData **v13; // r14
  int v14; // er12
  Scaleform::Render::ImageData *v15; // r15
  int v16; // er9
  Scaleform::Render::DICommandContext *v17; // r13
  int v18; // edx
  int v19; // er8
  int v20; // er8
  int v21; // edx
  int v22; // eax
  int v23; // er9
  int v24; // ecx
  int v25; // er12
  Scaleform::RefCountImplCoreVtbl *v26; // rax
  __int64 v27; // rax
  __int64 v28; // rax
  __int64 v29; // rax
  __int64 v30; // rbx
  __int64 v31; // rax
  int v32; // er13
  int v33; // ebx
  int v34; // er14
  unsigned __int8 v35; // r9
  unsigned int v36; // esi
  unsigned int v37; // ebx
  __int64 v38; // r10
  char *v39; // r11
  int *v40; // r8
  signed int v41; // eax
  signed __int64 v42; // r9
  int v43; // [rsp+20h] [rbp-69h]
  int v44; // [rsp+30h] [rbp-59h]
  int v45; // [rsp+34h] [rbp-55h]
  int v46; // [rsp+38h] [rbp-51h]
  int v47; // [rsp+40h] [rbp-49h]
  int v48; // [rsp+44h] [rbp-45h]
  int v49; // [rsp+48h] [rbp-41h]
  int v50; // [rsp+4Ch] [rbp-3Dh]
  __int64 v51; // [rsp+50h] [rbp-39h]
  __int64 v52; // [rsp+58h] [rbp-31h]
  __int64 v53; // [rsp+60h] [rbp-29h]
  int v54; // [rsp+68h] [rbp-21h]
  __int64 v55; // [rsp+70h] [rbp-19h]
  __int64 v56; // [rsp+78h] [rbp-11h]
  __int64 v57; // [rsp+80h] [rbp-9h]
  __int64 v58; // [rsp+88h] [rbp-1h]
  Scaleform::Render::ImageData *v59; // [rsp+90h] [rbp+7h]
  int v60; // [rsp+98h] [rbp+Fh]
  __int64 v61; // [rsp+A0h] [rbp+17h]
  __int64 v62; // [rsp+A8h] [rbp+1Fh]
  int v63; // [rsp+F0h] [rbp+67h]
  char v64; // [rsp+100h] [rbp+77h]
  char v65; // [rsp+101h] [rbp+78h]
  char v66; // [rsp+102h] [rbp+79h]
  unsigned __int8 v67; // [rsp+103h] [rbp+7Ah]
  int v68; // [rsp+108h] [rbp+7Fh]

  v4 = dest->pPlanes;
  v5 = this;
  v6 = v4->Width;
  v7 = v4->Height;
  v8 = (*psrc)->pPlanes;
  v9 = v8->Height;
  v10 = v8->Width;
  v11 = this->SourceRect.x1;
  v12 = this->SourceRect.y1;
  v13 = psrc;
  v14 = v5->DestPoint.x - v11;
  v15 = dest;
  v16 = v5->DestPoint.y - v12;
  v17 = context;
  v45 = v5->DestPoint.x - v11;
  v68 = v5->DestPoint.y - v12;
  if ( v9 >= v12 )
  {
    v18 = v5->SourceRect.y2;
    if ( v18 >= 0 )
    {
      v19 = v5->SourceRect.x2;
      if ( v19 >= 0 && v10 >= v11 )
      {
        if ( v11 < 0 )
          v11 = 0;
        if ( v10 > v19 )
          v10 = v5->SourceRect.x2;
        if ( v12 < 0 )
          v12 = 0;
        v20 = v10 + v14;
        if ( v9 > v18 )
          v9 = v5->SourceRect.y2;
        v21 = v11 + v14;
        v22 = v12 + v16;
        v23 = v9 + v16;
        if ( v23 >= 0 && v7 >= v22 && v6 >= v21 && v20 >= 0 )
        {
          v24 = 0;
          v25 = 0;
          if ( v21 > 0 )
            v24 = v21;
          if ( v20 > v6 )
            v20 = v6;
          v46 = v24;
          if ( v22 > 0 )
            v25 = v22;
          v26 = v17->pHAL->vfptr;
          if ( v23 > v7 )
            v23 = v7;
          v63 = v20;
          v44 = v25;
          v43 = v23;
          v27 = ((__int64 (*)(void))v26[61].__vecDelDtor)();
          v28 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v27 + 120i64))(v27);
          v59 = v15;
          v58 = 0i64;
          v60 = 0;
          v61 = 0i64;
          v62 = 0i64;
          v57 = v28;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v28 + 8i64))(v28, &v57);
          v29 = ((__int64 (*)(void))v17->pHAL->vfptr[61].__vecDelDtor)();
          v30 = (__int64)*v13;
          v31 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v29 + 120i64))(v29);
          v52 = 0i64;
          v53 = v30;
          v54 = 0;
          v55 = 0i64;
          v56 = 0i64;
          v51 = v31;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v31 + 8i64))(v31, &v51);
          if ( v25 < v43 )
          {
            v32 = v63;
            v33 = -v68;
            v68 = -v68;
            do
            {
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v57 + 16i64))(
                v57,
                &v57,
                (unsigned int)v25);
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v51 + 16i64))(
                v51,
                &v51,
                (unsigned int)(v33 + v25));
              v34 = v46;
              if ( v46 < v32 )
              {
                do
                {
                  (*(void (__fastcall **)(__int64, int *, __int64 *, _QWORD))(*(_QWORD *)v51 + 40i64))(
                    v51,
                    &v63,
                    &v51,
                    (unsigned int)(v34 - v45));
                  v35 = HIBYTE(v63);
                  if ( !v5->pSource.pObject->Transparent )
                    v35 = -1;
                  v36 = v5->ChannelMask;
                  HIBYTE(v63) = v35;
                  v66 = v63;
                  v67 = v35;
                  v49 = (unsigned __int8)v63;
                  v50 = v35 << 24;
                  v37 = 0;
                  v64 = BYTE2(v63);
                  v65 = BYTE1(v63);
                  v47 = BYTE2(v63) << 16;
                  v38 = 0i64;
                  v39 = &v64;
                  v40 = &v47;
                  v48 = BYTE1(v63) << 8;
                  v41 = 1;
                  v42 = 4i64;
                  do
                  {
                    if ( v41 & v36 )
                      *v40 = v5->Channels[v38 + (unsigned __int8)*v39];
                    v41 = __ROL4__(v41, 1);
                    v37 += *v40;
                    ++v40;
                    ++v39;
                    v38 += 256i64;
                    --v42;
                  }
                  while ( v42 );
                  if ( !v5->pImage.pObject->Transparent )
                    v37 |= 0xFF000000;
                  (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v57 + 24i64))(
                    v57,
                    &v57,
                    (unsigned int)v34++,
                    v37);
                }
                while ( v34 < v32 );
                v25 = v44;
                v33 = v68;
              }
              v44 = ++v25;
            }
            while ( v25 < v43 );
          }
        }
      }
    }
  }
}

// File Line: 729
// RVA: 0x9966A0
float __fastcall Scaleform::Render::PerlinGenerator::InterpolatedNoise(Scaleform::Render::PerlinGenerator *this, float x, float y)
{
  Scaleform::Render::PerlinGenerator *v3; // r14
  float v4; // xmm10_4
  float v5; // xmm8_4
  float v6; // xmm0_4
  float v7; // xmm7_4
  float v8; // xmm6_4

  v3 = this;
  v4 = (float)(1.0 - cosf((float)(x - (float)(signed int)x) * 3.1415927)) * 0.5;
  v5 = (float)(1.0 - cosf((float)(y - (float)(signed int)y) * 3.1415927)) * 0.5;
  v6 = Scaleform::Render::PerlinGenerator::SmoothNoise(v3, (signed int)x, (signed int)y);
  v7 = (float)((float)(v6 * (float)(1.0 - v4))
             + (float)(Scaleform::Render::PerlinGenerator::SmoothNoise(v3, (signed int)x + 1, (signed int)y) * v4))
     * (float)(1.0 - v5);
  v8 = Scaleform::Render::PerlinGenerator::SmoothNoise(v3, (signed int)x, (signed int)y + 1) * (float)(1.0 - v4);
  return v7
       + (float)((float)(v8
                       + (float)(Scaleform::Render::PerlinGenerator::SmoothNoise(
                                   v3,
                                   (signed int)x + 1,
                                   (signed int)y + 1)
                               * v4))
               * v5);
}

// File Line: 764
// RVA: 0x9B6980
float __fastcall Scaleform::Render::PerlinGenerator::SmoothNoise(Scaleform::Render::PerlinGenerator *this, int x, int y)
{
  unsigned int v3; // ebp
  unsigned int v4; // esi
  unsigned int v5; // er14
  unsigned int v6; // er15
  unsigned int v7; // er9
  unsigned int v8; // ecx
  int v9; // er11
  int v10; // er10
  int v11; // ebx
  int v12; // edi
  int v13; // er8
  int v14; // edx
  int v15; // er14

  v3 = this->PrimeSet.primes[1];
  v4 = x + this->PrimeSet.primes[0] * (y - 1);
  v5 = x + this->PrimeSet.primes[0] * (y + 1);
  v6 = y * this->PrimeSet.primes[0] + x;
  v7 = this->PrimeSet.primes[2];
  v8 = this->PrimeSet.primes[3];
  v9 = ((v4 - 1) << 13) ^ (v4 - 1);
  v10 = ((v4 + 1) << 13) ^ (v4 + 1);
  v11 = ((v5 - 1) << 13) ^ (v5 - 1);
  v12 = ((v5 + 1) << 13) ^ (v5 + 1);
  v13 = ((v6 - 1) << 13) ^ (v6 - 1);
  v14 = ((v6 + 1) << 13) ^ (v6 + 1);
  v15 = (v5 << 13) ^ v5;
  return (float)((float)((float)((float)((float)((float)(1.0
                                                       - (float)((float)((v8 + v10 * (v7 + v10 * v10 * v3)) & 0x7FFFFFFF)
                                                               * 9.3132257e-10))
                                               + (float)(1.0
                                                       - (float)((float)((v8 + v9 * (v7 + v9 * v9 * v3)) & 0x7FFFFFFF)
                                                               * 9.3132257e-10)))
                                       + (float)(1.0
                                               - (float)((float)((v8 + v11 * (v7 + v11 * v11 * v3)) & 0x7FFFFFFF)
                                                       * 9.3132257e-10)))
                               + (float)(1.0
                                       - (float)((float)((v8 + v12 * (v7 + v12 * v12 * v3)) & 0x7FFFFFFF) * 9.3132257e-10)))
                       * 0.0625)
               + (float)((float)((float)((float)((float)(1.0
                                                       - (float)((float)((v8 + v14 * (v7 + v14 * v14 * v3)) & 0x7FFFFFFF)
                                                               * 9.3132257e-10))
                                               + (float)(1.0
                                                       - (float)((float)((v8 + v13 * (v7 + v13 * v13 * v3)) & 0x7FFFFFFF)
                                                               * 9.3132257e-10)))
                                       + (float)(1.0
                                               - (float)((float)((v8
                                                                + ((v4 << 13) ^ v4)
                                                                * (v7 + ((v4 << 13) ^ v4) * ((v4 << 13) ^ v4) * v3)) & 0x7FFFFFFF)
                                                       * 9.3132257e-10)))
                               + (float)(1.0
                                       - (float)((float)((v8 + v15 * (v7 + v15 * v15 * v3)) & 0x7FFFFFFF) * 9.3132257e-10)))
                       * 0.125))
       + (float)((float)(1.0
                       - (float)((float)((v8 + ((v6 << 13) ^ v6) * (v7 + ((v6 << 13) ^ v6) * ((v6 << 13) ^ v6) * v3)) & 0x7FFFFFFF)
                               * 9.3132257e-10))
               * 0.25);
}

// File Line: 797
// RVA: 0x976E30
void __fastcall Scaleform::Render::DICommand_PerlinNoise::ExecuteSW(Scaleform::Render::DICommand_PerlinNoise *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **__formal)
{
  unsigned int v4; // edi
  Scaleform::Render::ImageData *v5; // r12
  Scaleform::Render::DICommand_PerlinNoise *v6; // r13
  __int64 v7; // rax
  __int64 v8; // rax
  unsigned int v9; // er15
  unsigned int v10; // ebx
  unsigned int v11; // esi
  signed int v12; // er14
  signed int v13; // eax
  BOOL v14; // edx
  bool v15; // zf
  unsigned int v16; // edx
  unsigned int v17; // er12
  float v18; // xmm9_4
  float v19; // xmm6_4
  float v20; // xmm10_4
  float v21; // xmm7_4
  float v22; // xmm8_4
  unsigned int v23; // edi
  __int64 v24; // rcx
  signed int v25; // eax
  float *v26; // rbx
  float v27; // xmm12_4
  signed int v28; // eax
  unsigned int v29; // er15
  float v30; // xmm13_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm6_4
  signed int v35; // eax
  float v36; // xmm6_4
  unsigned int v37; // [rsp+20h] [rbp-E0h]
  signed int v38; // [rsp+28h] [rbp-D8h]
  unsigned int v39; // [rsp+30h] [rbp-D0h]
  unsigned int v40; // [rsp+34h] [rbp-CCh]
  unsigned int v41; // [rsp+38h] [rbp-C8h]
  Scaleform::Render::PerlinGenerator v42; // [rsp+40h] [rbp-C0h]
  __int64 v43; // [rsp+50h] [rbp-B0h]
  __int64 v44; // [rsp+58h] [rbp-A8h]
  Scaleform::Render::ImageData *v45; // [rsp+60h] [rbp-A0h]
  int v46; // [rsp+68h] [rbp-98h]
  __int64 v47; // [rsp+70h] [rbp-90h]
  __int64 v48; // [rsp+78h] [rbp-88h]
  bool v49; // [rsp+160h] [rbp+60h]
  unsigned int v50; // [rsp+168h] [rbp+68h]
  Scaleform::Render::ImageData *v51; // [rsp+170h] [rbp+70h]

  v51 = dest;
  v4 = this->ChannelMask;
  v5 = dest;
  v37 = this->ChannelMask;
  v6 = this;
  if ( this->GrayScale )
  {
    v4 = v4 & 0xFFFFFFF9 | 1;
    v37 = v4;
  }
  v7 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::DICommandContext *, Scaleform::Render::ImageData *, Scaleform::Render::ImageData **))context->pHAL->vfptr[61].__vecDelDtor)(
         context->pHAL,
         context,
         dest,
         __formal);
  v8 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 120i64))(v7);
  v45 = v5;
  v44 = 0i64;
  v46 = 0;
  v47 = 0i64;
  v43 = v8;
  v48 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v8 + 8i64))(v8, &v43);
  v9 = 0;
  v40 = 0;
  while ( v9 < v5->pPlanes->Height )
  {
    (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v43 + 16i64))(v43, &v43, v9);
    v10 = 0;
    v39 = 0;
    if ( !v5->pPlanes->Width )
      goto LABEL_31;
    do
    {
      v11 = 0;
      v50 = -16777216;
      v12 = 1;
      v49 = v6->pImage.pObject->Transparent;
      LOBYTE(v13) = -1;
      v14 = v6->pImage.pObject->Transparent != 0;
      v15 = v14 == -3;
      v16 = v14 + 3;
      v41 = v16;
      if ( v15 )
        goto LABEL_28;
      LOBYTE(v38) = -1;
      do
      {
        if ( v12 & v4 )
        {
          v17 = v6->NumOctaves;
          v18 = *(float *)&FLOAT_1_0;
          v19 = 0.0;
          v20 = 0.0;
          v21 = 2.0 / v6->FrequencyX;
          v22 = 2.0 / v6->FrequencyY;
          v23 = 0;
          v24 = -3 * ((_BYTE)v11 + (unsigned __int8)v6->RandomSeed) & 7;
          v42.PrimeSet.primes[0] = Scaleform::Render::PerlinGenerator::NoisePrimeFactors[-3
                                                                                       * ((_BYTE)v11
                                                                                        + (unsigned __int8)v6->RandomSeed) & 7].primes[0];
          v42.PrimeSet.primes[1] = Scaleform::Render::PerlinGenerator::NoisePrimeFactors[v24].primes[1];
          v42.PrimeSet.primes[2] = Scaleform::Render::PerlinGenerator::NoisePrimeFactors[v24].primes[2];
          v42.PrimeSet.primes[3] = Scaleform::Render::PerlinGenerator::NoisePrimeFactors[v24].primes[3];
          if ( v17 )
          {
            v25 = v10;
            v26 = v6->Offsets;
            v27 = (float)v25;
            v28 = v9;
            v29 = v6->OffsetCount;
            v30 = (float)v28;
            do
            {
              v31 = v27 * v21;
              v32 = v30 * v22;
              if ( v23 < v29 )
              {
                v31 = v31 + *v26;
                v32 = v32 + v26[1];
              }
              ++v23;
              v26 += 2;
              v20 = v20 + v18;
              v21 = v21 * 2.0;
              v22 = v22 * 2.0;
              v33 = (float)((float)(Scaleform::Render::PerlinGenerator::InterpolatedNoise(&v42, v31, v32) + 1.0) * 0.5)
                  * v18;
              v18 = v18 * 0.5;
              v19 = v19 + v33;
            }
            while ( v23 < v17 );
            v16 = v41;
            v10 = v39;
            v9 = v40;
          }
          v34 = v19 / v20;
          if ( v6->GrayScale && v11 != 3 )
          {
            v4 = v37;
            v35 = (signed int)(float)(v34 * 255.0);
            BYTE2(v50) = v35;
            LOBYTE(v50) = v35;
LABEL_24:
            BYTE1(v50) = v35;
            goto LABEL_25;
          }
          v4 = v37;
          v36 = v34 * 255.0;
          if ( v11 == 1 )
          {
            v35 = (signed int)v36;
            goto LABEL_24;
          }
          if ( v11 == 2 )
          {
            LOBYTE(v50) = (signed int)v36;
          }
          else
          {
            v13 = (signed int)v36;
            if ( v11 == 3 )
            {
              v38 = (signed int)v36;
              goto LABEL_26;
            }
            BYTE2(v50) = (signed int)v36;
          }
        }
LABEL_25:
        LOBYTE(v13) = v38;
LABEL_26:
        v12 = __ROL4__(v12, 1);
        ++v11;
      }
      while ( v11 < v16 );
      v5 = v51;
LABEL_28:
      if ( !v49 )
        LOBYTE(v13) = -1;
      HIBYTE(v50) = v13;
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v43 + 24i64))(v43, &v43, v10++, v50);
      v39 = v10;
    }
    while ( v10 < v5->pPlanes->Width );
LABEL_31:
    v40 = ++v9;
  }
}

// File Line: 932
// RVA: 0x977210
void __fastcall Scaleform::Render::DICommand_PixelDissolve::ExecuteSW(Scaleform::Render::DICommand_PixelDissolve *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::DICommand_PixelDissolve *v4; // r14
  Scaleform::Render::ImageData **v5; // rsi
  Scaleform::Render::ImageData *v6; // rdi
  Scaleform::Render::DICommandContext *v7; // rbx
  __int64 v8; // rax
  __int64 v9; // rax
  unsigned int v10; // er12
  Scaleform::Render::ImagePlane *v11; // rax
  int v12; // ecx
  int v13; // esi
  int v14; // er15
  int v15; // edx
  int v16; // er8
  int v17; // eax
  unsigned int v18; // er15
  int v19; // esi
  int v20; // ecx
  unsigned int v21; // esi
  int v22; // ebx
  const unsigned int *v23; // r13
  _DWORD *v24; // rax
  __int64 v25; // rax
  __int64 v26; // rbx
  __int64 v27; // rax
  Scaleform::Render::ImagePlane *v28; // rax
  int v29; // er10
  int v30; // er15
  int v31; // er8
  Scaleform::Render::ImagePlane *v32; // rcx
  signed int v33; // ebx
  signed int v34; // er11
  int v35; // er9
  int v36; // eax
  int v37; // edx
  int v38; // ecx
  int v39; // eax
  int v40; // edx
  int v41; // ecx
  int v42; // er8
  unsigned int v43; // er15
  int v44; // esi
  const unsigned int *v45; // r13
  unsigned int v46; // edi
  unsigned int v47; // ebx
  _DWORD *v48; // rax
  __int64 v49; // [rsp+20h] [rbp-60h]
  __int64 v50; // [rsp+28h] [rbp-58h]
  Scaleform::Render::ImageData *v51; // [rsp+30h] [rbp-50h]
  int v52; // [rsp+38h] [rbp-48h]
  __int64 v53; // [rsp+40h] [rbp-40h]
  __int64 v54; // [rsp+48h] [rbp-38h]
  __int64 v55; // [rsp+50h] [rbp-30h]
  __int64 v56; // [rsp+58h] [rbp-28h]
  __int64 v57; // [rsp+60h] [rbp-20h]
  int v58; // [rsp+68h] [rbp-18h]
  __int64 v59; // [rsp+70h] [rbp-10h]
  __int64 v60; // [rsp+78h] [rbp-8h]
  unsigned int v61; // [rsp+C0h] [rbp+40h]
  int v62; // [rsp+C8h] [rbp+48h]

  v4 = this;
  v5 = psrc;
  v6 = dest;
  v7 = context;
  v8 = ((__int64 (*)(void))context->pHAL->vfptr[61].__vecDelDtor)();
  v9 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 120i64))(v8);
  v10 = 0;
  v51 = v6;
  v50 = 0i64;
  v52 = 0;
  v53 = 0i64;
  v49 = v9;
  v54 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v9 + 8i64))(v9, &v49);
  if ( v4->pImage.pObject == v4->pSource.pObject )
  {
    v11 = v6->pPlanes;
    v12 = v4->SourceRect.y1;
    v13 = v11->Height;
    v14 = v11->Width;
    if ( v13 >= v12 )
    {
      v15 = v4->SourceRect.y2;
      if ( v15 >= 0 )
      {
        v16 = v4->SourceRect.x2;
        if ( v16 >= 0 )
        {
          v17 = v4->SourceRect.x1;
          if ( v14 >= v17 )
          {
            if ( v17 < 0 )
              v17 = 0;
            if ( v14 > v16 )
              v14 = v4->SourceRect.x2;
            if ( v12 < 0 )
              v12 = 0;
            if ( v13 > v15 )
              v13 = v4->SourceRect.y2;
            v18 = v14 - v17;
            v19 = v13 - v12;
            v20 = 0;
            v21 = v18 * v19;
            if ( v21 > 1 )
            {
              do
                ++v20;
              while ( v21 > 1 << v20 );
            }
            v22 = v4->RandomSeed;
            if ( v4->NumPixels > 0 )
            {
              v23 = &Scaleform::Render::LFSR::FeedbackPoly[v20];
              do
              {
                do
                  v22 = (v22 >> 1) ^ *v23 & -(v22 & 1);
                while ( v22 > v21 );
                (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v49 + 16i64))(
                  v49,
                  &v49,
                  (v22 - 1) / v18);
                (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v49 + 24i64))(
                  v49,
                  &v49,
                  (v22 - 1) % v18,
                  v4->Fill.Raw);
                ++v10;
              }
              while ( v10 < v4->NumPixels );
            }
            v24 = v4->Result;
            if ( v24 )
              *v24 = v22;
            return;
          }
        }
      }
    }
LABEL_48:
    v4->Result = 0i64;
    return;
  }
  v25 = ((__int64 (*)(void))v7->pHAL->vfptr[61].__vecDelDtor)();
  v26 = (__int64)*v5;
  v27 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v25 + 120i64))(v25);
  v56 = 0i64;
  v57 = v26;
  v58 = 0;
  v59 = 0i64;
  v60 = 0i64;
  v55 = v27;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v27 + 8i64))(v27, &v55);
  v28 = v6->pPlanes;
  v29 = v28->Width - v4->DestPoint.x - v4->DestPoint.x;
  if ( v29 <= 0 )
    goto LABEL_48;
  v30 = v28->Height - v4->DestPoint.y - v4->DestPoint.y;
  if ( v30 <= 0 )
    goto LABEL_48;
  v31 = v4->SourceRect.y2;
  v32 = (*v5)->pPlanes;
  v33 = v32->Width;
  v34 = v32->Height;
  if ( v31 < 0 )
    goto LABEL_48;
  v35 = v4->SourceRect.y1;
  if ( v34 < v35 )
    goto LABEL_48;
  v36 = v4->SourceRect.x1;
  if ( v33 < v36 )
    goto LABEL_48;
  v37 = v4->SourceRect.x2;
  if ( v37 < 0 )
    goto LABEL_48;
  v38 = 0;
  if ( v36 > 0 )
    v38 = v4->SourceRect.x1;
  v39 = 0;
  if ( v37 > v33 )
    v37 = v33;
  if ( v35 > 0 )
    v39 = v4->SourceRect.y1;
  if ( v31 > v34 )
    v31 = v34;
  v40 = v37 - v38;
  v41 = 0;
  v42 = v31 - v39;
  if ( v40 < v29 )
    v29 = v40;
  if ( v42 < v30 )
    v30 = v42;
  v62 = v29;
  v43 = v29 * v30;
  if ( v43 > 1 )
  {
    do
      ++v41;
    while ( v43 > 1 << v41 );
  }
  v44 = v4->RandomSeed;
  if ( v4->NumPixels > 0 )
  {
    v45 = &Scaleform::Render::LFSR::FeedbackPoly[v41];
    do
    {
      do
        v44 = (v44 >> 1) ^ *v45 & -(v44 & 1);
      while ( v44 > v43 );
      v46 = (v44 - 1) % (unsigned int)v29;
      v47 = (v44 - 1) / (unsigned int)v29;
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v55 + 16i64))(v55, &v55, v47 + v4->SourceRect.y1);
      (*(void (__fastcall **)(__int64, unsigned int *, __int64 *, _QWORD))(*(_QWORD *)v55 + 40i64))(
        v55,
        &v61,
        &v55,
        v46 + v4->SourceRect.x1);
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v49 + 16i64))(v49, &v49, v47 + v4->DestPoint.y);
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v49 + 24i64))(
        v49,
        &v49,
        v46 + v4->DestPoint.x,
        v61);
      v29 = v62;
      ++v10;
    }
    while ( v10 < v4->NumPixels );
  }
  v48 = v4->Result;
  if ( v48 )
    *v48 = v44;
}

// File Line: 993
// RVA: 0x977580
void __fastcall Scaleform::Render::DICommand_Scroll::ExecuteSW(Scaleform::Render::DICommand_Scroll *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::DICommand_Scroll *v4; // rsi
  int v5; // ecx
  Scaleform::Render::ImagePlane *v6; // rax
  int v7; // er10
  signed int v8; // edx
  Scaleform::Render::ImageData *v9; // r9
  signed int v10; // er8
  Scaleform::Render::ImagePlane *v11; // rax
  int v12; // er13
  int v13; // er11
  int v14; // ebx
  int v15; // edi
  int v16; // eax
  int v17; // er9
  int v18; // er14
  int v19; // er12
  int v20; // eax
  int v21; // ecx
  int v22; // er15
  int v23; // eax
  __int64 v24; // rax
  __int64 v25; // rax
  __int64 v26; // rax
  __int64 v27; // rbx
  __int64 v28; // rax
  int v29; // er15
  int v30; // ebx
  unsigned int v31; // er12
  unsigned int v32; // edi
  __int64 v33; // [rsp+20h] [rbp-49h]
  __int64 v34; // [rsp+28h] [rbp-41h]
  __int64 v35; // [rsp+30h] [rbp-39h]
  int v36; // [rsp+38h] [rbp-31h]
  __int64 v37; // [rsp+40h] [rbp-29h]
  __int64 v38; // [rsp+48h] [rbp-21h]
  __int64 v39; // [rsp+50h] [rbp-19h]
  __int64 v40; // [rsp+58h] [rbp-11h]
  Scaleform::Render::ImageData *v41; // [rsp+60h] [rbp-9h]
  int v42; // [rsp+68h] [rbp-1h]
  __int64 v43; // [rsp+70h] [rbp+7h]
  __int64 v44; // [rsp+78h] [rbp+Fh]
  int v45; // [rsp+D0h] [rbp+67h]
  Scaleform::Render::DICommandContext *v46; // [rsp+D8h] [rbp+6Fh]
  Scaleform::Render::ImageData *v47; // [rsp+E0h] [rbp+77h]
  Scaleform::Render::ImageData **v48; // [rsp+E8h] [rbp+7Fh]

  v48 = psrc;
  v47 = dest;
  v46 = context;
  v4 = this;
  v5 = this->SourceRect.x1;
  v6 = (*psrc)->pPlanes;
  v7 = v4->SourceRect.y1;
  v8 = v6->Width;
  v9 = dest;
  v10 = v6->Height;
  v11 = v9->pPlanes;
  v12 = v4->DestPoint.x - v5;
  v13 = v11->Width;
  v14 = v11->Height;
  v15 = v4->DestPoint.y - v7;
  if ( v10 >= v7 )
  {
    v16 = v4->SourceRect.y2;
    if ( v16 >= 0 )
    {
      v17 = v4->SourceRect.x2;
      if ( v17 >= 0 && v8 >= v5 )
      {
        v18 = 0;
        if ( v5 < 0 )
          v5 = 0;
        if ( v8 > v17 )
          v8 = v4->SourceRect.x2;
        if ( v7 < 0 )
          v7 = 0;
        v19 = v8 + v12;
        if ( v10 > v16 )
          v10 = v4->SourceRect.y2;
        v20 = v5 + v12;
        v21 = v7 + v15;
        v22 = v10 + v15;
        if ( v10 + v15 >= 0 && v14 >= v21 && v13 >= v20 && v19 >= 0 )
        {
          if ( v20 > 0 )
            v18 = v20;
          if ( v19 > v13 )
            v19 = v13;
          v23 = 0;
          if ( v21 > 0 )
            v23 = v7 + v15;
          if ( v22 > v14 )
            v22 = v14;
          v45 = v23;
          v24 = ((__int64 (*)(void))v46->pHAL->vfptr[61].__vecDelDtor)();
          v25 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v24 + 120i64))(v24);
          v40 = 0i64;
          v42 = 0;
          v43 = 0i64;
          v41 = v47;
          v44 = 0i64;
          v39 = v25;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v25 + 8i64))(v25, &v39);
          v26 = ((__int64 (*)(void))v46->pHAL->vfptr[61].__vecDelDtor)();
          v27 = (__int64)*v48;
          v28 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 120i64))(v26);
          v35 = v27;
          v34 = 0i64;
          v36 = 0;
          v37 = 0i64;
          v38 = 0i64;
          v33 = v28;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v28 + 8i64))(v28, &v33);
          v29 = v22 - 1;
          if ( v29 >= v45 )
          {
            v30 = v19 - 1;
            LODWORD(v48) = v19 - 1;
            v31 = v29 - v15;
            do
            {
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v39 + 16i64))(
                v39,
                &v39,
                (unsigned int)v29);
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v33 + 16i64))(v33, &v33, v31);
              if ( v30 >= v18 )
              {
                v32 = v30 - v12;
                do
                {
                  (*(void (__fastcall **)(__int64, Scaleform::Render::ImageData **, __int64 *, _QWORD))(*(_QWORD *)v33 + 40i64))(
                    v33,
                    &v47,
                    &v33,
                    v32);
                  if ( !v4->pSource.pObject->Transparent || !v4->pImage.pObject->Transparent )
                    BYTE3(v47) = -1;
                  (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v39 + 24i64))(
                    v39,
                    &v39,
                    (unsigned int)v30--,
                    (unsigned int)v47);
                  --v32;
                }
                while ( v30 >= v18 );
              }
              v30 = (signed int)v48;
              --v29;
              --v31;
            }
            while ( v29 >= v45 );
          }
        }
      }
    }
  }
}

// File Line: 1037
// RVA: 0x9777F0
void __fastcall Scaleform::Render::DICommand_SetPixel32::ExecuteSW(Scaleform::Render::DICommand_SetPixel32 *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::DICommand_SetPixel32 *v4; // rdi
  Scaleform::Render::ImageData *v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rax
  __int128 v8; // [rsp+20h] [rbp-38h]
  Scaleform::Render::ImageData *v9; // [rsp+30h] [rbp-28h]
  int v10; // [rsp+38h] [rbp-20h]
  __int64 v11; // [rsp+40h] [rbp-18h]
  __int64 v12; // [rsp+48h] [rbp-10h]
  unsigned int v13; // [rsp+60h] [rbp+8h]
  char v14; // [rsp+68h] [rbp+10h]

  v4 = this;
  v5 = dest;
  v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::DICommandContext *, Scaleform::Render::ImageData *, Scaleform::Render::ImageData **))context->pHAL->vfptr[61].__vecDelDtor)(
         context->pHAL,
         context,
         dest,
         __formal);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 120i64))(v6);
  v9 = v5;
  v10 = 0;
  v11 = 0i64;
  v12 = 0i64;
  v8 = (unsigned __int64)v7;
  (*(void (__fastcall **)(__int64, __int128 *))(*(_QWORD *)v7 + 8i64))(v7, &v8);
  (*(void (__fastcall **)(_QWORD, __int128 *, _QWORD))(*(_QWORD *)v8 + 16i64))(v8, &v8, v4->Y);
  v13 = v4->Fill.Raw;
  if ( !v4->OverwriteAlpha )
    (*(void (__fastcall **)(_QWORD, char *, __int128 *, _QWORD))(*(_QWORD *)v8 + 40i64))(v8, &v14, &v8, v4->X);
  (*(void (__fastcall **)(_QWORD, __int128 *, _QWORD))(*(_QWORD *)v8 + 24i64))(v8, &v8, v4->X);
}

// File Line: 1047
// RVA: 0x9778B0
void __fastcall Scaleform::Render::DICommand_SetPixels::ExecuteSW(Scaleform::Render::DICommand_SetPixels *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::DICommand_SetPixels *v4; // rbx
  Scaleform::Render::ImageData *v5; // rdi
  __int64 v6; // rax
  __int64 v7; // rax
  unsigned int v8; // esi
  int v9; // ebp
  int v10; // edi
  unsigned int v11; // eax
  bool *v12; // rax
  bool *v13; // rax
  __int64 v14; // [rsp+20h] [rbp-38h]
  __int64 v15; // [rsp+28h] [rbp-30h]
  Scaleform::Render::ImageData *v16; // [rsp+30h] [rbp-28h]
  int v17; // [rsp+38h] [rbp-20h]
  __int64 v18; // [rsp+40h] [rbp-18h]
  __int64 v19; // [rsp+48h] [rbp-10h]

  v4 = this;
  v5 = dest;
  v6 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::DICommandContext *, Scaleform::Render::ImageData *, Scaleform::Render::ImageData **))context->pHAL->vfptr[61].__vecDelDtor)(
         context->pHAL,
         context,
         dest,
         __formal);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 120i64))(v6);
  v8 = 0;
  v16 = v5;
  v15 = 0i64;
  v17 = 0;
  v18 = 0i64;
  v14 = v7;
  v19 = 0i64;
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v7 + 8i64))(v7, &v14);
  v9 = v4->DestRect.y1;
  if ( v9 >= v4->DestRect.y2 )
  {
LABEL_6:
    v12 = v4->Result;
    if ( v12 )
      *v12 = 1;
  }
  else
  {
    while ( 1 )
    {
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v14 + 16i64))(v14, &v14, (unsigned int)v9);
      v10 = v4->DestRect.x1;
      if ( v10 < v4->DestRect.x2 )
        break;
LABEL_5:
      if ( ++v9 >= v4->DestRect.y2 )
        goto LABEL_6;
    }
    while ( v8 < (unsigned __int64)((__int64 (*)(void))v4->Provider->vfptr->GetLength)() )
    {
      v11 = ((__int64 (*)(void))v4->Provider->vfptr->ReadNextPixel)();
      (*(void (__fastcall **)(__int64, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v14 + 24i64))(
        v14,
        &v14,
        (unsigned int)v10++,
        v11);
      ++v8;
      if ( v10 >= v4->DestRect.x2 )
        goto LABEL_5;
    }
    v13 = v4->Result;
    if ( v13 )
      *v13 = 0;
  }
}

// File Line: 1070
// RVA: 0x9779C0
void __fastcall Scaleform::Render::DICommand_Threshold::ExecuteSW(Scaleform::Render::DICommand_Threshold *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::ImageData *dest, Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImagePlane *v4; // rax
  Scaleform::Render::DICommand_Threshold *v5; // rbx
  Scaleform::Render::ImageData **v6; // r12
  signed int v7; // edi
  signed int v8; // esi
  Scaleform::Render::ImagePlane *v9; // rax
  int v10; // ecx
  signed int v11; // er11
  signed int v12; // er10
  int v13; // eax
  int v14; // er14
  Scaleform::Render::ImageData *v15; // r13
  int v16; // er15
  Scaleform::Render::DICommandContext *v17; // r9
  int v18; // edx
  int v19; // er8
  int v20; // edx
  int v21; // er15
  int v22; // er8
  int v23; // eax
  int v24; // ecx
  int v25; // er14
  __int64 v26; // rax
  __int64 v27; // rax
  __int64 v28; // rsi
  __int64 v29; // rax
  __int64 v30; // rdi
  __int64 v31; // rax
  int v32; // er13
  int v33; // er12
  int v34; // edi
  int v35; // edi
  unsigned int v36; // er8
  unsigned int v37; // edx
  bool v38; // r9
  unsigned int v39; // er8
  char v40; // cl
  __int64 v41; // r9
  int v42; // [rsp+20h] [rbp-59h]
  int v43; // [rsp+24h] [rbp-55h]
  __int64 v44; // [rsp+28h] [rbp-51h]
  __int64 v45; // [rsp+30h] [rbp-49h]
  __int64 v46; // [rsp+38h] [rbp-41h]
  int v47; // [rsp+40h] [rbp-39h]
  __int64 v48; // [rsp+48h] [rbp-31h]
  __int64 v49; // [rsp+50h] [rbp-29h]
  __int64 v50; // [rsp+58h] [rbp-21h]
  __int64 v51; // [rsp+60h] [rbp-19h]
  Scaleform::Render::ImageData *v52; // [rsp+68h] [rbp-11h]
  int v53; // [rsp+70h] [rbp-9h]
  __int64 v54; // [rsp+78h] [rbp-1h]
  __int64 v55; // [rsp+80h] [rbp+7h]
  __int64 v56; // [rsp+E0h] [rbp+67h]
  Scaleform::Render::DICommandContext *v57; // [rsp+E8h] [rbp+6Fh]
  int v58; // [rsp+F0h] [rbp+77h]
  int v59; // [rsp+F8h] [rbp+7Fh]

  v57 = context;
  v4 = dest->pPlanes;
  v5 = this;
  v6 = psrc;
  v7 = v4->Width;
  v8 = v4->Height;
  v9 = (*psrc)->pPlanes;
  v10 = this->SourceRect.y1;
  v11 = v9->Height;
  v12 = v9->Width;
  v13 = v5->SourceRect.x1;
  v14 = v5->DestPoint.y - v10;
  v15 = dest;
  v16 = v5->DestPoint.x - v13;
  v17 = context;
  v58 = v5->DestPoint.y - v10;
  v59 = v16;
  if ( v11 >= v10 )
  {
    v18 = v5->SourceRect.y2;
    if ( v18 >= 0 )
    {
      v19 = v5->SourceRect.x2;
      if ( v19 >= 0 && v12 >= v13 )
      {
        v56 = 0i64;
        if ( v13 < 0 )
          v13 = v56;
        if ( v12 > v19 )
          v12 = v19;
        if ( v10 < 0 )
          v10 = v56;
        if ( v11 > v18 )
          v11 = v18;
        v20 = v13 + v16;
        v21 = v12 + v16;
        v22 = v11 + v14;
        v23 = v10 + v14;
        if ( v11 + v14 >= 0 && v8 >= v23 && v7 >= v20 && v21 >= 0 )
        {
          v24 = v56;
          v25 = v56;
          if ( v20 > 0 )
            v24 = v20;
          if ( v21 > v7 )
            v21 = v7;
          v43 = v24;
          if ( v23 > 0 )
            v25 = v23;
          if ( v22 > v8 )
            v22 = v8;
          v42 = v22;
          v26 = ((__int64 (*)(void))v17->pHAL->vfptr[61].__vecDelDtor)();
          v27 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 120i64))(v26);
          v28 = v56;
          v52 = v15;
          v51 = v56;
          v53 = v56;
          v54 = v56;
          v55 = v56;
          v50 = v27;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v27 + 8i64))(v27, &v50);
          v29 = ((__int64 (*)(void))v57->pHAL->vfptr[61].__vecDelDtor)();
          v30 = (__int64)*v6;
          v31 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v29 + 120i64))(v29);
          v45 = v28;
          v46 = v30;
          v47 = v28;
          v48 = v28;
          v49 = v28;
          v44 = v31;
          (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v31 + 8i64))(v31, &v44);
          v32 = v42;
          if ( v25 < v42 )
          {
            v33 = v59;
            v34 = -v58;
            v58 = -v58;
            do
            {
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v50 + 16i64))(
                v50,
                &v50,
                (unsigned int)v25);
              (*(void (__fastcall **)(__int64, __int64 *, _QWORD))(*(_QWORD *)v44 + 16i64))(
                v44,
                &v44,
                (unsigned int)(v34 + v25));
              v35 = v43;
              if ( v43 < v21 )
              {
                do
                {
                  (*(void (__fastcall **)(__int64, __int64 *, __int64 *, _QWORD))(*(_QWORD *)v44 + 40i64))(
                    v44,
                    &v56,
                    &v44,
                    (unsigned int)(v35 - v33));
                  v36 = v5->Mask;
                  v37 = v56 & v36;
                  v38 = 0;
                  v39 = v5->Threshold & v36;
                  switch ( v5->Operation )
                  {
                    case 0:
                      v38 = v37 < v39;
                      break;
                    case 1:
                      v38 = v37 <= v39;
                      break;
                    case 2:
                      v38 = v37 > v39;
                      break;
                    case 3:
                      v38 = v37 >= v39;
                      break;
                    case 4:
                      v38 = v37 == v39;
                      break;
                    case 5:
                      v38 = v37 != v39;
                      break;
                    default:
                      break;
                  }
                  v40 = BYTE3(v56);
                  if ( !v5->pSource.pObject->Transparent )
                    v40 = -1;
                  BYTE3(v56) = v40;
                  if ( v38 )
                    v41 = v5->ThresholdColor;
                  else
                    v41 = (unsigned int)v56;
                  if ( !v5->pImage.pObject->Transparent )
                    v41 = (unsigned int)v41 | 0xFF000000;
                  (*(void (__fastcall **)(__int64, __int64 *, _QWORD, __int64))(*(_QWORD *)v50 + 24i64))(
                    v50,
                    &v50,
                    (unsigned int)v35++,
                    v41);
                }
                while ( v35 < v21 );
                v33 = v59;
                v32 = v42;
              }
              v34 = v58;
              ++v25;
            }
            while ( v25 < v32 );
          }
        }
      }
    }
  }
}

