using NAudio.Wave;
using System;
using System.Collections.Generic;
using System.IO;

namespace SimpleBirthdaySong
{
    class Program
    {
        // 音符频率映射
        private static readonly Dictionary<string, float> Frequencies = new Dictionary<string, float>
        {
            {"C4", 261.63f}, {"D4", 293.66f}, {"E4", 329.63f}, {"F4", 349.23f},
            {"G4", 392.00f}, {"A4", 440.00f}, {"B4", 493.88f}, {"C5", 523.25f},
            {"D5", 587.33f}, {"E5", 659.25f}, {"F5", 698.46f}, {"G5", 783.99f}
        };
        static void Main(string[] args)
        {
            try
            {
                GenerateBirthdaySong("生日快乐歌.wav");
                Console.WriteLine("生日快乐歌生成成功！");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"错误: {ex.Message}");
            }
        }
        static void GenerateBirthdaySong(string filePath)
        {
            var notes = new[]
            {
                ("G4", 0.3), ("G4", 0.3), ("A4", 0.6), ("G4", 0.6), ("C5", 0.6), ("B4", 1.2),
                ("G4", 0.3), ("G4", 0.3), ("A4", 0.6), ("G4", 0.6), ("D5", 0.6), ("C5", 1.2),
                ("G4", 0.3), ("G4", 0.3), ("G5", 0.6), ("E5", 0.6), ("C5", 0.6), ("B4", 0.6), ("A4", 1.2),
                ("F5", 0.3), ("F5", 0.3), ("E5", 0.6), ("C5", 0.6), ("D5", 0.6), ("C5", 1.2)
            };
            var format = new WaveFormat(44100, 16, 1);
            using (var writer = new WaveFileWriter(filePath, format))
            {
                foreach (var (noteName, duration) in notes)
                {
                    if (Frequencies.TryGetValue(noteName, out float freq))
                    {
                        GenerateTone(writer, freq, duration, 0.3f);
                    }
                }
            }
        }
        static void GenerateTone(WaveFileWriter writer, float frequency, double seconds, float volume)
        {
            int samples = (int)(writer.WaveFormat.SampleRate * seconds);
            for (int i = 0; i < samples; i++)
            {
                double time = i / (double)writer.WaveFormat.SampleRate;
                short sample = (short)(volume * short.MaxValue * Math.Sin(2 * Math.PI * frequency * time));
                writer.WriteSample(sample);
            }
        }
    }
}