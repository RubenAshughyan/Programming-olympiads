#include<bits/stdc++.h>

//#include "rubo.h"
#define MP make_pair
#define PB push_back
#define in int
#define ll long long
#define ull unsigned long long
#define vc vector
#define SQ(j) (j)*(j)
//#define i first
//#define j second

//#define ld long double
#define dbl  double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define all(j) j.begin(), j.end()
#define loop(xxx, yyy) for(int xxx = 0; xxx < yyy; xxx++)
//#define printf(fmt, ...) (0)
//#define HOME
//#define y0 ngacaleiebinvoaeu
//#define y1 gnarpipipaigare
#define j1 adsfndnasfafoasp

//#define printf(...) (0)
#define db(x) cout << #x << " = " << x << endl
#define dbCont(x) cout << #x << ": "; for(auto shun: x) cout << shun << ' '; cout<<endl;

using namespace std;

int n, k;
vector<vector<int>> stacks;
vector<pii> ans;
vector<int> top_block_sizes, bottom_block_sizes;

int A = 0;
void move(int from, int to) {
    A++;
    assert(A <= 13*n);

    ans.emplace_back(from, to);
    stacks[to].PB(stacks[from].back());
    stacks[from].pop_back();
}

void operate(int destId) {
    set<pii> tops;
    for(int i = 0; i < k; i++) {
        if (i == destId || stacks[i].empty()) continue;
        tops.emplace(stacks[i].back(), i);
    }

    top_block_sizes.PB(tops.size());
    for(auto& pr : tops) {
        move(pr.second, destId);
    }
}

void freeUp(int freeId) {
    int to = 0;
    while(!stacks[freeId].empty()) {
        to %= k;
        if (to == freeId) { to++; continue; }
        move(freeId, to);
        to++;
    }
}

void fillEmptyStacks(int from) {
    vector<int>& sizes = (from == 0 ? top_block_sizes : bottom_block_sizes);
    for(int i = 1; i < k - 1; i++) {
        if (sizes.empty()) break;
        for(int j = 0; j < sizes.back(); ++j)
            move(from, i);
        sizes.pop_back();
    }
}

void mergeInto(int to) {
    set<pii> tops;
    for(int i = 1; i < k - 1; i++) {
        if (stacks[i].empty()) continue;
        tops.emplace(stacks[i].back(), i);
    }
    int sz = 0;

    while(!tops.empty()) {
        auto it = tops.begin();
        int stId = it->second;
        tops.erase(it);
        move(stId, to);
        sz++;

        if (!stacks[stId].empty())
            tops.emplace(stacks[stId].back(), stId);
    }
    if (to == 0)    top_block_sizes.PB(sz);
    else            bottom_block_sizes.PB(sz);
}


void fromEndToEnd(int from, int to) {
    if (from == 0) {
        while(!top_block_sizes.empty()) {
            fillEmptyStacks(from);
            mergeInto(to);
        }
    }
    else {
        while(!bottom_block_sizes.empty()) {
            fillEmptyStacks(from);
            mergeInto(to);
        }
    }
}

void normalize() {
    int normal = n / k;
    for(int i = 0; i < k; i++) {
        if (stacks[i].size() <= normal) continue;
        for(int j = 0; j < k && stacks[i].size() > normal; j++)
            if (stacks[j].size() < normal) {
                move(i, j);
                j--;
            }
    }
}

int main() {
//    cin >> n >> k;
//    stacks.resize(k);
//    for(int i = 0; i < k; i++) {
//        int cnt;
//        cin >> cnt;
//        stacks[i].resize(cnt);
//        for(int j = cnt - 1; j >= 0; --j)
//            cin >> stacks[i][j];
//    }
    k = 81;
    n = 25 * k;
    stacks.resize(k);
    stacks[0] = vector<int>{1679, 4492, 5910, 3062, 9105, 6798, 5797, 5204, 3906, 1526, 4083, 9389, 4285, 8400, 4123, 9371, 3813, 9625, 3480, 8408, 6148, 7279, 7726, 3178, 1535, 9864, 8976, 6023, 653, 6611, 404, 6048, 9110, 5657, 2247, 1447, 2785, 5161, 9203, 3466, 9835, 8498, 9757, 1391, 8401, 9905, 5782, 4074, 3969, 5655, 2696, 2405, 6768, 9746, 4083, 2662, 3449, 444, 1125, 974, 1674, 1042, 8752, 8809, 1798, 7873, 5542, 3543, 569, 3002, 3325, 2615, 6506, 1300, 1623, 1754, 8726, 3387, 2281, 855, 9171, 1836, 4234, 1230, 6377, 9473, 1651, 2910, 9972, 7493, 9268, 4085, 9277, 9041, 3697, 2745, 5382, 6867, 9771, 7615, 9720, 9088, 6129, 8768, 7874, 552, 8472, 3314, 4992, 4598, 5948, 1727, 772, 5116, 2074, 1500, 2643, 6100, 5717, 5828, 6908, 6866, 1698, 9708, 2700, 4476, 6659, 419, 8566, 3181, 2152, 2931, 3479, 9061, 2679, 7666, 6647, 3757, 7131, 2518, 8559, 3456, 5783, 873, 4473, 6221, 8184, 7491, 5899, 5546, 153, 1774, 504, 8763, 186, 792, 1633, 8355, 8587, 642, 1501, 2299, 2014, 9678, 6124, 7513, 6690, 1295, 743, 666, 7952, 9828, 186, 5888, 5178, 9739, 6446, 3953, 2669, 9711, 2393, 8685, 1599, 2294, 5876, 9926, 4742, 815, 6260, 3824, 7936, 1014, 5692, 2013, 603, 7559, 2366, 3275, 9349, 4800, 606, 501, 810, 5890, 9823, 3618, 2676, 1374, 461, 3320, 884, 1801, 3228, 6922, 8468, 835, 455, 135, 2133, 5212, 2943, 7014, 4993, 3591, 8594, 4376, 8086, 8962, 2727, 5540, 6214, 7886, 5139, 3077, 390, 7156, 5839, 5543, 771, 8217, 1231, 4845, 7871, 9403, 7919, 2472, 950, 8332, 8376, 8479, 6813, 1426, 925, 787, 4964, 5930, 3381, 1093, 7920, 9779, 3846, 243, 6554, 4838, 7105, 9694, 8511, 8754, 4692, 3332, 4317, 1190, 804, 2297, 6460, 1706, 2115, 9135, 5599, 7873, 4399, 960, 7836, 7545, 6905, 7058, 5833, 2923, 6011, 7156, 2375, 1076, 5096, 127, 1442, 3482, 221, 1798, 4079, 4625, 8309, 1871, 2992, 1386, 6667, 3007, 7671, 9657, 646, 11, 3292, 8313, 7832, 5644, 5344, 6391, 8696, 5895, 7553, 8720, 4182, 3132, 7634, 862, 5743, 6317, 5118, 2859, 8452, 7097, 7010, 8398, 5586, 5622, 9307, 5151, 8695, 4178, 2955, 1835, 215, 2930, 1933, 9683, 510, 3520, 9652, 8697, 5082, 572, 9610, 9013, 2385, 6424, 2363, 4341, 3436, 7748, 7699, 5193, 4851, 2981, 739, 538, 2736, 9107, 8347, 6297, 4692, 8156, 8179, 2117, 6301, 4338, 4135, 7952, 3422, 7263, 8213, 5994, 280, 2122, 64, 2453, 2412, 5248, 3335, 220, 8843, 1611, 4509, 4153, 7433, 7737, 3328, 9050, 1546, 3127, 8976, 567, 4288, 258, 7142, 1330, 4234, 7587, 8579, 6715, 5334, 8988, 732, 8981, 5646, 3329, 4030, 3854, 9830, 471, 8038, 8221, 5822, 8157, 3365, 1914, 2921, 5909, 419, 3861, 6800, 2529, 6066, 4104, 3295, 432, 4236, 5279, 9576, 3336, 99, 9448, 499, 1094, 9995, 1658, 5928, 607, 1752, 6427, 3411, 6353, 8501, 4375, 6747, 1862, 7676, 6037, 1218, 5966, 1331, 3530, 9077, 2224, 3887, 6006, 7987, 9486, 1057, 2422, 1223, 4108, 9528, 134, 3670, 9238, 8354, 9317, 7100, 5941, 7544, 7793, 8613, 4838, 8642, 7256, 5041, 6342, 4124, 2331, 8029, 382, 7685, 2650, 1451, 5989, 519, 4879, 9099, 6406, 7189, 371, 9902, 7796, 7660, 4963, 7194, 5036, 5771, 5239, 2258, 7593, 6894, 8834, 2640, 8331, 9014, 7966, 1053, 448, 9986, 2803, 106, 874, 1025, 9069, 6000, 3728, 6063, 9461, 8482, 4631, 3053, 8416, 1832, 7500, 5927, 6242, 4136, 9389, 8812, 852, 509, 6426, 615, 6644, 800, 3665, 610, 4810, 3123, 9511, 1538, 6364, 6915, 2212, 3289, 4585, 3462, 8892, 5963, 8250, 5858, 1112, 2211, 5366, 2337, 7282, 5212, 4826, 8989, 6943, 7880, 9534, 807, 37, 4329, 5059, 1690, 2875, 6476, 8295, 813, 5688, 4828, 2872, 4464, 9171, 4628, 2973, 1952, 3413, 957, 1959, 544, 1380, 9709, 994, 9098, 2239, 5146, 5497, 4630, 7103, 524, 3791, 1978, 2532, 887, 3752, 7429, 3579, 3735, 5506, 4875, 7356, 4131, 3404, 9056, 3290, 7176, 5831, 1110, 3380, 3150, 2928, 9468, 3443, 1656, 1105, 2152, 4817, 8696, 7479, 4251, 5855, 4572, 4259, 1641, 6408, 6895, 9402, 5479, 7419, 5879, 7337, 6757, 9365, 147, 6784, 4763, 337, 7592, 9162, 6461, 5139, 1659, 6093, 3362, 7120, 7676, 7649, 8261, 4565, 5918, 8756, 697, 9937, 8895, 9333, 8928, 2730, 1325, 7403, 48, 1390, 7953, 3043, 2754, 7937, 3444, 564, 9098, 3171, 5487, 5829, 9249, 8290, 65, 8012, 1568, 223, 3783, 3004, 4749, 6364, 6732, 9172, 3145, 3323, 4473, 7980, 4711, 1984, 6966, 5123, 3089, 3971, 8193, 5188, 6776, 6360, 983, 7933, 4056, 2183, 583, 6379, 2447, 1249, 8384, 7792, 6948, 2816, 969, 5388, 1374, 2762, 5374, 2307, 4755, 8656, 4091, 6682, 6033, 1490, 1470, 6507, 4051, 8886, 5005, 2230, 5761, 2713, 8039, 1311, 1723, 4139, 3128, 2901, 5405, 3963, 6336, 6753, 4265, 7038, 4093, 1272, 8554, 5, 3356, 279, 3552, 9085, 9239, 1088, 2675, 3602, 1894, 5237, 9195, 8811, 6096, 2217, 342, 4107, 5871, 638, 7278, 1896, 6398, 5867, 5584, 6826, 1101, 3194, 4029, 3637, 8841, 4732, 5572, 406, 947, 6528, 3978, 5991, 2328, 4813, 1882, 6336, 5228, 5773, 5928, 3630, 6501, 9658, 7886, 4356, 1045, 273, 7970, 1274, 3452, 5213, 4283, 5202, 7126, 3707, 8785, 5928, 3936, 4453, 4727, 3482, 4947, 3878, 5248, 7482, 5836, 5722, 3402, 114, 9941, 9614, 9891, 7318, 700, 2942, 6002, 7852, 776, 2197, 4903, 3240, 245, 2641, 387, 1893, 994, 9958, 9419, 2445, 2885, 4986, 1369, 2640, 1756, 719, 3344, 5374, 5652, 5200, 4084, 7948, 2773, 8985, 6199, 95, 7799, 4813, 9439, 7512, 2813, 3339, 5, 7389, 7814, 9677, 3142, 991, 6131, 1419, 7628, 6632, 6814, 9695, 349, 4069, 2568, 4427, 4597, 645, 5225, 36, 9650, 5682, 7389, 8132, 1263, 9355, 8216, 2529, 7769, 717, 6097, 1693, 6041, 1965, 3023, 4019, 8332, 9116, 8710, 7770, 9219, 8089, 9677, 3053, 7925, 5473, 5985, 7546, 9963, 4387, 3136, 3440, 4093, 2077, 126, 5575, 6197, 7706, 1830, 5925, 1705, 9446, 2481, 4421, 348, 362, 102, 6927, 7923, 3155, 4908, 103, 3588, 9816, 5941, 2902, 6076, 2993, 660, 7221, 7058, 4857, 4897, 7272, 1104, 7431, 8281, 6960, 3200, 3272, 2512, 5161, 948, 5026, 8792, 8676, 4499, 3904, 7854, 895, 9169, 6419, 4763, 493, 3224, 382, 1998, 9688, 338, 9664, 9133, 7964, 2896, 3449, 5767, 4276, 4860, 855, 7302, 6240, 4973, 5238, 7784, 9073, 862, 2290, 1308, 6611, 1487, 9824, 4798, 3490, 6335, 6615, 3877, 4551, 8162, 8377, 4805, 1599, 4106, 8808, 1749, 2311, 4121, 7834, 9209, 1830, 6718, 5153, 2333, 7167, 8204, 9507, 211, 7592, 9768, 9699, 9032, 8108, 5807, 9756, 8267, 6466, 9009, 252, 3896, 5240, 2481, 3113, 8398, 8897, 8603, 8143, 8264, 9243, 5462, 3233, 4930, 5688, 8852, 6022, 9438, 3841, 4592, 5401, 7966, 604, 8346, 8855, 9880, 3, 9323, 4801, 3165, 5782, 237, 2089, 6819, 9879, 2010, 6481, 92, 5699, 6787, 2119, 4648, 2708, 3453, 3473, 7554, 2023, 3596, 4981, 5419, 4405, 7586, 9250, 7910, 8548, 3732, 4886, 9921, 9953, 597, 6809, 854, 3921, 6881, 3264, 9506, 2397, 585, 8938, 7774, 3903, 4231, 5070, 1407, 8038, 4033, 637, 6465, 1297, 1051, 8069, 7636, 4832, 2177, 2186, 3660, 4861, 4187, 7468, 3992, 7648, 4173, 127, 904, 5159, 6284, 4086, 2025, 9942, 4153, 3078, 4170, 7188, 7399, 4177, 653, 1260, 9841, 2370, 8743, 8500, 7509, 1635, 1621, 4273, 2589, 6410, 5912, 4940, 6119, 3418, 543, 5550, 8610, 9911, 3235, 4250, 2305, 172, 8197, 6179, 3690, 739, 3077, 510, 8999, 5984, 3752, 6953, 9240, 2966, 7685, 5941, 4938, 7028, 6087, 5888, 6228, 1513, 3392, 617, 7930, 5267, 3476, 9048, 1314, 4620, 1428, 2049, 7143, 5374, 4737, 851, 6212, 6281, 4265, 3021, 7246, 3331, 898, 4430, 3745, 9400, 1250, 1309, 3627, 3048, 5698, 696, 3286, 4618, 5088, 4728, 1228, 3914, 9541, 5265, 2590, 8987, 4062, 6353, 3227, 3640, 4895, 1422, 3258, 9608, 5053, 4160, 6700, 7890, 8925, 5982, 5408, 3353, 8888, 2651, 3766, 5244, 8648, 8180, 3356, 8759, 3826, 5984, 4399, 1438, 9639, 4479, 3625, 1992, 2299, 5248, 2009, 2910, 163, 7081, 2976, 9394, 1259, 5529, 6710, 6483, 8918, 5608, 4445, 730, 4199, 9394, 9761, 2681, 1483, 4513, 660, 7953, 5804, 1544, 63, 92, 6351, 403, 9382, 9185, 3242, 1120, 1998, 2335, 9214, 355, 3351, 4665, 549, 2178, 4229, 2216, 5776, 4730, 6719, 6636, 3931, 7432, 5079, 3677, 9540, 3122, 5986, 1048, 8952, 6082, 3399, 5333, 8539, 807, 8003, 3084, 8304, 5679, 2111, 5620, 63, 3354, 2531, 1102, 9492, 4593, 5420, 5889, 1727, 1285, 171, 7907, 5614, 3849, 297, 840, 7799, 7414, 1608, 8145, 7794, 354, 8712, 6361, 310, 8825, 9076, 1065, 6936, 7006, 1319, 4523, 4517, 9227, 9247, 4907, 6171, 2841, 287, 9968, 442, 7241, 5711, 7590, 8282, 4086, 2168, 715, 2346, 3446, 7149, 3673, 6751, 6554, 7738, 7922, 1733, 8885, 118, 5834, 8884, 9778, 8805, 1282, 551, 1497, 4035, 1684, 3251, 4990, 6931, 9761, 5431, 3658, 9328, 5606, 4274, 1381, 9546, 9695, 5144, 7118, 1228, 4209, 7296, 4043, 5867, 5568, 9311, 5078, 1929, 6802, 9739, 4109, 3397, 9794, 1550, 8458, 621, 2831, 4782, 4292, 9793, 1852, 2567, 6030, 8855, 9332, 4734, 4171, 3024, 57, 8469, 9497, 3269, 5572, 9047, 3660, 8681, 6277, 2503, 1334, 7029, 653, 6596, 5868, 4839, 1212, 473, 3424, 3912, 7435, 4935, 6008, 2527, 1575, 3220, 9701, 6701, 7820, 986, 2678, 4527, 39, 4619, 6599, 5167, 7509, 9405, 9913, 893, 4337, 2953, 6063, 1650, 7843, 6770, 4971, 3301, 9542, 3175, 8821, 9153, 1993, 2583, 7610, 4728, 2862, 8866, 8450, 1855, 5876, 1217, 5148, 6277, 2414, 7737, 4168, 13, 1645, 6565, 2047, 2623, 2129, 8545, 5776, 7623, 3892, 4222, 7747, 2655, 8144, 2162, 4167, 3815, 7160, 1754, 2135, 6315, 3537, 7856, 1983, 7415, 255, 1633, 8585, 7235, 89, 8243, 9008, 7230, 2876, 8667, 7205, 3243, 1607, 2314, 5422, 9461, 8862, 4217, 4335, 8983, 7717, 585, 9822, 8484, 4244, 4401, 6993, 1291, 8105, 8358, 8932, 6665, 6858, 744, 8738, 7897, 1683, 7814, 198, 8982, 2753, 1298, 7430, 7153, 5111, 5339, 2865, 1164, 9637, 8034, 8507, 4154, 3608, 1397, 2087, 8976, 5865, 5679, 9882, 8850, 8260, 4218, 6850, 9121, 3830, 3636, 4028, 7037, 6531, 6468, 591, 5584, 18, 7583, 3625, 5788, 8747, 1247, 5291, 6970, 5881, 7735, 4142, 5489, 8722, 6923, 7922, 4989, 8180, 8997, 1921, 2896, 6495, 8324, 7717, 334, 1511, 1654, 5324, 8804, 7673, 6821, 7953, 360, 7247, 121, 9513, 3395, 173, 3512, 8704, 7437, 7362, 4263, 5016, 4487, 489, 7861, 6267, 5043, 9348, 7682, 1819, 5472, 3968, 6453, 961, 7186, 34, 2583, 5669, 8336, 4012, 7634, 6191, 7494, 1385, 855, 3718, 6550, 6675, 8761, 1539, 3395, 1300, 4290, 4714, 8538, 4050, 9214, 297, 909, 747, 6600, 4373, 5132, 2581, 6198, 6430, 3481, 3712, 7229, 6251, 6396, 314, 6951, 9347, 4238, 7295, 8835, 624, 879, 3430, 6824, 4263, 6496, 1557, 8293, 8381, 5558, 1798, 2930, 8125, 7604, 5808, 7376, 2918, 9326, 3121, 9772, 1507, 2433, 3054, 5708, 1195, 9291, 4402, 6695, 6257, 3948, 6626, 1904, 4602, 4083, 8822, 5408, 5205, 6217, 9821, 7243, 4570, 8975, 5719, 8229, 1511, 1971, 4023, 1454, 4485, 4813, 4324, 4961, 1125, 9038, 9912, 7522, 632, 5561, 8703, 5904, 1310, 6108, 6772, 237, 7234, 1437, 8352, 9215, 9688, 8301, 7864, 3368, 8257, 6008, 3913, 9877, 128, 4932, 155, 3672, 8524, 3384, 9579, 4902, 1348, 8455, 8947, 7500, 5146, 2865, 7371, 6258, 6078, 1180, 7593, 1149, 8274, 9911, 2911, 4342, 3160, 6784, 6699, 5510, 7060, 2715, 5329, 9423, 8081, 6920, 9029, 5712, 9157, 8174, 5958, 6685, 4403, 4010, 5167, 5223, 2447, 5326, 217, 2272, 3606, 8592, 2340, 6445, 9735, 4582, 2166, 5722, 5710, 5571, 8976, 8662, 9476, 3011, 2263, 3487, 3961, 5553, 6623, 6450, 3311, 6724, 2303, 1855, 3234, 7223, 5055, 938, 4857, 5928, 144, 7877, 7445, 8050, 4011, 6811, 8868, 2090, 4905, 4482, 461, 7489, 7187, 8035, 7614, 9455, 9102, 1573, 1197, 597, 8827, 5994, 1417, 5708, 235, 289, 4302, 5344, 1023, 972, 3007, 5004, 8346, 221, 1544, 2760, 3528, 6092, 5172, 1858, 7109, 7225, 4025, 5123, 7279, 8778, 7518, 4476, 8871, 4443, 1710, 5160, 6866, 5316, 8546, 4969, 2281, 1121, 1231, 7190, 4114, 3707, 6118, 8196, 7583, 7014, 640, 3261, 5365, 5392, 3369, 6648, 9784, 7692, 8514, 9036, 5127, 5991, 5581, 4872, 9438, 9691, 7076, 4064, 586, 325, 9051, 6853, 1262, 7393, 5784, 2400, 7762, 3127, 3319, 733, 7345, 6941, 7272, 5604, 7128, 9080, 5571, 9862, 3515, 2044, 6091, 4012, 9420, 7841, 3204, 4319, 3219, 4131, 3484, 8985, 4565, 3815, 1971, 5823, 524, 5736, 9446, 323, 8133, 8445, 1268, 8173, 8564, 9073, 448, 3508, 5459, 2576, 6677, 1780, 8315, 8691, 7730, 7565, 9665, 7913, 5661, 3099, 4740, 4325, 5087, 9286, 9483, 3410, 8065, 4600, 5330, 2427, 6751, 6300, 2240, 8675, 1405, 536, 7303, 2856, 596, 9884, 9499, 7416, 1145, 7083, 253, 2124, 2641, 684};
    normalize();

    freeUp(0);
//
//    for(int i = 0; i < k; i++, cout << endl)
//        for(int elem : stacks[i])
//            cout << elem << " ";


    int mx_len = stacks[1].size();
    for(int i = 0; i < mx_len; i++) {
        operate(0);
    }

    int now = 0;
    while(true) {
        if ((now == 0 && top_block_sizes.size() == 1) ||
                (now == k - 1 && bottom_block_sizes.size() == 1))
            break;
        int then = k - 1 - now;
        fromEndToEnd(now, then);
        now = then;
    }
//    cout << "-------------------------------------\n";
//    for(int i = 0; i < k; i++, cout << endl)
//        for(int elem : stacks[i])
//            cout << elem << " ";

    if (now == 0) {
        for(int i = k - 1; i > 0; i--) {
            for(int j = 0; j < n / k; j++)
                move(now, i);
        }
        for(int j = 0; j < n / k; j++)
            move(now, 1);
        for(int j = 0; j < n / k; j++)
            move(1, 2);
        for(int j = 0; j < n / k; j++)
            move(2, now);
    }
    else {
        for(int j = 0; j < n / k; j++) {
            move(now, 0);
        }
        for(int i = k - 1; i > 0; i--) {
            for(int j = 0; j < n / k; j++)
                move(now, i);
        }
        for(int j = 0; j < n / k; j++)
            move(0, 1);
        for(int j = 0; j < n / k; j++)
            move(now, 0);

        for(int j = 0; j < n / k; j++)
            move(1, now);
    }


    vc<int> sax;
    for(auto stck : stacks) {
        assert(stck.size() == n / k);
        reverse(all(stck));
        for(int e : stck){
            sax.push_back(e);
        }
    }
    assert(is_sorted(all(sax)));


    cout << ans.size() << endl;
    for(auto& move : ans)
        cout << move.first + 1 << " " << 1 + move.second << "\n";


//    cout << "-------------------------------------\n";
//    for(int i = 0; i < k; i++, cout << endl)
//        for(int elem : stacks[i])
//            cout << elem << " ";
    /*
    fillEmptyStacks(0);
    cout << "-------------------------------------\n";
    for(int i = 0; i < k; i++, cout << endl)
        for(int elem : stacks[i])
            cout << elem << " ";
    mergeInto(k - 1);
    cout << "-------------------------------------\n";
    for(int i = 0; i < k; i++, cout << endl)
        for(int elem : stacks[i])
            cout << elem << " ";
    dbCont(bottom_block_sizes);
*/

    return 0;

}