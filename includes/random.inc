float Rand21(vec2 seed) { return fract(sin(seed.x * 1995. + seed.y * 74.) * 66547.); }

vec2 Rand22(vec2 seed)
{
    float noise = fract(sin(seed.x * 1995. + seed.y * 74.) * 66547.);
    return vec2(noise, Rand21(seed + noise));
}

float SmoothRand21(vec2 uv)
{
    vec2 lv = fract(uv);
    vec2 id = floor(uv);
    lv = lv * lv * 3. - 2. * lv * lv * lv;
    float nBl = Rand21(id + vec2(0.,0.));
    float nBr = Rand21(id + vec2(1.,0.));
    float nB = mix(nBl, nBr, lv.x);
    float nTl = Rand21(id + vec2(0.,1.));
    float nTr = Rand21(id + vec2(1.,1.));
    float nT = mix(nTl, nTr, lv.x);
    float n = mix(nB, nT, lv.y);

    return n;
}