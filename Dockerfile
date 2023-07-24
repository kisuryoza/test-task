FROM alpine:latest
RUN apk update && \
    apk add --no-cache build-base meson
COPY . /project
WORKDIR /project
RUN meson setup target --wipe && meson compile -C target
# RUN make
CMD ["./target/bin", "polys.txt", "lines.txt"]
