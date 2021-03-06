import os, random, sys, vlc, glob

media_list = []
srt_list=[]
path="/media/diksha/BUBBLES/Leisure_Time/series/Friends"

def change_dir():
    os.chdir(path)
    files = os.listdir(path)                                      #list all the folders in that path
    index = random.randrange(0, len(files))                       #select a random index from 0 to total #files
    os.chdir(files[index])                                        #append this folder to the path
    return os.getcwd() 

def create_media_list(new_path):
    for path, subdirs, files in os.walk(new_path):                  
        for file in files:                                              
            if file.lower().endswith(('.mkv', '.avi', '.mp4')):
                media_list.append(file)                          #create a media list
            if file.endswith(('.srt')):
                srt_list.append(file)                            #create a srt list

def select_random_file(new_path):
    create_media_list(new_path)                                                         
    media = random.choice(media_list)                            #randomly select any media file
    srtfile = ""
    if len(srt_list) != 0:
        media_episode = media[:-4]                               #fetch the episode name
        for srt in srt_list:
            srt_episode = srt[:-4]                               #fetch the srt name
            if srt_episode == media_episode:                     #if srt is for the corresponding media, then save
                srtfile = os.path.join(new_path, srt)
                break
    return ( os.path.join(new_path, media),srtfile)

""" def play_episode():
    video, srt = select_random_file()
    instance = vlc.Instance('--fullscreen')
    player = instance.media_player_new()
    Media = instance.media_new(video)
    player.set_media(Media)
    #player.video_set_subtitle_file(srt)
    player.play() 
"""

def main():
    video, srt = select_random_file(change_dir())
    print(video,',', srt)

if __name__ == "__main__":
    main() 