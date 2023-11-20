// File Line: 39
// RVA: 0x42C730
signed __int64 __fastcall UFG::GetLeaderboardCategoryFromString(const char *pcString)
{
  unsigned int v1; // ebx
  const char *v2; // rdi
  signed __int64 result; // rax

  v1 = -1;
  v2 = pcString;
  result = UFG::qStringCompare(pcString, "StatAwards", -1);
  if ( (_DWORD)result )
  {
    if ( (unsigned int)UFG::qStringCompare(v2, "StatGames", -1) )
    {
      if ( (unsigned int)UFG::qStringCompare(v2, "Missions", -1) )
      {
        if ( !(unsigned int)UFG::qStringCompare(v2, "Races", -1) )
          v1 = 3;
        result = v1;
      }
      else
      {
        result = 2i64;
      }
    }
    else
    {
      result = 1i64;
    }
  }
  return result;
}

// File Line: 90
// RVA: 0x430F10
bool __fastcall UFG::SortByMapFloatUtilsLargestToSmallest(UFG::MapFloatSortUtil *a, UFG::MapFloatSortUtil *b)
{
  return b->mFloatValue < a->mFloatValue;
}

// File Line: 96
// RVA: 0x1506980
__int64 UFG::_dynamic_initializer_for__aHardcodedLeaderboardData__()
{
  UFG::qString::qString(&stru_1423F8C78, "StatAwardsOverall");
  UFG::qSymbol::create_from_string(&stru_1423F8CA0, "StatAwardsOverall");
  UFG::qString::qString(&stru_1423F8CA8, "$LEADERBOARD_STATAWARDS_OVERALL");
  unk_1423F8CD0 = 0;
  UFG::qString::qString(&stru_1423F8CD8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F8D00, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423F8D08, "$LEADERBOARD_STATAWARDS_OVERALL_DESC");
  UFG::qString::qString(&stru_1423F8D30, &customWorldMapCaption);
  unk_1423F8D58 = "Rank";
  _mm_store_si128((__m128i *)&unk_1423F8D60, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423F8D70 = 0i64;
  UFG::qString::qString(&stru_1423F8D78, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F8DA0, "Main");
  unk_1423F8DA8 = 1;
  unk_1423F8DAC = 1;
  UFG::qString::qString(&stru_1423F8DB0, "StatAwardsFluidStriker");
  UFG::qSymbol::create_from_string(&stru_1423F8DD8, "StatAwardsFluidStriker");
  UFG::qString::qString(&stru_1423F8DE0, "$LEADERBOARD_STATAWARDS_FLUID_STRIKER");
  unk_1423F8E08 = 0;
  UFG::qString::qString(&stru_1423F8E10, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F8E38, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423F8E40, "$LEADERBOARD_STATAWARDS_FLUID_STRIKER_DESC");
  UFG::qString::qString(&stru_1423F8E68, &customWorldMapCaption);
  unk_1423F8E90 = "Int32";
  unk_1423F8E98 = 50;
  unk_1423F8E9C = 25;
  _mm_store_si128((__m128i *)&unk_1423F8EA0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423F8EB0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F8ED8, "Main");
  unk_1423F8EE0 = 2;
  unk_1423F8EE4 = 2;
  UFG::qString::qString(&stru_1423F8EE8, "StatAwardsHeadhunter");
  UFG::qSymbol::create_from_string(&stru_1423F8F10, "StatAwardsHeadhunter");
  UFG::qString::qString(&stru_1423F8F18, "$LEADERBOARD_STATAWARDS_HEADHUNTER");
  unk_1423F8F40 = 0;
  UFG::qString::qString(&stru_1423F8F48, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F8F70, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423F8F78, "$LEADERBOARD_STATAWARDS_HEADHUNTER_DESC");
  UFG::qString::qString(&stru_1423F8FA0, &customWorldMapCaption);
  unk_1423F8FC8 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423F8FD0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423F8FE0 = 0i64;
  UFG::qString::qString(&stru_1423F8FE8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9010, "Main");
  unk_1423F9018 = 3;
  unk_1423F901C = 3;
  UFG::qString::qString(&stru_1423F9020, "StatAwardsLuckyShooter");
  UFG::qSymbol::create_from_string(&stru_1423F9048, "StatAwardsLuckyShooter");
  UFG::qString::qString(&stru_1423F9050, "$LEADERBOARD_STATAWARDS_LUCKY_SHOOTER");
  unk_1423F9078 = 0;
  UFG::qString::qString(&stru_1423F9080, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F90A8, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423F90B0, "$LEADERBOARD_STATAWARDS_LUCKY_SHOOTER_DESC");
  UFG::qString::qString(&stru_1423F90D8, &customWorldMapCaption);
  unk_1423F9100 = "Int32";
  unk_1423F9108 = 10;
  unk_1423F910C = 5;
  _mm_store_si128((__m128i *)&unk_1423F9110, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423F9120, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9148, "Main");
  unk_1423F9150 = 4;
  unk_1423F9154 = 4;
  UFG::qString::qString(&stru_1423F9158, "StatAwardsFirestarter");
  UFG::qSymbol::create_from_string(&stru_1423F9180, "StatAwardsFirestarter");
  UFG::qString::qString(&stru_1423F9188, "$LEADERBOARD_STATAWARDS_FIRESTARTER");
  unk_1423F91B0 = 0;
  UFG::qString::qString(&stru_1423F91B8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F91E0, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423F91E8, "$LEADERBOARD_STATAWARDS_FIRESTARTER_DESC");
  UFG::qString::qString(&stru_1423F9210, &customWorldMapCaption);
  unk_1423F9238 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423F9240, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423F9250 = 0i64;
  UFG::qString::qString(&stru_1423F9258, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9280, "Main");
  unk_1423F9288 = 5;
  unk_1423F928C = 5;
  UFG::qString::qString(&stru_1423F9290, "StatAwardsSniper");
  UFG::qSymbol::create_from_string(&stru_1423F92B8, "StatAwardsSniper");
  UFG::qString::qString(&stru_1423F92C0, "$LEADERBOARD_STATAWARDS_SNIPER");
  unk_1423F92E8 = 0;
  UFG::qString::qString(&stru_1423F92F0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9318, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423F9320, "$LEADERBOARD_STATAWARDS_SNIPER_DESC");
  UFG::qString::qString(&stru_1423F9348, &customWorldMapCaption);
  unk_1423F9370 = "Percentage";
  unk_1423F9378 = 50;
  unk_1423F937C = 30;
  _mm_store_si128((__m128i *)&unk_1423F9380, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423F9390, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F93B8, "Main");
  unk_1423F93C0 = 6;
  unk_1423F93C4 = 6;
  UFG::qString::qString(&stru_1423F93C8, "StatAwardsGunman");
  UFG::qSymbol::create_from_string(&stru_1423F93F0, "StatAwardsGunman");
  UFG::qString::qString(&stru_1423F93F8, "$LEADERBOARD_STATAWARDS_GUNMAN");
  unk_1423F9420 = 0;
  UFG::qString::qString(&stru_1423F9428, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9450, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423F9458, "$LEADERBOARD_STATAWARDS_GUNMAN_DESC");
  UFG::qString::qString(&stru_1423F9480, &customWorldMapCaption);
  unk_1423F94A8 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423F94B0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423F94C0 = 0i64;
  UFG::qString::qString(&stru_1423F94C8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F94F0, "Main");
  unk_1423F94F8 = 7;
  unk_1423F94FC = 7;
  UFG::qString::qString(&stru_1423F9500, "StatAwardsNinja");
  UFG::qSymbol::create_from_string(&stru_1423F9528, "StatAwardsNinja");
  UFG::qString::qString(&stru_1423F9530, "$LEADERBOARD_STATAWARDS_NINJA");
  unk_1423F9558 = 0;
  UFG::qString::qString(&stru_1423F9560, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9588, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423F9590, "$LEADERBOARD_STATAWARDS_NINJA_DESC");
  UFG::qString::qString(&stru_1423F95B8, &customWorldMapCaption);
  unk_1423F95E0 = "Int32";
  unk_1423F95E8 = 10;
  unk_1423F95EC = 5;
  _mm_store_si128((__m128i *)&unk_1423F95F0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423F9600, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9628, "Main");
  unk_1423F9630 = 8;
  unk_1423F9634 = 8;
  UFG::qString::qString(&stru_1423F9638, "StatAwardsBonebreaker");
  UFG::qSymbol::create_from_string(&stru_1423F9660, "StatAwardsBonebreaker");
  UFG::qString::qString(&stru_1423F9668, "$LEADERBOARD_STATAWARDS_BONEBREAKER");
  unk_1423F9690 = 0;
  UFG::qString::qString(&stru_1423F9698, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F96C0, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423F96C8, "$LEADERBOARD_STATAWARDS_BONEBREAKER_DESC");
  UFG::qString::qString(&stru_1423F96F0, &customWorldMapCaption);
  unk_1423F9718 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423F9720, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423F9730 = 0i64;
  UFG::qString::qString(&stru_1423F9738, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9760, "Main");
  unk_1423F9768 = 9;
  unk_1423F976C = 9;
  UFG::qString::qString(&stru_1423F9770, "StatAwardsEnvironmentalist");
  UFG::qSymbol::create_from_string(&stru_1423F9798, "StatAwardsEnvironmentalist");
  UFG::qString::qString(&stru_1423F97A0, "$LEADERBOARD_STATAWARDS_ENVIRONMENTALIST");
  unk_1423F97C8 = 0;
  UFG::qString::qString(&stru_1423F97D0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F97F8, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423F9800, "$LEADERBOARD_STATAWARDS_ENVIRONMENTALIST_DESC");
  UFG::qString::qString(&stru_1423F9828, &customWorldMapCaption);
  unk_1423F9850 = "Int32";
  unk_1423F9858 = 50;
  unk_1423F985C = 25;
  _mm_store_si128((__m128i *)&unk_1423F9860, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423F9870, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9898, "Main");
  unk_1423F98A0 = 10;
  unk_1423F98A4 = 10;
  UFG::qString::qString(&stru_1423F98A8, "StatAwardsHandyman");
  UFG::qSymbol::create_from_string(&stru_1423F98D0, "StatAwardsHandyman");
  UFG::qString::qString(&stru_1423F98D8, "$LEADERBOARD_STATAWARDS_HANDYMAN");
  unk_1423F9900 = 0;
  UFG::qString::qString(&stru_1423F9908, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9930, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423F9938, "$LEADERBOARD_STATAWARDS_HANDYMAN_DESC");
  UFG::qString::qString(&stru_1423F9960, &customWorldMapCaption);
  unk_1423F9988 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423F9990, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423F99A0 = 0i64;
  UFG::qString::qString(&stru_1423F99A8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F99D0, "Main");
  unk_1423F99D8 = 11;
  unk_1423F99DC = 11;
  UFG::qString::qString(&stru_1423F99E0, "StatAwardsDisarming");
  UFG::qSymbol::create_from_string(&stru_1423F9A08, "StatAwardsDisarming");
  UFG::qString::qString(&stru_1423F9A10, "$LEADERBOARD_STATAWARDS_DISARMING");
  unk_1423F9A38 = 0;
  UFG::qString::qString(&stru_1423F9A40, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9A68, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423F9A70, "$LEADERBOARD_STATAWARDS_DISARMING_DESC");
  UFG::qString::qString(&stru_1423F9A98, &customWorldMapCaption);
  unk_1423F9AC0 = "Int32";
  unk_1423F9AC8 = 50;
  unk_1423F9ACC = 25;
  _mm_store_si128((__m128i *)&unk_1423F9AD0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423F9AE0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9B08, "Main");
  unk_1423F9B10 = 12;
  unk_1423F9B14 = 12;
  UFG::qString::qString(&stru_1423F9B18, "StatAwardsDefence");
  UFG::qSymbol::create_from_string(&stru_1423F9B40, "StatAwardsDefence");
  UFG::qString::qString(&stru_1423F9B48, "$LEADERBOARD_STATAWARDS_DEFENCE");
  unk_1423F9B70 = 0;
  UFG::qString::qString(&stru_1423F9B78, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9BA0, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423F9BA8, "$LEADERBOARD_STATAWARDS_DEFENCE_DESC");
  UFG::qString::qString(&stru_1423F9BD0, &customWorldMapCaption);
  unk_1423F9BF8 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423F9C00, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423F9C10 = 0i64;
  UFG::qString::qString(&stru_1423F9C18, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9C40, "Main");
  unk_1423F9C48 = 13;
  unk_1423F9C4C = 13;
  UFG::qString::qString(&stru_1423F9C50, "StatAwardsFastTalker");
  UFG::qSymbol::create_from_string(&stru_1423F9C78, "StatAwardsFastTalker");
  UFG::qString::qString(&stru_1423F9C80, "$LEADERBOARD_STATAWARDS_FAST_TALKER");
  unk_1423F9CA8 = 0;
  UFG::qString::qString(&stru_1423F9CB0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9CD8, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423F9CE0, "$LEADERBOARD_STATAWARDS_FAST_TALKER_DESC");
  UFG::qString::qString(&stru_1423F9D08, &customWorldMapCaption);
  unk_1423F9D30 = "Int32";
  unk_1423F9D38 = 10;
  unk_1423F9D3C = 5;
  _mm_store_si128((__m128i *)&unk_1423F9D40, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423F9D50, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9D78, "Main");
  unk_1423F9D80 = 14;
  unk_1423F9D84 = 14;
  UFG::qString::qString(&stru_1423F9D88, "StatAwardsDeadeye");
  UFG::qSymbol::create_from_string(&stru_1423F9DB0, "StatAwardsDeadeye");
  UFG::qString::qString(&stru_1423F9DB8, "$LEADERBOARD_STATAWARDS_DEADEYE");
  unk_1423F9DE0 = 0;
  UFG::qString::qString(&stru_1423F9DE8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9E10, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423F9E18, "$LEADERBOARD_STATAWARDS_DEADEYE_DESC");
  UFG::qString::qString(&stru_1423F9E40, &customWorldMapCaption);
  unk_1423F9E68 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423F9E70, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423F9E80 = 0i64;
  UFG::qString::qString(&stru_1423F9E88, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9EB0, "Main");
  unk_1423F9EB8 = 15;
  unk_1423F9EBC = 15;
  UFG::qString::qString(&stru_1423F9EC0, "StatAwardsMartialArtist");
  UFG::qSymbol::create_from_string(&stru_1423F9EE8, "StatAwardsMartialArtist");
  UFG::qString::qString(&stru_1423F9EF0, "$LEADERBOARD_STATAWARDS_MARTIAL_ARTIST");
  unk_1423F9F18 = 0;
  UFG::qString::qString(&stru_1423F9F20, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9F48, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423F9F50, "$LEADERBOARD_STATAWARDS_MARTIAL_ARTIST_DESC");
  UFG::qString::qString(&stru_1423F9F78, &customWorldMapCaption);
  unk_1423F9FA0 = "Int32";
  unk_1423F9FA8 = 100;
  unk_1423F9FAC = 50;
  _mm_store_si128((__m128i *)&unk_1423F9FB0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423F9FC0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9FE8, "Main");
  unk_1423F9FF0 = 16;
  unk_1423F9FF4 = 16;
  UFG::qString::qString(&stru_1423F9FF8, "StatAwardsEnforcer");
  UFG::qSymbol::create_from_string(&stru_1423FA020, "StatAwardsEnforcer");
  UFG::qString::qString(&stru_1423FA028, "$LEADERBOARD_STATAWARDS_ENFORCER");
  unk_1423FA050 = 0;
  UFG::qString::qString(&stru_1423FA058, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA080, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FA088, "$LEADERBOARD_STATAWARDS_ENFORCER_DESC");
  UFG::qString::qString(&stru_1423FA0B0, &customWorldMapCaption);
  unk_1423FA0D8 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FA0E0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FA0F0 = 0i64;
  UFG::qString::qString(&stru_1423FA0F8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA120, "Main");
  unk_1423FA128 = 17;
  unk_1423FA12C = 17;
  UFG::qString::qString(&stru_1423FA130, "StatAwardsSafeDriver");
  UFG::qSymbol::create_from_string(&stru_1423FA158, "StatAwardsSafeDriver");
  UFG::qString::qString(&stru_1423FA160, "$LEADERBOARD_STATAWARDS_SAFE_DRIVER");
  unk_1423FA188 = 0;
  UFG::qString::qString(&stru_1423FA190, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA1B8, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FA1C0, "$LEADERBOARD_STATAWARDS_SAFE_DRIVER_DESC");
  UFG::qString::qString(&stru_1423FA1E8, &customWorldMapCaption);
  unk_1423FA210 = "RaceTime";
  unk_1423FA218 = 1800;
  unk_1423FA21C = 900;
  _mm_store_si128((__m128i *)&unk_1423FA220, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FA230, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA258, "Main");
  unk_1423FA260 = 18;
  unk_1423FA264 = 18;
  UFG::qString::qString(&stru_1423FA268, "StatAwardsRecklessDriver");
  UFG::qSymbol::create_from_string(&stru_1423FA290, "StatAwardsRecklessDriver");
  UFG::qString::qString(&stru_1423FA298, "$LEADERBOARD_STATAWARDS_RECKLESS_DRIVER");
  unk_1423FA2C0 = 0;
  UFG::qString::qString(&stru_1423FA2C8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA2F0, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FA2F8, "$LEADERBOARD_STATAWARDS_RECKLESS_DRIVER_DESC");
  UFG::qString::qString(&stru_1423FA320, &customWorldMapCaption);
  unk_1423FA348 = "RaceTime";
  _mm_store_si128((__m128i *)&unk_1423FA350, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FA360 = 0i64;
  UFG::qString::qString(&stru_1423FA368, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA390, "Main");
  unk_1423FA398 = 19;
  unk_1423FA39C = 19;
  UFG::qString::qString(&stru_1423FA3A0, "StatAwardsHijacker");
  UFG::qSymbol::create_from_string(&stru_1423FA3C8, "StatAwardsHijacker");
  UFG::qString::qString(&stru_1423FA3D0, "$LEADERBOARD_STATAWARDS_HIJACKER");
  unk_1423FA3F8 = 0;
  UFG::qString::qString(&stru_1423FA400, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA428, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FA430, "$LEADERBOARD_STATAWARDS_HIJACKER_DESC");
  UFG::qString::qString(&stru_1423FA458, &customWorldMapCaption);
  unk_1423FA480 = "Int32";
  unk_1423FA488 = 20;
  unk_1423FA48C = 10;
  _mm_store_si128((__m128i *)&unk_1423FA490, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FA4A0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA4C8, "Main");
  unk_1423FA4D0 = 20;
  unk_1423FA4D4 = 20;
  UFG::qString::qString(&stru_1423FA4D8, "StatAwardsWrecker");
  UFG::qSymbol::create_from_string(&stru_1423FA500, "StatAwardsWrecker");
  UFG::qString::qString(&stru_1423FA508, "$LEADERBOARD_STATAWARDS_WRECKER");
  unk_1423FA530 = 0;
  UFG::qString::qString(&stru_1423FA538, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA560, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FA568, "$LEADERBOARD_STATAWARDS_WRECKER_DESC");
  UFG::qString::qString(&stru_1423FA590, &customWorldMapCaption);
  unk_1423FA5B8 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FA5C0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FA5D0 = 0i64;
  UFG::qString::qString(&stru_1423FA5D8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA600, "Main");
  unk_1423FA608 = 21;
  unk_1423FA60C = 21;
  UFG::qString::qString(&stru_1423FA610, "StatAwardsRacer");
  UFG::qSymbol::create_from_string(&stru_1423FA638, "StatAwardsRacer");
  UFG::qString::qString(&stru_1423FA640, "$LEADERBOARD_STATAWARDS_RACER");
  unk_1423FA668 = 0;
  UFG::qString::qString(&stru_1423FA670, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA698, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FA6A0, "$LEADERBOARD_STATAWARDS_RACER_DESC");
  UFG::qString::qString(&stru_1423FA6C8, &customWorldMapCaption);
  unk_1423FA6F0 = "Int32";
  unk_1423FA6F8 = 17;
  unk_1423FA6FC = 10;
  _mm_store_si128((__m128i *)&unk_1423FA700, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FA710, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA738, "Main");
  unk_1423FA740 = 22;
  unk_1423FA744 = 22;
  UFG::qString::qString(&stru_1423FA748, "StatAwardsMogul");
  UFG::qSymbol::create_from_string(&stru_1423FA770, "StatAwardsMogul");
  UFG::qString::qString(&stru_1423FA778, "$LEADERBOARD_STATAWARDS_MOGUL");
  unk_1423FA7A0 = 0;
  UFG::qString::qString(&stru_1423FA7A8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA7D0, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FA7D8, "$LEADERBOARD_STATAWARDS_MOGUL_DESC");
  UFG::qString::qString(&stru_1423FA800, &customWorldMapCaption);
  unk_1423FA828 = "Money";
  _mm_store_si128((__m128i *)&unk_1423FA830, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FA840 = 0i64;
  UFG::qString::qString(&stru_1423FA848, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA870, "Main");
  unk_1423FA878 = 23;
  unk_1423FA87C = 23;
  UFG::qString::qString(&stru_1423FA880, "StatAwardsBigSpender");
  UFG::qSymbol::create_from_string(&stru_1423FA8A8, "StatAwardsBigSpender");
  UFG::qString::qString(&stru_1423FA8B0, "$LEADERBOARD_STATAWARDS_BIG_SPENDER");
  unk_1423FA8D8 = 0;
  UFG::qString::qString(&stru_1423FA8E0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA908, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FA910, "$LEADERBOARD_STATAWARDS_BIG_SPENDER_DESC");
  UFG::qString::qString(&stru_1423FA938, &customWorldMapCaption);
  unk_1423FA960 = "Money";
  unk_1423FA968 = 2000000;
  unk_1423FA96C = 500000;
  _mm_store_si128((__m128i *)&unk_1423FA970, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FA980, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA9A8, "Main");
  unk_1423FA9B0 = 24;
  unk_1423FA9B4 = 24;
  UFG::qString::qString(&stru_1423FA9B8, "StatAwardsGambler");
  UFG::qSymbol::create_from_string(&stru_1423FA9E0, "StatAwardsGambler");
  UFG::qString::qString(&stru_1423FA9E8, "$LEADERBOARD_STATAWARDS_GAMBLER");
  unk_1423FAA10 = 0;
  UFG::qString::qString(&stru_1423FAA18, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FAA40, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FAA48, "$LEADERBOARD_STATAWARDS_GAMBLER_DESC");
  UFG::qString::qString(&stru_1423FAA70, &customWorldMapCaption);
  unk_1423FAA98 = "Money";
  _mm_store_si128((__m128i *)&unk_1423FAAA0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FAAB0 = 0i64;
  UFG::qString::qString(&stru_1423FAAB8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FAAE0, "Main");
  unk_1423FAAE8 = 25;
  unk_1423FAAEC = 25;
  UFG::qString::qString(&stru_1423FAAF0, "StatAwardsCompletionist");
  UFG::qSymbol::create_from_string(&stru_1423FAB18, "StatAwardsCompletionist");
  UFG::qString::qString(&stru_1423FAB20, "$LEADERBOARD_STATAWARDS_COMPLETIONIST");
  unk_1423FAB48 = 0;
  UFG::qString::qString(&stru_1423FAB50, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FAB78, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FAB80, "$LEADERBOARD_STATAWARDS_COMPLETIONIST_DESC");
  UFG::qString::qString(&stru_1423FABA8, &customWorldMapCaption);
  unk_1423FABD0 = "Percentage";
  unk_1423FABD8 = 100;
  unk_1423FABDC = 60;
  _mm_store_si128((__m128i *)&unk_1423FABE0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FABF0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FAC18, "Main");
  unk_1423FAC20 = 26;
  unk_1423FAC24 = 26;
  UFG::qString::qString(&stru_1423FAC28, "StatAwardsExplorer");
  UFG::qSymbol::create_from_string(&stru_1423FAC50, "StatAwardsExplorer");
  UFG::qString::qString(&stru_1423FAC58, "$LEADERBOARD_STATAWARDS_EXPLORER");
  unk_1423FAC80 = 0;
  UFG::qString::qString(&stru_1423FAC88, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FACB0, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FACB8, "$LEADERBOARD_STATAWARDS_EXPLORER_DESC");
  UFG::qString::qString(&stru_1423FACE0, &customWorldMapCaption);
  unk_1423FAD08 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FAD10, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FAD20 = 0i64;
  UFG::qString::qString(&stru_1423FAD28, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FAD50, "Main");
  unk_1423FAD58 = 27;
  unk_1423FAD5C = 27;
  UFG::qString::qString(&stru_1423FAD60, "StatAwardsSurvivor");
  UFG::qSymbol::create_from_string(&stru_1423FAD88, "StatAwardsSurvivor");
  UFG::qString::qString(&stru_1423FAD90, "$LEADERBOARD_STATAWARDS_SURVIVOR");
  unk_1423FADB8 = 0;
  UFG::qString::qString(&stru_1423FADC0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FADE8, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FADF0, "$LEADERBOARD_STATAWARDS_SURVIVOR_DESC");
  UFG::qString::qString(&stru_1423FAE18, &customWorldMapCaption);
  unk_1423FAE40 = "RaceTime";
  unk_1423FAE48 = 1200;
  unk_1423FAE4C = 600;
  _mm_store_si128((__m128i *)&unk_1423FAE50, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FAE60, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FAE88, "Main");
  unk_1423FAE90 = 28;
  unk_1423FAE94 = 28;
  UFG::qString::qString(&stru_1423FAE98, "StatAwardsCopKiller");
  UFG::qSymbol::create_from_string(&stru_1423FAEC0, "StatAwardsCopKiller");
  UFG::qString::qString(&stru_1423FAEC8, "$LEADERBOARD_STATAWARDS_COP_KILLER");
  unk_1423FAEF0 = 0;
  UFG::qString::qString(&stru_1423FAEF8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FAF20, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FAF28, "$LEADERBOARD_STATAWARDS_COP_KILLER_DESC");
  UFG::qString::qString(&stru_1423FAF50, &customWorldMapCaption);
  unk_1423FAF78 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FAF80, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FAF90 = 0i64;
  UFG::qString::qString(&stru_1423FAF98, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FAFC0, "Main");
  unk_1423FAFC8 = 29;
  unk_1423FAFCC = 29;
  UFG::qString::qString(&stru_1423FAFD0, "StatAwardsPublicEnemy");
  UFG::qSymbol::create_from_string(&stru_1423FAFF8, "StatAwardsPublicEnemy");
  UFG::qString::qString(&stru_1423FB000, "$LEADERBOARD_STATAWARDS_PUBLIC_ENEMY");
  unk_1423FB028 = 0;
  UFG::qString::qString(&stru_1423FB030, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB058, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FB060, "$LEADERBOARD_STATAWARDS_PUBLIC_ENEMY_DESC");
  UFG::qString::qString(&stru_1423FB088, &customWorldMapCaption);
  unk_1423FB0B0 = "Int32";
  unk_1423FB0B8 = 200;
  unk_1423FB0BC = 100;
  _mm_store_si128((__m128i *)&unk_1423FB0C0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FB0D0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB0F8, "Main");
  unk_1423FB100 = 100;
  unk_1423FB104 = 30;
  UFG::qString::qString(&stru_1423FB108, "StatAwardsJiangShiDefeated");
  UFG::qSymbol::create_from_string(&stru_1423FB130, "StatAwardsJiangShiDefeated");
  UFG::qString::qString(&stru_1423FB138, "$LEADERBOARD_STATAWARDS_JIANG_SHI_DEFEATED");
  unk_1423FB160 = 0;
  UFG::qString::qString(&stru_1423FB168, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB190, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FB198, "$LEADERBOARD_STATAWARDS_JIANG_SHI_DEFEATED_DESC");
  UFG::qString::qString(&stru_1423FB1C0, &customWorldMapCaption);
  unk_1423FB1E8 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FB1F0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FB200 = 0i64;
  UFG::qString::qString(&stru_1423FB208, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB230, "DLC_Ghost");
  unk_1423FB238 = 101;
  unk_1423FB23C = 31;
  UFG::qString::qString(&stru_1423FB240, "StatAwardsYaoguaiDefeated");
  UFG::qSymbol::create_from_string(&stru_1423FB268, "StatAwardsYaoguaiDefeated");
  UFG::qString::qString(&stru_1423FB270, "$LEADERBOARD_STATAWARDS_YAOGUAI_DEFEATED");
  unk_1423FB298 = 0;
  UFG::qString::qString(&stru_1423FB2A0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB2C8, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FB2D0, "$LEADERBOARD_STATAWARDS_YAOGUAI_DEFEATED_DESC");
  UFG::qString::qString(&stru_1423FB2F8, &customWorldMapCaption);
  unk_1423FB320 = "Int32";
  unk_1423FB328 = 20;
  unk_1423FB32C = 10;
  _mm_store_si128((__m128i *)&unk_1423FB330, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FB340, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB368, "DLC_Ghost");
  unk_1423FB370 = 102;
  unk_1423FB374 = 32;
  UFG::qString::qString(&stru_1423FB378, "StatAwardsYaoguaiPeachwooded");
  UFG::qSymbol::create_from_string(&stru_1423FB3A0, "StatAwardsYaoguaiPeachwooded");
  UFG::qString::qString(&stru_1423FB3A8, "$LEADERBOARD_STATAWARDS_YAOGUAI_PEACHWOODED");
  unk_1423FB3D0 = 0;
  UFG::qString::qString(&stru_1423FB3D8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB400, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FB408, "$LEADERBOARD_STATAWARDS_YAOGUAI_PEACHWOODED_DESC");
  UFG::qString::qString(&stru_1423FB430, &customWorldMapCaption);
  unk_1423FB458 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FB460, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FB470 = 0i64;
  UFG::qString::qString(&stru_1423FB478, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB4A0, "DLC_Ghost");
  unk_1423FB4A8 = 103;
  unk_1423FB4AC = 33;
  UFG::qString::qString(&stru_1423FB4B0, "StatAwardsBitesAvoided");
  UFG::qSymbol::create_from_string(&stru_1423FB4D8, "StatAwardsBitesAvoided");
  UFG::qString::qString(&stru_1423FB4E0, "$LEADERBOARD_STATAWARDS_BITES_AVOIDED");
  unk_1423FB508 = 0;
  UFG::qString::qString(&stru_1423FB510, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB538, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FB540, "$LEADERBOARD_STATAWARDS_BITES_AVOIDED_DESC");
  UFG::qString::qString(&stru_1423FB568, &customWorldMapCaption);
  unk_1423FB590 = "Int32";
  unk_1423FB598 = 100;
  unk_1423FB59C = 60;
  _mm_store_si128((__m128i *)&unk_1423FB5A0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FB5B0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB5D8, "DLC_Ghost");
  unk_1423FB5E0 = 104;
  unk_1423FB5E4 = 34;
  UFG::qString::qString(&stru_1423FB5E8, "StatAwardsHellMoneyShrines");
  UFG::qSymbol::create_from_string(&stru_1423FB610, "StatAwardsHellMoneyShrines");
  UFG::qString::qString(&stru_1423FB618, "$LEADERBOARD_STATAWARDS_HELL_MONEY_SHRINES");
  unk_1423FB640 = 0;
  UFG::qString::qString(&stru_1423FB648, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB670, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FB678, "$LEADERBOARD_STATAWARDS_HELL_MONEY_SHRINES_DESC");
  UFG::qString::qString(&stru_1423FB6A0, &customWorldMapCaption);
  unk_1423FB6C8 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FB6D0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FB6E0 = 0i64;
  UFG::qString::qString(&stru_1423FB6E8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB710, "DLC_Ghost");
  unk_1423FB718 = 30i64;
  UFG::qString::qString(&stru_1423FB720, "StatGamesCarJump");
  UFG::qSymbol::create_from_string(&stru_1423FB748, "StatGamesCarJump");
  UFG::qString::qString(&stru_1423FB750, "$LEADERBOARD_CHALLENGES_CAR_JUMP");
  unk_1423FB778 = 1;
  UFG::qString::qString(&stru_1423FB780, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB7A8, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FB7B0, "$LEADERBOARD_CHALLENGES_CAR_JUMP_DESC");
  UFG::qString::qString(&stru_1423FB7D8, &customWorldMapCaption);
  unk_1423FB800 = "%.2f m";
  unk_1423FB808 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FB810, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FB820, "$LEADERBOARD_CHALLENGES_CAR_JUMP_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FB848, "Main");
  unk_1423FB850 = 31;
  unk_1423FB854 = 1;
  UFG::qString::qString(&stru_1423FB858, "StatGamesBikeJump");
  UFG::qSymbol::create_from_string(&stru_1423FB880, "StatGamesBikeJump");
  UFG::qString::qString(&stru_1423FB888, "$LEADERBOARD_CHALLENGES_BIKE_JUMP");
  unk_1423FB8B0 = 1;
  UFG::qString::qString(&stru_1423FB8B8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB8E0, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FB8E8, "$LEADERBOARD_CHALLENGES_BIKE_JUMP_DESC");
  UFG::qString::qString(&stru_1423FB910, &customWorldMapCaption);
  unk_1423FB938 = "%.2f m";
  _mm_store_si128((__m128i *)&unk_1423FB940, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FB950 = 500;
  unk_1423FB954 = 5000;
  UFG::qString::qString(&stru_1423FB958, "$LEADERBOARD_CHALLENGES_BIKE_JUMP_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FB980, "Main");
  unk_1423FB988 = 32;
  unk_1423FB98C = 4;
  UFG::qString::qString(&stru_1423FB990, "StatGamesWheelieDistance");
  UFG::qSymbol::create_from_string(&stru_1423FB9B8, "StatGamesWheelieDistance");
  UFG::qString::qString(&stru_1423FB9C0, "$LEADERBOARD_CHALLENGES_WHEELIE_DISTANCE");
  unk_1423FB9E8 = 1;
  UFG::qString::qString(&stru_1423FB9F0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FBA18, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FBA20, "$LEADERBOARD_CHALLENGES_WHEELIE_DISTANCE_DESC");
  UFG::qString::qString(&stru_1423FBA48, &customWorldMapCaption);
  unk_1423FBA70 = "%.1f s";
  unk_1423FBA78 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FBA80, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FBA90, "$LEADERBOARD_CHALLENGES_WHEELIE_DISTANCE_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FBAB8, "Main");
  unk_1423FBAC0 = 33;
  unk_1423FBAC4 = 5;
  UFG::qString::qString(&stru_1423FBAC8, "StatGamesLongestCarMaxSpeed");
  UFG::qSymbol::create_from_string(&stru_1423FBAF0, "StatGamesLongestCarMaxSpeed");
  UFG::qString::qString(&stru_1423FBAF8, "$LEADERBOARD_CHALLENGES_LONGEST_CAR_MAX_SPEED");
  unk_1423FBB20 = 1;
  UFG::qString::qString(&stru_1423FBB28, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FBB50, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FBB58, "$LEADERBOARD_CHALLENGES_LONGEST_CAR_MAX_SPEED_DESC");
  UFG::qString::qString(&stru_1423FBB80, &customWorldMapCaption);
  unk_1423FBBA8 = "%.1f s";
  _mm_store_si128((__m128i *)&unk_1423FBBB0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FBBC0 = 500;
  unk_1423FBBC4 = 3000;
  UFG::qString::qString(&stru_1423FBBC8, "$LEADERBOARD_CHALLENGES_LONGEST_CAR_MAX_SPEED_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FBBF0, "Main");
  unk_1423FBBF8 = 34;
  unk_1423FBBFC = 6;
  UFG::qString::qString(&stru_1423FBC00, "StatGamesVehicleTakedownStreak");
  UFG::qSymbol::create_from_string(&stru_1423FBC28, "StatGamesVehicleTakedownStreak");
  UFG::qString::qString(&stru_1423FBC30, "$LEADERBOARD_CHALLENGES_VEHICLE_TAKE_DOWN_STREAK");
  unk_1423FBC58 = 1;
  UFG::qString::qString(&stru_1423FBC60, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FBC88, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FBC90, "$LEADERBOARD_CHALLENGES_VEHICLE_TAKE_DOWN_STREAK_DESC");
  UFG::qString::qString(&stru_1423FBCB8, &customWorldMapCaption);
  unk_1423FBCE0 = "%d";
  unk_1423FBCE8 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FBCF0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FBD00, "$LEADERBOARD_CHALLENGES_VEHICLE_TAKE_DOWN_STREAK_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FBD28, "Main");
  unk_1423FBD30 = 35;
  unk_1423FBD34 = 7;
  UFG::qString::qString(&stru_1423FBD38, "StatGamesLongestNoDamageDriving");
  UFG::qSymbol::create_from_string(&stru_1423FBD60, "StatGamesLongestNoDamageDriving");
  UFG::qString::qString(&stru_1423FBD68, "$LEADERBOARD_CHALLENGES_LONGEST_NO_DAMAGE_DRIVING");
  unk_1423FBD90 = 1;
  UFG::qString::qString(&stru_1423FBD98, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FBDC0, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FBDC8, "$LEADERBOARD_CHALLENGES_LONGEST_NO_DAMAGE_DRIVING_DESC");
  UFG::qString::qString(&stru_1423FBDF0, &customWorldMapCaption);
  unk_1423FBE18 = "%.1f s";
  _mm_store_si128((__m128i *)&unk_1423FBE20, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FBE30 = 500;
  unk_1423FBE34 = 5000;
  UFG::qString::qString(&stru_1423FBE38, "$LEADERBOARD_CHALLENGES_LONGEST_NO_DAMAGE_DRIVING_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FBE60, "Main");
  unk_1423FBE68 = 36;
  unk_1423FBE6C = 8;
  UFG::qString::qString(&stru_1423FBE70, "StatGamesLongestHitAndRun");
  UFG::qSymbol::create_from_string(&stru_1423FBE98, "StatGamesLongestHitAndRun");
  UFG::qString::qString(&stru_1423FBEA0, "$LEADERBOARD_CHALLENGES_LONGEST_HIT_AND_RUN");
  unk_1423FBEC8 = 1;
  UFG::qString::qString(&stru_1423FBED0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FBEF8, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FBF00, "$LEADERBOARD_CHALLENGES_LONGEST_HIT_AND_RUN_DESC");
  UFG::qString::qString(&stru_1423FBF28, &customWorldMapCaption);
  unk_1423FBF50 = "%d";
  unk_1423FBF58 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FBF60, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FBF70, "$LEADERBOARD_CHALLENGES_LONGEST_HIT_AND_RUN_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FBF98, "Main");
  unk_1423FBFA0 = 37;
  unk_1423FBFA4 = 9;
  UFG::qString::qString(&stru_1423FBFA8, "StatGamesCoinsCollected");
  UFG::qSymbol::create_from_string(&stru_1423FBFD0, "StatGamesCoinsCollected");
  UFG::qString::qString(&stru_1423FBFD8, "$LEADERBOARD_CHALLENGES_COINS_COLLECTED");
  unk_1423FC000 = 1;
  UFG::qString::qString(&stru_1423FC008, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC030, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FC038, "$LEADERBOARD_CHALLENGES_COINS_COLLECTED_DESC");
  UFG::qString::qString(&stru_1423FC060, &customWorldMapCaption);
  unk_1423FC088 = "HK $ %d";
  _mm_store_si128((__m128i *)&unk_1423FC090, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FC0A0 = 6000;
  unk_1423FC0A4 = 200;
  UFG::qString::qString(&stru_1423FC0A8, "$LEADERBOARD_CHALLENGES_COINS_COLLECTED_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FC0D0, "Main");
  unk_1423FC0D8 = 38;
  unk_1423FC0DC = 10;
  UFG::qString::qString(&stru_1423FC0E0, "StatGamesLongestChase");
  UFG::qSymbol::create_from_string(&stru_1423FC108, "StatGamesLongestChase");
  UFG::qString::qString(&stru_1423FC110, "$LEADERBOARD_CHALLENGES_LONGEST_CHASE");
  unk_1423FC138 = 1;
  UFG::qString::qString(&stru_1423FC140, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC168, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FC170, "$LEADERBOARD_CHALLENGES_LONGEST_CHASE_DESC");
  UFG::qString::qString(&stru_1423FC198, &customWorldMapCaption);
  unk_1423FC1C0 = "%.1f s";
  unk_1423FC1C8 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FC1D0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FC1E0, "$LEADERBOARD_CHALLENGES_LONGEST_CHASE_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FC208, "Main");
  unk_1423FC210 = 39;
  unk_1423FC214 = 11;
  UFG::qString::qString(&stru_1423FC218, "StatGamesKillStreak");
  UFG::qSymbol::create_from_string(&stru_1423FC240, "StatGamesKillStreak");
  UFG::qString::qString(&stru_1423FC248, "$LEADERBOARD_CHALLENGES_KILL_STREAK");
  unk_1423FC270 = 1;
  UFG::qString::qString(&stru_1423FC278, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC2A0, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FC2A8, "$LEADERBOARD_CHALLENGES_KILL_STREAK_DESC");
  UFG::qString::qString(&stru_1423FC2D0, &customWorldMapCaption);
  unk_1423FC2F8 = "%d";
  _mm_store_si128((__m128i *)&unk_1423FC300, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FC310 = 8000;
  unk_1423FC314 = 3;
  UFG::qString::qString(&stru_1423FC318, "$LEADERBOARD_CHALLENGES_KILL_STREAK_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FC340, "Main");
  unk_1423FC348 = 40;
  unk_1423FC34C = 12;
  UFG::qString::qString(&stru_1423FC350, "StatGamesTackles");
  UFG::qSymbol::create_from_string(&stru_1423FC378, "StatGamesTackles");
  UFG::qString::qString(&stru_1423FC380, "$LEADERBOARD_CHALLENGES_TACKLES");
  unk_1423FC3A8 = 1;
  UFG::qString::qString(&stru_1423FC3B0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC3D8, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FC3E0, "$LEADERBOARD_CHALLENGES_TACKLES_DESC");
  UFG::qString::qString(&stru_1423FC408, &customWorldMapCaption);
  unk_1423FC430 = "%d";
  unk_1423FC438 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FC440, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FC450, "$LEADERBOARD_CHALLENGES_TACKLES_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FC478, "Main");
  unk_1423FC480 = 41;
  unk_1423FC484 = 13;
  UFG::qString::qString(&stru_1423FC488, "StatGamesFlyingKicks");
  UFG::qSymbol::create_from_string(&stru_1423FC4B0, "StatGamesFlyingKicks");
  UFG::qString::qString(&stru_1423FC4B8, "$LEADERBOARD_CHALLENGES_FLYING_JUMP_KICKS");
  unk_1423FC4E0 = 1;
  UFG::qString::qString(&stru_1423FC4E8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC510, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FC518, "$LEADERBOARD_CHALLENGES_FLYING_JUMP_KICKS_DESC");
  UFG::qString::qString(&stru_1423FC540, &customWorldMapCaption);
  unk_1423FC568 = "%d";
  _mm_store_si128((__m128i *)&unk_1423FC570, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FC580 = 10000;
  unk_1423FC584 = 2;
  UFG::qString::qString(&stru_1423FC588, "$LEADERBOARD_CHALLENGES_FLYING_JUMP_KICKS_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FC5B0, "Main");
  unk_1423FC5B8 = 42;
  unk_1423FC5BC = 14;
  UFG::qString::qString(&stru_1423FC5C0, "StatGamesHeadShots");
  UFG::qSymbol::create_from_string(&stru_1423FC5E8, "StatGamesHeadShots");
  UFG::qString::qString(&stru_1423FC5F0, "$LEADERBOARD_CHALLENGES_HEADSHOTS");
  unk_1423FC618 = 1;
  UFG::qString::qString(&stru_1423FC620, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC648, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FC650, "$LEADERBOARD_CHALLENGES_HEADSHOTS_DESC");
  UFG::qString::qString(&stru_1423FC678, &customWorldMapCaption);
  unk_1423FC6A0 = "%d";
  unk_1423FC6A8 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FC6B0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FC6C0, "$LEADERBOARD_CHALLENGES_HEADSHOTS_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FC6E8, "Main");
  unk_1423FC6F0 = 43;
  unk_1423FC6F4 = 15;
  UFG::qString::qString(&stru_1423FC6F8, "StatGamesTireShots");
  UFG::qSymbol::create_from_string(&stru_1423FC720, "StatGamesTireShots");
  UFG::qString::qString(&stru_1423FC728, "$LEADERBOARD_CHALLENGES_TIRESHOTS");
  unk_1423FC750 = 1;
  UFG::qString::qString(&stru_1423FC758, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC780, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FC788, "$LEADERBOARD_CHALLENGES_TIRESHOTS_DESC");
  UFG::qString::qString(&stru_1423FC7B0, &customWorldMapCaption);
  unk_1423FC7D8 = "%d";
  _mm_store_si128((__m128i *)&unk_1423FC7E0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FC7F0 = 10000;
  unk_1423FC7F4 = 2;
  UFG::qString::qString(&stru_1423FC7F8, "$LEADERBOARD_CHALLENGES_TIRESHOTS_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FC820, "Main");
  unk_1423FC828 = 44;
  unk_1423FC82C = 16;
  UFG::qString::qString(&stru_1423FC830, "StatGamesCopsKilled");
  UFG::qSymbol::create_from_string(&stru_1423FC858, "StatGamesCopsKilled");
  UFG::qString::qString(&stru_1423FC860, "$LEADERBOARD_CHALLENGES_COPS_KILLED");
  unk_1423FC888 = 1;
  UFG::qString::qString(&stru_1423FC890, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC8B8, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FC8C0, "$LEADERBOARD_CHALLENGES_COPS_KILLED_DESC");
  UFG::qString::qString(&stru_1423FC8E8, &customWorldMapCaption);
  unk_1423FC910 = "%d";
  unk_1423FC918 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FC920, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FC930, "$LEADERBOARD_CHALLENGES_COPS_KILLED_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FC958, "Main");
  unk_1423FC960 = 110;
  unk_1423FC964 = 17;
  UFG::qString::qString(&stru_1423FC968, "StatGamesJiangShiDefeatedStreak");
  UFG::qSymbol::create_from_string(&stru_1423FC990, "StatGamesJiangShiDefeatedStreak");
  UFG::qString::qString(&stru_1423FC998, "$LEADERBOARD_CHALLENGES_JIANG_SHI_DEFEATED_STREAK");
  unk_1423FC9C0 = 1;
  UFG::qString::qString(&stru_1423FC9C8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC9F0, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FC9F8, "$LEADERBOARD_CHALLENGES_JIANG_SHI_DEFEATED_STREAK_DESC");
  UFG::qString::qString(&stru_1423FCA20, &customWorldMapCaption);
  unk_1423FCA48 = "%d";
  _mm_store_si128((__m128i *)&unk_1423FCA50, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FCA60 = 15000;
  unk_1423FCA64 = 3;
  UFG::qString::qString(&stru_1423FCA68, "$LEADERBOARD_CHALLENGES_JIANG_SHI_DEFEATED_STREAK_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FCA90, "DLC_Ghost");
  unk_1423FCA98 = 111;
  unk_1423FCA9C = 18;
  UFG::qString::qString(&stru_1423FCAA0, "StatGamesEnemiesOnFire");
  UFG::qSymbol::create_from_string(&stru_1423FCAC8, "StatGamesEnemiesOnFire");
  UFG::qString::qString(&stru_1423FCAD0, "$LEADERBOARD_CHALLENGES_ENEMIES_ON_FIRE");
  unk_1423FCAF8 = 1;
  UFG::qString::qString(&stru_1423FCB00, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FCB28, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FCB30, "$LEADERBOARD_CHALLENGES_ENEMIES_ON_FIRE_DESC");
  UFG::qString::qString(&stru_1423FCB58, &customWorldMapCaption);
  unk_1423FCB80 = "%d";
  unk_1423FCB88 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FCB90, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FCBA0, "$LEADERBOARD_CHALLENGES_ENEMIES_ON_FIRE_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FCBC8, "DLC_Ghost");
  unk_1423FCBD0 = 112;
  unk_1423FCBD4 = 19;
  UFG::qString::qString(&stru_1423FCBD8, "StatGamesPossessedPedsKilled");
  UFG::qSymbol::create_from_string(&stru_1423FCC00, "StatGamesPossessedPedsKilled");
  UFG::qString::qString(&stru_1423FCC08, "$LEADERBOARD_CHALLENGES_POSSESSED_PEDS_KILLED");
  unk_1423FCC30 = 1;
  UFG::qString::qString(&stru_1423FCC38, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FCC60, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FCC68, "$LEADERBOARD_CHALLENGES_POSSESSED_PEDS_KILLED_DESC");
  UFG::qString::qString(&stru_1423FCC90, &customWorldMapCaption);
  unk_1423FCCB8 = "%d";
  _mm_store_si128((__m128i *)&unk_1423FCCC0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FCCD0 = 15000;
  unk_1423FCCD4 = 3;
  UFG::qString::qString(&stru_1423FCCD8, "$LEADERBOARD_CHALLENGES_POSSESSED_PEDS_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FCD00, "DLC_Ghost");
  unk_1423FCD08 = 113;
  unk_1423FCD0C = 20;
  UFG::qString::qString(&stru_1423FCD10, "StatGamesLongestNotBitten");
  UFG::qSymbol::create_from_string(&stru_1423FCD38, "StatGamesLongestNotBitten");
  UFG::qString::qString(&stru_1423FCD40, "$LEADERBOARD_CHALLENGES_LONGEST_NOT_BITTEN");
  unk_1423FCD68 = 1;
  UFG::qString::qString(&stru_1423FCD70, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FCD98, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FCDA0, "$LEADERBOARD_CHALLENGES_LONGEST_NOT_BITTEN_DESC");
  UFG::qString::qString(&stru_1423FCDC8, &customWorldMapCaption);
  unk_1423FCDF0 = "%.1f s";
  unk_1423FCDF8 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FCE00, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FCE10, "$LEADERBOARD_CHALLENGES_LONGEST_NOT_BITTEN_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FCE38, "DLC_Ghost");
  unk_1423FCE40 = 114;
  unk_1423FCE44 = 21;
  UFG::qString::qString(&stru_1423FCE48, "StatGamesJiangShiRunOver");
  UFG::qSymbol::create_from_string(&stru_1423FCE70, "StatGamesJiangShiRunOver");
  UFG::qString::qString(&stru_1423FCE78, "$LEADERBOARD_CHALLENGES_JIANG_SHI_RUN_OVER");
  unk_1423FCEA0 = 1;
  UFG::qString::qString(&stru_1423FCEA8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FCED0, &customWorldMapCaption);
  UFG::qString::qString(&stru_1423FCED8, "$LEADERBOARD_CHALLENGES_JIANG_SHI_RUN_OVER_DESC");
  UFG::qString::qString(&stru_1423FCF00, &customWorldMapCaption);
  unk_1423FCF28 = "%d";
  _mm_store_si128((__m128i *)&unk_1423FCF30, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FCF40 = 15000;
  unk_1423FCF44 = 3;
  UFG::qString::qString(&stru_1423FCF48, "$LEADERBOARD_CHALLENGES_JIANG_SHI_RUN_OVER_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FCF70, "DLC_Ghost");
  unk_1423FCF78 = 45i64;
  UFG::qString::qString(&stru_1423FCF80, "MissionsVendorExtortion");
  UFG::qSymbol::create_from_string(&stru_1423FCFA8, "MissionsVendorExtortion");
  UFG::qString::qString(&stru_1423FCFB0, "$SGTITLE_VENDOR_EXTORTION");
  unk_1423FCFD8 = 2;
  UFG::qString::qString(&stru_1423FCFE0, "M_VE");
  UFG::qSymbol::create_from_string(&stru_1423FD008, "M_VE");
  UFG::qString::qString(&stru_1423FD010, "$LEADERBOARD_MISSIONS_VENDOR_EXTORTION_DESC");
  UFG::qString::qString(&stru_1423FD038, "SocialHub_Mission_VendorExtortion");
  unk_1423FD060 = "Int32";
  unk_1423FD068 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FD070, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FD080, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FD0A8, "Main");
  unk_1423FD0B0 = 46;
  unk_1423FD0B4 = 1;
  UFG::qString::qString(&stru_1423FD0B8, "MissionsNightMarketChase");
  UFG::qSymbol::create_from_string(&stru_1423FD0E0, "MissionsNightMarketChase");
  UFG::qString::qString(&stru_1423FD0E8, "$SGTITLE_NIGHT_MARKET_CHASE");
  unk_1423FD110 = 2;
  UFG::qString::qString(&stru_1423FD118, "M_NMC");
  UFG::qSymbol::create_from_string(&stru_1423FD140, "M_NMC");
  UFG::qString::qString(&stru_1423FD148, "$LEADERBOARD_MISSIONS_NIGHT_MARKET_CHASE_DESC");
  UFG::qString::qString(&stru_1423FD170, "SocialHub_Mission_NightMarketChase");
  unk_1423FD198 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FD1A0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FD1B0 = 0i64;
  UFG::qString::qString(&stru_1423FD1B8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FD1E0, "Main");
  unk_1423FD1E8 = 47;
  unk_1423FD1EC = 2;
  UFG::qString::qString(&stru_1423FD1F0, "MissionsStickupDelivery");
  UFG::qSymbol::create_from_string(&stru_1423FD218, "MissionsStickupDelivery");
  UFG::qString::qString(&stru_1423FD220, "$SGTITLE_STICK_UPANDDELIVERY");
  unk_1423FD248 = 2;
  UFG::qString::qString(&stru_1423FD250, "M_SU");
  UFG::qSymbol::create_from_string(&stru_1423FD278, "M_SU");
  UFG::qString::qString(&stru_1423FD280, "$LEADERBOARD_MISSIONS_STICKUP_DELIVERY_DESC");
  UFG::qString::qString(&stru_1423FD2A8, "SocialHub_Mission_Stickup");
  unk_1423FD2D0 = "Int32";
  unk_1423FD2D8 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FD2E0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FD2F0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FD318, "Main");
  unk_1423FD320 = 48;
  unk_1423FD324 = 3;
  UFG::qString::qString(&stru_1423FD328, "MissionsMinibus");
  UFG::qSymbol::create_from_string(&stru_1423FD350, "MissionsMinibus");
  UFG::qString::qString(&stru_1423FD358, "$SGTITLE_MINI_BUS");
  unk_1423FD380 = 2;
  UFG::qString::qString(&stru_1423FD388, "M_MB");
  UFG::qSymbol::create_from_string(&stru_1423FD3B0, "M_MB");
  UFG::qString::qString(&stru_1423FD3B8, "$LEADERBOARD_MISSIONS_MINI_BUS_DESC");
  UFG::qString::qString(&stru_1423FD3E0, "SocialHub_Mission_Minibus");
  unk_1423FD408 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FD410, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FD420 = 0i64;
  UFG::qString::qString(&stru_1423FD428, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FD450, "Main");
  unk_1423FD458 = 49;
  unk_1423FD45C = 5;
  UFG::qString::qString(&stru_1423FD460, "MissionsBamBam");
  UFG::qSymbol::create_from_string(&stru_1423FD488, "MissionsBamBam");
  UFG::qString::qString(&stru_1423FD490, "$SGTITLE_BAM_BAM_CLUB");
  unk_1423FD4B8 = 2;
  UFG::qString::qString(&stru_1423FD4C0, "M_BBC");
  UFG::qSymbol::create_from_string(&stru_1423FD4E8, "M_BBC");
  UFG::qString::qString(&stru_1423FD4F0, "$LEADERBOARD_MISSIONS_BAM_BAM_DESC");
  UFG::qString::qString(&stru_1423FD518, "SocialHub_Mission_BamBamClub");
  unk_1423FD540 = "Int32";
  unk_1423FD548 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FD550, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FD560, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FD588, "Main");
  unk_1423FD590 = 50;
  unk_1423FD594 = 6;
  UFG::qString::qString(&stru_1423FD598, "MissionsPendrewBugs");
  UFG::qSymbol::create_from_string(&stru_1423FD5C0, "MissionsPendrewBugs");
  UFG::qString::qString(&stru_1423FD5C8, "$SGTITLE_PENDREWS_BUGS");
  unk_1423FD5F0 = 2;
  UFG::qString::qString(&stru_1423FD5F8, "M_PB");
  UFG::qSymbol::create_from_string(&stru_1423FD620, "M_PB");
  UFG::qString::qString(&stru_1423FD628, "$LEADERBOARD_MISSIONS_PENDREW_BUGS_DESC");
  UFG::qString::qString(&stru_1423FD650, "SocialHub_Mission_PendrewsBugs");
  unk_1423FD678 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FD680, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FD690 = 0i64;
  UFG::qString::qString(&stru_1423FD698, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FD6C0, "Main");
  unk_1423FD6C8 = 51;
  unk_1423FD6CC = 7;
  UFG::qString::qString(&stru_1423FD6D0, "MissionsTiffanyGun");
  UFG::qSymbol::create_from_string(&stru_1423FD6F8, "MissionsTiffanyGun");
  UFG::qString::qString(&stru_1423FD700, "$SGTITLE_TIFFANYS_GUN");
  unk_1423FD728 = 2;
  UFG::qString::qString(&stru_1423FD730, "M_TG");
  UFG::qSymbol::create_from_string(&stru_1423FD758, "M_TG");
  UFG::qString::qString(&stru_1423FD760, "$LEADERBOARD_MISSIONS_TIFFANY_GUN_DESC");
  UFG::qString::qString(&stru_1423FD788, "SocialHub_Mission_TiffanysGun");
  unk_1423FD7B0 = "Int32";
  unk_1423FD7B8 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FD7C0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FD7D0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FD7F8, "Main");
  unk_1423FD800 = 52;
  unk_1423FD804 = 8;
  UFG::qString::qString(&stru_1423FD808, "MissionsSweatshop");
  UFG::qSymbol::create_from_string(&stru_1423FD830, "MissionsSweatshop");
  UFG::qString::qString(&stru_1423FD838, "$SGTITLE_SWEATSHOP");
  unk_1423FD860 = 2;
  UFG::qString::qString(&stru_1423FD868, "M_SS");
  UFG::qSymbol::create_from_string(&stru_1423FD890, "M_SS");
  UFG::qString::qString(&stru_1423FD898, "$LEADERBOARD_MISSIONS_SWEATSHOP_DESC");
  UFG::qString::qString(&stru_1423FD8C0, "SocialHub_Mission_Sweatshop");
  unk_1423FD8E8 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FD8F0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FD900 = 0i64;
  UFG::qString::qString(&stru_1423FD908, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FD930, "Main");
  unk_1423FD938 = 53;
  unk_1423FD93C = 9;
  UFG::qString::qString(&stru_1423FD940, "MissionsUnclePo");
  UFG::qSymbol::create_from_string(&stru_1423FD968, "MissionsUnclePo");
  UFG::qString::qString(&stru_1423FD970, "$SGTITLE_UNCLE_PO");
  unk_1423FD998 = 2;
  UFG::qString::qString(&stru_1423FD9A0, "M_UP");
  UFG::qSymbol::create_from_string(&stru_1423FD9C8, "M_UP");
  UFG::qString::qString(&stru_1423FD9D0, "$LEADERBOARD_MISSIONS_UNCLE_PO_DESC");
  UFG::qString::qString(&stru_1423FD9F8, "SocialHub_Mission_UnclePo");
  unk_1423FDA20 = "Int32";
  unk_1423FDA28 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FDA30, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FDA40, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FDA68, "Main");
  unk_1423FDA70 = 54;
  unk_1423FDA74 = 10;
  UFG::qString::qString(&stru_1423FDA78, "MissionsBridetoBe");
  UFG::qSymbol::create_from_string(&stru_1423FDAA0, "MissionsBridetoBe");
  UFG::qString::qString(&stru_1423FDAA8, "$SGTITLE_BRIDE_TO_BE");
  unk_1423FDAD0 = 2;
  UFG::qString::qString(&stru_1423FDAD8, "M_BTB");
  UFG::qSymbol::create_from_string(&stru_1423FDB00, "M_BTB");
  UFG::qString::qString(&stru_1423FDB08, "$LEADERBOARD_MISSIONS_BRIDE_TO_BE_DESC");
  UFG::qString::qString(&stru_1423FDB30, "SocialHub_Mission_BridetoBe");
  unk_1423FDB58 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FDB60, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FDB70 = 0i64;
  UFG::qString::qString(&stru_1423FDB78, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FDBA0, "Main");
  unk_1423FDBA8 = 55;
  unk_1423FDBAC = 12;
  UFG::qString::qString(&stru_1423FDBB0, "MissionsWedding");
  UFG::qSymbol::create_from_string(&stru_1423FDBD8, "MissionsWedding");
  UFG::qString::qString(&stru_1423FDBE0, "$SGTITLE_WEDDING");
  unk_1423FDC08 = 2;
  UFG::qString::qString(&stru_1423FDC10, "M_WED");
  UFG::qSymbol::create_from_string(&stru_1423FDC38, "M_WED");
  UFG::qString::qString(&stru_1423FDC40, "$LEADERBOARD_MISSIONS_WEDDING_DESC");
  UFG::qString::qString(&stru_1423FDC68, "SocialHub_Mission_Wedding");
  unk_1423FDC90 = "Int32";
  unk_1423FDC98 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FDCA0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FDCB0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FDCD8, "Main");
  unk_1423FDCE0 = 56;
  unk_1423FDCE4 = 13;
  UFG::qString::qString(&stru_1423FDCE8, "MissionsMrsChuRevenge");
  UFG::qSymbol::create_from_string(&stru_1423FDD10, "MissionsMrsChuRevenge");
  UFG::qString::qString(&stru_1423FDD18, "$SGTITLE_MRS_CHUS_REVENGE");
  unk_1423FDD40 = 2;
  UFG::qString::qString(&stru_1423FDD48, "M_MCR");
  UFG::qSymbol::create_from_string(&stru_1423FDD70, "M_MCR");
  UFG::qString::qString(&stru_1423FDD78, "$LEADERBOARD_MISSIONS_MRS_CHU_REVENGE_DESC");
  UFG::qString::qString(&stru_1423FDDA0, "SocialHub_Mission_MrsChusRevenge");
  unk_1423FDDC8 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FDDD0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FDDE0 = 0i64;
  UFG::qString::qString(&stru_1423FDDE8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FDE10, "Main");
  unk_1423FDE18 = 57;
  unk_1423FDE1C = 14;
  UFG::qString::qString(&stru_1423FDE20, "MissionsTheNewBoss");
  UFG::qSymbol::create_from_string(&stru_1423FDE48, "MissionsTheNewBoss");
  UFG::qString::qString(&stru_1423FDE50, "$SGTITLE_THE_NEW_BOSS");
  unk_1423FDE78 = 2;
  UFG::qString::qString(&stru_1423FDE80, "M_TNB");
  UFG::qSymbol::create_from_string(&stru_1423FDEA8, "M_TNB");
  UFG::qString::qString(&stru_1423FDEB0, "$LEADERBOARD_MISSIONS_THE_NEW_BOSS_DESC");
  UFG::qString::qString(&stru_1423FDED8, "SocialHub_Mission_TheNewBoss");
  unk_1423FDF00 = "Int32";
  unk_1423FDF08 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FDF10, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FDF20, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FDF48, "Main");
  unk_1423FDF50 = 58;
  unk_1423FDF54 = 16;
  UFG::qString::qString(&stru_1423FDF58, "MissionsTopGlamour");
  UFG::qSymbol::create_from_string(&stru_1423FDF80, "MissionsTopGlamour");
  UFG::qString::qString(&stru_1423FDF88, "$SGTITLE_TOP_GLAMOUR_AMBUSH");
  unk_1423FDFB0 = 2;
  UFG::qString::qString(&stru_1423FDFB8, "M_TGA");
  UFG::qSymbol::create_from_string(&stru_1423FDFE0, "M_TGA");
  UFG::qString::qString(&stru_1423FDFE8, "$LEADERBOARD_MISSIONS_TOP_GLAMOUR_DESC");
  UFG::qString::qString(&stru_1423FE010, "SocialHub_Mission_TopGlamour");
  unk_1423FE038 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FE040, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FE050 = 0i64;
  UFG::qString::qString(&stru_1423FE058, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FE080, "Main");
  unk_1423FE088 = 59;
  unk_1423FE08C = 17;
  UFG::qString::qString(&stru_1423FE090, "MissionsFinalKill");
  UFG::qSymbol::create_from_string(&stru_1423FE0B8, "MissionsFinalKill");
  UFG::qString::qString(&stru_1423FE0C0, "$SGTITLE_FINAL_KILL");
  unk_1423FE0E8 = 2;
  UFG::qString::qString(&stru_1423FE0F0, "M_FK");
  UFG::qSymbol::create_from_string(&stru_1423FE118, "M_FK");
  UFG::qString::qString(&stru_1423FE120, "$LEADERBOARD_MISSIONS_FINAL_KILL_DESC");
  UFG::qString::qString(&stru_1423FE148, "SocialHub_Mission_FinalKill");
  unk_1423FE170 = "Int32";
  unk_1423FE178 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FE180, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FE190, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FE1B8, "Main");
  unk_1423FE1C0 = 60;
  unk_1423FE1C4 = 18;
  UFG::qString::qString(&stru_1423FE1C8, "MissionsInitiation");
  UFG::qSymbol::create_from_string(&stru_1423FE1F0, "MissionsInitiation");
  UFG::qString::qString(&stru_1423FE1F8, "$SGTITLE_INITIATION");
  unk_1423FE220 = 2;
  UFG::qString::qString(&stru_1423FE228, "M_IN");
  UFG::qSymbol::create_from_string(&stru_1423FE250, "M_IN");
  UFG::qString::qString(&stru_1423FE258, "$LEADERBOARD_MISSIONS_INITIATION_DESC");
  UFG::qString::qString(&stru_1423FE280, "SocialHub_Mission_Initiation");
  unk_1423FE2A8 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FE2B0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FE2C0 = 0i64;
  UFG::qString::qString(&stru_1423FE2C8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FE2F0, "Main");
  unk_1423FE2F8 = 61;
  unk_1423FE2FC = 19;
  UFG::qString::qString(&stru_1423FE300, "MissionsJackieArrested");
  UFG::qSymbol::create_from_string(&stru_1423FE328, "MissionsJackieArrested");
  UFG::qString::qString(&stru_1423FE330, "$SGTITLE_JACKIE_ARRESTED");
  unk_1423FE358 = 2;
  UFG::qString::qString(&stru_1423FE360, "M_JA");
  UFG::qSymbol::create_from_string(&stru_1423FE388, "M_JA");
  UFG::qString::qString(&stru_1423FE390, "$LEADERBOARD_MISSIONS_JACKIE_ARRESTED_DESC");
  UFG::qString::qString(&stru_1423FE3B8, "SocialHub_Mission_JackieArrested");
  unk_1423FE3E0 = "Int32";
  unk_1423FE3E8 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FE3F0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FE400, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FE428, "Main");
  unk_1423FE430 = 62;
  unk_1423FE434 = 20;
  UFG::qString::qString(&stru_1423FE438, "MissionsTheBossesMeet");
  UFG::qSymbol::create_from_string(&stru_1423FE460, "MissionsTheBossesMeet");
  UFG::qString::qString(&stru_1423FE468, "$SGTITLE_HOSPITAL_SHOOTOUT");
  unk_1423FE490 = 2;
  UFG::qString::qString(&stru_1423FE498, "M_HS");
  UFG::qSymbol::create_from_string(&stru_1423FE4C0, "M_HS");
  UFG::qString::qString(&stru_1423FE4C8, "$LEADERBOARD_MISSIONS_THE_BOSSES_MEET_DESC");
  UFG::qString::qString(&stru_1423FE4F0, "SocialHub_Mission_TheBossesMeet");
  unk_1423FE518 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FE520, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FE530 = 0i64;
  UFG::qString::qString(&stru_1423FE538, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FE560, "Main");
  unk_1423FE568 = 63;
  unk_1423FE56C = 11;
  UFG::qString::qString(&stru_1423FE570, "MissionsImportantVisitor");
  UFG::qSymbol::create_from_string(&stru_1423FE598, "MissionsImportantVisitor");
  UFG::qString::qString(&stru_1423FE5A0, "$SGTITLE_IMPORTANT_VISITOR");
  unk_1423FE5C8 = 2;
  UFG::qString::qString(&stru_1423FE5D0, "M_IV");
  UFG::qSymbol::create_from_string(&stru_1423FE5F8, "M_IV");
  UFG::qString::qString(&stru_1423FE600, "$LEADERBOARD_MISSIONS_IMPORTANT_VISITOR_DESC");
  UFG::qString::qString(&stru_1423FE628, "SocialHub_Mission_ImportantVisitor");
  unk_1423FE650 = "Int32";
  unk_1423FE658 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FE660, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FE670, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FE698, "Main");
  unk_1423FE6A0 = 64;
  unk_1423FE6A4 = 22;
  UFG::qString::qString(&stru_1423FE6A8, "MissionsFastGirls");
  UFG::qSymbol::create_from_string(&stru_1423FE6D0, "MissionsFastGirls");
  UFG::qString::qString(&stru_1423FE6D8, "$SGTITLE_FAST_GIRLS");
  unk_1423FE700 = 2;
  UFG::qString::qString(&stru_1423FE708, "M_FG");
  UFG::qSymbol::create_from_string(&stru_1423FE730, "M_FG");
  UFG::qString::qString(&stru_1423FE738, "$LEADERBOARD_MISSIONS_FAST_GIRLS_DESC");
  UFG::qString::qString(&stru_1423FE760, "SocialHub_Mission_FastGirls");
  unk_1423FE788 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FE790, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FE7A0 = 0i64;
  UFG::qString::qString(&stru_1423FE7A8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FE7D0, "Main");
  unk_1423FE7D8 = 65;
  unk_1423FE7DC = 21;
  UFG::qString::qString(&stru_1423FE7E0, "MissionsBadLuck");
  UFG::qSymbol::create_from_string(&stru_1423FE808, "MissionsBadLuck");
  UFG::qString::qString(&stru_1423FE810, "$SGTITLE_BAD_LUCK");
  unk_1423FE838 = 2;
  UFG::qString::qString(&stru_1423FE840, "M_BL");
  UFG::qSymbol::create_from_string(&stru_1423FE868, "M_BL");
  UFG::qString::qString(&stru_1423FE870, "$LEADERBOARD_MISSIONS_BAD_LUCK_DESC");
  UFG::qString::qString(&stru_1423FE898, "SocialHub_Mission_BadLuck");
  unk_1423FE8C0 = "Int32";
  unk_1423FE8C8 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FE8D0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FE8E0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FE908, "Main");
  unk_1423FE910 = 66;
  unk_1423FE914 = 23;
  UFG::qString::qString(&stru_1423FE918, "MissionsTheBigHit");
  UFG::qSymbol::create_from_string(&stru_1423FE940, "MissionsTheBigHit");
  UFG::qString::qString(&stru_1423FE948, "$SGTITLE_THE_BIG_HIT");
  unk_1423FE970 = 2;
  UFG::qString::qString(&stru_1423FE978, "M_TBH");
  UFG::qSymbol::create_from_string(&stru_1423FE9A0, "M_TBH");
  UFG::qString::qString(&stru_1423FE9A8, "$LEADERBOARD_MISSIONS_THE_BIG_HIT_DESC");
  UFG::qString::qString(&stru_1423FE9D0, "SocialHub_Mission_TheBigHit");
  unk_1423FE9F8 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FEA00, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FEA10 = 0i64;
  UFG::qString::qString(&stru_1423FEA18, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FEA40, "Main");
  unk_1423FEA48 = 67;
  unk_1423FEA4C = 24;
  UFG::qString::qString(&stru_1423FEA50, "MissionsTheFuneral");
  UFG::qSymbol::create_from_string(&stru_1423FEA78, "MissionsTheFuneral");
  UFG::qString::qString(&stru_1423FEA80, "$SGTITLE_THE_FUNERAL");
  unk_1423FEAA8 = 2;
  UFG::qString::qString(&stru_1423FEAB0, "M_FU");
  UFG::qSymbol::create_from_string(&stru_1423FEAD8, "M_FU");
  UFG::qString::qString(&stru_1423FEAE0, "$LEADERBOARD_MISSIONS_THE_FUNERAL_DESC");
  UFG::qString::qString(&stru_1423FEB08, "SocialHub_Mission_Funeral");
  unk_1423FEB30 = "Int32";
  unk_1423FEB38 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FEB40, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FEB50, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FEB78, "Main");
  unk_1423FEB80 = 68;
  unk_1423FEB84 = 25;
  UFG::qString::qString(&stru_1423FEB88, "MissionsCivilDiscord");
  UFG::qSymbol::create_from_string(&stru_1423FEBB0, "MissionsCivilDiscord");
  UFG::qString::qString(&stru_1423FEBB8, "$SGTITLE_CIVIL_DISCORD");
  unk_1423FEBE0 = 2;
  UFG::qString::qString(&stru_1423FEBE8, "M_CD");
  UFG::qSymbol::create_from_string(&stru_1423FEC10, "M_CD");
  UFG::qString::qString(&stru_1423FEC18, "$LEADERBOARD_MISSIONS_CIVIL_DISCORD_DESC");
  UFG::qString::qString(&stru_1423FEC40, "SocialHub_Mission_CivilDiscord");
  unk_1423FEC68 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FEC70, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FEC80 = 0i64;
  UFG::qString::qString(&stru_1423FEC88, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FECB0, "Main");
  unk_1423FECB8 = 69;
  unk_1423FECBC = 26;
  UFG::qString::qString(&stru_1423FECC0, "MissionsBuriedAlive");
  UFG::qSymbol::create_from_string(&stru_1423FECE8, "MissionsBuriedAlive");
  UFG::qString::qString(&stru_1423FECF0, "$SGTITLE_BURIED_ALIVE");
  unk_1423FED18 = 2;
  UFG::qString::qString(&stru_1423FED20, "M_BA");
  UFG::qSymbol::create_from_string(&stru_1423FED48, "M_BA");
  UFG::qString::qString(&stru_1423FED50, "$LEADERBOARD_MISSIONS_BURIED_ALIVE_DESC");
  UFG::qString::qString(&stru_1423FED78, "SocialHub_Mission_BuriedAlive");
  unk_1423FEDA0 = "Int32";
  unk_1423FEDA8 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FEDB0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FEDC0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FEDE8, "Main");
  unk_1423FEDF0 = 70;
  unk_1423FEDF4 = 27;
  UFG::qString::qString(&stru_1423FEDF8, "MissionsTheElection");
  UFG::qSymbol::create_from_string(&stru_1423FEE20, "MissionsTheElection");
  UFG::qString::qString(&stru_1423FEE28, "$SGTITLE_THE_ELECTION");
  unk_1423FEE50 = 2;
  UFG::qString::qString(&stru_1423FEE58, "M_TE");
  UFG::qSymbol::create_from_string(&stru_1423FEE80, "M_TE");
  UFG::qString::qString(&stru_1423FEE88, "$LEADERBOARD_MISSIONS_THE_ELECTION_DESC");
  UFG::qString::qString(&stru_1423FEEB0, "SocialHub_Mission_TheElection");
  unk_1423FEED8 = "Int32";
  _mm_store_si128((__m128i *)&unk_1423FEEE0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FEEF0 = 0i64;
  UFG::qString::qString(&stru_1423FEEF8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FEF20, "Main");
  unk_1423FEF28 = 71;
  unk_1423FEF2C = 15;
  UFG::qString::qString(&stru_1423FEF30, "MissionsBigSmileLee");
  UFG::qSymbol::create_from_string(&stru_1423FEF58, "MissionsBigSmileLee");
  UFG::qString::qString(&stru_1423FEF60, "$SGTITLE_BIG_SMILE_LEE");
  unk_1423FEF88 = 2;
  UFG::qString::qString(&stru_1423FEF90, "M_BSL");
  UFG::qSymbol::create_from_string(&stru_1423FEFB8, "M_BSL");
  UFG::qString::qString(&stru_1423FEFC0, "$LEADERBOARD_MISSIONS_BIG_SMILE_LEE_DESC");
  UFG::qString::qString(&stru_1423FEFE8, "SocialHub_Mission_BigSmileLee");
  unk_1423FF010 = "Int32";
  unk_1423FF018 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FF020, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FF030, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FF058, "Main");
  unk_1423FF060 = 72;
  unk_1423FF064 = 16;
  UFG::qString::qString(&stru_1423FF068, "RacesNP_04");
  UFG::qSymbol::create_from_string(&stru_1423FF090, "RacesNP_04");
  UFG::qString::qString(&stru_1423FF098, "$SGTITLE_RACE_HOTSHOT_LEAD_1");
  unk_1423FF0C0 = 3;
  UFG::qString::qString(&stru_1423FF0C8, "R_NP_04");
  UFG::qSymbol::create_from_string(&stru_1423FF0F0, "R_NP_04");
  UFG::qString::qString(&stru_1423FF0F8, "$LEADERBOARD_RACES_NP_04_DESC");
  UFG::qString::qString(&stru_1423FF120, "SocialHub_Race_Induction");
  unk_1423FF148 = "time";
  _mm_store_si128((__m128i *)&unk_1423FF150, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FF160 = 0i64;
  UFG::qString::qString(&stru_1423FF168, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FF190, "Main");
  unk_1423FF198 = 73i64;
  UFG::qString::qString(&stru_1423FF1A0, "RacesNP_03");
  UFG::qSymbol::create_from_string(&stru_1423FF1C8, "RacesNP_03");
  UFG::qString::qString(&stru_1423FF1D0, "$SGTITLE_RACE_HOTSHOT_LEAD_3");
  unk_1423FF1F8 = 3;
  UFG::qString::qString(&stru_1423FF200, "R_NP_03");
  UFG::qSymbol::create_from_string(&stru_1423FF228, "R_NP_03");
  UFG::qString::qString(&stru_1423FF230, "$LEADERBOARD_RACES_NP_03_DESC");
  UFG::qString::qString(&stru_1423FF258, "SocialHub_Race_Water_Street");
  unk_1423FF280 = "time";
  unk_1423FF288 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FF290, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FF2A0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FF2C8, "Main");
  unk_1423FF2D0 = 74;
  unk_1423FF2D4 = 7;
  UFG::qString::qString(&stru_1423FF2D8, "RacesNP_06");
  UFG::qSymbol::create_from_string(&stru_1423FF300, "RacesNP_06");
  UFG::qString::qString(&stru_1423FF308, "$SGTITLE_RACE_NORTH_POINT_06");
  unk_1423FF330 = 3;
  UFG::qString::qString(&stru_1423FF338, "R_NP_06");
  UFG::qSymbol::create_from_string(&stru_1423FF360, "R_NP_06");
  UFG::qString::qString(&stru_1423FF368, "$LEADERBOARD_RACES_NP_06_DESC");
  UFG::qString::qString(&stru_1423FF390, "SocialHub_Race_No_Sweat");
  unk_1423FF3B8 = "time";
  _mm_store_si128((__m128i *)&unk_1423FF3C0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FF3D0 = 0i64;
  UFG::qString::qString(&stru_1423FF3D8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FF400, "Main");
  unk_1423FF408 = 75;
  unk_1423FF40C = 4;
  UFG::qString::qString(&stru_1423FF410, "RacesCT_05");
  UFG::qSymbol::create_from_string(&stru_1423FF438, "RacesCT_05");
  UFG::qString::qString(&stru_1423FF440, "$SGTITLE_CENTRAL_05");
  unk_1423FF468 = 3;
  UFG::qString::qString(&stru_1423FF470, "R_CT_05");
  UFG::qSymbol::create_from_string(&stru_1423FF498, "R_CT_05");
  UFG::qString::qString(&stru_1423FF4A0, "$LEADERBOARD_RACES_CT_05_DESC");
  UFG::qString::qString(&stru_1423FF4C8, "SocialHub_Race_Mailman");
  unk_1423FF4F0 = "time";
  unk_1423FF4F8 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FF500, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FF510, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FF538, "Main");
  unk_1423FF540 = 76;
  unk_1423FF544 = 11;
  UFG::qString::qString(&stru_1423FF548, "RacesKT_02");
  UFG::qSymbol::create_from_string(&stru_1423FF570, "RacesKT_02");
  UFG::qString::qString(&stru_1423FF578, "$SGTITLE_RACE_KENNEDY_TOWN_02");
  unk_1423FF5A0 = 3;
  UFG::qString::qString(&stru_1423FF5A8, "R_KT_02");
  UFG::qSymbol::create_from_string(&stru_1423FF5D0, "R_KT_02");
  UFG::qString::qString(&stru_1423FF5D8, "$LEADERBOARD_RACES_KT_02_DESC");
  UFG::qString::qString(&stru_1423FF600, "SocialHub_Race_Dock_Yard");
  unk_1423FF628 = "time";
  _mm_store_si128((__m128i *)&unk_1423FF630, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FF640 = 0i64;
  UFG::qString::qString(&stru_1423FF648, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FF670, "Main");
  unk_1423FF678 = 77;
  unk_1423FF67C = 15;
  UFG::qString::qString(&stru_1423FF680, "RacesAB_04");
  UFG::qSymbol::create_from_string(&stru_1423FF6A8, "RacesAB_04");
  UFG::qString::qString(&stru_1423FF6B0, "$SGTITLE_RACE_ABERDEEN_04");
  unk_1423FF6D8 = 3;
  UFG::qString::qString(&stru_1423FF6E0, "R_AB_04");
  UFG::qSymbol::create_from_string(&stru_1423FF708, "R_AB_04");
  UFG::qString::qString(&stru_1423FF710, "$LEADERBOARD_RACES_AB_04_DESC");
  UFG::qString::qString(&stru_1423FF738, "SocialHub_Race_Indecision");
  unk_1423FF760 = "time";
  unk_1423FF768 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FF770, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FF780, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FF7A8, "Main");
  unk_1423FF7B0 = 78;
  unk_1423FF7B4 = 2;
  UFG::qString::qString(&stru_1423FF7B8, "RacesAB_02");
  UFG::qSymbol::create_from_string(&stru_1423FF7E0, "RacesAB_02");
  UFG::qString::qString(&stru_1423FF7E8, "$SGTITLE_RACE_ABERDEEN_02");
  unk_1423FF810 = 3;
  UFG::qString::qString(&stru_1423FF818, "R_AB_02");
  UFG::qSymbol::create_from_string(&stru_1423FF840, "R_AB_02");
  UFG::qString::qString(&stru_1423FF848, "$LEADERBOARD_RACES_AB_02_DESC");
  UFG::qString::qString(&stru_1423FF870, "SocialHub_Race_Lost");
  unk_1423FF898 = "time";
  _mm_store_si128((__m128i *)&unk_1423FF8A0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FF8B0 = 0i64;
  UFG::qString::qString(&stru_1423FF8B8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FF8E0, "Main");
  unk_1423FF8E8 = 79;
  unk_1423FF8EC = 6;
  UFG::qString::qString(&stru_1423FF8F0, "RacesNP_05");
  UFG::qSymbol::create_from_string(&stru_1423FF918, "RacesNP_05");
  UFG::qString::qString(&stru_1423FF920, "$SGTITLE_RACE_NORTH_POINT_05");
  unk_1423FF948 = 3;
  UFG::qString::qString(&stru_1423FF950, "R_NP_05");
  UFG::qSymbol::create_from_string(&stru_1423FF978, "R_NP_05");
  UFG::qString::qString(&stru_1423FF980, "$LEADERBOARD_RACES_NP_05_DESC");
  UFG::qString::qString(&stru_1423FF9A8, "SocialHub_Race_Crippling_Road");
  unk_1423FF9D0 = "time";
  unk_1423FF9D8 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FF9E0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FF9F0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FFA18, "Main");
  unk_1423FFA20 = 80;
  unk_1423FFA24 = 1;
  UFG::qString::qString(&stru_1423FFA28, "RacesAB_01");
  UFG::qSymbol::create_from_string(&stru_1423FFA50, "RacesAB_01");
  UFG::qString::qString(&stru_1423FFA58, "$SGTITLE_RACE_ABERDEEN_01");
  unk_1423FFA80 = 3;
  UFG::qString::qString(&stru_1423FFA88, "R_AB_01");
  UFG::qSymbol::create_from_string(&stru_1423FFAB0, "R_AB_01");
  UFG::qString::qString(&stru_1423FFAB8, "$LEADERBOARD_RACES_AB_01_DESC");
  UFG::qString::qString(&stru_1423FFAE0, "SocialHub_Race_D_Tour");
  unk_1423FFB08 = "time";
  _mm_store_si128((__m128i *)&unk_1423FFB10, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FFB20 = 0i64;
  UFG::qString::qString(&stru_1423FFB28, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FFB50, "Main");
  unk_1423FFB58 = 81;
  unk_1423FFB5C = 12;
  UFG::qString::qString(&stru_1423FFB60, "RacesNP_02");
  UFG::qSymbol::create_from_string(&stru_1423FFB88, "RacesNP_02");
  UFG::qString::qString(&stru_1423FFB90, "$SGTITLE_RACE_NORTH_POINT_02");
  unk_1423FFBB8 = 3;
  UFG::qString::qString(&stru_1423FFBC0, "R_NP_02");
  UFG::qSymbol::create_from_string(&stru_1423FFBE8, "R_NP_02");
  UFG::qString::qString(&stru_1423FFBF0, "$LEADERBOARD_RACES_NP_02_DESC");
  UFG::qString::qString(&stru_1423FFC18, "SocialHub_Race_Alley_Press");
  unk_1423FFC40 = "time";
  unk_1423FFC48 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FFC50, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FFC60, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FFC88, "Main");
  unk_1423FFC90 = 82;
  unk_1423FFC94 = 13;
  UFG::qString::qString(&stru_1423FFC98, "RacesCT_08");
  UFG::qSymbol::create_from_string(&stru_1423FFCC0, "RacesCT_08");
  UFG::qString::qString(&stru_1423FFCC8, "$SGTITLE_CENTRAL_08");
  unk_1423FFCF0 = 3;
  UFG::qString::qString(&stru_1423FFCF8, "R_CT_08");
  UFG::qSymbol::create_from_string(&stru_1423FFD20, "R_CT_08");
  UFG::qString::qString(&stru_1423FFD28, "$LEADERBOARD_RACES_CT_08_DESC");
  UFG::qString::qString(&stru_1423FFD50, "SocialHub_Race_Early_Grave");
  unk_1423FFD78 = "time";
  _mm_store_si128((__m128i *)&unk_1423FFD80, _mm_load_si128((const __m128i *)&_xmm));
  unk_1423FFD90 = 0i64;
  UFG::qString::qString(&stru_1423FFD98, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FFDC0, "Main");
  unk_1423FFDC8 = 83;
  unk_1423FFDCC = 14;
  UFG::qString::qString(&stru_1423FFDD0, "RacesCT_09");
  UFG::qSymbol::create_from_string(&stru_1423FFDF8, "RacesCT_09");
  UFG::qString::qString(&stru_1423FFE00, "$SGTITLE_CENTRAL_09");
  unk_1423FFE28 = 3;
  UFG::qString::qString(&stru_1423FFE30, "R_CT_09");
  UFG::qSymbol::create_from_string(&stru_1423FFE58, "R_CT_09");
  UFG::qString::qString(&stru_1423FFE60, "$LEADERBOARD_RACES_CT_09_DESC");
  UFG::qString::qString(&stru_1423FFE88, "SocialHub_Race_Starboard");
  unk_1423FFEB0 = "time";
  unk_1423FFEB8 = -1i64;
  _mm_store_si128((__m128i *)&unk_1423FFEC0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1423FFED0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1423FFEF8, "Main");
  unk_1423FFF00 = 84;
  unk_1423FFF04 = 3;
  UFG::qString::qString(&stru_1423FFF08, "RacesCT_02");
  UFG::qSymbol::create_from_string(&stru_1423FFF30, "RacesCT_02");
  UFG::qString::qString(&stru_1423FFF38, "$SGTITLE_RACE_CENTRAL_02");
  unk_1423FFF60 = 3;
  UFG::qString::qString(&stru_1423FFF68, "R_CT_02");
  UFG::qSymbol::create_from_string(&stru_1423FFF90, "R_CT_02");
  UFG::qString::qString(&stru_1423FFF98, "$LEADERBOARD_RACES_CT_02_DESC");
  UFG::qString::qString(&stru_1423FFFC0, "SocialHub_Race_Midtown");
  unk_1423FFFE8 = "time";
  _mm_store_si128((__m128i *)&unk_1423FFFF0, _mm_load_si128((const __m128i *)&_xmm));
  unk_142400000 = 0i64;
  UFG::qString::qString(&stru_142400008, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_142400030, "Main");
  unk_142400038 = 85;
  unk_14240003C = 5;
  UFG::qString::qString(&stru_142400040, "RacesCT_03");
  UFG::qSymbol::create_from_string(&stru_142400068, "RacesCT_03");
  UFG::qString::qString(&stru_142400070, "$SGTITLE_RACE_CENTRAL_03");
  unk_142400098 = 3;
  UFG::qString::qString(&stru_1424000A0, "R_CT_03");
  UFG::qSymbol::create_from_string(&stru_1424000C8, "R_CT_03");
  UFG::qString::qString(&stru_1424000D0, "$LEADERBOARD_RACES_CT_03_DESC");
  UFG::qString::qString(&stru_1424000F8, "SocialHub_Race_Wall_Street");
  unk_142400120 = "time";
  unk_142400128 = -1i64;
  _mm_store_si128((__m128i *)&unk_142400130, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_142400140, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_142400168, "Main");
  unk_142400170 = 86;
  unk_142400174 = 8;
  UFG::qString::qString(&stru_142400178, "RacesCT_10");
  UFG::qSymbol::create_from_string(&stru_1424001A0, "RacesCT_10");
  UFG::qString::qString(&stru_1424001A8, "$SGTITLE_CENTRAL_10");
  unk_1424001D0 = 3;
  UFG::qString::qString(&stru_1424001D8, "R_CT_10");
  UFG::qSymbol::create_from_string(&stru_142400200, "R_CT_10");
  UFG::qString::qString(&stru_142400208, "$LEADERBOARD_RACES_CT_10_DESC");
  UFG::qString::qString(&stru_142400230, "SocialHub_Race_Unconventional");
  unk_142400258 = "time";
  _mm_store_si128((__m128i *)&unk_142400260, _mm_load_si128((const __m128i *)&_xmm));
  unk_142400270 = 0i64;
  UFG::qString::qString(&stru_142400278, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1424002A0, "Main");
  unk_1424002A8 = 87;
  unk_1424002AC = 10;
  UFG::qString::qString(&stru_1424002B0, "RacesVP_01");
  UFG::qSymbol::create_from_string(&stru_1424002D8, "RacesVP_01");
  UFG::qString::qString(&stru_1424002E0, "$SGTITLE_RACE_VICTORIAPEAK01");
  unk_142400308 = 3;
  UFG::qString::qString(&stru_142400310, "R_VP_01");
  UFG::qSymbol::create_from_string(&stru_142400338, "R_VP_01");
  UFG::qString::qString(&stru_142400340, "$LEADERBOARD_RACES_VP_01_DESC");
  UFG::qString::qString(&stru_142400368, "SocialHub_Race_The_Queen");
  unk_142400390 = "time";
  unk_142400398 = -1i64;
  _mm_store_si128((__m128i *)&unk_1424003A0, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_1424003B0, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1424003D8, "Main");
  unk_1424003E0 = 88;
  unk_1424003E4 = 9;
  UFG::qString::qString(&stru_1424003E8, "RacesVP_02");
  UFG::qSymbol::create_from_string(&stru_142400410, "RacesVP_02");
  UFG::qString::qString(&stru_142400418, "$SGTITLE_RACE_VICTORIAPEAK02");
  unk_142400440 = 3;
  UFG::qString::qString(&stru_142400448, "R_VP_02");
  UFG::qSymbol::create_from_string(&stru_142400470, "R_VP_02");
  UFG::qString::qString(&stru_142400478, "$LEADERBOARD_RACES_VP_02_DESC");
  UFG::qString::qString(&stru_1424004A0, "SocialHub_Race_Summit");
  unk_1424004C8 = "time";
  _mm_store_si128((__m128i *)&unk_1424004D0, _mm_load_si128((const __m128i *)&_xmm));
  unk_1424004E0 = 0i64;
  UFG::qString::qString(&stru_1424004E8, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_142400510, "Main");
  unk_142400518 = 89;
  unk_14240051C = 17;
  UFG::qString::qString(&stru_142400520, "RacesCT_01");
  UFG::qSymbol::create_from_string(&stru_142400548, "RacesCT_01");
  UFG::qString::qString(&stru_142400550, "$SGTITLE_RACE_CENTRAL_01");
  unk_142400578 = 3;
  UFG::qString::qString(&stru_142400580, "R_CT_01");
  UFG::qSymbol::create_from_string(&stru_1424005A8, "R_CT_01");
  UFG::qString::qString(&stru_1424005B0, "$LEADERBOARD_RACES_CT_01_DESC");
  UFG::qString::qString(&stru_1424005D8, "SocialHub_Race_Kamikaze");
  unk_142400600 = "time";
  unk_142400608 = -1i64;
  _mm_store_si128((__m128i *)&unk_142400610, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_142400620, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_142400648, "Main");
  unk_142400650 = 90;
  unk_142400654 = 18;
  UFG::qString::qString(&stru_142400658, "RacesKT_01");
  UFG::qSymbol::create_from_string(&stru_142400680, "RacesKT_01");
  UFG::qString::qString(&stru_142400688, "$SGTITLE_DLC_RACER_HK_ENDURO");
  unk_1424006B0 = 3;
  UFG::qString::qString(&stru_1424006B8, "R_KT_01");
  UFG::qSymbol::create_from_string(&stru_1424006E0, "R_KT_01");
  UFG::qString::qString(&stru_1424006E8, "$LEADERBOARD_RACES_KT_01_DESC");
  UFG::qString::qString(&stru_142400710, "SocialHub_Race_Enduro");
  unk_142400738 = "time";
  _mm_store_si128((__m128i *)&unk_142400740, _mm_load_si128((const __m128i *)&_xmm));
  unk_142400750 = 0i64;
  UFG::qString::qString(&stru_142400758, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_142400780, "Main");
  unk_142400788 = 91;
  unk_14240078C = 19;
  UFG::qString::qString(&stru_142400790, "RacesKT_03");
  UFG::qSymbol::create_from_string(&stru_1424007B8, "RacesKT_03");
  UFG::qString::qString(&stru_1424007C0, "$SGTITLE_DLCRACER_HARBOURRUN");
  unk_1424007E8 = 3;
  UFG::qString::qString(&stru_1424007F0, "R_KT_03");
  UFG::qSymbol::create_from_string(&stru_142400818, "R_KT_03");
  UFG::qString::qString(&stru_142400820, "$LEADERBOARD_RACES_KT_03_DESC");
  UFG::qString::qString(&stru_142400848, "SocialHub_Race_Harbor_Run");
  unk_142400870 = "time";
  unk_142400878 = -1i64;
  _mm_store_si128((__m128i *)&unk_142400880, _mm_load_si128((const __m128i *)&_xmm));
  UFG::qString::qString(&stru_142400890, &customWorldMapCaption);
  UFG::qSymbol::create_from_string(&stru_1424008B8, "Main");
  return atexit(UFG::_dynamic_atexit_destructor_for__aHardcodedLeaderboardData__);
}ring(&stru_142400680, "RacesKT_01");
  UFG::qString::qString(&stru_142400688, "$SGTITLE_DLC_RACER_HK_ENDURO");
  unk_1424006B0 = 3;
  UFG::qString::qString(&stru_1424006B8, "R_KT_01");
  UFG::qSymbol::create_from_string(&stru_1424006E0, "R_KT_01");
  UFG::qString::qString(&stru_1424006E8, "$LEADERBOARD_RACES_KT_01_DESC");
  UFG::qString::qString(&stru_142400710, "SocialHub_Race_End

// File Line: 393
// RVA: 0x42AC80
void __fastcall UFG::MessageBuffer::AppendValue(UFG::MessageBuffer *this, UFG::PlayerStatSubmissionLookup *lookup, float value)
{
  UFG::MessageBuffer *v3; // rdi
  int v4; // eax
  __int64 v5; // rbx
  char dest; // [rsp+20h] [rbp-98h]

  v3 = this;
  UFG::MessageBuffer::AppendDescriptor(this, lookup, lookup->mStatName);
  v4 = UFG::qSPrintf(&dest, "%f", value);
  v5 = v4;
  UFG::qStringCopy(v3->mCurrentOffset, LODWORD(v3->mBuffer) + v3->mBufferSize - LODWORD(v3->mCurrentOffset), &dest, v4);
  v3->mCurrentOffset += v5;
  *v3->mCurrentOffset = 0;
}

// File Line: 404
// RVA: 0x42AC10
void __fastcall UFG::MessageBuffer::AppendValue(UFG::MessageBuffer *this, UFG::PlayerStatSubmissionLookup *lookup, int value)
{
  unsigned int v3; // ebx
  UFG::MessageBuffer *v4; // rdi
  int v5; // eax
  __int64 v6; // rbx
  char dest; // [rsp+20h] [rbp-88h]

  v3 = value;
  v4 = this;
  UFG::MessageBuffer::AppendDescriptor(this, lookup, lookup->mStatName);
  v5 = UFG::qSPrintf(&dest, "%d", v3);
  v6 = v5;
  UFG::qStringCopy(v4->mCurrentOffset, LODWORD(v4->mBuffer) + v4->mBufferSize - LODWORD(v4->mCurrentOffset), &dest, v5);
  v4->mCurrentOffset += v6;
  *v4->mCurrentOffset = 0;
}

// File Line: 428
// RVA: 0x42AB00
void __fastcall UFG::MessageBuffer::AppendDescriptor(UFG::MessageBuffer *this, UFG::PlayerStatSubmissionLookup *lookup, const char *statName)
{
  UFG::DataType v3; // er9
  UFG::MessageBuffer *v4; // rdi
  UFG::SubmissionType v5; // ecx
  char *v6; // rax
  const char *v7; // rsi
  char *v8; // rax
  int v9; // ecx
  int v10; // eax
  __int64 v11; // rbx

  v3 = lookup->mDataType;
  v4 = this;
  v5 = lookup->mSubmisionType;
  v6 = v4->mCurrentOffset;
  v7 = statName;
  if ( v6 != v4->mBuffer )
  {
    *v6 = 44;
    ++v4->mCurrentOffset;
  }
  v8 = v4->mCurrentOffset;
  if ( (unsigned int)(v3 - 1) <= 1 )
  {
    *v8 = 102;
    v4->mCurrentOffset[1] = 95;
    v4->mCurrentOffset += 2;
  }
  else
  {
    *v8 = 105;
    v4->mCurrentOffset[1] = 51;
    v4->mCurrentOffset[2] = 50;
    v4->mCurrentOffset[3] = 95;
    v4->mCurrentOffset += 4;
  }
  if ( v5 == SUBMITTYPE_SUM )
  {
    *v4->mCurrentOffset = 115;
    v4->mCurrentOffset[1] = 117;
    v4->mCurrentOffset[2] = 109;
    goto LABEL_12;
  }
  v9 = v5 - 1;
  if ( !v9 )
  {
    *v4->mCurrentOffset = 109;
    v4->mCurrentOffset[1] = 105;
    v4->mCurrentOffset[2] = 110;
    goto LABEL_12;
  }
  if ( v9 == 1 )
  {
    *v4->mCurrentOffset = 109;
    v4->mCurrentOffset[1] = 97;
    v4->mCurrentOffset[2] = 120;
LABEL_12:
    v4->mCurrentOffset += 3;
  }
  v10 = UFG::qStringLength(statName);
  v11 = v10;
  UFG::qStringCopy(v4->mCurrentOffset, LODWORD(v4->mBuffer) + v4->mBufferSize - LODWORD(v4->mCurrentOffset), v7, v10);
  v4->mCurrentOffset += v11;
  *v4->mCurrentOffset++ = 61;
  *v4->mCurrentOffset = 0;
}

// File Line: 493
// RVA: 0x42CF20
void __fastcall UFG::OSuiteLeaderboardManager::GetTopFriendsStatScoresCallback(OSuite::SCallbackData *pData, OSuite::ZWebServiceClient *pWebServiceClient)
{
  OSuite::ZWebServiceClient *v2; // rdi
  OSuite::SCallbackData *v3; // rbx
  UFG::OnlineManager *v4; // rax
  UFG::OnlineId *v5; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v6; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v7; // rax
  UFG::OnlineManager *v8; // rax
  OSuite::ZOEntry *v9; // r12
  unsigned int i; // er15
  signed __int64 v11; // rsi
  OSuite::ZOProperty *v12; // r14
  signed int v13; // ebx
  OSuite::ZOProperty *v14; // rdi
  OSuite::ZOProperty *v15; // rax
  OSuite::ZOProperty *v16; // rax
  const char *v17; // rax
  char *v18; // rdi
  const char *v19; // rax
  __int64 v20; // rdi
  UFG::CachedLeaderboardManager *v21; // rax
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *v22; // rcx
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *v23; // rax
  const char *v24; // rax
  char v25; // al
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v26; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v27; // rcx
  UFG::OSuiteLeaderboardData *v28; // rdi
  UFG::CachedLeaderboardManager *v29; // rax
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *v30; // rcx
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *v31; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v32; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v33; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v34; // rcx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v35; // rax
  UFG::OnlineId result; // [rsp+20h] [rbp-E0h]
  UFG::OnlineFriend frnd; // [rsp+40h] [rbp-C0h]
  OSuite::ZString outValue; // [rsp+A0h] [rbp-60h]
  char dest; // [rsp+B8h] [rbp-48h]
  char subPropertyName; // [rsp+C8h] [rbp-38h]
  UFG::CachedLeaderboard::Entry v41; // [rsp+E0h] [rbp-20h]
  UFG::CachedLeaderboard::Entry entry; // [rsp+140h] [rbp+40h]
  __int64 v43; // [rsp+1A0h] [rbp+A0h]
  UFG::qString v44; // [rsp+1A8h] [rbp+A8h]
  UFG::qString v45; // [rsp+1D0h] [rbp+D0h]
  int v46; // [rsp+240h] [rbp+140h]
  OSuite::ZOEntry *v47; // [rsp+250h] [rbp+150h]
  UFG::OnlineId *v48; // [rsp+258h] [rbp+158h]

  v43 = -2i64;
  v2 = pWebServiceClient;
  v3 = pData;
  if ( pData->Status.eError == HTTPERROR_OK )
  {
    UFG::OSuiteLeaderboardManager::m_bIsFriendsScoresInserted = 1;
    v4 = UFG::OnlineManager::Instance();
    v5 = UFG::OnlineManager::GetOnlineId(v4, &result);
    UFG::OnlineId::ToString(v5, &v44);
    v6 = result.mPrev;
    v7 = result.mNext;
    result.mPrev->mNext = result.mNext;
    v7->mPrev = v6;
    result.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&result;
    result.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&result;
    v8 = UFG::OnlineManager::Instance();
    UFG::OnlineManager::GetOnlineName(v8, &v45);
    v9 = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOEntry>(v2, &v3->URL);
    v47 = v9;
    if ( v9 )
    {
      for ( i = 0; ; ++i )
      {
        if ( !(_S10_6 & 1) )
        {
          _S10_6 |= 1u;
          UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
          atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
        }
        if ( i >= dword_1424014F8 )
          break;
        if ( !(_S10_6 & 1) )
        {
          _S10_6 |= 1u;
          UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
          atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
        }
        v11 = 312i64 * i;
        if ( *(_DWORD *)(v11 + qword_142401500 + 96) == 1 )
        {
          UFG::qMemSet(&dest, 0, 0x10u);
          if ( !(_S10_6 & 1) )
          {
            _S10_6 |= 1u;
            UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
            atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
          }
          UFG::qSPrintf(&dest, "c_lb%d", *(unsigned int *)(v11 + qword_142401500 + 4));
          v12 = OSuite::ZOEntry::Property(v9, &dest);
          if ( v12 )
          {
            v13 = 0;
            do
            {
              UFG::qMemSet(&subPropertyName, 0, 0x10u);
              UFG::qSPrintf(&subPropertyName, "c_p%d", (unsigned int)v13);
              v14 = OSuite::ZOProperty::GetSubProperty(v12, &subPropertyName);
              if ( v14 )
              {
                OSuite::ZString::ZString(&outValue);
                v46 = 0;
                v15 = OSuite::ZOProperty::GetSubProperty(v14, "s_Pid");
                OSuite::ZOProperty::GetValue(v15, &outValue);
                v16 = OSuite::ZOProperty::GetSubProperty(v14, "i32_Score");
                OSuite::ZOProperty::GetValue(v16, &v46);
                v17 = OSuite::ZString::c_str(&outValue);
                UFG::qPrintf("lbName: %s, id: %s, score: %d\n", &dest, v17, (unsigned int)v46);
                v18 = v44.mData;
                v19 = OSuite::ZString::c_str(&outValue);
                if ( (unsigned int)UFG::qStringCompare(v18, v19, -1) )
                {
                  frnd.mPrev = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&frnd.mPrev;
                  frnd.mNext = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&frnd.mPrev;
                  frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable';
                  v48 = &frnd.m_cOnlineId;
                  frnd.m_cOnlineId.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&frnd.m_cOnlineId.mPrev;
                  frnd.m_cOnlineId.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&frnd.m_cOnlineId.mPrev;
                  frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits = __PAIR__(
                                                                         HIDWORD(frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits),
                                                                         0) & 0xFF0FFFFF00000000ui64;
                  HIBYTE(frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits) = 0;
                  *((_DWORD *)&frnd.m_cOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
                  UFG::qString::qString(&frnd.m_sOnlineName);
                  v24 = OSuite::ZString::c_str(&outValue);
                  result.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&result;
                  result.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&result;
                  result.m_SteamId.m_steamid.m_unAll64Bits = __PAIR__(
                                                               HIDWORD(result.m_SteamId.m_steamid.m_unAll64Bits),
                                                               0) & 0xFF0FFFFF00000000ui64;
                  HIBYTE(result.m_SteamId.m_steamid.m_unAll64Bits) = 0;
                  *((_DWORD *)&result.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
                  result.m_SteamId.m_steamid.m_unAll64Bits = UFG::qToUInt64(v24, 0i64);
                  v25 = UFG::OnlineFriendManager::FindFriend(&frnd, &result);
                  v26 = result.mPrev;
                  v27 = result.mNext;
                  result.mPrev->mNext = result.mNext;
                  v27->mPrev = v26;
                  result.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&result;
                  result.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&result;
                  if ( v25 )
                  {
                    v41.mPrev = (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)&v41;
                    v41.mNext = (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)&v41;
                    v41.m_iRating = v46;
                    v41.m_uRank = 0;
                    v41.m_eEntryType = 1;
                    UFG::qStringCopy(v41.m_sUsername, 64, frnd.m_sOnlineName.mData, -1);
                    v28 = UFG::OSuiteLeaderboardManager::Instance()->mLeaderboardData.p;
                    v29 = UFG::CachedLeaderboardManager::Instance();
                    UFG::CachedLeaderboardManager::UpsertEntry(
                      v29,
                      v28[(unsigned __int64)v11 / 0x138].mLeaderboardId,
                      &v41);
                    v30 = v41.mPrev;
                    v31 = v41.mNext;
                    v41.mPrev->mNext = v41.mNext;
                    v31->mPrev = v30;
                    v41.mPrev = (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)&v41;
                    v41.mNext = (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)&v41;
                  }
                  frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable';
                  UFG::qString::~qString(&frnd.m_sOnlineName);
                  v48 = &frnd.m_cOnlineId;
                  v32 = frnd.m_cOnlineId.mPrev;
                  v33 = frnd.m_cOnlineId.mNext;
                  frnd.m_cOnlineId.mPrev->mNext = frnd.m_cOnlineId.mNext;
                  v33->mPrev = v32;
                  frnd.m_cOnlineId.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&frnd.m_cOnlineId.mPrev;
                  frnd.m_cOnlineId.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&frnd.m_cOnlineId.mPrev;
                  v34 = frnd.mPrev;
                  v35 = frnd.mNext;
                  frnd.mPrev->mNext = frnd.mNext;
                  v35->mPrev = v34;
                  frnd.mPrev = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&frnd.mPrev;
                  frnd.mNext = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&frnd.mPrev;
                }
                else
                {
                  entry.mPrev = (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)&entry;
                  entry.mNext = (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)&entry;
                  entry.m_iRating = v46;
                  entry.m_uRank = 0;
                  entry.m_eEntryType = 2;
                  UFG::qStringCopy(entry.m_sUsername, 64, v45.mData, -1);
                  if ( !(_S10_6 & 1) )
                  {
                    _S10_6 |= 1u;
                    UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
                    atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
                  }
                  v20 = qword_142401500;
                  v21 = UFG::CachedLeaderboardManager::Instance();
                  UFG::CachedLeaderboardManager::UpsertEntry(v21, *(_DWORD *)(v20 + v11), &entry);
                  v22 = entry.mPrev;
                  v23 = entry.mNext;
                  entry.mPrev->mNext = entry.mNext;
                  v23->mPrev = v22;
                  entry.mPrev = (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)&entry;
                  entry.mNext = (UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *)&entry;
                }
                OSuite::ZString::~ZString(&outValue);
              }
              ++v13;
            }
            while ( v13 < 10 );
            v9 = v47;
          }
        }
      }
    }
    UFG::qString::~qString(&v45);
    UFG::qString::~qString(&v44);
  }
}

// File Line: 587
// RVA: 0x428570
void __fastcall UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(UFG::OSuiteLeaderboardManager *this)
{
  UFG::OSuiteLeaderboardManager *v1; // rsi
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v2; // rdi
  UFG::OSuiteManager *v3; // rax
  signed __int64 v4; // rdx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v5; // rax
  UFG::qList<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent,1,0> *v6; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable';
  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteLeaderboardManager::`vftable';
  this->mLeaderboardData.p = 0i64;
  *(_QWORD *)&this->mLeaderboardData.size = 0i64;
  this->mLeaderboardData_SortedBySliceName.p = 0i64;
  *(_QWORD *)&this->mLeaderboardData_SortedBySliceName.size = 0i64;
  this->mLeaderboardData_SortedByLeaderboardName.p = 0i64;
  *(_QWORD *)&this->mLeaderboardData_SortedByLeaderboardName.size = 0i64;
  this->m_pWebServiceClient = 0i64;
  v6 = &this->m_updateEvents;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  this->m_rTimerForFriendsScores = 0.0;
  *(_WORD *)&this->m_bQueueOptionsSave = 0;
  UFG::qMutex::qMutex(&this->m_cMutex, &customWorldMapCaption);
  UFG::qEvent::qEvent(&v1->m_cThreadEvent, "OSuiteLeaderboardManager", 1);
  UFG::qThread::qThread(&v1->m_cUpdateThread, "OSuiteLeaderboardManager");
  v3 = UFG::OSuiteManager::Instance();
  v4 = (signed __int64)&v3->m_lOSuiteObservers;
  v5 = v3->m_lOSuiteObservers.mNode.mNext;
  *(_QWORD *)(v4 + 8) = v2;
  v2->mPrev = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)v4;
  v2->mNext = v5;
  v5->mPrev = v2;
  UFG::qBaseNodeRB::SetUID((UFG::qBaseNodeRB *)&v1->m_cUpdateThread, 0x4000u);
  UFG::qThread::SetThreadPriority(&v1->m_cUpdateThread, -1);
  UFG::qThread::Start(&v1->m_cUpdateThread, UFG::OSuiteLeaderboardManager::UpdateThread, v1);
}

// File Line: 596
// RVA: 0x42E3E0
UFG::OSuiteLeaderboardManager *__fastcall UFG::OSuiteLeaderboardManager::Instance()
{
  if ( !(_S10_6 & 1) )
  {
    _S10_6 |= 1u;
    UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
    atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  return &instance_4;
}

// File Line: 602
// RVA: 0x42E9B0
void __fastcall UFG::OSuiteLeaderboardManager::OSuiteManagerConnected(UFG::OSuiteLeaderboardManager *this, OSuite::ZWebServiceClient *p)
{
  if ( !this->m_pWebServiceClient )
  {
    this->m_pWebServiceClient = p;
    UFG::DataSynchronizer::UpdateOptionSaveDataIfNeeded();
  }
}

// File Line: 617
// RVA: 0x42E880
bool __fastcall UFG::LeaderboardDataComparison_Id(UFG::OSuiteLeaderboardData *one, UFG::OSuiteLeaderboardData *two)
{
  return one->mLeaderboardId <= two->mLeaderboardId;
}

// File Line: 621
// RVA: 0x42E8B0
bool __fastcall UFG::LeaderboardDataComparison_SliceName(UFG::OSuiteLeaderboardData *const *one, UFG::OSuiteLeaderboardData *const *two)
{
  return (*one)->mSliceName.mUID <= (*two)->mSliceName.mUID;
}

// File Line: 625
// RVA: 0x42E890
bool __fastcall UFG::LeaderboardDataComparison_LeaderboardName(UFG::OSuiteLeaderboardData *const *one, UFG::OSuiteLeaderboardData *const *two)
{
  return (*one)->mLeaderboardName.mUID <= (*two)->mLeaderboardName.mUID;
}

// File Line: 629
// RVA: 0x42D520
void __fastcall UFG::OSuiteLeaderboardManager::Init(UFG::OSuiteLeaderboardManager *this)
{
  UFG::OSuiteLeaderboardManager *v1; // rdi
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *v3; // rbx
  UFG::qSymbol *v4; // rax
  signed __int64 v5; // rsi
  UFG::qPropertyList *v6; // r14
  int *v7; // rax
  int v8; // er15
  UFG::qArray<UFG::OSuiteLeaderboardData,0> *v9; // r12
  unsigned __int64 v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::OSuiteLeaderboardData **v12; // rbx
  unsigned int i; // er9
  __int64 v14; // rcx
  unsigned __int64 v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::OSuiteLeaderboardData **v17; // rbx
  unsigned int j; // er9
  __int64 v19; // rcx
  unsigned int v20; // eax
  char *v21; // rax
  UFG::qPropertySet *v22; // rbx
  UFG::qSymbol *v23; // rax
  UFG::qPropertyList *v24; // r14
  UFG::qSymbol *v25; // rax
  unsigned int v26; // er13
  UFG::qPropertyList *v27; // rdi
  __int64 v28; // r14
  unsigned int v29; // edx
  unsigned int v30; // ebx
  unsigned int v31; // edx
  signed __int64 v32; // r14
  char *v33; // rax
  UFG::qPropertySet *v34; // rbx
  unsigned int *v35; // rax
  signed int v36; // er13
  int *v37; // rax
  int *v38; // rax
  int *v39; // rax
  int *v40; // rax
  int *v41; // rax
  int *v42; // rax
  int v43; // er13
  int *v44; // rax
  int v45; // ebx
  char *v46; // rdx
  UFG::qSymbol *v47; // rax
  char *v48; // rdx
  int v49; // eax
  char *v50; // rdx
  UFG::qSymbol *v51; // rax
  char *v52; // rdx
  char *v53; // rdx
  UFG::OSuiteLeaderboardData *v54; // r14
  __int64 v55; // r13
  unsigned int v56; // edx
  unsigned int v57; // ebx
  unsigned int v58; // edx
  unsigned int v59; // eax
  unsigned int v60; // ebx
  signed __int64 v61; // rcx
  __int64 v62; // rax
  __int64 v63; // rcx
  unsigned int v64; // er14
  unsigned int v65; // ebx
  unsigned __int64 v66; // rax
  UFG::allocator::free_link *v67; // rax
  UFG::OSuiteLeaderboardData **v68; // r13
  unsigned int k; // er9
  __int64 v70; // rcx
  UFG::OSuiteLeaderboardData **v71; // rax
  __int64 v72; // rdx
  __int64 v73; // rcx
  unsigned int v74; // ebx
  unsigned int v75; // er14
  unsigned int v76; // ebx
  unsigned __int64 v77; // rax
  UFG::allocator::free_link *v78; // rax
  UFG::OSuiteLeaderboardData **v79; // r13
  unsigned int l; // er9
  __int64 v81; // rcx
  UFG::OSuiteLeaderboardData **v82; // rax
  __int64 v83; // rdx
  UFG::qPropertySet **v84; // r9
  UFG::qPropertySet **v85; // r14
  signed __int64 v86; // rax
  signed int v87; // ecx
  signed __int64 v88; // rcx
  UFG::qPropertySet *v89; // r8
  UFG::qPropertySet *v90; // r8
  UFG::qPropertySet *v91; // r8
  UFG::qPropertySet *v92; // r8
  UFG::qPropertySet **v93; // rbx
  UFG::qPropertySet **n; // rdx
  unsigned int v95; // ecx
  UFG::qPropertySet *v96; // rax
  __int64 v97; // rax
  UFG::qPropertySet *v98; // rax
  UFG::qPropertySet *v99; // rcx
  signed __int64 v100; // r14
  signed __int64 v101; // r11
  int v102; // ebx
  UFG::qPropertySet *v103; // r10
  int v104; // edx
  signed __int64 m; // rcx
  UFG::qPropertySet *v106; // r8
  UFG::qPropertySet **v107; // r9
  UFG::qPropertySet **v108; // rdi
  signed __int64 v109; // rax
  signed int v110; // ecx
  signed __int64 v111; // rcx
  UFG::qPropertySet *v112; // r8
  UFG::qPropertySet *v113; // r8
  UFG::qPropertySet *v114; // r8
  UFG::qPropertySet *v115; // r8
  UFG::qPropertySet **v116; // rbx
  UFG::qPropertySet **jj; // rdx
  unsigned int v118; // ecx
  UFG::qPropertySet *v119; // rax
  __int64 v120; // rax
  UFG::qPropertySet *v121; // rax
  UFG::qPropertySet *v122; // rcx
  signed __int64 v123; // r11
  UFG::qPropertySet *v124; // r10
  int v125; // edx
  signed __int64 ii; // rcx
  UFG::qPropertySet *v127; // r8
  int v128; // [rsp+20h] [rbp-E0h]
  signed int v129; // [rsp+24h] [rbp-DCh]
  unsigned int v130; // [rsp+28h] [rbp-D8h]
  signed int v131; // [rsp+2Ch] [rbp-D4h]
  unsigned int v132; // [rsp+30h] [rbp-D0h]
  UFG::qSymbol v133; // [rsp+34h] [rbp-CCh]
  UFG::qSymbol v134; // [rsp+38h] [rbp-C8h]
  UFG::qSymbol v135; // [rsp+3Ch] [rbp-C4h]
  UFG::qSymbol v136; // [rsp+40h] [rbp-C0h]
  UFG::qSymbol propName; // [rsp+44h] [rbp-BCh]
  UFG::qSymbol v138; // [rsp+48h] [rbp-B8h]
  UFG::qSymbol v139; // [rsp+4Ch] [rbp-B4h]
  UFG::qSymbol name; // [rsp+50h] [rbp-B0h]
  UFG::qSymbol v141; // [rsp+54h] [rbp-ACh]
  UFG::qSymbol v142; // [rsp+58h] [rbp-A8h]
  UFG::qSymbol v143; // [rsp+5Ch] [rbp-A4h]
  UFG::qSymbol v144; // [rsp+60h] [rbp-A0h]
  UFG::qSymbol v145; // [rsp+64h] [rbp-9Ch]
  UFG::qSymbol v146; // [rsp+68h] [rbp-98h]
  UFG::qSymbol v147; // [rsp+6Ch] [rbp-94h]
  UFG::qSymbol v148; // [rsp+70h] [rbp-90h]
  UFG::qSymbol v149; // [rsp+74h] [rbp-8Ch]
  UFG::qPropertyList *v150; // [rsp+78h] [rbp-88h]
  char *text; // [rsp+80h] [rbp-80h]
  char *pszSymbolString; // [rsp+88h] [rbp-78h]
  UFG::qSymbol v153; // [rsp+90h] [rbp-70h]
  char *pcString; // [rsp+98h] [rbp-68h]
  char *v155; // [rsp+A0h] [rbp-60h]
  UFG::qSymbol v156; // [rsp+A8h] [rbp-58h]
  char *v157; // [rsp+B0h] [rbp-50h]
  UFG::qSymbol v158; // [rsp+B8h] [rbp-48h]
  char *v159; // [rsp+C0h] [rbp-40h]
  UFG::qSymbol v160; // [rsp+C8h] [rbp-38h]
  char *v161; // [rsp+D0h] [rbp-30h]
  char *v162; // [rsp+D8h] [rbp-28h]
  char *v163; // [rsp+E0h] [rbp-20h]
  UFG::qSymbol v164; // [rsp+E8h] [rbp-18h]
  UFG::qSymbol v165; // [rsp+ECh] [rbp-14h]
  UFG::OSuiteLeaderboardManager *v166; // [rsp+140h] [rbp+40h]
  UFG::qSymbol result; // [rsp+148h] [rbp+48h]
  unsigned int v168; // [rsp+150h] [rbp+50h]
  UFG::OSuiteLeaderboardData *v169; // [rsp+158h] [rbp+58h]

  v166 = this;
  v1 = this;
  v2 = UFG::qSymbol::create_from_string(&result, "UI-Leaderboard");
  v3 = UFG::PropertySetManager::GetPropertySet(v2);
  if ( v3 )
  {
    v4 = UFG::qSymbol::create_from_string(&v153, "items");
    v5 = 1i64;
    v6 = PropertyUtils::Get<UFG::qPropertyList>(v3, v4, DEPTH_RECURSE);
    v150 = v6;
    if ( v6 )
    {
      UFG::qSymbol::create_from_string(&name, "version");
      v7 = UFG::qPropertySet::Get<long>(v3, &name, DEPTH_RECURSE);
      v8 = 0;
      if ( v7 && *v7 > 0 )
      {
        v9 = &v1->mLeaderboardData;
        if ( v1->mLeaderboardData.capacity < 0x80 )
          UFG::qArray<UFG::OSuiteLeaderboardData,0>::Reallocate(
            &v1->mLeaderboardData,
            0x80u,
            "qArray.Reallocate(Reserve)");
        if ( v1->mLeaderboardData_SortedBySliceName.capacity < 0x80
          && v1->mLeaderboardData_SortedBySliceName.size != 128 )
        {
          v10 = 1024i64;
          if ( !is_mul_ok(0x80ui64, 8ui64) )
            v10 = -1i64;
          v11 = UFG::qMalloc(v10, "qArray.Reallocate(Reserve)", 0i64);
          v12 = (UFG::OSuiteLeaderboardData **)v11;
          if ( v1->mLeaderboardData_SortedBySliceName.p )
          {
            for ( i = 0;
                  i < v1->mLeaderboardData_SortedBySliceName.size;
                  v11[v14] = (UFG::allocator::free_link)v1->mLeaderboardData_SortedBySliceName.p[v14] )
            {
              v14 = i++;
            }
            operator delete[](v1->mLeaderboardData_SortedBySliceName.p);
          }
          v1->mLeaderboardData_SortedBySliceName.p = v12;
          v1->mLeaderboardData_SortedBySliceName.capacity = 128;
        }
        if ( v1->mLeaderboardData_SortedByLeaderboardName.capacity < 0x80
          && v1->mLeaderboardData_SortedByLeaderboardName.size != 128 )
        {
          v15 = 1024i64;
          if ( !is_mul_ok(0x80ui64, 8ui64) )
            v15 = -1i64;
          v16 = UFG::qMalloc(v15, "qArray.Reallocate(Reserve)", 0i64);
          v17 = (UFG::OSuiteLeaderboardData **)v16;
          if ( v1->mLeaderboardData_SortedByLeaderboardName.p )
          {
            for ( j = 0;
                  j < v1->mLeaderboardData_SortedByLeaderboardName.size;
                  v16[v19] = (UFG::allocator::free_link)v1->mLeaderboardData_SortedByLeaderboardName.p[v19] )
            {
              v19 = j++;
            }
            operator delete[](v1->mLeaderboardData_SortedByLeaderboardName.p);
          }
          v1->mLeaderboardData_SortedByLeaderboardName.p = v17;
          v1->mLeaderboardData_SortedByLeaderboardName.capacity = 128;
        }
        UFG::qSymbol::create_from_string(&v146, "lbId");
        UFG::qSymbol::create_from_string(&v148, "lbLocalId");
        UFG::qSymbol::create_from_string(&propName, "caption");
        UFG::qSymbol::create_from_string(&v145, "sliceName");
        UFG::qSymbol::create_from_string(&v139, "leaderboardName");
        UFG::qSymbol::create_from_string(&v149, "desc");
        UFG::qSymbol::create_from_string(&v141, "imagesrc");
        UFG::qSymbol::create_from_string(&v147, "format");
        UFG::qSymbol::create_from_string(&v136, "gold");
        UFG::qSymbol::create_from_string(&v138, "silver");
        UFG::qSymbol::create_from_string(&v133, "bronze");
        UFG::qSymbol::create_from_string(&v142, "startMs");
        UFG::qSymbol::create_from_string(&v144, "deltaTime");
        UFG::qSymbol::create_from_string(&v134, "attemptCount");
        UFG::qSymbol::create_from_string(&v143, "rankDesc");
        UFG::qSymbol::create_from_string(&v135, "flow");
        v20 = 0;
        v132 = 0;
        if ( v6->mNumElements > 0 )
        {
          do
          {
            v21 = UFG::qPropertyList::GetValuePtr(v6, 0x1Au, v20);
            if ( !v21 || (v22 = (UFG::qPropertySet *)&v21[*(_QWORD *)v21], !*(_QWORD *)v21) )
              v22 = 0i64;
            v23 = UFG::qSymbol::create_from_string(&v164, "stats");
            v24 = PropertyUtils::Get<UFG::qPropertyList>(v22, v23, DEPTH_RECURSE);
            v25 = UFG::qSymbol::create_from_string(&v158, "category");
            v26 = 0;
            v130 = 0;
            pcString = PropertyUtils::Get<char const *>(v22, v25, DEPTH_RECURSE);
            if ( v24->mNumElements > 0 )
            {
              v27 = v24;
              do
              {
                v28 = v9->size;
                v29 = v9->capacity;
                v30 = v28 + 1;
                if ( (signed int)v28 + 1 > v29 )
                {
                  if ( v29 )
                    v31 = 2 * v29;
                  else
                    v31 = 1;
                  for ( ; v31 < v30; v31 *= 2 )
                    ;
                  if ( v31 - v30 > 0x10000 )
                    v31 = v28 + 65537;
                  UFG::qArray<UFG::OSuiteLeaderboardData,0>::Reallocate(v9, v31, "qArray.Add");
                }
                v9->size = v30;
                v32 = (signed __int64)&v9->p[v28];
                v33 = UFG::qPropertyList::GetValuePtr(v27, 0x1Au, v26);
                if ( !v33 || (v34 = (UFG::qPropertySet *)&v33[*(_QWORD *)v33], !*(_QWORD *)v33) )
                  v34 = 0i64;
                v35 = (unsigned int *)UFG::qPropertySet::Get<long>(v34, &v146, DEPTH_RECURSE);
                if ( v35 )
                {
                  result.mUID = *v35;
                  v36 = -1;
                }
                else
                {
                  v36 = -1;
                  result.mUID = -1;
                }
                v37 = UFG::qPropertySet::Get<long>(v34, &v148, DEPTH_RECURSE);
                if ( v37 )
                {
                  v168 = *v37;
                  v36 = -1;
                }
                else
                {
                  v168 = -1;
                }
                v162 = PropertyUtils::Get<char const *>(v34, &propName, DEPTH_RECURSE);
                pszSymbolString = PropertyUtils::Get<char const *>(v34, &v145, DEPTH_RECURSE);
                text = PropertyUtils::Get<char const *>(v34, &v139, DEPTH_RECURSE);
                v155 = PropertyUtils::Get<char const *>(v34, &v149, DEPTH_RECURSE);
                v157 = PropertyUtils::Get<char const *>(v34, &v141, DEPTH_RECURSE);
                v159 = PropertyUtils::Get<char const *>(v34, &v147, DEPTH_RECURSE);
                v161 = PropertyUtils::Get<char const *>(v34, &v143, DEPTH_RECURSE);
                v163 = PropertyUtils::Get<char const *>(v34, &v135, DEPTH_RECURSE);
                v38 = UFG::qPropertySet::Get<long>(v34, &v136, DEPTH_RECURSE);
                if ( v38 )
                {
                  LODWORD(v169) = *v38;
                  v36 = -1;
                }
                else
                {
                  LODWORD(v169) = -1;
                }
                v39 = UFG::qPropertySet::Get<long>(v34, &v138, DEPTH_RECURSE);
                if ( v39 )
                {
                  v129 = *v39;
                  v36 = -1;
                }
                else
                {
                  v129 = -1;
                }
                v40 = UFG::qPropertySet::Get<long>(v34, &v133, DEPTH_RECURSE);
                if ( v40 )
                  v36 = *v40;
                v131 = v36;
                v41 = UFG::qPropertySet::Get<long>(v34, &v142, DEPTH_RECURSE);
                if ( v41 )
                  v128 = *v41;
                else
                  v128 = 0;
                v42 = UFG::qPropertySet::Get<long>(v34, &v144, DEPTH_RECURSE);
                if ( v42 )
                  v43 = *v42;
                else
                  v43 = 0;
                v44 = UFG::qPropertySet::Get<long>(v34, &v134, DEPTH_RECURSE);
                if ( v44 )
                  v45 = *v44;
                else
                  v45 = 0;
                if ( (result.mUID & 0x80000000) == 0 )
                {
                  v46 = text;
                  *(UFG::qSymbol *)v32 = result;
                  *(_DWORD *)(v32 + 4) = v168;
                  UFG::qString::Set((UFG::qString *)(v32 + 8), v46);
                  v47 = UFG::qSymbol::create_from_string(&v165, text);
                  v48 = v162;
                  *(UFG::qSymbol *)(v32 + 48) = (UFG::qSymbol)v47->mUID;
                  UFG::qString::Set((UFG::qString *)(v32 + 56), v48);
                  v49 = UFG::GetLeaderboardCategoryFromString(pcString);
                  v50 = pszSymbolString;
                  *(_DWORD *)(v32 + 96) = v49;
                  UFG::qString::Set((UFG::qString *)(v32 + 104), v50);
                  v51 = UFG::qSymbol::create_from_string(&v160, pszSymbolString);
                  v52 = v155;
                  *(UFG::qSymbol *)(v32 + 144) = (UFG::qSymbol)v51->mUID;
                  UFG::qString::Set((UFG::qString *)(v32 + 152), v52);
                  UFG::qString::Set((UFG::qString *)(v32 + 192), v157);
                  v53 = v161;
                  *(_QWORD *)(v32 + 232) = v159;
                  *(_DWORD *)(v32 + 240) = (_DWORD)v169;
                  *(_DWORD *)(v32 + 256) = v43;
                  *(_DWORD *)(v32 + 244) = v129;
                  *(_DWORD *)(v32 + 260) = v45;
                  *(_DWORD *)(v32 + 248) = v131;
                  *(_DWORD *)(v32 + 252) = v128;
                  UFG::qString::Set((UFG::qString *)(v32 + 264), v53);
                  *(UFG::qSymbol *)(v32 + 304) = (UFG::qSymbol)UFG::qSymbol::create_from_string(&v156, v163)->mUID;
                }
                v26 = v130 + 1;
                v130 = v26;
              }
              while ( v26 < v27->mNumElements );
            }
            v6 = v150;
            v20 = v132 + 1;
            v132 = v20;
          }
          while ( v20 < v150->mNumElements );
          v1 = v166;
        }
      }
      else
      {
        v9 = &v1->mLeaderboardData;
        v54 = UFG::aHardcodedLeaderboardData;
        *(_QWORD *)&result.mUID = 102i64;
        do
        {
          v55 = v9->size;
          v56 = v1->mLeaderboardData.capacity;
          v57 = v55 + 1;
          if ( (signed int)v55 + 1 > v56 )
          {
            if ( v56 )
              v58 = 2 * v56;
            else
              v58 = 1;
            for ( ; v58 < v57; v58 *= 2 )
              ;
            if ( v58 - v57 > 0x10000 )
              v58 = v55 + 65537;
            UFG::qArray<UFG::OSuiteLeaderboardData,0>::Reallocate(&v1->mLeaderboardData, v58, "qArray.Add");
          }
          v9->size = v57;
          UFG::OSuiteLeaderboardData::operator=(&v1->mLeaderboardData.p[v55], v54);
          ++v54;
          --*(_QWORD *)&result.mUID;
        }
        while ( *(_QWORD *)&result.mUID );
      }
      UFG::qQuickSortImpl<UFG::OSuiteLeaderboardData,bool (*)(UFG::OSuiteLeaderboardData const &,UFG::OSuiteLeaderboardData const &)>(
        v9->p,
        &v9->p[(signed int)v9->size - 1],
        UFG::LeaderboardDataComparison_Id);
      v59 = 0;
      for ( result.mUID = 0; v59 < v9->size; result.mUID = v59 )
      {
        v60 = v1->mLeaderboardData_SortedBySliceName.capacity;
        v61 = v59;
        v62 = (__int64)&v1->mLeaderboardData.p[v61];
        v150 = (UFG::qPropertyList *)(v61 * 312);
        v63 = v1->mLeaderboardData_SortedBySliceName.size;
        v64 = v63 + 1;
        v169 = (UFG::OSuiteLeaderboardData *)v62;
        v168 = v63;
        if ( (signed int)v63 + 1 > v60 )
        {
          if ( v60 )
            v65 = 2 * v60;
          else
            v65 = 1;
          for ( ; v65 < v64; v65 *= 2 )
            ;
          if ( v65 <= 2 )
            v65 = 2;
          if ( v65 - v64 > 0x10000 )
            v65 = v63 + 65537;
          if ( v65 != (_DWORD)v63 )
          {
            v66 = 8i64 * v65;
            if ( !is_mul_ok(v65, 8ui64) )
              v66 = -1i64;
            v67 = UFG::qMalloc(v66, "qArray.Add", 0i64);
            v68 = (UFG::OSuiteLeaderboardData **)v67;
            if ( v1->mLeaderboardData_SortedBySliceName.p )
            {
              for ( k = 0;
                    k < v1->mLeaderboardData_SortedBySliceName.size;
                    v67[v70] = (UFG::allocator::free_link)v1->mLeaderboardData_SortedBySliceName.p[v70] )
              {
                v70 = k++;
              }
              operator delete[](v1->mLeaderboardData_SortedBySliceName.p);
            }
            v63 = v168;
            v1->mLeaderboardData_SortedBySliceName.p = v68;
            v1->mLeaderboardData_SortedBySliceName.capacity = v65;
          }
        }
        v71 = v1->mLeaderboardData_SortedBySliceName.p;
        v72 = (__int64)v169;
        v1->mLeaderboardData_SortedBySliceName.size = v64;
        v71[v63] = (UFG::OSuiteLeaderboardData *)v72;
        v73 = v1->mLeaderboardData_SortedByLeaderboardName.size;
        v74 = v1->mLeaderboardData_SortedByLeaderboardName.capacity;
        v75 = v73 + 1;
        v169 = (UFG::OSuiteLeaderboardData *)((char *)v150 + (unsigned __int64)v1->mLeaderboardData.p);
        v168 = v73;
        if ( (signed int)v73 + 1 > v74 )
        {
          if ( v74 )
            v76 = 2 * v74;
          else
            v76 = 1;
          for ( ; v76 < v75; v76 *= 2 )
            ;
          if ( v76 <= 2 )
            v76 = 2;
          if ( v76 - v75 > 0x10000 )
            v76 = v73 + 65537;
          if ( v76 != (_DWORD)v73 )
          {
            v77 = 8i64 * v76;
            if ( !is_mul_ok(v76, 8ui64) )
              v77 = -1i64;
            v78 = UFG::qMalloc(v77, "qArray.Add", 0i64);
            v79 = (UFG::OSuiteLeaderboardData **)v78;
            if ( v1->mLeaderboardData_SortedByLeaderboardName.p )
            {
              for ( l = 0;
                    l < v1->mLeaderboardData_SortedByLeaderboardName.size;
                    v78[v81] = (UFG::allocator::free_link)v1->mLeaderboardData_SortedByLeaderboardName.p[v81] )
              {
                v81 = l++;
              }
              operator delete[](v1->mLeaderboardData_SortedByLeaderboardName.p);
            }
            v73 = v168;
            v1->mLeaderboardData_SortedByLeaderboardName.p = v79;
            v1->mLeaderboardData_SortedByLeaderboardName.capacity = v76;
          }
        }
        v82 = v1->mLeaderboardData_SortedByLeaderboardName.p;
        v83 = (__int64)v169;
        v1->mLeaderboardData_SortedByLeaderboardName.size = v75;
        v82[v73] = (UFG::OSuiteLeaderboardData *)v83;
        v59 = result.mUID + 1;
      }
      v84 = (UFG::qPropertySet **)v1->mLeaderboardData_SortedBySliceName.p;
      v85 = &v84[(signed int)v1->mLeaderboardData_SortedBySliceName.size - 1i64];
      v86 = 8 * ((signed int)v1->mLeaderboardData_SortedBySliceName.size - 1i64) >> 3;
      v87 = v86 + 1;
      if ( (signed int)v86 + 1 < 32 )
      {
        if ( v87 > 1 )
        {
          v100 = v87;
          v101 = 1i64;
          if ( v87 > 1i64 )
          {
            v102 = 0;
            do
            {
              v103 = v84[v101];
              v104 = v102;
              for ( m = v101 - 1; v104 >= 0; --v104 )
              {
                v106 = v84[m];
                if ( LODWORD(v103[1].mProperties.mOffset) > LODWORD(v106[1].mProperties.mOffset) )
                  break;
                v84[m-- + 1] = v106;
              }
              ++v101;
              ++v102;
              v84[m + 1] = v103;
            }
            while ( v101 < v100 );
          }
        }
      }
      else
      {
        v88 = (signed __int64)&v84[v86 / 2];
        v89 = *(UFG::qPropertySet **)v88;
        if ( *(_DWORD *)(*(_QWORD *)v88 + 144i64) <= LODWORD((*v84)[1].mProperties.mOffset) )
        {
          *(_QWORD *)v88 = *v84;
          *v84 = v89;
        }
        v90 = *v85;
        if ( LODWORD((*v85)[1].mProperties.mOffset) <= *(_DWORD *)(*(_QWORD *)v88 + 144i64) )
        {
          *v85 = *(UFG::qPropertySet **)v88;
          *(_QWORD *)v88 = v90;
        }
        v91 = *(UFG::qPropertySet **)v88;
        if ( *(_DWORD *)(*(_QWORD *)v88 + 144i64) <= LODWORD((*v84)[1].mProperties.mOffset) )
        {
          *(_QWORD *)v88 = *v84;
          *v84 = v91;
        }
        v92 = *(UFG::qPropertySet **)v88;
        v93 = v84;
        for ( n = v85; v93 <= n; ++v93 )
        {
          v95 = v92[1].mProperties.mOffset;
          if ( LODWORD((*v93)[1].mProperties.mOffset) <= v95 )
          {
            do
            {
              if ( v93 >= v85 )
                break;
              v96 = v93[1];
              ++v93;
            }
            while ( LODWORD(v96[1].mProperties.mOffset) <= v95 );
          }
          if ( v95 <= LODWORD((*n)[1].mProperties.mOffset) )
          {
            do
            {
              if ( v84 >= n )
                break;
              v97 = (__int64)*(n - 1);
              --n;
            }
            while ( v95 <= *(_DWORD *)(v97 + 144) );
          }
          if ( v93 > n )
            break;
          v98 = *n;
          v99 = *v93;
          --n;
          *v93 = v98;
          n[1] = v99;
        }
        if ( v84 < n )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            v84,
            n,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::LeaderboardDataComparison_SliceName);
        if ( v93 < v85 )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            v93,
            v85,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::LeaderboardDataComparison_SliceName);
      }
      v107 = (UFG::qPropertySet **)v1->mLeaderboardData_SortedByLeaderboardName.p;
      v108 = &v107[(signed int)v1->mLeaderboardData_SortedByLeaderboardName.size - 1i64];
      v109 = v108 - v107;
      v110 = v109 + 1;
      if ( (signed int)v109 + 1 < 32 )
      {
        if ( v110 > 1 )
        {
          v123 = v110;
          if ( v110 > 1i64 )
          {
            do
            {
              v124 = v107[v5];
              v125 = v8;
              for ( ii = v5 - 1; v125 >= 0; --v125 )
              {
                v127 = v107[ii];
                if ( LODWORD(v124->mDefaultBits.mOffset) > LODWORD(v127->mDefaultBits.mOffset) )
                  break;
                v107[ii-- + 1] = v127;
              }
              ++v5;
              ++v8;
              v107[ii + 1] = v124;
            }
            while ( v5 < v123 );
          }
        }
      }
      else
      {
        v111 = (signed __int64)&v107[v109 / 2];
        v112 = *(UFG::qPropertySet **)v111;
        if ( *(_DWORD *)(*(_QWORD *)v111 + 48i64) <= LODWORD((*v107)->mDefaultBits.mOffset) )
        {
          *(_QWORD *)v111 = *v107;
          *v107 = v112;
        }
        v113 = *v108;
        if ( LODWORD((*v108)->mDefaultBits.mOffset) <= *(_DWORD *)(*(_QWORD *)v111 + 48i64) )
        {
          *v108 = *(UFG::qPropertySet **)v111;
          *(_QWORD *)v111 = v113;
        }
        v114 = *(UFG::qPropertySet **)v111;
        if ( *(_DWORD *)(*(_QWORD *)v111 + 48i64) <= LODWORD((*v107)->mDefaultBits.mOffset) )
        {
          *(_QWORD *)v111 = *v107;
          *v107 = v114;
        }
        v115 = *(UFG::qPropertySet **)v111;
        v116 = v107;
        for ( jj = v108; v116 <= jj; ++v116 )
        {
          v118 = v115->mDefaultBits.mOffset;
          if ( LODWORD((*v116)->mDefaultBits.mOffset) <= v118 )
          {
            do
            {
              if ( v116 >= v108 )
                break;
              v119 = v116[1];
              ++v116;
            }
            while ( LODWORD(v119->mDefaultBits.mOffset) <= v118 );
          }
          if ( v118 <= LODWORD((*jj)->mDefaultBits.mOffset) )
          {
            do
            {
              if ( v107 >= jj )
                break;
              v120 = (__int64)*(jj - 1);
              --jj;
            }
            while ( v118 <= *(_DWORD *)(v120 + 48) );
          }
          if ( v116 > jj )
            break;
          v121 = *jj;
          v122 = *v116;
          --jj;
          *v116 = v121;
          jj[1] = v122;
        }
        if ( v107 < jj )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            v107,
            jj,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::LeaderboardDataComparison_LeaderboardName);
        if ( v116 < v108 )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            v116,
            v108,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::LeaderboardDataComparison_LeaderboardName);
      }
    }
  }
}

// File Line: 768
// RVA: 0x42C7E0
UFG::OSuiteLeaderboardData *__fastcall UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingId(UFG::OSuiteLeaderboardManager *this, int id)
{
  unsigned int v2; // er10
  unsigned int v3; // edx
  int v4; // er8
  int v5; // edx
  UFG::OSuiteLeaderboardData *v6; // r11
  __int64 v7; // rax
  unsigned int v8; // er9

  v2 = id;
  v3 = this->mLeaderboardData.size;
  if ( !v3 )
    return 0i64;
  v4 = 0;
  v5 = v3 - 1;
  if ( v5 < 0 )
    return 0i64;
  v6 = this->mLeaderboardData.p;
  while ( 1 )
  {
    v7 = (unsigned int)(v5 + v4) >> 1;
    v8 = v6[v7].mLeaderboardId;
    if ( v8 >= v2 )
      break;
    v4 = v7 + 1;
LABEL_8:
    if ( v4 > v5 )
      return 0i64;
  }
  if ( v8 > v2 )
  {
    v5 = v7 - 1;
    goto LABEL_8;
  }
  return &v6[v7];
}

// File Line: 791
// RVA: 0x42C950
UFG::OSuiteLeaderboardData *__fastcall UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingSliceName(UFG::OSuiteLeaderboardManager *this, const char *sliceName)
{
  UFG::OSuiteLeaderboardManager *v2; // rbx
  UFG::qSymbol *v3; // rax
  unsigned int v4; // er8
  int v5; // er9
  int v6; // er8
  UFG::OSuiteLeaderboardData **v7; // r11
  unsigned int v8; // er10
  __int64 v9; // rdx
  unsigned int v10; // eax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = UFG::qSymbol::create_from_string(&result, sliceName);
  v4 = v2->mLeaderboardData_SortedBySliceName.size;
  if ( !v4 )
    return 0i64;
  v5 = 0;
  v6 = v4 - 1;
  if ( v6 < 0 )
    return 0i64;
  v8 = v3->mUID;
  while ( 1 )
  {
    v9 = (unsigned int)(v6 + v5) >> 1;
    v7 = v2->mLeaderboardData_SortedBySliceName.p;
    v10 = v7[v9]->mSliceName.mUID;
    if ( v10 >= v8 )
      break;
    v5 = v9 + 1;
LABEL_8:
    if ( v5 > v6 )
      return 0i64;
  }
  if ( v10 > v8 )
  {
    v6 = v9 - 1;
    goto LABEL_8;
  }
  return v7[v9];
}

// File Line: 795
// RVA: 0x42C900
UFG::OSuiteLeaderboardData *__fastcall UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingSliceName(UFG::OSuiteLeaderboardManager *this, UFG::qSymbol *key)
{
  unsigned int v2; // er8
  int v3; // er9
  int v4; // er8
  UFG::OSuiteLeaderboardData **v5; // r11
  unsigned int v6; // er10
  __int64 v7; // rcx
  unsigned int v8; // eax

  v2 = this->mLeaderboardData_SortedBySliceName.size;
  if ( !v2 )
    return 0i64;
  v3 = 0;
  v4 = v2 - 1;
  if ( v4 < 0 )
    return 0i64;
  v5 = this->mLeaderboardData_SortedBySliceName.p;
  v6 = key->mUID;
  while ( 1 )
  {
    v7 = (unsigned int)(v4 + v3) >> 1;
    v8 = v5[v7]->mSliceName.mUID;
    if ( v8 >= v6 )
      break;
    v3 = v7 + 1;
LABEL_8:
    if ( v3 > v4 )
      return 0i64;
  }
  if ( v8 > v6 )
  {
    v4 = v7 - 1;
    goto LABEL_8;
  }
  return v5[v7];
}

// File Line: 818
// RVA: 0x42C890
UFG::OSuiteLeaderboardData *__fastcall UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(UFG::OSuiteLeaderboardManager *this, const char *leaderboardName)
{
  UFG::OSuiteLeaderboardManager *v2; // rbx
  UFG::qSymbol *v3; // rax
  unsigned int v4; // er8
  int v5; // er9
  int v6; // er8
  UFG::OSuiteLeaderboardData **v7; // r11
  unsigned int v8; // er10
  __int64 v9; // rdx
  unsigned int v10; // eax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = UFG::qSymbol::create_from_string(&result, leaderboardName);
  v4 = v2->mLeaderboardData_SortedByLeaderboardName.size;
  if ( !v4 )
    return 0i64;
  v5 = 0;
  v6 = v4 - 1;
  if ( v6 < 0 )
    return 0i64;
  v8 = v3->mUID;
  while ( 1 )
  {
    v9 = (unsigned int)(v6 + v5) >> 1;
    v7 = v2->mLeaderboardData_SortedByLeaderboardName.p;
    v10 = v7[v9]->mLeaderboardName.mUID;
    if ( v10 >= v8 )
      break;
    v5 = v9 + 1;
LABEL_8:
    if ( v5 > v6 )
      return 0i64;
  }
  if ( v10 > v8 )
  {
    v6 = v9 - 1;
    goto LABEL_8;
  }
  return v7[v9];
}

// File Line: 822
// RVA: 0x42C840
UFG::OSuiteLeaderboardData *__fastcall UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(UFG::OSuiteLeaderboardManager *this, UFG::qSymbol *key)
{
  unsigned int v2; // er8
  int v3; // er9
  int v4; // er8
  UFG::OSuiteLeaderboardData **v5; // r11
  unsigned int v6; // er10
  __int64 v7; // rcx
  unsigned int v8; // eax

  v2 = this->mLeaderboardData_SortedByLeaderboardName.size;
  if ( !v2 )
    return 0i64;
  v3 = 0;
  v4 = v2 - 1;
  if ( v4 < 0 )
    return 0i64;
  v5 = this->mLeaderboardData_SortedByLeaderboardName.p;
  v6 = key->mUID;
  while ( 1 )
  {
    v7 = (unsigned int)(v4 + v3) >> 1;
    v8 = v5[v7]->mLeaderboardName.mUID;
    if ( v8 >= v6 )
      break;
    v3 = v7 + 1;
LABEL_8:
    if ( v3 > v4 )
      return 0i64;
  }
  if ( v8 > v6 )
  {
    v4 = v7 - 1;
    goto LABEL_8;
  }
  return v5[v7];
}

// File Line: 845
// RVA: 0x430DF0
void __fastcall UFG::OSuiteLeaderboardManager::Shutdown(UFG::OSuiteLeaderboardManager *this)
{
  UFG::OSuiteLeaderboardManager *v1; // rbx

  v1 = this;
  this->m_bExitRequested = 1;
  UFG::qEvent::Signal(&this->m_cThreadEvent);
  UFG::qThread::WaitForCompletion(&v1->m_cUpdateThread);
}

// File Line: 875
// RVA: 0x431490
char __fastcall UFG::OSuiteLeaderboardManager::Update(UFG::OSuiteLeaderboardManager *this, float timeDelta)
{
  UFG::OSuiteLeaderboardManager *v2; // rbx
  void (__fastcall *v3)(OSuite::fastdelegate::detail::GenericClass *); // rax
  char result; // al
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> callback; // [rsp+20h] [rbp-28h]

  v2 = this;
  if ( !UFG::OSuiteManager::Instance()->m_bConnected
    || UFG::OnlineFriendManager::nState != 1
    || !UFG::CachedLeaderboardManager::Instance()->m_bIsCachedLeaderboardBuilt )
  {
    return 0;
  }
  if ( !UFG::OSuiteLeaderboardManager::m_bIsFriendsScoresInserted && v2->m_rTimerForFriendsScores > 30.0 )
  {
    callback.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)UFG::OSuiteLeaderboardManager::GetTopFriendsStatScoresCallback;
    v3 = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>::InvokeStaticFunction;
    if ( !UFG::OSuiteLeaderboardManager::GetTopFriendsStatScoresCallback )
      v3 = 0i64;
    callback.m_Closure.m_pFunction = v3;
    UFG::OSuiteLeaderboardManager::GetTopFriendsStatScores(v2, &callback);
    v2->m_rTimerForFriendsScores = 0.0;
  }
  result = 1;
  v2->m_rTimerForFriendsScores = timeDelta + v2->m_rTimerForFriendsScores;
  return result;
}

// File Line: 894
// RVA: 0x42F180
char __fastcall UFG::OSuiteLeaderboardManager::QueueUpdateEvent(UFG::OSuiteLeaderboardManager *this, UFG::OSuiteLeaderboardManager::UpdateEvent *entry)
{
  UFG::OSuiteLeaderboardManager::UpdateEvent *v2; // rbx
  UFG::OSuiteLeaderboardManager *v3; // rdi
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v4; // rax
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v5; // rdx
  signed __int64 v6; // r9

  v2 = entry;
  v3 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->m_cMutex);
  v4 = v3->m_updateEvents.mNode.mPrev;
  v5 = (UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *)&v2->mPrev;
  v6 = (signed __int64)&v3->m_updateEvents.mNode.mNext[-1].mNext;
  v4->mNext = (UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *)&v2->mPrev;
  v5->mPrev = v4;
  v5->mNext = &v3->m_updateEvents.mNode;
  v3->m_updateEvents.mNode.mPrev = (UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *)&v2->mPrev;
  if ( (OSuite::ZWebServiceClient **)v6 == &v3->m_pWebServiceClient )
    UFG::qEvent::Signal(&v3->m_cThreadEvent);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->m_cMutex);
  return 1;
}

// File Line: 910
// RVA: 0x435560
void __fastcall UFG::OSuiteLeaderboardManager::UploadStatAwardResult(UFG::OSuiteLeaderboardManager *this, UFG::OSuiteLeaderboardData *pLBD, int score, void (__fastcall *callback)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, UFG::OSuiteLeaderboardData *))
{
  void (__fastcall *v4)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, UFG::OSuiteLeaderboardData *); // rbp
  int v5; // er14
  UFG::OSuiteLeaderboardData *v6; // rbx
  UFG::OSuiteLeaderboardManager *v7; // rsi
  char v8; // di
  UFG::GameStatTracker *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdx
  UFG::allocator::free_link *v12; // rax

  v4 = callback;
  v5 = score;
  v6 = pLBD;
  v7 = this;
  if ( pLBD->mCategory == LeaderboardCategory_StatAward )
  {
    v8 = 1;
    if ( !UFG::OSuiteManager::Instance()->m_bConnected )
      v8 = 0;
    v9 = UFG::GameStatTracker::Instance();
    if ( (signed int)UFG::GameStatTracker::GetStat(v9, IsBannedByCommunityManager) <= 0 && v8 )
    {
      v10 = UFG::qMalloc(0x38ui64, "OSuiteLeaderboardManager", 0i64);
      v11 = v10;
      if ( v10 )
      {
        v12 = v10 + 1;
        v12->mNext = v12;
        v12[1].mNext = v12;
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable';
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::Score::`vftable';
        v11[4].mNext = (UFG::allocator::free_link *)v6;
        LODWORD(v11[5].mNext) = v5;
        v11[6].mNext = (UFG::allocator::free_link *)v4;
        LODWORD(v11[3].mNext) = 0;
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::StatAwardScore::`vftable';
      }
      else
      {
        v11 = 0i64;
      }
      UFG::OSuiteLeaderboardManager::QueueUpdateEvent(v7, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v11);
    }
  }
}

// File Line: 923
// RVA: 0x435650
void __fastcall UFG::OSuiteLeaderboardManager::UploadStatGameResult(UFG::OSuiteLeaderboardManager *this, UFG::OSuiteLeaderboardData *pLBD, int score, void (__fastcall *callback)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, UFG::OSuiteLeaderboardData *))
{
  void (__fastcall *v4)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, UFG::OSuiteLeaderboardData *); // rbp
  int v5; // er14
  UFG::OSuiteLeaderboardData *v6; // rbx
  UFG::OSuiteLeaderboardManager *v7; // rsi
  char v8; // di
  UFG::GameStatTracker *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdx
  UFG::allocator::free_link *v12; // rax

  v4 = callback;
  v5 = score;
  v6 = pLBD;
  v7 = this;
  if ( pLBD->mCategory == 1 )
  {
    v8 = 1;
    if ( !UFG::OSuiteManager::Instance()->m_bConnected )
      v8 = 0;
    v9 = UFG::GameStatTracker::Instance();
    if ( (signed int)UFG::GameStatTracker::GetStat(v9, IsBannedByCommunityManager) <= 0 && v8 )
    {
      v10 = UFG::qMalloc(0x38ui64, "OSuiteLeaderboardManager", 0i64);
      v11 = v10;
      if ( v10 )
      {
        v12 = v10 + 1;
        v12->mNext = v12;
        v12[1].mNext = v12;
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable';
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::Score::`vftable';
        v11[4].mNext = (UFG::allocator::free_link *)v6;
        LODWORD(v11[5].mNext) = v5;
        v11[6].mNext = (UFG::allocator::free_link *)v4;
        LODWORD(v11[3].mNext) = 1;
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::StatGameScore::`vftable';
      }
      else
      {
        v11 = 0i64;
      }
      UFG::OSuiteLeaderboardManager::QueueUpdateEvent(v7, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v11);
    }
  }
}

// File Line: 936
// RVA: 0x435250
void __fastcall UFG::OSuiteLeaderboardManager::UploadMissionResult(UFG::OSuiteLeaderboardManager *this, UFG::OSuiteLeaderboardData *pLBD, int score, void (__fastcall *callback)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, UFG::OSuiteLeaderboardData *))
{
  void (__fastcall *v4)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, UFG::OSuiteLeaderboardData *); // rbp
  int v5; // er14
  UFG::OSuiteLeaderboardData *v6; // rbx
  UFG::OSuiteLeaderboardManager *v7; // rsi
  char v8; // di
  UFG::GameStatTracker *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdx
  UFG::allocator::free_link *v12; // rax

  v4 = callback;
  v5 = score;
  v6 = pLBD;
  v7 = this;
  if ( pLBD->mCategory == 2 )
  {
    v8 = 1;
    if ( !UFG::OSuiteManager::Instance()->m_bConnected )
      v8 = 0;
    v9 = UFG::GameStatTracker::Instance();
    if ( (signed int)UFG::GameStatTracker::GetStat(v9, IsBannedByCommunityManager) <= 0 && v8 )
    {
      v10 = UFG::qMalloc(0x38ui64, "OSuiteLeaderboardManager", 0i64);
      v11 = v10;
      if ( v10 )
      {
        v12 = v10 + 1;
        v12->mNext = v12;
        v12[1].mNext = v12;
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable';
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::Score::`vftable';
        v11[4].mNext = (UFG::allocator::free_link *)v6;
        LODWORD(v11[5].mNext) = v5;
        v11[6].mNext = (UFG::allocator::free_link *)v4;
        LODWORD(v11[3].mNext) = 2;
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::MissionScore::`vftable';
      }
      else
      {
        v11 = 0i64;
      }
      UFG::OSuiteLeaderboardManager::QueueUpdateEvent(v7, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v11);
    }
  }
}

// File Line: 949
// RVA: 0x435480
void __fastcall UFG::OSuiteLeaderboardManager::UploadRaceResult(UFG::OSuiteLeaderboardManager *this, UFG::OSuiteLeaderboardData *pLBD, int raceTime, bool isWin, const char *carUsed, void (__fastcall *callback)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, UFG::OSuiteLeaderboardData *))
{
  bool v6; // r14
  int v7; // er15
  UFG::OSuiteLeaderboardData *v8; // rdi
  UFG::OSuiteLeaderboardManager *v9; // rbp
  char v10; // si
  UFG::OSuiteLeaderboardManager::UpdateEvent *v11; // rbx
  UFG::GameStatTracker *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::OSuiteLeaderboardManager::UpdateEvent *v14; // rax

  v6 = isWin;
  v7 = raceTime;
  v8 = pLBD;
  v9 = this;
  if ( pLBD->mCategory == 3 )
  {
    v10 = 1;
    v11 = 0i64;
    if ( !UFG::OSuiteManager::Instance()->m_bConnected )
      v10 = 0;
    v12 = UFG::GameStatTracker::Instance();
    if ( (signed int)UFG::GameStatTracker::GetStat(v12, IsBannedByCommunityManager) <= 0 && v10 )
    {
      v13 = UFG::qMalloc(0x68ui64, "OSuiteLeaderboardManager", 0i64);
      if ( v13 )
      {
        UFG::OSuiteLeaderboardManager::RaceScore::RaceScore(
          (UFG::OSuiteLeaderboardManager::RaceScore *)v13,
          v8,
          v7,
          v6,
          carUsed,
          callback);
        v11 = v14;
      }
      UFG::OSuiteLeaderboardManager::QueueUpdateEvent(v9, v11);
    }
  }
}

// File Line: 962
// RVA: 0x42AE80
void __fastcall UFG::OSuiteLeaderboardManager::CommandCB(UFG::OSuiteLeaderboardManager *this, OSuite::SCallbackData *pData, OSuite::ZWebServiceClient *pWebServiceClient)
{
  OSuite::SCallbackData *v3; // rbx
  OSuite::ZWebServiceClient *v4; // rsi
  UFG::OSuiteLeaderboardManager *v5; // rbp
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v6; // r10
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v7; // rax
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v8; // r9
  signed __int64 v9; // rdi
  int v10; // eax
  OSuite::ZOEntry *v11; // rax
  OSuite::ZOProperty *v12; // rax
  int v13; // ebx
  UFG::GameStatTracker *v14; // rax
  void (__fastcall *v15)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, _QWORD); // rax
  UFG::UIScreenTextureManager *v16; // rax
  int v17; // ebx
  UFG::GameSaveLoad *v18; // rax
  UFG::ProgressionTracker *v19; // rax
  UFG::ProgressionTracker::ActiveMasterMode v20; // ebx
  UFG::ProgressionTracker::State v21; // edi
  bool v22; // al
  UFG::GameSaveLoad *v23; // rax
  bool outValue; // [rsp+40h] [rbp+8h]

  v3 = pData;
  v4 = pWebServiceClient;
  v5 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->m_cMutex);
  v6 = v5->m_updateEvents.mNode.mNext;
  v7 = v6->mNext;
  v8 = v6->mPrev;
  v9 = (signed __int64)&v6[-1].mNext;
  v8->mNext = v7;
  v7->mPrev = v8;
  v6->mPrev = v6;
  v6->mNext = v6;
  v10 = (int)v6[1].mPrev;
  switch ( v10 )
  {
    case 4:
      if ( v3->Status.eError == HTTPERROR_OK )
        UFG::OSuiteLeaderboardManager::ScanOrResetPlayerStats(0i64);
      break;
    case 6:
      if ( v3->Status.eError == HTTPERROR_OK )
      {
        v11 = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOEntry>(v4, &v3->URL);
        if ( v11 )
        {
          v12 = OSuite::ZOEntry::Property(v11, "b_Banned");
          if ( v12 )
          {
            outValue = 0;
            OSuite::ZOProperty::GetValue(v12, &outValue);
            v13 = outValue != 0;
            v14 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::SetStat(v14, IsBannedByCommunityManager, v13);
          }
        }
      }
      break;
    case 7:
      (*(void (__fastcall **)(_QWORD, OSuite::SCallbackData *, OSuite::ZWebServiceClient *))(v9 + 56))(
        *(_QWORD *)(v9 + 48),
        v3,
        v4);
      break;
    case 8:
      (*(void (__fastcall **)(_QWORD, OSuite::SCallbackData *, OSuite::ZWebServiceClient *))(v9 + 56))(
        *(_QWORD *)(v9 + 48),
        v3,
        v4);
      break;
    case 9:
      (*(void (__fastcall **)(_QWORD, OSuite::SCallbackData *, OSuite::ZWebServiceClient *))(v9 + 40))(
        *(_QWORD *)(v9 + 32),
        v3,
        v4);
      break;
    case 10:
      (*(void (__fastcall **)(_QWORD, OSuite::SCallbackData *, OSuite::ZWebServiceClient *))(v9 + 40))(
        *(_QWORD *)(v9 + 32),
        v3,
        v4);
      break;
    case 11:
      (*(void (__fastcall **)(_QWORD, OSuite::SCallbackData *, OSuite::ZWebServiceClient *))(v9 + 56))(
        *(_QWORD *)(v9 + 48),
        v3,
        v4);
      break;
    default:
      v15 = *(void (__fastcall **)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, _QWORD))(v9 + 48);
      if ( v15 )
        v15(v3, v4, *(_QWORD *)(v9 + 32));
      break;
  }
  (**(void (__fastcall ***)(signed __int64, signed __int64))v9)(v9, 1i64);
  if ( v5->m_bQueueOptionsSave )
  {
    if ( (OSuite::ZWebServiceClient **)&v5->m_updateEvents.mNode.mNext[-1].mNext == &v5->m_pWebServiceClient )
    {
      v16 = UFG::UIScreenTextureManager::Instance();
      v17 = UFG::UIScreenTextureManager::GetGameState(v16);
      v18 = UFG::GameSaveLoad::Instance();
      if ( UFG::GameSaveLoad::IsSaveAvaliable(v18) && v17 == 2 )
      {
        v19 = UFG::ProgressionTracker::Instance();
        v20 = v19->mActiveMasterMode;
        v21 = v19->mState;
        v22 = UFG::UIScreenManagerBase::getScreen(
                (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                "GarageBrowser") != 0i64;
        if ( v20 == ActiveMasterMode_OpenWorld && v21 == 3 && !v22 )
        {
          v23 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::SaveAutoGameSlot(v23);
          v5->m_bQueueOptionsSave = 0;
        }
      }
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v5->m_cMutex);
  UFG::qEvent::Signal(&v5->m_cThreadEvent);
}

// File Line: 1042
// RVA: 0x4321F0
void __fastcall UFG::OSuiteLeaderboardManager::UpdateThread(void *param)
{
  char *v1; // r14
  char *v2; // rbx
  UFG::OnlineId *v3; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v4; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v5; // rax
  __int64 v6; // rsi
  int v7; // eax
  signed __int64 v8; // rax
  unsigned __int8 v9; // cf
  unsigned __int64 v10; // rax
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v11; // rax
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **v12; // rbx
  unsigned int v13; // eax
  signed __int64 v14; // rbx
  unsigned __int64 v15; // rax
  OSuite::ZRedBlackTreeBase *v16; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v17; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v18; // rax
  unsigned __int64 v19; // rax
  unsigned int v20; // eax
  signed __int64 v21; // rbx
  unsigned __int64 v22; // rax
  OSuite::ZRedBlackTreeBase *v23; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v24; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v25; // rax
  unsigned __int64 v26; // rax
  OSuite::ZOQuery *v27; // rcx
  signed __int64 v28; // rax
  unsigned __int64 v29; // rax
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v30; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v31; // rbx
  unsigned int v32; // eax
  __int64 v33; // rbx
  unsigned __int64 v34; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v35; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v36; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v37; // rax
  unsigned __int64 v38; // rax
  signed __int64 v39; // rax
  unsigned __int64 v40; // rax
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v41; // rax
  void **v42; // rbx
  unsigned int v43; // eax
  signed __int64 v44; // rbx
  unsigned __int64 v45; // rax
  OSuite::ZRedBlackTreeBase *v46; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v47; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v48; // rax
  unsigned __int64 v49; // rax
  OSuite::ZString *v50; // rax
  OSuite::ZString *v51; // rdi
  unsigned int v52; // eax
  signed __int64 v53; // rbx
  unsigned __int64 v54; // rax
  unsigned __int64 v55; // rax
  signed __int64 v56; // rax
  unsigned __int64 v57; // rax
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v58; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v59; // rbx
  unsigned int v60; // eax
  __int64 v61; // rbx
  unsigned __int64 v62; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v63; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v64; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v65; // rax
  unsigned __int64 v66; // rax
  OSuite::ZString *v67; // rax
  OSuite::ZString *v68; // rdi
  unsigned int v69; // eax
  __int64 v70; // rbx
  unsigned __int64 v71; // rax
  unsigned __int64 v72; // rax
  signed __int64 v73; // rax
  unsigned __int64 v74; // rax
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v75; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v76; // rbx
  unsigned int v77; // eax
  __int64 v78; // rbx
  unsigned __int64 v79; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v80; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v81; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v82; // rax
  unsigned __int64 v83; // rax
  unsigned int v84; // eax
  __int64 v85; // rbx
  unsigned __int64 v86; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v87; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v88; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v89; // rax
  unsigned __int64 v90; // rax
  int v91; // ecx
  const char *v92; // rbx
  int v93; // ecx
  int v94; // ecx
  unsigned int v95; // eax
  __int64 v96; // rdi
  unsigned __int64 v97; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v98; // r15
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v99; // rax
  unsigned __int64 v100; // rax
  unsigned int v101; // eax
  __int64 v102; // rbx
  unsigned __int64 v103; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v104; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v105; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v106; // rax
  unsigned __int64 v107; // rax
  OSuite::ZString *v108; // rax
  OSuite::ZString *v109; // rdi
  unsigned int v110; // eax
  __int64 v111; // rbx
  unsigned __int64 v112; // rax
  unsigned __int64 v113; // rax
  OSuite::ZString *v114; // rax
  OSuite::ZString *v115; // rdi
  unsigned int v116; // eax
  __int64 v117; // rbx
  unsigned __int64 v118; // rax
  unsigned __int64 v119; // rax
  unsigned int v120; // eax
  __int64 v121; // rbx
  unsigned __int64 v122; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v123; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v124; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v125; // rax
  unsigned __int64 v126; // rax
  UFG::OnlineManager *v127; // rax
  UFG::qString *v128; // rax
  unsigned int v129; // eax
  __int64 v130; // rbx
  unsigned __int64 v131; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v132; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v133; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v134; // rax
  unsigned __int64 v135; // rax
  Region v136; // eax
  const char *v137; // rax
  unsigned int v138; // eax
  __int64 v139; // rbx
  unsigned __int64 v140; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v141; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v142; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v143; // rax
  unsigned __int64 v144; // rax
  OSuite::ZString *v145; // rax
  OSuite::ZString *v146; // rdi
  unsigned int v147; // eax
  __int64 v148; // rbx
  unsigned __int64 v149; // rax
  unsigned __int64 v150; // rax
  OSuite::ZString *v151; // rax
  OSuite::ZString *v152; // rdi
  unsigned int v153; // eax
  __int64 v154; // rbx
  unsigned __int64 v155; // rax
  unsigned __int64 v156; // rax
  int v157; // ecx
  int v158; // ecx
  int v159; // ecx
  OSuite::ZString *v160; // rax
  OSuite::ZString *v161; // rdi
  unsigned int v162; // eax
  __int64 v163; // rbx
  unsigned __int64 v164; // rax
  unsigned __int64 v165; // rax
  const char *v166; // rdx
  unsigned int v167; // eax
  __int64 v168; // rbx
  unsigned __int64 v169; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v170; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v171; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v172; // rax
  unsigned __int64 v173; // rax
  unsigned int v174; // eax
  __int64 v175; // rbx
  unsigned __int64 v176; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v177; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v178; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v179; // rax
  unsigned __int64 v180; // rax
  const char *v181; // rdx
  OSuite::ZString *v182; // rax
  OSuite::ZString *v183; // rdi
  unsigned int v184; // eax
  __int64 v185; // rbx
  unsigned __int64 v186; // rax
  unsigned __int64 v187; // rax
  unsigned int v188; // eax
  __int64 v189; // rbx
  unsigned __int64 v190; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v191; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v192; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v193; // rax
  unsigned __int64 v194; // rax
  OSuite::ZString *v195; // rax
  OSuite::ZString *v196; // rdi
  unsigned int v197; // eax
  __int64 v198; // rbx
  unsigned __int64 v199; // rax
  unsigned __int64 v200; // rax
  unsigned int v201; // eax
  __int64 v202; // rbx
  unsigned __int64 v203; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v204; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v205; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v206; // rax
  unsigned __int64 v207; // rax
  OSuite::ZString *v208; // rax
  OSuite::ZString *v209; // rdi
  unsigned int v210; // eax
  __int64 v211; // rbx
  unsigned __int64 v212; // rax
  unsigned __int64 v213; // rax
  OSuite::TMap<OSuite::ZString,OSuite::ZString> v214; // [rsp+30h] [rbp-A8h]
  OSuite::TMap<OSuite::ZString,OSuite::ZString> params; // [rsp+50h] [rbp-88h]
  void **v216; // [rsp+70h] [rbp-68h]
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **v217; // [rsp+78h] [rbp-60h]
  __int64 v218; // [rsp+80h] [rbp-58h]
  OSuite::TMap<OSuite::ZString,OSuite::ZString> v219; // [rsp+88h] [rbp-50h]
  OSuite::TMap<OSuite::ZString,OSuite::ZString> v220; // [rsp+A8h] [rbp-30h]
  OSuite::TMap<OSuite::ZString,OSuite::ZString> v221; // [rsp+C8h] [rbp-10h]
  OSuite::TMap<OSuite::ZString,OSuite::ZString> v222; // [rsp+E8h] [rbp+10h]
  UFG::OnlineId result; // [rsp+108h] [rbp+30h]
  UFG::qString v224; // [rsp+120h] [rbp+48h]
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> v225; // [rsp+148h] [rbp+70h]
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> v226; // [rsp+158h] [rbp+80h]
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> v227; // [rsp+168h] [rbp+90h]
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> cb; // [rsp+178h] [rbp+A0h]
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> v229; // [rsp+188h] [rbp+B0h]
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> v230; // [rsp+198h] [rbp+C0h]
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> v231; // [rsp+1A8h] [rbp+D0h]
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> v232; // [rsp+1B8h] [rbp+E0h]
  OSuite::ZString v233; // [rsp+1C8h] [rbp+F0h]
  OSuite::ZString v234; // [rsp+1E0h] [rbp+108h]
  OSuite::ZString v235; // [rsp+1F8h] [rbp+120h]
  OSuite::ZString key; // [rsp+210h] [rbp+138h]
  OSuite::ZString v237; // [rsp+228h] [rbp+150h]
  OSuite::ZString v238; // [rsp+240h] [rbp+168h]
  OSuite::ZString v239; // [rsp+258h] [rbp+180h]
  OSuite::ZString v240; // [rsp+270h] [rbp+198h]
  OSuite::ZString v241; // [rsp+288h] [rbp+1B0h]
  OSuite::ZString v242; // [rsp+2A0h] [rbp+1C8h]
  OSuite::ZString v243; // [rsp+2B8h] [rbp+1E0h]
  OSuite::ZString v244; // [rsp+2D0h] [rbp+1F8h]
  OSuite::ZString that; // [rsp+2E8h] [rbp+210h]
  OSuite::ZString v246; // [rsp+300h] [rbp+228h]
  OSuite::ZString v247; // [rsp+318h] [rbp+240h]
  OSuite::ZString v248; // [rsp+330h] [rbp+258h]
  OSuite::ZString v249; // [rsp+348h] [rbp+270h]
  OSuite::ZString v250; // [rsp+360h] [rbp+288h]
  OSuite::ZString v251; // [rsp+378h] [rbp+2A0h]
  OSuite::ZString v252; // [rsp+390h] [rbp+2B8h]
  OSuite::ZString v253; // [rsp+3A8h] [rbp+2D0h]
  OSuite::ZString v254; // [rsp+3C0h] [rbp+2E8h]
  OSuite::ZString v255; // [rsp+3D8h] [rbp+300h]
  OSuite::ZString v256; // [rsp+3F0h] [rbp+318h]
  OSuite::ZString v257; // [rsp+408h] [rbp+330h]
  OSuite::ZString v258; // [rsp+420h] [rbp+348h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v259; // [rsp+438h] [rbp+360h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v260; // [rsp+470h] [rbp+398h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> data; // [rsp+4A8h] [rbp+3D0h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v262; // [rsp+4E0h] [rbp+408h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v263; // [rsp+518h] [rbp+440h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v264; // [rsp+550h] [rbp+478h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v265; // [rsp+588h] [rbp+4B0h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v266; // [rsp+5C0h] [rbp+4E8h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v267; // [rsp+5F8h] [rbp+520h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v268; // [rsp+630h] [rbp+558h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v269; // [rsp+668h] [rbp+590h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v270; // [rsp+6A0h] [rbp+5C8h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v271; // [rsp+6D8h] [rbp+600h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v272; // [rsp+710h] [rbp+638h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v273; // [rsp+748h] [rbp+670h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v274; // [rsp+780h] [rbp+6A8h]
  OSuite::ZString v275; // [rsp+7B8h] [rbp+6E0h]
  OSuite::ZString v276; // [rsp+7D0h] [rbp+6F8h]
  OSuite::ZString v277; // [rsp+7E8h] [rbp+710h]
  OSuite::ZString v278; // [rsp+800h] [rbp+728h]
  OSuite::ZString v279; // [rsp+818h] [rbp+740h]
  OSuite::ZString v280; // [rsp+830h] [rbp+758h]
  OSuite::ZString v281; // [rsp+848h] [rbp+770h]
  OSuite::ZString v282; // [rsp+860h] [rbp+788h]
  OSuite::ZString v283; // [rsp+878h] [rbp+7A0h]
  OSuite::ZString v284; // [rsp+890h] [rbp+7B8h]
  __int64 v285; // [rsp+8A8h] [rbp+7D0h]
  OSuite::ZString v286; // [rsp+8B0h] [rbp+7D8h]
  OSuite::ZString v287; // [rsp+8C8h] [rbp+7F0h]
  OSuite::ZString v288; // [rsp+8E0h] [rbp+808h]
  OSuite::ZString v289; // [rsp+8F8h] [rbp+820h]
  OSuite::ZString v290; // [rsp+910h] [rbp+838h]
  OSuite::ZString v291; // [rsp+928h] [rbp+850h]
  OSuite::ZString v292; // [rsp+940h] [rbp+868h]
  OSuite::ZString v293; // [rsp+958h] [rbp+880h]
  OSuite::ZString v294; // [rsp+970h] [rbp+898h]
  OSuite::ZString v295; // [rsp+988h] [rbp+8B0h]
  OSuite::ZString v296; // [rsp+9A0h] [rbp+8C8h]
  OSuite::ZString v297; // [rsp+9B8h] [rbp+8E0h]
  OSuite::ZString v298; // [rsp+9D0h] [rbp+8F8h]
  OSuite::ZString v299; // [rsp+9E8h] [rbp+910h]
  OSuite::ZString v300; // [rsp+A00h] [rbp+928h]
  OSuite::ZString v301; // [rsp+A18h] [rbp+940h]
  OSuite::ZOQuery v302; // [rsp+A38h] [rbp+960h]
  UFG::qString v303; // [rsp+AA8h] [rbp+9D0h]
  OSuite::ZOQuery v304; // [rsp+AD8h] [rbp+A00h]
  OSuite::ZOQuery v305; // [rsp+B48h] [rbp+A70h]
  OSuite::ZOQuery v306; // [rsp+BB8h] [rbp+AE0h]
  OSuite::ZOQuery query; // [rsp+C28h] [rbp+B50h]
  OSuite::ZOQuery v308; // [rsp+C98h] [rbp+BC0h]
  OSuite::ZOQuery v309; // [rsp+D08h] [rbp+C30h]
  OSuite::ZOQuery v310; // [rsp+D78h] [rbp+CA0h]
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v311; // [rsp+E18h] [rbp+D40h]

  v285 = -2i64;
  v1 = (char *)param;
  if ( !*((_BYTE *)param + 101) )
  {
    v2 = (char *)param + 72;
    do
    {
      if ( !(_S5_9 & 1) )
      {
        _S5_9 |= 1u;
        instance.vfptr = (UFG::OnlineManagerVtbl *)&UFG::OnlineManager::`vftable';
        unk_1424011B8 = 0;
        v311 = &stru_1424011C0;
        stru_1424011C0.mNode.mPrev = (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *)&stru_1424011C0;
        stru_1424011C0.mNode.mNext = (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *)&stru_1424011C0;
        UFG::qString::qString(&stru_1424011D0);
        atexit(UFG::OnlineManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
      }
      v3 = UFG::OnlineManager::GetOnlineId(&instance, &result);
      UFG::OnlineId::ToString(v3, &v224);
      v4 = result.mPrev;
      v5 = result.mNext;
      result.mPrev->mNext = result.mNext;
      v5->mPrev = v4;
      result.mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&result;
      result.mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&result;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)(v1 + 104));
      if ( (char *)(*((_QWORD *)v1 + 11) - 8i64) == v2 || v224.mLength <= 0 )
        goto LABEL_156;
      v6 = *((_QWORD *)v1 + 11);
      v7 = *(_DWORD *)(v6 + 16);
      switch ( v7 )
      {
        case 4:
          OSuite::ZOQuery::ZOQuery(&query);
          v216 = &OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable';
          LODWORD(params.m_pLists) = 16;
          *(_QWORD *)&params.m_nHashSize = 0i64;
          v8 = 640i64;
          if ( !is_mul_ok(0x10ui64, 0x28ui64) )
            v8 = -1i64;
          v9 = __CFADD__(v8, 8i64);
          v10 = v8 + 8;
          if ( v9 )
            v10 = -1i64;
          v11 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)OSuite::ZObject::operator new(v10);
          v311 = v11;
          if ( v11 )
          {
            LODWORD(v11->mNode.mPrev) = 16;
            v12 = &v11->mNode.mNext;
            `eh vector constructor iterator'(
              &v11->mNode.mNext,
              0x28ui64,
              16,
              (void (__fastcall *)(void *))OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>);
          }
          else
          {
            v12 = 0i64;
          }
          v217 = v12;
          OSuite::ZString::ZString(&v278, v224.mData);
          OSuite::ZString::ZString(&that, "s_Pid");
          v13 = that.vfptr->ComputeHash((OSuite::IHashable *)&that.vfptr);
          v14 = 5i64 * (signed int)((LODWORD(params.m_pLists) - 1) & v13);
          v15 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v217[v14]);
          *(_QWORD *)&params.m_nHashSize -= v15;
          v16 = (OSuite::ZRedBlackTreeBase *)&v217[v14];
          data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::ZString(&data.m_First, &that);
          OSuite::ZString::ZString(&data.m_Second, &v278);
          data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
          v17 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v17;
          if ( v17 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v17,
              &data);
          else
            v18 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet(v16, v18);
          data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::~ZString(&data.m_Second);
          OSuite::ZString::~ZString(&data.m_First);
          v19 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v217[v14]);
          *(_QWORD *)&params.m_nHashSize += v19;
          OSuite::ZString::~ZString(&that);
          OSuite::ZString::~ZString(&v278);
          OSuite::ZString::ZString(&v288, **(const char ***)(v6 + 24));
          OSuite::ZString::ZString(&v246, "s_Stats");
          v20 = v246.vfptr->ComputeHash((OSuite::IHashable *)&v246.vfptr);
          v21 = 5i64 * (signed int)((LODWORD(params.m_pLists) - 1) & v20);
          v22 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v217[v21]);
          *(_QWORD *)&params.m_nHashSize -= v22;
          v23 = (OSuite::ZRedBlackTreeBase *)&v217[v21];
          v271.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::ZString(&v271.m_First, &v246);
          OSuite::ZString::ZString(&v271.m_Second, &v288);
          v271.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
          v24 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v24;
          if ( v24 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v24,
              &v271);
          else
            v25 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet(v23, v25);
          v271.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::~ZString(&v271.m_Second);
          OSuite::ZString::~ZString(&v271.m_First);
          v26 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v217[v21]);
          *(_QWORD *)&params.m_nHashSize += v26;
          OSuite::ZString::~ZString(&v246);
          OSuite::ZString::~ZString(&v288);
          OSuite::ZOQuery::ServiceOperation(
            &query,
            "UpdatePlayersStats",
            (OSuite::TMap<OSuite::ZString,OSuite::ZString> *)&v216);
          cb.m_Closure.m_pthis = 0i64;
          cb.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteLeaderboardManager::CommandCB;
          cb.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(v1);
          OSuite::ZWebServiceClient::ExecuteQuery(*((OSuite::ZWebServiceClient **)v1 + 9), &query, &cb);
          v216 = &OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable';
          if ( v217 )
          {
            if ( *((_DWORD *)v217 - 2) )
              ((void (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **, signed __int64))(*v217)->mPrev)(
                v217,
                3i64);
            else
              operator delete[](v217 - 1);
          }
          v27 = &query;
          break;
        case 6:
          OSuite::ZOQuery::ZOQuery(&v309);
          v221.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable';
          v221.m_nHashSize = 16;
          v221.m_nCount = 0i64;
          v28 = 640i64;
          if ( !is_mul_ok(0x10ui64, 0x28ui64) )
            v28 = -1i64;
          v9 = __CFADD__(v28, 8i64);
          v29 = v28 + 8;
          if ( v9 )
            v29 = -1i64;
          v30 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)OSuite::ZObject::operator new(v29);
          v311 = v30;
          if ( v30 )
          {
            LODWORD(v30->mNode.mPrev) = 16;
            v31 = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *)&v30->mNode.mNext;
            `eh vector constructor iterator'(
              &v30->mNode.mNext,
              0x28ui64,
              16,
              (void (__fastcall *)(void *))OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>);
          }
          else
          {
            v31 = 0i64;
          }
          v221.m_pLists = v31;
          OSuite::ZString::ZString(&v280, v224.mData);
          OSuite::ZString::ZString(&v248, "s_Pid");
          v32 = v248.vfptr->ComputeHash((OSuite::IHashable *)&v248.vfptr);
          v33 = (signed int)((v221.m_nHashSize - 1) & v32);
          v34 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v221.m_pLists[v33].vfptr);
          v221.m_nCount -= v34;
          v35 = &v221.m_pLists[v33];
          v263.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::ZString(&v263.m_First, &v248);
          OSuite::ZString::ZString(&v263.m_Second, &v280);
          v263.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
          v36 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v36;
          if ( v36 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v36,
              &v263);
          else
            v37 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet((OSuite::ZRedBlackTreeBase *)&v35->vfptr, v37);
          v263.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::~ZString(&v263.m_Second);
          OSuite::ZString::~ZString(&v263.m_First);
          v38 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v221.m_pLists[v33].vfptr);
          v221.m_nCount += v38;
          OSuite::ZString::~ZString(&v248);
          OSuite::ZString::~ZString(&v280);
          OSuite::ZOQuery::ServiceOperation(&v309, "GetBanStatus", &v221);
          v230.m_Closure.m_pthis = 0i64;
          v230.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteLeaderboardManager::CommandCB;
          v230.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(v1);
          OSuite::ZWebServiceClient::ExecuteQuery(*((OSuite::ZWebServiceClient **)v1 + 9), &v309, &v230);
          v221.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable';
          if ( v221.m_pLists )
          {
            if ( LODWORD(v221.m_pLists[-1].m_Comparer.vfptr) )
              v221.m_pLists->vfptr->__vecDelDtor((OSuite::ZObject *)v221.m_pLists, 3u);
            else
              operator delete[](&v221.m_pLists[-1].m_Comparer.vfptr);
          }
          v27 = &v309;
          break;
        case 7:
          OSuite::ZOQuery::ZOQuery(&v304);
          params.m_nCount = (unsigned __int64)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable';
          LODWORD(v217) = 16;
          v218 = 0i64;
          v39 = 640i64;
          if ( !is_mul_ok(0x10ui64, 0x28ui64) )
            v39 = -1i64;
          v9 = __CFADD__(v39, 8i64);
          v40 = v39 + 8;
          if ( v9 )
            v40 = -1i64;
          v41 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)OSuite::ZObject::operator new(v40);
          v311 = v41;
          if ( v41 )
          {
            LODWORD(v41->mNode.mPrev) = 16;
            v42 = (void **)&v41->mNode.mNext;
            `eh vector constructor iterator'(
              &v41->mNode.mNext,
              0x28ui64,
              16,
              (void (__fastcall *)(void *))OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>);
          }
          else
          {
            v42 = 0i64;
          }
          v216 = v42;
          OSuite::ZString::ZString(&v286, v224.mData);
          OSuite::ZString::ZString(&v234, "s_Pid");
          v43 = v234.vfptr->ComputeHash((OSuite::IHashable *)&v234.vfptr);
          v44 = 5i64 * (signed int)(((_DWORD)v217 - 1) & v43);
          v45 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v216[v44]);
          v218 -= v45;
          v46 = (OSuite::ZRedBlackTreeBase *)&v216[v44];
          v269.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::ZString(&v269.m_First, &v234);
          OSuite::ZString::ZString(&v269.m_Second, &v286);
          v269.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
          v47 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v47;
          if ( v47 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v47,
              &v269);
          else
            v48 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet(v46, v48);
          v269.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::~ZString(&v269.m_Second);
          OSuite::ZString::~ZString(&v269.m_First);
          v49 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v216[v44]);
          v218 += v49;
          OSuite::ZString::~ZString(&v234);
          OSuite::ZString::~ZString(&v286);
          OSuite::ZString::ZString(&key, "i32_LB");
          OSuite::ZString::ZString(&v295, *(_DWORD *)(*(_QWORD *)(v6 + 24) + 4i64));
          v51 = v50;
          v52 = key.vfptr->ComputeHash((OSuite::IHashable *)&key.vfptr);
          v53 = 5i64 * (signed int)(v52 & ((_DWORD)v217 - 1));
          v54 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v216[v53]);
          v218 -= v54;
          OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
            (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *)&v216[v53],
            &key,
            v51);
          v55 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v216[v53]);
          v218 += v55;
          OSuite::ZString::~ZString(&v295);
          OSuite::ZString::~ZString(&key);
          OSuite::ZOQuery::ServiceOperation(
            &v304,
            *(const char **)(v6 + 32),
            (OSuite::TMap<OSuite::ZString,OSuite::ZString> *)((char *)&params + 24));
          v232.m_Closure.m_pthis = 0i64;
          v232.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteLeaderboardManager::CommandCB;
          v232.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(v1);
          OSuite::ZWebServiceClient::ExecuteQuery(*((OSuite::ZWebServiceClient **)v1 + 9), &v304, &v232);
          params.m_nCount = (unsigned __int64)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable';
          if ( v216 )
          {
            if ( *((_DWORD *)v216 - 2) )
              (*(void (__fastcall **)(void **, signed __int64))*v216)(v216, 3i64);
            else
              operator delete[](v216 - 1);
          }
          v27 = &v304;
          break;
        case 8:
          OSuite::ZOQuery::ZOQuery(&v305);
          v219.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable';
          v219.m_nHashSize = 16;
          v219.m_nCount = 0i64;
          v56 = 640i64;
          if ( !is_mul_ok(0x10ui64, 0x28ui64) )
            v56 = -1i64;
          v9 = __CFADD__(v56, 8i64);
          v57 = v56 + 8;
          if ( v9 )
            v57 = -1i64;
          v58 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)OSuite::ZObject::operator new(v57);
          v311 = v58;
          if ( v58 )
          {
            LODWORD(v58->mNode.mPrev) = 16;
            v59 = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *)&v58->mNode.mNext;
            `eh vector constructor iterator'(
              &v58->mNode.mNext,
              0x28ui64,
              16,
              (void (__fastcall *)(void *))OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>);
          }
          else
          {
            v59 = 0i64;
          }
          v219.m_pLists = v59;
          OSuite::ZString::ZString(&v282, v224.mData);
          OSuite::ZString::ZString(&v238, "s_Pid");
          v60 = v238.vfptr->ComputeHash((OSuite::IHashable *)&v238.vfptr);
          v61 = (signed int)((v219.m_nHashSize - 1) & v60);
          v62 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v219.m_pLists[v61].vfptr);
          v219.m_nCount -= v62;
          v63 = &v219.m_pLists[v61];
          v265.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::ZString(&v265.m_First, &v238);
          OSuite::ZString::ZString(&v265.m_Second, &v282);
          v265.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
          v64 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v64;
          if ( v64 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v64,
              &v265);
          else
            v65 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet((OSuite::ZRedBlackTreeBase *)&v63->vfptr, v65);
          v265.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::~ZString(&v265.m_Second);
          OSuite::ZString::~ZString(&v265.m_First);
          v66 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v219.m_pLists[v61].vfptr);
          v219.m_nCount += v66;
          OSuite::ZString::~ZString(&v238);
          OSuite::ZString::~ZString(&v282);
          OSuite::ZString::ZString(&v240, "i32_LB");
          OSuite::ZString::ZString(&v301, *(_DWORD *)(*(_QWORD *)(v6 + 24) + 4i64));
          v68 = v67;
          v69 = v240.vfptr->ComputeHash((OSuite::IHashable *)&v240.vfptr);
          v70 = (signed int)(v69 & (v219.m_nHashSize - 1));
          v71 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v219.m_pLists[v70].vfptr);
          v219.m_nCount -= v71;
          OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
            &v219.m_pLists[v70],
            &v240,
            v68);
          v72 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v219.m_pLists[v70].vfptr);
          v219.m_nCount += v72;
          OSuite::ZString::~ZString(&v301);
          OSuite::ZString::~ZString(&v240);
          OSuite::ZOQuery::ServiceOperation(&v305, *(const char **)(v6 + 32), &v219);
          v227.m_Closure.m_pthis = 0i64;
          v227.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteLeaderboardManager::CommandCB;
          v227.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(v1);
          OSuite::ZWebServiceClient::ExecuteQuery(*((OSuite::ZWebServiceClient **)v1 + 9), &v305, &v227);
          v219.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable';
          if ( v219.m_pLists )
          {
            if ( LODWORD(v219.m_pLists[-1].m_Comparer.vfptr) )
              v219.m_pLists->vfptr->__vecDelDtor((OSuite::ZObject *)v219.m_pLists, 3u);
            else
              operator delete[](&v219.m_pLists[-1].m_Comparer.vfptr);
          }
          v27 = &v305;
          break;
        case 9:
          OSuite::ZOQuery::ZOQuery(&v306);
          v220.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable';
          v220.m_nHashSize = 16;
          v220.m_nCount = 0i64;
          v73 = 640i64;
          if ( !is_mul_ok(0x10ui64, 0x28ui64) )
            v73 = -1i64;
          v9 = __CFADD__(v73, 8i64);
          v74 = v73 + 8;
          if ( v9 )
            v74 = -1i64;
          v75 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)OSuite::ZObject::operator new(v74);
          v311 = v75;
          if ( v75 )
          {
            LODWORD(v75->mNode.mPrev) = 16;
            v76 = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *)&v75->mNode.mNext;
            `eh vector constructor iterator'(
              &v75->mNode.mNext,
              0x28ui64,
              16,
              (void (__fastcall *)(void *))OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>);
          }
          else
          {
            v76 = 0i64;
          }
          v220.m_pLists = v76;
          OSuite::ZString::ZString(&v290, v224.mData);
          OSuite::ZString::ZString(&v242, "s_Pid");
          v77 = v242.vfptr->ComputeHash((OSuite::IHashable *)&v242.vfptr);
          v78 = (signed int)((v220.m_nHashSize - 1) & v77);
          v79 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v220.m_pLists[v78].vfptr);
          v220.m_nCount -= v79;
          v80 = &v220.m_pLists[v78];
          v273.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::ZString(&v273.m_First, &v242);
          OSuite::ZString::ZString(&v273.m_Second, &v290);
          v273.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
          v81 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v81;
          if ( v81 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v81,
              &v273);
          else
            v82 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet((OSuite::ZRedBlackTreeBase *)&v80->vfptr, v82);
          v273.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::~ZString(&v273.m_Second);
          OSuite::ZString::~ZString(&v273.m_First);
          v83 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v220.m_pLists[v78].vfptr);
          v220.m_nCount += v83;
          OSuite::ZString::~ZString(&v242);
          OSuite::ZString::~ZString(&v290);
          OSuite::ZOQuery::ServiceOperation(&v306, "GetTopFriendsStatScores", &v220);
          v231.m_Closure.m_pthis = 0i64;
          v231.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteLeaderboardManager::CommandCB;
          v231.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(v1);
          OSuite::ZWebServiceClient::ExecuteQuery(*((OSuite::ZWebServiceClient **)v1 + 9), &v306, &v231);
          v220.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable';
          if ( v220.m_pLists )
          {
            if ( LODWORD(v220.m_pLists[-1].m_Comparer.vfptr) )
              v220.m_pLists->vfptr->__vecDelDtor((OSuite::ZObject *)v220.m_pLists, 3u);
            else
              operator delete[](&v220.m_pLists[-1].m_Comparer.vfptr);
          }
          v27 = &v306;
          break;
        case 10:
          OSuite::ZOQuery::ZOQuery(&v308);
          OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&v222, 0x10ui64);
          OSuite::ZString::ZString(&v284, v224.mData);
          OSuite::ZString::ZString(&v244, "s_Pid");
          v84 = v244.vfptr->ComputeHash((OSuite::IHashable *)&v244.vfptr);
          v85 = (signed int)((v222.m_nHashSize - 1) & v84);
          v86 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v222.m_pLists[v85].vfptr);
          v222.m_nCount -= v86;
          v87 = &v222.m_pLists[v85];
          v267.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::ZString(&v267.m_First, &v244);
          OSuite::ZString::ZString(&v267.m_Second, &v284);
          v267.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
          v88 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v88;
          if ( v88 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v88,
              &v267);
          else
            v89 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet((OSuite::ZRedBlackTreeBase *)&v87->vfptr, v89);
          v267.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::~ZString(&v267.m_Second);
          OSuite::ZString::~ZString(&v267.m_First);
          v90 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v222.m_pLists[v85].vfptr);
          v222.m_nCount += v90;
          OSuite::ZString::~ZString(&v244);
          OSuite::ZString::~ZString(&v284);
          OSuite::ZOQuery::ServiceOperation(&v308, "GetPlayerStats", &v222);
          v229.m_Closure.m_pthis = 0i64;
          v229.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteLeaderboardManager::CommandCB;
          v229.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(v1);
          OSuite::ZWebServiceClient::ExecuteQuery(*((OSuite::ZWebServiceClient **)v1 + 9), &v308, &v229);
          v222.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable';
          if ( v222.m_pLists )
          {
            if ( LODWORD(v222.m_pLists[-1].m_Comparer.vfptr) )
              v222.m_pLists->vfptr->__vecDelDtor((OSuite::ZObject *)v222.m_pLists, 3u);
            else
              operator delete[](&v222.m_pLists[-1].m_Comparer.vfptr);
          }
          v27 = &v308;
          break;
        case 11:
          v91 = *(_DWORD *)(*(_QWORD *)(v6 + 24) + 96i64);
          v92 = &customWorldMapCaption;
          if ( v91 )
          {
            v93 = v91 - 1;
            if ( v93 )
            {
              v94 = v93 - 1;
              if ( v94 )
              {
                if ( v94 == 1 )
                  v92 = "race";
              }
              else
              {
                v92 = "mission";
              }
            }
            else
            {
              v92 = "statgame";
            }
          }
          else
          {
            v92 = "stataward";
          }
          OSuite::ZOQuery::ZOQuery(&v310);
          OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&params, 0x10ui64);
          OSuite::ZString::ZString(&v277, v224.mData);
          OSuite::ZString::ZString(&v235, "s_Pid");
          v95 = v235.vfptr->ComputeHash((OSuite::IHashable *)&v235.vfptr);
          v96 = (signed int)((params.m_nHashSize - 1) & v95);
          v97 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v96].vfptr);
          params.m_nCount -= v97;
          v98 = &params.m_pLists[v96];
          v260.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::ZString(&v260.m_First, &v235);
          OSuite::ZString::ZString(&v260.m_Second, &v277);
          v260.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
          v99 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v99;
          if ( v99 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v99,
              &v260);
          OSuite::ZRedBlackTreeBase::InsertElementSet(
            (OSuite::ZRedBlackTreeBase *)&v98->vfptr,
            (OSuite::ZRedBlackTreeBase::ZElementBase *)&v99->vfptr);
          v260.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::~ZString(&v260.m_Second);
          OSuite::ZString::~ZString(&v260.m_First);
          v100 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v96].vfptr);
          params.m_nCount += v100;
          OSuite::ZString::~ZString(&v235);
          OSuite::ZString::~ZString(&v277);
          OSuite::ZString::ZString(&v279, v92);
          OSuite::ZString::ZString(&v250, "s_LBType");
          v101 = v250.vfptr->ComputeHash((OSuite::IHashable *)&v250.vfptr);
          v102 = (signed int)((params.m_nHashSize - 1) & v101);
          v103 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v102].vfptr);
          params.m_nCount -= v103;
          v104 = &params.m_pLists[v102];
          v262.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::ZString(&v262.m_First, &v250);
          OSuite::ZString::ZString(&v262.m_Second, &v279);
          v262.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
          v105 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v105;
          if ( v105 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v105,
              &v262);
          else
            v106 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet((OSuite::ZRedBlackTreeBase *)&v104->vfptr, v106);
          v262.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::~ZString(&v262.m_Second);
          OSuite::ZString::~ZString(&v262.m_First);
          v107 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v102].vfptr);
          params.m_nCount += v107;
          OSuite::ZString::~ZString(&v250);
          OSuite::ZString::~ZString(&v279);
          OSuite::ZString::ZString(&v237, "i32_LB");
          OSuite::ZString::ZString(&v300, *(_DWORD *)(*(_QWORD *)(v6 + 24) + 4i64));
          v109 = v108;
          v110 = v237.vfptr->ComputeHash((OSuite::IHashable *)&v237.vfptr);
          v111 = (signed int)(v110 & (params.m_nHashSize - 1));
          v112 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v111].vfptr);
          params.m_nCount -= v112;
          OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
            &params.m_pLists[v111],
            &v237,
            v109);
          v113 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v111].vfptr);
          params.m_nCount += v113;
          OSuite::ZString::~ZString(&v300);
          OSuite::ZString::~ZString(&v237);
          OSuite::ZString::ZString(&v252, "i32_Score");
          OSuite::ZString::ZString(&v298, *(_DWORD *)(v6 + 32));
          v115 = v114;
          v116 = v252.vfptr->ComputeHash((OSuite::IHashable *)&v252.vfptr);
          v117 = (signed int)(v116 & (params.m_nHashSize - 1));
          v118 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v117].vfptr);
          params.m_nCount -= v118;
          OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
            &params.m_pLists[v117],
            &v252,
            v115);
          v119 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v117].vfptr);
          params.m_nCount += v119;
          OSuite::ZString::~ZString(&v298);
          OSuite::ZString::~ZString(&v252);
          OSuite::ZOQuery::ServiceOperation(&v310, "GetChallengeFriends", &params);
          v226.m_Closure.m_pthis = 0i64;
          v226.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteLeaderboardManager::CommandCB;
          v226.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(v1);
          OSuite::ZWebServiceClient::ExecuteQuery(*((OSuite::ZWebServiceClient **)v1 + 9), &v310, &v226);
          params.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable';
          if ( params.m_pLists )
          {
            if ( LODWORD(params.m_pLists[-1].m_Comparer.vfptr) )
              params.m_pLists->vfptr->__vecDelDtor((OSuite::ZObject *)params.m_pLists, 3u);
            else
              operator delete[](&params.m_pLists[-1].m_Comparer.vfptr);
          }
          v27 = &v310;
          break;
        default:
          OSuite::ZOQuery::ZOQuery(&v302);
          OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&v214, 0x10ui64);
          OSuite::ZString::ZString(&v281, v224.mData);
          OSuite::ZString::ZString(&v239, "s_Pid");
          v120 = v239.vfptr->ComputeHash((OSuite::IHashable *)&v239.vfptr);
          v121 = (signed int)((v214.m_nHashSize - 1) & v120);
          v122 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v121].vfptr);
          v214.m_nCount -= v122;
          v123 = &v214.m_pLists[v121];
          v264.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::ZString(&v264.m_First, &v239);
          OSuite::ZString::ZString(&v264.m_Second, &v281);
          v264.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
          v124 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v124;
          if ( v124 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v124,
              &v264);
          else
            v125 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet((OSuite::ZRedBlackTreeBase *)&v123->vfptr, v125);
          v264.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::~ZString(&v264.m_Second);
          OSuite::ZString::~ZString(&v264.m_First);
          v126 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v121].vfptr);
          v214.m_nCount += v126;
          OSuite::ZString::~ZString(&v239);
          OSuite::ZString::~ZString(&v281);
          v127 = UFG::OnlineManager::Instance();
          v128 = UFG::OnlineManager::GetOnlineName(v127, &v303);
          OSuite::ZString::ZString(&v283, v128->mData);
          OSuite::ZString::ZString(&v254, "s_Name");
          v129 = v254.vfptr->ComputeHash((OSuite::IHashable *)&v254.vfptr);
          v130 = (signed int)((v214.m_nHashSize - 1) & v129);
          v131 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v130].vfptr);
          v214.m_nCount -= v131;
          v132 = &v214.m_pLists[v130];
          v266.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::ZString(&v266.m_First, &v254);
          OSuite::ZString::ZString(&v266.m_Second, &v283);
          v266.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
          v133 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v133;
          if ( v133 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v133,
              &v266);
          else
            v134 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet((OSuite::ZRedBlackTreeBase *)&v132->vfptr, v134);
          v266.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::~ZString(&v266.m_Second);
          OSuite::ZString::~ZString(&v266.m_First);
          v135 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v130].vfptr);
          v214.m_nCount += v135;
          OSuite::ZString::~ZString(&v254);
          OSuite::ZString::~ZString(&v283);
          UFG::qString::~qString(&v303);
          v136 = GetSystemRegion();
          v137 = MapRegionToRegionCode(v136);
          OSuite::ZString::ZString(&v275, v137);
          OSuite::ZString::ZString(&v241, "s_Region");
          v138 = v241.vfptr->ComputeHash((OSuite::IHashable *)&v241.vfptr);
          v139 = (signed int)((v214.m_nHashSize - 1) & v138);
          v140 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v139].vfptr);
          v214.m_nCount -= v140;
          v141 = &v214.m_pLists[v139];
          v268.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::ZString(&v268.m_First, &v241);
          OSuite::ZString::ZString(&v268.m_Second, &v275);
          v268.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
          v142 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v142;
          if ( v142 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v142,
              &v268);
          else
            v143 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet((OSuite::ZRedBlackTreeBase *)&v141->vfptr, v143);
          v268.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::~ZString(&v268.m_Second);
          OSuite::ZString::~ZString(&v268.m_First);
          v144 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v139].vfptr);
          v214.m_nCount += v144;
          OSuite::ZString::~ZString(&v241);
          OSuite::ZString::~ZString(&v275);
          OSuite::ZString::ZString(&v256, "i32_DLC");
          OSuite::ZString::ZString(&v296, 0);
          v146 = v145;
          v147 = v256.vfptr->ComputeHash((OSuite::IHashable *)&v256.vfptr);
          v148 = (signed int)(v147 & (v214.m_nHashSize - 1));
          v149 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v148].vfptr);
          v214.m_nCount -= v149;
          OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
            &v214.m_pLists[v148],
            &v256,
            v146);
          v150 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v148].vfptr);
          v214.m_nCount += v150;
          OSuite::ZString::~ZString(&v296);
          OSuite::ZString::~ZString(&v256);
          OSuite::ZString::ZString(&v243, "i32_LB");
          OSuite::ZString::ZString(&v297, *(_DWORD *)(*(_QWORD *)(v6 + 24) + 4i64));
          v152 = v151;
          v153 = v243.vfptr->ComputeHash((OSuite::IHashable *)&v243.vfptr);
          v154 = (signed int)(v153 & (v214.m_nHashSize - 1));
          v155 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v154].vfptr);
          v214.m_nCount -= v155;
          OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
            &v214.m_pLists[v154],
            &v243,
            v152);
          v156 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v154].vfptr);
          v214.m_nCount += v156;
          OSuite::ZString::~ZString(&v297);
          OSuite::ZString::~ZString(&v243);
          v157 = *(_DWORD *)(v6 + 16);
          if ( v157 )
          {
            v158 = v157 - 1;
            if ( !v158 )
            {
              OSuite::ZString::ZString(&v291, "gt");
              OSuite::ZString::ZString(&v253, "s_Operation");
              v188 = v253.vfptr->ComputeHash((OSuite::IHashable *)&v253.vfptr);
              v189 = (signed int)((v214.m_nHashSize - 1) & v188);
              v190 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v189].vfptr);
              v214.m_nCount -= v190;
              v191 = &v214.m_pLists[v189];
              v274.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
              OSuite::ZString::ZString(&v274.m_First, &v253);
              OSuite::ZString::ZString(&v274.m_Second, &v291);
              v274.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
              v192 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
              v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v192;
              if ( v192 )
                OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
                  v192,
                  &v274);
              else
                v193 = 0i64;
              OSuite::ZRedBlackTreeBase::InsertElementSet((OSuite::ZRedBlackTreeBase *)&v191->vfptr, v193);
              v274.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
              OSuite::ZString::~ZString(&v274.m_Second);
              OSuite::ZString::~ZString(&v274.m_First);
              v194 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v189].vfptr);
              v214.m_nCount += v194;
              OSuite::ZString::~ZString(&v253);
              OSuite::ZString::~ZString(&v291);
              OSuite::ZString::ZString(&v249, "i32_Score");
              OSuite::ZString::ZString(&v294, *(_DWORD *)(v6 + 32));
              v196 = v195;
              v197 = v249.vfptr->ComputeHash((OSuite::IHashable *)&v249.vfptr);
              v198 = (signed int)(v197 & (v214.m_nHashSize - 1));
              v199 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v198].vfptr);
              v214.m_nCount -= v199;
              OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
                &v214.m_pLists[v198],
                &v249,
                v196);
              v200 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v198].vfptr);
              v214.m_nCount += v200;
              OSuite::ZString::~ZString(&v294);
              OSuite::ZString::~ZString(&v249);
              v181 = "UpdateStatGameResult";
              goto LABEL_149;
            }
            v159 = v158 - 1;
            if ( !v159 )
            {
              OSuite::ZString::ZString(&v247, "i32_Score");
              OSuite::ZString::ZString(&v293, *(_DWORD *)(v6 + 32));
              v183 = v182;
              v184 = v247.vfptr->ComputeHash((OSuite::IHashable *)&v247.vfptr);
              v185 = (signed int)(v184 & (v214.m_nHashSize - 1));
              v186 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v185].vfptr);
              v214.m_nCount -= v186;
              OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
                &v214.m_pLists[v185],
                &v247,
                v183);
              v187 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v185].vfptr);
              v214.m_nCount += v187;
              OSuite::ZString::~ZString(&v293);
              OSuite::ZString::~ZString(&v247);
              v181 = "UpdateMissionResult";
              goto LABEL_149;
            }
            if ( v159 == 1 )
            {
              OSuite::ZString::ZString(&v258, "i32_Score");
              OSuite::ZString::ZString(&v299, *(_DWORD *)(v6 + 32));
              v161 = v160;
              v162 = v258.vfptr->ComputeHash((OSuite::IHashable *)&v258.vfptr);
              v163 = (signed int)(v162 & (v214.m_nHashSize - 1));
              v164 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v163].vfptr);
              v214.m_nCount -= v164;
              OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
                &v214.m_pLists[v163],
                &v258,
                v161);
              v165 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v163].vfptr);
              v214.m_nCount += v165;
              OSuite::ZString::~ZString(&v299);
              OSuite::ZString::~ZString(&v258);
              v166 = "false";
              if ( *(_BYTE *)(v6 + 48) )
                v166 = "true";
              OSuite::ZString::ZString(&v287, v166);
              OSuite::ZString::ZString(&v233, "b_Won");
              v167 = v233.vfptr->ComputeHash((OSuite::IHashable *)&v233.vfptr);
              v168 = (signed int)((v214.m_nHashSize - 1) & v167);
              v169 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v168].vfptr);
              v214.m_nCount -= v169;
              v170 = &v214.m_pLists[v168];
              v270.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
              OSuite::ZString::ZString(&v270.m_First, &v233);
              OSuite::ZString::ZString(&v270.m_Second, &v287);
              v270.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
              v171 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
              v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v171;
              if ( v171 )
                OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
                  v171,
                  &v270);
              else
                v172 = 0i64;
              OSuite::ZRedBlackTreeBase::InsertElementSet((OSuite::ZRedBlackTreeBase *)&v170->vfptr, v172);
              v270.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
              OSuite::ZString::~ZString(&v270.m_Second);
              OSuite::ZString::~ZString(&v270.m_First);
              v173 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v168].vfptr);
              v214.m_nCount += v173;
              OSuite::ZString::~ZString(&v233);
              OSuite::ZString::~ZString(&v287);
              OSuite::ZString::ZString(&v289, *(const char **)(v6 + 80));
              OSuite::ZString::ZString(&v255, "s_CarUsed");
              v174 = v255.vfptr->ComputeHash((OSuite::IHashable *)&v255.vfptr);
              v175 = (signed int)((v214.m_nHashSize - 1) & v174);
              v176 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v175].vfptr);
              v214.m_nCount -= v176;
              v177 = &v214.m_pLists[v175];
              v272.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
              OSuite::ZString::ZString(&v272.m_First, &v255);
              OSuite::ZString::ZString(&v272.m_Second, &v289);
              v272.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
              v178 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
              v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v178;
              if ( v178 )
                OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
                  v178,
                  &v272);
              else
                v179 = 0i64;
              OSuite::ZRedBlackTreeBase::InsertElementSet((OSuite::ZRedBlackTreeBase *)&v177->vfptr, v179);
              v272.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
              OSuite::ZString::~ZString(&v272.m_Second);
              OSuite::ZString::~ZString(&v272.m_First);
              v180 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v175].vfptr);
              v214.m_nCount += v180;
              OSuite::ZString::~ZString(&v255);
              OSuite::ZString::~ZString(&v289);
              v181 = "UpdateRaceResult";
LABEL_149:
              OSuite::ZOQuery::ServiceOperation(&v302, v181, &v214);
              v225.m_Closure.m_pthis = 0i64;
              v225.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteLeaderboardManager::CommandCB;
              v225.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(v1);
              OSuite::ZWebServiceClient::ExecuteQuery(*((OSuite::ZWebServiceClient **)v1 + 9), &v302, &v225);
            }
            v214.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable';
            if ( v214.m_pLists )
            {
              if ( LODWORD(v214.m_pLists[-1].m_Comparer.vfptr) )
                v214.m_pLists->vfptr->__vecDelDtor((OSuite::ZObject *)v214.m_pLists, 3u);
              else
                operator delete[](&v214.m_pLists[-1].m_Comparer.vfptr);
            }
            v27 = &v302;
            break;
          }
          OSuite::ZString::ZString(&v276, "gt");
          OSuite::ZString::ZString(&v257, "s_Operation");
          v201 = v257.vfptr->ComputeHash((OSuite::IHashable *)&v257.vfptr);
          v202 = (signed int)((v214.m_nHashSize - 1) & v201);
          v203 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v202].vfptr);
          v214.m_nCount -= v203;
          v204 = &v214.m_pLists[v202];
          v259.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::ZString(&v259.m_First, &v257);
          OSuite::ZString::ZString(&v259.m_Second, &v276);
          v259.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable';
          v205 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v205;
          if ( v205 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v205,
              &v259);
          else
            v206 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet((OSuite::ZRedBlackTreeBase *)&v204->vfptr, v206);
          v259.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable';
          OSuite::ZString::~ZString(&v259.m_Second);
          OSuite::ZString::~ZString(&v259.m_First);
          v207 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v202].vfptr);
          v214.m_nCount += v207;
          OSuite::ZString::~ZString(&v257);
          OSuite::ZString::~ZString(&v276);
          OSuite::ZString::ZString(&v251, "i32_Score");
          OSuite::ZString::ZString(&v292, *(_DWORD *)(v6 + 32));
          v209 = v208;
          v210 = v251.vfptr->ComputeHash((OSuite::IHashable *)&v251.vfptr);
          v211 = (signed int)(v210 & (v214.m_nHashSize - 1));
          v212 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v211].vfptr);
          v214.m_nCount -= v212;
          OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
            &v214.m_pLists[v211],
            &v251,
            v209);
          v213 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v214.m_pLists[v211].vfptr);
          v214.m_nCount += v213;
          OSuite::ZString::~ZString(&v292);
          OSuite::ZString::~ZString(&v251);
          v181 = "UpdateStatAwardResult";
          goto LABEL_149;
      }
      OSuite::ZOQuery::~ZOQuery(v27);
      v2 = v1 + 72;
LABEL_156:
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)(v1 + 104));
      UFG::qEvent::Wait((UFG::qEvent *)(v1 + 152));
      UFG::qString::~qString(&v224);
    }
    while ( !v1[101] );
  }
}

// File Line: 1231
// RVA: 0x42CAA0
char __fastcall UFG::OSuiteLeaderboardManager::GetResultFriends(UFG::OSuiteLeaderboardManager *this, UFG::OSuiteLeaderboardData *pLBD, OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *callback)
{
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *v3; // rsi
  UFG::OSuiteLeaderboardData *v4; // rdi
  UFG::OSuiteLeaderboardManager *v5; // rbp
  char v6; // bl
  UFG::GameStatTracker *v7; // rax
  UFG::LeaderboardCategory v8; // ecx
  int v9; // ecx
  int v10; // ecx
  const char *v11; // rbx
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rdx
  UFG::allocator::free_link *v14; // rax

  v3 = callback;
  v4 = pLBD;
  v5 = this;
  v6 = 1;
  if ( !UFG::OSuiteManager::Instance()->m_bConnected )
    v6 = 0;
  v7 = UFG::GameStatTracker::Instance();
  if ( (signed int)UFG::GameStatTracker::GetStat(v7, IsBannedByCommunityManager) > 0 || !v6 )
    return 0;
  v8 = v4->mCategory;
  if ( v8 == LeaderboardCategory_StatAward )
  {
    v11 = "GetStatAwardResults";
    goto LABEL_13;
  }
  v9 = v8 - 1;
  if ( !v9 )
  {
    v11 = "GetStatGameResults";
    goto LABEL_13;
  }
  v10 = v9 - 1;
  if ( !v10 )
  {
    v11 = "GetMissionResults";
    goto LABEL_13;
  }
  if ( v10 != 1 )
    return 0;
  v11 = "GetRaceResults";
LABEL_13:
  v12 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
  v13 = v12;
  if ( v12 )
  {
    v14 = v12 + 1;
    v14->mNext = v14;
    v14[1].mNext = v14;
    v13->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable';
    v13->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateFriendsResultsEvent::`vftable';
    v13[4].mNext = (UFG::allocator::free_link *)v4;
    v13[5].mNext = (UFG::allocator::free_link *)v11;
    v13[6].mNext = 0i64;
    v13[7].mNext = 0i64;
    v13[7].mNext = (UFG::allocator::free_link *)v3->m_Closure.m_pFunction;
    v13[6].mNext = (UFG::allocator::free_link *)v3->m_Closure.m_pthis;
    LODWORD(v13[3].mNext) = 7;
  }
  else
  {
    v13 = 0i64;
  }
  UFG::OSuiteLeaderboardManager::QueueUpdateEvent(v5, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v13);
  return 1;
}

// File Line: 1263
// RVA: 0x42CBC0
char __fastcall UFG::OSuiteLeaderboardManager::GetResultGlobal(UFG::OSuiteLeaderboardManager *this, UFG::OSuiteLeaderboardData *pLBD, OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *callback)
{
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *v3; // rsi
  UFG::OSuiteLeaderboardData *v4; // rdi
  UFG::OSuiteLeaderboardManager *v5; // rbp
  char v6; // bl
  UFG::GameStatTracker *v7; // rax
  UFG::LeaderboardCategory v8; // ecx
  int v9; // ecx
  int v10; // ecx
  const char *v11; // rbx
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rdx
  UFG::allocator::free_link *v14; // rax

  v3 = callback;
  v4 = pLBD;
  v5 = this;
  v6 = 1;
  if ( !UFG::OSuiteManager::Instance()->m_bConnected )
    v6 = 0;
  v7 = UFG::GameStatTracker::Instance();
  if ( (signed int)UFG::GameStatTracker::GetStat(v7, IsBannedByCommunityManager) > 0 || !v6 )
    return 0;
  v8 = v4->mCategory;
  if ( v8 == LeaderboardCategory_StatAward )
  {
    v11 = "GetGlobalStatAwardResults";
    goto LABEL_13;
  }
  v9 = v8 - 1;
  if ( !v9 )
  {
    v11 = "GetGlobalStatGameResults";
    goto LABEL_13;
  }
  v10 = v9 - 1;
  if ( !v10 )
  {
    v11 = "GetGlobalMissionResults";
    goto LABEL_13;
  }
  if ( v10 != 1 )
    return 0;
  v11 = "GetGlobalRaceResults";
LABEL_13:
  v12 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
  v13 = v12;
  if ( v12 )
  {
    v14 = v12 + 1;
    v14->mNext = v14;
    v14[1].mNext = v14;
    v13->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable';
    v13->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateGlobalResultsEvent::`vftable';
    v13[4].mNext = (UFG::allocator::free_link *)v4;
    v13[5].mNext = (UFG::allocator::free_link *)v11;
    v13[6].mNext = 0i64;
    v13[7].mNext = 0i64;
    v13[7].mNext = (UFG::allocator::free_link *)v3->m_Closure.m_pFunction;
    v13[6].mNext = (UFG::allocator::free_link *)v3->m_Closure.m_pthis;
    LODWORD(v13[3].mNext) = 8;
  }
  else
  {
    v13 = 0i64;
  }
  UFG::OSuiteLeaderboardManager::QueueUpdateEvent(v5, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v13);
  return 1;
}

// File Line: 1295
// RVA: 0x42CE40
char __fastcall UFG::OSuiteLeaderboardManager::GetTopFriendsStatScores(UFG::OSuiteLeaderboardManager *this, OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *callback)
{
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *v2; // rdi
  UFG::OSuiteLeaderboardManager *v3; // rsi
  char v4; // bl
  UFG::GameStatTracker *v5; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rdx
  UFG::allocator::free_link *v8; // rax

  v2 = callback;
  v3 = this;
  v4 = 1;
  if ( !UFG::OSuiteManager::Instance()->m_bConnected )
    v4 = 0;
  v5 = UFG::GameStatTracker::Instance();
  if ( (signed int)UFG::GameStatTracker::GetStat(v5, IsBannedByCommunityManager) > 0 || !v4 )
    return 0;
  v6 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v7 = v6;
  if ( v6 )
  {
    v8 = v6 + 1;
    v8->mNext = v8;
    v8[1].mNext = v8;
    v7->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable';
    v7->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateTopFriendsScoresEvent::`vftable';
    v7[4].mNext = 0i64;
    v7[5].mNext = 0i64;
    v7[5].mNext = (UFG::allocator::free_link *)v2->m_Closure.m_pFunction;
    v7[4].mNext = (UFG::allocator::free_link *)v2->m_Closure.m_pthis;
    LODWORD(v7[3].mNext) = 9;
  }
  else
  {
    v7 = 0i64;
  }
  UFG::OSuiteLeaderboardManager::QueueUpdateEvent(v3, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v7);
  return 1;
}

// File Line: 1305
// RVA: 0x42C9C0
char __fastcall UFG::OSuiteLeaderboardManager::GetPlayerStats(UFG::OSuiteLeaderboardManager *this, OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *callback)
{
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *v2; // rdi
  UFG::OSuiteLeaderboardManager *v3; // rsi
  char v4; // bl
  UFG::GameStatTracker *v5; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rdx
  UFG::allocator::free_link *v8; // rax

  v2 = callback;
  v3 = this;
  v4 = 1;
  if ( !UFG::OSuiteManager::Instance()->m_bConnected )
    v4 = 0;
  v5 = UFG::GameStatTracker::Instance();
  if ( (signed int)UFG::GameStatTracker::GetStat(v5, IsBannedByCommunityManager) > 0 || !v4 )
    return 0;
  v6 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v7 = v6;
  if ( v6 )
  {
    v8 = v6 + 1;
    v8->mNext = v8;
    v8[1].mNext = v8;
    v7->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable';
    v7->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateGetPlayerStatsEvent::`vftable';
    v7[4].mNext = 0i64;
    v7[5].mNext = 0i64;
    v7[5].mNext = (UFG::allocator::free_link *)v2->m_Closure.m_pFunction;
    v7[4].mNext = (UFG::allocator::free_link *)v2->m_Closure.m_pthis;
    LODWORD(v7[3].mNext) = 10;
  }
  else
  {
    v7 = 0i64;
  }
  UFG::OSuiteLeaderboardManager::QueueUpdateEvent(v3, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v7);
  return 1;
}

// File Line: 1315
// RVA: 0x42C630
char __fastcall UFG::OSuiteLeaderboardManager::GetChallengeFriends(UFG::OSuiteLeaderboardManager *this, UFG::OSuiteLeaderboardData *pLBD, int score, OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *callback)
{
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *v4; // rdi
  int v5; // ebp
  UFG::OSuiteLeaderboardData *v6; // r14
  UFG::OSuiteLeaderboardManager *v7; // rsi
  char v8; // bl
  UFG::GameStatTracker *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdx
  UFG::allocator::free_link *v12; // rax

  v4 = callback;
  v5 = score;
  v6 = pLBD;
  v7 = this;
  v8 = 1;
  if ( !UFG::OSuiteManager::Instance()->m_bConnected )
    v8 = 0;
  v9 = UFG::GameStatTracker::Instance();
  if ( (signed int)UFG::GameStatTracker::GetStat(v9, IsBannedByCommunityManager) > 0 || !v8 )
    return 0;
  v10 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
  v11 = v10;
  if ( v10 )
  {
    v12 = v10 + 1;
    v12->mNext = v12;
    v12[1].mNext = v12;
    v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable';
    v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateGetChallengeFriendsEvent::`vftable';
    v11[4].mNext = (UFG::allocator::free_link *)v6;
    LODWORD(v11[5].mNext) = v5;
    v11[6].mNext = 0i64;
    v11[7].mNext = 0i64;
    v11[7].mNext = (UFG::allocator::free_link *)v4->m_Closure.m_pFunction;
    v11[6].mNext = (UFG::allocator::free_link *)v4->m_Closure.m_pthis;
    LODWORD(v11[3].mNext) = 11;
  }
  else
  {
    v11 = 0i64;
  }
  UFG::OSuiteLeaderboardManager::QueueUpdateEvent(v7, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v11);
  return 1;
}

// File Line: 1341
// RVA: 0x42FA50
void __fastcall UFG::OSuiteLeaderboardManager::ScanOrResetPlayerStats(UFG::MessageBuffer *msgBuffer)
{
  UFG::MessageBuffer *v1; // r13
  unsigned int v2; // er14
  UFG::GameStatTracker *v3; // r12
  __int64 v4; // rax
  _QWORD *v5; // r15
  int v6; // ebx
  UFG::qSymbol *v7; // rdi
  int v8; // eax
  UFG::PersistentData::MapInt *v9; // rsi
  int v10; // er8
  int v11; // er8
  float v12; // xmm0_4
  float v13; // xmm6_4
  UFG::qSymbol *v14; // rbx
  int v15; // eax
  UFG::PersistentData::MapFloat *v16; // rdi
  float v17; // xmm2_4
  UFG::PersistentData::Time *v18; // rax
  float v19; // xmm2_4
  UFG::PersistentData::MapBool *v20; // rax
  int v21; // ebx
  UFG::qSymbol *v22; // rsi
  UFG::PersistentData::MapInt *v23; // rdi
  UFG::PersistentData::MapInt *v24; // rdi
  int v25; // eax
  int v26; // eax
  UFG::qSymbol *v27; // rax
  int v28; // edx
  int v29; // edx
  bool v30; // zf
  int v31; // er8
  UFG::PersistentData::MapFloat *v32; // rax
  UFG::qSymbol *v33; // rax
  UFG::PersistentData::MapFloat *v34; // rax
  __int64 v35; // r14
  __int64 v36; // rdi
  UFG::AIAwareness::Effector::ScoreIndex *v37; // rdi
  signed __int64 v38; // rax
  int v39; // edx
  signed __int64 v40; // rax
  signed __int64 v41; // r8
  UFG::AIAwareness::Effector::ScoreIndex v42; // rcx
  UFG::AIAwareness::Effector::ScoreIndex v43; // rcx
  UFG::AIAwareness::Effector::ScoreIndex v44; // rax
  UFG::AIAwareness::Effector::ScoreIndex v45; // rax
  UFG::AIAwareness::Effector::ScoreIndex *v46; // rbx
  unsigned __int64 v47; // rdx
  float v48; // xmm0_4
  UFG::AIAwareness::Effector::ScoreIndex v49; // rcx
  UFG::AIAwareness::Effector::ScoreIndex v50; // rax
  __int64 v51; // rdi
  unsigned int v52; // ebx
  UFG::PersistentData::MapInt *v53; // rsi
  int v54; // eax
  __int64 v55; // rbx
  UFG::PersistentData::MapFloat *v56; // rsi
  int v57; // ebx
  int v58; // edi
  unsigned int v59; // ecx
  UFG::ProgressionTracker *v60; // r14
  UFG::qSymbol *v61; // rax
  UFG::qBaseTreeRB *v62; // rax
  unsigned __int8 v63; // al
  UFG::PersistentData::MapInt *v64; // r14
  int v65; // esi
  int v66; // eax
  __int64 v67; // rbx
  int v68; // ebx
  int v69; // eax
  __int64 v70; // rbx
  __int64 v71; // [rsp+20h] [rbp-E0h]
  UFG::qSymbol *min; // [rsp+30h] [rbp-D0h]
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+38h] [rbp-C8h]
  UFG::PersistentData::MapFloat::Iterator v74; // [rsp+48h] [rbp-B8h]
  __int64 v75; // [rsp+58h] [rbp-A8h]
  UFG::PersistentData::MapFloat::Iterator v76; // [rsp+60h] [rbp-A0h]
  __int128 v77; // [rsp+70h] [rbp-90h]
  UFG::qSymbol v78; // [rsp+80h] [rbp-80h]
  char dest; // [rsp+90h] [rbp-70h]
  UFG::AIAwareness::Effector::ScoreIndex right; // [rsp+108h] [rbp+8h]
  UFG::AIAwareness::Effector::ScoreIndex left[64]; // [rsp+110h] [rbp+10h]
  char text; // [rsp+310h] [rbp+210h]
  UFG::qSymbol *max; // [rsp+3F8h] [rbp+2F8h]
  UFG::qSymbol v84; // [rsp+400h] [rbp+300h]
  UFG::qSymbol name; // [rsp+408h] [rbp+308h]

  v1 = msgBuffer;
  v2 = 0;
  v3 = UFG::GameStatTracker::Instance();
  v4 = 0i64;
  v75 = 0i64;
  LODWORD(max) = 0;
  while ( 2 )
  {
    v5 = (_QWORD *)(24 * v4 + 5402784064i64);
    switch ( UFG::sPlayerStatSubmissions[v4].mDataType )
    {
      case 0:
        v6 = UFG::GameStatTracker::GetStat(v3, (UFG::GameStat::Int32Stat)UFG::sPlayerStatSubmissions[v4].mGameStatId);
        v7 = UFG::GameStat::GetSymbol((UFG::GameStat::Int32Stat)*((_DWORD *)v5 + 2));
        v8 = *((_DWORD *)v5 + 3);
        if ( v8 )
        {
          if ( v8 == 2 )
            goto LABEL_5;
        }
        else
        {
          v9 = UFG::GameStatTracker::GetMapInt(v3, PlayersStatsIntListSum);
          v11 = v6 - UFG::PersistentData::MapInt::GetStatus(v9, v7);
          if ( v11 > 0 )
          {
            if ( !v1 )
              goto LABEL_11;
            UFG::MessageBuffer::AppendValue(v1, (UFG::PlayerStatSubmissionLookup *)v5, v11);
          }
        }
        goto LABEL_112;
      case 1:
        v12 = UFG::GameStatTracker::GetStat(v3, (UFG::GameStat::FloatStat)UFG::sPlayerStatSubmissions[v4].mGameStatId);
        v13 = v12;
        v14 = UFG::GameStat::GetSymbol((UFG::GameStat::FloatStat)*((_DWORD *)v5 + 2));
        v15 = *((_DWORD *)v5 + 3);
        if ( !v15 )
          goto LABEL_21;
        if ( v15 == 2 )
        {
          v16 = UFG::GameStatTracker::GetMapFloat(v3, PlayersStatsFloatListMax);
          if ( v12 > UFG::PersistentData::MapFloat::GetStatus(v16, v14) )
          {
            v17 = v13;
            if ( !v1 )
              goto LABEL_19;
            UFG::MessageBuffer::AppendValue(v1, (UFG::PlayerStatSubmissionLookup *)v5, v13);
          }
        }
        goto LABEL_112;
      case 2:
        v18 = UFG::GameStatTracker::GetTimeStat(
                v3,
                (UFG::GameStat::TimeStat)UFG::sPlayerStatSubmissions[v4].mGameStatId);
        v13 = UFG::PersistentData::Time::GetTotalTime(v18);
        v14 = UFG::GameStat::GetSymbol((UFG::GameStat::TimeStat)*((_DWORD *)v5 + 2));
        if ( !*((_DWORD *)v5 + 3) )
        {
LABEL_21:
          v16 = UFG::GameStatTracker::GetMapFloat(v3, PlayersStatsFloatListSum);
          v19 = v13 - UFG::PersistentData::MapFloat::GetStatus(v16, v14);
          if ( v19 > 0.0 )
          {
            if ( v1 )
            {
              UFG::MessageBuffer::AppendValue(v1, (UFG::PlayerStatSubmissionLookup *)v5, v19);
            }
            else
            {
              v17 = v13;
LABEL_19:
              UFG::PersistentData::MapFloat::SetStatus(v16, v14, v17);
            }
          }
        }
        goto LABEL_112;
      case 3:
        v20 = UFG::GameStatTracker::GetMapBool(
                v3,
                (UFG::GameStat::MapBoolStat)UFG::sPlayerStatSubmissions[v4].mGameStatId);
        v21 = UFG::PersistentData::MapBool::GetTrueCount(v20);
        v22 = UFG::GameStat::GetSymbol((UFG::GameStat::MapBoolStat)*((_DWORD *)v5 + 2));
        if ( *((_DWORD *)v5 + 3) == 2 )
        {
          v23 = UFG::GameStatTracker::GetMapInt(v3, PlayersStatsIntListMax);
          if ( v21 > UFG::PersistentData::MapInt::GetStatus(v23, v22) )
          {
            if ( v1 )
              UFG::MessageBuffer::AppendValue(v1, (UFG::PlayerStatSubmissionLookup *)v5, v21);
            else
              UFG::PersistentData::MapInt::SetStatus(v23, v22, v21);
          }
        }
        goto LABEL_112;
      case 4:
      case 5:
        v6 = 0;
        v24 = UFG::GameStatTracker::GetMapInt(
                v3,
                (UFG::GameStat::MapInt32Stat)UFG::sPlayerStatSubmissions[v4].mGameStatId);
        v25 = *((_DWORD *)v5 + 4);
        if ( v25 == 4 )
        {
          v26 = UFG::PersistentData::MapInt::GetTotal(v24);
LABEL_34:
          v6 = v26;
          goto LABEL_35;
        }
        if ( v25 == 5 )
        {
          min = 0i64;
          max = 0i64;
          UFG::PersistentData::MapInt::GetMaxMin(v24, &max, &min);
          if ( max )
          {
            v26 = UFG::PersistentData::MapInt::GetStatus(v24, max);
            goto LABEL_34;
          }
        }
LABEL_35:
        v27 = UFG::GameStat::GetSymbol((UFG::GameStat::MapInt32Stat)*((_DWORD *)v5 + 2));
        v28 = *((_DWORD *)v5 + 3);
        v7 = v27;
        if ( v28 )
        {
          v29 = v28 - 2;
          if ( v29 )
          {
            v30 = v29 == 1;
            goto LABEL_38;
          }
LABEL_5:
          v9 = UFG::GameStatTracker::GetMapInt(v3, PlayersStatsIntListMax);
          if ( v6 > UFG::PersistentData::MapInt::GetStatus(v9, v7) )
            goto LABEL_6;
        }
        else
        {
          v9 = UFG::GameStatTracker::GetMapInt(v3, PlayersStatsIntListSum);
          v31 = v6 - UFG::PersistentData::MapInt::GetStatus(v9, v7);
          if ( v31 > 0 )
          {
            if ( !v1 )
            {
LABEL_11:
              v10 = v6;
              goto LABEL_12;
            }
            UFG::MessageBuffer::AppendValue(v1, (UFG::PlayerStatSubmissionLookup *)v5, v31);
          }
        }
LABEL_112:
        ++v2;
        v4 = v75 + 1;
        LODWORD(max) = v2;
        ++v75;
        if ( v2 < 0x82 )
          continue;
        return;
      case 6:
        v32 = UFG::GameStatTracker::GetMapFloat(
                v3,
                (UFG::GameStat::MapFloatStat)UFG::sPlayerStatSubmissions[v4].mGameStatId);
        v77 = 0ui64;
        UFG::PersistentData::MapFloat::GetMaxMin(v32, (UFG::qSymbol **)&v77, (UFG::qSymbol **)&v77 + 1);
        if ( (_QWORD)v77 )
        {
          v6 = *(_DWORD *)v77;
          v33 = UFG::GameStat::GetSymbol((UFG::GameStat::MapInt32Stat)*((_DWORD *)v5 + 2));
          v30 = *((_DWORD *)v5 + 3) == 3;
          v7 = v33;
LABEL_38:
          if ( v30 )
          {
            v9 = UFG::GameStatTracker::GetMapInt(v3, PlayersStatsIntList);
            if ( v6 != UFG::PersistentData::MapInt::GetStatus(v9, v7) )
            {
LABEL_6:
              v10 = v6;
              if ( v1 )
                UFG::MessageBuffer::AppendValue(v1, (UFG::PlayerStatSubmissionLookup *)v5, v6);
              else
LABEL_12:
                UFG::PersistentData::MapInt::SetStatus(v9, v7, v10);
            }
          }
        }
        goto LABEL_112;
      case 7:
        v34 = UFG::GameStatTracker::GetMapFloat(
                v3,
                (UFG::GameStat::MapFloatStat)UFG::sPlayerStatSubmissions[v4].mGameStatId);
        UFG::PersistentData::MapInt::GetIterator(v34, &result);
        v35 = 0i64;
        v36 = 0i64;
        while ( UFG::PersistentData::MapBinary::Iterator::IsValid(&result) )
        {
          if ( (unsigned int)v35 >= 0x40 )
            break;
          if ( (unsigned int)v35 >= *((_DWORD *)v5 + 5) )
            break;
          *(float *)&left[v35].mScore = UFG::PersistentData::MapFloat::Iterator::GetStatus(&result);
          ++v36;
          left[v35].mIndex = UFG::PersistentData::MapFloat::Iterator::GetName(&result)->mUID;
          v35 = (unsigned int)(v35 + 1);
          UFG::PersistentData::MapFloat::Iterator::Next((ARefCountMix<SSInstance> *)&result);
        }
        v37 = &right + v36;
        v38 = v37 - left;
        v39 = v38 + 1;
        if ( (signed int)v38 + 1 < 32 )
        {
          if ( v39 > 1 )
            UFG::qInsertionSort<UFG::OSuiteLeaderboardData const *,bool (*)(UFG::OSuiteLeaderboardData const * const &,UFG::OSuiteLeaderboardData const * const &)>(
              (UFG::qPropertySet **)left,
              v39,
              (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::SortByMapFloatUtilsLargestToSmallest);
        }
        else
        {
          v40 = v38 / 2;
          v41 = v40;
          if ( *(float *)&left[0].mScore < *(float *)&left[v40].mScore )
          {
            v42 = left[v40];
            left[v40] = left[0];
            left[0] = v42;
          }
          if ( *(float *)&left[v40].mScore < *(float *)&v37->mScore )
          {
            v43 = left[v40];
            v44 = *v37;
            *v37 = v43;
            left[v41] = v44;
          }
          if ( *(float *)&left[0].mScore < *(float *)&left[v41].mScore )
          {
            v45 = left[v41];
            left[v41] = left[0];
            left[0] = v45;
          }
          v46 = left;
          v47 = (unsigned __int64)v37;
          min = (UFG::qSymbol *)left[v41];
          if ( left <= v37 )
          {
            v48 = *((float *)&min + 1);
            do
            {
              for ( ; v48 < *(float *)&v46->mScore; ++v46 )
              {
                if ( v46 >= v37 )
                  break;
              }
              for ( ; v48 > *(float *)(v47 + 4); v47 -= 8i64 )
              {
                if ( (unsigned __int64)left >= v47 )
                  break;
              }
              if ( (unsigned __int64)v46 > v47 )
                break;
              v49 = *(UFG::AIAwareness::Effector::ScoreIndex *)v47;
              v50 = *v46;
              v47 -= 8i64;
              *v46 = v49;
              *(UFG::AIAwareness::Effector::ScoreIndex *)(v47 + 8) = v50;
              ++v46;
            }
            while ( (unsigned __int64)v46 <= v47 );
          }
          if ( (unsigned __int64)left < v47 )
            UFG::qQuickSortImpl<UFG::MapFloatSortUtil,bool (*)(UFG::MapFloatSortUtil const &,UFG::MapFloatSortUtil const &)>(
              left,
              (UFG::AIAwareness::Effector::ScoreIndex *)v47,
              (bool (__fastcall *)(UFG::AIAwareness::Effector::ScoreIndex *, UFG::AIAwareness::Effector::ScoreIndex *))UFG::SortByMapFloatUtilsLargestToSmallest);
          if ( v46 < v37 )
            UFG::qQuickSortImpl<UFG::MapFloatSortUtil,bool (*)(UFG::MapFloatSortUtil const &,UFG::MapFloatSortUtil const &)>(
              v46,
              v37,
              (bool (__fastcall *)(UFG::AIAwareness::Effector::ScoreIndex *, UFG::AIAwareness::Effector::ScoreIndex *))UFG::SortByMapFloatUtilsLargestToSmallest);
        }
        if ( *((_DWORD *)v5 + 3) == 3 )
        {
          v51 = 0i64;
          if ( *((_DWORD *)v5 + 5) )
          {
            do
            {
              if ( (unsigned int)v51 >= (unsigned int)v35 )
                break;
              v52 = left[v51].mIndex;
              v51 = (unsigned int)(v51 + 1);
              LODWORD(v71) = v51;
              UFG::qSPrintf(&dest, 128, "%s%d", *v5, v71);
              UFG::qSymbol::create_from_string(&name, &dest);
              v53 = UFG::GameStatTracker::GetMapInt(v3, PlayersStatsIntList);
              if ( v52 != UFG::PersistentData::MapInt::GetStatus(v53, &name) )
              {
                if ( v1 )
                {
                  UFG::MessageBuffer::AppendDescriptor(v1, (UFG::PlayerStatSubmissionLookup *)v5, &dest);
                  v54 = UFG::qSPrintf(&text, "%d", v52);
                  v55 = v54;
                  UFG::qStringCopy(
                    v1->mCurrentOffset,
                    LODWORD(v1->mBuffer) + v1->mBufferSize - LODWORD(v1->mCurrentOffset),
                    &text,
                    v54);
                  v1->mCurrentOffset += v55;
                  *v1->mCurrentOffset = 0;
                }
                else
                {
                  UFG::PersistentData::MapInt::SetStatus(v53, &name, v52);
                }
              }
            }
            while ( (unsigned int)v51 < *((_DWORD *)v5 + 5) );
          }
        }
        goto LABEL_111;
      case 8:
      case 9:
        v56 = (UFG::PersistentData::MapFloat *)UFG::GameStatTracker::GetMapBool(
                                                 v3,
                                                 (UFG::GameStat::MapBoolStat)UFG::sPlayerStatSubmissions[v4].mGameStatId);
        UFG::GameStat::GetSymbol(*((UFG::GameStat::MapBoolStat *)v5 + 2));
        v57 = 0;
        v58 = 0;
        if ( *((_DWORD *)v5 + 4) == 9 )
        {
          UFG::PersistentData::MapInt::GetIterator(v56, &v74);
          while ( UFG::PersistentData::MapBool::Iterator::IsValid((UFG::PersistentData::MapBool::Iterator *)&v74) )
          {
            if ( UFG::PersistentData::MapBool::Iterator::GetStatus((UFG::PersistentData::MapBool::Iterator *)&v74) )
            {
              v59 = UFG::PersistentData::MapBool::Iterator::GetName((UFG::PersistentData::MapBool::Iterator *)&v74)->mUID;
              if ( v59 )
              {
                if ( v59 > 0x20 )
                {
                  if ( v59 <= 0x40 )
                    v58 |= 1 << (v59 - 33);
                }
                else
                {
                  v57 |= 1 << (v59 - 1);
                }
              }
            }
            UFG::PersistentData::MapFloat::Iterator::Next((ARefCountMix<SSInstance> *)&v74);
          }
        }
        else
        {
          v60 = UFG::ProgressionTracker::Instance();
          UFG::PersistentData::MapInt::GetIterator(v56, &v76);
          while ( UFG::PersistentData::MapBool::Iterator::IsValid((UFG::PersistentData::MapBool::Iterator *)&v76) )
          {
            if ( UFG::PersistentData::MapBool::Iterator::GetStatus((UFG::PersistentData::MapBool::Iterator *)&v76) )
            {
              v61 = UFG::PersistentData::MapBool::Iterator::GetName((UFG::PersistentData::MapBool::Iterator *)&v76);
              v62 = UFG::ProgressionTracker::Find(v60, v61, 0);
              if ( v62 )
              {
                v63 = BYTE4(v62[4].mNULL.mChild[1]);
                if ( v63 )
                {
                  if ( (signed int)v63 > 32 )
                  {
                    if ( (signed int)v63 <= 64 )
                      v58 |= 1 << (v63 - 33);
                  }
                  else
                  {
                    v57 |= 1 << (v63 - 1);
                  }
                }
              }
            }
            UFG::PersistentData::MapFloat::Iterator::Next((ARefCountMix<SSInstance> *)&v76);
          }
          v2 = (unsigned int)max;
        }
        if ( *((_DWORD *)v5 + 3) == 3 )
        {
          v64 = UFG::GameStatTracker::GetMapInt(v3, PlayersStatsIntList);
          UFG::qSPrintf(&dest, 128, "%s0", *v5);
          UFG::qSymbol::create_from_string(&v84, &dest);
          v65 = UFG::PersistentData::MapInt::GetStatus(v64, &v84);
          if ( v65 != v57 )
          {
            if ( v1 )
            {
              UFG::MessageBuffer::AppendDescriptor(v1, (UFG::PlayerStatSubmissionLookup *)v5, &dest);
              v66 = UFG::qSPrintf(&text, "%d", v57 | (unsigned int)v65);
              v67 = v66;
              UFG::qStringCopy(
                v1->mCurrentOffset,
                LODWORD(v1->mBuffer) + v1->mBufferSize - LODWORD(v1->mCurrentOffset),
                &text,
                v66);
              v1->mCurrentOffset += v67;
              *v1->mCurrentOffset = 0;
            }
            else
            {
              UFG::PersistentData::MapInt::SetStatus(v64, &v84, v57 | v65);
            }
          }
          UFG::qSPrintf(&dest, 128, "%s1", *v5);
          v84.mUID = UFG::qSymbol::create_from_string(&v78, &dest)->mUID;
          v68 = UFG::PersistentData::MapInt::GetStatus(v64, &v84);
          if ( v68 != v58 )
          {
            if ( v1 )
            {
              UFG::MessageBuffer::AppendDescriptor(v1, (UFG::PlayerStatSubmissionLookup *)v5, &dest);
              v69 = UFG::qSPrintf(&text, "%d", v58 | (unsigned int)v68);
              v70 = v69;
              UFG::qStringCopy(
                v1->mCurrentOffset,
                LODWORD(v1->mBuffer) + v1->mBufferSize - LODWORD(v1->mCurrentOffset),
                &text,
                v69);
              v1->mCurrentOffset += v70;
              *v1->mCurrentOffset = 0;
            }
            else
            {
              UFG::PersistentData::MapInt::SetStatus(v64, &v84, v58 | v68);
            }
          }
LABEL_111:
          v2 = (unsigned int)max;
        }
        goto LABEL_112;
      default:
        goto LABEL_112;
    }
  }
}

// File Line: 1851
// RVA: 0x435340
char __fastcall UFG::OSuiteLeaderboardManager::UploadPlayerStats(UFG::OSuiteLeaderboardManager *this)
{
  UFG::OSuiteLeaderboardManager *v1; // rdi
  char v2; // bl
  UFG::GameStatTracker *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::MessageBuffer *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rdx
  UFG::allocator::free_link *v9; // rax

  v1 = this;
  v2 = 1;
  if ( !UFG::OSuiteManager::Instance()->m_bConnected )
    v2 = 0;
  v3 = UFG::GameStatTracker::Instance();
  if ( (signed int)UFG::GameStatTracker::GetStat(v3, IsBannedByCommunityManager) > 0 || !v2 )
    return 0;
  v4 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
  v5 = (UFG::MessageBuffer *)v4;
  if ( v4 )
  {
    v4->mNext = 0i64;
    v4[1].mNext = 0i64;
    LODWORD(v4[2].mNext) = 0;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = UFG::qMalloc(0x1BEEui64, "DataSynchronizer::MessageBuffer", 0i64);
  v5->mBuffer = (char *)v6;
  v5->mBufferSize = 7150;
  v5->mCurrentOffset = (char *)v6;
  LOBYTE(v6->mNext) = 0;
  UFG::OSuiteLeaderboardManager::ScanOrResetPlayerStats(v5);
  if ( LODWORD(v5->mCurrentOffset) == LODWORD(v5->mBuffer) )
  {
    if ( v5->mBuffer )
    {
      operator delete[](v5->mBuffer);
      v5->mBuffer = 0i64;
    }
    operator delete[](v5);
  }
  else
  {
    v7 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    v8 = v7;
    if ( v7 )
    {
      v9 = v7 + 1;
      v9->mNext = v9;
      v9[1].mNext = v9;
      v8->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable';
      v8->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdatePlayerStatsEvent::`vftable';
      v8[4].mNext = (UFG::allocator::free_link *)v5;
      LODWORD(v8[3].mNext) = 4;
    }
    else
    {
      v8 = 0i64;
    }
    UFG::OSuiteLeaderboardManager::QueueUpdateEvent(v1, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v8);
  }
  return 1;
}

// File Line: 1875
// RVA: 0x42F920
void __fastcall UFG::OSuiteLeaderboardManager::ResetStatSumsOnLoad(UFG::OSuiteLeaderboardManager *this)
{
  unsigned int *v1; // rsi
  signed __int64 v2; // r14
  UFG::GameStatTracker *v3; // rbp
  unsigned int v4; // edx
  int v5; // edx
  int v6; // edx
  UFG::PersistentData::MapInt *v7; // rax
  int v8; // edi
  UFG::qSymbol *v9; // rax
  UFG::PersistentData::Time *v10; // rax
  float v11; // xmm6_4
  UFG::qSymbol *v12; // rax
  UFG::qSymbol *v13; // rbx
  UFG::PersistentData::MapFloat *v14; // rax
  UFG::qSymbol *v15; // rbx
  UFG::PersistentData::MapInt *v16; // rax

  v1 = &UFG::sPlayerStatSubmissions[0].mGameStatId;
  v2 = 130i64;
  v3 = UFG::GameStatTracker::Instance();
  do
  {
    if ( v1[1] )
      goto LABEL_13;
    v4 = v1[2];
    if ( v4 )
    {
      v5 = v4 - 1;
      if ( v5 )
      {
        v6 = v5 - 1;
        if ( v6 )
        {
          if ( v6 != 2 )
            goto LABEL_13;
          v7 = UFG::GameStatTracker::GetMapInt(v3, (UFG::GameStat::MapInt32Stat)*v1);
          v8 = UFG::PersistentData::MapInt::GetTotal(v7);
          v9 = UFG::GameStat::GetSymbol((UFG::GameStat::MapInt32Stat)*v1);
          goto LABEL_12;
        }
        v10 = UFG::GameStatTracker::GetTimeStat(v3, (UFG::GameStat::TimeStat)*v1);
        v11 = UFG::PersistentData::Time::GetTotalTime(v10);
        v12 = UFG::GameStat::GetSymbol((UFG::GameStat::TimeStat)*v1);
      }
      else
      {
        v11 = UFG::GameStatTracker::GetStat(v3, (UFG::GameStat::FloatStat)*v1);
        v12 = UFG::GameStat::GetSymbol((UFG::GameStat::FloatStat)*v1);
      }
      v13 = v12;
      v14 = UFG::GameStatTracker::GetMapFloat(v3, PlayersStatsFloatListSum);
      UFG::PersistentData::MapFloat::SetStatus(v14, v13, v11);
      goto LABEL_13;
    }
    v8 = UFG::GameStatTracker::GetStat(v3, (UFG::GameStat::Int32Stat)*v1);
    v9 = UFG::GameStat::GetSymbol((UFG::GameStat::Int32Stat)*v1);
LABEL_12:
    v15 = v9;
    v16 = UFG::GameStatTracker::GetMapInt(v3, PlayersStatsIntListSum);
    UFG::PersistentData::MapInt::SetStatus(v16, v15, v8);
LABEL_13:
    v1 += 6;
    --v2;
  }
  while ( v2 );
}

// File Line: 1969
// RVA: 0x429530
void __fastcall UFG::OSuiteLeaderboardManager::UpdatePlayerStatsEvent::~UpdatePlayerStatsEvent(UFG::OSuiteLeaderboardManager::UpdatePlayerStatsEvent *this)
{
  UFG::OSuiteLeaderboardManager::UpdatePlayerStatsEvent *v1; // rbx
  UFG::MessageBuffer *v2; // rdi
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v3; // rdx
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v4; // rcx
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v5; // rax

  v1 = this;
  this->vfptr = (UFG::OSuiteLeaderboardManager::UpdateEventVtbl *)&UFG::OSuiteLeaderboardManager::UpdatePlayerStatsEvent::`vftable';
  v2 = this->mMessage;
  if ( v2 )
  {
    if ( v2->mBuffer )
    {
      operator delete[](v2->mBuffer);
      v2->mBuffer = 0i64;
    }
    operator delete[](v2);
    v1->mMessage = 0i64;
  }
  v1->vfptr = (UFG::OSuiteLeaderboardManager::UpdateEventVtbl *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable';
  v3 = (UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *)&v1->mPrev;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v3->mPrev = v3;
  v3->mNext = v3;
}

