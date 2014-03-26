uniform sampler2DRect tex;
uniform vec2 windowSize;
uniform float offsetALL;
uniform vec2 offsetRed;
uniform vec2 offsetGreen;
uniform vec2 offsetBlue;

varying vec2 texcoord0;


void main()
{
	//vec2 offset			= ( gl_FragCoord.xy/windowSize - vec2( 0.5 ) ) * 0.005;
    vec2 offset			= ( gl_FragCoord.xy/windowSize - vec2( 0.5 ) ) * offsetALL;
    vec2 offsetRedX     = ( gl_FragCoord.xy/windowSize - 0.5 * offsetRed);
    vec2 offsetGreenX   = ( gl_FragCoord.xy/windowSize - 0.5 * offsetGreen);
    vec2 offsetBlueX    = ( gl_FragCoord.xy/windowSize - 0.5 * offsetBlue);

	float rChannel		= texture2DRect( tex, texcoord0 + offsetRedX).r;
	float gChannel		= texture2DRect( tex, texcoord0 + offset  + offsetGreenX).g;
	float bChannel		= texture2DRect( tex, texcoord0 + offset + offsetBlueX).b;
   // float aChannel		= texture2DRect( tex, texcoord0 ).a;
	vec3 finalCol		= vec3( rChannel, gChannel, bChannel );
	
	gl_FragColor.rgb	= finalCol;
	gl_FragColor.a		= 1.0;
}