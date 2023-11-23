// File Line: 39
// RVA: 0x42C730
signed __int64 __fastcall UFG::GetLeaderboardCategoryFromString(const char *pcString)
{
  unsigned int v1; // ebx
  signed __int64 result; // rax

  v1 = -1;
  result = UFG::qStringCompare(pcString, "StatAwards", -1);
  if ( (_DWORD)result )
  {
    if ( (unsigned int)UFG::qStringCompare(pcString, "StatGames", -1) )
    {
      if ( (unsigned int)UFG::qStringCompare(pcString, "Missions", -1) )
      {
        if ( !(unsigned int)UFG::qStringCompare(pcString, "Races", -1) )
          return 3;
        return v1;
      }
      else
      {
        return 2i64;
      }
    }
    else
    {
      return 1i64;
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
  UFG::qString::qString(&stru_1423F8CD8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F8D00, &customCaption);
  UFG::qString::qString(&stru_1423F8D08, "$LEADERBOARD_STATAWARDS_OVERALL_DESC");
  UFG::qString::qString(&stru_1423F8D30, &customCaption);
  unk_1423F8D58 = "Rank";
  unk_1423F8D60 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423F8D70 = 0i64;
  UFG::qString::qString(&stru_1423F8D78, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F8DA0, "Main");
  unk_1423F8DA8 = 1;
  unk_1423F8DAC = 1;
  UFG::qString::qString(&stru_1423F8DB0, "StatAwardsFluidStriker");
  UFG::qSymbol::create_from_string(&stru_1423F8DD8, "StatAwardsFluidStriker");
  UFG::qString::qString(&stru_1423F8DE0, "$LEADERBOARD_STATAWARDS_FLUID_STRIKER");
  unk_1423F8E08 = 0;
  UFG::qString::qString(&stru_1423F8E10, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F8E38, &customCaption);
  UFG::qString::qString(&stru_1423F8E40, "$LEADERBOARD_STATAWARDS_FLUID_STRIKER_DESC");
  UFG::qString::qString(&stru_1423F8E68, &customCaption);
  unk_1423F8E90 = "Int32";
  unk_1423F8E98 = 50;
  unk_1423F8E9C = 25;
  unk_1423F8EA0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423F8EB0, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F8ED8, "Main");
  unk_1423F8EE0 = 2;
  unk_1423F8EE4 = 2;
  UFG::qString::qString(&stru_1423F8EE8, "StatAwardsHeadhunter");
  UFG::qSymbol::create_from_string(&stru_1423F8F10, "StatAwardsHeadhunter");
  UFG::qString::qString(&stru_1423F8F18, "$LEADERBOARD_STATAWARDS_HEADHUNTER");
  unk_1423F8F40 = 0;
  UFG::qString::qString(&stru_1423F8F48, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F8F70, &customCaption);
  UFG::qString::qString(&stru_1423F8F78, "$LEADERBOARD_STATAWARDS_HEADHUNTER_DESC");
  UFG::qString::qString(&stru_1423F8FA0, &customCaption);
  unk_1423F8FC8 = "Int32";
  unk_1423F8FD0 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423F8FE0 = 0i64;
  UFG::qString::qString(&stru_1423F8FE8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9010, "Main");
  unk_1423F9018 = 3;
  unk_1423F901C = 3;
  UFG::qString::qString(&stru_1423F9020, "StatAwardsLuckyShooter");
  UFG::qSymbol::create_from_string(&stru_1423F9048, "StatAwardsLuckyShooter");
  UFG::qString::qString(&stru_1423F9050, "$LEADERBOARD_STATAWARDS_LUCKY_SHOOTER");
  unk_1423F9078 = 0;
  UFG::qString::qString(&stru_1423F9080, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F90A8, &customCaption);
  UFG::qString::qString(&stru_1423F90B0, "$LEADERBOARD_STATAWARDS_LUCKY_SHOOTER_DESC");
  UFG::qString::qString(&stru_1423F90D8, &customCaption);
  unk_1423F9100 = "Int32";
  unk_1423F9108 = 10;
  unk_1423F910C = 5;
  unk_1423F9110 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423F9120, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9148, "Main");
  unk_1423F9150 = 4;
  unk_1423F9154 = 4;
  UFG::qString::qString(&stru_1423F9158, "StatAwardsFirestarter");
  UFG::qSymbol::create_from_string(&stru_1423F9180, "StatAwardsFirestarter");
  UFG::qString::qString(&stru_1423F9188, "$LEADERBOARD_STATAWARDS_FIRESTARTER");
  unk_1423F91B0 = 0;
  UFG::qString::qString(&stru_1423F91B8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F91E0, &customCaption);
  UFG::qString::qString(&stru_1423F91E8, "$LEADERBOARD_STATAWARDS_FIRESTARTER_DESC");
  UFG::qString::qString(&stru_1423F9210, &customCaption);
  unk_1423F9238 = "Int32";
  unk_1423F9240 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423F9250 = 0i64;
  UFG::qString::qString(&stru_1423F9258, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9280, "Main");
  unk_1423F9288 = 5;
  unk_1423F928C = 5;
  UFG::qString::qString(&stru_1423F9290, "StatAwardsSniper");
  UFG::qSymbol::create_from_string(&stru_1423F92B8, "StatAwardsSniper");
  UFG::qString::qString(&stru_1423F92C0, "$LEADERBOARD_STATAWARDS_SNIPER");
  unk_1423F92E8 = 0;
  UFG::qString::qString(&stru_1423F92F0, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9318, &customCaption);
  UFG::qString::qString(&stru_1423F9320, "$LEADERBOARD_STATAWARDS_SNIPER_DESC");
  UFG::qString::qString(&stru_1423F9348, &customCaption);
  unk_1423F9370 = "Percentage";
  unk_1423F9378 = 50;
  unk_1423F937C = 30;
  unk_1423F9380 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423F9390, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F93B8, "Main");
  unk_1423F93C0 = 6;
  unk_1423F93C4 = 6;
  UFG::qString::qString(&stru_1423F93C8, "StatAwardsGunman");
  UFG::qSymbol::create_from_string(&stru_1423F93F0, "StatAwardsGunman");
  UFG::qString::qString(&stru_1423F93F8, "$LEADERBOARD_STATAWARDS_GUNMAN");
  unk_1423F9420 = 0;
  UFG::qString::qString(&stru_1423F9428, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9450, &customCaption);
  UFG::qString::qString(&stru_1423F9458, "$LEADERBOARD_STATAWARDS_GUNMAN_DESC");
  UFG::qString::qString(&stru_1423F9480, &customCaption);
  unk_1423F94A8 = "Int32";
  unk_1423F94B0 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423F94C0 = 0i64;
  UFG::qString::qString(&stru_1423F94C8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F94F0, "Main");
  unk_1423F94F8 = 7;
  unk_1423F94FC = 7;
  UFG::qString::qString(&stru_1423F9500, "StatAwardsNinja");
  UFG::qSymbol::create_from_string(&stru_1423F9528, "StatAwardsNinja");
  UFG::qString::qString(&stru_1423F9530, "$LEADERBOARD_STATAWARDS_NINJA");
  unk_1423F9558 = 0;
  UFG::qString::qString(&stru_1423F9560, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9588, &customCaption);
  UFG::qString::qString(&stru_1423F9590, "$LEADERBOARD_STATAWARDS_NINJA_DESC");
  UFG::qString::qString(&stru_1423F95B8, &customCaption);
  unk_1423F95E0 = "Int32";
  unk_1423F95E8 = 10;
  unk_1423F95EC = 5;
  unk_1423F95F0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423F9600, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9628, "Main");
  unk_1423F9630 = 8;
  unk_1423F9634 = 8;
  UFG::qString::qString(&stru_1423F9638, "StatAwardsBonebreaker");
  UFG::qSymbol::create_from_string(&stru_1423F9660, "StatAwardsBonebreaker");
  UFG::qString::qString(&stru_1423F9668, "$LEADERBOARD_STATAWARDS_BONEBREAKER");
  unk_1423F9690 = 0;
  UFG::qString::qString(&stru_1423F9698, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F96C0, &customCaption);
  UFG::qString::qString(&stru_1423F96C8, "$LEADERBOARD_STATAWARDS_BONEBREAKER_DESC");
  UFG::qString::qString(&stru_1423F96F0, &customCaption);
  unk_1423F9718 = "Int32";
  unk_1423F9720 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423F9730 = 0i64;
  UFG::qString::qString(&stru_1423F9738, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9760, "Main");
  unk_1423F9768 = 9;
  unk_1423F976C = 9;
  UFG::qString::qString(&stru_1423F9770, "StatAwardsEnvironmentalist");
  UFG::qSymbol::create_from_string(&stru_1423F9798, "StatAwardsEnvironmentalist");
  UFG::qString::qString(&stru_1423F97A0, "$LEADERBOARD_STATAWARDS_ENVIRONMENTALIST");
  unk_1423F97C8 = 0;
  UFG::qString::qString(&stru_1423F97D0, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F97F8, &customCaption);
  UFG::qString::qString(&stru_1423F9800, "$LEADERBOARD_STATAWARDS_ENVIRONMENTALIST_DESC");
  UFG::qString::qString(&stru_1423F9828, &customCaption);
  unk_1423F9850 = "Int32";
  unk_1423F9858 = 50;
  unk_1423F985C = 25;
  unk_1423F9860 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423F9870, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9898, "Main");
  unk_1423F98A0 = 10;
  unk_1423F98A4 = 10;
  UFG::qString::qString(&stru_1423F98A8, "StatAwardsHandyman");
  UFG::qSymbol::create_from_string(&stru_1423F98D0, "StatAwardsHandyman");
  UFG::qString::qString(&stru_1423F98D8, "$LEADERBOARD_STATAWARDS_HANDYMAN");
  unk_1423F9900 = 0;
  UFG::qString::qString(&stru_1423F9908, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9930, &customCaption);
  UFG::qString::qString(&stru_1423F9938, "$LEADERBOARD_STATAWARDS_HANDYMAN_DESC");
  UFG::qString::qString(&stru_1423F9960, &customCaption);
  unk_1423F9988 = "Int32";
  unk_1423F9990 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423F99A0 = 0i64;
  UFG::qString::qString(&stru_1423F99A8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F99D0, "Main");
  unk_1423F99D8 = 11;
  unk_1423F99DC = 11;
  UFG::qString::qString(&stru_1423F99E0, "StatAwardsDisarming");
  UFG::qSymbol::create_from_string(&stru_1423F9A08, "StatAwardsDisarming");
  UFG::qString::qString(&stru_1423F9A10, "$LEADERBOARD_STATAWARDS_DISARMING");
  unk_1423F9A38 = 0;
  UFG::qString::qString(&stru_1423F9A40, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9A68, &customCaption);
  UFG::qString::qString(&stru_1423F9A70, "$LEADERBOARD_STATAWARDS_DISARMING_DESC");
  UFG::qString::qString(&stru_1423F9A98, &customCaption);
  unk_1423F9AC0 = "Int32";
  unk_1423F9AC8 = 50;
  unk_1423F9ACC = 25;
  unk_1423F9AD0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423F9AE0, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9B08, "Main");
  unk_1423F9B10 = 12;
  unk_1423F9B14 = 12;
  UFG::qString::qString(&stru_1423F9B18, "StatAwardsDefence");
  UFG::qSymbol::create_from_string(&stru_1423F9B40, "StatAwardsDefence");
  UFG::qString::qString(&stru_1423F9B48, "$LEADERBOARD_STATAWARDS_DEFENCE");
  unk_1423F9B70 = 0;
  UFG::qString::qString(&stru_1423F9B78, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9BA0, &customCaption);
  UFG::qString::qString(&stru_1423F9BA8, "$LEADERBOARD_STATAWARDS_DEFENCE_DESC");
  UFG::qString::qString(&stru_1423F9BD0, &customCaption);
  unk_1423F9BF8 = "Int32";
  unk_1423F9C00 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423F9C10 = 0i64;
  UFG::qString::qString(&stru_1423F9C18, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9C40, "Main");
  unk_1423F9C48 = 13;
  unk_1423F9C4C = 13;
  UFG::qString::qString(&stru_1423F9C50, "StatAwardsFastTalker");
  UFG::qSymbol::create_from_string(&stru_1423F9C78, "StatAwardsFastTalker");
  UFG::qString::qString(&stru_1423F9C80, "$LEADERBOARD_STATAWARDS_FAST_TALKER");
  unk_1423F9CA8 = 0;
  UFG::qString::qString(&stru_1423F9CB0, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9CD8, &customCaption);
  UFG::qString::qString(&stru_1423F9CE0, "$LEADERBOARD_STATAWARDS_FAST_TALKER_DESC");
  UFG::qString::qString(&stru_1423F9D08, &customCaption);
  unk_1423F9D30 = "Int32";
  unk_1423F9D38 = 10;
  unk_1423F9D3C = 5;
  unk_1423F9D40 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423F9D50, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9D78, "Main");
  unk_1423F9D80 = 14;
  unk_1423F9D84 = 14;
  UFG::qString::qString(&stru_1423F9D88, "StatAwardsDeadeye");
  UFG::qSymbol::create_from_string(&stru_1423F9DB0, "StatAwardsDeadeye");
  UFG::qString::qString(&stru_1423F9DB8, "$LEADERBOARD_STATAWARDS_DEADEYE");
  unk_1423F9DE0 = 0;
  UFG::qString::qString(&stru_1423F9DE8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9E10, &customCaption);
  UFG::qString::qString(&stru_1423F9E18, "$LEADERBOARD_STATAWARDS_DEADEYE_DESC");
  UFG::qString::qString(&stru_1423F9E40, &customCaption);
  unk_1423F9E68 = "Int32";
  unk_1423F9E70 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423F9E80 = 0i64;
  UFG::qString::qString(&stru_1423F9E88, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9EB0, "Main");
  unk_1423F9EB8 = 15;
  unk_1423F9EBC = 15;
  UFG::qString::qString(&stru_1423F9EC0, "StatAwardsMartialArtist");
  UFG::qSymbol::create_from_string(&stru_1423F9EE8, "StatAwardsMartialArtist");
  UFG::qString::qString(&stru_1423F9EF0, "$LEADERBOARD_STATAWARDS_MARTIAL_ARTIST");
  unk_1423F9F18 = 0;
  UFG::qString::qString(&stru_1423F9F20, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9F48, &customCaption);
  UFG::qString::qString(&stru_1423F9F50, "$LEADERBOARD_STATAWARDS_MARTIAL_ARTIST_DESC");
  UFG::qString::qString(&stru_1423F9F78, &customCaption);
  unk_1423F9FA0 = "Int32";
  unk_1423F9FA8 = 100;
  unk_1423F9FAC = 50;
  unk_1423F9FB0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423F9FC0, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423F9FE8, "Main");
  unk_1423F9FF0 = 16;
  unk_1423F9FF4 = 16;
  UFG::qString::qString(&stru_1423F9FF8, "StatAwardsEnforcer");
  UFG::qSymbol::create_from_string(&stru_1423FA020, "StatAwardsEnforcer");
  UFG::qString::qString(&stru_1423FA028, "$LEADERBOARD_STATAWARDS_ENFORCER");
  unk_1423FA050 = 0;
  UFG::qString::qString(&stru_1423FA058, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA080, &customCaption);
  UFG::qString::qString(&stru_1423FA088, "$LEADERBOARD_STATAWARDS_ENFORCER_DESC");
  UFG::qString::qString(&stru_1423FA0B0, &customCaption);
  unk_1423FA0D8 = "Int32";
  unk_1423FA0E0 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FA0F0 = 0i64;
  UFG::qString::qString(&stru_1423FA0F8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA120, "Main");
  unk_1423FA128 = 17;
  unk_1423FA12C = 17;
  UFG::qString::qString(&stru_1423FA130, "StatAwardsSafeDriver");
  UFG::qSymbol::create_from_string(&stru_1423FA158, "StatAwardsSafeDriver");
  UFG::qString::qString(&stru_1423FA160, "$LEADERBOARD_STATAWARDS_SAFE_DRIVER");
  unk_1423FA188 = 0;
  UFG::qString::qString(&stru_1423FA190, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA1B8, &customCaption);
  UFG::qString::qString(&stru_1423FA1C0, "$LEADERBOARD_STATAWARDS_SAFE_DRIVER_DESC");
  UFG::qString::qString(&stru_1423FA1E8, &customCaption);
  unk_1423FA210 = "RaceTime";
  unk_1423FA218 = 1800;
  unk_1423FA21C = 900;
  unk_1423FA220 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FA230, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA258, "Main");
  unk_1423FA260 = 18;
  unk_1423FA264 = 18;
  UFG::qString::qString(&stru_1423FA268, "StatAwardsRecklessDriver");
  UFG::qSymbol::create_from_string(&stru_1423FA290, "StatAwardsRecklessDriver");
  UFG::qString::qString(&stru_1423FA298, "$LEADERBOARD_STATAWARDS_RECKLESS_DRIVER");
  unk_1423FA2C0 = 0;
  UFG::qString::qString(&stru_1423FA2C8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA2F0, &customCaption);
  UFG::qString::qString(&stru_1423FA2F8, "$LEADERBOARD_STATAWARDS_RECKLESS_DRIVER_DESC");
  UFG::qString::qString(&stru_1423FA320, &customCaption);
  unk_1423FA348 = "RaceTime";
  unk_1423FA350 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FA360 = 0i64;
  UFG::qString::qString(&stru_1423FA368, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA390, "Main");
  unk_1423FA398 = 19;
  unk_1423FA39C = 19;
  UFG::qString::qString(&stru_1423FA3A0, "StatAwardsHijacker");
  UFG::qSymbol::create_from_string(&stru_1423FA3C8, "StatAwardsHijacker");
  UFG::qString::qString(&stru_1423FA3D0, "$LEADERBOARD_STATAWARDS_HIJACKER");
  unk_1423FA3F8 = 0;
  UFG::qString::qString(&stru_1423FA400, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA428, &customCaption);
  UFG::qString::qString(&stru_1423FA430, "$LEADERBOARD_STATAWARDS_HIJACKER_DESC");
  UFG::qString::qString(&stru_1423FA458, &customCaption);
  unk_1423FA480 = "Int32";
  unk_1423FA488 = 20;
  unk_1423FA48C = 10;
  unk_1423FA490 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FA4A0, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA4C8, "Main");
  unk_1423FA4D0 = 20;
  unk_1423FA4D4 = 20;
  UFG::qString::qString(&stru_1423FA4D8, "StatAwardsWrecker");
  UFG::qSymbol::create_from_string(&stru_1423FA500, "StatAwardsWrecker");
  UFG::qString::qString(&stru_1423FA508, "$LEADERBOARD_STATAWARDS_WRECKER");
  unk_1423FA530 = 0;
  UFG::qString::qString(&stru_1423FA538, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA560, &customCaption);
  UFG::qString::qString(&stru_1423FA568, "$LEADERBOARD_STATAWARDS_WRECKER_DESC");
  UFG::qString::qString(&stru_1423FA590, &customCaption);
  unk_1423FA5B8 = "Int32";
  unk_1423FA5C0 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FA5D0 = 0i64;
  UFG::qString::qString(&stru_1423FA5D8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA600, "Main");
  unk_1423FA608 = 21;
  unk_1423FA60C = 21;
  UFG::qString::qString(&stru_1423FA610, "StatAwardsRacer");
  UFG::qSymbol::create_from_string(&stru_1423FA638, "StatAwardsRacer");
  UFG::qString::qString(&stru_1423FA640, "$LEADERBOARD_STATAWARDS_RACER");
  unk_1423FA668 = 0;
  UFG::qString::qString(&stru_1423FA670, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA698, &customCaption);
  UFG::qString::qString(&stru_1423FA6A0, "$LEADERBOARD_STATAWARDS_RACER_DESC");
  UFG::qString::qString(&stru_1423FA6C8, &customCaption);
  unk_1423FA6F0 = "Int32";
  unk_1423FA6F8 = 17;
  unk_1423FA6FC = 10;
  unk_1423FA700 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FA710, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA738, "Main");
  unk_1423FA740 = 22;
  unk_1423FA744 = 22;
  UFG::qString::qString(&stru_1423FA748, "StatAwardsMogul");
  UFG::qSymbol::create_from_string(&stru_1423FA770, "StatAwardsMogul");
  UFG::qString::qString(&stru_1423FA778, "$LEADERBOARD_STATAWARDS_MOGUL");
  unk_1423FA7A0 = 0;
  UFG::qString::qString(&stru_1423FA7A8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA7D0, &customCaption);
  UFG::qString::qString(&stru_1423FA7D8, "$LEADERBOARD_STATAWARDS_MOGUL_DESC");
  UFG::qString::qString(&stru_1423FA800, &customCaption);
  unk_1423FA828 = "Money";
  unk_1423FA830 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FA840 = 0i64;
  UFG::qString::qString(&stru_1423FA848, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA870, "Main");
  unk_1423FA878 = 23;
  unk_1423FA87C = 23;
  UFG::qString::qString(&stru_1423FA880, "StatAwardsBigSpender");
  UFG::qSymbol::create_from_string(&stru_1423FA8A8, "StatAwardsBigSpender");
  UFG::qString::qString(&stru_1423FA8B0, "$LEADERBOARD_STATAWARDS_BIG_SPENDER");
  unk_1423FA8D8 = 0;
  UFG::qString::qString(&stru_1423FA8E0, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA908, &customCaption);
  UFG::qString::qString(&stru_1423FA910, "$LEADERBOARD_STATAWARDS_BIG_SPENDER_DESC");
  UFG::qString::qString(&stru_1423FA938, &customCaption);
  unk_1423FA960 = "Money";
  unk_1423FA968 = 2000000;
  unk_1423FA96C = 500000;
  unk_1423FA970 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FA980, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FA9A8, "Main");
  unk_1423FA9B0 = 24;
  unk_1423FA9B4 = 24;
  UFG::qString::qString(&stru_1423FA9B8, "StatAwardsGambler");
  UFG::qSymbol::create_from_string(&stru_1423FA9E0, "StatAwardsGambler");
  UFG::qString::qString(&stru_1423FA9E8, "$LEADERBOARD_STATAWARDS_GAMBLER");
  unk_1423FAA10 = 0;
  UFG::qString::qString(&stru_1423FAA18, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FAA40, &customCaption);
  UFG::qString::qString(&stru_1423FAA48, "$LEADERBOARD_STATAWARDS_GAMBLER_DESC");
  UFG::qString::qString(&stru_1423FAA70, &customCaption);
  unk_1423FAA98 = "Money";
  unk_1423FAAA0 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FAAB0 = 0i64;
  UFG::qString::qString(&stru_1423FAAB8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FAAE0, "Main");
  unk_1423FAAE8 = 25;
  unk_1423FAAEC = 25;
  UFG::qString::qString(&stru_1423FAAF0, "StatAwardsCompletionist");
  UFG::qSymbol::create_from_string(&stru_1423FAB18, "StatAwardsCompletionist");
  UFG::qString::qString(&stru_1423FAB20, "$LEADERBOARD_STATAWARDS_COMPLETIONIST");
  unk_1423FAB48 = 0;
  UFG::qString::qString(&stru_1423FAB50, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FAB78, &customCaption);
  UFG::qString::qString(&stru_1423FAB80, "$LEADERBOARD_STATAWARDS_COMPLETIONIST_DESC");
  UFG::qString::qString(&stru_1423FABA8, &customCaption);
  unk_1423FABD0 = "Percentage";
  unk_1423FABD8 = 100;
  unk_1423FABDC = 60;
  unk_1423FABE0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FABF0, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FAC18, "Main");
  unk_1423FAC20 = 26;
  unk_1423FAC24 = 26;
  UFG::qString::qString(&stru_1423FAC28, "StatAwardsExplorer");
  UFG::qSymbol::create_from_string(&stru_1423FAC50, "StatAwardsExplorer");
  UFG::qString::qString(&stru_1423FAC58, "$LEADERBOARD_STATAWARDS_EXPLORER");
  unk_1423FAC80 = 0;
  UFG::qString::qString(&stru_1423FAC88, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FACB0, &customCaption);
  UFG::qString::qString(&stru_1423FACB8, "$LEADERBOARD_STATAWARDS_EXPLORER_DESC");
  UFG::qString::qString(&stru_1423FACE0, &customCaption);
  unk_1423FAD08 = "Int32";
  unk_1423FAD10 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FAD20 = 0i64;
  UFG::qString::qString(&stru_1423FAD28, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FAD50, "Main");
  unk_1423FAD58 = 27;
  unk_1423FAD5C = 27;
  UFG::qString::qString(&stru_1423FAD60, "StatAwardsSurvivor");
  UFG::qSymbol::create_from_string(&stru_1423FAD88, "StatAwardsSurvivor");
  UFG::qString::qString(&stru_1423FAD90, "$LEADERBOARD_STATAWARDS_SURVIVOR");
  unk_1423FADB8 = 0;
  UFG::qString::qString(&stru_1423FADC0, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FADE8, &customCaption);
  UFG::qString::qString(&stru_1423FADF0, "$LEADERBOARD_STATAWARDS_SURVIVOR_DESC");
  UFG::qString::qString(&stru_1423FAE18, &customCaption);
  unk_1423FAE40 = "RaceTime";
  unk_1423FAE48 = 1200;
  unk_1423FAE4C = 600;
  unk_1423FAE50 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FAE60, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FAE88, "Main");
  unk_1423FAE90 = 28;
  unk_1423FAE94 = 28;
  UFG::qString::qString(&stru_1423FAE98, "StatAwardsCopKiller");
  UFG::qSymbol::create_from_string(&stru_1423FAEC0, "StatAwardsCopKiller");
  UFG::qString::qString(&stru_1423FAEC8, "$LEADERBOARD_STATAWARDS_COP_KILLER");
  unk_1423FAEF0 = 0;
  UFG::qString::qString(&stru_1423FAEF8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FAF20, &customCaption);
  UFG::qString::qString(&stru_1423FAF28, "$LEADERBOARD_STATAWARDS_COP_KILLER_DESC");
  UFG::qString::qString(&stru_1423FAF50, &customCaption);
  unk_1423FAF78 = "Int32";
  unk_1423FAF80 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FAF90 = 0i64;
  UFG::qString::qString(&stru_1423FAF98, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FAFC0, "Main");
  unk_1423FAFC8 = 29;
  unk_1423FAFCC = 29;
  UFG::qString::qString(&stru_1423FAFD0, "StatAwardsPublicEnemy");
  UFG::qSymbol::create_from_string(&stru_1423FAFF8, "StatAwardsPublicEnemy");
  UFG::qString::qString(&stru_1423FB000, "$LEADERBOARD_STATAWARDS_PUBLIC_ENEMY");
  unk_1423FB028 = 0;
  UFG::qString::qString(&stru_1423FB030, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB058, &customCaption);
  UFG::qString::qString(&stru_1423FB060, "$LEADERBOARD_STATAWARDS_PUBLIC_ENEMY_DESC");
  UFG::qString::qString(&stru_1423FB088, &customCaption);
  unk_1423FB0B0 = "Int32";
  unk_1423FB0B8 = 200;
  unk_1423FB0BC = 100;
  unk_1423FB0C0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FB0D0, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB0F8, "Main");
  unk_1423FB100 = 100;
  unk_1423FB104 = 30;
  UFG::qString::qString(&stru_1423FB108, "StatAwardsJiangShiDefeated");
  UFG::qSymbol::create_from_string(&stru_1423FB130, "StatAwardsJiangShiDefeated");
  UFG::qString::qString(&stru_1423FB138, "$LEADERBOARD_STATAWARDS_JIANG_SHI_DEFEATED");
  unk_1423FB160 = 0;
  UFG::qString::qString(&stru_1423FB168, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB190, &customCaption);
  UFG::qString::qString(&stru_1423FB198, "$LEADERBOARD_STATAWARDS_JIANG_SHI_DEFEATED_DESC");
  UFG::qString::qString(&stru_1423FB1C0, &customCaption);
  unk_1423FB1E8 = "Int32";
  unk_1423FB1F0 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FB200 = 0i64;
  UFG::qString::qString(&stru_1423FB208, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB230, "DLC_Ghost");
  unk_1423FB238 = 101;
  unk_1423FB23C = 31;
  UFG::qString::qString(&stru_1423FB240, "StatAwardsYaoguaiDefeated");
  UFG::qSymbol::create_from_string(&stru_1423FB268, "StatAwardsYaoguaiDefeated");
  UFG::qString::qString(&stru_1423FB270, "$LEADERBOARD_STATAWARDS_YAOGUAI_DEFEATED");
  unk_1423FB298 = 0;
  UFG::qString::qString(&stru_1423FB2A0, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB2C8, &customCaption);
  UFG::qString::qString(&stru_1423FB2D0, "$LEADERBOARD_STATAWARDS_YAOGUAI_DEFEATED_DESC");
  UFG::qString::qString(&stru_1423FB2F8, &customCaption);
  unk_1423FB320 = "Int32";
  unk_1423FB328 = 20;
  unk_1423FB32C = 10;
  unk_1423FB330 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FB340, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB368, "DLC_Ghost");
  unk_1423FB370 = 102;
  unk_1423FB374 = 32;
  UFG::qString::qString(&stru_1423FB378, "StatAwardsYaoguaiPeachwooded");
  UFG::qSymbol::create_from_string(&stru_1423FB3A0, "StatAwardsYaoguaiPeachwooded");
  UFG::qString::qString(&stru_1423FB3A8, "$LEADERBOARD_STATAWARDS_YAOGUAI_PEACHWOODED");
  unk_1423FB3D0 = 0;
  UFG::qString::qString(&stru_1423FB3D8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB400, &customCaption);
  UFG::qString::qString(&stru_1423FB408, "$LEADERBOARD_STATAWARDS_YAOGUAI_PEACHWOODED_DESC");
  UFG::qString::qString(&stru_1423FB430, &customCaption);
  unk_1423FB458 = "Int32";
  unk_1423FB460 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FB470 = 0i64;
  UFG::qString::qString(&stru_1423FB478, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB4A0, "DLC_Ghost");
  unk_1423FB4A8 = 103;
  unk_1423FB4AC = 33;
  UFG::qString::qString(&stru_1423FB4B0, "StatAwardsBitesAvoided");
  UFG::qSymbol::create_from_string(&stru_1423FB4D8, "StatAwardsBitesAvoided");
  UFG::qString::qString(&stru_1423FB4E0, "$LEADERBOARD_STATAWARDS_BITES_AVOIDED");
  unk_1423FB508 = 0;
  UFG::qString::qString(&stru_1423FB510, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB538, &customCaption);
  UFG::qString::qString(&stru_1423FB540, "$LEADERBOARD_STATAWARDS_BITES_AVOIDED_DESC");
  UFG::qString::qString(&stru_1423FB568, &customCaption);
  unk_1423FB590 = "Int32";
  unk_1423FB598 = 100;
  unk_1423FB59C = 60;
  unk_1423FB5A0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FB5B0, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB5D8, "DLC_Ghost");
  unk_1423FB5E0 = 104;
  unk_1423FB5E4 = 34;
  UFG::qString::qString(&stru_1423FB5E8, "StatAwardsHellMoneyShrines");
  UFG::qSymbol::create_from_string(&stru_1423FB610, "StatAwardsHellMoneyShrines");
  UFG::qString::qString(&stru_1423FB618, "$LEADERBOARD_STATAWARDS_HELL_MONEY_SHRINES");
  unk_1423FB640 = 0;
  UFG::qString::qString(&stru_1423FB648, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB670, &customCaption);
  UFG::qString::qString(&stru_1423FB678, "$LEADERBOARD_STATAWARDS_HELL_MONEY_SHRINES_DESC");
  UFG::qString::qString(&stru_1423FB6A0, &customCaption);
  unk_1423FB6C8 = "Int32";
  unk_1423FB6D0 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FB6E0 = 0i64;
  UFG::qString::qString(&stru_1423FB6E8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB710, "DLC_Ghost");
  unk_1423FB718 = 30i64;
  UFG::qString::qString(&stru_1423FB720, "StatGamesCarJump");
  UFG::qSymbol::create_from_string(&stru_1423FB748, "StatGamesCarJump");
  UFG::qString::qString(&stru_1423FB750, "$LEADERBOARD_CHALLENGES_CAR_JUMP");
  unk_1423FB778 = 1;
  UFG::qString::qString(&stru_1423FB780, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB7A8, &customCaption);
  UFG::qString::qString(&stru_1423FB7B0, "$LEADERBOARD_CHALLENGES_CAR_JUMP_DESC");
  UFG::qString::qString(&stru_1423FB7D8, &customCaption);
  unk_1423FB800 = "%.2f m";
  unk_1423FB808 = -1i64;
  unk_1423FB810 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FB820, "$LEADERBOARD_CHALLENGES_CAR_JUMP_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FB848, "Main");
  unk_1423FB850 = 31;
  unk_1423FB854 = 1;
  UFG::qString::qString(&stru_1423FB858, "StatGamesBikeJump");
  UFG::qSymbol::create_from_string(&stru_1423FB880, "StatGamesBikeJump");
  UFG::qString::qString(&stru_1423FB888, "$LEADERBOARD_CHALLENGES_BIKE_JUMP");
  unk_1423FB8B0 = 1;
  UFG::qString::qString(&stru_1423FB8B8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FB8E0, &customCaption);
  UFG::qString::qString(&stru_1423FB8E8, "$LEADERBOARD_CHALLENGES_BIKE_JUMP_DESC");
  UFG::qString::qString(&stru_1423FB910, &customCaption);
  unk_1423FB938 = "%.2f m";
  unk_1423FB940 = _mm_load_si128((const __m128i *)&_xmm);
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
  UFG::qString::qString(&stru_1423FB9F0, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FBA18, &customCaption);
  UFG::qString::qString(&stru_1423FBA20, "$LEADERBOARD_CHALLENGES_WHEELIE_DISTANCE_DESC");
  UFG::qString::qString(&stru_1423FBA48, &customCaption);
  unk_1423FBA70 = "%.1f s";
  unk_1423FBA78 = -1i64;
  unk_1423FBA80 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FBA90, "$LEADERBOARD_CHALLENGES_WHEELIE_DISTANCE_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FBAB8, "Main");
  unk_1423FBAC0 = 33;
  unk_1423FBAC4 = 5;
  UFG::qString::qString(&stru_1423FBAC8, "StatGamesLongestCarMaxSpeed");
  UFG::qSymbol::create_from_string(&stru_1423FBAF0, "StatGamesLongestCarMaxSpeed");
  UFG::qString::qString(&stru_1423FBAF8, "$LEADERBOARD_CHALLENGES_LONGEST_CAR_MAX_SPEED");
  unk_1423FBB20 = 1;
  UFG::qString::qString(&stru_1423FBB28, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FBB50, &customCaption);
  UFG::qString::qString(&stru_1423FBB58, "$LEADERBOARD_CHALLENGES_LONGEST_CAR_MAX_SPEED_DESC");
  UFG::qString::qString(&stru_1423FBB80, &customCaption);
  unk_1423FBBA8 = "%.1f s";
  unk_1423FBBB0 = _mm_load_si128((const __m128i *)&_xmm);
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
  UFG::qString::qString(&stru_1423FBC60, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FBC88, &customCaption);
  UFG::qString::qString(&stru_1423FBC90, "$LEADERBOARD_CHALLENGES_VEHICLE_TAKE_DOWN_STREAK_DESC");
  UFG::qString::qString(&stru_1423FBCB8, &customCaption);
  unk_1423FBCE0 = "%d";
  unk_1423FBCE8 = -1i64;
  unk_1423FBCF0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FBD00, "$LEADERBOARD_CHALLENGES_VEHICLE_TAKE_DOWN_STREAK_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FBD28, "Main");
  unk_1423FBD30 = 35;
  unk_1423FBD34 = 7;
  UFG::qString::qString(&stru_1423FBD38, "StatGamesLongestNoDamageDriving");
  UFG::qSymbol::create_from_string(&stru_1423FBD60, "StatGamesLongestNoDamageDriving");
  UFG::qString::qString(&stru_1423FBD68, "$LEADERBOARD_CHALLENGES_LONGEST_NO_DAMAGE_DRIVING");
  unk_1423FBD90 = 1;
  UFG::qString::qString(&stru_1423FBD98, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FBDC0, &customCaption);
  UFG::qString::qString(&stru_1423FBDC8, "$LEADERBOARD_CHALLENGES_LONGEST_NO_DAMAGE_DRIVING_DESC");
  UFG::qString::qString(&stru_1423FBDF0, &customCaption);
  unk_1423FBE18 = "%.1f s";
  unk_1423FBE20 = _mm_load_si128((const __m128i *)&_xmm);
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
  UFG::qString::qString(&stru_1423FBED0, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FBEF8, &customCaption);
  UFG::qString::qString(&stru_1423FBF00, "$LEADERBOARD_CHALLENGES_LONGEST_HIT_AND_RUN_DESC");
  UFG::qString::qString(&stru_1423FBF28, &customCaption);
  unk_1423FBF50 = "%d";
  unk_1423FBF58 = -1i64;
  unk_1423FBF60 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FBF70, "$LEADERBOARD_CHALLENGES_LONGEST_HIT_AND_RUN_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FBF98, "Main");
  unk_1423FBFA0 = 37;
  unk_1423FBFA4 = 9;
  UFG::qString::qString(&stru_1423FBFA8, "StatGamesCoinsCollected");
  UFG::qSymbol::create_from_string(&stru_1423FBFD0, "StatGamesCoinsCollected");
  UFG::qString::qString(&stru_1423FBFD8, "$LEADERBOARD_CHALLENGES_COINS_COLLECTED");
  unk_1423FC000 = 1;
  UFG::qString::qString(&stru_1423FC008, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC030, &customCaption);
  UFG::qString::qString(&stru_1423FC038, "$LEADERBOARD_CHALLENGES_COINS_COLLECTED_DESC");
  UFG::qString::qString(&stru_1423FC060, &customCaption);
  unk_1423FC088 = "HK $ %d";
  unk_1423FC090 = _mm_load_si128((const __m128i *)&_xmm);
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
  UFG::qString::qString(&stru_1423FC140, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC168, &customCaption);
  UFG::qString::qString(&stru_1423FC170, "$LEADERBOARD_CHALLENGES_LONGEST_CHASE_DESC");
  UFG::qString::qString(&stru_1423FC198, &customCaption);
  unk_1423FC1C0 = "%.1f s";
  unk_1423FC1C8 = -1i64;
  unk_1423FC1D0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FC1E0, "$LEADERBOARD_CHALLENGES_LONGEST_CHASE_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FC208, "Main");
  unk_1423FC210 = 39;
  unk_1423FC214 = 11;
  UFG::qString::qString(&stru_1423FC218, "StatGamesKillStreak");
  UFG::qSymbol::create_from_string(&stru_1423FC240, "StatGamesKillStreak");
  UFG::qString::qString(&stru_1423FC248, "$LEADERBOARD_CHALLENGES_KILL_STREAK");
  unk_1423FC270 = 1;
  UFG::qString::qString(&stru_1423FC278, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC2A0, &customCaption);
  UFG::qString::qString(&stru_1423FC2A8, "$LEADERBOARD_CHALLENGES_KILL_STREAK_DESC");
  UFG::qString::qString(&stru_1423FC2D0, &customCaption);
  unk_1423FC2F8 = "%d";
  unk_1423FC300 = _mm_load_si128((const __m128i *)&_xmm);
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
  UFG::qString::qString(&stru_1423FC3B0, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC3D8, &customCaption);
  UFG::qString::qString(&stru_1423FC3E0, "$LEADERBOARD_CHALLENGES_TACKLES_DESC");
  UFG::qString::qString(&stru_1423FC408, &customCaption);
  unk_1423FC430 = "%d";
  unk_1423FC438 = -1i64;
  unk_1423FC440 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FC450, "$LEADERBOARD_CHALLENGES_TACKLES_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FC478, "Main");
  unk_1423FC480 = 41;
  unk_1423FC484 = 13;
  UFG::qString::qString(&stru_1423FC488, "StatGamesFlyingKicks");
  UFG::qSymbol::create_from_string(&stru_1423FC4B0, "StatGamesFlyingKicks");
  UFG::qString::qString(&stru_1423FC4B8, "$LEADERBOARD_CHALLENGES_FLYING_JUMP_KICKS");
  unk_1423FC4E0 = 1;
  UFG::qString::qString(&stru_1423FC4E8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC510, &customCaption);
  UFG::qString::qString(&stru_1423FC518, "$LEADERBOARD_CHALLENGES_FLYING_JUMP_KICKS_DESC");
  UFG::qString::qString(&stru_1423FC540, &customCaption);
  unk_1423FC568 = "%d";
  unk_1423FC570 = _mm_load_si128((const __m128i *)&_xmm);
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
  UFG::qString::qString(&stru_1423FC620, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC648, &customCaption);
  UFG::qString::qString(&stru_1423FC650, "$LEADERBOARD_CHALLENGES_HEADSHOTS_DESC");
  UFG::qString::qString(&stru_1423FC678, &customCaption);
  unk_1423FC6A0 = "%d";
  unk_1423FC6A8 = -1i64;
  unk_1423FC6B0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FC6C0, "$LEADERBOARD_CHALLENGES_HEADSHOTS_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FC6E8, "Main");
  unk_1423FC6F0 = 43;
  unk_1423FC6F4 = 15;
  UFG::qString::qString(&stru_1423FC6F8, "StatGamesTireShots");
  UFG::qSymbol::create_from_string(&stru_1423FC720, "StatGamesTireShots");
  UFG::qString::qString(&stru_1423FC728, "$LEADERBOARD_CHALLENGES_TIRESHOTS");
  unk_1423FC750 = 1;
  UFG::qString::qString(&stru_1423FC758, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC780, &customCaption);
  UFG::qString::qString(&stru_1423FC788, "$LEADERBOARD_CHALLENGES_TIRESHOTS_DESC");
  UFG::qString::qString(&stru_1423FC7B0, &customCaption);
  unk_1423FC7D8 = "%d";
  unk_1423FC7E0 = _mm_load_si128((const __m128i *)&_xmm);
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
  UFG::qString::qString(&stru_1423FC890, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC8B8, &customCaption);
  UFG::qString::qString(&stru_1423FC8C0, "$LEADERBOARD_CHALLENGES_COPS_KILLED_DESC");
  UFG::qString::qString(&stru_1423FC8E8, &customCaption);
  unk_1423FC910 = "%d";
  unk_1423FC918 = -1i64;
  unk_1423FC920 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FC930, "$LEADERBOARD_CHALLENGES_COPS_KILLED_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FC958, "Main");
  unk_1423FC960 = 110;
  unk_1423FC964 = 17;
  UFG::qString::qString(&stru_1423FC968, "StatGamesJiangShiDefeatedStreak");
  UFG::qSymbol::create_from_string(&stru_1423FC990, "StatGamesJiangShiDefeatedStreak");
  UFG::qString::qString(&stru_1423FC998, "$LEADERBOARD_CHALLENGES_JIANG_SHI_DEFEATED_STREAK");
  unk_1423FC9C0 = 1;
  UFG::qString::qString(&stru_1423FC9C8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FC9F0, &customCaption);
  UFG::qString::qString(&stru_1423FC9F8, "$LEADERBOARD_CHALLENGES_JIANG_SHI_DEFEATED_STREAK_DESC");
  UFG::qString::qString(&stru_1423FCA20, &customCaption);
  unk_1423FCA48 = "%d";
  unk_1423FCA50 = _mm_load_si128((const __m128i *)&_xmm);
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
  UFG::qString::qString(&stru_1423FCB00, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FCB28, &customCaption);
  UFG::qString::qString(&stru_1423FCB30, "$LEADERBOARD_CHALLENGES_ENEMIES_ON_FIRE_DESC");
  UFG::qString::qString(&stru_1423FCB58, &customCaption);
  unk_1423FCB80 = "%d";
  unk_1423FCB88 = -1i64;
  unk_1423FCB90 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FCBA0, "$LEADERBOARD_CHALLENGES_ENEMIES_ON_FIRE_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FCBC8, "DLC_Ghost");
  unk_1423FCBD0 = 112;
  unk_1423FCBD4 = 19;
  UFG::qString::qString(&stru_1423FCBD8, "StatGamesPossessedPedsKilled");
  UFG::qSymbol::create_from_string(&stru_1423FCC00, "StatGamesPossessedPedsKilled");
  UFG::qString::qString(&stru_1423FCC08, "$LEADERBOARD_CHALLENGES_POSSESSED_PEDS_KILLED");
  unk_1423FCC30 = 1;
  UFG::qString::qString(&stru_1423FCC38, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FCC60, &customCaption);
  UFG::qString::qString(&stru_1423FCC68, "$LEADERBOARD_CHALLENGES_POSSESSED_PEDS_KILLED_DESC");
  UFG::qString::qString(&stru_1423FCC90, &customCaption);
  unk_1423FCCB8 = "%d";
  unk_1423FCCC0 = _mm_load_si128((const __m128i *)&_xmm);
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
  UFG::qString::qString(&stru_1423FCD70, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FCD98, &customCaption);
  UFG::qString::qString(&stru_1423FCDA0, "$LEADERBOARD_CHALLENGES_LONGEST_NOT_BITTEN_DESC");
  UFG::qString::qString(&stru_1423FCDC8, &customCaption);
  unk_1423FCDF0 = "%.1f s";
  unk_1423FCDF8 = -1i64;
  unk_1423FCE00 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FCE10, "$LEADERBOARD_CHALLENGES_LONGEST_NOT_BITTEN_RANKDESC");
  UFG::qSymbol::create_from_string(&stru_1423FCE38, "DLC_Ghost");
  unk_1423FCE40 = 114;
  unk_1423FCE44 = 21;
  UFG::qString::qString(&stru_1423FCE48, "StatGamesJiangShiRunOver");
  UFG::qSymbol::create_from_string(&stru_1423FCE70, "StatGamesJiangShiRunOver");
  UFG::qString::qString(&stru_1423FCE78, "$LEADERBOARD_CHALLENGES_JIANG_SHI_RUN_OVER");
  unk_1423FCEA0 = 1;
  UFG::qString::qString(&stru_1423FCEA8, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1423FCED0, &customCaption);
  UFG::qString::qString(&stru_1423FCED8, "$LEADERBOARD_CHALLENGES_JIANG_SHI_RUN_OVER_DESC");
  UFG::qString::qString(&stru_1423FCF00, &customCaption);
  unk_1423FCF28 = "%d";
  unk_1423FCF30 = _mm_load_si128((const __m128i *)&_xmm);
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
  unk_1423FD070 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FD080, &customCaption);
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
  unk_1423FD1A0 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FD1B0 = 0i64;
  UFG::qString::qString(&stru_1423FD1B8, &customCaption);
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
  unk_1423FD2E0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FD2F0, &customCaption);
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
  unk_1423FD410 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FD420 = 0i64;
  UFG::qString::qString(&stru_1423FD428, &customCaption);
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
  unk_1423FD550 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FD560, &customCaption);
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
  unk_1423FD680 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FD690 = 0i64;
  UFG::qString::qString(&stru_1423FD698, &customCaption);
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
  unk_1423FD7C0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FD7D0, &customCaption);
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
  unk_1423FD8F0 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FD900 = 0i64;
  UFG::qString::qString(&stru_1423FD908, &customCaption);
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
  unk_1423FDA30 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FDA40, &customCaption);
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
  unk_1423FDB60 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FDB70 = 0i64;
  UFG::qString::qString(&stru_1423FDB78, &customCaption);
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
  unk_1423FDCA0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FDCB0, &customCaption);
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
  unk_1423FDDD0 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FDDE0 = 0i64;
  UFG::qString::qString(&stru_1423FDDE8, &customCaption);
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
  unk_1423FDF10 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FDF20, &customCaption);
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
  unk_1423FE040 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FE050 = 0i64;
  UFG::qString::qString(&stru_1423FE058, &customCaption);
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
  unk_1423FE180 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FE190, &customCaption);
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
  unk_1423FE2B0 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FE2C0 = 0i64;
  UFG::qString::qString(&stru_1423FE2C8, &customCaption);
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
  unk_1423FE3F0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FE400, &customCaption);
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
  unk_1423FE520 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FE530 = 0i64;
  UFG::qString::qString(&stru_1423FE538, &customCaption);
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
  unk_1423FE660 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FE670, &customCaption);
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
  unk_1423FE790 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FE7A0 = 0i64;
  UFG::qString::qString(&stru_1423FE7A8, &customCaption);
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
  unk_1423FE8D0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FE8E0, &customCaption);
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
  unk_1423FEA00 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FEA10 = 0i64;
  UFG::qString::qString(&stru_1423FEA18, &customCaption);
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
  unk_1423FEB40 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FEB50, &customCaption);
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
  unk_1423FEC70 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FEC80 = 0i64;
  UFG::qString::qString(&stru_1423FEC88, &customCaption);
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
  unk_1423FEDB0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FEDC0, &customCaption);
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
  unk_1423FEEE0 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FEEF0 = 0i64;
  UFG::qString::qString(&stru_1423FEEF8, &customCaption);
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
  unk_1423FF020 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FF030, &customCaption);
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
  unk_1423FF150 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FF160 = 0i64;
  UFG::qString::qString(&stru_1423FF168, &customCaption);
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
  unk_1423FF290 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FF2A0, &customCaption);
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
  unk_1423FF3C0 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FF3D0 = 0i64;
  UFG::qString::qString(&stru_1423FF3D8, &customCaption);
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
  unk_1423FF500 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FF510, &customCaption);
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
  unk_1423FF630 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FF640 = 0i64;
  UFG::qString::qString(&stru_1423FF648, &customCaption);
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
  unk_1423FF770 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FF780, &customCaption);
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
  unk_1423FF8A0 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FF8B0 = 0i64;
  UFG::qString::qString(&stru_1423FF8B8, &customCaption);
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
  unk_1423FF9E0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FF9F0, &customCaption);
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
  unk_1423FFB10 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FFB20 = 0i64;
  UFG::qString::qString(&stru_1423FFB28, &customCaption);
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
  unk_1423FFC50 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FFC60, &customCaption);
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
  unk_1423FFD80 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1423FFD90 = 0i64;
  UFG::qString::qString(&stru_1423FFD98, &customCaption);
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
  unk_1423FFEC0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1423FFED0, &customCaption);
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
  unk_1423FFFF0 = _mm_load_si128((const __m128i *)&_xmm);
  unk_142400000 = 0i64;
  UFG::qString::qString(&stru_142400008, &customCaption);
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
  unk_142400130 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_142400140, &customCaption);
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
  unk_142400260 = _mm_load_si128((const __m128i *)&_xmm);
  unk_142400270 = 0i64;
  UFG::qString::qString(&stru_142400278, &customCaption);
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
  unk_1424003A0 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_1424003B0, &customCaption);
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
  unk_1424004D0 = _mm_load_si128((const __m128i *)&_xmm);
  unk_1424004E0 = 0i64;
  UFG::qString::qString(&stru_1424004E8, &customCaption);
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
  unk_142400610 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_142400620, &customCaption);
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
  unk_142400740 = _mm_load_si128((const __m128i *)&_xmm);
  unk_142400750 = 0i64;
  UFG::qString::qString(&stru_142400758, &customCaption);
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
  unk_142400880 = _mm_load_si128((const __m128i *)&_xmm);
  UFG::qString::qString(&stru_142400890, &customCaption);
  UFG::qSymbol::create_from_string(&stru_1424008B8, "Main");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__aHardcodedLeaderboardData__);
}58, "RacesKT_01");
  UFG::qSymbol::create_from_string(&stru_142400680, "RacesKT_01");
  UFG::qString::qString(&stru_142400688, "$SGTITLE_DLC_RACER_HK_ENDURO");
  unk_1424006B0 = 3;
  UFG::qString::qString(&stru_1424006B8, "R_KT_01");
  UFG::qSymbol::create_from_string(&stru_1424006E0, "R_KT_01");
  UFG::qString::qString(&stru_1424006E8, "$LEADERBOARD_RACES_KT_01_DESC");
  UFG::qString::qString(&stru_142400710, "SocialHub_Race_Enduro");
  unk_142400738 = "time";
  unk_142400740 = _mm_load_si128((const __m128i *)&_xmm);
  unk_142400750 = 0i64;
  UFG::qString::qString(&stru_142400758, &customCaption);
  UFG::qSymbol::create_from_string(&stru_142400780, "Main");
  unk_142400788 = 91;
  unk_14240078C = 19;
  UFG::qString::qString(&stru_142400790, "RacesKT_03");
  UFG::qSymbol::create_from_string(&stru_1424007B8, "RacesKT_03");
  UFG::qString::qString(&stru_1424007C0, "$SGTITLE_DLCRACER_HARBOURRUN");
  unk_1424007E8 = 3;
  UFG::qString::qString(&stru_1424007F0, "R_KT_03");
  UFG::qSymbol::create_from_string(&stru_142400818, "R_KT_03");
  UFG::qString::qString(&stru_1424008

// File Line: 393
// RVA: 0x42AC80
void __fastcall UFG::MessageBuffer::AppendValue(
        UFG::MessageBuffer *this,
        UFG::PlayerStatSubmissionLookup *lookup,
        float value)
{
  int v4; // eax
  __int64 v5; // rbx
  char dest[128]; // [rsp+20h] [rbp-98h] BYREF

  UFG::MessageBuffer::AppendDescriptor(this, lookup, (char *)lookup->mStatName);
  v4 = UFG::qSPrintf(dest, "%f", value);
  v5 = v4;
  UFG::qStringCopy(
    this->mCurrentOffset,
    LODWORD(this->mBuffer) + this->mBufferSize - LODWORD(this->mCurrentOffset),
    dest,
    v4);
  this->mCurrentOffset += v5;
  *this->mCurrentOffset = 0;
}

// File Line: 404
// RVA: 0x42AC10
void __fastcall UFG::MessageBuffer::AppendValue(
        UFG::MessageBuffer *this,
        UFG::PlayerStatSubmissionLookup *lookup,
        unsigned int value)
{
  int v5; // eax
  __int64 v6; // rbx
  char dest[136]; // [rsp+20h] [rbp-88h] BYREF

  UFG::MessageBuffer::AppendDescriptor(this, lookup, (char *)lookup->mStatName);
  v5 = UFG::qSPrintf(dest, "%d", value);
  v6 = v5;
  UFG::qStringCopy(
    this->mCurrentOffset,
    LODWORD(this->mBuffer) + this->mBufferSize - LODWORD(this->mCurrentOffset),
    dest,
    v5);
  this->mCurrentOffset += v6;
  *this->mCurrentOffset = 0;
}

// File Line: 428
// RVA: 0x42AB00
void __fastcall UFG::MessageBuffer::AppendDescriptor(
        UFG::MessageBuffer *this,
        UFG::PlayerStatSubmissionLookup *lookup,
        char *statName)
{
  UFG::DataType mDataType; // r9d
  UFG::SubmissionType mSubmisionType; // ecx
  char *mCurrentOffset; // rax
  char *v8; // rax
  __int32 v9; // ecx
  int v10; // eax
  __int64 v11; // rbx

  mDataType = lookup->mDataType;
  mSubmisionType = lookup->mSubmisionType;
  mCurrentOffset = this->mCurrentOffset;
  if ( mCurrentOffset != this->mBuffer )
  {
    *mCurrentOffset = 44;
    ++this->mCurrentOffset;
  }
  v8 = this->mCurrentOffset;
  if ( (unsigned int)(mDataType - 1) <= 1 )
  {
    *v8 = 102;
    this->mCurrentOffset[1] = 95;
    this->mCurrentOffset += 2;
  }
  else
  {
    *v8 = 105;
    this->mCurrentOffset[1] = 51;
    this->mCurrentOffset[2] = 50;
    this->mCurrentOffset[3] = 95;
    this->mCurrentOffset += 4;
  }
  if ( mSubmisionType == SUBMITTYPE_SUM )
  {
    *this->mCurrentOffset = 115;
    this->mCurrentOffset[1] = 117;
    this->mCurrentOffset[2] = 109;
    goto LABEL_12;
  }
  v9 = mSubmisionType - 1;
  if ( !v9 )
  {
    *this->mCurrentOffset = 109;
    this->mCurrentOffset[1] = 105;
    this->mCurrentOffset[2] = 110;
    goto LABEL_12;
  }
  if ( v9 == 1 )
  {
    *this->mCurrentOffset = 109;
    this->mCurrentOffset[1] = 97;
    this->mCurrentOffset[2] = 120;
LABEL_12:
    this->mCurrentOffset += 3;
  }
  v10 = UFG::qStringLength(statName);
  v11 = v10;
  UFG::qStringCopy(
    this->mCurrentOffset,
    LODWORD(this->mBuffer) + this->mBufferSize - LODWORD(this->mCurrentOffset),
    statName,
    v10);
  this->mCurrentOffset += v11;
  *this->mCurrentOffset++ = 61;
  *this->mCurrentOffset = 0;
}

// File Line: 493
// RVA: 0x42CF20
void __fastcall UFG::OSuiteLeaderboardManager::GetTopFriendsStatScoresCallback(
        OSuite::SCallbackData *pData,
        OSuite::ZWebServiceClient *pWebServiceClient)
{
  UFG::OnlineManager *v4; // rax
  UFG::OnlineId *OnlineId; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mPrev; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mNext; // rax
  UFG::OnlineManager *v8; // rax
  OSuite::ZOEntry *v9; // r12
  unsigned int i; // r15d
  __int64 v11; // rsi
  OSuite::ZOProperty *v12; // r14
  int j; // ebx
  OSuite::ZOProperty *SubProperty; // rdi
  OSuite::ZOProperty *v15; // rax
  OSuite::ZOProperty *v16; // rax
  const char *v17; // rax
  char *mData; // rdi
  const char *v19; // rax
  __int64 v20; // rdi
  UFG::CachedLeaderboardManager *v21; // rax
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *v22; // rcx
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *v23; // rax
  const char *v24; // rax
  char Friend; // al
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v26; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v27; // rcx
  UFG::OSuiteLeaderboardData *p; // rdi
  UFG::CachedLeaderboardManager *v29; // rax
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *v30; // rcx
  UFG::qNode<UFG::CachedLeaderboard::Entry,UFG::CachedLeaderboard::Entry> *v31; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v32; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v33; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v34; // rcx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v35; // rax
  UFG::OnlineId result; // [rsp+20h] [rbp-E0h] BYREF
  UFG::OnlineFriend frnd; // [rsp+40h] [rbp-C0h] BYREF
  OSuite::ZString outValue; // [rsp+A0h] [rbp-60h] BYREF
  char dest[16]; // [rsp+B8h] [rbp-48h] BYREF
  char subPropertyName[24]; // [rsp+C8h] [rbp-38h] BYREF
  UFG::CachedLeaderboard::Entry v41; // [rsp+E0h] [rbp-20h] BYREF
  UFG::CachedLeaderboard::Entry entry; // [rsp+140h] [rbp+40h] BYREF
  __int64 v43; // [rsp+1A0h] [rbp+A0h]
  UFG::qString v44; // [rsp+1A8h] [rbp+A8h] BYREF
  UFG::qString v45; // [rsp+1D0h] [rbp+D0h] BYREF
  int v46; // [rsp+240h] [rbp+140h] BYREF
  OSuite::ZOEntry *v47; // [rsp+250h] [rbp+150h]
  UFG::OnlineId *p_m_cOnlineId; // [rsp+258h] [rbp+158h]

  v43 = -2i64;
  if ( pData->Status.eError == HTTPERROR_OK )
  {
    UFG::OSuiteLeaderboardManager::m_bIsFriendsScoresInserted = 1;
    v4 = UFG::OnlineManager::Instance();
    OnlineId = UFG::OnlineManager::GetOnlineId(v4, &result);
    UFG::OnlineId::ToString(OnlineId, &v44);
    mPrev = result.mPrev;
    mNext = result.mNext;
    result.mPrev->mNext = result.mNext;
    mNext->mPrev = mPrev;
    result.mPrev = &result;
    result.mNext = &result;
    v8 = UFG::OnlineManager::Instance();
    UFG::OnlineManager::GetOnlineName(v8, &v45);
    v9 = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOEntry>(pWebServiceClient, &pData->URL);
    v47 = v9;
    if ( v9 )
    {
      for ( i = 0; ; ++i )
      {
        if ( (_S10_6 & 1) == 0 )
        {
          _S10_6 |= 1u;
          UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
          atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
        }
        if ( i >= dword_1424014F8 )
          break;
        if ( (_S10_6 & 1) == 0 )
        {
          _S10_6 |= 1u;
          UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
          atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
        }
        v11 = 312i64 * i;
        if ( *(_DWORD *)(v11 + qword_142401500 + 96) == 1 )
        {
          UFG::qMemSet(dest, 0, 0x10u);
          if ( (_S10_6 & 1) == 0 )
          {
            _S10_6 |= 1u;
            UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
            atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
          }
          UFG::qSPrintf(dest, "c_lb%d", *(unsigned int *)(v11 + qword_142401500 + 4));
          v12 = OSuite::ZOEntry::Property(v9, dest);
          if ( v12 )
          {
            for ( j = 0; j < 10; ++j )
            {
              UFG::qMemSet(subPropertyName, 0, 0x10u);
              UFG::qSPrintf(subPropertyName, "c_p%d", (unsigned int)j);
              SubProperty = OSuite::ZOProperty::GetSubProperty(v12, subPropertyName);
              if ( SubProperty )
              {
                OSuite::ZString::ZString(&outValue);
                v46 = 0;
                v15 = OSuite::ZOProperty::GetSubProperty(SubProperty, "s_Pid");
                OSuite::ZOProperty::GetValue(v15, &outValue);
                v16 = OSuite::ZOProperty::GetSubProperty(SubProperty, "i32_Score");
                OSuite::ZOProperty::GetValue(v16, &v46);
                v17 = OSuite::ZString::c_str(&outValue);
                UFG::qPrintf("lbName: %s, id: %s, score: %d\n", dest, v17, (unsigned int)v46);
                mData = v44.mData;
                v19 = OSuite::ZString::c_str(&outValue);
                if ( (unsigned int)UFG::qStringCompare(mData, v19, -1) )
                {
                  frnd.mPrev = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
                  frnd.mNext = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
                  frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable;
                  p_m_cOnlineId = &frnd.m_cOnlineId;
                  frnd.m_cOnlineId.mPrev = &frnd.m_cOnlineId;
                  frnd.m_cOnlineId.mNext = &frnd.m_cOnlineId;
                  frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits = __PAIR64__(
                                                                         HIDWORD(frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits),
                                                                         0) & 0xFF0FFFFF00000000ui64;
                  HIBYTE(frnd.m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits) = 0;
                  *((_DWORD *)&frnd.m_cOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
                  UFG::qString::qString(&frnd.m_sOnlineName);
                  v24 = OSuite::ZString::c_str(&outValue);
                  result.mPrev = &result;
                  result.mNext = &result;
                  result.m_SteamId.m_steamid.m_unAll64Bits = __PAIR64__(
                                                               HIDWORD(result.m_SteamId.m_steamid.m_unAll64Bits),
                                                               0) & 0xFF0FFFFF00000000ui64;
                  HIBYTE(result.m_SteamId.m_steamid.m_unAll64Bits) = 0;
                  *((_DWORD *)&result.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
                  result.m_SteamId.m_steamid.m_unAll64Bits = UFG::qToUInt64(v24, 0i64);
                  Friend = UFG::OnlineFriendManager::FindFriend(
                             (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> **)&frnd,
                             &result);
                  v26 = result.mPrev;
                  v27 = result.mNext;
                  result.mPrev->mNext = result.mNext;
                  v27->mPrev = v26;
                  result.mPrev = &result;
                  result.mNext = &result;
                  if ( Friend )
                  {
                    v41.mPrev = &v41;
                    v41.mNext = &v41;
                    v41.m_iRating = v46;
                    v41.m_uRank = 0;
                    v41.m_eEntryType = EntryType_Friend;
                    UFG::qStringCopy(v41.m_sUsername, 64, frnd.m_sOnlineName.mData, -1);
                    p = UFG::OSuiteLeaderboardManager::Instance()->mLeaderboardData.p;
                    v29 = UFG::CachedLeaderboardManager::Instance();
                    UFG::CachedLeaderboardManager::UpsertEntry(v29, p[i].mLeaderboardId, &v41);
                    v30 = v41.mPrev;
                    v31 = v41.mNext;
                    v41.mPrev->mNext = v41.mNext;
                    v31->mPrev = v30;
                    v41.mPrev = &v41;
                    v41.mNext = &v41;
                  }
                  frnd.vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable;
                  UFG::qString::~qString(&frnd.m_sOnlineName);
                  p_m_cOnlineId = &frnd.m_cOnlineId;
                  v32 = frnd.m_cOnlineId.mPrev;
                  v33 = frnd.m_cOnlineId.mNext;
                  frnd.m_cOnlineId.mPrev->mNext = frnd.m_cOnlineId.mNext;
                  v33->mPrev = v32;
                  frnd.m_cOnlineId.mPrev = &frnd.m_cOnlineId;
                  frnd.m_cOnlineId.mNext = &frnd.m_cOnlineId;
                  v34 = frnd.mPrev;
                  v35 = frnd.mNext;
                  frnd.mPrev->mNext = frnd.mNext;
                  v35->mPrev = v34;
                  frnd.mPrev = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
                  frnd.mNext = &frnd.UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
                }
                else
                {
                  entry.mPrev = &entry;
                  entry.mNext = &entry;
                  entry.m_iRating = v46;
                  entry.m_uRank = 0;
                  entry.m_eEntryType = EntryType_YourSelf;
                  UFG::qStringCopy(entry.m_sUsername, 64, v45.mData, -1);
                  if ( (_S10_6 & 1) == 0 )
                  {
                    _S10_6 |= 1u;
                    UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
                    atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
                  }
                  v20 = qword_142401500;
                  v21 = UFG::CachedLeaderboardManager::Instance();
                  UFG::CachedLeaderboardManager::UpsertEntry(v21, *(_DWORD *)(v20 + 312i64 * i), &entry);
                  v22 = entry.mPrev;
                  v23 = entry.mNext;
                  entry.mPrev->mNext = entry.mNext;
                  v23->mPrev = v22;
                  entry.mPrev = &entry;
                  entry.mNext = &entry;
                }
                OSuite::ZString::~ZString(&outValue);
              }
            }
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
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v2; // rdi
  UFG::OSuiteManager *v3; // rax
  UFG::qList<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver,1,0> *p_m_lOSuiteObservers; // rdx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *mNext; // rax

  v2 = &this->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
  this->mPrev = &this->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
  this->mNext = &this->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable;
  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteLeaderboardManager::`vftable;
  this->mLeaderboardData.p = 0i64;
  *(_QWORD *)&this->mLeaderboardData.size = 0i64;
  this->mLeaderboardData_SortedBySliceName.p = 0i64;
  *(_QWORD *)&this->mLeaderboardData_SortedBySliceName.size = 0i64;
  this->mLeaderboardData_SortedByLeaderboardName.p = 0i64;
  *(_QWORD *)&this->mLeaderboardData_SortedByLeaderboardName.size = 0i64;
  this->m_pWebServiceClient = 0i64;
  this->m_updateEvents.mNode.mPrev = &this->m_updateEvents.mNode;
  this->m_updateEvents.mNode.mNext = &this->m_updateEvents.mNode;
  this->m_rTimerForFriendsScores = 0.0;
  *(_WORD *)&this->m_bQueueOptionsSave = 0;
  UFG::qMutex::qMutex(&this->m_cMutex, &customCaption);
  UFG::qEvent::qEvent(&this->m_cThreadEvent, "OSuiteLeaderboardManager", 1);
  UFG::qThread::qThread(&this->m_cUpdateThread, "OSuiteLeaderboardManager");
  v3 = UFG::OSuiteManager::Instance();
  p_m_lOSuiteObservers = &v3->m_lOSuiteObservers;
  mNext = v3->m_lOSuiteObservers.mNode.mNext;
  p_m_lOSuiteObservers->mNode.mNext = v2;
  v2->mPrev = &p_m_lOSuiteObservers->mNode;
  v2->mNext = mNext;
  mNext->mPrev = v2;
  UFG::qBaseNodeRB::SetUID((UFG::qBaseNodeRB *)&this->m_cUpdateThread, 0x4000u);
  UFG::qThread::SetThreadPriority(&this->m_cUpdateThread, -1);
  UFG::qThread::Start(&this->m_cUpdateThread, UFG::OSuiteLeaderboardManager::UpdateThread, this);
}

// File Line: 596
// RVA: 0x42E3E0
UFG::OSuiteLeaderboardManager *__fastcall UFG::OSuiteLeaderboardManager::Instance()
{
  if ( (_S10_6 & 1) == 0 )
  {
    _S10_6 |= 1u;
    UFG::OSuiteLeaderboardManager::OSuiteLeaderboardManager(&instance_4);
    atexit(UFG::OSuiteLeaderboardManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  return &instance_4;
}

// File Line: 602
// RVA: 0x42E9B0
void __fastcall UFG::OSuiteLeaderboardManager::OSuiteManagerConnected(
        UFG::OSuiteLeaderboardManager *this,
        OSuite::ZWebServiceClient *p)
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
bool __fastcall UFG::LeaderboardDataComparison_SliceName(
        UFG::OSuiteLeaderboardData *const *one,
        UFG::OSuiteLeaderboardData *const *two)
{
  return (*one)->mSliceName.mUID <= (*two)->mSliceName.mUID;
}

// File Line: 625
// RVA: 0x42E890
bool __fastcall UFG::LeaderboardDataComparison_LeaderboardName(
        UFG::OSuiteLeaderboardData *const *one,
        UFG::OSuiteLeaderboardData *const *two)
{
  return (*one)->mLeaderboardName.mUID <= (*two)->mLeaderboardName.mUID;
}

// File Line: 629
// RVA: 0x42D520
void __fastcall UFG::OSuiteLeaderboardManager::Init(UFG::OSuiteLeaderboardManager *this)
{
  UFG::OSuiteLeaderboardManager *v1; // rdi
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *PropertySet; // rbx
  UFG::qArray<unsigned long,0> *v4; // rax
  __int64 v5; // rsi
  UFG::qPropertyList *v6; // r14
  int *v7; // rax
  int v8; // r15d
  UFG::qArray<UFG::OSuiteLeaderboardData,0> *p_mLeaderboardData; // r12
  unsigned __int64 v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::OSuiteLeaderboardData **v12; // rbx
  unsigned int i; // r9d
  __int64 v14; // rcx
  unsigned __int64 v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::OSuiteLeaderboardData **v17; // rbx
  unsigned int j; // r9d
  __int64 v19; // rcx
  unsigned int v20; // eax
  char *ValuePtr; // rax
  UFG::qPropertySet *v22; // rbx
  UFG::qArray<unsigned long,0> *v23; // rax
  UFG::qPropertyList *v24; // r14
  UFG::qArray<unsigned long,0> *v25; // rax
  unsigned int v26; // r13d
  UFG::qPropertyList *v27; // rdi
  __int64 size; // r14
  unsigned int capacity; // edx
  unsigned int v30; // ebx
  unsigned int v31; // edx
  __int64 v32; // r14
  char *v33; // rax
  UFG::qPropertySet *v34; // rbx
  int *v35; // rax
  int v36; // r13d
  int *v37; // rax
  int *v38; // rax
  int *v39; // rax
  int *v40; // rax
  int *v41; // rax
  int *v42; // rax
  int v43; // r13d
  int *v44; // rax
  int v45; // ebx
  char *v46; // rdx
  UFG::qSymbol *v47; // rax
  char *v48; // rdx
  int LeaderboardCategoryFromString; // eax
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
  __int64 v61; // rcx
  __int64 v62; // rax
  __int64 v63; // rcx
  unsigned int v64; // r14d
  unsigned int v65; // ebx
  unsigned __int64 v66; // rax
  UFG::allocator::free_link *v67; // rax
  UFG::OSuiteLeaderboardData **v68; // r13
  unsigned int k; // r9d
  __int64 v70; // rcx
  UFG::OSuiteLeaderboardData **p; // rax
  __int64 v72; // rdx
  __int64 v73; // rcx
  unsigned int v74; // ebx
  unsigned int v75; // r14d
  unsigned int v76; // ebx
  unsigned __int64 v77; // rax
  UFG::allocator::free_link *v78; // rax
  UFG::OSuiteLeaderboardData **v79; // r13
  unsigned int m; // r9d
  __int64 v81; // rcx
  UFG::OSuiteLeaderboardData **v82; // rax
  __int64 v83; // rdx
  UFG::qPropertySet **v84; // r9
  UFG::qPropertySet **v85; // r14
  __int64 v86; // rax
  int v87; // ecx
  UFG::qPropertySet **v88; // rcx
  UFG::qPropertySet *v89; // r8
  UFG::qPropertySet *v90; // r8
  UFG::qPropertySet *v91; // r8
  UFG::qPropertySet *v92; // r8
  UFG::qPropertySet **v93; // rbx
  UFG::qPropertySet **ii; // rdx
  unsigned int mOffset; // ecx
  UFG::qPropertySet *v96; // rax
  __int64 v97; // rax
  UFG::qPropertySet *v98; // rax
  UFG::qPropertySet *v99; // rcx
  __int64 v100; // r14
  __int64 v101; // r11
  int v102; // ebx
  UFG::qPropertySet *v103; // r10
  int v104; // edx
  __int64 n; // rcx
  UFG::qPropertySet *v106; // r8
  UFG::qPropertySet **v107; // r9
  UFG::qPropertySet **v108; // rdi
  __int64 v109; // rax
  int v110; // ecx
  UFG::qPropertySet **v111; // rcx
  UFG::qPropertySet *v112; // r8
  UFG::qPropertySet *v113; // r8
  UFG::qPropertySet *v114; // r8
  UFG::qPropertySet *v115; // r8
  UFG::qPropertySet **v116; // rbx
  UFG::qPropertySet **kk; // rdx
  unsigned int v118; // ecx
  UFG::qPropertySet *v119; // rax
  __int64 v120; // rax
  UFG::qPropertySet *v121; // rax
  UFG::qPropertySet *v122; // rcx
  __int64 v123; // r11
  UFG::qPropertySet *v124; // r10
  int v125; // edx
  __int64 jj; // rcx
  UFG::qPropertySet *v127; // r8
  int v128; // [rsp+20h] [rbp-E0h]
  int v129; // [rsp+24h] [rbp-DCh]
  unsigned int v130; // [rsp+28h] [rbp-D8h]
  int v131; // [rsp+2Ch] [rbp-D4h]
  unsigned int v132; // [rsp+30h] [rbp-D0h]
  UFG::qArray<unsigned long,0> v133; // [rsp+34h] [rbp-CCh] BYREF
  UFG::qArray<unsigned long,0> propName; // [rsp+44h] [rbp-BCh] BYREF
  UFG::qArray<unsigned long,0> v135; // [rsp+54h] [rbp-ACh] BYREF
  UFG::qArray<unsigned long,0> v136; // [rsp+64h] [rbp-9Ch] BYREF
  UFG::qSymbol v137; // [rsp+74h] [rbp-8Ch] BYREF
  UFG::qPropertyList *v138; // [rsp+78h] [rbp-88h]
  char *text; // [rsp+80h] [rbp-80h]
  char *pszSymbolString; // [rsp+88h] [rbp-78h]
  UFG::qSymbol v141; // [rsp+90h] [rbp-70h] BYREF
  char *pcString; // [rsp+98h] [rbp-68h]
  char *v143; // [rsp+A0h] [rbp-60h]
  UFG::qSymbol v144; // [rsp+A8h] [rbp-58h] BYREF
  char *v145; // [rsp+B0h] [rbp-50h]
  UFG::qSymbol v146; // [rsp+B8h] [rbp-48h] BYREF
  char *v147; // [rsp+C0h] [rbp-40h]
  UFG::qSymbol v148; // [rsp+C8h] [rbp-38h] BYREF
  char *v149; // [rsp+D0h] [rbp-30h]
  char *v150; // [rsp+D8h] [rbp-28h]
  char *v151; // [rsp+E0h] [rbp-20h]
  UFG::qSymbol v152; // [rsp+E8h] [rbp-18h] BYREF
  UFG::qSymbol v153; // [rsp+ECh] [rbp-14h] BYREF
  __int64 result; // [rsp+148h] [rbp+48h] BYREF
  unsigned int v156; // [rsp+150h] [rbp+50h]
  __int64 v157; // [rsp+158h] [rbp+58h]

  v1 = this;
  v2 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "UI-Leaderboard");
  PropertySet = UFG::PropertySetManager::GetPropertySet(v2);
  if ( PropertySet )
  {
    v4 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v141, "items");
    v5 = 1i64;
    v6 = PropertyUtils::Get<UFG::qPropertyList>(PropertySet, v4, DEPTH_RECURSE);
    v138 = v6;
    if ( v6 )
    {
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&propName.p + 1, "version");
      v7 = UFG::qPropertySet::Get<long>(
             PropertySet,
             (UFG::qArray<unsigned long,0> *)((char *)&propName.p + 4),
             DEPTH_RECURSE);
      v8 = 0;
      if ( v7 && *v7 > 0 )
      {
        p_mLeaderboardData = &v1->mLeaderboardData;
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
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&v136.capacity, "lbId");
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&v136.p + 1, "lbLocalId");
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&propName, "caption");
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&v136, "sliceName");
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&propName.p, "leaderboardName");
        UFG::qSymbol::create_from_string(&v137, "desc");
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&v135, "imagesrc");
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&v136.p, "format");
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&v133.p + 1, "gold");
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&propName.capacity, "silver");
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&v133, "bronze");
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&v135.capacity, "startMs");
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&v135.p + 1, "deltaTime");
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&v133.capacity, "attemptCount");
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&v135.p, "rankDesc");
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&v133.p, "flow");
        v20 = 0;
        v132 = 0;
        if ( v6->mNumElements )
        {
          do
          {
            ValuePtr = UFG::qPropertyList::GetValuePtr(v6, 0x1Au, v20);
            if ( !ValuePtr || (v22 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr], !*(_QWORD *)ValuePtr) )
              v22 = 0i64;
            v23 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v152, "stats");
            v24 = PropertyUtils::Get<UFG::qPropertyList>(v22, v23, DEPTH_RECURSE);
            v25 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v146, "category");
            v26 = 0;
            v130 = 0;
            pcString = PropertyUtils::Get<char const *>(v22, v25, DEPTH_RECURSE);
            if ( v24->mNumElements )
            {
              v27 = v24;
              do
              {
                size = p_mLeaderboardData->size;
                capacity = p_mLeaderboardData->capacity;
                v30 = size + 1;
                if ( (int)size + 1 > capacity )
                {
                  if ( capacity )
                    v31 = 2 * capacity;
                  else
                    v31 = 1;
                  for ( ; v31 < v30; v31 *= 2 )
                    ;
                  if ( v31 - v30 > 0x10000 )
                    v31 = size + 65537;
                  UFG::qArray<UFG::OSuiteLeaderboardData,0>::Reallocate(p_mLeaderboardData, v31, "qArray.Add");
                }
                p_mLeaderboardData->size = v30;
                v32 = (__int64)&p_mLeaderboardData->p[size];
                v33 = UFG::qPropertyList::GetValuePtr(v27, 0x1Au, v26);
                if ( !v33 || (v34 = (UFG::qPropertySet *)&v33[*(_QWORD *)v33], !*(_QWORD *)v33) )
                  v34 = 0i64;
                v35 = UFG::qPropertySet::Get<long>(v34, (UFG::qArray<unsigned long,0> *)&v136.capacity, DEPTH_RECURSE);
                if ( v35 )
                {
                  LODWORD(result) = *v35;
                  v36 = -1;
                }
                else
                {
                  v36 = -1;
                  LODWORD(result) = -1;
                }
                v37 = UFG::qPropertySet::Get<long>(
                        v34,
                        (UFG::qArray<unsigned long,0> *)((char *)&v136.p + 4),
                        DEPTH_RECURSE);
                if ( v37 )
                {
                  v156 = *v37;
                  v36 = -1;
                }
                else
                {
                  v156 = -1;
                }
                v150 = PropertyUtils::Get<char const *>(v34, &propName, DEPTH_RECURSE);
                pszSymbolString = PropertyUtils::Get<char const *>(v34, &v136, DEPTH_RECURSE);
                text = PropertyUtils::Get<char const *>(v34, (UFG::qArray<unsigned long,0> *)&propName.p, DEPTH_RECURSE);
                v143 = PropertyUtils::Get<char const *>(v34, (UFG::qArray<unsigned long,0> *)&v137, DEPTH_RECURSE);
                v145 = PropertyUtils::Get<char const *>(v34, &v135, DEPTH_RECURSE);
                v147 = PropertyUtils::Get<char const *>(v34, (UFG::qArray<unsigned long,0> *)&v136.p, DEPTH_RECURSE);
                v149 = PropertyUtils::Get<char const *>(v34, (UFG::qArray<unsigned long,0> *)&v135.p, DEPTH_RECURSE);
                v151 = PropertyUtils::Get<char const *>(v34, (UFG::qArray<unsigned long,0> *)&v133.p, DEPTH_RECURSE);
                v38 = UFG::qPropertySet::Get<long>(
                        v34,
                        (UFG::qArray<unsigned long,0> *)((char *)&v133.p + 4),
                        DEPTH_RECURSE);
                if ( v38 )
                {
                  LODWORD(v157) = *v38;
                  v36 = -1;
                }
                else
                {
                  LODWORD(v157) = -1;
                }
                v39 = UFG::qPropertySet::Get<long>(
                        v34,
                        (UFG::qArray<unsigned long,0> *)&propName.capacity,
                        DEPTH_RECURSE);
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
                v41 = UFG::qPropertySet::Get<long>(v34, (UFG::qArray<unsigned long,0> *)&v135.capacity, DEPTH_RECURSE);
                if ( v41 )
                  v128 = *v41;
                else
                  v128 = 0;
                v42 = UFG::qPropertySet::Get<long>(
                        v34,
                        (UFG::qArray<unsigned long,0> *)((char *)&v135.p + 4),
                        DEPTH_RECURSE);
                if ( v42 )
                  v43 = *v42;
                else
                  v43 = 0;
                v44 = UFG::qPropertySet::Get<long>(v34, (UFG::qArray<unsigned long,0> *)&v133.capacity, DEPTH_RECURSE);
                if ( v44 )
                  v45 = *v44;
                else
                  v45 = 0;
                if ( (int)result >= 0 )
                {
                  v46 = text;
                  *(_DWORD *)v32 = result;
                  *(_DWORD *)(v32 + 4) = v156;
                  UFG::qString::Set((UFG::qString *)(v32 + 8), v46);
                  v47 = UFG::qSymbol::create_from_string(&v153, text);
                  v48 = v150;
                  *(UFG::qSymbol *)(v32 + 48) = (UFG::qSymbol)v47->mUID;
                  UFG::qString::Set((UFG::qString *)(v32 + 56), v48);
                  LeaderboardCategoryFromString = UFG::GetLeaderboardCategoryFromString(pcString);
                  v50 = pszSymbolString;
                  *(_DWORD *)(v32 + 96) = LeaderboardCategoryFromString;
                  UFG::qString::Set((UFG::qString *)(v32 + 104), v50);
                  v51 = UFG::qSymbol::create_from_string(&v148, pszSymbolString);
                  v52 = v143;
                  *(UFG::qSymbol *)(v32 + 144) = (UFG::qSymbol)v51->mUID;
                  UFG::qString::Set((UFG::qString *)(v32 + 152), v52);
                  UFG::qString::Set((UFG::qString *)(v32 + 192), v145);
                  v53 = v149;
                  *(_QWORD *)(v32 + 232) = v147;
                  *(_DWORD *)(v32 + 240) = v157;
                  *(_DWORD *)(v32 + 256) = v43;
                  *(_DWORD *)(v32 + 244) = v129;
                  *(_DWORD *)(v32 + 260) = v45;
                  *(_DWORD *)(v32 + 248) = v131;
                  *(_DWORD *)(v32 + 252) = v128;
                  UFG::qString::Set((UFG::qString *)(v32 + 264), v53);
                  *(UFG::qSymbol *)(v32 + 304) = (UFG::qSymbol)UFG::qSymbol::create_from_string(&v144, v151)->mUID;
                }
                v26 = v130 + 1;
                v130 = v26;
              }
              while ( v26 < v27->mNumElements );
            }
            v6 = v138;
            v20 = v132 + 1;
            v132 = v20;
          }
          while ( v20 < v138->mNumElements );
          v1 = this;
        }
      }
      else
      {
        p_mLeaderboardData = &v1->mLeaderboardData;
        v54 = UFG::aHardcodedLeaderboardData;
        result = 102i64;
        do
        {
          v55 = p_mLeaderboardData->size;
          v56 = v1->mLeaderboardData.capacity;
          v57 = v55 + 1;
          if ( (int)v55 + 1 > v56 )
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
          p_mLeaderboardData->size = v57;
          UFG::OSuiteLeaderboardData::operator=(&v1->mLeaderboardData.p[v55], v54++);
          --result;
        }
        while ( result );
      }
      UFG::qQuickSortImpl<UFG::OSuiteLeaderboardData,bool (*)(UFG::OSuiteLeaderboardData const &,UFG::OSuiteLeaderboardData const &)>(
        p_mLeaderboardData->p,
        &p_mLeaderboardData->p[(int)p_mLeaderboardData->size - 1],
        UFG::LeaderboardDataComparison_Id);
      v59 = 0;
      for ( LODWORD(result) = 0; v59 < p_mLeaderboardData->size; LODWORD(result) = v59 )
      {
        v60 = v1->mLeaderboardData_SortedBySliceName.capacity;
        v61 = v59;
        v62 = (__int64)&v1->mLeaderboardData.p[v61];
        v138 = (UFG::qPropertyList *)(v61 * 312);
        v63 = v1->mLeaderboardData_SortedBySliceName.size;
        v64 = v63 + 1;
        v157 = v62;
        v156 = v63;
        if ( (int)v63 + 1 > v60 )
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
            v63 = v156;
            v1->mLeaderboardData_SortedBySliceName.p = v68;
            v1->mLeaderboardData_SortedBySliceName.capacity = v65;
          }
        }
        p = v1->mLeaderboardData_SortedBySliceName.p;
        v72 = v157;
        v1->mLeaderboardData_SortedBySliceName.size = v64;
        p[v63] = (UFG::OSuiteLeaderboardData *)v72;
        v73 = v1->mLeaderboardData_SortedByLeaderboardName.size;
        v74 = v1->mLeaderboardData_SortedByLeaderboardName.capacity;
        v75 = v73 + 1;
        v157 = (__int64)v138 + (unsigned __int64)v1->mLeaderboardData.p;
        v156 = v73;
        if ( (int)v73 + 1 > v74 )
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
              for ( m = 0;
                    m < v1->mLeaderboardData_SortedByLeaderboardName.size;
                    v78[v81] = (UFG::allocator::free_link)v1->mLeaderboardData_SortedByLeaderboardName.p[v81] )
              {
                v81 = m++;
              }
              operator delete[](v1->mLeaderboardData_SortedByLeaderboardName.p);
            }
            v73 = v156;
            v1->mLeaderboardData_SortedByLeaderboardName.p = v79;
            v1->mLeaderboardData_SortedByLeaderboardName.capacity = v76;
          }
        }
        v82 = v1->mLeaderboardData_SortedByLeaderboardName.p;
        v83 = v157;
        v1->mLeaderboardData_SortedByLeaderboardName.size = v75;
        v82[v73] = (UFG::OSuiteLeaderboardData *)v83;
        v59 = result + 1;
      }
      v84 = (UFG::qPropertySet **)v1->mLeaderboardData_SortedBySliceName.p;
      v85 = &v84[(int)v1->mLeaderboardData_SortedBySliceName.size - 1];
      v86 = (8 * ((int)v1->mLeaderboardData_SortedBySliceName.size - 1i64)) >> 3;
      v87 = v86 + 1;
      if ( (int)v86 + 1 < 32 )
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
              for ( n = v101 - 1; v104 >= 0; --v104 )
              {
                v106 = v84[n];
                if ( LODWORD(v103[1].mProperties.mOffset) > LODWORD(v106[1].mProperties.mOffset) )
                  break;
                v84[n-- + 1] = v106;
              }
              ++v101;
              ++v102;
              v84[n + 1] = v103;
            }
            while ( v101 < v100 );
          }
        }
      }
      else
      {
        v88 = &v84[v86 / 2];
        v89 = *v88;
        if ( LODWORD((*v88)[1].mProperties.mOffset) <= LODWORD((*v84)[1].mProperties.mOffset) )
        {
          *v88 = *v84;
          *v84 = v89;
        }
        v90 = *v85;
        if ( LODWORD((*v85)[1].mProperties.mOffset) <= LODWORD((*v88)[1].mProperties.mOffset) )
        {
          *v85 = *v88;
          *v88 = v90;
        }
        v91 = *v88;
        if ( LODWORD((*v88)[1].mProperties.mOffset) <= LODWORD((*v84)[1].mProperties.mOffset) )
        {
          *v88 = *v84;
          *v84 = v91;
        }
        v92 = *v88;
        v93 = v84;
        for ( ii = v85; v93 <= ii; ++v93 )
        {
          mOffset = v92[1].mProperties.mOffset;
          if ( LODWORD((*v93)[1].mProperties.mOffset) <= mOffset )
          {
            do
            {
              if ( v93 >= v85 )
                break;
              v96 = v93[1];
              ++v93;
            }
            while ( LODWORD(v96[1].mProperties.mOffset) <= mOffset );
          }
          if ( mOffset <= LODWORD((*ii)[1].mProperties.mOffset) )
          {
            do
            {
              if ( v84 >= ii )
                break;
              v97 = (__int64)*--ii;
            }
            while ( mOffset <= *(_DWORD *)(v97 + 144) );
          }
          if ( v93 > ii )
            break;
          v98 = *ii;
          v99 = *v93;
          --ii;
          *v93 = v98;
          ii[1] = v99;
        }
        if ( v84 < ii )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            v84,
            ii,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::LeaderboardDataComparison_SliceName);
        if ( v93 < v85 )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            v93,
            v85,
            (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::LeaderboardDataComparison_SliceName);
      }
      v107 = (UFG::qPropertySet **)v1->mLeaderboardData_SortedByLeaderboardName.p;
      v108 = &v107[(int)v1->mLeaderboardData_SortedByLeaderboardName.size - 1];
      v109 = v108 - v107;
      v110 = v109 + 1;
      if ( (int)v109 + 1 < 32 )
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
              for ( jj = v5 - 1; v125 >= 0; --v125 )
              {
                v127 = v107[jj];
                if ( LODWORD(v124->mDefaultBits.mOffset) > LODWORD(v127->mDefaultBits.mOffset) )
                  break;
                v107[jj-- + 1] = v127;
              }
              ++v5;
              ++v8;
              v107[jj + 1] = v124;
            }
            while ( v5 < v123 );
          }
        }
      }
      else
      {
        v111 = &v107[v109 / 2];
        v112 = *v111;
        if ( LODWORD((*v111)->mDefaultBits.mOffset) <= LODWORD((*v107)->mDefaultBits.mOffset) )
        {
          *v111 = *v107;
          *v107 = v112;
        }
        v113 = *v108;
        if ( LODWORD((*v108)->mDefaultBits.mOffset) <= LODWORD((*v111)->mDefaultBits.mOffset) )
        {
          *v108 = *v111;
          *v111 = v113;
        }
        v114 = *v111;
        if ( LODWORD((*v111)->mDefaultBits.mOffset) <= LODWORD((*v107)->mDefaultBits.mOffset) )
        {
          *v111 = *v107;
          *v107 = v114;
        }
        v115 = *v111;
        v116 = v107;
        for ( kk = v108; v116 <= kk; ++v116 )
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
          if ( v118 <= LODWORD((*kk)->mDefaultBits.mOffset) )
          {
            do
            {
              if ( v107 >= kk )
                break;
              v120 = (__int64)*--kk;
            }
            while ( v118 <= *(_DWORD *)(v120 + 48) );
          }
          if ( v116 > kk )
            break;
          v121 = *kk;
          v122 = *v116;
          --kk;
          *v116 = v121;
          kk[1] = v122;
        }
        if ( v107 < kk )
          UFG::qQuickSortImpl<UFG::UIMapBlip *,bool (*)(UFG::UIMapBlip * const &,UFG::UIMapBlip * const &)>(
            v107,
            kk,
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
UFG::OSuiteLeaderboardData *__fastcall UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingId(
        UFG::OSuiteLeaderboardManager *this,
        unsigned int id)
{
  unsigned int size; // edx
  int v4; // r8d
  int v5; // edx
  UFG::OSuiteLeaderboardData *p; // r11
  __int64 v7; // rax
  unsigned int mLeaderboardId; // r9d

  size = this->mLeaderboardData.size;
  if ( !size )
    return 0i64;
  v4 = 0;
  v5 = size - 1;
  if ( v5 < 0 )
    return 0i64;
  p = this->mLeaderboardData.p;
  while ( 1 )
  {
    v7 = (unsigned int)(v5 + v4) >> 1;
    mLeaderboardId = p[v7].mLeaderboardId;
    if ( mLeaderboardId >= id )
      break;
    v4 = v7 + 1;
LABEL_8:
    if ( v4 > v5 )
      return 0i64;
  }
  if ( mLeaderboardId > id )
  {
    v5 = v7 - 1;
    goto LABEL_8;
  }
  return &p[v7];
}

// File Line: 791
// RVA: 0x42C950
UFG::OSuiteLeaderboardData *__fastcall UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingSliceName(
        UFG::OSuiteLeaderboardManager *this,
        const char *sliceName)
{
  UFG::qSymbol *v3; // rax
  unsigned int size; // r8d
  int v5; // r9d
  int v6; // r8d
  UFG::OSuiteLeaderboardData **p; // r11
  unsigned int mUID; // r10d
  __int64 v9; // rdx
  unsigned int v10; // eax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  v3 = UFG::qSymbol::create_from_string(&result, sliceName);
  size = this->mLeaderboardData_SortedBySliceName.size;
  if ( !size )
    return 0i64;
  v5 = 0;
  v6 = size - 1;
  if ( v6 < 0 )
    return 0i64;
  mUID = v3->mUID;
  while ( 1 )
  {
    v9 = (unsigned int)(v6 + v5) >> 1;
    p = this->mLeaderboardData_SortedBySliceName.p;
    v10 = p[v9]->mSliceName.mUID;
    if ( v10 >= mUID )
      break;
    v5 = v9 + 1;
LABEL_8:
    if ( v5 > v6 )
      return 0i64;
  }
  if ( v10 > mUID )
  {
    v6 = v9 - 1;
    goto LABEL_8;
  }
  return p[v9];
}

// File Line: 795
// RVA: 0x42C900
UFG::OSuiteLeaderboardData *__fastcall UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingSliceName(
        UFG::OSuiteLeaderboardManager *this,
        UFG::qSymbol *key)
{
  unsigned int size; // r8d
  int v3; // r9d
  int v4; // r8d
  UFG::OSuiteLeaderboardData **p; // r11
  unsigned int mUID; // r10d
  __int64 v7; // rcx
  unsigned int v8; // eax

  size = this->mLeaderboardData_SortedBySliceName.size;
  if ( !size )
    return 0i64;
  v3 = 0;
  v4 = size - 1;
  if ( v4 < 0 )
    return 0i64;
  p = this->mLeaderboardData_SortedBySliceName.p;
  mUID = key->mUID;
  while ( 1 )
  {
    v7 = (unsigned int)(v4 + v3) >> 1;
    v8 = p[v7]->mSliceName.mUID;
    if ( v8 >= mUID )
      break;
    v3 = v7 + 1;
LABEL_8:
    if ( v3 > v4 )
      return 0i64;
  }
  if ( v8 > mUID )
  {
    v4 = v7 - 1;
    goto LABEL_8;
  }
  return p[v7];
}

// File Line: 818
// RVA: 0x42C890
UFG::OSuiteLeaderboardData *__fastcall UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
        UFG::OSuiteLeaderboardManager *this,
        const char *leaderboardName)
{
  UFG::qSymbol *v3; // rax
  unsigned int size; // r8d
  int v5; // r9d
  int v6; // r8d
  UFG::OSuiteLeaderboardData **p; // r11
  unsigned int mUID; // r10d
  __int64 v9; // rdx
  unsigned int v10; // eax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  v3 = UFG::qSymbol::create_from_string(&result, leaderboardName);
  size = this->mLeaderboardData_SortedByLeaderboardName.size;
  if ( !size )
    return 0i64;
  v5 = 0;
  v6 = size - 1;
  if ( v6 < 0 )
    return 0i64;
  mUID = v3->mUID;
  while ( 1 )
  {
    v9 = (unsigned int)(v6 + v5) >> 1;
    p = this->mLeaderboardData_SortedByLeaderboardName.p;
    v10 = p[v9]->mLeaderboardName.mUID;
    if ( v10 >= mUID )
      break;
    v5 = v9 + 1;
LABEL_8:
    if ( v5 > v6 )
      return 0i64;
  }
  if ( v10 > mUID )
  {
    v6 = v9 - 1;
    goto LABEL_8;
  }
  return p[v9];
}

// File Line: 822
// RVA: 0x42C840
UFG::OSuiteLeaderboardData *__fastcall UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
        UFG::OSuiteLeaderboardManager *this,
        UFG::qSymbol *key)
{
  unsigned int size; // r8d
  int v3; // r9d
  int v4; // r8d
  UFG::OSuiteLeaderboardData **p; // r11
  unsigned int mUID; // r10d
  __int64 v7; // rcx
  unsigned int v8; // eax

  size = this->mLeaderboardData_SortedByLeaderboardName.size;
  if ( !size )
    return 0i64;
  v3 = 0;
  v4 = size - 1;
  if ( v4 < 0 )
    return 0i64;
  p = this->mLeaderboardData_SortedByLeaderboardName.p;
  mUID = key->mUID;
  while ( 1 )
  {
    v7 = (unsigned int)(v4 + v3) >> 1;
    v8 = p[v7]->mLeaderboardName.mUID;
    if ( v8 >= mUID )
      break;
    v3 = v7 + 1;
LABEL_8:
    if ( v3 > v4 )
      return 0i64;
  }
  if ( v8 > mUID )
  {
    v4 = v7 - 1;
    goto LABEL_8;
  }
  return p[v7];
}

// File Line: 845
// RVA: 0x430DF0
void __fastcall UFG::OSuiteLeaderboardManager::Shutdown(UFG::OSuiteLeaderboardManager *this)
{
  this->m_bExitRequested = 1;
  UFG::qEvent::Signal(&this->m_cThreadEvent);
  UFG::qThread::WaitForCompletion(&this->m_cUpdateThread);
}

// File Line: 875
// RVA: 0x431490
char __fastcall UFG::OSuiteLeaderboardManager::Update(UFG::OSuiteLeaderboardManager *this, float timeDelta)
{
  void (__fastcall *v3)(OSuite::fastdelegate::detail::GenericClass *); // rax
  char result; // al
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> callback; // [rsp+20h] [rbp-28h] BYREF

  if ( !UFG::OSuiteManager::Instance()->m_bConnected
    || UFG::OnlineFriendManager::nState != State_Retrieved
    || !UFG::CachedLeaderboardManager::Instance()->m_bIsCachedLeaderboardBuilt )
  {
    return 0;
  }
  if ( !UFG::OSuiteLeaderboardManager::m_bIsFriendsScoresInserted && this->m_rTimerForFriendsScores > 30.0 )
  {
    callback.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)UFG::OSuiteLeaderboardManager::GetTopFriendsStatScoresCallback;
    v3 = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>::InvokeStaticFunction;
    if ( !UFG::OSuiteLeaderboardManager::GetTopFriendsStatScoresCallback )
      v3 = 0i64;
    callback.m_Closure.m_pFunction = v3;
    UFG::OSuiteLeaderboardManager::GetTopFriendsStatScores(this, &callback);
    this->m_rTimerForFriendsScores = 0.0;
  }
  result = 1;
  this->m_rTimerForFriendsScores = timeDelta + this->m_rTimerForFriendsScores;
  return result;
}

// File Line: 894
// RVA: 0x42F180
char __fastcall UFG::OSuiteLeaderboardManager::QueueUpdateEvent(
        UFG::OSuiteLeaderboardManager *this,
        UFG::OSuiteLeaderboardManager::UpdateEvent *entry)
{
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *mPrev; // rax
  UFG::OSuiteLeaderboardManager *p_mNext; // r9

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->m_cMutex);
  mPrev = this->m_updateEvents.mNode.mPrev;
  p_mNext = (UFG::OSuiteLeaderboardManager *)&this->m_updateEvents.mNode.mNext[-1].mNext;
  mPrev->mNext = &entry->UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent>;
  entry->mPrev = mPrev;
  entry->mNext = &this->m_updateEvents.mNode;
  this->m_updateEvents.mNode.mPrev = &entry->UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent>;
  if ( p_mNext == (UFG::OSuiteLeaderboardManager *)&this->m_pWebServiceClient )
    UFG::qEvent::Signal(&this->m_cThreadEvent);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->m_cMutex);
  return 1;
}

// File Line: 910
// RVA: 0x435560
void __fastcall UFG::OSuiteLeaderboardManager::UploadStatAwardResult(
        UFG::OSuiteLeaderboardManager *this,
        UFG::allocator::free_link *pLBD,
        int score,
        UFG::allocator::free_link *callback)
{
  bool m_bConnected; // di
  UFG::GameStatTracker *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdx
  UFG::allocator::free_link *v12; // rax

  if ( !LODWORD(pLBD[12].mNext) )
  {
    m_bConnected = UFG::OSuiteManager::Instance()->m_bConnected;
    v9 = UFG::GameStatTracker::Instance();
    if ( (int)UFG::GameStatTracker::GetStat(v9, IsBannedByCommunityManager) <= 0 && m_bConnected )
    {
      v10 = UFG::qMalloc(0x38ui64, "OSuiteLeaderboardManager", 0i64);
      v11 = v10;
      if ( v10 )
      {
        v12 = v10 + 1;
        v12->mNext = v12;
        v12[1].mNext = v12;
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable;
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::Score::`vftable;
        v11[4].mNext = pLBD;
        LODWORD(v11[5].mNext) = score;
        v11[6].mNext = callback;
        LODWORD(v11[3].mNext) = 0;
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::StatAwardScore::`vftable;
      }
      else
      {
        v11 = 0i64;
      }
      UFG::OSuiteLeaderboardManager::QueueUpdateEvent(this, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v11);
    }
  }
}

// File Line: 923
// RVA: 0x435650
void __fastcall UFG::OSuiteLeaderboardManager::UploadStatGameResult(
        UFG::OSuiteLeaderboardManager *this,
        UFG::allocator::free_link *pLBD,
        int score,
        UFG::allocator::free_link *callback)
{
  bool m_bConnected; // di
  UFG::GameStatTracker *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdx
  UFG::allocator::free_link *v12; // rax

  if ( LODWORD(pLBD[12].mNext) == 1 )
  {
    m_bConnected = UFG::OSuiteManager::Instance()->m_bConnected;
    v9 = UFG::GameStatTracker::Instance();
    if ( (int)UFG::GameStatTracker::GetStat(v9, IsBannedByCommunityManager) <= 0 && m_bConnected )
    {
      v10 = UFG::qMalloc(0x38ui64, "OSuiteLeaderboardManager", 0i64);
      v11 = v10;
      if ( v10 )
      {
        v12 = v10 + 1;
        v12->mNext = v12;
        v12[1].mNext = v12;
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable;
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::Score::`vftable;
        v11[4].mNext = pLBD;
        LODWORD(v11[5].mNext) = score;
        v11[6].mNext = callback;
        LODWORD(v11[3].mNext) = 1;
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::StatGameScore::`vftable;
      }
      else
      {
        v11 = 0i64;
      }
      UFG::OSuiteLeaderboardManager::QueueUpdateEvent(this, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v11);
    }
  }
}

// File Line: 936
// RVA: 0x435250
void __fastcall UFG::OSuiteLeaderboardManager::UploadMissionResult(
        UFG::OSuiteLeaderboardManager *this,
        UFG::allocator::free_link *pLBD,
        int score,
        UFG::allocator::free_link *callback)
{
  bool m_bConnected; // di
  UFG::GameStatTracker *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdx
  UFG::allocator::free_link *v12; // rax

  if ( LODWORD(pLBD[12].mNext) == 2 )
  {
    m_bConnected = UFG::OSuiteManager::Instance()->m_bConnected;
    v9 = UFG::GameStatTracker::Instance();
    if ( (int)UFG::GameStatTracker::GetStat(v9, IsBannedByCommunityManager) <= 0 && m_bConnected )
    {
      v10 = UFG::qMalloc(0x38ui64, "OSuiteLeaderboardManager", 0i64);
      v11 = v10;
      if ( v10 )
      {
        v12 = v10 + 1;
        v12->mNext = v12;
        v12[1].mNext = v12;
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable;
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::Score::`vftable;
        v11[4].mNext = pLBD;
        LODWORD(v11[5].mNext) = score;
        v11[6].mNext = callback;
        LODWORD(v11[3].mNext) = 2;
        v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::MissionScore::`vftable;
      }
      else
      {
        v11 = 0i64;
      }
      UFG::OSuiteLeaderboardManager::QueueUpdateEvent(this, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v11);
    }
  }
}

// File Line: 949
// RVA: 0x435480
void __fastcall UFG::OSuiteLeaderboardManager::UploadRaceResult(
        UFG::OSuiteLeaderboardManager *this,
        UFG::OSuiteLeaderboardData *pLBD,
        int raceTime,
        bool isWin,
        const char *carUsed,
        void (__fastcall *callback)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, UFG::OSuiteLeaderboardData *))
{
  char v10; // si
  UFG::OSuiteLeaderboardManager::UpdateEvent *v11; // rbx
  UFG::GameStatTracker *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::OSuiteLeaderboardManager::UpdateEvent *v14; // rax

  if ( pLBD->mCategory == LeaderboardCategory_Race )
  {
    v10 = 1;
    v11 = 0i64;
    if ( !UFG::OSuiteManager::Instance()->m_bConnected )
      v10 = 0;
    v12 = UFG::GameStatTracker::Instance();
    if ( (int)UFG::GameStatTracker::GetStat(v12, IsBannedByCommunityManager) <= 0 && v10 )
    {
      v13 = UFG::qMalloc(0x68ui64, "OSuiteLeaderboardManager", 0i64);
      if ( v13 )
      {
        UFG::OSuiteLeaderboardManager::RaceScore::RaceScore(
          (UFG::OSuiteLeaderboardManager::RaceScore *)v13,
          pLBD,
          raceTime,
          isWin,
          carUsed,
          callback);
        v11 = v14;
      }
      UFG::OSuiteLeaderboardManager::QueueUpdateEvent(this, v11);
    }
  }
}

// File Line: 962
// RVA: 0x42AE80
void __fastcall UFG::OSuiteLeaderboardManager::CommandCB(
        UFG::OSuiteLeaderboardManager *this,
        OSuite::SCallbackData *pData,
        OSuite::ZWebServiceClient *pWebServiceClient)
{
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *mNext; // r10
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v7; // rax
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *mPrev; // r9
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> **p_mNext; // rdi
  int v10; // eax
  OSuite::ZOEntry *v11; // rax
  OSuite::ZOProperty *v12; // rax
  int v13; // ebx
  UFG::GameStatTracker *v14; // rax
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v15; // rax
  UFG::UIScreenTextureManager *v16; // rax
  int GameState; // ebx
  UFG::GameSaveLoad *v18; // rax
  UFG::ProgressionTracker *v19; // rax
  UFG::ProgressionTracker::ActiveMasterMode mActiveMasterMode; // ebx
  UFG::ProgressionTracker::State mState; // edi
  bool v22; // al
  UFG::GameSaveLoad *v23; // rax
  bool outValue; // [rsp+40h] [rbp+8h] BYREF

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->m_cMutex);
  mNext = this->m_updateEvents.mNode.mNext;
  v7 = mNext->mNext;
  mPrev = mNext->mPrev;
  p_mNext = &mNext[-1].mNext;
  mPrev->mNext = v7;
  v7->mPrev = mPrev;
  mNext->mPrev = mNext;
  mNext->mNext = mNext;
  v10 = (int)mNext[1].mPrev;
  switch ( v10 )
  {
    case 4:
      if ( pData->Status.eError == HTTPERROR_OK )
        UFG::OSuiteLeaderboardManager::ScanOrResetPlayerStats(0i64);
      break;
    case 6:
      if ( pData->Status.eError == HTTPERROR_OK )
      {
        v11 = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOEntry>(pWebServiceClient, &pData->URL);
        if ( v11 )
        {
          v12 = OSuite::ZOEntry::Property(v11, "b_Banned");
          if ( v12 )
          {
            outValue = 0;
            OSuite::ZOProperty::GetValue(v12, &outValue);
            v13 = outValue;
            v14 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::SetStat(v14, IsBannedByCommunityManager, v13);
          }
        }
      }
      break;
    case 7:
    case 8:
      goto LABEL_16;
    case 9:
    case 10:
      ((void (__fastcall *)(UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *, OSuite::SCallbackData *, OSuite::ZWebServiceClient *))p_mNext[5])(
        p_mNext[4],
        pData,
        pWebServiceClient);
      break;
    case 11:
LABEL_16:
      ((void (__fastcall *)(UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *, OSuite::SCallbackData *, OSuite::ZWebServiceClient *))p_mNext[7])(
        p_mNext[6],
        pData,
        pWebServiceClient);
      break;
    default:
      v15 = p_mNext[6];
      if ( v15 )
        ((void (__fastcall *)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *))v15)(
          pData,
          pWebServiceClient,
          p_mNext[4]);
      break;
  }
  ((void (__fastcall *)(UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> **, __int64))(*p_mNext)->mPrev)(
    p_mNext,
    1i64);
  if ( this->m_bQueueOptionsSave
    && (OSuite::ZWebServiceClient **)&this->m_updateEvents.mNode.mNext[-1].mNext == &this->m_pWebServiceClient )
  {
    v16 = UFG::UIScreenTextureManager::Instance();
    GameState = UFG::UIScreenTextureManager::GetGameState(v16);
    v18 = UFG::GameSaveLoad::Instance();
    if ( UFG::GameSaveLoad::IsSaveAvaliable(v18) && GameState == 2 )
    {
      v19 = UFG::ProgressionTracker::Instance();
      mActiveMasterMode = v19->mActiveMasterMode;
      mState = v19->mState;
      v22 = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "GarageBrowser") != 0i64;
      if ( mActiveMasterMode == ActiveMasterMode_OpenWorld && mState == STATE_COMPLETE && !v22 )
      {
        v23 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SaveAutoGameSlot(v23);
        this->m_bQueueOptionsSave = 0;
      }
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->m_cMutex);
  UFG::qEvent::Signal(&this->m_cThreadEvent);
}

// File Line: 1042
// RVA: 0x4321F0
void __fastcall UFG::OSuiteLeaderboardManager::UpdateThread(char *param)
{
  char *v2; // rbx
  UFG::OnlineId *OnlineId; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mPrev; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mNext; // rax
  __int64 v6; // rsi
  int v7; // eax
  __int64 v8; // rax
  bool v9; // cf
  unsigned __int64 v10; // rax
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v11; // rax
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **p_mNext; // rbx
  unsigned int v13; // eax
  __int64 v14; // rbx
  unsigned __int64 v15; // rax
  OSuite::ZRedBlackTreeBase *v16; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v17; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v18; // rax
  unsigned __int64 v19; // rax
  unsigned int v20; // eax
  __int64 v21; // rbx
  unsigned __int64 v22; // rax
  OSuite::ZRedBlackTreeBase *v23; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v24; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v25; // rax
  unsigned __int64 v26; // rax
  OSuite::ZOQuery *p_query; // rcx
  __int64 v28; // rax
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
  __int64 v39; // rax
  unsigned __int64 v40; // rax
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v41; // rax
  void **v42; // rbx
  unsigned int v43; // eax
  __int64 v44; // rbx
  unsigned __int64 v45; // rax
  OSuite::ZRedBlackTreeBase *v46; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v47; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v48; // rax
  unsigned __int64 v49; // rax
  OSuite::ZString *v50; // rax
  OSuite::ZString *v51; // rdi
  unsigned int v52; // eax
  __int64 v53; // rbx
  unsigned __int64 v54; // rax
  unsigned __int64 v55; // rax
  __int64 v56; // rax
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
  __int64 v73; // rax
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
  UFG::qString *OnlineName; // rax
  unsigned int v129; // eax
  __int64 v130; // rbx
  unsigned __int64 v131; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v132; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v133; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v134; // rax
  unsigned __int64 v135; // rax
  int SystemRegion; // eax
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
  OSuite::TMap<OSuite::ZString,OSuite::ZString> v214; // [rsp+30h] [rbp-A8h] BYREF
  OSuite::TMap<OSuite::ZString,OSuite::ZString> params; // [rsp+50h] [rbp-88h] BYREF
  void **v216; // [rsp+70h] [rbp-68h] BYREF
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **v217; // [rsp+78h] [rbp-60h]
  __int64 v218; // [rsp+80h] [rbp-58h]
  OSuite::TMap<OSuite::ZString,OSuite::ZString> v219; // [rsp+88h] [rbp-50h] BYREF
  OSuite::TMap<OSuite::ZString,OSuite::ZString> v220; // [rsp+A8h] [rbp-30h] BYREF
  OSuite::TMap<OSuite::ZString,OSuite::ZString> v221; // [rsp+C8h] [rbp-10h] BYREF
  OSuite::TMap<OSuite::ZString,OSuite::ZString> v222; // [rsp+E8h] [rbp+10h] BYREF
  UFG::OnlineId result; // [rsp+108h] [rbp+30h] BYREF
  UFG::qString v224; // [rsp+120h] [rbp+48h] BYREF
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> v225; // [rsp+148h] [rbp+70h] BYREF
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> v226; // [rsp+158h] [rbp+80h] BYREF
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> v227; // [rsp+168h] [rbp+90h] BYREF
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> cb; // [rsp+178h] [rbp+A0h] BYREF
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> v229; // [rsp+188h] [rbp+B0h] BYREF
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> v230; // [rsp+198h] [rbp+C0h] BYREF
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> v231; // [rsp+1A8h] [rbp+D0h] BYREF
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> v232; // [rsp+1B8h] [rbp+E0h] BYREF
  OSuite::ZString v233; // [rsp+1C8h] [rbp+F0h] BYREF
  OSuite::ZString v234; // [rsp+1E0h] [rbp+108h] BYREF
  OSuite::ZString v235; // [rsp+1F8h] [rbp+120h] BYREF
  OSuite::ZString key; // [rsp+210h] [rbp+138h] BYREF
  OSuite::ZString v237; // [rsp+228h] [rbp+150h] BYREF
  OSuite::ZString v238; // [rsp+240h] [rbp+168h] BYREF
  OSuite::ZString v239; // [rsp+258h] [rbp+180h] BYREF
  OSuite::ZString v240; // [rsp+270h] [rbp+198h] BYREF
  OSuite::ZString v241; // [rsp+288h] [rbp+1B0h] BYREF
  OSuite::ZString v242; // [rsp+2A0h] [rbp+1C8h] BYREF
  OSuite::ZString v243; // [rsp+2B8h] [rbp+1E0h] BYREF
  OSuite::ZString v244; // [rsp+2D0h] [rbp+1F8h] BYREF
  OSuite::ZString that; // [rsp+2E8h] [rbp+210h] BYREF
  OSuite::ZString v246; // [rsp+300h] [rbp+228h] BYREF
  OSuite::ZString v247; // [rsp+318h] [rbp+240h] BYREF
  OSuite::ZString v248; // [rsp+330h] [rbp+258h] BYREF
  OSuite::ZString v249; // [rsp+348h] [rbp+270h] BYREF
  OSuite::ZString v250; // [rsp+360h] [rbp+288h] BYREF
  OSuite::ZString v251; // [rsp+378h] [rbp+2A0h] BYREF
  OSuite::ZString v252; // [rsp+390h] [rbp+2B8h] BYREF
  OSuite::ZString v253; // [rsp+3A8h] [rbp+2D0h] BYREF
  OSuite::ZString v254; // [rsp+3C0h] [rbp+2E8h] BYREF
  OSuite::ZString v255; // [rsp+3D8h] [rbp+300h] BYREF
  OSuite::ZString v256; // [rsp+3F0h] [rbp+318h] BYREF
  OSuite::ZString v257; // [rsp+408h] [rbp+330h] BYREF
  OSuite::ZString v258; // [rsp+420h] [rbp+348h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v259; // [rsp+438h] [rbp+360h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v260; // [rsp+470h] [rbp+398h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> data; // [rsp+4A8h] [rbp+3D0h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v262; // [rsp+4E0h] [rbp+408h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v263; // [rsp+518h] [rbp+440h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v264; // [rsp+550h] [rbp+478h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v265; // [rsp+588h] [rbp+4B0h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v266; // [rsp+5C0h] [rbp+4E8h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v267; // [rsp+5F8h] [rbp+520h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v268; // [rsp+630h] [rbp+558h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v269; // [rsp+668h] [rbp+590h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v270; // [rsp+6A0h] [rbp+5C8h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v271; // [rsp+6D8h] [rbp+600h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v272; // [rsp+710h] [rbp+638h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v273; // [rsp+748h] [rbp+670h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> v274; // [rsp+780h] [rbp+6A8h] BYREF
  OSuite::ZString v275; // [rsp+7B8h] [rbp+6E0h] BYREF
  OSuite::ZString v276; // [rsp+7D0h] [rbp+6F8h] BYREF
  OSuite::ZString v277; // [rsp+7E8h] [rbp+710h] BYREF
  OSuite::ZString v278; // [rsp+800h] [rbp+728h] BYREF
  OSuite::ZString v279; // [rsp+818h] [rbp+740h] BYREF
  OSuite::ZString v280; // [rsp+830h] [rbp+758h] BYREF
  OSuite::ZString v281; // [rsp+848h] [rbp+770h] BYREF
  OSuite::ZString v282; // [rsp+860h] [rbp+788h] BYREF
  OSuite::ZString v283; // [rsp+878h] [rbp+7A0h] BYREF
  OSuite::ZString v284; // [rsp+890h] [rbp+7B8h] BYREF
  __int64 v285; // [rsp+8A8h] [rbp+7D0h]
  OSuite::ZString v286; // [rsp+8B0h] [rbp+7D8h] BYREF
  OSuite::ZString v287; // [rsp+8C8h] [rbp+7F0h] BYREF
  OSuite::ZString v288; // [rsp+8E0h] [rbp+808h] BYREF
  OSuite::ZString v289; // [rsp+8F8h] [rbp+820h] BYREF
  OSuite::ZString v290; // [rsp+910h] [rbp+838h] BYREF
  OSuite::ZString v291; // [rsp+928h] [rbp+850h] BYREF
  OSuite::ZString v292; // [rsp+940h] [rbp+868h] BYREF
  OSuite::ZString v293; // [rsp+958h] [rbp+880h] BYREF
  OSuite::ZString v294; // [rsp+970h] [rbp+898h] BYREF
  OSuite::ZString v295; // [rsp+988h] [rbp+8B0h] BYREF
  OSuite::ZString v296; // [rsp+9A0h] [rbp+8C8h] BYREF
  OSuite::ZString v297; // [rsp+9B8h] [rbp+8E0h] BYREF
  OSuite::ZString v298; // [rsp+9D0h] [rbp+8F8h] BYREF
  OSuite::ZString v299; // [rsp+9E8h] [rbp+910h] BYREF
  OSuite::ZString v300; // [rsp+A00h] [rbp+928h] BYREF
  OSuite::ZString v301; // [rsp+A18h] [rbp+940h] BYREF
  OSuite::ZOQuery v302; // [rsp+A38h] [rbp+960h] BYREF
  UFG::qString v303; // [rsp+AA8h] [rbp+9D0h] BYREF
  OSuite::ZOQuery v304; // [rsp+AD8h] [rbp+A00h] BYREF
  OSuite::ZOQuery v305; // [rsp+B48h] [rbp+A70h] BYREF
  OSuite::ZOQuery v306; // [rsp+BB8h] [rbp+AE0h] BYREF
  OSuite::ZOQuery query; // [rsp+C28h] [rbp+B50h] BYREF
  OSuite::ZOQuery v308; // [rsp+C98h] [rbp+BC0h] BYREF
  OSuite::ZOQuery v309; // [rsp+D08h] [rbp+C30h] BYREF
  OSuite::ZOQuery v310; // [rsp+D78h] [rbp+CA0h] BYREF
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v311; // [rsp+E18h] [rbp+D40h]

  v285 = -2i64;
  if ( !param[101] )
  {
    v2 = param + 72;
    do
    {
      if ( (_S5_9 & 1) == 0 )
      {
        _S5_9 |= 1u;
        instance.vfptr = (UFG::OnlineManagerVtbl *)&UFG::OnlineManager::`vftable;
        unk_1424011B8 = 0;
        v311 = &stru_1424011C0;
        stru_1424011C0.mNode.mPrev = (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *)&stru_1424011C0;
        stru_1424011C0.mNode.mNext = (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *)&stru_1424011C0;
        UFG::qString::qString(&stru_1424011D0);
        atexit(UFG::OnlineManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
      }
      OnlineId = UFG::OnlineManager::GetOnlineId(&instance, &result);
      UFG::OnlineId::ToString(OnlineId, &v224);
      mPrev = result.mPrev;
      mNext = result.mNext;
      result.mPrev->mNext = result.mNext;
      mNext->mPrev = mPrev;
      result.mPrev = &result;
      result.mNext = &result;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)(param + 104));
      if ( (char *)(*((_QWORD *)param + 11) - 8i64) == v2 || v224.mLength <= 0 )
        goto LABEL_156;
      v6 = *((_QWORD *)param + 11);
      v7 = *(_DWORD *)(v6 + 16);
      switch ( v7 )
      {
        case 4:
          OSuite::ZOQuery::ZOQuery(&query);
          v216 = &OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
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
            p_mNext = &v11->mNode.mNext;
            `eh vector constructor iterator(
              &v11->mNode.mNext,
              0x28ui64,
              16,
              (void (__fastcall *)(void *))OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>);
          }
          else
          {
            p_mNext = 0i64;
          }
          v217 = p_mNext;
          OSuite::ZString::ZString(&v278, v224.mData);
          OSuite::ZString::ZString(&that, "s_Pid");
          v13 = that.OSuite::IHashable::vfptr->ComputeHash(&that.OSuite::IHashable);
          v14 = 5i64 * (int)((LODWORD(params.m_pLists) - 1) & v13);
          v15 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v217[v14]);
          *(_QWORD *)&params.m_nHashSize -= v15;
          v16 = (OSuite::ZRedBlackTreeBase *)&v217[v14];
          data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&data.m_First, &that);
          OSuite::ZString::ZString(&data.m_Second, &v278);
          data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v17 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v17;
          if ( v17 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v17,
              &data);
          else
            v18 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet(v16, v18);
          data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&data.m_Second);
          OSuite::ZString::~ZString(&data.m_First);
          v19 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v217[v14]);
          *(_QWORD *)&params.m_nHashSize += v19;
          OSuite::ZString::~ZString(&that);
          OSuite::ZString::~ZString(&v278);
          OSuite::ZString::ZString(&v288, **(const char ***)(v6 + 24));
          OSuite::ZString::ZString(&v246, "s_Stats");
          v20 = v246.OSuite::IHashable::vfptr->ComputeHash(&v246.OSuite::IHashable);
          v21 = 5i64 * (int)((LODWORD(params.m_pLists) - 1) & v20);
          v22 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v217[v21]);
          *(_QWORD *)&params.m_nHashSize -= v22;
          v23 = (OSuite::ZRedBlackTreeBase *)&v217[v21];
          v271.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&v271.m_First, &v246);
          OSuite::ZString::ZString(&v271.m_Second, &v288);
          v271.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v24 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v24;
          if ( v24 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v24,
              &v271);
          else
            v25 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet(v23, v25);
          v271.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
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
          cb.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(param);
          OSuite::ZWebServiceClient::ExecuteQuery(*((OSuite::ZWebServiceClient **)param + 9), &query, &cb);
          v216 = &OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
          if ( v217 )
          {
            if ( *((_DWORD *)v217 - 2) )
              ((void (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **, __int64))(*v217)->mPrev)(
                v217,
                3i64);
            else
              operator delete[](v217 - 1);
          }
          p_query = &query;
          break;
        case 6:
          OSuite::ZOQuery::ZOQuery(&v309);
          v221.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
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
            `eh vector constructor iterator(
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
          v32 = v248.OSuite::IHashable::vfptr->ComputeHash(&v248.OSuite::IHashable);
          v33 = (int)((v221.m_nHashSize - 1) & v32);
          v34 = OSuite::ZHttpStreamReader::Tell(&v221.m_pLists[v33]);
          v221.m_nCount -= v34;
          v35 = &v221.m_pLists[v33];
          v263.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&v263.m_First, &v248);
          OSuite::ZString::ZString(&v263.m_Second, &v280);
          v263.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v36 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v36;
          if ( v36 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v36,
              &v263);
          else
            v37 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet(v35, v37);
          v263.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&v263.m_Second);
          OSuite::ZString::~ZString(&v263.m_First);
          v38 = OSuite::ZHttpStreamReader::Tell(&v221.m_pLists[v33]);
          v221.m_nCount += v38;
          OSuite::ZString::~ZString(&v248);
          OSuite::ZString::~ZString(&v280);
          OSuite::ZOQuery::ServiceOperation(&v309, "GetBanStatus", &v221);
          v230.m_Closure.m_pthis = 0i64;
          v230.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteLeaderboardManager::CommandCB;
          v230.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(param);
          OSuite::ZWebServiceClient::ExecuteQuery(*((OSuite::ZWebServiceClient **)param + 9), &v309, &v230);
          v221.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
          if ( v221.m_pLists )
          {
            if ( LODWORD(v221.m_pLists[-1].m_Comparer.vfptr) )
              v221.m_pLists->vfptr->__vecDelDtor(v221.m_pLists, 3u);
            else
              operator delete[](&v221.m_pLists[-1].m_Comparer.OSuite::ZObject);
          }
          p_query = &v309;
          break;
        case 7:
          OSuite::ZOQuery::ZOQuery(&v304);
          params.m_nCount = (unsigned __int64)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
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
            `eh vector constructor iterator(
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
          v43 = v234.OSuite::IHashable::vfptr->ComputeHash(&v234.OSuite::IHashable);
          v44 = 5i64 * (int)(((_DWORD)v217 - 1) & v43);
          v45 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v216[v44]);
          v218 -= v45;
          v46 = (OSuite::ZRedBlackTreeBase *)&v216[v44];
          v269.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&v269.m_First, &v234);
          OSuite::ZString::ZString(&v269.m_Second, &v286);
          v269.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v47 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v47;
          if ( v47 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v47,
              &v269);
          else
            v48 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet(v46, v48);
          v269.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&v269.m_Second);
          OSuite::ZString::~ZString(&v269.m_First);
          v49 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&v216[v44]);
          v218 += v49;
          OSuite::ZString::~ZString(&v234);
          OSuite::ZString::~ZString(&v286);
          OSuite::ZString::ZString(&key, "i32_LB");
          OSuite::ZString::ZString(&v295, *(_DWORD *)(*(_QWORD *)(v6 + 24) + 4i64));
          v51 = v50;
          v52 = key.OSuite::IHashable::vfptr->ComputeHash(&key.OSuite::IHashable);
          v53 = 5i64 * (int)(v52 & ((_DWORD)v217 - 1));
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
            (OSuite::TMap<OSuite::ZString,OSuite::ZString> *)&params.m_nCount);
          v232.m_Closure.m_pthis = 0i64;
          v232.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteLeaderboardManager::CommandCB;
          v232.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(param);
          OSuite::ZWebServiceClient::ExecuteQuery(*((OSuite::ZWebServiceClient **)param + 9), &v304, &v232);
          params.m_nCount = (unsigned __int64)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
          if ( v216 )
          {
            if ( *((_DWORD *)v216 - 2) )
              (*(void (__fastcall **)(void **, __int64))*v216)(v216, 3i64);
            else
              operator delete[](v216 - 1);
          }
          p_query = &v304;
          break;
        case 8:
          OSuite::ZOQuery::ZOQuery(&v305);
          v219.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
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
            `eh vector constructor iterator(
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
          v60 = v238.OSuite::IHashable::vfptr->ComputeHash(&v238.OSuite::IHashable);
          v61 = (int)((v219.m_nHashSize - 1) & v60);
          v62 = OSuite::ZHttpStreamReader::Tell(&v219.m_pLists[v61]);
          v219.m_nCount -= v62;
          v63 = &v219.m_pLists[v61];
          v265.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&v265.m_First, &v238);
          OSuite::ZString::ZString(&v265.m_Second, &v282);
          v265.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v64 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v64;
          if ( v64 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v64,
              &v265);
          else
            v65 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet(v63, v65);
          v265.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&v265.m_Second);
          OSuite::ZString::~ZString(&v265.m_First);
          v66 = OSuite::ZHttpStreamReader::Tell(&v219.m_pLists[v61]);
          v219.m_nCount += v66;
          OSuite::ZString::~ZString(&v238);
          OSuite::ZString::~ZString(&v282);
          OSuite::ZString::ZString(&v240, "i32_LB");
          OSuite::ZString::ZString(&v301, *(_DWORD *)(*(_QWORD *)(v6 + 24) + 4i64));
          v68 = v67;
          v69 = v240.OSuite::IHashable::vfptr->ComputeHash(&v240.OSuite::IHashable);
          v70 = (int)(v69 & (v219.m_nHashSize - 1));
          v71 = OSuite::ZHttpStreamReader::Tell(&v219.m_pLists[v70]);
          v219.m_nCount -= v71;
          OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
            &v219.m_pLists[v70],
            &v240,
            v68);
          v72 = OSuite::ZHttpStreamReader::Tell(&v219.m_pLists[v70]);
          v219.m_nCount += v72;
          OSuite::ZString::~ZString(&v301);
          OSuite::ZString::~ZString(&v240);
          OSuite::ZOQuery::ServiceOperation(&v305, *(const char **)(v6 + 32), &v219);
          v227.m_Closure.m_pthis = 0i64;
          v227.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteLeaderboardManager::CommandCB;
          v227.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(param);
          OSuite::ZWebServiceClient::ExecuteQuery(*((OSuite::ZWebServiceClient **)param + 9), &v305, &v227);
          v219.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
          if ( v219.m_pLists )
          {
            if ( LODWORD(v219.m_pLists[-1].m_Comparer.vfptr) )
              v219.m_pLists->vfptr->__vecDelDtor(v219.m_pLists, 3u);
            else
              operator delete[](&v219.m_pLists[-1].m_Comparer.OSuite::ZObject);
          }
          p_query = &v305;
          break;
        case 9:
          OSuite::ZOQuery::ZOQuery(&v306);
          v220.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
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
            `eh vector constructor iterator(
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
          v77 = v242.OSuite::IHashable::vfptr->ComputeHash(&v242.OSuite::IHashable);
          v78 = (int)((v220.m_nHashSize - 1) & v77);
          v79 = OSuite::ZHttpStreamReader::Tell(&v220.m_pLists[v78]);
          v220.m_nCount -= v79;
          v80 = &v220.m_pLists[v78];
          v273.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&v273.m_First, &v242);
          OSuite::ZString::ZString(&v273.m_Second, &v290);
          v273.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v81 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v81;
          if ( v81 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v81,
              &v273);
          else
            v82 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet(v80, v82);
          v273.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&v273.m_Second);
          OSuite::ZString::~ZString(&v273.m_First);
          v83 = OSuite::ZHttpStreamReader::Tell(&v220.m_pLists[v78]);
          v220.m_nCount += v83;
          OSuite::ZString::~ZString(&v242);
          OSuite::ZString::~ZString(&v290);
          OSuite::ZOQuery::ServiceOperation(&v306, "GetTopFriendsStatScores", &v220);
          v231.m_Closure.m_pthis = 0i64;
          v231.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteLeaderboardManager::CommandCB;
          v231.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(param);
          OSuite::ZWebServiceClient::ExecuteQuery(*((OSuite::ZWebServiceClient **)param + 9), &v306, &v231);
          v220.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
          if ( v220.m_pLists )
          {
            if ( LODWORD(v220.m_pLists[-1].m_Comparer.vfptr) )
              v220.m_pLists->vfptr->__vecDelDtor(v220.m_pLists, 3u);
            else
              operator delete[](&v220.m_pLists[-1].m_Comparer.OSuite::ZObject);
          }
          p_query = &v306;
          break;
        case 10:
          OSuite::ZOQuery::ZOQuery(&v308);
          OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&v222, 0x10ui64);
          OSuite::ZString::ZString(&v284, v224.mData);
          OSuite::ZString::ZString(&v244, "s_Pid");
          v84 = v244.OSuite::IHashable::vfptr->ComputeHash(&v244.OSuite::IHashable);
          v85 = (int)((v222.m_nHashSize - 1) & v84);
          v86 = OSuite::ZHttpStreamReader::Tell(&v222.m_pLists[v85]);
          v222.m_nCount -= v86;
          v87 = &v222.m_pLists[v85];
          v267.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&v267.m_First, &v244);
          OSuite::ZString::ZString(&v267.m_Second, &v284);
          v267.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v88 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v88;
          if ( v88 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v88,
              &v267);
          else
            v89 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet(v87, v89);
          v267.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&v267.m_Second);
          OSuite::ZString::~ZString(&v267.m_First);
          v90 = OSuite::ZHttpStreamReader::Tell(&v222.m_pLists[v85]);
          v222.m_nCount += v90;
          OSuite::ZString::~ZString(&v244);
          OSuite::ZString::~ZString(&v284);
          OSuite::ZOQuery::ServiceOperation(&v308, "GetPlayerStats", &v222);
          v229.m_Closure.m_pthis = 0i64;
          v229.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteLeaderboardManager::CommandCB;
          v229.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(param);
          OSuite::ZWebServiceClient::ExecuteQuery(*((OSuite::ZWebServiceClient **)param + 9), &v308, &v229);
          v222.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
          if ( v222.m_pLists )
          {
            if ( LODWORD(v222.m_pLists[-1].m_Comparer.vfptr) )
              v222.m_pLists->vfptr->__vecDelDtor(v222.m_pLists, 3u);
            else
              operator delete[](&v222.m_pLists[-1].m_Comparer.OSuite::ZObject);
          }
          p_query = &v308;
          break;
        case 11:
          v91 = *(_DWORD *)(*(_QWORD *)(v6 + 24) + 96i64);
          v92 = &customCaption;
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
          v95 = v235.OSuite::IHashable::vfptr->ComputeHash(&v235.OSuite::IHashable);
          v96 = (int)((params.m_nHashSize - 1) & v95);
          v97 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v96]);
          params.m_nCount -= v97;
          v98 = &params.m_pLists[v96];
          v260.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&v260.m_First, &v235);
          OSuite::ZString::ZString(&v260.m_Second, &v277);
          v260.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v99 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v99;
          if ( v99 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v99,
              &v260);
          OSuite::ZRedBlackTreeBase::InsertElementSet(v98, v99);
          v260.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&v260.m_Second);
          OSuite::ZString::~ZString(&v260.m_First);
          v100 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v96]);
          params.m_nCount += v100;
          OSuite::ZString::~ZString(&v235);
          OSuite::ZString::~ZString(&v277);
          OSuite::ZString::ZString(&v279, v92);
          OSuite::ZString::ZString(&v250, "s_LBType");
          v101 = v250.OSuite::IHashable::vfptr->ComputeHash(&v250.OSuite::IHashable);
          v102 = (int)((params.m_nHashSize - 1) & v101);
          v103 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v102]);
          params.m_nCount -= v103;
          v104 = &params.m_pLists[v102];
          v262.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&v262.m_First, &v250);
          OSuite::ZString::ZString(&v262.m_Second, &v279);
          v262.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v105 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v105;
          if ( v105 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v105,
              &v262);
          else
            v106 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet(v104, v106);
          v262.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&v262.m_Second);
          OSuite::ZString::~ZString(&v262.m_First);
          v107 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v102]);
          params.m_nCount += v107;
          OSuite::ZString::~ZString(&v250);
          OSuite::ZString::~ZString(&v279);
          OSuite::ZString::ZString(&v237, "i32_LB");
          OSuite::ZString::ZString(&v300, *(_DWORD *)(*(_QWORD *)(v6 + 24) + 4i64));
          v109 = v108;
          v110 = v237.OSuite::IHashable::vfptr->ComputeHash(&v237.OSuite::IHashable);
          v111 = (int)(v110 & (params.m_nHashSize - 1));
          v112 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v111]);
          params.m_nCount -= v112;
          OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
            &params.m_pLists[v111],
            &v237,
            v109);
          v113 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v111]);
          params.m_nCount += v113;
          OSuite::ZString::~ZString(&v300);
          OSuite::ZString::~ZString(&v237);
          OSuite::ZString::ZString(&v252, "i32_Score");
          OSuite::ZString::ZString(&v298, *(_DWORD *)(v6 + 32));
          v115 = v114;
          v116 = v252.OSuite::IHashable::vfptr->ComputeHash(&v252.OSuite::IHashable);
          v117 = (int)(v116 & (params.m_nHashSize - 1));
          v118 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v117]);
          params.m_nCount -= v118;
          OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
            &params.m_pLists[v117],
            &v252,
            v115);
          v119 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v117]);
          params.m_nCount += v119;
          OSuite::ZString::~ZString(&v298);
          OSuite::ZString::~ZString(&v252);
          OSuite::ZOQuery::ServiceOperation(&v310, "GetChallengeFriends", &params);
          v226.m_Closure.m_pthis = 0i64;
          v226.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteLeaderboardManager::CommandCB;
          v226.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(param);
          OSuite::ZWebServiceClient::ExecuteQuery(*((OSuite::ZWebServiceClient **)param + 9), &v310, &v226);
          params.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
          if ( params.m_pLists )
          {
            if ( LODWORD(params.m_pLists[-1].m_Comparer.vfptr) )
              params.m_pLists->vfptr->__vecDelDtor(params.m_pLists, 3u);
            else
              operator delete[](&params.m_pLists[-1].m_Comparer.OSuite::ZObject);
          }
          p_query = &v310;
          break;
        default:
          OSuite::ZOQuery::ZOQuery(&v302);
          OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&v214, 0x10ui64);
          OSuite::ZString::ZString(&v281, v224.mData);
          OSuite::ZString::ZString(&v239, "s_Pid");
          v120 = v239.OSuite::IHashable::vfptr->ComputeHash(&v239.OSuite::IHashable);
          v121 = (int)((v214.m_nHashSize - 1) & v120);
          v122 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v121]);
          v214.m_nCount -= v122;
          v123 = &v214.m_pLists[v121];
          v264.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&v264.m_First, &v239);
          OSuite::ZString::ZString(&v264.m_Second, &v281);
          v264.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v124 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v124;
          if ( v124 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v124,
              &v264);
          else
            v125 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet(v123, v125);
          v264.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&v264.m_Second);
          OSuite::ZString::~ZString(&v264.m_First);
          v126 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v121]);
          v214.m_nCount += v126;
          OSuite::ZString::~ZString(&v239);
          OSuite::ZString::~ZString(&v281);
          v127 = UFG::OnlineManager::Instance();
          OnlineName = UFG::OnlineManager::GetOnlineName(v127, &v303);
          OSuite::ZString::ZString(&v283, OnlineName->mData);
          OSuite::ZString::ZString(&v254, "s_Name");
          v129 = v254.OSuite::IHashable::vfptr->ComputeHash(&v254.OSuite::IHashable);
          v130 = (int)((v214.m_nHashSize - 1) & v129);
          v131 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v130]);
          v214.m_nCount -= v131;
          v132 = &v214.m_pLists[v130];
          v266.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&v266.m_First, &v254);
          OSuite::ZString::ZString(&v266.m_Second, &v283);
          v266.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v133 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v133;
          if ( v133 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v133,
              &v266);
          else
            v134 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet(v132, v134);
          v266.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&v266.m_Second);
          OSuite::ZString::~ZString(&v266.m_First);
          v135 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v130]);
          v214.m_nCount += v135;
          OSuite::ZString::~ZString(&v254);
          OSuite::ZString::~ZString(&v283);
          UFG::qString::~qString(&v303);
          SystemRegion = GetSystemRegion();
          v137 = MapRegionToRegionCode(SystemRegion);
          OSuite::ZString::ZString(&v275, v137);
          OSuite::ZString::ZString(&v241, "s_Region");
          v138 = v241.OSuite::IHashable::vfptr->ComputeHash(&v241.OSuite::IHashable);
          v139 = (int)((v214.m_nHashSize - 1) & v138);
          v140 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v139]);
          v214.m_nCount -= v140;
          v141 = &v214.m_pLists[v139];
          v268.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&v268.m_First, &v241);
          OSuite::ZString::ZString(&v268.m_Second, &v275);
          v268.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v142 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v142;
          if ( v142 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v142,
              &v268);
          else
            v143 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet(v141, v143);
          v268.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&v268.m_Second);
          OSuite::ZString::~ZString(&v268.m_First);
          v144 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v139]);
          v214.m_nCount += v144;
          OSuite::ZString::~ZString(&v241);
          OSuite::ZString::~ZString(&v275);
          OSuite::ZString::ZString(&v256, "i32_DLC");
          OSuite::ZString::ZString(&v296, 0);
          v146 = v145;
          v147 = v256.OSuite::IHashable::vfptr->ComputeHash(&v256.OSuite::IHashable);
          v148 = (int)(v147 & (v214.m_nHashSize - 1));
          v149 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v148]);
          v214.m_nCount -= v149;
          OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
            &v214.m_pLists[v148],
            &v256,
            v146);
          v150 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v148]);
          v214.m_nCount += v150;
          OSuite::ZString::~ZString(&v296);
          OSuite::ZString::~ZString(&v256);
          OSuite::ZString::ZString(&v243, "i32_LB");
          OSuite::ZString::ZString(&v297, *(_DWORD *)(*(_QWORD *)(v6 + 24) + 4i64));
          v152 = v151;
          v153 = v243.OSuite::IHashable::vfptr->ComputeHash(&v243.OSuite::IHashable);
          v154 = (int)(v153 & (v214.m_nHashSize - 1));
          v155 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v154]);
          v214.m_nCount -= v155;
          OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
            &v214.m_pLists[v154],
            &v243,
            v152);
          v156 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v154]);
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
              v188 = v253.OSuite::IHashable::vfptr->ComputeHash(&v253.OSuite::IHashable);
              v189 = (int)((v214.m_nHashSize - 1) & v188);
              v190 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v189]);
              v214.m_nCount -= v190;
              v191 = &v214.m_pLists[v189];
              v274.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
              OSuite::ZString::ZString(&v274.m_First, &v253);
              OSuite::ZString::ZString(&v274.m_Second, &v291);
              v274.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
              v192 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
              v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v192;
              if ( v192 )
                OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
                  v192,
                  &v274);
              else
                v193 = 0i64;
              OSuite::ZRedBlackTreeBase::InsertElementSet(v191, v193);
              v274.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
              OSuite::ZString::~ZString(&v274.m_Second);
              OSuite::ZString::~ZString(&v274.m_First);
              v194 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v189]);
              v214.m_nCount += v194;
              OSuite::ZString::~ZString(&v253);
              OSuite::ZString::~ZString(&v291);
              OSuite::ZString::ZString(&v249, "i32_Score");
              OSuite::ZString::ZString(&v294, *(_DWORD *)(v6 + 32));
              v196 = v195;
              v197 = v249.OSuite::IHashable::vfptr->ComputeHash(&v249.OSuite::IHashable);
              v198 = (int)(v197 & (v214.m_nHashSize - 1));
              v199 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v198]);
              v214.m_nCount -= v199;
              OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
                &v214.m_pLists[v198],
                &v249,
                v196);
              v200 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v198]);
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
              v184 = v247.OSuite::IHashable::vfptr->ComputeHash(&v247.OSuite::IHashable);
              v185 = (int)(v184 & (v214.m_nHashSize - 1));
              v186 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v185]);
              v214.m_nCount -= v186;
              OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
                &v214.m_pLists[v185],
                &v247,
                v183);
              v187 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v185]);
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
              v162 = v258.OSuite::IHashable::vfptr->ComputeHash(&v258.OSuite::IHashable);
              v163 = (int)(v162 & (v214.m_nHashSize - 1));
              v164 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v163]);
              v214.m_nCount -= v164;
              OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
                &v214.m_pLists[v163],
                &v258,
                v161);
              v165 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v163]);
              v214.m_nCount += v165;
              OSuite::ZString::~ZString(&v299);
              OSuite::ZString::~ZString(&v258);
              v166 = "false";
              if ( *(_BYTE *)(v6 + 48) )
                v166 = "true";
              OSuite::ZString::ZString(&v287, v166);
              OSuite::ZString::ZString(&v233, "b_Won");
              v167 = v233.OSuite::IHashable::vfptr->ComputeHash(&v233.OSuite::IHashable);
              v168 = (int)((v214.m_nHashSize - 1) & v167);
              v169 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v168]);
              v214.m_nCount -= v169;
              v170 = &v214.m_pLists[v168];
              v270.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
              OSuite::ZString::ZString(&v270.m_First, &v233);
              OSuite::ZString::ZString(&v270.m_Second, &v287);
              v270.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
              v171 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
              v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v171;
              if ( v171 )
                OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
                  v171,
                  &v270);
              else
                v172 = 0i64;
              OSuite::ZRedBlackTreeBase::InsertElementSet(v170, v172);
              v270.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
              OSuite::ZString::~ZString(&v270.m_Second);
              OSuite::ZString::~ZString(&v270.m_First);
              v173 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v168]);
              v214.m_nCount += v173;
              OSuite::ZString::~ZString(&v233);
              OSuite::ZString::~ZString(&v287);
              OSuite::ZString::ZString(&v289, *(const char **)(v6 + 80));
              OSuite::ZString::ZString(&v255, "s_CarUsed");
              v174 = v255.OSuite::IHashable::vfptr->ComputeHash(&v255.OSuite::IHashable);
              v175 = (int)((v214.m_nHashSize - 1) & v174);
              v176 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v175]);
              v214.m_nCount -= v176;
              v177 = &v214.m_pLists[v175];
              v272.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
              OSuite::ZString::ZString(&v272.m_First, &v255);
              OSuite::ZString::ZString(&v272.m_Second, &v289);
              v272.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
              v178 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
              v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v178;
              if ( v178 )
                OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
                  v178,
                  &v272);
              else
                v179 = 0i64;
              OSuite::ZRedBlackTreeBase::InsertElementSet(v177, v179);
              v272.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
              OSuite::ZString::~ZString(&v272.m_Second);
              OSuite::ZString::~ZString(&v272.m_First);
              v180 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v175]);
              v214.m_nCount += v180;
              OSuite::ZString::~ZString(&v255);
              OSuite::ZString::~ZString(&v289);
              v181 = "UpdateRaceResult";
LABEL_149:
              OSuite::ZOQuery::ServiceOperation(&v302, v181, &v214);
              v225.m_Closure.m_pthis = 0i64;
              v225.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteLeaderboardManager::CommandCB;
              v225.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(param);
              OSuite::ZWebServiceClient::ExecuteQuery(*((OSuite::ZWebServiceClient **)param + 9), &v302, &v225);
            }
            v214.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
            if ( v214.m_pLists )
            {
              if ( LODWORD(v214.m_pLists[-1].m_Comparer.vfptr) )
                v214.m_pLists->vfptr->__vecDelDtor(v214.m_pLists, 3u);
              else
                operator delete[](&v214.m_pLists[-1].m_Comparer.OSuite::ZObject);
            }
            p_query = &v302;
            break;
          }
          OSuite::ZString::ZString(&v276, "gt");
          OSuite::ZString::ZString(&v257, "s_Operation");
          v201 = v257.OSuite::IHashable::vfptr->ComputeHash(&v257.OSuite::IHashable);
          v202 = (int)((v214.m_nHashSize - 1) & v201);
          v203 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v202]);
          v214.m_nCount -= v203;
          v204 = &v214.m_pLists[v202];
          v259.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::ZString(&v259.m_First, &v257);
          OSuite::ZString::ZString(&v259.m_Second, &v276);
          v259.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
          v205 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
          v311 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)v205;
          if ( v205 )
            OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
              v205,
              &v259);
          else
            v206 = 0i64;
          OSuite::ZRedBlackTreeBase::InsertElementSet(v204, v206);
          v259.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&v259.m_Second);
          OSuite::ZString::~ZString(&v259.m_First);
          v207 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v202]);
          v214.m_nCount += v207;
          OSuite::ZString::~ZString(&v257);
          OSuite::ZString::~ZString(&v276);
          OSuite::ZString::ZString(&v251, "i32_Score");
          OSuite::ZString::ZString(&v292, *(_DWORD *)(v6 + 32));
          v209 = v208;
          v210 = v251.OSuite::IHashable::vfptr->ComputeHash(&v251.OSuite::IHashable);
          v211 = (int)(v210 & (v214.m_nHashSize - 1));
          v212 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v211]);
          v214.m_nCount -= v212;
          OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
            &v214.m_pLists[v211],
            &v251,
            v209);
          v213 = OSuite::ZHttpStreamReader::Tell(&v214.m_pLists[v211]);
          v214.m_nCount += v213;
          OSuite::ZString::~ZString(&v292);
          OSuite::ZString::~ZString(&v251);
          v181 = "UpdateStatAwardResult";
          goto LABEL_149;
      }
      OSuite::ZOQuery::~ZOQuery(p_query);
      v2 = param + 72;
LABEL_156:
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)(param + 104));
      UFG::qEvent::Wait((UFG::qEvent *)(param + 152));
      UFG::qString::~qString(&v224);
    }
    while ( !param[101] );
  }
}[v202]);
          v214.m_nCount += v207;
          OSuite::ZString::~ZString(&v257);
          OSuite::ZString::~ZString(&v276);
          OSuite::ZString::ZString(&v251, "i32_Score");
          OSuite::ZString::ZString(&v292, *(_DWORD *)(v6 + 32));
          v20

// File Line: 1231
// RVA: 0x42CAA0
char __fastcall UFG::OSuiteLeaderboardManager::GetResultFriends(
        UFG::OSuiteLeaderboardManager *this,
        UFG::allocator::free_link *pLBD,
        OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *callback)
{
  bool m_bConnected; // bl
  UFG::GameStatTracker *v7; // rax
  UFG::LeaderboardCategory mNext; // ecx
  __int32 v9; // ecx
  __int32 v10; // ecx
  const char *v11; // rbx
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rdx
  UFG::allocator::free_link *v14; // rax

  m_bConnected = UFG::OSuiteManager::Instance()->m_bConnected;
  v7 = UFG::GameStatTracker::Instance();
  if ( (int)UFG::GameStatTracker::GetStat(v7, IsBannedByCommunityManager) > 0 || !m_bConnected )
    return 0;
  mNext = (UFG::LeaderboardCategory)pLBD[12].mNext;
  if ( mNext == LeaderboardCategory_StatAward )
  {
    v11 = "GetStatAwardResults";
    goto LABEL_11;
  }
  v9 = mNext - 1;
  if ( !v9 )
  {
    v11 = "GetStatGameResults";
    goto LABEL_11;
  }
  v10 = v9 - 1;
  if ( !v10 )
  {
    v11 = "GetMissionResults";
    goto LABEL_11;
  }
  if ( v10 != 1 )
    return 0;
  v11 = "GetRaceResults";
LABEL_11:
  v12 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
  v13 = v12;
  if ( v12 )
  {
    v14 = v12 + 1;
    v14->mNext = v14;
    v14[1].mNext = v14;
    v13->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable;
    v13->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateFriendsResultsEvent::`vftable;
    v13[4].mNext = pLBD;
    v13[5].mNext = (UFG::allocator::free_link *)v11;
    v13[6].mNext = 0i64;
    v13[7].mNext = 0i64;
    v13[7].mNext = (UFG::allocator::free_link *)callback->m_Closure.m_pFunction;
    v13[6].mNext = (UFG::allocator::free_link *)callback->m_Closure.m_pthis;
    LODWORD(v13[3].mNext) = 7;
  }
  else
  {
    v13 = 0i64;
  }
  UFG::OSuiteLeaderboardManager::QueueUpdateEvent(this, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v13);
  return 1;
}

// File Line: 1263
// RVA: 0x42CBC0
char __fastcall UFG::OSuiteLeaderboardManager::GetResultGlobal(
        UFG::OSuiteLeaderboardManager *this,
        UFG::allocator::free_link *pLBD,
        OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *callback)
{
  bool m_bConnected; // bl
  UFG::GameStatTracker *v7; // rax
  UFG::LeaderboardCategory mNext; // ecx
  __int32 v9; // ecx
  __int32 v10; // ecx
  const char *v11; // rbx
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rdx
  UFG::allocator::free_link *v14; // rax

  m_bConnected = UFG::OSuiteManager::Instance()->m_bConnected;
  v7 = UFG::GameStatTracker::Instance();
  if ( (int)UFG::GameStatTracker::GetStat(v7, IsBannedByCommunityManager) > 0 || !m_bConnected )
    return 0;
  mNext = (UFG::LeaderboardCategory)pLBD[12].mNext;
  if ( mNext == LeaderboardCategory_StatAward )
  {
    v11 = "GetGlobalStatAwardResults";
    goto LABEL_11;
  }
  v9 = mNext - 1;
  if ( !v9 )
  {
    v11 = "GetGlobalStatGameResults";
    goto LABEL_11;
  }
  v10 = v9 - 1;
  if ( !v10 )
  {
    v11 = "GetGlobalMissionResults";
    goto LABEL_11;
  }
  if ( v10 != 1 )
    return 0;
  v11 = "GetGlobalRaceResults";
LABEL_11:
  v12 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
  v13 = v12;
  if ( v12 )
  {
    v14 = v12 + 1;
    v14->mNext = v14;
    v14[1].mNext = v14;
    v13->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable;
    v13->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateGlobalResultsEvent::`vftable;
    v13[4].mNext = pLBD;
    v13[5].mNext = (UFG::allocator::free_link *)v11;
    v13[6].mNext = 0i64;
    v13[7].mNext = 0i64;
    v13[7].mNext = (UFG::allocator::free_link *)callback->m_Closure.m_pFunction;
    v13[6].mNext = (UFG::allocator::free_link *)callback->m_Closure.m_pthis;
    LODWORD(v13[3].mNext) = 8;
  }
  else
  {
    v13 = 0i64;
  }
  UFG::OSuiteLeaderboardManager::QueueUpdateEvent(this, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v13);
  return 1;
}

// File Line: 1295
// RVA: 0x42CE40
char __fastcall UFG::OSuiteLeaderboardManager::GetTopFriendsStatScores(
        UFG::OSuiteLeaderboardManager *this,
        OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *callback)
{
  bool m_bConnected; // bl
  UFG::GameStatTracker *v5; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rdx
  UFG::allocator::free_link *v8; // rax

  m_bConnected = UFG::OSuiteManager::Instance()->m_bConnected;
  v5 = UFG::GameStatTracker::Instance();
  if ( (int)UFG::GameStatTracker::GetStat(v5, IsBannedByCommunityManager) > 0 || !m_bConnected )
    return 0;
  v6 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v7 = v6;
  if ( v6 )
  {
    v8 = v6 + 1;
    v8->mNext = v8;
    v8[1].mNext = v8;
    v7->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable;
    v7->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateTopFriendsScoresEvent::`vftable;
    v7[4].mNext = 0i64;
    v7[5].mNext = 0i64;
    v7[5].mNext = (UFG::allocator::free_link *)callback->m_Closure.m_pFunction;
    v7[4].mNext = (UFG::allocator::free_link *)callback->m_Closure.m_pthis;
    LODWORD(v7[3].mNext) = 9;
  }
  else
  {
    v7 = 0i64;
  }
  UFG::OSuiteLeaderboardManager::QueueUpdateEvent(this, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v7);
  return 1;
}

// File Line: 1305
// RVA: 0x42C9C0
char __fastcall UFG::OSuiteLeaderboardManager::GetPlayerStats(
        UFG::OSuiteLeaderboardManager *this,
        OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *callback)
{
  bool m_bConnected; // bl
  UFG::GameStatTracker *v5; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rdx
  UFG::allocator::free_link *v8; // rax

  m_bConnected = UFG::OSuiteManager::Instance()->m_bConnected;
  v5 = UFG::GameStatTracker::Instance();
  if ( (int)UFG::GameStatTracker::GetStat(v5, IsBannedByCommunityManager) > 0 || !m_bConnected )
    return 0;
  v6 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v7 = v6;
  if ( v6 )
  {
    v8 = v6 + 1;
    v8->mNext = v8;
    v8[1].mNext = v8;
    v7->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable;
    v7->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateGetPlayerStatsEvent::`vftable;
    v7[4].mNext = 0i64;
    v7[5].mNext = 0i64;
    v7[5].mNext = (UFG::allocator::free_link *)callback->m_Closure.m_pFunction;
    v7[4].mNext = (UFG::allocator::free_link *)callback->m_Closure.m_pthis;
    LODWORD(v7[3].mNext) = 10;
  }
  else
  {
    v7 = 0i64;
  }
  UFG::OSuiteLeaderboardManager::QueueUpdateEvent(this, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v7);
  return 1;
}

// File Line: 1315
// RVA: 0x42C630
char __fastcall UFG::OSuiteLeaderboardManager::GetChallengeFriends(
        UFG::OSuiteLeaderboardManager *this,
        UFG::allocator::free_link *pLBD,
        int score,
        OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> *callback)
{
  bool m_bConnected; // bl
  UFG::GameStatTracker *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdx
  UFG::allocator::free_link *v12; // rax

  m_bConnected = UFG::OSuiteManager::Instance()->m_bConnected;
  v9 = UFG::GameStatTracker::Instance();
  if ( (int)UFG::GameStatTracker::GetStat(v9, IsBannedByCommunityManager) > 0 || !m_bConnected )
    return 0;
  v10 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
  v11 = v10;
  if ( v10 )
  {
    v12 = v10 + 1;
    v12->mNext = v12;
    v12[1].mNext = v12;
    v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable;
    v11->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateGetChallengeFriendsEvent::`vftable;
    v11[4].mNext = pLBD;
    LODWORD(v11[5].mNext) = score;
    v11[6].mNext = 0i64;
    v11[7].mNext = 0i64;
    v11[7].mNext = (UFG::allocator::free_link *)callback->m_Closure.m_pFunction;
    v11[6].mNext = (UFG::allocator::free_link *)callback->m_Closure.m_pthis;
    LODWORD(v11[3].mNext) = 11;
  }
  else
  {
    v11 = 0i64;
  }
  UFG::OSuiteLeaderboardManager::QueueUpdateEvent(this, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v11);
  return 1;
}

// File Line: 1341
// RVA: 0x42FA50
void __fastcall UFG::OSuiteLeaderboardManager::ScanOrResetPlayerStats(UFG::MessageBuffer *msgBuffer)
{
  unsigned int v2; // r14d
  UFG::GameStatTracker *v3; // r12
  __int64 v4; // rax
  const char **v5; // r15
  int Stat; // ebx
  UFG::qSymbol *Symbol; // rdi
  int v8; // eax
  UFG::PersistentData::MapInt *MapInt; // rsi
  int v10; // r8d
  float v11; // xmm0_4
  float TotalTime; // xmm6_4
  UFG::qSymbol *v13; // rbx
  int v14; // eax
  UFG::PersistentData::MapFloat *MapFloat; // rdi
  float v16; // xmm2_4
  UFG::PersistentData::Time *TimeStat; // rax
  UFG::PersistentData::MapBool *MapBool; // rax
  int TrueCount; // ebx
  UFG::qSymbol *v20; // rsi
  UFG::PersistentData::MapInt *v21; // rdi
  UFG::PersistentData::MapInt *v22; // rdi
  int v23; // eax
  int Total; // eax
  UFG::qSymbol *v25; // rax
  int v26; // edx
  int v27; // edx
  bool v28; // zf
  UFG::PersistentData::MapFloat *v29; // rax
  UFG::qSymbol *v30; // rax
  UFG::PersistentData::MapFloat *v31; // rax
  __int64 v32; // r14
  __int64 v33; // rdi
  UFG::AIAwareness::Effector::ScoreIndex *v34; // rdi
  __int64 v35; // rax
  int v36; // edx
  __int64 v37; // rax
  __int64 v38; // r8
  UFG::AIAwareness::Effector::ScoreIndex v39; // rcx
  UFG::AIAwareness::Effector::ScoreIndex v40; // rcx
  UFG::AIAwareness::Effector::ScoreIndex v41; // rax
  UFG::AIAwareness::Effector::ScoreIndex v42; // rax
  UFG::AIAwareness::Effector::ScoreIndex *v43; // rbx
  unsigned __int64 v44; // rdx
  float v45; // xmm0_4
  UFG::AIAwareness::Effector::ScoreIndex v46; // rcx
  UFG::qPropertySet *v47; // rax
  __int64 v48; // rdi
  unsigned int mIndex; // ebx
  UFG::PersistentData::MapInt *v50; // rsi
  int v51; // eax
  __int64 v52; // rbx
  UFG::PersistentData::MapFloat *v53; // rsi
  int v54; // ebx
  int v55; // edi
  unsigned int mUID; // ecx
  UFG::ProgressionTracker *v57; // r14
  UFG::qSymbol *v58; // rax
  UFG::qBaseTreeRB *v59; // rax
  unsigned __int8 v60; // al
  UFG::PersistentData::MapInt *v61; // r14
  int Status; // esi
  int v63; // eax
  __int64 v64; // rbx
  int v65; // ebx
  int v66; // eax
  __int64 v67; // rbx
  __int64 v68; // [rsp+20h] [rbp-E0h]
  UFG::qSymbol *min; // [rsp+30h] [rbp-D0h] BYREF
  UFG::PersistentData::MapFloat::Iterator result; // [rsp+38h] [rbp-C8h] BYREF
  UFG::PersistentData::MapFloat::Iterator v71; // [rsp+48h] [rbp-B8h] BYREF
  __int64 v72; // [rsp+58h] [rbp-A8h]
  UFG::PersistentData::MapFloat::Iterator v73; // [rsp+60h] [rbp-A0h] BYREF
  __int128 v74; // [rsp+70h] [rbp-90h] BYREF
  UFG::qSymbol v75; // [rsp+80h] [rbp-80h] BYREF
  char dest[120]; // [rsp+90h] [rbp-70h] BYREF
  UFG::AIAwareness::Effector::ScoreIndex right; // [rsp+108h] [rbp+8h] BYREF
  UFG::AIAwareness::Effector::ScoreIndex left[64]; // [rsp+110h] [rbp+10h] BYREF
  char text[128]; // [rsp+310h] [rbp+210h] BYREF
  UFG::qSymbol *max; // [rsp+3F8h] [rbp+2F8h] BYREF
  UFG::qSymbol v81; // [rsp+400h] [rbp+300h] BYREF
  UFG::qSymbol name; // [rsp+408h] [rbp+308h] BYREF

  v2 = 0;
  v3 = UFG::GameStatTracker::Instance();
  v4 = 0i64;
  v72 = 0i64;
  LODWORD(max) = 0;
  while ( 2 )
  {
    v5 = (const char **)(0x140000000i64 + 24 * v4 + 34074944);
    switch ( *(_DWORD *)(0x140000010i64 + 24 * v4 + 34074944) )
    {
      case 0:
        Stat = UFG::GameStatTracker::GetStat(
                 v3,
                 (UFG::GameStat::Int32Stat)*(_DWORD *)(0x140000008i64 + 24 * v4 + 34074944));
        Symbol = UFG::GameStat::GetSymbol((UFG::GameStat::Int32Stat)*((_DWORD *)v5 + 2));
        v8 = *((_DWORD *)v5 + 3);
        if ( v8 )
        {
          if ( v8 == 2 )
            goto LABEL_5;
        }
        else
        {
          MapInt = UFG::GameStatTracker::GetMapInt(v3, PlayersStatsIntListSum);
          v10 = Stat - UFG::PersistentData::MapInt::GetStatus(MapInt, Symbol);
          if ( v10 > 0 )
          {
            if ( msgBuffer )
              goto LABEL_41;
            goto LABEL_10;
          }
        }
        goto LABEL_110;
      case 1:
        v11 = UFG::GameStatTracker::GetStat(v3, *(UFG::GameStat::FloatStat *)(0x140000008i64 + 24 * v4 + 34074944));
        TotalTime = v11;
        v13 = UFG::GameStat::GetSymbol((UFG::GameStat::FloatStat)*((_DWORD *)v5 + 2));
        v14 = *((_DWORD *)v5 + 3);
        if ( !v14 )
          goto LABEL_20;
        if ( v14 == 2 )
        {
          MapFloat = UFG::GameStatTracker::GetMapFloat(v3, PlayersStatsFloatListMax);
          if ( v11 > UFG::PersistentData::MapFloat::GetStatus(MapFloat, v13) )
          {
            v16 = TotalTime;
            if ( !msgBuffer )
              goto LABEL_18;
            goto LABEL_16;
          }
        }
        goto LABEL_110;
      case 2:
        TimeStat = UFG::GameStatTracker::GetTimeStat(
                     v3,
                     (UFG::GameStat::TimeStat)*(_DWORD *)(0x140000008i64 + 24 * v4 + 34074944));
        TotalTime = UFG::PersistentData::Time::GetTotalTime(TimeStat);
        v13 = UFG::GameStat::GetSymbol((UFG::GameStat::TimeStat)*((_DWORD *)v5 + 2));
        if ( !*((_DWORD *)v5 + 3) )
        {
LABEL_20:
          MapFloat = UFG::GameStatTracker::GetMapFloat(v3, PlayersStatsFloatListSum);
          v16 = TotalTime - UFG::PersistentData::MapFloat::GetStatus(MapFloat, v13);
          if ( v16 > 0.0 )
          {
            if ( msgBuffer )
            {
LABEL_16:
              UFG::MessageBuffer::AppendValue(msgBuffer, (UFG::PlayerStatSubmissionLookup *)v5, v16);
            }
            else
            {
              v16 = TotalTime;
LABEL_18:
              UFG::PersistentData::MapFloat::SetStatus(MapFloat, v13, v16);
            }
          }
        }
        goto LABEL_110;
      case 3:
        MapBool = UFG::GameStatTracker::GetMapBool(
                    v3,
                    (UFG::GameStat::MapBoolStat)*(_DWORD *)(0x140000008i64 + 24 * v4 + 34074944));
        TrueCount = UFG::PersistentData::MapBool::GetTrueCount(MapBool);
        v20 = UFG::GameStat::GetSymbol((UFG::GameStat::MapBoolStat)*((_DWORD *)v5 + 2));
        if ( *((_DWORD *)v5 + 3) == 2 )
        {
          v21 = UFG::GameStatTracker::GetMapInt(v3, PlayersStatsIntListMax);
          if ( TrueCount > UFG::PersistentData::MapInt::GetStatus(v21, v20) )
          {
            v10 = TrueCount;
            if ( msgBuffer )
              goto LABEL_41;
            UFG::PersistentData::MapInt::SetStatus(v21, v20, TrueCount);
          }
        }
        goto LABEL_110;
      case 4:
      case 5:
        Stat = 0;
        v22 = UFG::GameStatTracker::GetMapInt(
                v3,
                (UFG::GameStat::MapInt32Stat)*(_DWORD *)(0x140000008i64 + 24 * v4 + 34074944));
        v23 = *((_DWORD *)v5 + 4);
        if ( v23 == 4 )
        {
          Total = UFG::PersistentData::MapInt::GetTotal(v22);
LABEL_32:
          Stat = Total;
          goto LABEL_33;
        }
        if ( v23 == 5 )
        {
          min = 0i64;
          max = 0i64;
          UFG::PersistentData::MapInt::GetMaxMin(v22, &max, &min);
          if ( max )
          {
            Total = UFG::PersistentData::MapInt::GetStatus(v22, max);
            goto LABEL_32;
          }
        }
LABEL_33:
        v25 = UFG::GameStat::GetSymbol((UFG::GameStat::MapInt32Stat)*((_DWORD *)v5 + 2));
        v26 = *((_DWORD *)v5 + 3);
        Symbol = v25;
        if ( v26 )
        {
          v27 = v26 - 2;
          if ( v27 )
          {
            v28 = v27 == 1;
            goto LABEL_36;
          }
LABEL_5:
          MapInt = UFG::GameStatTracker::GetMapInt(v3, PlayersStatsIntListMax);
          if ( Stat > UFG::PersistentData::MapInt::GetStatus(MapInt, Symbol) )
            goto LABEL_6;
        }
        else
        {
          MapInt = UFG::GameStatTracker::GetMapInt(v3, PlayersStatsIntListSum);
          v10 = Stat - UFG::PersistentData::MapInt::GetStatus(MapInt, Symbol);
          if ( v10 > 0 )
          {
            if ( !msgBuffer )
            {
LABEL_10:
              v10 = Stat;
              goto LABEL_11;
            }
            goto LABEL_41;
          }
        }
LABEL_110:
        ++v2;
        v4 = v72 + 1;
        LODWORD(max) = v2;
        ++v72;
        if ( v2 < 0x82 )
          continue;
        return;
      case 6:
        v29 = UFG::GameStatTracker::GetMapFloat(
                v3,
                (UFG::GameStat::MapFloatStat)*(_DWORD *)(0x140000008i64 + 24 * v4 + 34074944));
        v74 = 0ui64;
        UFG::PersistentData::MapFloat::GetMaxMin(v29, (UFG::qSymbol **)&v74, (UFG::qSymbol **)&v74 + 1);
        if ( (_QWORD)v74 )
        {
          Stat = *(_DWORD *)v74;
          v30 = UFG::GameStat::GetSymbol((UFG::GameStat::MapInt32Stat)*((_DWORD *)v5 + 2));
          v28 = *((_DWORD *)v5 + 3) == 3;
          Symbol = v30;
LABEL_36:
          if ( v28 )
          {
            MapInt = UFG::GameStatTracker::GetMapInt(v3, PlayersStatsIntList);
            if ( Stat != UFG::PersistentData::MapInt::GetStatus(MapInt, Symbol) )
            {
LABEL_6:
              v10 = Stat;
              if ( msgBuffer )
LABEL_41:
                UFG::MessageBuffer::AppendValue(msgBuffer, (UFG::PlayerStatSubmissionLookup *)v5, v10);
              else
LABEL_11:
                UFG::PersistentData::MapInt::SetStatus(MapInt, Symbol, v10);
            }
          }
        }
        goto LABEL_110;
      case 7:
        v31 = UFG::GameStatTracker::GetMapFloat(
                v3,
                (UFG::GameStat::MapFloatStat)*(_DWORD *)(0x140000008i64 + 24 * v4 + 34074944));
        UFG::PersistentData::MapInt::GetIterator(v31, &result);
        v32 = 0i64;
        v33 = 0i64;
        while ( UFG::PersistentData::MapBinary::Iterator::IsValid(&result) )
        {
          if ( (unsigned int)v32 >= 0x40 )
            break;
          if ( (unsigned int)v32 >= *((_DWORD *)v5 + 5) )
            break;
          *(float *)&left[v32].mScore = UFG::PersistentData::MapFloat::Iterator::GetStatus(&result);
          ++v33;
          left[v32].mIndex = UFG::PersistentData::MapFloat::Iterator::GetName(&result)->mUID;
          v32 = (unsigned int)(v32 + 1);
          UFG::PersistentData::MapFloat::Iterator::Next((ARefCountMix<SSInstance> *)&result);
        }
        v34 = &right + v33;
        v35 = v34 - left;
        v36 = v35 + 1;
        if ( (int)v35 + 1 < 32 )
        {
          if ( v36 > 1 )
            UFG::qInsertionSort<UFG::OSuiteLeaderboardData const *,bool (*)(UFG::OSuiteLeaderboardData const * const &,UFG::OSuiteLeaderboardData const * const &)>(
              (UFG::qPropertySet **)left,
              v36,
              (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::SortByMapFloatUtilsLargestToSmallest);
        }
        else
        {
          v37 = v35 / 2;
          v38 = v37;
          if ( *(float *)&left[0].mScore < *(float *)&left[v37].mScore )
          {
            v39 = left[v37];
            left[v37] = left[0];
            left[0] = v39;
          }
          if ( *(float *)&left[v37].mScore < *(float *)&v34->mScore )
          {
            v40 = left[v37];
            v41 = *v34;
            *v34 = v40;
            left[v38] = v41;
          }
          if ( *(float *)&left[0].mScore < *(float *)&left[v38].mScore )
          {
            v42 = left[v38];
            left[v38] = left[0];
            left[0] = v42;
          }
          v43 = left;
          v44 = (unsigned __int64)v34;
          min = (UFG::qSymbol *)left[v38];
          if ( left <= v34 )
          {
            v45 = *((float *)&min + 1);
            do
            {
              for ( ; v45 < *(float *)&v43->mScore; ++v43 )
              {
                if ( v43 >= v34 )
                  break;
              }
              for ( ; v45 > *(float *)(v44 + 4); v44 -= 8i64 )
              {
                if ( (unsigned __int64)left >= v44 )
                  break;
              }
              if ( (unsigned __int64)v43 > v44 )
                break;
              v46 = *(UFG::AIAwareness::Effector::ScoreIndex *)v44;
              v47 = (UFG::qPropertySet *)*v43;
              v44 -= 8i64;
              *v43 = v46;
              *(_QWORD *)(v44 + 8) = v47;
              ++v43;
            }
            while ( (unsigned __int64)v43 <= v44 );
          }
          if ( (unsigned __int64)left < v44 )
            UFG::qQuickSortImpl<UFG::MapFloatSortUtil,bool (*)(UFG::MapFloatSortUtil const &,UFG::MapFloatSortUtil const &)>(
              (UFG::qPropertySet **)left,
              (UFG::AIAwareness::Effector::ScoreIndex *)v44,
              (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::SortByMapFloatUtilsLargestToSmallest);
          if ( v43 < v34 )
            UFG::qQuickSortImpl<UFG::MapFloatSortUtil,bool (*)(UFG::MapFloatSortUtil const &,UFG::MapFloatSortUtil const &)>(
              (UFG::qPropertySet **)v43,
              v34,
              (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::SortByMapFloatUtilsLargestToSmallest);
        }
        if ( *((_DWORD *)v5 + 3) == 3 )
        {
          v48 = 0i64;
          while ( (unsigned int)v48 < *((_DWORD *)v5 + 5) )
          {
            if ( (unsigned int)v48 >= (unsigned int)v32 )
              break;
            mIndex = left[v48].mIndex;
            v48 = (unsigned int)(v48 + 1);
            LODWORD(v68) = v48;
            UFG::qSPrintf(dest, 128, "%s%d", *v5, v68);
            UFG::qSymbol::create_from_string(&name, dest);
            v50 = UFG::GameStatTracker::GetMapInt(v3, PlayersStatsIntList);
            if ( mIndex != UFG::PersistentData::MapInt::GetStatus(v50, &name) )
            {
              if ( msgBuffer )
              {
                UFG::MessageBuffer::AppendDescriptor(msgBuffer, (UFG::PlayerStatSubmissionLookup *)v5, dest);
                v51 = UFG::qSPrintf(text, "%d", mIndex);
                v52 = v51;
                UFG::qStringCopy(
                  msgBuffer->mCurrentOffset,
                  LODWORD(msgBuffer->mBuffer) + msgBuffer->mBufferSize - LODWORD(msgBuffer->mCurrentOffset),
                  text,
                  v51);
                msgBuffer->mCurrentOffset += v52;
                *msgBuffer->mCurrentOffset = 0;
              }
              else
              {
                UFG::PersistentData::MapInt::SetStatus(v50, &name, mIndex);
              }
            }
          }
        }
        goto LABEL_109;
      case 8:
      case 9:
        v53 = (UFG::PersistentData::MapFloat *)UFG::GameStatTracker::GetMapBool(
                                                 v3,
                                                 (UFG::GameStat::MapBoolStat)*(_DWORD *)(0x140000008i64
                                                                                       + 24 * v4
                                                                                       + 34074944));
        UFG::GameStat::GetSymbol(*((UFG::GameStat::MapBoolStat *)v5 + 2));
        v54 = 0;
        v55 = 0;
        if ( *((_DWORD *)v5 + 4) == 9 )
        {
          UFG::PersistentData::MapInt::GetIterator(v53, &v71);
          while ( UFG::PersistentData::MapBool::Iterator::IsValid((UFG::PersistentData::MapBool::Iterator *)&v71) )
          {
            if ( UFG::PersistentData::MapBool::Iterator::GetStatus((UFG::PersistentData::MapBool::Iterator *)&v71) )
            {
              mUID = UFG::PersistentData::MapBool::Iterator::GetName((UFG::PersistentData::MapBool::Iterator *)&v71)->mUID;
              if ( mUID )
              {
                if ( mUID > 0x20 )
                {
                  if ( mUID <= 0x40 )
                    v55 |= 1 << (mUID - 33);
                }
                else
                {
                  v54 |= 1 << (mUID - 1);
                }
              }
            }
            UFG::PersistentData::MapFloat::Iterator::Next((ARefCountMix<SSInstance> *)&v71);
          }
        }
        else
        {
          v57 = UFG::ProgressionTracker::Instance();
          UFG::PersistentData::MapInt::GetIterator(v53, &v73);
          while ( UFG::PersistentData::MapBool::Iterator::IsValid((UFG::PersistentData::MapBool::Iterator *)&v73) )
          {
            if ( UFG::PersistentData::MapBool::Iterator::GetStatus((UFG::PersistentData::MapBool::Iterator *)&v73) )
            {
              v58 = UFG::PersistentData::MapBool::Iterator::GetName((UFG::PersistentData::MapBool::Iterator *)&v73);
              v59 = UFG::ProgressionTracker::Find(v57, v58, 0);
              if ( v59 )
              {
                v60 = BYTE4(v59[4].mNULL.mChild[1]);
                if ( v60 )
                {
                  if ( v60 > 0x20u )
                  {
                    if ( v60 <= 0x40u )
                      v55 |= 1 << (v60 - 33);
                  }
                  else
                  {
                    v54 |= 1 << (v60 - 1);
                  }
                }
              }
            }
            UFG::PersistentData::MapFloat::Iterator::Next((ARefCountMix<SSInstance> *)&v73);
          }
          v2 = (unsigned int)max;
        }
        if ( *((_DWORD *)v5 + 3) == 3 )
        {
          v61 = UFG::GameStatTracker::GetMapInt(v3, PlayersStatsIntList);
          UFG::qSPrintf(dest, 128, "%s0", *v5);
          UFG::qSymbol::create_from_string(&v81, dest);
          Status = UFG::PersistentData::MapInt::GetStatus(v61, &v81);
          if ( Status != v54 )
          {
            if ( msgBuffer )
            {
              UFG::MessageBuffer::AppendDescriptor(msgBuffer, (UFG::PlayerStatSubmissionLookup *)v5, dest);
              v63 = UFG::qSPrintf(text, "%d", v54 | (unsigned int)Status);
              v64 = v63;
              UFG::qStringCopy(
                msgBuffer->mCurrentOffset,
                LODWORD(msgBuffer->mBuffer) + msgBuffer->mBufferSize - LODWORD(msgBuffer->mCurrentOffset),
                text,
                v63);
              msgBuffer->mCurrentOffset += v64;
              *msgBuffer->mCurrentOffset = 0;
            }
            else
            {
              UFG::PersistentData::MapInt::SetStatus(v61, &v81, v54 | Status);
            }
          }
          UFG::qSPrintf(dest, 128, "%s1", *v5);
          v81.mUID = UFG::qSymbol::create_from_string(&v75, dest)->mUID;
          v65 = UFG::PersistentData::MapInt::GetStatus(v61, &v81);
          if ( v65 != v55 )
          {
            if ( msgBuffer )
            {
              UFG::MessageBuffer::AppendDescriptor(msgBuffer, (UFG::PlayerStatSubmissionLookup *)v5, dest);
              v66 = UFG::qSPrintf(text, "%d", v55 | (unsigned int)v65);
              v67 = v66;
              UFG::qStringCopy(
                msgBuffer->mCurrentOffset,
                LODWORD(msgBuffer->mBuffer) + msgBuffer->mBufferSize - LODWORD(msgBuffer->mCurrentOffset),
                text,
                v66);
              msgBuffer->mCurrentOffset += v67;
              *msgBuffer->mCurrentOffset = 0;
            }
            else
            {
              UFG::PersistentData::MapInt::SetStatus(v61, &v81, v55 | v65);
            }
          }
LABEL_109:
          v2 = (unsigned int)max;
        }
        goto LABEL_110;
      default:
        goto LABEL_110;
    }
  }
}

// File Line: 1851
// RVA: 0x435340
char __fastcall UFG::OSuiteLeaderboardManager::UploadPlayerStats(UFG::OSuiteLeaderboardManager *this)
{
  bool m_bConnected; // bl
  UFG::GameStatTracker *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::MessageBuffer *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rdx
  UFG::allocator::free_link *v9; // rax

  m_bConnected = UFG::OSuiteManager::Instance()->m_bConnected;
  v3 = UFG::GameStatTracker::Instance();
  if ( (int)UFG::GameStatTracker::GetStat(v3, IsBannedByCommunityManager) > 0 || !m_bConnected )
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
      v8->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable;
      v8->mNext = (UFG::allocator::free_link *)&UFG::OSuiteLeaderboardManager::UpdatePlayerStatsEvent::`vftable;
      v8[4].mNext = (UFG::allocator::free_link *)v5;
      LODWORD(v8[3].mNext) = 4;
    }
    else
    {
      v8 = 0i64;
    }
    UFG::OSuiteLeaderboardManager::QueueUpdateEvent(this, (UFG::OSuiteLeaderboardManager::UpdateEvent *)v8);
  }
  return 1;
}

// File Line: 1875
// RVA: 0x42F920
void __fastcall UFG::OSuiteLeaderboardManager::ResetStatSumsOnLoad(UFG::OSuiteLeaderboardManager *this)
{
  unsigned int *p_mGameStatId; // rsi
  __int64 v2; // r14
  UFG::GameStatTracker *v3; // rbp
  unsigned int v4; // edx
  unsigned int v5; // edx
  unsigned int v6; // edx
  UFG::PersistentData::MapInt *MapInt; // rax
  int Total; // edi
  UFG::qSymbol *Symbol; // rax
  UFG::PersistentData::Time *TimeStat; // rax
  float TotalTime; // xmm6_4
  UFG::qSymbol *v12; // rax
  UFG::qSymbol *v13; // rbx
  UFG::PersistentData::MapFloat *MapFloat; // rax
  UFG::qSymbol *v15; // rbx
  UFG::PersistentData::MapInt *v16; // rax

  p_mGameStatId = &UFG::sPlayerStatSubmissions[0].mGameStatId;
  v2 = 130i64;
  v3 = UFG::GameStatTracker::Instance();
  do
  {
    if ( p_mGameStatId[1] )
      goto LABEL_13;
    v4 = p_mGameStatId[2];
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
          MapInt = UFG::GameStatTracker::GetMapInt(v3, (UFG::GameStat::MapInt32Stat)*p_mGameStatId);
          Total = UFG::PersistentData::MapInt::GetTotal(MapInt);
          Symbol = UFG::GameStat::GetSymbol((UFG::GameStat::MapInt32Stat)*p_mGameStatId);
          goto LABEL_12;
        }
        TimeStat = UFG::GameStatTracker::GetTimeStat(v3, (UFG::GameStat::TimeStat)*p_mGameStatId);
        TotalTime = UFG::PersistentData::Time::GetTotalTime(TimeStat);
        v12 = UFG::GameStat::GetSymbol((UFG::GameStat::TimeStat)*p_mGameStatId);
      }
      else
      {
        TotalTime = UFG::GameStatTracker::GetStat(v3, (UFG::GameStat::FloatStat)*p_mGameStatId);
        v12 = UFG::GameStat::GetSymbol((UFG::GameStat::FloatStat)*p_mGameStatId);
      }
      v13 = v12;
      MapFloat = UFG::GameStatTracker::GetMapFloat(v3, PlayersStatsFloatListSum);
      UFG::PersistentData::MapFloat::SetStatus(MapFloat, v13, TotalTime);
      goto LABEL_13;
    }
    Total = UFG::GameStatTracker::GetStat(v3, (UFG::GameStat::Int32Stat)*p_mGameStatId);
    Symbol = UFG::GameStat::GetSymbol((UFG::GameStat::Int32Stat)*p_mGameStatId);
LABEL_12:
    v15 = Symbol;
    v16 = UFG::GameStatTracker::GetMapInt(v3, PlayersStatsIntListSum);
    UFG::PersistentData::MapInt::SetStatus(v16, v15, Total);
LABEL_13:
    p_mGameStatId += 6;
    --v2;
  }
  while ( v2 );
}

// File Line: 1969
// RVA: 0x429530
void __fastcall UFG::OSuiteLeaderboardManager::UpdatePlayerStatsEvent::~UpdatePlayerStatsEvent(
        UFG::OSuiteLeaderboardManager::UpdatePlayerStatsEvent *this)
{
  UFG::MessageBuffer *mMessage; // rdi
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *mPrev; // rcx
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *mNext; // rax

  this->vfptr = (UFG::OSuiteLeaderboardManager::UpdateEventVtbl *)&UFG::OSuiteLeaderboardManager::UpdatePlayerStatsEvent::`vftable;
  mMessage = this->mMessage;
  if ( mMessage )
  {
    if ( mMessage->mBuffer )
    {
      operator delete[](mMessage->mBuffer);
      mMessage->mBuffer = 0i64;
    }
    operator delete[](mMessage);
    this->mMessage = 0i64;
  }
  this->vfptr = (UFG::OSuiteLeaderboardManager::UpdateEventVtbl *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent>;
  this->mNext = &this->UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent>;
}

